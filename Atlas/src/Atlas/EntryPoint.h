#pragma once

#ifdef AT_PLATFORM_WINDOWS

extern Atlas::main* Atlas::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Atlas::CreateApplication();
	app->Run();

	delete app;
}

#endif // AT_PLATFORM_WINDOWS
