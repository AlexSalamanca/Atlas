#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Events/ApplicationEvents.h"

#include "Window.h"

namespace Atlas {
	
	class ATLAS_API main
	{
	public:
		main();
		virtual ~main();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowsCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Run = true;
	};

	//to be defined in CLIENT
	main* CreateApplication();
}

