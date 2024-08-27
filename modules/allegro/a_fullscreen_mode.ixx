export module allegro:fullscreen_mode;

import <memory>;
import <allegro5/fullscreen_mode.h>;
import :base;
import :memory;

namespace ALLEGRO
{
	export using DISPLAY_MODE_DATA = ALLEGRO_DISPLAY_MODE;
	export using DISPLAY_MODE = ALLEGRO::OBJECT_TYPE;
}

namespace al
{
	export inline ALLEGRO::DISPLAY_MODE get_display_mode(int32_t index)
	{
		ALLEGRO::DISPLAY_MODE rv = std::make_shared<ALLEGRO::DISPLAY_MODE_DATA>();

		if (rv)
		{
			al_get_display_mode(index, (ALLEGRO::DISPLAY_MODE_DATA*)rv.get());
		}

		return rv;
	}

	export inline int32_t get_num_display_modes()
	{
		return al_get_num_display_modes();
	}
}
