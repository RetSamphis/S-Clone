#include "vec4.h"
namespace sparky {
	namespace math {

		vec4::vec4() {
			x = 0.0;
			y = 0.0;
			z = 0.0;
			w = 0.0;
		}

		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::operator+=(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		vec4& vec4::operator-=(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}

		vec4& vec4::operator*=(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}

		vec4& vec4::operator/=(const vec4& other)
		{

			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}
		vec4& vec4::operator=(const vec4& other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
			return *this;
		}

		vec4& vec4::operator+(const vec4& right)
		{
			return vec4(this->x + right.x, this->y + right.y, this->z + right.z, this->w + right.w);
		}

		vec4& vec4::operator-(const vec4& right)
		{
			return vec4(this->x - right.x, this->y - right.y, this->z - right.z,this->w - right.w);
		}

		vec4& vec4::operator*(const vec4& right)
		{
			return vec4(this->x * right.x, this->y * right.y, this->z * right.z, this->w * right.w);
		}

		vec4& vec4::operator/(const vec4& right)
		{
			return vec4(this->x / right.x, this->y / right.y, this->z / right.z, this->w / right.w);
		}
		bool vec4::operator==(const vec4& right) {
			return ((this->x == right.x) && (this->y == right.y) && (this->z == right.z) && (this->w == right.w));
		}
		bool vec4::operator!=(const vec4& right) {
			return !((this->x == right.x) && (this->y == right.y) && (this->z == right.z) && (this->w == right.w));
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			return stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << ")";
		}
	}
}