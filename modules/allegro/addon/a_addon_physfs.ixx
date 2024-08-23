export module allegro.physfs_addon;

import allegro;
import <allegro5/allegro_physfs.h>;
export import <physfs.h>;

namespace al
{
	namespace physfs_addon
	{
		export inline uint32_t get_version()
		{
			return al_get_allegro_physfs_version();
		}

	export inline void set_file_interface()
	{
		al_set_physfs_file_interface();
	}
	}
}
