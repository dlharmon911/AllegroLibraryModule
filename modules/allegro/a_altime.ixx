export module allegro:altime;

import <allegro5/altime.h>;

import :base;

namespace ALLEGRO
{
	export using TIMEOUT = ::ALLEGRO_TIMEOUT;
}

namespace al
{
	export inline double get_time()
	{
		return al_get_time();
	}

	export inline void init_timeout(ALLEGRO::TIMEOUT& timeout, double seconds)
	{
		return al_init_timeout(&timeout, seconds);
	}

	export inline void rest(double seconds)
	{
		al_rest(seconds);
	}
}
