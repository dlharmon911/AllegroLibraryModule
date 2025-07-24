export module allegro:vector_4d;

import std;
import :base;
import :error;

namespace ALLEGRO
{
	export constexpr size_t VECTOR_4D_ARRAY_SIZE{ 4 };

	export template <typename T> class VECTOR_4D
	{
	public:
		using TYPE = typename T;

		constexpr VECTOR_4D()
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(0);
			}
		}

		constexpr VECTOR_4D(const T _x, const T _y, const T _z, const T _w)
		{
			this->m_x = _x;
			this->m_y = _y;
			this->m_z = _z;
			this->m_w = _w;
		}

		constexpr VECTOR_4D(const VECTOR_4D<T>& v)
		{
			this->m_x = v.m_x;
			this->m_y = v.m_y;
			this->m_z = v.m_z;
			this->m_w = v.m_w;
		}

		template <typename Q> constexpr VECTOR_4D(const Q _x, const Q _y, const Q _z, const Q _w)
		{
			this->m_x = static_case<T>(_x);
			this->m_y = static_case<T>(_y);
			this->m_z = static_case<T>(_z);
			this->m_w = static_case<T>(_w);
		}

		template <typename Q> explicit constexpr VECTOR_4D<T>(const VECTOR_4D<Q>& v)
		{
			this->m_x = static_case<T>(v.m_x);
			this->m_y = static_case<T>(v.m_y);
			this->m_z = static_case<T>(v.m_z);
			this->m_w = static_case<T>(v.m_w);
		}

		constexpr VECTOR_4D(const std::array<T, ALLEGRO::VECTOR_4D_ARRAY_SIZE>& array)
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}
		}

		constexpr auto operator =(const std::array<T, ALLEGRO::VECTOR_4D_ARRAY_SIZE>& array) -> VECTOR_4D&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}

			return *this;
		}

		constexpr auto operator =(const VECTOR_4D& vector) -> VECTOR_4D&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = vector.m_array[i];
			}

			return *this;
		}

		constexpr ~VECTOR_4D() = default;

		auto zero_out() -> void
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(0);
			}
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

		auto get_x() const -> T
		{
			return this->m_x;
		}

		auto get_y() const -> T
		{
			return this->m_y;
		}

		auto get_z() const -> T
		{
			return this->m_z;
		}

		auto get_w() const -> T
		{
			return this->m_w;
		}

		auto set_x(T x) -> void
		{
			this->m_x = x;
		}

		auto set_y(T y) -> void
		{
			this->m_y = y;
		}

		auto set_z(T z) -> void
		{
			this->m_z = z;
		}

		auto set_w(T w) -> void
		{
			this->m_w = w;
		}

		auto get_array() const -> const std::array<T, ALLEGRO::VECTOR_4D_ARRAY_SIZE>&
		{
			return this->m_array;
		}

	private:
		union {
			struct {
				T m_x;
				T m_y;
				T m_z;
				T m_w;
			};
			std::array<T, ALLEGRO::VECTOR_4D_ARRAY_SIZE> m_array{};
		};
	};
}
