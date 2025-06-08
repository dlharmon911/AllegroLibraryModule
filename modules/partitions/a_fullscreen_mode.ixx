export module allegro:fullscreen_mode;

import <memory>;
import <allegro5/fullscreen_mode.h>;
import :base;
import :memory;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using DISPLAY_MODE_DATA = ALLEGRO_DISPLAY_MODE;
		export using DISPLAY_MODE_DATA_PTR = std::add_pointer<DISPLAY_MODE_DATA>::type;
	}

	export using DISPLAY_MODE = std::shared_ptr<INTERNAL::DISPLAY_MODE_DATA>;
}

namespace al
{
	export inline auto get_display_mode(int32_t index) -> ALLEGRO::DISPLAY_MODE
	{
		ALLEGRO::DISPLAY_MODE rv = std::make_shared<ALLEGRO::INTERNAL::DISPLAY_MODE_DATA>();

		if (rv)
		{
			al_get_display_mode(index, static_cast<ALLEGRO::INTERNAL::DISPLAY_MODE_DATA_PTR>(rv.get()));
		}

		return rv;
	}

	export inline auto get_num_display_modes() -> int32_t
	{
		return al_get_num_display_modes();
	}
}
