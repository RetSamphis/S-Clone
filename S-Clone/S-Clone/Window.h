#pragma once
#include <glfw3.h>
#include <iostream>

namespace sparky {
	namespace graphics {

		class Window {
		private:
			const char *m_Name;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
		public:
			Window(const char *name, int width, int height);
			~Window();
			bool Window::init();
			void Window::update() const;
			bool Window::closed() const;
		};

	}
}