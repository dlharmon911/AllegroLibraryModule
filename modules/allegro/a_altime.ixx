export module allegro:altime;

import <allegro5/altime.h>;

import :base;

namespace ALLEGRO
{
	export using TIMEOUT = ::ALLEGRO_TIMEOUT;
}

namespace al
{
	export inline auto get_time() -> double
	{
		return al_get_time();
	}

	export inline auto init_timeout(ALLEGRO::TIMEOUT& timeout, double seconds) -> void
	{
		return al_init_timeout(&timeout, seconds);
	}

	export inline auto rest(double seconds) -> void
	{
		al_rest(seconds);
	}
}