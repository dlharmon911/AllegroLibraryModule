export module allegro:rectangle;

import std;
import :base;
import :vector_2d;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export constexpr size_t RECTANGLE_ARRAY_SIZE{ 4 };
	}

	export template <typename T> class RECTANGLE
	{
	public:
		using TYPE = typename T;

		constexpr RECTANGLE()
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(0);
			}
		}

		constexpr RECTANGLE(const T _x, const T _y, const T _width, const T _height)
		{
			this->m_position = VECTOR_2D(_x, _y);
			this->m_size = VECTOR_2D(_width, _height);
		}

		constexpr RECTANGLE(const VECTOR_2D<T>& _position, const VECTOR_2D<T>& _size)
		{
			this->m_position = _position;
			this->m_size = _size;
		}

		constexpr RECTANGLE(const RECTANGLE& rectangle)
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = rectangle.m_array[i];
			}
		}

		~RECTANGLE() = default;

		auto is_inside(const ALLEGRO::VECTOR_2D<T>& point) -> bool
		{
			return (point.get_x() >= this->position.get_x() && 
				point.get_x() < (this->position.get_x() + this->size.get_x()) &&
				point.get_y() >= this->position.get_y() && 
				point.get_y() < (this->position.get_y() + this->size.get_y()));
		}

		template <typename Q> constexpr RECTANGLE(const Q _x, const Q _y, const Q _width, const Q _height)
		{
			this->m_position = VECTOR_2D<T>(_x, _y);
			this->m_size = VECTOR_2D<T>(_width, _height);
		}

		template <typename Q> constexpr RECTANGLE(const VECTOR_2D<Q> _position, VECTOR_2D<Q> _size)
		{
			this->m_position = VECTOR_2D<T>(_position);
			this->m_size = VECTOR_2D<T>(_size);
		}

		template <typename Q> explicit constexpr RECTANGLE(const RECTANGLE<Q>& rectangle)
		{
			const auto& array = rectangle.get_array();

			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = static_cast<T>(array[i]);
			}
		}

		explicit constexpr RECTANGLE(const std::array<T, ALLEGRO::INTERNAL::RECTANGLE_ARRAY_SIZE>& array)
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}
		}

		auto operator =(const std::array<T, ALLEGRO::INTERNAL::RECTANGLE_ARRAY_SIZE>& array) -> RECTANGLE&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = array[i];
			}

			return *this;
		}

		constexpr auto operator = (const RECTANGLE& rectangle) -> RECTANGLE&
		{
			for (size_t i = 0; i < this->m_array.size(); ++i)
			{
				this->m_array[i] = rectangle.m_array[i];
			}

			return *this;
		}

		auto set_position(const VECTOR_2D<T>& position) -> void
		{
			this->m_position = position;
		}

		auto set_position(T x, T y) -> void
		{
			this->m_position = VECTOR_2D(x, y);
		}

		auto set_size(const VECTOR_2D<T>& size) -> void
		{
			this->m_size = size;
		}

		auto set_size(T width, T height) -> void
		{
			this->m_position = VECTOR_2D(width, height);
		}

		auto get_x() const -> T
		{
			return this->m_position.get_x();
		}

		auto get_y() const -> T
		{
			return this->m_position.get_y();
		}

		auto get_width() const -> T
		{
			return this->m_size.get_x();
		}

		auto get_height() const -> T
		{
			return this->m_size.get_y();
		}

		auto set_x(T x) -> void
		{
			this->m_position.set_x(x);
		}

		auto set_y(T y) -> void
		{
			this->m_position.set_y(y);
		}

		auto set_width(T width) -> void
		{
			this->m_size.set_x(width);
		}

		auto set_height(T height) -> void
		{
			this->m_size.set_y(height);
		}

		auto get_position() const -> const VECTOR_2D<T>&
		{
			return this->m_position;
		}

		auto get_size() const -> const VECTOR_2D<T>&
		{
			return this->m_size;
		}

		auto get_array() const -> const std::array<T, ALLEGRO::INTERNAL::RECTANGLE_ARRAY_SIZE>&
		{
			return this->m_array;
		}

	private:
		union
		{
			struct
			{
				VECTOR_2D<T> m_position;
				VECTOR_2D<T> m_size;
			};
			std::array<T, ALLEGRO::INTERNAL::RECTANGLE_ARRAY_SIZE> m_array{};
		};
	};
}
