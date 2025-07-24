export module allegro:math;

import std;
import <allegro5/base.h>;

namespace ALLEGRO
{
	export constexpr double PI = static_cast<double>(ALLEGRO_PI);
	export constexpr double PI_HALF = static_cast<double>(ALLEGRO_PI) * 0.5;
	export constexpr double PI_DOUBLE = static_cast<double>(ALLEGRO_PI) * 2.0;

	namespace INTERNAL
	{
		export template <typename T> concept ALLOWED_TYPE = std::is_same_v<T, double> || std::is_same_v<T, float>;
	}
}

namespace al
{
	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto is_value_zero(T value) -> bool
	{
		return std::abs<T>(value) <= std::numeric_limits<T>::epsilon();
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto are_values_equal(T a_value, T b_value) -> bool
	{
		return std::abs<T>(a_value - b_value) <= std::numeric_limits<T>::epsilon();
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto calculate_maximum_value(T a_value, T b_value) -> bool
	{
		if (a_value > b_value)
		{
			return a_value;
		}

		return b_value;
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto calculate_minimum_value(T a_value, T b_value) -> bool
	{
		if (a_value < b_value)
		{
			return a_value;
		}

		return b_value;
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto calculate_difference_of_values(T a_value, T b_value) -> T
	{
		return std::abs<T>(a_value - b_value);
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto add_values(T a_value, T b_value) -> T
	{
		return (a_value + b_value);
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto subtract_values(T a_value, T b_value) -> T
	{
		return a_value - b_value;
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto multiply_values(T a_value, T b_value) -> T
	{
		return (a_value * b_value);
	}

	export template<ALLEGRO::INTERNAL::ALLOWED_TYPE T> auto divide_values(T a_value, T b_value) -> T
	{
		if (is_zero(b_value))
		{
			if (std::signbit(a_value))
			{
				return -std::numeric_limits<T>::infinity();
			}

			return std::numeric_limits<T>::infinity();
		}

		return multiply_value(a_value, static_cast<T>(1) / b_value);
	}
}
