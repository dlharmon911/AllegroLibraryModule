export module allegro.acodec_addon;

import allegro;
import <allegro5/allegro_acodec.h>;

namespace al
{
	namespace acodec_addon
	{
		export inline bool init()
		{
			return al_init_acodec_addon();
		}

		export inline bool is_initialized()
		{
			return al_is_acodec_addon_initialized();
		}

		export inline uint32_t get_version()
		{
			return al_get_allegro_acodec_version();
		}
	}
}
