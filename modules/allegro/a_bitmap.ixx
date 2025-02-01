export module allegro:bitmap;

import <allegro5/bitmap.h>;
import <memory>;
import :base;
import :color;
import :memory;

namespace ALLEGRO
{
	export using BITMAP_DATA = ALLEGRO_BITMAP;
	export using BITMAP_DATA_PTR = std::add_pointer<BITMAP_DATA>::type;
	export using BITMAP = std::shared_ptr<BITMAP_DATA>;

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export using BITMAP_WRAP = ::ALLEGRO_BITMAP_WRAP;
	export using  BITMAP_BLENDER = struct BITMAP_BLENDER_TAG
	{
		int32_t operation{ 0 };
		int32_t source{ 0 };
		int32_t destination{ 0 };
	};
#endif

	export enum
	{
		BITMAP_FLAG_MEMORY_BITMAP = ALLEGRO_MEMORY_BITMAP,
		_BITMAP_FLAG_KEEP_FORMAT = _ALLEGRO_KEEP_BITMAP_FORMAT,
		BITMAP_FLAG_FORCE_LOCKING = ALLEGRO_FORCE_LOCKING,
		BITMAP_FLAG_NO_PRESERVE_TEXTURE = ALLEGRO_NO_PRESERVE_TEXTURE,
		_BITMAP_FLAG_ALPHA_TEST = _ALLEGRO_ALPHA_TEST,
		_BITMAP_FLAG_INTERNAL_OPENGL = _ALLEGRO_INTERNAL_OPENGL,
		BITMAP_FLAG_MIN_LINEAR = ALLEGRO_MIN_LINEAR,
		BITMAP_FLAG_MAG_LINEAR = ALLEGRO_MAG_LINEAR,
		BITMAP_FLAG_MIMMAP = ALLEGRO_MIPMAP,
		_BITMAP_FLAG_PREMULTIPLIED_ALPHA = _ALLEGRO_NO_PREMULTIPLIED_ALPHA,
		BITMAP_FLAG_VIDEO_BITMAP = ALLEGRO_VIDEO_BITMAP,
		BITMAP_FLAG_CONVERT_BITMAP = ALLEGRO_CONVERT_BITMAP
	};

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export enum
	{
		BITMAP_WRAP_DEFAULT = ALLEGRO_BITMAP_WRAP_DEFAULT,
		BITMAP_WRAP_REPEAT = ALLEGRO_BITMAP_WRAP_REPEAT,
		BITMAP_WRAP_CLAMP = ALLEGRO_BITMAP_WRAP_CLAMP,
		BITMAP_WRAP_MIRROR = ALLEGRO_BITMAP_WRAP_MIRROR
	};
#endif
}

namespace al
{
	namespace internal
	{
		export inline auto create_bitmap(const ALLEGRO::SIZE<size_t>& size) -> ALLEGRO::BITMAP_DATA_PTR
		{
			return al_create_bitmap((int32_t)size.width, (int32_t)size.height);
		}

		export inline auto destroy_bitmap(ALLEGRO::BITMAP_DATA_PTR data) -> void
		{
			al_destroy_bitmap(data);
		}
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto get_new_bitmap_wrap(ALLEGRO::BITMAP_WRAP& u, ALLEGRO::BITMAP_WRAP& v) -> void
	{
		return ::al_get_new_bitmap_wrap(&u, &v);
	}

	export inline auto set_new_bitmap_wrap(const ALLEGRO::BITMAP_WRAP& u, const ALLEGRO::BITMAP_WRAP& v) -> void
	{
		return ::al_set_new_bitmap_wrap(u, v);
	}
#endif

	export inline auto set_new_bitmap_flags(int32_t flags) -> void
	{
		return ::al_set_new_bitmap_flags(flags);
	}

	export inline auto get_new_bitmap_flags() -> int32_t
	{
		return ::al_get_new_bitmap_flags();
	}

	export inline auto add_new_bitmap_flags(int32_t flags) -> void
	{
		return ::al_add_new_bitmap_flag(flags);
	}

	export inline auto get_bitmap_flags(const ALLEGRO::BITMAP& bitmap) -> int32_t
	{
		return ::al_get_bitmap_flags((ALLEGRO::BITMAP_DATA_PTR)bitmap.get());
	}

	export inline auto set_new_bitmap_pixel_format(int32_t format) -> void
	{
		return ::al_set_new_bitmap_format(format);
	}

	export inline auto get_new_bitmap_pixel_format() -> int32_t
	{
		return ::al_get_new_bitmap_format();
	}

	export inline auto get_bitmap_pixel_format(const ALLEGRO::BITMAP& bitmap) -> int32_t
	{
		return ::al_get_bitmap_format((ALLEGRO::BITMAP_DATA_PTR)bitmap.get());
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto get_new_bitmap_depth() -> int32_t
	{
		return ::al_get_new_bitmap_depth();
	}

	export inline auto set_new_bitmap_depth(int32_t depth) -> void
	{
		::al_set_new_bitmap_depth(depth);
	}

	export inline auto get_bitmap_depth(const ALLEGRO::BITMAP& bitmap) -> int32_t
	{
		return ::al_get_bitmap_depth(bitmap.get());
	}

	export inline auto get_new_bitmap_samples() -> int32_t
	{
		return ::al_get_new_bitmap_samples();
	}

	export inline auto set_bitmap_new_samples(int32_t samples) -> void
	{
		::al_set_new_bitmap_samples(samples);
	}

	export inline auto get_bitmap_samples(const ALLEGRO::BITMAP& bitmap) -> int32_t
	{
		return ::al_get_bitmap_samples(bitmap.get());
	}
#endif

	export inline auto get_bitmap_width(const ALLEGRO::BITMAP& bitmap) -> int32_t
	{
		return ::al_get_bitmap_width((ALLEGRO::BITMAP_DATA_PTR)bitmap.get());
	}

	export inline auto get_bitmap_height(const ALLEGRO::BITMAP& bitmap) -> int32_t
	{
		return ::al_get_bitmap_height((ALLEGRO::BITMAP_DATA_PTR)bitmap.get());
	}

	export inline auto get_bitmap_dimensions(const ALLEGRO::BITMAP& bitmap) -> const ALLEGRO::SIZE<int32_t>
	{
		return { ::al_get_bitmap_width((ALLEGRO::BITMAP_DATA_PTR)bitmap.get()), al_get_bitmap_height((ALLEGRO::BITMAP_DATA_PTR)bitmap.get()) };
	}

	export inline auto get_pixel(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::POINT<float>& point) -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_get_pixel((ALLEGRO::BITMAP_DATA_PTR)bitmap.get(), point.x, point.y);
	}

	export inline auto create_bitmap(const ALLEGRO::SIZE<size_t>& size) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(::al_create_bitmap((int32_t)size.width, (int32_t)size.height), internal::destroy_bitmap);
	}

	export inline auto create_sub_bitmap(const ALLEGRO::BITMAP& parent, const ALLEGRO::RECTANGLE<int32_t>& rectangle) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(::al_create_sub_bitmap((ALLEGRO::BITMAP_DATA_PTR)parent.get(), rectangle.position.x, rectangle.position.y, rectangle.size.width, rectangle.size.height), internal::destroy_bitmap);
	}

	export inline auto reparent_sub_bitmap(const ALLEGRO::BITMAP& bitmap, ALLEGRO::BITMAP& parent, const ALLEGRO::RECTANGLE<int32_t>& rectangle) -> void
	{
		::al_reparent_bitmap((ALLEGRO::BITMAP_DATA_PTR)bitmap.get(), (ALLEGRO::BITMAP_DATA_PTR)parent.get(), rectangle.position.x, rectangle.position.y, rectangle.size.width, rectangle.size.height);
	}

	export inline auto convert_mask_to_alpha(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::COLOR& mask_color) -> void
	{
		::al_convert_mask_to_alpha((ALLEGRO::BITMAP_DATA_PTR)bitmap.get(), (const ALLEGRO::COLOR_DATA)mask_color);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)

	export inline auto get_blender() -> ALLEGRO::BITMAP_BLENDER
	{
		ALLEGRO::BITMAP_BLENDER rv;

		::al_get_bitmap_blender(&rv.operation, &rv.source, &rv.destination);

		return rv;
	}

	export inline auto set_blender(const ALLEGRO::BITMAP_BLENDER& blender) -> void
	{
		::al_set_bitmap_blender(blender.operation, blender.source, blender.destination);
	}

	export inline auto reset_blender() -> void
	{
		::al_reset_bitmap_blender();
	}

	export inline auto get_separate_blender(ALLEGRO::BITMAP_BLENDER& blender, ALLEGRO::BITMAP_BLENDER& alpha) -> void
	{
		::al_get_separate_bitmap_blender(&blender.operation, &blender.source, &blender.destination, &alpha.operation, &alpha.source, &alpha.destination);
	}

	export inline auto set_separate_blender(const ALLEGRO::BITMAP_BLENDER& blender, const ALLEGRO::BITMAP_BLENDER& alpha) -> void
	{
		::al_set_separate_bitmap_blender(blender.operation, blender.source, blender.destination, alpha.operation, alpha.source, alpha.destination);
	}

	export inline auto get_blend_color() -> ALLEGRO::COLOR
	{
		return ::al_get_bitmap_blend_color();
	}

	export inline auto set_blend_color(const ALLEGRO::COLOR color) -> void
	{
		::al_set_bitmap_blend_color(color);
	}
#endif

	export inline auto get_clipping_rectangle() -> ALLEGRO::RECTANGLE<int32_t>
	{
		ALLEGRO::RECTANGLE<int32_t> clip{ {0, 0}, {0, 0} };
		::al_get_clipping_rectangle(&clip.position.x, &clip.position.y, &clip.size.width, &clip.size.height);
		return clip;
	}

	export inline auto set_clipping_rectangle(const ALLEGRO::RECTANGLE<int32_t>& clip) -> void
	{
		::al_set_clipping_rectangle(clip.position.x, clip.position.y, clip.size.width, clip.size.height);
	}

	export inline auto reset_clipping() -> void
	{
		::al_reset_clipping_rectangle();
	}

	export inline auto get_parent(const ALLEGRO::BITMAP& bitmap) -> ALLEGRO::BITMAP
	{
		ALLEGRO::BITMAP rv{ nullptr };

		if (bitmap)
		{
			rv.reset(::al_get_parent_bitmap((ALLEGRO::BITMAP_DATA_PTR)bitmap.get()), internal::deleter_empty<ALLEGRO::BITMAP_DATA>);
		}

		return rv;
	}

	export inline auto get_parent_bitmap_x(const ALLEGRO::BITMAP& parent) -> int32_t
	{
		return ::al_get_bitmap_x((ALLEGRO::BITMAP_DATA_PTR)parent.get());
	}

	export inline auto get_parent_bitmap_y(const ALLEGRO::BITMAP& parent) -> int32_t
	{
		return ::al_get_bitmap_y((ALLEGRO::BITMAP_DATA_PTR)parent.get());
	}

	export inline auto is_sub_bitmap(const ALLEGRO::BITMAP& bitmap) -> bool
	{
		return ::al_is_sub_bitmap((ALLEGRO::BITMAP_DATA_PTR)bitmap.get());
	}

	export inline auto clone_bitmap(const ALLEGRO::BITMAP& bitmap) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_clone_bitmap((ALLEGRO::BITMAP_DATA_PTR)bitmap.get()), internal::destroy_bitmap);
	}

	export inline auto convert_to_video_bitmap(const ALLEGRO::BITMAP& bitmap) -> void
	{
		::al_convert_bitmap((ALLEGRO::BITMAP_DATA_PTR)bitmap.get());
	}

	export inline auto convert_memory_bitmaps_to_video_bitmaps(ALLEGRO::BITMAP& bitmap) -> void
	{
		::al_convert_memory_bitmaps();
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto backup_dirty_bitmap(ALLEGRO::BITMAP& bitmap) -> void
	{
		::al_backup_dirty_bitmap(bitmap.get());
	}
#endif
}