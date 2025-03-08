export module allegro:fixed;

import <allegro5/fixed.h>;

export using fixed_t = typename al_fixed;

namespace al
{
	export constexpr fixed_t fixtorad_r = static_cast<fixed_t>(1608);
	export constexpr fixed_t radtofix_r = static_cast<fixed_t>(2670177);
}
