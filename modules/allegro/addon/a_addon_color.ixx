export module allegro.color_addon;

import <string>;
import allegro;
import <allegro5/allegro_color.h>;

namespace ALLEGRO
{
	export struct COLOR_RGB
	{
		float red;
		float green;
		float blue;
	};

	export struct COLOR_HSL
	{
		float hue;
		float saturation;
		float lightness;
	};

	export struct COLOR_HSV
	{
		float hue;
		float saturation;
		float value;
	};

	export struct COLOR_CMYK
	{
		float cyan;
		float magenta;
		float yellow;
		float key;
	};

	export struct COLOR_YUV
	{
		float y;
		float u;
		float vec;
	};

	export struct COLOR_LAB
	{
		float luminance;
		float a;
		float b;
	};

	export struct COLOR_LCH
	{
		float luminance;
		float chroma;
		float hue;
	};

	export struct COLOR_XYY
	{
		float x;
		float y1;
		float y2;
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

	export inline auto color_name_to_rgb(const_cptr_t name, ALLEGRO::COLOR_RGB& rgb) -> bool
	{
		return al_color_name_to_rgb(name, &rgb.red, &rgb.green, &rgb.blue);
	}

	export inline auto color_rgb_to_name(const ALLEGRO::COLOR_RGB& rgb) -> const_cptr_t
	{
		return (const_cptr_t)al_color_rgb_to_name(rgb.red, rgb.green, rgb.blue);
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

	export inline auto color_rgb_to_html(const ALLEGRO::COLOR_RGB rgb, cptr_t string) -> void
	{
		al_color_rgb_to_html(rgb.red, rgb.green, rgb.blue, string);
	}

	export inline auto color_html_to_rgb(const_cptr_t string, ALLEGRO::COLOR_RGB& rgb) -> bool
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

	export inline auto color_name(const_cptr_t name) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_color_name(name);
	}

	export inline auto color_html(const_cptr_t string) -> ALLEGRO::COLOR
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
