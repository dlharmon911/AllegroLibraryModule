export module allegro.physfs_addon;

import allegro;
import <allegro5/allegro_physfs.h>;
export import <physfs.h>;

namespace al
{
	namespace physfs_addon
	{
		bool initialized = false;

		auto shutdown() -> void;

		export inline auto init(const char* argv0) -> bool
		{
			if (!initialized)
			{
				if (PHYSFS_init(argv0))
				{
					atexit(shutdown);
					initialized = true;
				}
			}
			return initialized;
		}

		export inline auto is_initialized() -> bool
		{
			return initialized;
		}

		export inline auto shutdown() -> void
		{
			if (initialized)
			{
				PHYSFS_deinit();
			}
			initialized = false;
		}

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
