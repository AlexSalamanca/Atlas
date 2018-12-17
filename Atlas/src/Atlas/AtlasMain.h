#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Atlas {
	
	class ATLAS_API main
	{
	public:
		main();
		virtual ~main();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Run = true;
	};

	//to be defined in CLIENT
	main* CreateApplication();
}

