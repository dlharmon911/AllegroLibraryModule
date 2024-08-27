export module allegro:display;

import <string>;
import <allegro5/display.h>;
import <vector>;
import <memory>;
import :base;
import :color;
import :bitmap;
import :events;
import :memory;

namespace ALLEGRO
{
	export using DISPLAY_DATA = ALLEGRO_DISPLAY;
	export using DISPLAY = std::shared_ptr<DISPLAY_DATA>;

	export enum
	{
		DISPLAY_FLAG_WINDOWED = ALLEGRO_WINDOWED,
		DISPLAY_FLAG_FULLSCREEN = ALLEGRO_FULLSCREEN,
		DISPLAY_FLAG_OPENGL = ALLEGRO_OPENGL,
		DISPLAY_FLAG_DIRECT3D_INTERNAL = ALLEGRO_DIRECT3D_INTERNAL,
		DISPLAY_FLAG_RESIZABLE = ALLEGRO_RESIZABLE,
		DISPLAY_FLAG_FRAMELESS = ALLEGRO_FRAMELESS,
		DISPLAY_FLAG_NOFRAME = ALLEGRO_NOFRAME,
		DISPLAY_FLAG_GENERATE_EXPOSE_EVENTS = ALLEGRO_GENERATE_EXPOSE_EVENTS,
		DISPLAY_FLAG_OPENGL_3_0 = ALLEGRO_OPENGL_3_0,
		DISPLAY_FLAG_OPENGL_FORWARD_COMPATIBLE = ALLEGRO_OPENGL_FORWARD_COMPATIBLE,
		DISPLAY_FLAG_FULLSCREEN_WINDOW = ALLEGRO_FULLSCREEN_WINDOW,
		DISPLAY_FLAG_MINIMIZED = ALLEGRO_MINIMIZED,
		DISPLAY_FLAG_PROGRAMMABLE_PIPELINE = ALLEGRO_PROGRAMMABLE_PIPELINE,
		DISPLAY_FLAG_GTK_TOPLEVEL_INTERNAL = ALLEGRO_GTK_TOPLEVEL_INTERNAL,
		DISPLAY_FLAG_MAXIMIZED = ALLEGRO_MAXIMIZED,
		DISPLAY_FLAG_OPENGL_ES_PROFILE = ALLEGRO_OPENGL_ES_PROFILE,
#if defined(DISPLAY_FLAG_UNSTABLE) || defined(DISPLAY_FLAG_INTERNAL_UNSTABLE) || defined(DISPLAY_FLAG_SRC)
		DISPLAY_FLAG_OPENGL_CORE_PROFILE = ALLEGRO_OPENGL_CORE_PROFILE,
#endif
	};

	export enum
	{
		DISPLAY_OPTION_RED_SIZE = ALLEGRO_RED_SIZE,
		DISPLAY_OPTION_GREEN_SIZE = ALLEGRO_GREEN_SIZE,
		DISPLAY_OPTION_BLUE_SIZE = ALLEGRO_BLUE_SIZE,
		DISPLAY_OPTION_ALPHA_SIZE = ALLEGRO_ALPHA_SIZE,
		DISPLAY_OPTION_RED_SHIFT = ALLEGRO_RED_SHIFT,
		DISPLAY_OPTION_GREEN_SHIFT = ALLEGRO_GREEN_SHIFT,
		DISPLAY_OPTION_BLUE_SHIFT = ALLEGRO_BLUE_SHIFT,
		DISPLAY_OPTION_ALPHA_SHIFT = ALLEGRO_ALPHA_SHIFT,
		DISPLAY_OPTION_ACC_RED_SIZE = ALLEGRO_ACC_RED_SIZE,
		DISPLAY_OPTION_ACC_GREEN_SIZE = ALLEGRO_ACC_GREEN_SIZE,
		DISPLAY_OPTION_ACC_BLUE_SIZE = ALLEGRO_ACC_BLUE_SIZE,
		DISPLAY_OPTION_ACC_ALPHA_SIZE = ALLEGRO_ACC_ALPHA_SIZE,
		DISPLAY_OPTION_STEREO = ALLEGRO_STEREO,
		DISPLAY_OPTION_AUX_BUFFERS = ALLEGRO_AUX_BUFFERS,
		DISPLAY_OPTION_COLOR_SIZE = ALLEGRO_COLOR_SIZE,
		DISPLAY_OPTION_DEPTH_SIZE = ALLEGRO_DEPTH_SIZE,
		DISPLAY_OPTION_STENCIL_SIZE = ALLEGRO_STENCIL_SIZE,
		DISPLAY_OPTION_SAMPLE_BUFFERS = ALLEGRO_SAMPLE_BUFFERS,
		DISPLAY_OPTION_SAMPLES = ALLEGRO_SAMPLES,
		DISPLAY_OPTION_RENDER_METHOD = ALLEGRO_RENDER_METHOD,
		DISPLAY_OPTION_FLOAT_COLOR = ALLEGRO_FLOAT_COLOR,
		DISPLAY_OPTION_FLOAT_DEPTH = ALLEGRO_FLOAT_DEPTH,
		DISPLAY_OPTION_SINGLE_BUFFER = ALLEGRO_SINGLE_BUFFER,
		DISPLAY_OPTION_SWAP_METHOD = ALLEGRO_SWAP_METHOD,
		DISPLAY_OPTION_COMPATIBLE_DISPLAY = ALLEGRO_COMPATIBLE_DISPLAY,
		DISPLAY_OPTION_UPDATE_DISPLAY_REGION = ALLEGRO_UPDATE_DISPLAY_REGION,
		DISPLAY_OPTION_VSYNC = ALLEGRO_VSYNC,
		DISPLAY_OPTION_MAX_BITMAP_SIZE = ALLEGRO_MAX_BITMAP_SIZE,
		DISPLAY_OPTION_SUPPORT_NPOT_BITMAP = ALLEGRO_SUPPORT_NPOT_BITMAP,
		DISPLAY_OPTION_CAN_DRAW_INTO_BITMAP = ALLEGRO_CAN_DRAW_INTO_BITMAP,
		DISPLAY_OPTION_SUPPORT_SEPARATE_ALPHA = ALLEGRO_SUPPORT_SEPARATE_ALPHA,
		DISPLAY_OPTION_AUTO_CONVERT_BITMAPS = ALLEGRO_AUTO_CONVERT_BITMAPS,
		DISPLAY_OPTION_SUPPORTED_ORIENTATIONS = ALLEGRO_SUPPORTED_ORIENTATIONS,
		DISPLAY_OPTION_OPENGL_MAJOR_VERSION = ALLEGRO_OPENGL_MAJOR_VERSION,
		DISPLAY_OPTION_OPENGL_MINOR_VERSION = ALLEGRO_OPENGL_MINOR_VERSION,
		DISPLAY_OPTION_DEFAULT_SHADER_PLATFORM = ALLEGRO_DEFAULT_SHADER_PLATFORM,
		DISPLAY_OPTION_COUNT
	};

	export enum
	{
		DISPLAY_OPTION_IMPORTANCE_DONTCARE = ALLEGRO_DONTCARE,
		DISPLAY_OPTION_IMPORTANCE_REQUIRE = ALLEGRO_REQUIRE,
		DISPLAY_OPTION_IMPORTANCE_SUGGEST = ALLEGRO_SUGGEST
	};

	export enum
	{
		DISPLAY_ORIENTATION_UNKNOWN = ALLEGRO_DISPLAY_ORIENTATION_UNKNOWN,
		DISPLAY_ORIENTATION_0_DEGREES = ALLEGRO_DISPLAY_ORIENTATION_0_DEGREES,
		DISPLAY_ORIENTATION_90_DEGREES = ALLEGRO_DISPLAY_ORIENTATION_90_DEGREES,
		DISPLAY_ORIENTATION_180_DEGREES = ALLEGRO_DISPLAY_ORIENTATION_180_DEGREES,
		DISPLAY_ORIENTATION_270_DEGREES = ALLEGRO_DISPLAY_ORIENTATION_270_DEGREES,
		DISPLAY_ORIENTATION_PORTRAIT = ALLEGRO_DISPLAY_ORIENTATION_PORTRAIT,
		DISPLAY_ORIENTATION_LANDSCAPE = ALLEGRO_DISPLAY_ORIENTATION_LANDSCAPE,
		DISPLAY_ORIENTATION_ALL = ALLEGRO_DISPLAY_ORIENTATION_LANDSCAPE,
		DISPLAY_ORIENTATION_FACE_UP = ALLEGRO_DISPLAY_ORIENTATION_FACE_UP,
		DISPLAY_ORIENTATION_FACE_DOWN = ALLEGRO_DISPLAY_ORIENTATION_FACE_DOWN
	};
}

namespace al
{
	namespace internal
	{
		export inline void destroy_display(ALLEGRO::DISPLAY_DATA* data)
		{
			al_destroy_display(data);
		}
	}

	export inline constexpr size_t get_display_max_title_size()
	{
		return ALLEGRO_NEW_WINDOW_TITLE_MAX_SIZE;
	}

	export inline void set_new_display_refresh_rate(int32_t rate)
	{
		al_set_new_display_refresh_rate(rate);
	}

	export inline void set_new_display_flags(int32_t flags)
	{
		al_set_new_display_flags(flags);
	}

	export inline int32_t get_new_display_refresh_rate()
	{
		return al_get_new_display_refresh_rate();
	}

	export inline int32_t get_new_display_flags()
	{
		return al_get_new_display_flags();
	}

	export inline void set_window_title(ALLEGRO::DISPLAY& display, const char* title)
	{
		al_set_window_title((ALLEGRO::DISPLAY_DATA*)display.get(), title);
	}

	export inline void set_new_window_title(const char* title)
	{
		al_set_new_window_title(title);
	}

	export inline const char* get_new_window_title()
	{
		return al_get_new_window_title();
	}

	export inline int32_t get_display_width(const ALLEGRO::DISPLAY& display)
	{
		return al_get_display_width((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline int32_t get_display_height(const ALLEGRO::DISPLAY& display)
	{
		return al_get_display_height((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline int32_t get_display_format(const ALLEGRO::DISPLAY& display)
	{
		return al_get_display_format((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline int32_t get_display_refresh_rate(const ALLEGRO::DISPLAY& display)
	{
		return al_get_display_refresh_rate((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline int32_t get_display_flags(const ALLEGRO::DISPLAY& display)
	{
		return al_get_display_flags((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline int32_t get_display_orientation(const ALLEGRO::DISPLAY& display)
	{
		return al_get_display_orientation((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline bool set_display_flag(const ALLEGRO::DISPLAY& display, int32_t flag, bool onoff)
	{
		return al_set_display_flag((ALLEGRO::DISPLAY_DATA*)display.get(), flag, onoff);
	}

	export inline ALLEGRO::DISPLAY create_display(int32_t width, int32_t height)
	{
		return ALLEGRO::DISPLAY(::al_create_display(width, height), internal::destroy_display);
	}

	export inline ALLEGRO::DISPLAY get_current_display()
	{
		return ALLEGRO::DISPLAY(al_get_current_display(), al::internal::deleter_empty<ALLEGRO::DISPLAY_DATA>);
	}

	export inline void set_target_bitmap(ALLEGRO::BITMAP& bitmap)
	{
		al_set_target_bitmap((ALLEGRO::BITMAP_DATA*)bitmap.get());
	}

	export inline void set_target_backbuffer(ALLEGRO::DISPLAY& display)
	{
		al_set_target_backbuffer((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline ALLEGRO::BITMAP get_backbuffer(ALLEGRO::DISPLAY& display)
	{
		return ALLEGRO::BITMAP(al_get_backbuffer((ALLEGRO::DISPLAY_DATA*)display.get()), al::internal::deleter_empty<ALLEGRO::BITMAP_DATA>);
	}

	export inline ALLEGRO::BITMAP get_target_bitmap()
	{
		return ALLEGRO::BITMAP(al_get_target_bitmap(), al::internal::deleter_empty<ALLEGRO::BITMAP_DATA>);
	}

	export inline bool acknowledge_resize(ALLEGRO::DISPLAY& display)
	{
		return al_acknowledge_resize((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline bool resize_display(ALLEGRO::DISPLAY& display, ALLEGRO::SIZE<size_t> size)
	{
		return al_resize_display((ALLEGRO::DISPLAY_DATA*)display.get(), (int32_t)size.width, (int32_t)size.height);
	}

	export inline void flip_display()
	{
		al_flip_display();
	}

	export inline void update_display_region(const ALLEGRO::RECTANGLE<int32_t> region)
	{
		al_update_display_region(region.position.x, region.position.y, region.size.width, region.size.height);
	}

	export inline bool is_compatible_bitmap(const ALLEGRO::BITMAP& bitmap)
	{
		return al_is_compatible_bitmap((ALLEGRO::BITMAP_DATA*)bitmap.get());
	}

	export inline bool wait_for_vsync()
	{
		return al_wait_for_vsync();
	}

	export inline ALLEGRO::EVENT_SOURCE get_display_event_source(ALLEGRO::DISPLAY& display)
	{
		return ALLEGRO::EVENT_SOURCE(al_get_display_event_source((ALLEGRO::DISPLAY_DATA*)display.get()), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}

	export inline void set_display_icon(ALLEGRO::DISPLAY& display, const ALLEGRO::BITMAP& icon)
	{
		al_set_display_icon((ALLEGRO::DISPLAY_DATA*)display.get(), (ALLEGRO::BITMAP_DATA*)icon.get());
	}

	export inline void set_display_icons(ALLEGRO::DISPLAY& display, const std::vector<ALLEGRO::BITMAP>& icons)
	{
		std::vector<void*> temp;
		for (auto icon : icons)
		{
			temp.push_back(icon.get());
		}
		al_set_display_icons((ALLEGRO::DISPLAY_DATA*)display.get(), (int32_t)temp.size(), (ALLEGRO::BITMAP_DATA**)temp.data());
	}

	export inline int32_t get_new_display_adapter()
	{
		return al_get_new_display_adapter();
	}

	export inline void set_new_display_adapter(int32_t adapter)
	{
		al_set_new_display_adapter(adapter);
	}

	export inline void set_new_window_position(const ALLEGRO::POINT<int32_t> point)
	{
		al_set_new_window_position(point.x, point.y);
	}

	export inline ALLEGRO::POINT<int32_t> get_new_window_position()
	{
		ALLEGRO::POINT<int32_t> point;

		al_get_new_window_position(&point.x, &point.y);

		return point;
	}

	export inline void set_window_position(ALLEGRO::DISPLAY& display, const ALLEGRO::POINT<int32_t> point)
	{
		al_set_window_position((ALLEGRO::DISPLAY_DATA*)display.get(), point.x, point.y);
	}

	export inline ALLEGRO::POINT<int32_t> get_window_position(ALLEGRO::DISPLAY& display)
	{
		ALLEGRO::POINT<int32_t> point;

		al_get_window_position((ALLEGRO::DISPLAY_DATA*)display.get(), &point.x, &point.y);

		return point;
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline bool get_window_borders(ALLEGRO::DISPLAY& display, ALLEGRO::BOX<int32_t>& box)
	{
		return al_get_window_borders(display.get(), &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}
#endif
	
	export inline bool set_window_constraints(ALLEGRO::DISPLAY& display, const ALLEGRO::SIZE<int32_t>& min, const ALLEGRO::SIZE<int32_t>& max)
	{
		return al_set_window_constraints((ALLEGRO::DISPLAY_DATA*)display.get(), min.width, min.height, max.width, max.height);
	}

	export inline bool get_window_constraints(const ALLEGRO::DISPLAY& display, ALLEGRO::SIZE<int32_t>& min, ALLEGRO::SIZE<int32_t>& max)
	{
		return al_get_window_constraints((ALLEGRO::DISPLAY_DATA*)display.get(), &min.width, &min.height, &max.width, &max.height);
	}

	export inline void apply_window_constraints(ALLEGRO::DISPLAY& display, bool onoff)
	{
		al_apply_window_constraints((ALLEGRO::DISPLAY_DATA*)display.get(), onoff);
	}

	export inline void set_new_display_option(int32_t option, int32_t value, int32_t importance)
	{
		al_set_new_display_option(option, value, importance);
	}

	export inline std::tuple<int32_t, int32_t> get_new_display_option(int32_t option)
	{
		int32_t importance = 0;
		int32_t value = al_get_new_display_option(option, &importance);
		return std::make_tuple(value, importance);
	}

	export inline void reset_new_display_options()
	{
		al_reset_new_display_options();
	}

	export inline void set_display_option(ALLEGRO::DISPLAY& display, int32_t option, int32_t value)
	{
		al_set_display_option((ALLEGRO::DISPLAY_DATA*)display.get(), option, value);
	}

	export inline int32_t get_display_option(const ALLEGRO::DISPLAY& display, int32_t option)
	{
		return al_get_display_option((ALLEGRO::DISPLAY_DATA*)display.get(), option);
	}

	export inline void hold_bitmap_drawing(bool hold)
	{
		al_hold_bitmap_drawing(hold);
	}

	export inline bool is_bitmap_drawing_held()
	{
		return al_is_bitmap_drawing_held();
	}

	export inline void acknowledge_drawing_halt(ALLEGRO::DISPLAY& display)
	{
		al_acknowledge_drawing_halt((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline void acknowledge_drawing_resume(ALLEGRO::DISPLAY& display)
	{
		al_acknowledge_drawing_resume((ALLEGRO::DISPLAY_DATA*)display.get());
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline void backup_dirty_bitmaps(ALLEGRO::DISPLAY& display)
	{
		al_backup_dirty_bitmaps(display.get());
	}
#endif
}

