#include <math.h>
#include "Mat4.h"
#include "Math_Func.h"
namespace sparky {
	namespace math {

		mat4::mat4() 
		{
			for (int i = 0; i < 4 * 4; i++) {
				elements[i] = 0;
			}
		}

		mat4::mat4(float diagonal) {
			for (int i = 0; i < 4 * 4; i++) {
				elements[i] = 0;
			}
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;

		}

		mat4::mat4(mat4& matrix) {
			for (int i = 0; i < 4 * 4; i++)
			{
				this->elements[i] = matrix.elements[i];
			}
		}

		mat4 mat4::identity() 
		{
			return mat4(0.0f);
		}

		mat4& mat4::operator*=(const mat4& other) 
		{
			for (int c = 0; c < 4; c++)
			{
				for (int r = 0; r < 4; r++) 
				{
					float sum = 0.0f;

					for (int e = 0; e < 4; e++) 
					{
						sum += elements[r + e * 4] * other.elements[e + c * 4];
					}
					elements[r + c * 4] = sum;
				}
			}
			return *this;
		}
		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far) 
		{
			mat4 result(1.0f);
			result.elements[0 + 0 * 4] = 2.0f / (right-left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);
			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (near + far) / (near - far);
			return result;
		}
		mat4 mat4::projection(float fov, float apsectRatio, float near, float far) 
		{
			mat4 result;
			float q = 1.0f / tan(toRadians(0.5f * fov));
			float a = q/ apsectRatio;

			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = c;
			result.elements[2 + 3 * 4] = 1;
			return result;
		}

		mat4 mat4::translation(const vec3& translation) 
		{
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;
			
			return result;

		}
		mat4 mat4::rotation(float angle, const vec3& axis) 
		{
			mat4 result(1.0f);
			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = x * y * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;

			result.elements[0 + 1 * 4] = x * y * omc  - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc - z * s;

			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}

		mat4 mat4::scale(const vec3& scale)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}

		mat4 mat4::operator*(const mat4& right) 
		{
			mat4 m(*this);

			m *= right;
			return m;
		}

		mat4 mat4::operator=(const mat4& right)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				this->elements[i] = right.elements[i];
			}
			return *this;
		}

		std::ostream& operator<<(std::ostream& stream, const mat4& right)
		{
			stream << "[ ";
			for (int i = 0; i < 4; i++)
			{
				for (int v = 0; v < 4; v++) {
					if (i + v * 4 != 15) {
						stream << right.elements[i + v * 4] << ", ";
					}
					else {
						stream << right.elements[i + v * 4];
					}
				}
				if(i != 3)
					stream << std::endl;
			}
			stream << " ]";
			return stream;
		}

	}
} 