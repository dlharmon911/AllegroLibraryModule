export module allegro:fixed;

import <allegro5/fixed.h>;

namespace al
{
	export using fixed_t = al_fixed;
	export constexpr fixed_t fixtorad_r = (fixed_t)1608;
	export constexpr fixed_t radtofix_r = (fixed_t)2670177;
}
