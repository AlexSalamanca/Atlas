#include "atpch.h"
#include "Atlas.h"

class Sandbox : public Atlas::main
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}

};

Atlas::main* Atlas::CreateApplication() 
{
	return new Sandbox();
}
