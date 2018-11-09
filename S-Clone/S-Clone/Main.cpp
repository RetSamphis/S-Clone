#include <glfw3.h>
#include <iostream>

#include "Window.h"

int main()
{
	using namespace sparky;
	sparky::graphics::Window window("Test", 800,600 );
	
	while (!window.closed())
	{
		window.update();
	}
	
	system("Pause");
	return 0;

}