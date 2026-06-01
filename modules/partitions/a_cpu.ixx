export module allegro:cpu;

import <allegro5/cpu.h>;
import std;

namespace al
{
	export inline auto get_cpu_count() -> int32_t
	{
		return al_get_cpu_count();
	}

	export inline auto get_ram_size() -> int32_t
	{
		return al_get_ram_size();
	}
}
