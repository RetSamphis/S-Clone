#include "Shader.h"
#include <vector>
#include<iostream>


namespace sparky{
	namespace graphics {
		Shader::Shader(const char* vertPath, const char* fragPath): m_VertPath(vertPath), m_FragPath(fragPath)
		{
			m_Shader = load();
		}
		Shader::~Shader() 
		{
			glDeleteProgram(m_Shader);
		}

		void Shader::enable() const 
		{
			glUseProgram(m_Shader);
		}
		void Shader::disable() const 
		{
			glUseProgram(0);
		}
		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileUtils::read_file(m_VertPath);
			std::string fragSourceString = FileUtils::read_file(m_FragPath);

			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();


			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}


			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);


			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << &error[0] << " Failed to compile fragment shader" << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			
			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);
			
			return program;
		}

		void Shader::setUniform1f(const GLchar* name, float f)
		{
			glUniform1f(getUniformLocation(name),f);
		}
		void Shader::setUniform1i(const GLchar* name, int i) {
			glUniform1i(getUniformLocation(name), i);
		}

		void Shader::setUniform2f(const GLchar* name, const math::vec2& vec) 
		{
			glUniform2f(getUniformLocation(name), vec.x, vec.y);
		}

		void Shader::setUniform3f(const GLchar* name, const math::vec3& vec) 
		{
			glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z);
		}

		void Shader::setUniform4f(const GLchar* name, const math::vec4& vec) 
		{
			glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
		}

		void Shader::setUniformMat4(const GLchar* name, const math::mat4& matrix) 
		{
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		GLint Shader::getUniformLocation( const GLchar* name)
		{
			return glGetUniformLocation(m_Shader, name);
		}

	}
}