export module allegro.memfile_addon;

import <string>;
import allegro;
import <allegro5/allegro_memfile.h>;

namespace al
{
	namespace memfile_addon
	{
		export inline uint32_t get_version()
		{
			return al_get_allegro_memfile_version();
		}
	}

	export inline ALLEGRO::FILE fopen(void* data, int64_t size, const std::string& mode)
	{
		ALLEGRO::FILE(al_open_memfile(data, size, mode.c_str()), internal::destroy_file);
	}
}
