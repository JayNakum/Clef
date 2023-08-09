#pragma once

#include "imgui.h"

#include "Layer.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

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
		inline void close() { m_isRunning = false; }

		void setMenubarCallback(const std::function<void()>& menubarCallback) { m_menubarCallback = menubarCallback; }

		template<typename T>
		void pushLayer()
		{
			static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
			m_layerStack.emplace_back(std::make_shared<T>())->onAttach();
		}

		void pushLayer(const std::shared_ptr<Layer>& layer) { m_layerStack.emplace_back(layer); layer->onAttach(); }

		inline float getTime() const;
	
	private:
		void init();
		void shutdown();

	private:
		ApplicationSpecification m_appSpecs;
		GLFWwindow* m_windowHandle = nullptr;
		bool m_isRunning = false;

		float m_timeStep = 0.0f;
		float m_frameTime = 0.0f;
		float m_lastFrameTime = 0.0f;

		std::vector<std::shared_ptr<Layer>> m_layerStack;
		std::function<void()> m_menubarCallback;
	};

	Application* createApplication(int argc, char** argv);
}