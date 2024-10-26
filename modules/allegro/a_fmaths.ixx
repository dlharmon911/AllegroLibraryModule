export module allegro:fmaths;

import <allegro5/fmaths.h>;
import :fixed;

namespace al
{
	export inline auto al_fixsqrt(fixed_t x) -> fixed_t
	{
		return al_fixsqrt(x);
	}

	export inline auto al_fixhypot(fixed_t x, fixed_t y) -> fixed_t
	{
		return al_fixhypot(x, y);
	}

	export inline auto al_fixatan(fixed_t x) -> fixed_t
	{
		return al_fixatan(x);
	}

	export inline auto al_fixatan2(fixed_t y, fixed_t x) -> fixed_t
	{
		return al_fixatan2(y, x);
	}

	export inline auto fixsqrt(fixed_t x) -> fixed_t
	{
		return al_fixsqrt(x);
	}

	export inline auto itofix(int32_t x) -> fixed_t
	{
		return al_itofix(x);
	}

	export inline auto fixtoi(fixed_t x) -> int32_t
	{
		return al_fixtoi(x);
	}

	export inline auto fixfloor(fixed_t x) -> int32_t
	{
		return al_fixfloor(x);
	}

	export inline auto fixceil(fixed_t x) -> int32_t
	{
		return al_fixceil(x);
	}

	export inline auto ftofix(double x) -> fixed_t
	{
		return al_ftofix(x);
	}

	export inline auto fixtof(fixed_t x) -> double
	{
		return al_fixtof(x);
	}

	export inline auto fixadd(fixed_t x, fixed_t y) -> fixed_t
	{
		return al_fixadd(x, y);
	}

	export inline auto fixsub(fixed_t x, fixed_t y) -> fixed_t
	{
		return al_fixsub(x, y);
	}

	export inline auto fixmul(fixed_t x, fixed_t y) -> fixed_t
	{
		return al_fixmul(x, y);
	}

	export inline auto fixdiv(fixed_t x, fixed_t y) -> fixed_t
	{
		return al_fixdiv(x, y);
	}

	export inline auto fixcos(fixed_t x) -> fixed_t
	{
		return al_fixcos(x);
	}

	export inline auto fixsin(fixed_t x) -> fixed_t
	{
		return al_fixsin(x);
	}

	export inline auto fixtan(fixed_t x) -> fixed_t
	{
		return al_fixtan(x);
	}

	export inline auto fixacos(fixed_t x) -> fixed_t
	{
		return al_fixacos(x);
	}

	export inline auto fixasin(fixed_t x) -> fixed_t
	{
		return al_fixasin(x);
	}
}
