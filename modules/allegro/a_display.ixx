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
	namespace INTERNAL
	{
		export using DISPLAY_DATA = typename ALLEGRO_DISPLAY;
		export using DISPLAY_DATA_PTR = std::add_pointer<DISPLAY_DATA>::type;
	}

	export using DISPLAY = typename std::shared_ptr<INTERNAL::DISPLAY_DATA>;

	export constexpr int32_t DISPLAY_FLAG_WINDOWED{ ALLEGRO_WINDOWED };
	export constexpr int32_t DISPLAY_FLAG_FULLSCREEN{ ALLEGRO_FULLSCREEN };
	export constexpr int32_t DISPLAY_FLAG_OPENGL{ ALLEGRO_OPENGL };
	export constexpr int32_t DISPLAY_FLAG_DIRECT3D_INTERNAL{ ALLEGRO_DIRECT3D_INTERNAL };
	export constexpr int32_t DISPLAY_FLAG_RESIZABLE{ ALLEGRO_RESIZABLE };
	export constexpr int32_t DISPLAY_FLAG_FRAMELESS{ ALLEGRO_FRAMELESS };
	export constexpr int32_t DISPLAY_FLAG_NOFRAME{ ALLEGRO_NOFRAME };
	export constexpr int32_t DISPLAY_FLAG_GENERATE_EXPOSE_EVENTS{ ALLEGRO_GENERATE_EXPOSE_EVENTS };
	export constexpr int32_t DISPLAY_FLAG_OPENGL_3_0{ ALLEGRO_OPENGL_3_0 };
	export constexpr int32_t DISPLAY_FLAG_OPENGL_FORWARD_COMPATIBLE{ ALLEGRO_OPENGL_FORWARD_COMPATIBLE };
	export constexpr int32_t DISPLAY_FLAG_FULLSCREEN_WINDOW{ ALLEGRO_FULLSCREEN_WINDOW };
	export constexpr int32_t DISPLAY_FLAG_MINIMIZED{ ALLEGRO_MINIMIZED };
	export constexpr int32_t DISPLAY_FLAG_PROGRAMMABLE_PIPELINE{ ALLEGRO_PROGRAMMABLE_PIPELINE };
	export constexpr int32_t DISPLAY_FLAG_GTK_TOPLEVEL_INTERNAL{ ALLEGRO_GTK_TOPLEVEL_INTERNAL };
	export constexpr int32_t DISPLAY_FLAG_MAXIMIZED{ ALLEGRO_MAXIMIZED };
	export constexpr int32_t DISPLAY_FLAG_OPENGL_ES_PROFILE{ ALLEGRO_OPENGL_ES_PROFILE };
#if defined(ALLEGRO_DISPLAY_FLAG_UNSTABLE) || defined(ALLEGRO_DISPLAY_FLAG_INTERNAL_UNSTABLE) || defined(ALLEGRO_DISPLAY_FLAG_SRC)
	export constexpr int32_t DISPLAY_FLAG_OPENGL_CORE_PROFILE{ ALLEGRO_OPENGL_CORE_PROFILE };
#endif

	export constexpr int32_t DISPLAY_OPTION_RED_SIZE{ ALLEGRO_RED_SIZE };
	export constexpr int32_t DISPLAY_OPTION_GREEN_SIZE{ ALLEGRO_GREEN_SIZE };
	export constexpr int32_t DISPLAY_OPTION_BLUE_SIZE{ ALLEGRO_BLUE_SIZE };
	export constexpr int32_t DISPLAY_OPTION_ALPHA_SIZE{ ALLEGRO_ALPHA_SIZE };
	export constexpr int32_t DISPLAY_OPTION_RED_SHIFT{ ALLEGRO_RED_SHIFT };
	export constexpr int32_t DISPLAY_OPTION_GREEN_SHIFT{ ALLEGRO_GREEN_SHIFT };
	export constexpr int32_t DISPLAY_OPTION_BLUE_SHIFT{ ALLEGRO_BLUE_SHIFT };
	export constexpr int32_t DISPLAY_OPTION_ALPHA_SHIFT{ ALLEGRO_ALPHA_SHIFT };
	export constexpr int32_t DISPLAY_OPTION_ACC_RED_SIZE{ ALLEGRO_ACC_RED_SIZE };
	export constexpr int32_t DISPLAY_OPTION_ACC_GREEN_SIZE{ ALLEGRO_ACC_GREEN_SIZE };
	export constexpr int32_t DISPLAY_OPTION_ACC_BLUE_SIZE{ ALLEGRO_ACC_BLUE_SIZE };
	export constexpr int32_t DISPLAY_OPTION_ACC_ALPHA_SIZE{ ALLEGRO_ACC_ALPHA_SIZE };
	export constexpr int32_t DISPLAY_OPTION_STEREO{ ALLEGRO_STEREO };
	export constexpr int32_t DISPLAY_OPTION_AUX_BUFFERS{ ALLEGRO_AUX_BUFFERS };
	export constexpr int32_t DISPLAY_OPTION_COLOR_SIZE{ ALLEGRO_COLOR_SIZE };
	export constexpr int32_t DISPLAY_OPTION_DEPTH_SIZE{ ALLEGRO_DEPTH_SIZE };
	export constexpr int32_t DISPLAY_OPTION_STENCIL_SIZE{ ALLEGRO_STENCIL_SIZE };
	export constexpr int32_t DISPLAY_OPTION_SAMPLE_BUFFERS{ ALLEGRO_SAMPLE_BUFFERS };
	export constexpr int32_t DISPLAY_OPTION_SAMPLES{ ALLEGRO_SAMPLES };
	export constexpr int32_t DISPLAY_OPTION_RENDER_METHOD{ ALLEGRO_RENDER_METHOD };
	export constexpr int32_t DISPLAY_OPTION_FLOAT_COLOR{ ALLEGRO_FLOAT_COLOR };
	export constexpr int32_t DISPLAY_OPTION_FLOAT_DEPTH{ ALLEGRO_FLOAT_DEPTH };
	export constexpr int32_t DISPLAY_OPTION_SINGLE_BUFFER{ ALLEGRO_SINGLE_BUFFER };
	export constexpr int32_t DISPLAY_OPTION_SWAP_METHOD{ ALLEGRO_SWAP_METHOD };
	export constexpr int32_t DISPLAY_OPTION_COMPATIBLE_DISPLAY{ ALLEGRO_COMPATIBLE_DISPLAY };
	export constexpr int32_t DISPLAY_OPTION_UPDATE_DISPLAY_REGION{ ALLEGRO_UPDATE_DISPLAY_REGION };
	export constexpr int32_t DISPLAY_OPTION_VSYNC{ ALLEGRO_VSYNC };
	export constexpr int32_t DISPLAY_OPTION_MAX_BITMAP_SIZE{ ALLEGRO_MAX_BITMAP_SIZE };
	export constexpr int32_t DISPLAY_OPTION_SUPPORT_NPOT_BITMAP{ ALLEGRO_SUPPORT_NPOT_BITMAP };
	export constexpr int32_t DISPLAY_OPTION_CAN_DRAW_INTO_BITMAP{ ALLEGRO_CAN_DRAW_INTO_BITMAP };
	export constexpr int32_t DISPLAY_OPTION_SUPPORT_SEPARATE_ALPHA{ ALLEGRO_SUPPORT_SEPARATE_ALPHA };
	export constexpr int32_t DISPLAY_OPTION_AUTO_CONVERT_BITMAPS{ ALLEGRO_AUTO_CONVERT_BITMAPS };
	export constexpr int32_t DISPLAY_OPTION_SUPPORTED_ORIENTATIONS{ ALLEGRO_SUPPORTED_ORIENTATIONS };
	export constexpr int32_t DISPLAY_OPTION_OPENGL_MAJOR_VERSION{ ALLEGRO_OPENGL_MAJOR_VERSION };
	export constexpr int32_t DISPLAY_OPTION_OPENGL_MINOR_VERSION{ ALLEGRO_OPENGL_MINOR_VERSION };
	export constexpr int32_t DISPLAY_OPTION_DEFAULT_SHADER_PLATFORM{ ALLEGRO_DEFAULT_SHADER_PLATFORM };
	export constexpr int32_t DISPLAY_OPTION_COUNT{ ALLEGRO_DISPLAY_OPTIONS_COUNT };

	export constexpr int32_t DISPLAY_OPTION_IMPORTANCE_DONTCARE{ ALLEGRO_DONTCARE };
	export constexpr int32_t DISPLAY_OPTION_IMPORTANCE_REQUIRE{ ALLEGRO_REQUIRE };
	export constexpr int32_t DISPLAY_OPTION_IMPORTANCE_SUGGEST{ ALLEGRO_SUGGEST };

	export constexpr int32_t DISPLAY_ORIENTATION_UNKNOWN{ ALLEGRO_DISPLAY_ORIENTATION_UNKNOWN };
	export constexpr int32_t DISPLAY_ORIENTATION_0_DEGREES{ ALLEGRO_DISPLAY_ORIENTATION_0_DEGREES };
	export constexpr int32_t DISPLAY_ORIENTATION_90_DEGREES{ ALLEGRO_DISPLAY_ORIENTATION_90_DEGREES };
	export constexpr int32_t DISPLAY_ORIENTATION_180_DEGREES{ ALLEGRO_DISPLAY_ORIENTATION_180_DEGREES };
	export constexpr int32_t DISPLAY_ORIENTATION_270_DEGREES{ ALLEGRO_DISPLAY_ORIENTATION_270_DEGREES };
	export constexpr int32_t DISPLAY_ORIENTATION_PORTRAIT{ ALLEGRO_DISPLAY_ORIENTATION_PORTRAIT };
	export constexpr int32_t DISPLAY_ORIENTATION_LANDSCAPE{ ALLEGRO_DISPLAY_ORIENTATION_LANDSCAPE };
	export constexpr int32_t DISPLAY_ORIENTATION_ALL{ ALLEGRO_DISPLAY_ORIENTATION_LANDSCAPE };
	export constexpr int32_t DISPLAY_ORIENTATION_FACE_UP{ ALLEGRO_DISPLAY_ORIENTATION_FACE_UP };
	export constexpr int32_t DISPLAY_ORIENTATION_FACE_DOWN{ ALLEGRO_DISPLAY_ORIENTATION_FACE_DOWN };
}

namespace al
{
	namespace internal
	{
		export inline auto destroy_display(ALLEGRO::INTERNAL::DISPLAY_DATA_PTR data) -> void
		{
			al_destroy_display(data);
		}
	}

	export inline constexpr auto get_display_max_title_size() -> size_t
	{
		return static_cast<size_t>(ALLEGRO_NEW_WINDOW_TITLE_MAX_SIZE);
	}

	export inline auto set_new_display_refresh_rate(int32_t rate) -> void
	{
		al_set_new_display_refresh_rate(rate);
	}

	export inline auto set_new_display_flags(int32_t flags) -> void
	{
		al_set_new_display_flags(flags);
	}

	export inline auto get_new_display_refresh_rate() -> int32_t
	{
		return al_get_new_display_refresh_rate();
	}

	export inline auto get_new_display_flags() -> int32_t
	{
		return al_get_new_display_flags();
	}

	export inline auto set_window_title(const ALLEGRO::DISPLAY& display, const char* title) -> void
	{
		al_set_window_title(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), title);
	}

	export inline auto set_new_window_title(const char* title) -> void
	{
		al_set_new_window_title(title);
	}

	export inline auto get_new_window_title() -> const char*
	{
		return al_get_new_window_title();
	}

	export inline auto get_display_width(const ALLEGRO::DISPLAY& display) -> int32_t
	{
		return al_get_display_width(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto get_display_height(const ALLEGRO::DISPLAY& display) -> int32_t
	{
		return al_get_display_height(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto get_display_dimensions(const ALLEGRO::DISPLAY& display) -> ALLEGRO::SIZE<int32_t>
	{
		return { ::al_get_display_width(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get())), al_get_display_height(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get())) };
	}

	export inline auto get_display_format(const ALLEGRO::DISPLAY& display) -> int32_t
	{
		return al_get_display_format(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto get_display_refresh_rate(const ALLEGRO::DISPLAY& display) -> int32_t
	{
		return al_get_display_refresh_rate(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto get_display_flags(const ALLEGRO::DISPLAY& display) -> int32_t
	{
		return al_get_display_flags(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto get_display_orientation(const ALLEGRO::DISPLAY& display) -> int32_t
	{
		return al_get_display_orientation(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto set_display_flag(const ALLEGRO::DISPLAY& display, int32_t flag, bool onoff) -> bool
	{
		return al_set_display_flag(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), flag, onoff);
	}

	export inline auto create_display(const ALLEGRO::SIZE<size_t>& size) -> ALLEGRO::DISPLAY
	{
		return ALLEGRO::DISPLAY(::al_create_display(static_cast<int32_t>(size.width), static_cast<int32_t>(size.height)), internal::destroy_display);
	}

	export inline auto get_current_display() -> ALLEGRO::DISPLAY
	{
		return ALLEGRO::DISPLAY(al_get_current_display(), al::internal::deleter_empty<ALLEGRO::INTERNAL::DISPLAY_DATA>);
	}

	export inline auto set_target_bitmap(const ALLEGRO::BITMAP& bitmap) -> void
	{
		al_set_target_bitmap(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export inline auto set_target_backbuffer(const ALLEGRO::DISPLAY& display) -> void
	{
		al_set_target_backbuffer(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto get_backbuffer(const ALLEGRO::DISPLAY& display) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_get_backbuffer(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get())), al::internal::deleter_empty<ALLEGRO::INTERNAL::BITMAP_DATA>);
	}

	export inline auto get_target_bitmap() -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_get_target_bitmap(), al::internal::deleter_empty<ALLEGRO::INTERNAL::BITMAP_DATA>);
	}

	export inline auto acknowledge_resize(const ALLEGRO::DISPLAY& display) -> bool
	{
		return al_acknowledge_resize(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto resize_display(const ALLEGRO::DISPLAY& display, const ALLEGRO::SIZE<size_t>& size) -> bool
	{
		return al_resize_display(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), (int32_t)size.width, (int32_t)size.height);
	}

	export inline auto flip_display()
	{
		al_flip_display();
	}

	export inline auto update_display_region(const ALLEGRO::RECTANGLE<int32_t>& region)
	{
		al_update_display_region(region.position.x, region.position.y, region.size.width, region.size.height);
	}

	export inline auto is_compatible_bitmap(const ALLEGRO::BITMAP& bitmap) -> bool
	{
		return al_is_compatible_bitmap(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export inline auto wait_for_vsync() -> bool
	{
		return al_wait_for_vsync();
	}

	export inline auto get_display_event_source(const ALLEGRO::DISPLAY& display) -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_display_event_source(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get())), al::internal::deleter_empty<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA>);
	}

	export inline auto set_display_icon(const ALLEGRO::DISPLAY& display, const ALLEGRO::BITMAP& icon)
	{
		al_set_display_icon(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), (ALLEGRO::INTERNAL::BITMAP_DATA_PTR)icon.get());
	}

	export inline auto set_display_icons(ALLEGRO::DISPLAY& display, const std::vector<ALLEGRO::BITMAP>& icons)
	{
		std::vector<void*> temp{ icons.size() };

		for (size_t i = 0; i < icons.size(); ++i)
		{
			temp[i] = icons[i].get();
		}

		al_set_display_icons(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), (int32_t)temp.size(), (ALLEGRO::INTERNAL::BITMAP_DATA_PTR*)temp.data());
	}

	export inline auto get_new_display_adapter() -> int32_t
	{
		return al_get_new_display_adapter();
	}

	export inline auto set_new_display_adapter(int32_t adapter)
	{
		al_set_new_display_adapter(adapter);
	}

	export inline auto set_new_window_position(const ALLEGRO::POINT<int32_t>& point)
	{
		al_set_new_window_position(point.x, point.y);
	}

	export inline auto get_new_window_position() -> ALLEGRO::POINT<int32_t>
	{
		ALLEGRO::POINT<int32_t> point;

		al_get_new_window_position(&point.x, &point.y);

		return point;
	}

	export inline auto set_window_position(ALLEGRO::DISPLAY& display, const ALLEGRO::POINT<int32_t>& point)
	{
		al_set_window_position(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), point.x, point.y);
	}

	export inline auto get_window_position(ALLEGRO::DISPLAY& display) -> ALLEGRO::POINT<int32_t>
	{
		ALLEGRO::POINT<int32_t> point;

		al_get_window_position(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), &point.x, &point.y);

		return point;
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto get_window_borders(ALLEGRO::DISPLAY& display, ALLEGRO::BOX<int32_t>& box) -> bool
	{
		return al_get_window_borders(display.get(), &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}
#endif

	export inline auto set_window_constraints(const ALLEGRO::DISPLAY& display, const ALLEGRO::SIZE<int32_t>& min, const ALLEGRO::SIZE<int32_t>& max) -> bool
	{
		return al_set_window_constraints(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), min.width, min.height, max.width, max.height);
	}

	export inline auto get_window_constraints(const ALLEGRO::DISPLAY& display, ALLEGRO::SIZE<int32_t>& min, ALLEGRO::SIZE<int32_t>& max) -> bool
	{
		return al_get_window_constraints(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), &min.width, &min.height, &max.width, &max.height);
	}

	export inline auto apply_window_constraints(const ALLEGRO::DISPLAY& display, bool onoff)
	{
		al_apply_window_constraints(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), onoff);
	}

	export inline auto set_new_display_option(int32_t option, int32_t value, int32_t importance)
	{
		al_set_new_display_option(option, value, importance);
	}

	export inline auto get_new_display_option(int32_t option) -> std::tuple<int32_t, int32_t>
	{
		int32_t importance{ 0 };
		int32_t value{ al_get_new_display_option(option, &importance) };
		return std::make_tuple(value, importance);
	}

	export inline auto reset_new_display_options()
	{
		al_reset_new_display_options();
	}

	export inline auto set_display_option(const ALLEGRO::DISPLAY& display, int32_t option, int32_t value)
	{
		al_set_display_option(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), option, value);
	}

	export inline auto get_display_option(const ALLEGRO::DISPLAY& display, int32_t option)
	{
		return al_get_display_option(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), option);
	}

	export inline auto hold_bitmap_drawing(bool hold)
	{
		al_hold_bitmap_drawing(hold);
	}

	export inline auto is_bitmap_drawing_held() -> bool
	{
		return al_is_bitmap_drawing_held();
	}

	export inline auto acknowledge_drawing_halt(const ALLEGRO::DISPLAY& display)
	{
		al_acknowledge_drawing_halt(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto acknowledge_drawing_resume(const ALLEGRO::DISPLAY& display)
	{
		al_acknowledge_drawing_resume(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto backup_dirty_bitmaps(const ALLEGRO::DISPLAY& display)
	{
		al_backup_dirty_bitmaps(display.get());
	}
#endif
}
