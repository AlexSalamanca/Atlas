#include "atpch.h"

#include "AtlasMain.h"

#include "Events/ApplicationEvents.h"
#include "ErrorLog.h"

#include "GLFW/glfw3.h"

namespace Atlas {
	main::main()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
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
}
