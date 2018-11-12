#pragma once

#include "Core.h"

namespace Atlas {
	
	class ATLAS_API main
	{
	public:
		main();
		virtual ~main();

		void Run();
	};

	//to be defined in CLIENT
	main* CreateApplication();
}

