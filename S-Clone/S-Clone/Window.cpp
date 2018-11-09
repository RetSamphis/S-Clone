#include "Window.h"

namespace sparky {
	namespace graphics {

		Window::Window(const char *name, int width, int height)
		{
			m_Height = height;
			m_Name = name;
			m_Width = width;
			init();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init() 
		{
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}
			else {
				std::cout << "Sucess!" << std::endl;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
			
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			return true;
		}

		void Window::update() const 
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const 
		{
			return glfwWindowShouldClose(m_Window);
		}
	}
}
