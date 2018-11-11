#pragma once

#include <iostream>


namespace sparky {
	namespace math {

		struct vec4
		{
			float x, y, z, w;

			vec4();
			vec4(const float& x = 0, const float& y = 0, const float& z = 0, const float& w = 0);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);
			vec4& operator=(const vec4& other);

			vec4& operator+(const vec4& right);
			vec4& operator-(const vec4& right);
			vec4& operator*(const vec4& right);
			vec4& operator/(const vec4& right);
			bool operator==(const vec4& right);
			bool operator!=(const vec4& right);



			friend std::ostream& operator<<(std::ostream&, const vec4& vector);

		};
	}
}
