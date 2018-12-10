#include "atpch.h"

#include "AtlasMain.h"

#include "Events/ApplicationEvents.h"
#include "ErrorLog.h"

namespace Atlas {
	main::main()
	{
	}


	main::~main()
	{
	}

	void main::Run()
	{
		WindowsResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			AT_INFO(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {
			AT_INFO(e);
		}

		while (true);
	}
}
