export module allegro:bitmap.lock;

import <memory>;
import <allegro5/bitmap_lock.h>;
import :base;
import :bitmap;
import :memory;
import :vector_2d;
import :rectangle;

namespace ALLEGRO
{
	export using BITMAP_LOCKED_REGION_DATA = ALLEGRO_LOCKED_REGION;
	export using BITMAP_LOCKED_REGION = std::shared_ptr<BITMAP_LOCKED_REGION_DATA>;
	export constexpr int32_t BITMAP_LOCK_READ_WRITE{ ALLEGRO_LOCK_READWRITE };
	export constexpr int32_t BITMAP_LOCK_READ_ONLY{ ALLEGRO_LOCK_READONLY };
	export constexpr int32_t BITMAP_LOCK_WRITE_ONLY{ ALLEGRO_LOCK_WRITEONLY };
}

namespace al
{
	export inline auto lock_bitmap(const ALLEGRO::BITMAP& bitmap, int32_t format, int32_t flags) -> ALLEGRO::BITMAP_LOCKED_REGION
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), format, flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline auto lock_bitmap_region(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<int32_t>& region, int32_t format, int32_t flags) -> ALLEGRO::BITMAP_LOCKED_REGION
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap_region(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), region.get_position().get_x(), region.get_position().get_y(), region.get_size().get_x(), region.get_size().get_y(), format, flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline auto lock_bitmap_blocked(const ALLEGRO::BITMAP& bitmap, int32_t flags) -> ALLEGRO::BITMAP_LOCKED_REGION
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap_blocked(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline auto lock_bitmap_region_blocked(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<int32_t>& region, int32_t flags) -> ALLEGRO::BITMAP_LOCKED_REGION
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap_region_blocked(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), region.get_position().get_x(), region.get_position().get_y(), region.get_size().get_x(), region.get_size().get_y(), flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline auto unlock_bitmap(const ALLEGRO::BITMAP& bitmap) -> void
	{
		al_unlock_bitmap(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export inline auto is_bitmap_locked(const ALLEGRO::BITMAP& bitmap) -> bool
	{
		return al_is_bitmap_locked(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}
}
