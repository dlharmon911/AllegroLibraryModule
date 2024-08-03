export module allegro:bitmap.draw;

import <allegro5/bitmap_draw.h>;
import :base;
import :bitmap;
import :color;

namespace ALLEGRO
{
	export enum
	{
		BITMAP_FLIP_NONE = 0,
		BITMAP_FLIP_HORIZONTAL = ALLEGRO_FLIP_HORIZONTAL,
		BITMAP_FLIP_VERTICAL = ALLEGRO_FLIP_VERTICAL
	};
}

namespace al
{
	export inline void draw_pixel(const ALLEGRO::POINT<int32_t> point, ALLEGRO::COLOR color)
	{
		al_put_pixel(point.x, point.y, (ALLEGRO::COLOR_DATA)color);
	}

	export inline void draw_blended_pixel(const ALLEGRO::POINT<int32_t> point, ALLEGRO::COLOR color)
	{
		al_put_pixel(point.x, point.y, (ALLEGRO::COLOR_DATA)color);
	}

	export inline void draw_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::POINT<float> destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_bitmap(
			bitmap.get(), 
			destination.x, destination.y, 
			flip_flags);
	}

	export inline void draw_bitmap_region(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<float> region, const ALLEGRO::POINT<float> destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_bitmap_region(
			bitmap.get(), 
			region.position.x, region.position.y, 
			region.size.width, region.size.height, 
			destination.x, destination.y, 
			flip_flags);
	}

	export inline void draw_scaled_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<float> source, const ALLEGRO::RECTANGLE<float> destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_scaled_bitmap(
			bitmap.get(),
			source.position.x, source.position.y, 
			source.size.width, source.size.height,
			destination.position.x, destination.position.y,
			destination.size.width, destination.size.height,
			flip_flags);
	}

	export inline void draw_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::POINT<float> center, const  ALLEGRO::POINT<float>& destination, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_rotated_bitmap(
			bitmap.get(),
			center.x, center.y,
			destination.x, destination.y,
			angle,
			flip_flags);
	}

	export inline void draw_scaled_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::POINT<float> center, const ALLEGRO::POINT<float> destination, const ALLEGRO::POINT<float> scale, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_scaled_rotated_bitmap(
			bitmap.get(),
			center.x, center.y,
			destination.x, destination.y,
			scale.x, scale.y,
			angle,
			flip_flags);
	}


	export inline void draw_tinted_bitmap(const ALLEGRO::BITMAP& bitmap, ALLEGRO::COLOR tint, const ALLEGRO::POINT<float> destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_tinted_bitmap(
			bitmap.get(),
			(ALLEGRO::COLOR_DATA)tint,
			destination.x, destination.y,
			flip_flags);
	}

	export inline void draw_tinted_bitmap_region(const ALLEGRO::BITMAP& bitmap, ALLEGRO::COLOR tint, const ALLEGRO::RECTANGLE<float> region, const ALLEGRO::POINT<float> destination, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_tinted_bitmap_region(
			bitmap.get(),
			(ALLEGRO::COLOR_DATA)tint,
			region.position.x, region.position.y,
			region.size.width, region.size.height,
			destination.x, destination.y,
			flip_flags);
	}

	export inline void draw_tinted_scaled_bitmap(const ALLEGRO::BITMAP& bitmap, ALLEGRO::COLOR tint, const ALLEGRO::RECTANGLE<float> source, const ALLEGRO::POINT<float> destination, const ALLEGRO::POINT<float> scale, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_tinted_scaled_bitmap(
			bitmap.get(),
			(ALLEGRO::COLOR_DATA)tint,
			source.position.x, source.position.y,
			source.size.width, source.size.height,
			destination.x, destination.y,
			source.size.width * scale.x, source.size.height * scale.y,
			flip_flags);
	}

	export inline void draw_tinted_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, ALLEGRO::COLOR tint, const ALLEGRO::POINT<float> center, const  ALLEGRO::POINT<float>& destination, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_tinted_rotated_bitmap(
			bitmap.get(),
			(ALLEGRO::COLOR_DATA)tint,
			center.x, center.y,
			destination.x, destination.y,
			angle,
			flip_flags);
	}

	export inline void draw_tinted_scaled_rotated_bitmap(const ALLEGRO::BITMAP& bitmap, ALLEGRO::COLOR tint, const ALLEGRO::POINT<float> center, const ALLEGRO::POINT<float> destination, const ALLEGRO::POINT<float> scale, float angle, int32_t flip_flags = ALLEGRO::BITMAP_FLIP_NONE)
	{
		al_draw_tinted_scaled_rotated_bitmap(
			bitmap.get(),
			(ALLEGRO::COLOR_DATA)tint,
			center.x, center.y,
			destination.x, destination.y,
			scale.x, scale.y,
			angle,
			flip_flags);
	}
}
