#pragma once
#include <iostream>
#include "Math.h"



namespace sparky {
	namespace math {

		struct mat4
		{
			union
			{
				float elements[4 * 4];
				vec4 columns[4];
			};
			mat4();
			mat4(float diagonal);
			mat4(mat4& matrix);

			static mat4 identity();
			mat4& operator*=(const mat4& other);

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 projection(float fov, float apsectRatio, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);

			mat4 operator*(const mat4& right);
			mat4 mat4::operator=(const mat4& right);

			friend std::ostream& operator<<(std::ostream& stream,const mat4& right);
		};

	}
}