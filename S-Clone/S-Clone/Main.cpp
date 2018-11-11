#include "Window.h"
#include "Math.h"
int main()
{
	using namespace sparky;


	sparky::graphics::Window window("Test", 800,600 );
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	math::mat4 vect(2.0f);
	math::mat4 mat(.3f);
	math::mat4 mati;
	mati = mat*vect;


	while (!window.closed())
	{
		window.clear();
		window.update();
	}
	
	system("Pause");
	return 0;

}