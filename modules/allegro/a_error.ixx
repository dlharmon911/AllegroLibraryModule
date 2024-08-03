export module allegro:error;

import <allegro5/error.h>;

namespace al
{
	export inline int32_t get_errno()
	{
		return al_get_errno();
	}

	export inline void set_errno(int32_t errnum)
	{
		return al_set_errno(errnum);
	}
}
