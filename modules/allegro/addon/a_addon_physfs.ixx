export module allegro.physfs_addon;

import allegro;
import <allegro5/allegro_physfs.h>;
export import <physfs.h>;

namespace al
{
	namespace physfs_addon
	{
		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_physfs_version();
		}

		export inline auto set_file_interface() -> void
		{
			al_set_physfs_file_interface();
		}
	}
}
