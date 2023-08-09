#include "Clef/Application.h"
#include "Clef/EntryPoint.h"

Clef::Application* Clef::createApplication(int argc, char** argv)
{
	Clef::ApplicationSpecification spec;
	spec.name = "Clef Example";

	Clef::Application* app = new Clef::Application(spec);

	return app;
}