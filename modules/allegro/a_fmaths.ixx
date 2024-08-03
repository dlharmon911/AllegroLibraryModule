export module allegro:fmaths;

import <allegro5/fmaths.h>;
import :fixed;

namespace al
{
	export inline fixed_t al_fixsqrt(fixed_t x)
	{
		return al_fixsqrt(x);
	}

	export inline fixed_t al_fixhypot(fixed_t x, fixed_t y)
	{
		return al_fixhypot(x, y);
	}

	export inline fixed_t al_fixatan(fixed_t x)
	{
		return al_fixatan(x);
	}

	export inline fixed_t al_fixatan2(fixed_t y, fixed_t x)
	{
		return al_fixatan2(y, x);
	}

	export inline fixed_t fixsqrt(fixed_t x)
	{
		return al_fixsqrt(x);
	}

	export inline fixed_t itofix(int32_t x) 
	{
		return al_itofix(x);
	}

	export inline int32_t fixtoi(fixed_t x)
	{
		return al_fixtoi(x);
	}

	export inline int32_t fixfloor(fixed_t x)
	{
		return al_fixfloor(x);
	}

	export inline int32_t fixceil(fixed_t x)
	{
		return al_fixceil(x);
	}

	export inline fixed_t ftofix(double x)
	{
		return al_ftofix(x);
	}

	export inline double fixtof(fixed_t x)
	{
		return al_fixtof(x);
	}

	export inline fixed_t fixadd(fixed_t x, fixed_t y)
	{
		return al_fixadd(x, y);
	}

	export inline fixed_t fixsub(fixed_t x, fixed_t y)
	{
		return al_fixsub(x, y);
	}

	export inline fixed_t fixmul(fixed_t x, fixed_t y)
	{
		return al_fixmul(x, y);
	}

	export inline fixed_t fixdiv(fixed_t x, fixed_t y)
	{
		return al_fixdiv(x, y);
	}

	export inline fixed_t fixcos(fixed_t x)
	{
		return al_fixcos(x);
	}

	export inline fixed_t fixsin(fixed_t x)
	{
		return al_fixsin(x);
	}

	export inline fixed_t fixtan(fixed_t x)
	{
		return al_fixtan(x);
	}

	export inline fixed_t fixacos(fixed_t x)
	{
		return al_fixacos(x);
	}

	export inline fixed_t fixasin(fixed_t x)
	{
		return al_fixasin(x);
	}
}
