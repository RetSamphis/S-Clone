#pragma once
#include "Fileutils.h"
#include <glew.h>
#include "Math.h"

namespace sparky {
	namespace graphics {

		class Shader 
		{
		public:
			GLuint m_Shader;
			const char* m_VertPath;
			const char* m_FragPath;

		public:

			Shader(const char* vertPath, const char* fragPath);
			~Shader();


			void setUniform1f(const GLchar* name, float f);
			void setUniform1i(const GLchar* name, int i);
			void setUniform2f(const GLchar* name, const math::vec2& vec);
			void setUniform3f(const GLchar* name, const math::vec3& vec);
			void setUniform4f(const GLchar* name, const math::vec4& vec);

			void setUniformMat4(const GLchar* name, const math::mat4& matrix);

			void enable() const;
			void disable() const;

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};
	}
}