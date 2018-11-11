#include "Vec2.h"
namespace sparky {
	namespace math {

		vec2::vec2() {
			x = 0.0;
			y = 0.0;
		}

		vec2::vec2(const float& x, const float& y) 
		{
			this->x = x;
			this->y = y;
		}

		vec2& vec2::operator+=(const vec2& other) 
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		vec2& vec2::operator-=(const vec2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		vec2& vec2::operator*=(const vec2& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		vec2& vec2::operator/=(const vec2& other) 
		{

			x /= other.x;
			y /= other.y;
			return *this;
		}
		vec2& vec2::operator=(const vec2& other) {
			this->x = other.x;
			this->y = other.y;
			return *this;
		}

		vec2& vec2::operator+(const vec2& right) 
		{
			return vec2(this->x + right.x, this->y + right.y);
		}

		vec2& vec2::operator-(const vec2& right)
		{
			return vec2(this->x - right.x, this->y - right.y);
		}

		vec2& vec2::operator*(const vec2& right)
		{
			return vec2(this->x * right.x, this->y * right.y);
		}

		vec2& vec2::operator/(const vec2& right)
		{
			return vec2(this->x / right.x, this->y / right.y);
		}
		bool vec2::operator==(const vec2& right) {
			return (this->x == right.x && this->y == right.y);
		}
		bool vec2::operator!=(const vec2& right) {
			return !(this->x == right.x && this->y == right.y);
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector) 
		{
			return stream << "vec2: (" << vector.x << " , " << vector.y << ")";
		}
	}
}
