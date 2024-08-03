export module allegro:color;

import <cmath>;
import <limits>;
import <allegro5/color.h>;
import :base;

typedef struct _COLOR_STRUCT
{
	float red;
	float green;
	float blue;
	float alpha;
	constexpr _COLOR_STRUCT() : red(0.0f), green(0.0f), blue(0.0f), alpha(1.0f) {}
	explicit constexpr _COLOR_STRUCT(const ALLEGRO_COLOR& color) : red(color.r), green(color.g), blue(color.b), alpha(color.a) {}
	constexpr _COLOR_STRUCT(const float _red, const float _green, const float _blue, const float _alpha) : red(_red), green(_green), blue(_blue), alpha(_alpha) {}
	constexpr _COLOR_STRUCT(const _COLOR_STRUCT& v) : red(v.red), green(v.green), blue(v.blue), alpha(v.alpha) {}

	bool operator == (const _COLOR_STRUCT& v)
	{
		return (fabsf(v.red - this->red) <= std::numeric_limits<float>::epsilon() &&
			fabsf(v.green - this->green) <= std::numeric_limits<float>::epsilon() &&
			fabsf(v.blue - this->blue) <= std::numeric_limits<float>::epsilon() &&
			fabsf(v.alpha - this->alpha) <= std::numeric_limits<float>::epsilon());
	}

	bool operator != (const _COLOR_STRUCT& v)
	{
		return !(this->operator==(v));
	}

	explicit operator ALLEGRO_COLOR  ()
	{
		return ALLEGRO_COLOR(this->red, this->green, this->blue, this->alpha);
	}
} _COLOR_STRUCT;

namespace ALLEGRO
{
	export using COLOR_DATA = ALLEGRO_COLOR;
	export using COLOR = _COLOR_STRUCT;

	export enum
	{
		PIXEL_FORMAT_ANY = ::ALLEGRO_PIXEL_FORMAT_ANY,
		PIXEL_FORMAT_ANY_NO_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_NO_ALPHA,
		PIXEL_FORMAT_ANY_WITH_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_WITH_ALPHA,
		PIXEL_FORMAT_ANY_15_NO_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_15_NO_ALPHA,
		PIXEL_FORMAT_ANY_16_NO_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_16_NO_ALPHA,
		PIXEL_FORMAT_ANY_16_WITH_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_16_WITH_ALPHA,
		PIXEL_FORMAT_ANY_24_NO_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_24_NO_ALPHA,
		PIXEL_FORMAT_ANY_32_NO_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_32_NO_ALPHA,
		PIXEL_FORMAT_ANY_32_WITH_ALPHA = ::ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA,
		PIXEL_FORMAT_ARGB_8888 = ::ALLEGRO_PIXEL_FORMAT_ARGB_8888,
		PIXEL_FORMAT_RGBA_8888 = ::ALLEGRO_PIXEL_FORMAT_RGBA_8888,
		PIXEL_FORMAT_ARGB_4444 = ::ALLEGRO_PIXEL_FORMAT_ARGB_4444,
		PIXEL_FORMAT_RGB_888 = ::ALLEGRO_PIXEL_FORMAT_RGB_888,
		PIXEL_FORMAT_RGB_565 = ::ALLEGRO_PIXEL_FORMAT_RGB_565,
		PIXEL_FORMAT_RGB_555 = ::ALLEGRO_PIXEL_FORMAT_RGB_555,
		PIXEL_FORMAT_RGBA_5551 = ::ALLEGRO_PIXEL_FORMAT_RGBA_5551,
		PIXEL_FORMAT_ARGB_1555 = ::ALLEGRO_PIXEL_FORMAT_ARGB_1555,
		PIXEL_FORMAT_ABGR_8888 = ::ALLEGRO_PIXEL_FORMAT_ABGR_8888,
		PIXEL_FORMAT_XBGR_8888 = ::ALLEGRO_PIXEL_FORMAT_XBGR_8888,
		PIXEL_FORMAT_BGR_888 = ::ALLEGRO_PIXEL_FORMAT_BGR_888,
		PIXEL_FORMAT_BGR_565 = ::ALLEGRO_PIXEL_FORMAT_BGR_565,
		PIXEL_FORMAT_BGR_555 = ::ALLEGRO_PIXEL_FORMAT_BGR_555,
		PIXEL_FORMAT_RGBX_8888 = ::ALLEGRO_PIXEL_FORMAT_RGBX_8888,
		PIXEL_FORMAT_XRGB_8888 = ::ALLEGRO_PIXEL_FORMAT_XRGB_8888,
		PIXEL_FORMAT_ABGR_F32 = ::ALLEGRO_PIXEL_FORMAT_ABGR_F32,
		PIXEL_FORMAT_ABGR_8888_LE = ::ALLEGRO_PIXEL_FORMAT_ABGR_8888_LE,
		PIXEL_FORMAT_RGBA_4444 = ::ALLEGRO_PIXEL_FORMAT_RGBA_4444,
		PIXEL_FORMAT_SINGLE_CHANNEL_8 = ::ALLEGRO_PIXEL_FORMAT_SINGLE_CHANNEL_8,
		PIXEL_FORMAT_COMPRESSED_RGBA_DXT1 = ::ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT1,
		PIXEL_FORMAT_COMPRESSED_RGBA_DXT2 = ::ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT3,
		PIXEL_FORMAT_COMPRESSED_RGBA_DXT3 = ::ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT5,
		PIXEL_FORMAT_COUNT = ::ALLEGRO_NUM_PIXEL_FORMATS
	};
}

namespace al
{
	export inline int32_t get_pixel_format_size(int32_t format)
	{
		return ::al_get_pixel_size(format);
	}

	export inline int32_t get_pixel_format_bits(int32_t format)
	{
		return ::al_get_pixel_format_bits(format);
	}

	export inline int32_t get_pixel_format_block_size(int32_t format)
	{
		return ::al_get_pixel_block_size(format);
	}

	export inline int32_t get_pixel_format_block_width(int32_t format)
	{
		return ::al_get_pixel_block_width(format);
	}

	export inline int32_t get_pixel_format_block_height(int32_t format)
	{
		return ::al_get_pixel_block_height(format);
	}

	export inline ALLEGRO::COLOR map_rgba_f(float red, float green, float blue, float alpha, bool premultiply_alpha = false)
	{
		if (premultiply_alpha)
		{
			return (ALLEGRO::COLOR)al_premul_rgba_f(red, green, blue, alpha);
		}

		return (ALLEGRO::COLOR)al_map_rgba_f(red, green, blue, alpha);
	}

	export inline ALLEGRO::COLOR map_rgb_f(float red, float green, float blue)
	{
		return (ALLEGRO::COLOR)al_map_rgb_f(red, green, blue);
	}

	export inline ALLEGRO::COLOR map_rgba(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha, bool premultiply_alpha = false)
	{
		if (premultiply_alpha)
		{
			return (ALLEGRO::COLOR)al_premul_rgba(red, green, blue, alpha);
		}

		return (ALLEGRO::COLOR)al_map_rgba(red, green, blue, alpha);
	}

	export inline ALLEGRO::COLOR map_rgb(uint8_t red, uint8_t green, uint8_t blue)
	{
		return map_rgba(red, green, blue, 0xff, false);
	}

	export inline void unmap_rgba_f(ALLEGRO::COLOR color, float& red, float& green, float& blue, float& alpha)
	{
		al_unmap_rgba_f((ALLEGRO::COLOR_DATA)color, &red, &green, &blue, &alpha);
	}

	export inline void unmap_rgb_f(ALLEGRO::COLOR color, float& red, float& green, float& blue)
	{
		al_unmap_rgb_f((ALLEGRO::COLOR_DATA)color, &red, &green, &blue);
	}

	export inline void unmap_rgba(ALLEGRO::COLOR color, uint8_t& red, uint8_t& green, uint8_t& blue, uint8_t& alpha)
	{
		al_unmap_rgba((ALLEGRO::COLOR_DATA)color, &red, &green, &blue, &alpha);
	}

	export inline void unmap_rgb(ALLEGRO::COLOR color, uint8_t& red, uint8_t& green, uint8_t& blue)
	{
		al_unmap_rgb((ALLEGRO::COLOR_DATA)color, &red, &green, &blue);
	}
}
