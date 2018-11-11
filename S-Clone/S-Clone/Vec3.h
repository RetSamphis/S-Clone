#pragma once

#include <iostream>


namespace sparky {
	namespace math {

		struct vec3
		{
			float x, y, z;

			vec3();
			vec3(const float& x= 0, const float& y = 0, const float& z = 0);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);
			vec3& operator=(const vec3& other);

			vec3& operator+(const vec3& right);
			vec3& operator-(const vec3& right);
			vec3& operator*(const vec3& right);
			vec3& operator/(const vec3& right);
			bool operator==(const vec3& right);
			bool operator!=(const vec3& right);



			friend std::ostream& operator<<(std::ostream&, const vec3& vector);

		};
	}
}
