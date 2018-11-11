#pragma once

namespace sparky {
	namespace math {

		inline float toRadians(float degrees)
		{
			return degrees * (3.1415926535897 / 180.0f);
		}
	}
}