export module allegro:base;

import <string>;
import <cstdint>;
import <memory>;
import <allegro5/base.h>;
import <type_traits>;

export using cptr_t = std::add_pointer_t<char>;
export using vptr_t = std::add_pointer_t<void>;

namespace ALLEGRO
{
	export constexpr uint8_t VERSION = ALLEGRO_VERSION;
	export constexpr uint8_t SUB_VERSION = ALLEGRO_SUB_VERSION;
	export constexpr uint8_t WIP_VERSION = ALLEGRO_WIP_VERSION;
	export constexpr uint8_t UNSTABLE_BIT = ALLEGRO_UNSTABLE_BIT;
	export constexpr uint8_t RELEASE_NUMBER = ALLEGRO_RELEASE_NUMBER;
	export const char* VERSION_STR = (const char*)ALLEGRO_VERSION_STR;
	export const char* DATE_STR = (const char*)ALLEGRO_DATE_STR;
	export constexpr int32_t DATE = ALLEGRO_DATE;
	export constexpr int32_t VERSION_INT = ALLEGRO_VERSION_INT;
	export constexpr double PI = ALLEGRO_PI;
}

namespace al
{
	export inline constexpr auto generate_id(uint32_t a, uint32_t b, uint32_t c, uint32_t d) -> uint32_t
	{
		return (((a) << 24) | ((b) << 16) | ((c) << 8) | (d));
	}

	export inline auto run_main(int32_t argc, char** argv, int32_t(*user_main)(int32_t, char**)) -> int32_t
	{
		return al_run_main(argc, argv, user_main);
	}
}

namespace ALLEGRO
{
	template <typename T> struct POINT;
	template <typename T> struct SIZE;

	export template <typename T> struct POINT
	{
		T x{ T(0) };
		T y{ T(0) };
		constexpr POINT() : x(T(0)), y(T(0)) {}
		constexpr POINT(const T _x, const T _y) : x(_x), y(_y) {}
		constexpr POINT(const POINT<T>& v) : x(v.x), y(v.y) {}
		explicit constexpr POINT(const SIZE<T>& v) : x(v.width), y(v.height) {}

		template <typename Q>
		constexpr POINT(const Q _x, const Q _y) : x((T)_x), y((T)_y) {}

		template <typename Q>
		constexpr POINT<T>(const POINT<Q>& point) : x((T)point.x), y((T)point.y) {}

		auto operator -() const -> const POINT<T>&
		{
			return POINT<T>{ -this->x, -this->y};
		}

		auto operator == (const POINT<T>& v) const -> bool
		{
			return (this->x == v.x && this->y == v.y);
		}
		auto operator != (const POINT<T>& v) const -> bool
		{
			return !this->operator==(v);
		}
	};

	export template <typename T> struct VECTOR3
	{
		T x{ T(0) };
		T y{ T(0) };
		T z{ T(0) };
		constexpr VECTOR3() : x(T(0)), y(T(0)), z(T(0)) {}
		constexpr VECTOR3(const T _x, const T _y, const T _z) : x(_x), y(_y), z(_z) {}
		constexpr VECTOR3(const VECTOR3<T>& v) : x(v.x), y(v.y), z(v.z) {}

		template <typename Q>
		constexpr VECTOR3(const Q _x, const Q _y, const Q _z) : x((T)_x), y((T)_y), z((T)_z) {}

		template <typename Q>
		constexpr VECTOR3<T>(const VECTOR3<Q>& v) : x((T)v.x), y((T)v.y), z((T)v.z) {}
	};

	export template <typename T> struct VECTOR4
	{
		T x{ T(0) };
		T y{ T(0) };
		T z{ T(0) };
		T w{ T(0) };
		constexpr VECTOR4() : x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}
		constexpr VECTOR4(const T _x, const T _y, const T _z, const T _w) : x(_x), y(_y), z(_z), w(_w) {}
		constexpr VECTOR4(const VECTOR4<T>& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

		template <typename Q>
		constexpr VECTOR4(const Q _x, const Q _y, const Q _z, const Q _w) : x((T)_x), y((T)_y), z((T)_z), w((T)_w) {}

		template <typename Q>
		constexpr VECTOR4<T>(const VECTOR4<Q>& v) : x((T)v.x), y((T)v.y), z((T)v.z), w((T)v.w) {}
	};

	export template <typename T> struct SIZE
	{
		T width{ T(0) };
		T height{ T(0) };
		constexpr SIZE() : width(T(0)), height(T(0)) {}
		constexpr SIZE(const T _width, const T _height) : width(_width), height(_height) {}
		constexpr SIZE(const SIZE<T>& v) : width(v.width), height(v.height) {}
		explicit constexpr SIZE(const POINT<T>& v) : width(v.x), height(v.y) {}

		template <typename Q>
		constexpr SIZE(const Q _width, const Q _height) : width((T)_width), height((T)_height) {}

		template <typename Q>
		constexpr SIZE<T>(const SIZE<Q>& size) : width((T)size.width), height((T)size.height) {}
	};

	export template <typename T> struct RECTANGLE
	{
		POINT<T> position{ T(0), T(0) };
		SIZE<T> size{ T(0), T(0) };
		constexpr RECTANGLE() : position(), size() {}
		constexpr RECTANGLE(const T _x, const T _y, const T _width, const T _height) : position(_x, _y), size(_width, _height) {}
		constexpr RECTANGLE(const POINT<T> _position, const SIZE<T> _size) : position(_position), size(_size) {}
		constexpr RECTANGLE(const RECTANGLE& r) : position(r.position), size(r.size) {}

		auto is_inside(const ALLEGRO::POINT<T>& point) -> bool
		{
			return (point.x >= this->position.x && point.x < (this->position.x + this->size.width) &&
				point.y >= this->position.y && point.y < (this->position.y + this->size.height));
		}

		template <typename Q>
		constexpr RECTANGLE(const Q _x, const Q _y, const Q _width, const Q _height) : position(POINT<T>(_x, _y)), size(SIZE<T>(_width, _height)) {}

		template <typename Q>
		constexpr RECTANGLE(const POINT<Q> _position, SIZE<Q> _size) : position(POINT<T>(_position)), size(SIZE<T>(_size)) {}

		template <typename Q>
		constexpr RECTANGLE<T>(const RECTANGLE<Q>& r) : position(POINT<T>(r.position)), size(SIZE<T>(r.size)) {}
	};

	export template <typename T> struct BOX
	{
		POINT<T> top_left{ T(0), T(0) };
		POINT<T> bottom_right{ T(0), T(0) };
		constexpr BOX() : top_left(), bottom_right() {}
		constexpr BOX(const T _left, const T _top, const T _right, const T _bottom) : top_left(_left, _top), bottom_right(_right, _bottom) {}
		constexpr BOX(const POINT<T> _top_left, const POINT<T> _bottom_right) : top_left(_top_left), bottom_right(_bottom_right) {}
		constexpr BOX(const BOX& r) : top_left(r.top_left), bottom_right(r.bottom_right) {}

		auto get_width() const -> T
		{
			return bottom_right.x - top_left.x + 1;
		}

		auto get_height() const -> T
		{
			return bottom_right.y - top_left.y + 1;
		}

		template <typename Q>
		constexpr BOX(const Q _left, const Q _top, const Q _right, const Q _bottom) : top_left(POINT<T>(_left, _top)), bottom_right(POINT<T>(_right, _bottom)) {}

		template <typename Q>
		constexpr BOX(const POINT<Q> _top_left, POINT<Q> _bottom_right) : top_left(POINT<T>(_top_left)), bottom_right(POINT<T>(_bottom_right)) {}

		template <typename Q>
		constexpr BOX<T>(const BOX<Q>& r) : top_left(POINT<T>(r.top_left)), bottom_right(POINT<T>(r.bottom_right)) {}
	};

	export template <typename T> auto operator * (const ALLEGRO::POINT<T>& a, T b) -> ALLEGRO::POINT<T>
	{
		return { a.x * (T)b, a.y * (T)b };
	}

	export template <typename T> auto operator / (const ALLEGRO::POINT<T>& a, const T b) -> ALLEGRO::POINT<T>
	{
		return { a.x / (T)b, a.y / (T)b };
	}

	export template <typename T> auto operator + (const ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>
	{
		return { a.x + (T)b.x, a.y + (T)b.y };
	}

	export template <typename T> auto operator - (const ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>
	{
		return { a.x - (T)b.x, a.y - (T)b.y };
	}

	export template <typename T> auto operator * (const ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>
	{
		return { a.x * (T)b.x, a.y * (T)b.y };
	}

	export template <typename T> auto operator / (const ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>
	{
		return { a.x / (T)b.x, a.y / (T)b.y };
	}

	export template <typename T> auto operator *= (const ALLEGRO::POINT<T>& a, T b) -> ALLEGRO::POINT<T>&
	{
		a = (a + b);

		return a;
	}

	export template <typename T> auto operator /= (const ALLEGRO::POINT<T>& a, const T b) -> ALLEGRO::POINT<T>&
	{
		a = (a / b);

		return a;
	}

	export template <typename T> auto operator += (ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>&
	{
		a = (a + b);

		return a;
	}

	export template <typename T> auto operator -= (ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>&
	{
		a = (a - b);

		return a;
	}

	export template <typename T> auto operator *= (ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>&
	{
		a = (a * b);

		return a;
	}

	export template <typename T> auto operator /= (ALLEGRO::POINT<T>& a, const ALLEGRO::POINT<T>& b) -> ALLEGRO::POINT<T>&
	{
		a = (a / b);

		return a;
	}
}