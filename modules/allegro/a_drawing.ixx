export module allegro:drawing;

import <allegro5/drawing.h>;
import :base;
import :color;

namespace al
{
	export inline void clear_to_color(ALLEGRO::COLOR color)
	{
		al_clear_to_color((ALLEGRO::COLOR_DATA)color);
	}

	export inline void clear_depth_buffer(float z)
	{
		al_clear_depth_buffer(z);
	}

	export inline void draw_pixel(const ALLEGRO::POINT<float> point, ALLEGRO::COLOR color)
	{
		al_draw_pixel(point.x, point.y, (ALLEGRO::COLOR_DATA)color);
	}
}
