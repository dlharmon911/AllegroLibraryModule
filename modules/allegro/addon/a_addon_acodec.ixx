export module allegro.acodec_addon;

import allegro;
import <allegro5/allegro_acodec.h>;

namespace al
{
	namespace acodec_addon
	{
		export inline auto init() -> bool
		{
			return al_init_acodec_addon();
		}

		export inline auto is_initialized() -> bool
		{
			return al_is_acodec_addon_initialized();
		}

		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_acodec_version();
		}
	}
}
