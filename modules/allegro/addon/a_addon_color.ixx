export module allegro.color_addon;

import <string>;
import allegro;
import <allegro5/allegro_color.h>;

namespace ALLEGRO
{
	export using COLOR_RGB = struct COLOR_RGB_TAG
	{
		float red{ 0.0f };
		float green{ 0.0f };
		float blue{ 0.0f };
	};

	export using COLOR_HSL = struct COLOR_HSL_TAG
	{
		float hue{ 0.0f };
		float saturation{ 0.0f };
		float lightness{ 0.0f };
	};

	export using COLOR_HSV = struct COLOR_HSV_TAG
	{
		float hue{ 0.0f };
		float saturation{ 0.0f };
		float value{ 0.0f };
	};

	export using COLOR_CMYK = struct COLOR_CMYK_TAG
	{
		float cyan{ 0.0f };
		float magenta{ 0.0f };
		float yellow{ 0.0f };
		float key{ 0.0f };
	};

	export using COLOR_YUV = struct COLOR_YUV_TAG
	{
		float y{ 0.0f };
		float u{ 0.0f };
		float vec{ 0.0f };
	};

	export using COLOR_LAB = struct COLOR_LAB_TAG
	{
		float luminance{ 0.0f };
		float a{ 0.0f };
		float b{ 0.0f };
	};

	export using COLOR_LCH = struct COLOR_LCH_TAG
	{
		float luminance{ 0.0f };
		float chroma{ 0.0f };
		float hue{ 0.0f };
	};

	export using COLOR_XYY = struct COLOR_XYY_TAG
	{
		float x{ 0.0f };
		float y1{ 0.0f };
		float y2{ 0.0f };
	};
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
		al_color_hsv_to_rgb(hsv.hue, hsv.saturation, hsv.value, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_hsl(const ALLEGRO::COLOR rgb, ALLEGRO::COLOR_HSL& hsl) -> void
	{
		al_color_rgb_to_hsl(rgb.red, rgb.green, rgb.blue, &hsl.hue, &hsl.saturation, &hsl.lightness);
	}

	export inline auto color_rgb_to_hsv(const ALLEGRO::COLOR rgb, ALLEGRO::COLOR_HSL& hsl) -> void
	{
		al_color_rgb_to_hsv(rgb.red, rgb.green, rgb.blue, &hsl.hue, &hsl.saturation, &hsl.lightness);
	}

	export inline auto color_hsl_to_rgb(const ALLEGRO::COLOR_HSL hsl, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_hsl_to_rgb(hsl.hue, hsl.saturation, hsl.lightness, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_name_to_rgb(const char* name, ALLEGRO::COLOR_RGB& rgb) -> bool
	{
		return al_color_name_to_rgb(name, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_name(const ALLEGRO::COLOR_RGB& rgb) -> const char*
	{
		return (const char*)al_color_rgb_to_name(rgb.red, rgb.green, rgb.blue);
	}

	export inline auto color_cmyk_to_rgb(const ALLEGRO::COLOR_CMYK cmyk, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_cmyk_to_rgb(cmyk.cyan, cmyk.magenta, cmyk.yellow, cmyk.key, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_cmyk(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_CMYK& cmyk) -> void
	{
		al_color_rgb_to_cmyk(rgb.red, rgb.green, rgb.blue, &cmyk.cyan, &cmyk.magenta, &cmyk.yellow, &cmyk.key);
	}

	export inline auto color_yuv_to_rgb(const ALLEGRO::COLOR_YUV yuv, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_yuv_to_rgb(yuv.y, yuv.u, yuv.vec, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_yuv(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_YUV& yuv) -> void
	{
		al_color_rgb_to_yuv(rgb.red, rgb.green, rgb.blue, &yuv.y, &yuv.u, &yuv.vec);
	}

	export inline auto color_rgb_to_html(const ALLEGRO::COLOR_RGB rgb, char* string) -> void
	{
		al_color_rgb_to_html(rgb.red, rgb.green, rgb.blue, string);
	}

	export inline auto color_html_to_rgb(const char* string, ALLEGRO::COLOR_RGB& rgb) -> bool
	{
		return al_color_html_to_rgb(string, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_yuv(const ALLEGRO::COLOR_YUV& yuv) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_yuv(yuv.y, yuv.u, yuv.vec);
	}

	export inline auto color_cmyk(ALLEGRO::COLOR_CMYK& cmyk) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_cmyk(cmyk.cyan, cmyk.magenta, cmyk.yellow, cmyk.key);
	}

	export inline auto color_hsl(ALLEGRO::COLOR_HSL& hsl) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_hsl(hsl.hue, hsl.saturation, hsl.lightness);
	}

	export inline auto color_hsv(ALLEGRO::COLOR_HSV& hsv) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_hsv(hsv.hue, hsv.saturation, hsv.value);
	}

	export inline auto color_name(const char* name) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_name(name);
	}

	export inline auto color_html(const char* string) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_html(string);
	}

	export inline auto color_xyz_to_rgb(const ALLEGRO::VECTOR3<float>& vec, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_xyz_to_rgb(vec.x, vec.y, vec.z, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_xyz(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::VECTOR3<float>& vec) -> void
	{
		al_color_rgb_to_xyz(rgb.red, rgb.green, rgb.blue, &vec.x, &vec.y, &vec.z);
	}

	export inline auto color_xyz(const ALLEGRO::VECTOR3<float>& vec) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_xyz(vec.x, vec.y, vec.z);
	}

	export inline auto color_lab_to_rgb(const ALLEGRO::COLOR_LAB lab, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_lab_to_rgb(lab.luminance, lab.a, lab.b, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_lab(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_LAB& lab) -> void
	{
		al_color_rgb_to_lab(rgb.red, rgb.green, rgb.blue, &lab.luminance, &lab.a, &lab.b);
	}

	export inline auto color_lab(const ALLEGRO::COLOR_LAB lab) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_lab(lab.luminance, lab.a, lab.b);
	}

	export inline auto color_xyy_to_rgb(const ALLEGRO::COLOR_XYY xyy, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_xyy_to_rgb(xyy.x, xyy.y1, xyy.y2, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_xyy(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_XYY& xyy) -> void
	{
		al_color_rgb_to_xyy(rgb.red, rgb.green, rgb.blue, &xyy.x, &xyy.y1, &xyy.y2);
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
		al_color_lch_to_rgb(lch.luminance, lch.chroma, lch.hue, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_lch(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_LCH& lch) -> void
	{
		al_color_rgb_to_lch(rgb.red, rgb.green, rgb.blue, &lch.luminance, &lch.chroma, &lch.hue);
	}

	export inline auto color_lch(const ALLEGRO::COLOR_LCH lch) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_lch(lch.luminance, lch.chroma, lch.hue);
	}

	export inline auto is_color_valid(ALLEGRO::COLOR color) -> bool
	{
		return al_is_color_valid((ALLEGRO_COLOR)color);
	}

	export inline auto color_oklab_to_rgb(const ALLEGRO::COLOR_LAB lab, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_oklab_to_rgb(lab.luminance, lab.a, lab.b, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_oklab(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::COLOR_LAB& lab) -> void
	{
		al_color_rgb_to_oklab(rgb.red, rgb.green, rgb.blue, &lab.luminance, &lab.a, &lab.b);
	}

	export inline auto color_oklab(const ALLEGRO::COLOR_LAB lab) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_oklab(lab.luminance, lab.a, lab.b);
	}

	export inline auto color_linear_to_rgb(const ALLEGRO::VECTOR3<float>& vec, ALLEGRO::COLOR_RGB& rgb) -> void
	{
		al_color_linear_to_rgb(vec.x, vec.y, vec.z, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_linear(const ALLEGRO::COLOR_RGB rgb, ALLEGRO::VECTOR3<float>& vec) -> void
	{
		al_color_rgb_to_linear(rgb.red, rgb.green, rgb.blue, &vec.x, &vec.y, &vec.z);
	}

	export inline auto color_linear(const ALLEGRO::COLOR_RGB rgb) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_linear(rgb.red, rgb.green, rgb.blue);
	}
}
