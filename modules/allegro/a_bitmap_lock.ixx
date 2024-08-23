export module allegro:bitmap.lock;

import <memory>;
import <allegro5/bitmap_lock.h>;
import :base;
import :bitmap;
import :memory;

namespace ALLEGRO
{
	export using BITMAP_LOCKED_REGION_DATA = ALLEGRO_LOCKED_REGION;
	export using BITMAP_LOCKED_REGION = std::shared_ptr<BITMAP_LOCKED_REGION_DATA>;
	export enum
	{
		BITMAP_LOCK_READ_WRITE = ALLEGRO_LOCK_READWRITE,
		BITMAP_LOCK_READ_ONLY = ALLEGRO_LOCK_READONLY,
		BITMAP_LOCK_WRITE_ONLY = ALLEGRO_LOCK_WRITEONLY
	};
}

namespace al
{
	export inline ALLEGRO::BITMAP_LOCKED_REGION lock_bitmap(const ALLEGRO::BITMAP& bitmap, int32_t format, int32_t flags)
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap(bitmap.get(), format, flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline ALLEGRO::BITMAP_LOCKED_REGION lock_bitmap_region(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<int32_t> region, int32_t format, int32_t flags)
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap_region(bitmap.get(), region.position.x, region.position.y, region.size.width, region.size.height, format, flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline ALLEGRO::BITMAP_LOCKED_REGION lock_bitmap_blocked(const ALLEGRO::BITMAP& bitmap, int32_t flags)
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap_blocked(bitmap.get(), flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline ALLEGRO::BITMAP_LOCKED_REGION lock_bitmap_region_blocked(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::RECTANGLE<int32_t> region, int32_t flags)
	{
		return ALLEGRO::BITMAP_LOCKED_REGION(al_lock_bitmap_region_blocked(bitmap.get(), region.position.x, region.position.y, region.size.width, region.size.height, flags), al::internal::deleter_empty<ALLEGRO::BITMAP_LOCKED_REGION_DATA>);
	}

	export inline void unlock_bitmap(const ALLEGRO::BITMAP& bitmap)
	{
		al_unlock_bitmap(bitmap.get());
	}

	export inline bool is_bitmap_locked(const ALLEGRO::BITMAP& bitmap)
	{
		return al_is_bitmap_locked(bitmap.get());
	}
}
