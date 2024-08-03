export module allegro.image_addon;

import allegro;
import <allegro5/allegro_image.h>;

namespace al
{
	namespace image_addon
	{
		export inline bool init()
		{
			return al_init_image_addon();
		}

		export inline bool is_initialized()
		{
			return al_is_image_addon_initialized();
		}

		export inline void shutdown()
		{
			al_shutdown_image_addon();
		}

		export inline uint32_t get_version()
		{
			return al_get_allegro_image_version();
		}
	}
}
