#include "Window.h"
#include "Math.h"
#include "Shader.h"
int main()
{
	using namespace sparky;

	
	sparky::graphics::Window window("Test", 800,600 );
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	GLfloat vertices[] = {
		-0.0,-0.0,0.0,
		 15,0.5,0.0,
		 0.5,8,0.0
	};

	GLuint vao, vbo;


	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,0 ,0);
	glEnableVertexAttribArray(0);

	math::mat4 ortho = math::mat4::orthographic(0, 16, 0, 9, -1, 1);

	graphics::Shader shader("basic.vert", "basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", math::mat4::rotation(7, math::vec3(0, 0, 1)));
	shader.setUniform2f("light_pos", math::vec2(8, 4.5));
	shader.setUniform4f("colour", math::vec4(0.2, 0.3, 0.8, 1));
	while (!window.closed())
	{
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		window.update();
	}
	
	system("Pause");
	return 0;

}