export module allegro.memfile_addon;

import std;
import allegro;
import <allegro5/allegro_memfile.h>;

namespace al
{
	namespace memfile_addon
	{
		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_memfile_version();
		}
	}

	export inline auto fopen(void* data, int64_t size, const char* mode) -> ALLEGRO::FILE
	{
		ALLEGRO::FILE(al_open_memfile(data, size, mode), internal::destroy_file);
	}
}
