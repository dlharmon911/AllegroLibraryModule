export module allegro:cpu;

import <allegro5/cpu.h>;

namespace al
{
	export inline int32_t get_cpu_count()
	{
		return al_get_cpu_count();
	}

	export inline int32_t get_ram_size()
	{
		return al_get_ram_size();
	}
}

