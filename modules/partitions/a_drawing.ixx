export module allegro:drawing;

import std;
import <allegro5/drawing.h>;
import :base;
import :color;
import :vector_2d;

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

	export inline auto draw_pixel(const ALLEGRO::VECTOR_2D<float>& point, const ALLEGRO::COLOR& color) -> void
	{
		al_draw_pixel(point.get_x(), point.get_y(), static_cast<ALLEGRO_COLOR>(color));
	}
}
