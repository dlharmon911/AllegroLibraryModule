export module allegro:math;

import std;
import <allegro5/base.h>;

namespace ALLEGRO
{
	export constexpr double PI = static_cast<double>(ALLEGRO_PI);
	export constexpr double PI_HALF = static_cast<double>(ALLEGRO_PI) * 0.5;
	export constexpr double PI_DOUBLE = static_cast<double>(ALLEGRO_PI) * 2.0;
}

namespace al
{
	export inline auto is_zero(double a) -> bool
	{
		return std::abs(a) <= std::numeric_limits<double>::epsilon();
	}

	export inline auto is_zero(float a) -> bool
	{
		return std::fabs(a) <= std::numeric_limits<float>::epsilon();
	}

	export inline auto are_equal(double a, double b) -> bool
	{
		return std::abs(a) <= std::numeric_limits<double>::epsilon();
	}

	export inline auto are_equal(float a, float b) -> bool
	{
		return std::fabs(a) <= std::numeric_limits<float>::epsilon();
	}
}

