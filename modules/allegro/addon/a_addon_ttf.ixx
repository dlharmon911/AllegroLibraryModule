export module allegro.ttf_addon;

import <cstdint>;
import <string>;
import allegro;
import allegro.font_addon;
import <allegro5/allegro_font.h>;
import <allegro5/allegro_ttf.h>;

namespace ALLEGRO
{
	export inline constexpr uint32_t FLAG_TTF_NO_KERNING = ALLEGRO_TTF_NO_KERNING;
	export inline constexpr uint32_t FLAG_TTF_MONOCHROME = ALLEGRO_TTF_MONOCHROME;
	export inline constexpr uint32_t FLAG_TTF_NO_AUTOHINT = ALLEGRO_TTF_NO_AUTOHINT;
}

namespace al
{
	namespace ttf_addon
	{
		export inline auto init() -> bool
		{
			return al_init_ttf_addon();
		}

		export inline auto is_initialized() -> bool
		{
			return al_is_ttf_addon_initialized();
		}

		export inline auto shutdown() -> void
		{
			al_shutdown_ttf_addon();
		}

		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_ttf_version();
		}
	}

	export inline auto load_ttf_font(const char* filename, int32_t size, int32_t flags) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_load_ttf_font(filename, size, flags), internal::destroy_font);
	}

	export inline auto load_ttf_font_f(ALLEGRO::FILE& file, const char* filename, int32_t size, int32_t flags) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_load_ttf_font_f((ALLEGRO::FILE_DATA_PTR)file.get(), filename, size, flags), internal::destroy_font);
	}

	export inline auto load_ttf_font_stretch(const char* filename, const ALLEGRO::SIZE<int32_t>& size, int32_t flags) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_load_ttf_font_stretch(filename, size.width, size.height, flags), internal::destroy_font);
	}

	export inline auto load_ttf_font_stretch_f(ALLEGRO::FILE& file, const char* filename, const ALLEGRO::SIZE<int32_t>& size, int32_t flags) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_load_ttf_font_stretch_f((ALLEGRO::FILE_DATA_PTR)file.get(), filename, size.width, size.height, flags), internal::destroy_font);
	}
}