export module allegro.ttf_addon;

import <cstdint>;
import <string>;
import allegro;
import allegro.font_addon;
import <allegro5/allegro_font.h>;
import <allegro5/allegro_ttf.h>;

namespace ALLEGRO
{
	export inline constexpr uint32_t TTF_NO_KERNING = ALLEGRO_TTF_NO_KERNING;
	export inline constexpr uint32_t TTF_MONOCHROME = ALLEGRO_TTF_MONOCHROME;
	export inline constexpr uint32_t TTF_NO_AUTOHINT = ALLEGRO_TTF_NO_AUTOHINT;
}

namespace al
{
	namespace ttf_addon
	{
		export inline bool init()
		{
			return al_init_ttf_addon();
		}

		export inline bool is_initialized()
		{
			return al_is_ttf_addon_initialized();
		}

		export inline void shutdown()
		{
			al_shutdown_ttf_addon();
		}

		export inline uint32_t get_version()
		{
			return al_get_allegro_ttf_version();
		}
	}

	export inline ALLEGRO::FONT load_ttf_font(const std::string& filename, int32_t size, int32_t flags)
	{
		return ALLEGRO::FONT(al_load_ttf_font(filename.c_str(), size, flags), internal::destroy_font);
	}

	export inline ALLEGRO::FONT load_ttf_font_f(ALLEGRO::FILE& file, const std::string& filename, int32_t size, int32_t flags)
	{
		return ALLEGRO::FONT(al_load_ttf_font_f(file.get(), filename.c_str(), size, flags), internal::destroy_font);
	}

	export inline ALLEGRO::FONT load_ttf_font_stretch(const std::string& filename, const ALLEGRO::SIZE<int32_t>& size, int32_t flags)
	{
		return ALLEGRO::FONT(al_load_ttf_font_stretch(filename.c_str(), size.width, size.height, flags), internal::destroy_font);
	}

	export inline ALLEGRO::FONT load_ttf_font_stretch_f(ALLEGRO::FILE& file, const std::string& filename, const ALLEGRO::SIZE<int32_t>& size, int32_t flags)
	{
		return ALLEGRO::FONT(al_load_ttf_font_stretch_f(file.get(), filename.c_str(), size.width, size.height, flags), internal::destroy_font);
	}
}
