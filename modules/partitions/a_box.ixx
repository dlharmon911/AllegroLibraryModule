export module allegro:box;

import std;
import :base;
import :vector_2d;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export constexpr size_t BOX_ARRAY_SIZE{ 4 };
	}

	export template <typename T> struct BOX
	{
		using TYPE = typename T;

		constexpr BOX()
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(0);
			}
		}

		constexpr BOX(const T _left, const T _top, const T _right, const T _bottom)
		{
			this->m_top_left = VECTOR_2D(_left, _top);
			this->m_bottom_right = VECTOR_2D(_right, _bottom);
		}

		constexpr BOX(const VECTOR_2D<T> _top_left, const VECTOR_2D<T> _bottom_right)
		{
			this->m_top_left = _top_left;
			this->m_bottom_right = _bottom_right;
		}

		constexpr BOX(const BOX& box)
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = box.m_array[i];
			}
		}

		template <typename Q> constexpr BOX(const Q _left, const Q _top, const Q _right, const Q _bottom)
		{
			this->m_top_left = VECTOR_2D(_left, _top);
			this->m_bottom_right = VECTOR_2D(_right, _bottom);
		}

		template <typename Q> constexpr BOX(const VECTOR_2D<Q> _top_left, VECTOR_2D<Q> _bottom_right)
		{
			this->m_top_left = _top_left;
			this->m_bottom_right = _bottom_right;
		}

		template <typename Q> explicit constexpr BOX<T>(const BOX<Q>& box)
		{
			this->m_top_left = box.m_top_left;
			this->m_bottom_right = box.m_bottom_right;
		}

		constexpr BOX(const std::array<T, ALLEGRO::INTERNAL::BOX_ARRAY_SIZE>& array)
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}
		}

		virtual ~BOX() {}

		constexpr auto operator =(const std::array<T, ALLEGRO::INTERNAL::BOX_ARRAY_SIZE>& array) -> BOX&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}

			return *this;
		}

		constexpr auto operator = (const BOX& box) -> BOX&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = box.m_array[i];
			}

			return *this;
		}

		auto get_x() -> T&
		{
			return this->m_top_left.get_x();
		}

		auto get_x() const -> const T&
		{
			return this->m_top_left.get_x();
		}

		auto get_y() -> T&
		{
			return this->m_top_left.get_y();
		}

		auto get_y() const -> const T&
		{
			return this->m_top_left.get_y();
		}

		auto get_width() -> T&
		{
			return this->m_bottom_right.get_x() - this->m_top_left.get_x() + 1;
		}

		auto get_width() const -> const T&
		{
			return this->m_bottom_right.get_x() - this->m_top_left.get_x() + 1;
		}

		auto get_height() -> T&
		{
			return this->m_bottom_right.get_y() - this->m_top_left.get_y() + 1;
		}

		auto get_height() const -> const T&
		{
			return this->m_bottom_right.get_y() - this->m_top_left.get_y() + 1;
		}

		auto get_top_left() -> VECTOR_2D<T>&
		{
			return this->m_top_left;
		}

		auto get_top_left() const -> const VECTOR_2D<T>&
		{
			return this->m_top_left;
		}

		auto get_bottom_right() -> VECTOR_2D<T>&
		{
			return this->m_bottom_right;
		}

		auto get_bottom_right() const -> const VECTOR_2D<T>&
		{
			return this->m_bottom_right;
		}

		auto get_array() const -> const std::array<T, ALLEGRO::INTERNAL::BOX_ARRAY_SIZE>&
		{
			return this->m_array;
		}

	private:
		union
		{
			struct
			{
				VECTOR_2D<T> m_top_left;
				VECTOR_2D<T> m_bottom_right;
			};
			std::array<T, ALLEGRO::INTERNAL::BOX_ARRAY_SIZE> m_array{};
		};
	};
}
