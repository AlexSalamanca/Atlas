#pragma once

#include "Core.h"

#include "Window.h"

#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvents.h"

namespace Atlas {
	
	class ATLAS_API main
	{
	public:
		main();
		virtual ~main();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static main& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowsCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Run = true;

		LayerStack m_LayerStack;

		static main* s_Instance;
	};

	//to be defined in CLIENT
	main* CreateApplication();
}

