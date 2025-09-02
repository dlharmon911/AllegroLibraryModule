export module allegro:color;

import std;
import <allegro5/color.h>;
import :base;
import :math;

namespace ALLEGRO
{
	export using COLOR = typename ALLEGRO_COLOR;

	export constexpr int32_t PIXEL_FORMAT_ANY{ ALLEGRO_PIXEL_FORMAT_ANY };
	export constexpr int32_t PIXEL_FORMAT_ANY_NO_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_NO_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ANY_WITH_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_WITH_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ANY_15_NO_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_15_NO_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ANY_16_NO_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_16_NO_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ANY_16_WITH_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_16_WITH_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ANY_24_NO_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_24_NO_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ANY_32_NO_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_32_NO_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ANY_32_WITH_ALPHA{ ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA };
	export constexpr int32_t PIXEL_FORMAT_ARGB_8888{ ALLEGRO_PIXEL_FORMAT_ARGB_8888 };
	export constexpr int32_t PIXEL_FORMAT_RGBA_8888{ ALLEGRO_PIXEL_FORMAT_RGBA_8888 };
	export constexpr int32_t PIXEL_FORMAT_ARGB_4444{ ALLEGRO_PIXEL_FORMAT_ARGB_4444 };
	export constexpr int32_t PIXEL_FORMAT_RGB_888{ ALLEGRO_PIXEL_FORMAT_RGB_888 };
	export constexpr int32_t PIXEL_FORMAT_RGB_565{ ALLEGRO_PIXEL_FORMAT_RGB_565 };
	export constexpr int32_t PIXEL_FORMAT_RGB_555{ ALLEGRO_PIXEL_FORMAT_RGB_555 };
	export constexpr int32_t PIXEL_FORMAT_RGBA_5551{ ALLEGRO_PIXEL_FORMAT_RGBA_5551 };
	export constexpr int32_t PIXEL_FORMAT_ARGB_1555{ ALLEGRO_PIXEL_FORMAT_ARGB_1555 };
	export constexpr int32_t PIXEL_FORMAT_ABGR_8888{ ALLEGRO_PIXEL_FORMAT_ABGR_8888 };
	export constexpr int32_t PIXEL_FORMAT_XBGR_8888{ ALLEGRO_PIXEL_FORMAT_XBGR_8888 };
	export constexpr int32_t PIXEL_FORMAT_BGR_888{ ALLEGRO_PIXEL_FORMAT_BGR_888 };
	export constexpr int32_t PIXEL_FORMAT_BGR_565{ ALLEGRO_PIXEL_FORMAT_BGR_565 };
	export constexpr int32_t PIXEL_FORMAT_BGR_555{ ALLEGRO_PIXEL_FORMAT_BGR_555 };
	export constexpr int32_t PIXEL_FORMAT_RGBX_8888{ ALLEGRO_PIXEL_FORMAT_RGBX_8888 };
	export constexpr int32_t PIXEL_FORMAT_XRGB_8888{ ALLEGRO_PIXEL_FORMAT_XRGB_8888 };
	export constexpr int32_t PIXEL_FORMAT_ABGR_F32{ ALLEGRO_PIXEL_FORMAT_ABGR_F32 };
	export constexpr int32_t PIXEL_FORMAT_ABGR_8888_LE{ ALLEGRO_PIXEL_FORMAT_ABGR_8888_LE };
	export constexpr int32_t PIXEL_FORMAT_RGBA_4444{ ALLEGRO_PIXEL_FORMAT_RGBA_4444 };
	export constexpr int32_t PIXEL_FORMAT_SINGLE_CHANNEL_8{ ALLEGRO_PIXEL_FORMAT_SINGLE_CHANNEL_8 };
	export constexpr int32_t PIXEL_FORMAT_COMPRESSED_RGBA_DXT1{ ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT1 };
	export constexpr int32_t PIXEL_FORMAT_COMPRESSED_RGBA_DXT2{ ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT3 };
	export constexpr int32_t PIXEL_FORMAT_COMPRESSED_RGBA_DXT3{ ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT5 };
	export constexpr int32_t PIXEL_FORMAT_COUNT{ ALLEGRO_NUM_PIXEL_FORMATS };
}

namespace al
{
	export inline auto get_pixel_format_size(int32_t format) -> int32_t
	{
		return ::al_get_pixel_size(format);
	}

	export inline auto get_pixel_format_bits(int32_t format) -> int32_t
	{
		return ::al_get_pixel_format_bits(format);
	}

	export inline auto get_pixel_format_block_size(int32_t format) -> int32_t
	{
		return ::al_get_pixel_block_size(format);
	}

	export inline auto get_pixel_format_block_width(int32_t format) -> int32_t
	{
		return ::al_get_pixel_block_width(format);
	}

	export inline auto get_pixel_format_block_height(int32_t format) -> int32_t
	{
		return ::al_get_pixel_block_height(format);
	}

	export constexpr auto map_rgba_f(float red, float green, float blue, float alpha, bool premultiply_alpha = false) -> ALLEGRO::COLOR
	{
		ALLEGRO::COLOR color{ red, green, blue, 1.0f };

		if (premultiply_alpha)
		{
			color.r *= alpha;
			color.g *= alpha;
			color.b *= alpha;
		}

		return color;
	}

	export constexpr auto map_rgb_f(float red, float green, float blue) -> ALLEGRO::COLOR
	{
		ALLEGRO::COLOR color{ red, green, blue, 1.0f };
		return color;
	}

	export inline auto map_rgba(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha, bool premultiply_alpha = false) -> ALLEGRO::COLOR
	{
		if (premultiply_alpha)
		{
			return static_cast<ALLEGRO::COLOR>(al_premul_rgba(red, green, blue, alpha));
		}

		return static_cast<ALLEGRO::COLOR>(al_map_rgba(red, green, blue, alpha));
	}

	export inline auto map_rgb(uint8_t red, uint8_t green, uint8_t blue) -> ALLEGRO::COLOR
	{
		return map_rgba(red, green, blue, 0xff, false);
	}

	export inline auto unmap_rgba_f(const ALLEGRO::COLOR& color, float& red, float& green, float& blue, float& alpha) -> void
	{
		al_unmap_rgba_f(color, &red, &green, &blue, &alpha);
	}

	export inline auto unmap_rgb_f(const ALLEGRO::COLOR& color, float& red, float& green, float& blue) -> void
	{
		al_unmap_rgb_f(color, &red, &green, &blue);
	}

	export inline auto unmap_rgba(const ALLEGRO::COLOR& color, uint8_t& red, uint8_t& green, uint8_t& blue, uint8_t& alpha) -> void
	{
		al_unmap_rgba(color, &red, &green, &blue, &alpha);
	}

	export inline auto unmap_rgb(const ALLEGRO::COLOR& color, uint8_t& red, uint8_t& green, uint8_t& blue) -> void
	{
		al_unmap_rgb(color, &red, &green, &blue);
	}

	export inline auto equal_colors(const ALLEGRO::COLOR& color1, const ALLEGRO::COLOR& color2)
	{
		if (std::fabs(color1.r - color2.r) > std::numeric_limits<float>::epsilon() ||
			std::fabs(color1.g - color2.g) > std::numeric_limits<float>::epsilon() ||
			std::fabs(color1.b - color2.b) > std::numeric_limits<float>::epsilon() ||
			std::fabs(color1.a - color2.a) > std::numeric_limits<float>::epsilon())
		{
			return false;
		}

		return true;
	}
}

export auto operator == (const ALLEGRO::COLOR& color1, const ALLEGRO::COLOR& color2) -> bool
{
	return al::equal_colors(color1, color2);
}
