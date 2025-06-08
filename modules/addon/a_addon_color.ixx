export module allegro.color_addon;

import <string>;
import allegro;
import <allegro5/allegro_color.h>;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export struct COLOR_RGB_TAG
		{
			float r{ 0.0f };
			float g{ 0.0f };
			float b{ 0.0f };
		};

		export struct COLOR_HSL_TAG
		{
			float h{ 0.0f };
			float s{ 0.0f };
			float l{ 0.0f };
		};

		export struct COLOR_HSV_TAG
		{
			float h{ 0.0f };
			float s{ 0.0f };
			float v{ 0.0f };
		};

		export struct COLOR_CMYK_TAG
		{
			float c{ 0.0f };
			float m{ 0.0f };
			float y{ 0.0f };
			float k{ 0.0f };
		};

		export struct COLOR_YUV_TAG
		{
			float y{ 0.0f };
			float u{ 0.0f };
			float v{ 0.0f };
		};

		export struct COLOR_LAB_TAG
		{
			float l{ 0.0f };
			float a{ 0.0f };
			float b{ 0.0f };
		};

		export struct COLOR_LCH_TAG
		{
			float l{ 0.0f };
			float c{ 0.0f };
			float h{ 0.0f };
		};

		export struct COLOR_XYY_TAG
		{
			float x{ 0.0f };
			float y1{ 0.0f };
			float y2{ 0.0f };
		};
	}

	export using COLOR_RGB = typename INTERNAL::COLOR_RGB_TAG;
	export using COLOR_HSL = typename INTERNAL::COLOR_HSL_TAG;
	export using COLOR_HSV = typename INTERNAL::COLOR_HSV_TAG;
	export using COLOR_CMYK = typename INTERNAL::COLOR_CMYK_TAG;
	export using COLOR_YUV = typename INTERNAL::COLOR_YUV_TAG;
	export using COLOR_LAB = typename INTERNAL::COLOR_LAB_TAG;
	export using COLOR_LCH = typename INTERNAL::COLOR_LCH_TAG;
	export using COLOR_XYY = typename INTERNAL::COLOR_XYY_TAG;
}

namespace al
{
	namespace color_addon
	{
		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_color_version();
		}
	}

	export inline auto color_hsv_to_rgb(const ALLEGRO::COLOR_HSV hsv, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_hsv_to_rgb(hsv.h, hsv.s, hsv.v, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_hsl(const ALLEGRO::COLOR rgb, ALLEGRO::COLOR_HSL& hsl) -> void
	{
		al_color_rgb_to_hsl(rgb.r, rgb.g, rgb.b, &hsl.h, &hsl.s, &hsl.l);
	}

	export inline auto color_rgb_to_hsv(const ALLEGRO::COLOR rgb, ALLEGRO::COLOR_HSL& hsl) -> void
	{
		al_color_rgb_to_hsv(rgb.r, rgb.g, rgb.b, &hsl.h, &hsl.s, &hsl.l);
	}

	export inline auto color_hsl_to_rgb(const ALLEGRO::COLOR_HSL hsl, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_hsl_to_rgb(hsl.h, hsl.s, hsl.l, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_name_to_rgb(const char* name, ALLEGRO::COLOR_RGB& rgb) -> bool
	{
		return al_color_name_to_rgb(name, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_name(const ALLEGRO::COLOR_RGB& rgb) -> const char*
	{
		return (const char*)al_color_rgb_to_name(rgb.r, rgb.g, rgb.b);
	}

	export inline auto color_cmyk_to_rgb(const ALLEGRO::COLOR_CMYK cmyk, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_cmyk_to_rgb(cmyk.c, cmyk.m, cmyk.y, cmyk.k, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_cmyk(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_CMYK& cmyk) -> void
	{
		al_color_rgb_to_cmyk(rgb.r, rgb.g, rgb.b, &cmyk.c, &cmyk.m, &cmyk.y, &cmyk.k);
	}

	export inline auto color_yuv_to_rgb(const ALLEGRO::COLOR_YUV yuv, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_yuv_to_rgb(yuv.y, yuv.u, yuv.v, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_yuv(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_YUV& yuv) -> void
	{
		al_color_rgb_to_yuv(rgb.r, rgb.g, rgb.b, &yuv.y, &yuv.u, &yuv.v);
	}

	export inline auto color_rgb_to_html(const ALLEGRO::COLOR_RGB rgb, char* string) -> void
	{
		al_color_rgb_to_html(rgb.r, rgb.g, rgb.b, string);
	}

	export inline auto color_html_to_rgb(const char* string, ALLEGRO::COLOR_RGB& rgb) -> bool
	{
		return al_color_html_to_rgb(string, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_yuv(const ALLEGRO::COLOR_YUV& yuv) -> ALLEGRO::COLOR
	{
		return static_cast<ALLEGRO::COLOR>(al_color_yuv(yuv.y, yuv.u, yuv.v));
	}

	export inline auto color_cmyk(ALLEGRO::COLOR_CMYK& cmyk) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_cmyk(cmyk.c, cmyk.m, cmyk.y, cmyk.k);
	}

	export inline auto color_hsl(ALLEGRO::COLOR_HSL& hsl) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_hsl(hsl.h, hsl.s, hsl.l);
	}

	export inline auto color_hsv(ALLEGRO::COLOR_HSV& hsv) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_hsv(hsv.h, hsv.s, hsv.v);
	}

	export inline auto color_name(const char* name) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_name(name);
	}

	export inline auto color_html(const char* string) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_html(string);
	}

	export inline auto color_xyz_to_rgb(const ALLEGRO::COLOR_XYY& xyy, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_xyz_to_rgb(xyy.x, xyy.y1, xyy.y2, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_xyz(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_XYY& xyy) -> void
	{
		al_color_rgb_to_xyz(rgb.r, rgb.g, rgb.b, &xyy.x, &xyy.y1, &xyy.y2);
	}

	export inline auto color_xyz(const ALLEGRO::COLOR_XYY& xyy) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_xyz(xyy.x, xyy.y1, xyy.y2);
	}

	export inline auto color_lab_to_rgb(const ALLEGRO::COLOR_LAB lab, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_lab_to_rgb(lab.l, lab.a, lab.b, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_lab(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_LAB& lab) -> void
	{
		al_color_rgb_to_lab(rgb.r, rgb.g, rgb.b, &lab.l, &lab.a, &lab.b);
	}

	export inline auto color_lab(const ALLEGRO::COLOR_LAB lab) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_lab(lab.l, lab.a, lab.b);
	}

	export inline auto color_xyy_to_rgb(const ALLEGRO::COLOR_XYY xyy, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_xyy_to_rgb(xyy.x, xyy.y1, xyy.y2, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_xyy(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_XYY& xyy) -> void
	{
		al_color_rgb_to_xyy(rgb.r, rgb.g, rgb.b, &xyy.x, &xyy.y1, &xyy.y2);
	}

	export inline auto color_xyy(const ALLEGRO::COLOR_XYY xyy) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_xyy(xyy.x, xyy.y1, xyy.y2);
	}

	export inline auto color_distance_ciede2000(ALLEGRO::COLOR c1, ALLEGRO::COLOR c2) -> double
	{
		return al_color_distance_ciede2000((ALLEGRO_COLOR)c1, (ALLEGRO_COLOR)c2);
	}

	export inline auto color_lch_to_rgb(const ALLEGRO::COLOR_LCH lch, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_lch_to_rgb(lch.l, lch.c, lch.h, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_lch(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_LCH& lch) -> void
	{
		al_color_rgb_to_lch(rgb.r, rgb.g, rgb.b, &lch.l, &lch.c, &lch.h);
	}

	export inline auto color_lch(const ALLEGRO::COLOR_LCH lch) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_lch(lch.l, lch.c, lch.h);
	}

	export inline auto is_color_valid(ALLEGRO::COLOR color) -> bool
	{
		return al_is_color_valid((ALLEGRO_COLOR)color);
	}

	export inline auto color_oklab_to_rgb(const ALLEGRO::COLOR_LAB lab, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_oklab_to_rgb(lab.l, lab.a, lab.b, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_oklab(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_LAB& lab) -> void
	{
		al_color_rgb_to_oklab(rgb.r, rgb.g, rgb.b, &lab.l, &lab.a, &lab.b);
	}

	export inline auto color_oklab(const ALLEGRO::COLOR_LAB lab) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_oklab(lab.l, lab.a, lab.b);
	}

	export inline auto color_linear_to_rgb(const ALLEGRO::COLOR_XYY& xyy, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_linear_to_rgb(xyy.x, xyy.y1, xyy.y2, &rgb.r, &rgb.g, &rgb.b);
	}

	export inline auto color_rgb_to_linear(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_XYY& xyy) -> void
	{
		al_color_rgb_to_linear(rgb.r, rgb.g, rgb.b, &xyy.x, &xyy.y1, &xyy.y2);
	}

	export inline auto color_linear(const ALLEGRO::COLOR_RGB rgb) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_linear(rgb.r, rgb.g, rgb.b);
	}
}
