export module allegro:mouse_cursor;

import <memory>;
import <allegro5/mouse_cursor.h>;
import :base;
import :bitmap;
import :display;
import :memory;
import :vector_2d;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using MOUSE_CURSOR_DATA = typename ALLEGRO_MOUSE_CURSOR;
		export using MOUSE_CURSOR_DATA_PTR = std::add_pointer<MOUSE_CURSOR_DATA>::type;
	}

	export using MOUSE_CURSOR = std::shared_ptr<INTERNAL::MOUSE_CURSOR_DATA>;
	export using SYSTEM_MOUSE_CURSOR = ALLEGRO_SYSTEM_MOUSE_CURSOR;

	export constexpr int32_t SYSTEM_MOUSE_CURSOR_NONE{ ALLEGRO_SYSTEM_MOUSE_CURSOR_NONE };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_DEFAULT{ ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_ARROW{ ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_BUSY{ ALLEGRO_SYSTEM_MOUSE_CURSOR_BUSY };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_QUESTION{ ALLEGRO_SYSTEM_MOUSE_CURSOR_QUESTION };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_EDIT{ ALLEGRO_SYSTEM_MOUSE_CURSOR_EDIT };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_MOVE{ ALLEGRO_SYSTEM_MOUSE_CURSOR_MOVE };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_N{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_N };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_W{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_W };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_S{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_S };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_E{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_E };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_NW{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_NW };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_SW{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_SW };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_SE{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_SE };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_RESIZE_NE{ ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_NE };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_PROGRESS{ ALLEGRO_SYSTEM_MOUSE_CURSOR_PROGRESS };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_PRECISION{ ALLEGRO_SYSTEM_MOUSE_CURSOR_PRECISION };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_LINK{ ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_ALT_SELECT{ ALLEGRO_SYSTEM_MOUSE_CURSOR_ALT_SELECT };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_UNAVAILABLE{ ALLEGRO_SYSTEM_MOUSE_CURSOR_UNAVAILABLE };
	export constexpr int32_t SYSTEM_MOUSE_CURSOR_COUNT{ ALLEGRO_NUM_SYSTEM_MOUSE_CURSORS };
}

namespace al
{
	namespace internal
	{
		export inline auto create_mouse_cursor(ALLEGRO::INTERNAL::BITMAP_DATA_PTR bitmap, const ALLEGRO::VECTOR_2D<int32_t>& focus) -> ALLEGRO::INTERNAL::MOUSE_CURSOR_DATA_PTR
		{
			return al_create_mouse_cursor(bitmap, focus.get_x(), focus.get_y());
		}

		export inline auto destroy_mouse_cursor(ALLEGRO::INTERNAL::MOUSE_CURSOR_DATA_PTR data) -> void
		{
			al_destroy_mouse_cursor(data);
		}
	}

	export inline auto create_mouse_cursor(const ALLEGRO::BITMAP& sprite, const ALLEGRO::VECTOR_2D<int32_t>& focus) -> ALLEGRO::MOUSE_CURSOR
	{
		return ALLEGRO::MOUSE_CURSOR(al_create_mouse_cursor(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(sprite.get()), focus.get_x(), focus.get_y()), internal::destroy_mouse_cursor);
	}

	export inline auto set_mouse_cursor(const ALLEGRO::DISPLAY& display, const ALLEGRO::MOUSE_CURSOR& cursor) -> bool
	{
		return al_set_mouse_cursor(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), (ALLEGRO::INTERNAL::MOUSE_CURSOR_DATA_PTR)cursor.get());
	}

	export inline auto set_system_mouse_cursor(const ALLEGRO::DISPLAY& display, const ALLEGRO::SYSTEM_MOUSE_CURSOR& cursor_id) -> bool
	{
		return al_set_system_mouse_cursor(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), cursor_id);
	}

	export inline auto show_mouse_cursor(const ALLEGRO::DISPLAY& display) -> bool
	{
		return al_show_mouse_cursor(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto hide_mouse_cursor(const ALLEGRO::DISPLAY& display) -> bool
	{
		return al_hide_mouse_cursor(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}
}
