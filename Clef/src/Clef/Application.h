#pragma once

#include <string>

struct GLFWwindow;

namespace Clef
{
	struct ApplicationSpecification
	{
		std::string name = "Clef App";
		uint32_t width = 1600;
		uint32_t height = 900;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& appSpecs = ApplicationSpecification());
		~Application();

		void run();
	
	private:
		void init();
		void shutdown();

	private:
		ApplicationSpecification m_appSpecs;
		GLFWwindow* m_windowHandle = nullptr;
		bool m_isRunning = false;
	};

	Application* createApplication(int argc, char** argv);
}