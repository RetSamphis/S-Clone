#pragma once
#include <glew.h>
#include <glfw3.h>
#include <iostream>

namespace sparky {
	namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window {


		private:

			const char *m_Name;
			int m_Width, m_Height;
			GLFWwindow* m_Window;

			bool m_Keys[MAX_KEYS];
			bool m_Buttons[MAX_BUTTONS];
			double mx, my;

		public:
			/*/
			Constructors
			/*/
			Window(const char *name, int width, int height);
			~Window();

			/*/
			Bools
			/*/

			bool Window::closed() const;
			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int keycode) const;
			void getMousePosition(double& x, double &y) const;


			/*/
			Voids
			/*/
			void Window::clear() const;
			void Window::update();


			/*/
			Ints
			/*/
			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			/*/
			Static functions
			/*/

		private:
			bool Window::init();
			friend static void mousecursor_callback(GLFWwindow* window, double xpos, double ypos);
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mousebutton_callback(GLFWwindow* window, int key, int action, int mods);
		};

	}
}