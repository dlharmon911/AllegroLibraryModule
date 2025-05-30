export module allegro:color;

import <cmath>;
import <limits>;
import <allegro5/color.h>;
import :base;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		struct COLOR_TAG
		{
			float red{ 0.0f };
			float green{ 0.0f };
			float blue{ 0.0f };
			float alpha{ 0.0f };
			constexpr COLOR_TAG() = default;
			explicit constexpr COLOR_TAG(const ALLEGRO_COLOR& color) : red(color.r), green(color.g), blue(color.b), alpha(color.a) {}
			constexpr COLOR_TAG(const float _red, const float _green, const float _blue, const float _alpha) : red(_red), green(_green), blue(_blue), alpha(_alpha) {}
			constexpr COLOR_TAG(const COLOR_TAG& v) : red(v.red), green(v.green), blue(v.blue), alpha(v.alpha) {}

			auto operator == (const COLOR_TAG& v) -> bool
			{
				return (fabsf(v.red - this->red) <= std::numeric_limits<float>::epsilon() &&
					fabsf(v.green - this->green) <= std::numeric_limits<float>::epsilon() &&
					fabsf(v.blue - this->blue) <= std::numeric_limits<float>::epsilon() &&
					fabsf(v.alpha - this->alpha) <= std::numeric_limits<float>::epsilon());
			}

			auto operator != (const COLOR_TAG& v) -> bool
			{
				return !(this->operator==(v));
			}

			explicit operator ALLEGRO_COLOR () const
			{
				return ALLEGRO_COLOR(this->red, this->green, this->blue, this->alpha);
			}
		};

		export using COLOR_DATA = typename ALLEGRO_COLOR;
	}

	export using COLOR = typename INTERNAL::COLOR_TAG;

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

	export inline auto map_rgba_f(float red, float green, float blue, float alpha, bool premultiply_alpha = false) -> ALLEGRO::COLOR
	{
		if (premultiply_alpha)
		{
			return static_cast<ALLEGRO::COLOR>(al_premul_rgba_f(red, green, blue, alpha));
		}

		return static_cast<ALLEGRO::COLOR>(al_map_rgba_f(red, green, blue, alpha));
	}

	export inline auto map_rgb_f(float red, float green, float blue) -> ALLEGRO::COLOR
	{
		return static_cast<ALLEGRO::COLOR>(al_map_rgb_f(red, green, blue));
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
		al_unmap_rgba_f(static_cast<ALLEGRO::INTERNAL::COLOR_DATA>(color), &red, &green, &blue, &alpha);
	}

	export inline auto unmap_rgb_f(const ALLEGRO::COLOR& color, float& red, float& green, float& blue) -> void
	{
		al_unmap_rgb_f(static_cast<ALLEGRO::INTERNAL::COLOR_DATA>(color), &red, &green, &blue);
	}

	export inline auto unmap_rgba(const ALLEGRO::COLOR& color, uint8_t& red, uint8_t& green, uint8_t& blue, uint8_t& alpha) -> void
	{
		al_unmap_rgba(static_cast<ALLEGRO::INTERNAL::COLOR_DATA>(color), &red, &green, &blue, &alpha);
	}

	export inline auto unmap_rgb(const ALLEGRO::COLOR& color, uint8_t& red, uint8_t& green, uint8_t& blue) -> void
	{
		al_unmap_rgb(static_cast<ALLEGRO::INTERNAL::COLOR_DATA>(color), &red, &green, &blue);
	}
}
