#include "atpch.h"
#include "Atlas.h"

class ExampleLayer : public Atlas::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnUpdate() override {
		AT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Atlas::Event& event) override{
		AT_TRACE("{0}", event);
	}
};

class Sandbox : public Atlas::main
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Atlas::ImGuiLayer());
	}

	~Sandbox() 
	{

	}

};

Atlas::main* Atlas::CreateApplication() 
{
	return new Sandbox();
}
