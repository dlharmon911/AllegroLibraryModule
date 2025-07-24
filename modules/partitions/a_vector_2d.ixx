export module allegro:vector_2d;

import std;
import :base;
import :error;
import :math;

namespace ALLEGRO
{
	export constexpr size_t VECTOR_2D_ARRAY_SIZE{ 2 };

	export template <typename T> class VECTOR_2D
	{
	public:
		using TYPE = typename T;

		constexpr VECTOR_2D()
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(0);
			}
		}

		constexpr VECTOR_2D(const T _x, const T _y)
		{
			this->m_x = _x;
			this->m_y = _y;
		}

		constexpr VECTOR_2D(const VECTOR_2D& vector)
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = vector.m_array[i];
			}
		}

		constexpr VECTOR_2D(const std::array<T, ALLEGRO::VECTOR_2D_ARRAY_SIZE>& array)
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}
		}

		template <typename Q> explicit constexpr VECTOR_2D(const Q _x, const Q _y)
		{
			this->m_x = static_cast<T>(_x);
			this->m_y = static_cast<T>(_y);
		}

		template <typename Q> explicit constexpr VECTOR_2D(const VECTOR_2D<Q>& vector)
		{
			const auto& array = vector.get_array();

			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(array[i]);
			}
		}

		virtual ~VECTOR_2D() = default;

		constexpr auto operator =(const std::array<T, ALLEGRO::VECTOR_2D_ARRAY_SIZE>& array) -> VECTOR_2D&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}

			return *this;
		}

		constexpr auto operator = (const VECTOR_2D& vector) -> VECTOR_2D&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = vector.m_array[i];
			}

			return *this;
		}

		auto is_equal(const VECTOR_2D& v) const -> bool
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				if (!al::are_values_equal(this->m_array[i], v.m_array[i]))
				{
					return false;
				}
			}

			return true;
		}

		auto is_value_zeroed_out() const -> bool
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				if (!al::is_value_zero(this->m_array[i]))
				{
					return false;
				}
			}

			return true;
		}

		auto get_length() const -> T
		{
			return std::sqrt<T>(this->m_x * this->m_x + this->m_y * this->m_y);
		}

		auto negate() -> void
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = -this->m_array[i];
			}
		}

		auto normalize() -> void
		{
			T length = this->get_length();

			if (al::is_value_zero(length))
			{
				for (size_t i = 0; i < this->m_array.size(); ++i)
				{
					this->m_array[i] = std::numeric_limits<T>::infinity();
				}
			}
			else
			{
				length = static_cast<T>(1) / length;

				for (size_t i = 0; i < this->m_array.size(); ++i)
				{
					this->m_array[i] = this->m_array[i] * length;
				}
			}
		}

		auto translate(T x, T y) -> void
		{
			this->m_x = this->m_x + x;
			this->m_y = this->m_y + y;
		}

		auto translate(const VECTOR_2D& vector) -> void
		{
			this->m_x = this->m_x + vector.m_x;
			this->m_y = this->m_y + vector.m_y;
		}

		auto scale(T scale) -> void
		{
			this->m_x = this->m_x * scale;
			this->m_y = this->m_x * scale;
		}

		auto scale(T scale_x, T scale_y) -> void
		{
			this->m_x = this->m_x * scale_x;
			this->m_y = this->m_y * scale_y;
		}

		auto scale(const VECTOR_2D& vector) -> void
		{
			this->m_x = this->m_x * vector.m_x;
			this->m_y = this->m_y * vector.m_y;
		}

		auto rotate(T angle) -> void
		{
			this->m_x = this->m_x * std::cos<T>(angle) - this->m_y * std::sin<T>(angle);
			this->m_y = this->m_x * std::sin<T>(angle) + this->m_y * std::cos<T>(angle);
		}

		auto zero_out() -> void
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(0);
			}
		}

		auto get_indexed(size_t index) const -> const T&
		{
			ALLEGRO::ASSERT(index < this->m_array.size());
			return this->m_array[index];
		}

		auto get_indexed(size_t index) -> T&
		{
			ALLEGRO::ASSERT(index < this->m_array.size());
			return this->m_array[index];
		}

		auto operator[](size_t index) const -> const T&
		{
			ALLEGRO::ASSERT(index < this->m_array.size());
			return this->m_array[index];
		}

		auto operator[](size_t index)->T&
		{
			ALLEGRO::ASSERT(index < this->m_array.size());
			return this->m_array[index];
		}

		auto get_x() const -> const T&
		{
			return this->m_x;
		}

		auto get_x() -> T&
		{
			return this->m_x;
		}

		auto get_y() const -> const T&
		{
			return this->m_y;
		}

		auto get_y() -> T&
		{
			return this->m_y;
		}

		auto set_values(T x, T y) -> void
		{
			this->m_x = x;
			this->m_y = y;
		}

		auto set_x(T x) -> void
		{
			this->m_x = x;
		}

		auto set_y(T y) -> void
		{
			this->m_y = y;
		}

		auto get_array() const -> const std::array<T, ALLEGRO::VECTOR_2D_ARRAY_SIZE>&
		{
			return this->m_array;
		}

		auto get_array() -> std::array<T, ALLEGRO::VECTOR_2D_ARRAY_SIZE>&
		{
			return this->m_array;
		}

		auto operator == (const VECTOR_2D& v) const -> bool
		{
			return this->is_equal(v);
		}

		auto operator -() const -> VECTOR_2D
		{
			VECTOR_2D rv{ *this };

			rv.negate();

			return rv;
		}

		friend auto operator * (const VECTOR_2D& vector, T rhs) -> VECTOR_2D
		{
			VECTOR_2D rv{ vector };

			rv.scale(rhs);

			return rv;
		}

		friend auto operator / (const VECTOR_2D& vector, const T rhs) -> VECTOR_2D
		{
			VECTOR_2D rv{ vector };

			if (al::is_value_zero(rhs))
			{
				for (size_t i = 0; i < ALLEGRO::VECTOR_2D_ARRAY_SIZE; ++i)
				{
					rv.m_array[i] = std::numeric_limits<T>::infinity();
				}
			}
			else
			{
				rv.scale(static_cast<T>(1) / rhs);
			}

			return rv;
		}

		friend auto operator + (const VECTOR_2D& vector, const VECTOR_2D& rhs) -> VECTOR_2D
		{
			VECTOR_2D rv{ };

			for (size_t i = 0; i < ALLEGRO::VECTOR_2D_ARRAY_SIZE; ++i)
			{
				rv.m_array[i] = vector.m_array[i] + rhs.m_array[i];
			}

			return rv;
		}

		friend auto operator - (const VECTOR_2D& vector, const VECTOR_2D& rhs) -> VECTOR_2D
		{
			VECTOR_2D rv{ };

			for (size_t i = 0; i < ALLEGRO::VECTOR_2D_ARRAY_SIZE; ++i)
			{
				rv.m_array[i] = vector.m_array[i] - rhs.m_array[i];
			}

			return rv;
		}

		friend auto operator * (const VECTOR_2D& vector, const VECTOR_2D& rhs) -> VECTOR_2D
		{
			VECTOR_2D rv{ };

			for (size_t i = 0; i < ALLEGRO::VECTOR_2D_ARRAY_SIZE; ++i)
			{
				rv.m_array[i] = vector.m_array[i] * rhs.m_array[i];
			}

			return rv;
		}

		friend auto operator / (const VECTOR_2D& vector, const VECTOR_2D& rhs) -> VECTOR_2D
		{
			VECTOR_2D rv{ };

			for (size_t i = 0; i < ALLEGRO::VECTOR_2D_ARRAY_SIZE; ++i)
			{
				if (al::is_value_zero(rhs.m_array[i]))
				{
					rv.m_array[i] = std::numeric_limits<T>::infinity;
				}
				else
				{
					rv.m_array[i] = vector.m_array[i] / rhs.m_array[i];
				}
			}

			return rv;
		}

	private:
		union {
			struct {
				T m_x;
				T m_y;
			};
			std::array<T, ALLEGRO::VECTOR_2D_ARRAY_SIZE> m_array{};
		};
	};
}

namespace al
{
	export template <typename T> auto negate_point(const ALLEGRO::VECTOR_2D<T>& vector) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.negate();

		return rv;
	}

	export template <typename T> auto normalize_point(const ALLEGRO::VECTOR_2D<T>& vector) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.normalize();

		return rv;
	}

	export template <typename T> auto translate_point(const ALLEGRO::VECTOR_2D<T>& vector, const ALLEGRO::VECTOR_2D<T>& point2) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.translate(point2);

		return rv;
	}

	export template <typename T> auto translate_point(const ALLEGRO::VECTOR_2D<T>& vector, T translate_x, T translate_y) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.translate(translate_x, translate_y);

		return rv;
	}

	export template <typename T> auto scale_point(const ALLEGRO::VECTOR_2D<T>& vector, const ALLEGRO::VECTOR_2D<T>& point2) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.scale(point2);

		return rv;
	}

	export template <typename T> auto scale_point(const ALLEGRO::VECTOR_2D<T>& vector, T scale_amount) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.scale(scale_amount);

		return rv;
	}

	export template <typename T> auto scale_point(const ALLEGRO::VECTOR_2D<T>& vector, T scale_x, T scale_y) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.scale(scale_x, scale_y);

		return rv;
	}

	export template <typename T> auto rotate_point(const ALLEGRO::VECTOR_2D<T>& vector, T angle_change) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv{ vector };

		rv.rotate(angle_change);

		return rv;
	}

	export template <typename T> auto get_point_difference(const ALLEGRO::VECTOR_2D<T>& vector, const ALLEGRO::VECTOR_2D<T>& point2) -> ALLEGRO::VECTOR_2D<T>
	{
		ALLEGRO::VECTOR_2D<T> rv
		{
			std::fabsf(vector.get_x()() - point2.get_x()()),
			std::fabsf(vector.get_y()() - point2.get_y()())
		};

		return rv;
	}

	export template <typename T> auto calculate_distance_between_points(const ALLEGRO::VECTOR_2D<T>& vector, const ALLEGRO::VECTOR_2D<T>& point2) -> T
	{
		return difference(vector, point2).get_length();
	}

	export template <typename T> auto calculate_point_dot_product(const ALLEGRO::VECTOR_2D<T>& vector, const ALLEGRO::VECTOR_2D<T>& point2) -> T
	{
		T sum{ static_cast<T>(0) };
		const std::array<T, ALLEGRO::VECTOR_2D_ARRAY_SIZE>& point_array1 = vector.get_array();
		const std::array<T, ALLEGRO::VECTOR_2D_ARRAY_SIZE>& point_array2 = point2.get_array();

		for (size_t i = 0; i < ALLEGRO::VECTOR_2D_ARRAY_SIZE; ++i)
		{
			sum += (point_array1[i] * point_array2[i]);
		}

		return sum;
	}
}

export template <typename T> inline auto operator *= (const ALLEGRO::VECTOR_2D<T>& a, T b) -> ALLEGRO::VECTOR_2D<T>&
{
	a = (a * b);

	return a;
}

export template <typename T> inline auto operator /= (const ALLEGRO::VECTOR_2D<T>& a, const T b) -> ALLEGRO::VECTOR_2D<T>&
{
	a = (a / b);

	return a;
}

export template <typename T> auto operator += (ALLEGRO::VECTOR_2D<T>& a, const ALLEGRO::VECTOR_2D<T>& b) -> ALLEGRO::VECTOR_2D<T>&
{
	a = (a + b);

	return a;
}

export template <typename T> auto operator -= (ALLEGRO::VECTOR_2D<T>& a, const ALLEGRO::VECTOR_2D<T>& b) -> ALLEGRO::VECTOR_2D<T>&
{
	a = (a - b);

	return a;
}

export template <typename T> auto operator *= (ALLEGRO::VECTOR_2D<T>& a, const ALLEGRO::VECTOR_2D<T>& b) -> ALLEGRO::VECTOR_2D<T>&
{
	a = (a * b);

	return a;
}

export template <typename T> auto operator /= (ALLEGRO::VECTOR_2D<T>& a, const ALLEGRO::VECTOR_2D<T>& b) -> ALLEGRO::VECTOR_2D<T>&
{
	a = (a / b);

	return a;
}
