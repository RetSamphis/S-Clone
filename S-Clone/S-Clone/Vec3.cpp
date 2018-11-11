#include "vec3.h"
namespace sparky {
	namespace math {

		vec3::vec3() {
			x = 0.0;
			y = 0.0;
			z = 0.0;
		}

		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::operator+=(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		vec3& vec3::operator-=(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		vec3& vec3::operator*=(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		vec3& vec3::operator/=(const vec3& other)
		{

			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}
		vec3& vec3::operator=(const vec3& other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;
		}

		vec3& vec3::operator+(const vec3& right)
		{
			return vec3(this->x + right.x, this->y + right.y, this->z + right.z);
		}

		vec3& vec3::operator-(const vec3& right)
		{
			return vec3(this->x - right.x, this->y - right.y, this->z - right.z);
		}

		vec3& vec3::operator*(const vec3& right)
		{
			return vec3(this->x * right.x, this->y * right.y, this->z * right.z);
		}

		vec3& vec3::operator/(const vec3& right)
		{
			return vec3(this->x / right.x, this->y / right.y, this->z / right.z);
		}
		bool vec3::operator==(const vec3& right) {
			return ((this->x == right.x) && (this->y == right.y) && (this->z == right.z));
		}
		bool vec3::operator!=(const vec3& right) {
			return !((this->x == right.x) && (this->y == right.y) && (this->z == right.z));
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			return stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		}
	}
}
