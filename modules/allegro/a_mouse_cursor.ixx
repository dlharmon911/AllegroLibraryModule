export module allegro:mouse_cursor;

import <memory>;
import <allegro5/mouse_cursor.h>;
import :base;
import :bitmap;
import :display;
import :memory;

namespace ALLEGRO
{
	export using MOUSE_CURSOR_DATA = ALLEGRO_MOUSE_CURSOR;
	export using MOUSE_CURSOR_DATA_PTR = std::add_pointer<MOUSE_CURSOR_DATA>::type;
	export using MOUSE_CURSOR = std::shared_ptr<MOUSE_CURSOR_DATA>;
	export using SYSTEM_MOUSE_CURSOR = ALLEGRO_SYSTEM_MOUSE_CURSOR;

	export enum
	{
		SYSTEM_MOUSE_CURSOR_NONE = ALLEGRO_SYSTEM_MOUSE_CURSOR_NONE,
		SYSTEM_MOUSE_CURSOR_DEFAULT = ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT,
		SYSTEM_MOUSE_CURSOR_ARROW = ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW,
		SYSTEM_MOUSE_CURSOR_BUSY = ALLEGRO_SYSTEM_MOUSE_CURSOR_BUSY,
		SYSTEM_MOUSE_CURSOR_QUESTION = ALLEGRO_SYSTEM_MOUSE_CURSOR_QUESTION,
		SYSTEM_MOUSE_CURSOR_EDIT = ALLEGRO_SYSTEM_MOUSE_CURSOR_EDIT,
		SYSTEM_MOUSE_CURSOR_MOVE = ALLEGRO_SYSTEM_MOUSE_CURSOR_MOVE,
		SYSTEM_MOUSE_CURSOR_RESIZE_N = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_N,
		SYSTEM_MOUSE_CURSOR_RESIZE_W = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_W,
		SYSTEM_MOUSE_CURSOR_RESIZE_S = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_S,
		SYSTEM_MOUSE_CURSOR_RESIZE_E = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_E,
		SYSTEM_MOUSE_CURSOR_RESIZE_NW = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_NW,
		SYSTEM_MOUSE_CURSOR_RESIZE_SW = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_SW,
		SYSTEM_MOUSE_CURSOR_RESIZE_SE = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_SE,
		SYSTEM_MOUSE_CURSOR_RESIZE_NE = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_NE,
		SYSTEM_MOUSE_CURSOR_PROGRESS = ALLEGRO_SYSTEM_MOUSE_CURSOR_PROGRESS,
		SYSTEM_MOUSE_CURSOR_PRECISION = ALLEGRO_SYSTEM_MOUSE_CURSOR_PRECISION,
		SYSTEM_MOUSE_CURSOR_LINK = ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK,
		SYSTEM_MOUSE_CURSOR_ALT_SELECT = ALLEGRO_SYSTEM_MOUSE_CURSOR_ALT_SELECT,
		SYSTEM_MOUSE_CURSOR_UNAVAILABLE = ALLEGRO_SYSTEM_MOUSE_CURSOR_UNAVAILABLE,
		SYSTEM_MOUSE_CURSOR_COUNT = ALLEGRO_NUM_SYSTEM_MOUSE_CURSORS
	};
}

namespace al
{
	namespace internal
	{
		export inline auto create_mouse_cursor(ALLEGRO::BITMAP_DATA_PTR bitmap, const ALLEGRO::POINT<int32_t>& focus) -> ALLEGRO::MOUSE_CURSOR_DATA_PTR
		{
			return al_create_mouse_cursor(bitmap, focus.x, focus.y);
		}

		export inline auto destroy_mouse_cursor(ALLEGRO::MOUSE_CURSOR_DATA_PTR data) -> void
		{
			al_destroy_mouse_cursor(data);
		}
	}

	export inline auto create_mouse_cursor(const ALLEGRO::BITMAP& sprite, const ALLEGRO::POINT<int32_t>& focus) -> ALLEGRO::MOUSE_CURSOR
	{
		return ALLEGRO::MOUSE_CURSOR(al_create_mouse_cursor((ALLEGRO::BITMAP_DATA_PTR)sprite.get(), focus.x, focus.y), internal::destroy_mouse_cursor);
	}

	export inline auto set_mouse_cursor(const ALLEGRO::DISPLAY& display, const ALLEGRO::MOUSE_CURSOR& cursor) -> bool
	{
		return al_set_mouse_cursor((ALLEGRO::DISPLAY_DATA_PTR)display.get(), (ALLEGRO::MOUSE_CURSOR_DATA_PTR)cursor.get());
	}

	export inline auto set_system_mouse_cursor(const ALLEGRO::DISPLAY& display, const ALLEGRO::SYSTEM_MOUSE_CURSOR& cursor_id) -> bool
	{
		return al_set_system_mouse_cursor((ALLEGRO::DISPLAY_DATA_PTR)display.get(), cursor_id);
	}

	export inline auto show_mouse_cursor(const ALLEGRO::DISPLAY& display) -> bool
	{
		return al_show_mouse_cursor((ALLEGRO::DISPLAY_DATA_PTR)display.get());
	}

	export inline auto hide_mouse_cursor(const ALLEGRO::DISPLAY& display) -> bool
	{
		return al_hide_mouse_cursor((ALLEGRO::DISPLAY_DATA_PTR)display.get());
	}
}