export module allegro:fixed;

import <allegro5/fixed.h>;

namespace ALLEGRO
{
	export using FIXED = typename al_fixed;
}

namespace al
{
	export constexpr ALLEGRO::FIXED fixtorad_r = static_cast<ALLEGRO::FIXED>(1608);
	export constexpr ALLEGRO::FIXED radtofix_r = static_cast<ALLEGRO::FIXED>(2670177);
}
