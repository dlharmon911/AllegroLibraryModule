export module allegro:bitmap;

import <allegro5/bitmap.h>;
import <memory>;
import :base;
import :color;
import :memory;

namespace ALLEGRO
{
	export using BITMAP_DATA = ALLEGRO_BITMAP;
	export using BITMAP = std::shared_ptr<BITMAP_DATA>;
	export using BITMAP_CLIP = RECTANGLE<int32_t>;
#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export using BITMAP_WRAP = ::ALLEGRO_BITMAP_WRAP;
	export typedef struct BITMAP_BLENDER
	{
		int32_t operation;
		int32_t source;
		int32_t destination;
	} BITMAP_BLENDER;
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
		export inline void destroy_bitmap(ALLEGRO::BITMAP_DATA* data)
		{
			al_destroy_bitmap(data);
		}
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline void get_new_bitmap_wrap(ALLEGRO::BITMAP_WRAP& u, ALLEGRO::BITMAP_WRAP& v)
	{
		return ::al_get_new_bitmap_wrap(&u, &v);
	}

	export inline void set_new_bitmap_wrap(const ALLEGRO::BITMAP_WRAP& u, const ALLEGRO::BITMAP_WRAP& v)
	{
		return ::al_set_new_bitmap_wrap(u, v);
	}
#endif

	export inline void set_new_bitmap_flags(int32_t flags)
	{
		return ::al_set_new_bitmap_flags(flags);
	}

	export inline int32_t get_new_bitmap_flags()
	{
		return ::al_get_new_bitmap_flags();
	}

	export inline void add_new_bitmap_flags(int32_t flags)
	{
		return ::al_add_new_bitmap_flag(flags);
	}

	export inline int32_t get_bitmap_flags(const ALLEGRO::BITMAP& bitmap)
	{
		return ::al_get_bitmap_flags(bitmap.get());
	}

	export inline void set_new_bitmap_pixel_format(int32_t format)
	{
		return ::al_set_new_bitmap_format(format);
	}

	export inline int32_t get_new_bitmap_pixel_format()
	{
		return ::al_get_new_bitmap_format();
	}

	export inline int32_t get_bitmap_pixel_format(const ALLEGRO::BITMAP& bitmap)
	{
		return ::al_get_bitmap_format(bitmap.get());
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline int32_t get_new_bitmap_depth()
	{
		return ::al_get_new_bitmap_depth();
	}

	export inline void set_new_bitmap_depth(int32_t depth)
	{
		::al_set_new_bitmap_depth(depth);
	}

	export inline int32_t get_bitmap_depth(const ALLEGRO::BITMAP& bitmap)
	{
		return ::al_get_bitmap_depth(bitmap.get());
	}

	export inline int32_t get_new_bitmap_samples()
	{
		return ::al_get_new_bitmap_samples();
	}

	export inline void set_bitmap_new_samples(int32_t samples)
	{
		::al_set_new_bitmap_samples(samples);
	}

	export inline int32_t get_bitmap_samples(const ALLEGRO::BITMAP& bitmap)
	{
		return ::al_get_bitmap_samples(bitmap.get());
	}
#endif

	export inline int32_t get_bitmap_width(const ALLEGRO::BITMAP& bitmap)
	{
		return ::al_get_bitmap_width(bitmap.get());
	}

	export inline int32_t get_bitmap_height(const ALLEGRO::BITMAP& bitmap)
	{
		return ::al_get_bitmap_height(bitmap.get());
	}

	export inline ALLEGRO::COLOR get_bitmap_pixel(const ALLEGRO::BITMAP& bitmap, const ALLEGRO::POINT<float> point)
	{
		return (ALLEGRO::COLOR)al_get_pixel(bitmap.get(), point.x, point.y);
	}

	export inline ALLEGRO::BITMAP create_bitmap(int32_t width, int32_t height)
	{
		return ALLEGRO::BITMAP(::al_create_bitmap(width, height), internal::destroy_bitmap);
	}

	export inline ALLEGRO::BITMAP create_sub_bitmap(ALLEGRO::BITMAP& parent, const ALLEGRO::RECTANGLE<int32_t> rectangle)
	{
		return ALLEGRO::BITMAP(::al_create_sub_bitmap(parent.get(), rectangle.position.x, rectangle.position.y, rectangle.size.width, rectangle.size.height), internal::destroy_bitmap);
	}

	export inline void reparent_sub_bitmap(ALLEGRO::BITMAP& bitmap, ALLEGRO::BITMAP& parent, const ALLEGRO::RECTANGLE<int32_t> rectangle)
	{
		::al_reparent_bitmap(bitmap.get(), parent.get(), rectangle.position.x, rectangle.position.y, rectangle.size.width, rectangle.size.height);
	}

	export inline void convert_mask_to_alpha(ALLEGRO::BITMAP& bitmap, ALLEGRO::COLOR mask_color)
	{
		::al_convert_mask_to_alpha(bitmap.get(), (ALLEGRO::COLOR_DATA)mask_color);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)

	export inline ALLEGRO::BITMAP_BLENDER get_blender()
	{
		ALLEGRO::BITMAP_BLENDER rv;

		::al_get_bitmap_blender(&rv.operation, &rv.source, &rv.destination);

		return rv;
	}

	export inline void set_blender(const ALLEGRO::BITMAP_BLENDER& blender)
	{
		::al_set_bitmap_blender(blender.operation, blender.source, blender.destination);
	}

	export inline void reset_blender()
	{
		::al_reset_bitmap_blender();
	}

	export inline void get_separate_blender(ALLEGRO::BITMAP_BLENDER& blender, ALLEGRO::BITMAP_BLENDER& alpha)
	{
		::al_get_separate_bitmap_blender(&blender.operation, &blender.source, &blender.destination, &alpha.operation, &alpha.source, &alpha.destination);
	}

	export inline void set_separate_blender(const ALLEGRO::BITMAP_BLENDER& blender, const ALLEGRO::BITMAP_BLENDER& alpha)
	{
		::al_set_separate_bitmap_blender(blender.operation, blender.source, blender.destination, alpha.operation, alpha.source, alpha.destination);
	}

	export inline ALLEGRO::COLOR get_blend_color()
	{
		return ::al_get_bitmap_blend_color();
	}

	export inline void set_blend_color(const ALLEGRO::COLOR color)
	{
		::al_set_bitmap_blend_color(color);
	}
#endif

	export inline void get_clipping(ALLEGRO::BITMAP_CLIP& clip)
	{
		::al_get_clipping_rectangle(&clip.position.x, &clip.position.y, &clip.size.width, &clip.size.height);
	}

	export inline void set_clipping(const ALLEGRO::BITMAP_CLIP clip)
	{
		::al_set_clipping_rectangle(clip.position.x, clip.position.y, clip.size.width, clip.size.height);
	}

	export inline void reset_clipping()
	{
		::al_reset_clipping_rectangle();
	}

	export inline ALLEGRO::BITMAP get_parent(ALLEGRO::BITMAP& bitmap)
	{
		ALLEGRO::BITMAP rv;

		if (bitmap)
		{
			rv.reset(::al_get_parent_bitmap(bitmap.get()), internal::deleter_empty<ALLEGRO::BITMAP_DATA>);
		}

		return rv;
	}

	export inline int32_t get_parent_bitmap_x(const ALLEGRO::BITMAP& parent)
	{
		return ::al_get_bitmap_x(parent.get());
	}

	export inline int32_t get_parent_bitmap_y(const ALLEGRO::BITMAP& parent)
	{
		return ::al_get_bitmap_y(parent.get());
	}

	export inline bool is_sub_bitmap(const ALLEGRO::BITMAP& bitmap)
	{
		return ::al_is_sub_bitmap(bitmap.get());
	}

	export inline ALLEGRO::BITMAP clone_bitmap(const ALLEGRO::BITMAP& bitmap)
	{
		return ALLEGRO::BITMAP(al_clone_bitmap(bitmap.get()), internal::destroy_bitmap);
	}

	export inline void convert_to_video_bitmap(ALLEGRO::BITMAP& bitmap)
	{
		::al_convert_bitmap(bitmap.get());
	}

	export inline void convert_memory_bitmaps_to_video_bitmaps(ALLEGRO::BITMAP& bitmap)
	{
		::al_convert_memory_bitmaps();
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline void backup_dirty_bitmap(ALLEGRO::BITMAP& bitmap)
	{
		::al_backup_dirty_bitmap(bitmap.get());
	}
#endif
}
