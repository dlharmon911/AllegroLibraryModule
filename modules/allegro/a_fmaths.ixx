export module allegro:fmaths;

import <allegro5/fmaths.h>;
import :fixed;

namespace al
{
	export inline auto fixhypot(ALLEGRO::FIXED x, ALLEGRO::FIXED y) -> ALLEGRO::FIXED
	{
		return al_fixhypot(x, y);
	}

	export inline auto fixatan(ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixatan(x);
	}

	export inline auto fixatan2(ALLEGRO::FIXED y, ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixatan2(y, x);
	}

	export inline auto fixsqrt(ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixsqrt(x);
	}

	export inline auto itofix(int32_t x) -> ALLEGRO::FIXED
	{
		return al_itofix(x);
	}

	export inline auto fixtoi(ALLEGRO::FIXED x) -> int32_t
	{
		return al_fixtoi(x);
	}

	export inline auto fixfloor(ALLEGRO::FIXED x) -> int32_t
	{
		return al_fixfloor(x);
	}

	export inline auto fixceil(ALLEGRO::FIXED x) -> int32_t
	{
		return al_fixceil(x);
	}

	export inline auto ftofix(double x) -> ALLEGRO::FIXED
	{
		return al_ftofix(x);
	}

	export inline auto fixtof(ALLEGRO::FIXED x) -> double
	{
		return al_fixtof(x);
	}

	export inline auto fixadd(ALLEGRO::FIXED x, ALLEGRO::FIXED y) -> ALLEGRO::FIXED
	{
		return al_fixadd(x, y);
	}

	export inline auto fixsub(ALLEGRO::FIXED x, ALLEGRO::FIXED y) -> ALLEGRO::FIXED
	{
		return al_fixsub(x, y);
	}

	export inline auto fixmul(ALLEGRO::FIXED x, ALLEGRO::FIXED y) -> ALLEGRO::FIXED
	{
		return al_fixmul(x, y);
	}

	export inline auto fixdiv(ALLEGRO::FIXED x, ALLEGRO::FIXED y) -> ALLEGRO::FIXED
	{
		return al_fixdiv(x, y);
	}

	export inline auto fixcos(ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixcos(x);
	}

	export inline auto fixsin(ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixsin(x);
	}

	export inline auto fixtan(ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixtan(x);
	}

	export inline auto fixacos(ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixacos(x);
	}

	export inline auto fixasin(ALLEGRO::FIXED x) -> ALLEGRO::FIXED
	{
		return al_fixasin(x);
	}
}
