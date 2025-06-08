export module allegro.image_addon;

import allegro;
import <allegro5/allegro_image.h>;

namespace al
{
	namespace image_addon
	{
		export inline auto init() -> bool
		{
			return al_init_image_addon();
		}

		export inline auto is_initialized() -> bool
		{
			return al_is_image_addon_initialized();
		}

		export inline auto shutdown() -> void
		{
			al_shutdown_image_addon();
		}

		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_image_version();
		}
	}
}
