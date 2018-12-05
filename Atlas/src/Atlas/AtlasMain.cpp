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
			AT_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {
			AT_TRACE(e);
		}

		while (true);
	}
}
