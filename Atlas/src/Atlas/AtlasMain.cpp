#include "atpch.h"

#include "AtlasMain.h"

#include "ErrorLog.h"

#include "GLFW/glfw3.h"

namespace Atlas {
	main::main()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(main::OnEvent));
	}


	main::~main()
	{
	}

	void main::Run()
	{
		while (m_Run) {
			glClearColor(0.8, 0.4, 0.6, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void main::OnEvent(Event & e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowsCloseEvent>(BIND_EVENT_FN(main::OnWindowClose));

		AT_CORE_TRACE("{0}", e);
	}

	bool main::OnWindowClose(WindowsCloseEvent& e)
	{
		m_Run = false;

		return true;
	}
}
