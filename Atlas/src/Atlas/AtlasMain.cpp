#include "atpch.h"

#include "AtlasMain.h"
#include "ErrorLog.h"

#include "glad/glad.h"

namespace Atlas {
	main* main::s_Instance = nullptr;

	main::main()
	{
		AT_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(main::OnEvent));
	}


	main::~main()
	{
	}

	void main::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void main::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void main::Run()
	{
		while (m_Run) {
			glClearColor(0.8, 0.4, 0.6, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void main::OnEvent(Event & e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowsCloseEvent>(BIND_EVENT_FN(main::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}

	bool main::OnWindowClose(WindowsCloseEvent& e)
	{
		m_Run = false;

		return true;
	}
}
