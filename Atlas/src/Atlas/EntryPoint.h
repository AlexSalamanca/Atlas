#pragma once

#ifdef AT_PLATFORM_WINDOWS

extern Atlas::main* Atlas::CreateApplication();

int main(int argc, char** argv)
{
	Atlas::Log::Init();
	AT_CORE_WARN("Initialize log");
	int a = 5;
	AT_INFO("Hello! Var= {0}", a);

	auto app = Atlas::CreateApplication();
	app->Run();

	delete app;
}

#endif // AT_PLATFORM_WINDOWS