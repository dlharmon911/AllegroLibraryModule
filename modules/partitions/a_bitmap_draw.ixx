export module allegro:bitmap.draw;

import std;
import <allegro5/bitmap_draw.h>;
import :base;
import :bitmap;
import :color;
import :vector_2d;
import :rectangle;

namespace ALLEGRO
{
	export constexpr int32_t BITMAP_FLIP_NONE{ 0 };
	export constexpr int32_t BITMAP_FLIP_HORIZONTAL{ ALLEGRO_FLIP_HORIZONTAL };
	export constexpr int32_t BITMAP_FLIP_VERTICAL{ ALLEGRO_FLIP_VERTICAL };
}

namespace al
{
	export inline auto put_pixel(int32_t x, int32_t y, const ALLEGRO::COLOR& color) -> void
	{
		al_put_pixel(x, y, color);
	}

	export inline auto put_pixel(const ALLEGRO::VECTOR_2D<int32_t>& point, const ALLEGRO::COLOR& color) -> void
	{
		al_put_pixel(point.get_x(), point.get_y(), color);
	}

	export inline auto put_blended_pixel(int32_t x, int32_t y, const ALLEGRO::COLOR& color) -> void
	{
		al_put_blended_pixel(x, y, color);
	}

	export inline auto put_blended_pixel(const ALLEGRO::VECTOR_2D<int32_t>& point, const ALLEGRO::COLOR& color) -> void
	{
		al_put_blended_pixel(point.get_x(), point.get_y(), color);
	}

	export inline auto draw_bitmap(const ALLEGRO::BITMAP& bitmap, int32_t x, int32_t y, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			x, y,
			flip_flags);
	}

	export inline auto draw_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::VECTOR_2D<float>& destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			destination.get_x(), destination.get_y(),
			flip_flags);
	}

	export inline auto draw_bitmap_region(const ALLEGRO::BITMAP& bitmap, int32_t sx, int32_t sy, int32_t width, int32_t height, int32_t dx, int32_t dy, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_bitmap_region(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			sx, sy,
			width, height,
			dx, dy,
			flip_flags);
	}

	export inline auto draw_bitmap_region(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<float>& region, const ALLEGRO::VECTOR_2D<float>& destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_bitmap_region(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			region.get_position().get_x(), region.get_position().get_y(),
			region.get_size().get_x(), region.get_size().get_y(),
			destination.get_x(), destination.get_y(),
			flip_flags);
	}

	export inline auto draw_scaled_bitmap(const ALLEGRO::BITMAP& bitmap, int32_t sx, int32_t sy, int32_t swidth, int32_t sheight, int32_t dx, int32_t dy, int32_t dwidth, int32_t dheight, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_scaled_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			sx, sy,
			swidth, sheight,
			dx, dy,
			dwidth, dheight,
			flip_flags);
	}

	export inline auto draw_scaled_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<float>& source, const ALLEGRO::RECTANGLE<float>& destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_scaled_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			source.get_position().get_x(), source.get_position().get_y(),
			source.get_size().get_x(), source.get_size().get_y(),
			destination.get_position().get_x(), destination.get_position().get_y(),
			destination.get_size().get_x(), destination.get_size().get_y(),
			flip_flags);
	}

	export inline auto draw_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, int32_t cx, int32_t cy, int32_t dx, int32_t dy, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			cx, cy,
			dx, dy,
			angle,
			flip_flags);
	}

	export inline auto draw_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::VECTOR_2D<float>& center, const ALLEGRO::VECTOR_2D<float>& destination, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			center.get_x(), center.get_y(),
			destination.get_x(), destination.get_y(),
			angle,
			flip_flags);
	}

	export inline auto draw_scaled_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::VECTOR_2D<float>& center, const ALLEGRO::VECTOR_2D<float>& destination, const ALLEGRO::VECTOR_2D<float>& scale, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_scaled_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			center.get_x(), center.get_y(),
			destination.get_x(), destination.get_y(),
			scale.get_x(), scale.get_y(),
			angle,
			flip_flags);
	}

	export inline auto draw_scaled_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, float center_x, float center_y, float destination_x, float destination_y, float scale_x, float scale_y, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_scaled_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			center_x, center_y,
			destination_x, destination_y,
			scale_x, scale_y,
			angle,
			flip_flags);
	}

	export inline auto draw_tinted_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, const ALLEGRO::VECTOR_2D<float>& destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			destination.get_x(), destination.get_y(),
			flip_flags);
	}

	export inline auto draw_tinted_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, float destination_x, float destination_y, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			destination_x, destination_y,
			flip_flags);
	}

	export inline auto draw_tinted_bitmap_region(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, const ALLEGRO::RECTANGLE<float>& region, float destination_x, float destination_y, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_bitmap_region(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			region.get_position().get_x(), region.get_position().get_y(),
			region.get_size().get_x(), region.get_size().get_y(),
			destination_x, destination_y,
			flip_flags);
	}

	export inline auto draw_tinted_bitmap_region(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, int32_t source_x, int32_t source_y, int32_t width, int32_t height, float destination_x, float destination_y, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_bitmap_region(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			source_x, source_y,
			width, height,
			destination_x, destination_y,
			flip_flags);
	}

	export inline auto draw_tinted_bitmap_region(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, const ALLEGRO::RECTANGLE<float>& region, const ALLEGRO::VECTOR_2D<float>& destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_bitmap_region(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			region.get_position().get_x(), region.get_position().get_y(),
			region.get_size().get_x(), region.get_size().get_y(),
			destination.get_x(), destination.get_y(),
			flip_flags);
	}

	export inline auto draw_tinted_scaled_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, int32_t source_x, int32_t source_y, int32_t source_width, int32_t source_height, int32_t destination_x, int32_t destination_y, int32_t destination_width, int32_t destination_height, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_scaled_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			source_x, source_y,
			source_width, source_height,
			destination_x, destination_y,
			destination_width, destination_height,
			flip_flags);
	}

	export inline auto draw_tinted_scaled_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, const ALLEGRO::RECTANGLE<float>& source, const ALLEGRO::RECTANGLE<float>& destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_scaled_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			source.get_position().get_x(), source.get_position().get_y(),
			source.get_size().get_x(), source.get_size().get_y(),
			destination.get_position().get_x(), destination.get_position().get_y(),
			destination.get_size().get_x(), destination.get_size().get_y(),
			flip_flags);
	}

	export inline auto draw_tinted_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, int32_t center_x, int32_t center_y, int32_t destination_x, int32_t destination_y, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			center_x, center_y,
			destination_x, destination_y,
			angle,
			flip_flags);
	}

	export inline auto draw_tinted_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, const ALLEGRO::VECTOR_2D<float>& center, const  ALLEGRO::VECTOR_2D<float>& destination, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			center.get_x(), center.get_y(),
			destination.get_x(), destination.get_y(),
			angle,
			flip_flags);
	}

	export inline auto draw_tinted_scaled_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, const ALLEGRO::VECTOR_2D<float>& center, const ALLEGRO::VECTOR_2D<float>& destination, const ALLEGRO::VECTOR_2D<float>& scale, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_scaled_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			center.get_x(), center.get_y(),
			destination.get_x(), destination.get_y(),
			scale.get_x(), scale.get_y(),
			angle,
			flip_flags);
	}

	export inline auto draw_tinted_scaled_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& tint, float center_x, float center_y, float destination_x, float destination_y, float scale_x, float scale_y, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE) -> void
	{
		al_draw_tinted_scaled_rotated_bitmap(
			static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()),
			tint,
			center_x, center_y,
			destination_x, destination_y,
			scale_x, scale_y,
			angle,
			flip_flags);
	}
}
