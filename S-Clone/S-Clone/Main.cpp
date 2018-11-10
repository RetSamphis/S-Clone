#include "Window.h"

int main()
{
	using namespace sparky;


	sparky::graphics::Window window("Test", 800,600 );
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.closed())
	{
		window.clear();
		window.update();
	}
	
	system("Pause");
	return 0;

}