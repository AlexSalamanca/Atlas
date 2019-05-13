#pragma once

#include "atpch.h"

#include "Atlas/Core.h"
#include "Atlas/Events/Event.h"

namespace Atlas {

	struct WindowProps {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& window_title = "Atlas Engine",
					unsigned int window_width = 1280,
					unsigned int window_height = 720)
			: title(window_title), width(window_width), height(window_height)
		{

		}
	};

	//Interface representing a desktop system based Window
	class ATLAS_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}