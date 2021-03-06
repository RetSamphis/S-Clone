#include "Window.h"

namespace sparky {
	namespace graphics {

		void window_Resize(GLFWwindow *,int,int);
		void mousebutton_callback(GLFWwindow*, int, int, int);

		Window::Window(const char *name, int width, int height)
		{
			m_Height = height;
			m_Name = name;
			m_Width = width;
			if (!init()) {
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++) {
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++) {
				m_Buttons[i] = false;
			}
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
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window,window_Resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mousebutton_callback);
			glfwSetCursorPosCallback(m_Window, mousecursor_callback);


 			if (glewInit() != GLEW_OK) {
				std::cout << "Could not init GLEW!" << std::endl;
				return false;
			}
			return true;
		}


		bool Window::closed() const 
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}


		bool Window::isKeyPressed(unsigned int keycode) const
		{
			//TODO: LOGGING
			if (keycode >= MAX_KEYS)
				return false;
			return m_Keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int keycode) const
		{
			//TODO: LOGGING
			if (keycode >= MAX_BUTTONS)
				return false;
			return m_Buttons[keycode];
		}
		void Window::getMousePosition(double& x, double &y) const
		{
			x = mx;
			y = my;
		}

		void Window::clear() const{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		void window_Resize(GLFWwindow * window, int width, int height) {
			glViewport(0, 0, width, height);
		}



		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) 
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = (action != GLFW_RELEASE);
		}

		void mousebutton_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Buttons[button] = (action != GLFW_RELEASE);
		}

		void mousecursor_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
	}
}
