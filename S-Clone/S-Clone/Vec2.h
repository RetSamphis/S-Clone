#pragma once

#include <iostream>


namespace sparky {
	namespace math {

		struct vec2 
		{
			float x, y;

			vec2();
			vec2(const float& x = 0,const float& y = 0);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);
			vec2& operator=(const vec2& other);

			vec2& operator+(const vec2& right);
			vec2& operator-(const vec2& right);
			vec2& operator*(const vec2& right);
			vec2& operator/(const vec2& right);
			bool operator==(const vec2& right);
			bool operator!=(const vec2& right);



			friend std::ostream& operator<<(std::ostream&, const vec2& vector);

		};
	}
}