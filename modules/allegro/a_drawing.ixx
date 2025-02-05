export module allegro:drawing;

import <allegro5/drawing.h>;
import :base;
import :color;

namespace al
{
	export inline auto clear_to_color(const ALLEGRO::COLOR& color) -> void
	{
		al_clear_to_color(static_cast<ALLEGRO_COLOR>(color));
	}

	export inline auto clear_depth_buffer(float z) -> void
	{
		al_clear_depth_buffer(z);
	}

	export inline auto draw_pixel(const ALLEGRO::POINT<float>& point, const ALLEGRO::COLOR& color) -> void
	{
		al_draw_pixel(point.x, point.y, static_cast<ALLEGRO_COLOR>(color));
	}
}
