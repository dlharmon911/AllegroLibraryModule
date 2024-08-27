export module allegro:base;

import <string>;
import <cstdint>;
import <memory>;
import <allegro5/base.h>;

namespace al
{
	export inline constexpr uint8_t get_version()
	{
		return ALLEGRO_VERSION;
	}

	export inline constexpr uint8_t get_version_sub()
	{
		return ALLEGRO_SUB_VERSION;
	}

	export inline constexpr uint8_t get_version_wip()
	{
		return ALLEGRO_WIP_VERSION;
	}

	export inline constexpr uint8_t get_version_unstable_bit()
	{
		return ALLEGRO_UNSTABLE_BIT;
	}

	export inline constexpr uint8_t get_version_release_number()
	{
		return ALLEGRO_RELEASE_NUMBER;
	}

	export inline const char* get_version_string()
	{
		return (const char*)ALLEGRO_VERSION_STR;
	}

	export inline const char* get_version_date_string()
	{
		return (const char*)ALLEGRO_DATE_STR;
	}

	export inline constexpr int32_t get_version_date()
	{
		return ALLEGRO_DATE;
	}

	export inline constexpr int32_t get_version_as_integer()
	{
		return ALLEGRO_VERSION_INT;
	}

	export inline constexpr double get_pi()
	{
		return ALLEGRO_PI;
	}

	export inline uint32_t generate_id(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
	{
		return (((a) << 24) | ((b) << 16) | ((c) << 8) | (d));
	}

	export using ::al_get_allegro_version;
	export using ::al_run_main;
}

namespace ALLEGRO
{
	export using OBJECT_TYPE = std::shared_ptr<void>;
	export using CONST_OBJECT_TYPE = std::shared_ptr<const void>;

	export template <typename T> struct POINT
	{
		T x;
		T y;
		constexpr POINT() : x(T(0)), y(T(0)) {}
		constexpr POINT(const T _x, const T _y) : x(_x), y(_y) {}
		constexpr POINT(const POINT& v) : x(v.x), y(v.y) {}

		template <typename Q>
		constexpr POINT(const Q _x, const Q _y) : x((T)_x), y((T)_y) {}

		template <typename Q>
		constexpr POINT<T>(const POINT<Q>& point) : x((T)point.x), y((T)point.y) {}
	};

	export template <typename T> struct VECTOR3
	{
		T x;
		T y;
		T z;
		constexpr VECTOR3() : x(T(0)), y(T(0)), z(T(0)) {}
		constexpr VECTOR3(const T _x, const T _y, const T _z) : x(_x), y(_y), z(_z) {}
		constexpr VECTOR3(const VECTOR3& v) : x(v.x), y(v.y), z(v.z) {}

		template <typename Q>
		constexpr VECTOR3(const Q _x, const Q _y, const Q _z) : x((T)_x), y((T)_y), z((T)_z) {}

		template <typename Q>
		constexpr VECTOR3<T>(const VECTOR3<Q>& v) : x((T)v.x), y((T)v.y), z((T)v.z) {}
	};

	export template <typename T> struct VECTOR4
	{
		T x;
		T y;
		T z;
		T w;
		constexpr VECTOR4() : x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}
		constexpr VECTOR4(const T _x, const T _y, const T _z, const T _w) : x(_x), y(_y), z(_z), w(_w) {}
		constexpr VECTOR4(const VECTOR4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

		template <typename Q>
		constexpr VECTOR4(const Q _x, const Q _y, const Q _z, const Q _w) : x((T)_x), y((T)_y), z((T)_z), w((T)_w) {}

		template <typename Q>
		constexpr VECTOR4<T>(const VECTOR4<Q>& v) : x((T)v.x), y((T)v.y), z((T)v.z), w((T)v.w) {}
	};

	export template <typename T> struct SIZE
	{
		T width;
		T height;
		constexpr SIZE() : width(T(0)), height(T(0)) {}
		constexpr SIZE(const T _width, const T _height) : width(_width), height(_height) {}
		constexpr SIZE(const SIZE& v) : width(v.width), height(v.height) {}

		template <typename Q>
		constexpr SIZE(const Q _width, const Q _height) : width((T)_width), height((T)_height) {}

		template <typename Q>
		constexpr SIZE<T>(const SIZE<Q>& size) : width((T)size.width), height((T)size.height) {}
	};

	export template <typename T> struct RECTANGLE
	{
		POINT<T> position;
		SIZE<T> size;
		constexpr RECTANGLE() : position(), size() {}
		constexpr RECTANGLE(const T _x, const T _y, const T _width, const T _height) : position(_x, _y), size(_width, _height) {}
		constexpr RECTANGLE(const POINT<T> _position, const SIZE<T> _size) : position(_position), size(_size) {}
		constexpr RECTANGLE(const RECTANGLE& r) : position(r.position), size(r.size) {}

		template <typename Q>
		constexpr RECTANGLE(const Q _x, const Q _y, const Q _width, const Q _height) : position(POINT<T>(_x, _y)), size(SIZE<T>(_width, _height)) {}

		template <typename Q>
		constexpr RECTANGLE(const POINT<Q> _position, SIZE<Q> _size) : position(POINT<T>(_position)), size(SIZE<T>(_size)) {}

		template <typename Q>
		constexpr RECTANGLE<T>(const RECTANGLE<Q>& r) : position(POINT<T>(r.position)), size(SIZE<T>(r.size)) {}
	};

	export template <typename T> struct BOX
	{
		POINT<T> top_left;
		POINT<T> bottom_right;
		constexpr BOX() : top_left(), bottom_right() {}
		constexpr BOX(const T _left, const T _top, const T _right, const T _bottom) : top_left(_left, _top), bottom_right(_right, _bottom) {}
		constexpr BOX(const POINT<T> _top_left, const POINT<T> _bottom_right) : top_left(_top_left), bottom_right(_bottom_right) {}
		constexpr BOX(const BOX& r) : top_left(r.top_left), bottom_right(r.bottom_right) {}

		template <typename Q>
		constexpr BOX(const Q _left, const Q _top, const Q _right, const Q _bottom) : top_left(POINT<T>(_left, _top)), bottom_right(POINT<T>(_right, _bottom)) {}

		template <typename Q>
		constexpr BOX(const POINT<Q> _top_left, POINT<Q> _bottom_right) : top_left(POINT<T>(_top_left)), bottom_right(POINT<T>(_bottom_right)) {}

		template <typename Q>
		constexpr BOX<T>(const BOX<Q>& r) : top_left(POINT<T>(r.top_left)), bottom_right(POINT<T>(r.bottom_right)) {}
	};
}
