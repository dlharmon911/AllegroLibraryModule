export module allegro:mouse; 

import <memory>;
import <allegro5\mouse.h>;
import :base;
import :events;
import :display;
import :memory;

namespace ALLEGRO
{
	export using MOUSE = ::ALLEGRO_MOUSE;
	export using MOUSE_STATE = ::ALLEGRO_MOUSE_STATE;
}

namespace al
{
	export inline constexpr int32_t get_mouse_max_extra_axes()
	{
		return (int32_t)ALLEGRO_MOUSE_MAX_EXTRA_AXES;
	}

	export inline bool is_mouse_installed()
	{
		return al_is_mouse_installed();
	}

	export inline bool install_mouse()
	{
		return al_install_mouse();
	}

	export inline void uninstall_mouse()
	{
		al_uninstall_mouse();
	}

	export inline uint32_t get_mouse_num_buttons()
	{
		return al_get_mouse_num_buttons();
	}

	export inline uint32_t get_mouse_num_axes()
	{
		return al_get_mouse_num_axes();
	}

	export inline bool set_mouse_xy(ALLEGRO::DISPLAY& display, const ALLEGRO::POINT<int32_t> point)
	{
		return al_set_mouse_xy((ALLEGRO::DISPLAY_DATA*)display.get(), point.x, point.y);
	}

	export inline bool set_mouse_z(int32_t z)
	{
		return al_set_mouse_z(z);
	}

	export inline bool set_mouse_w(int32_t w)
	{
		return al_set_mouse_w(w);
	}

	export inline bool set_mouse_axis(int32_t axis, int32_t value)
	{
		return al_set_mouse_axis(axis, value);
	}

	export inline void get_mouse_state(ALLEGRO::MOUSE_STATE& ret_state)
	{
		al_get_mouse_state(&ret_state);
	}

	export inline bool is_mouse_button_down(const ALLEGRO::MOUSE_STATE& state, int32_t button)
	{
		return al_mouse_button_down(&state, button);
	}

	export inline int32_t get_mouse_state_axis(const ALLEGRO::MOUSE_STATE& state, int32_t axis)
	{
		return al_get_mouse_state_axis(&state, axis);
	}

	export inline bool can_get_mouse_cursor_position()
	{
		return al_can_get_mouse_cursor_position();
	}

	export inline bool get_mouse_cursor_position(ALLEGRO::POINT<int32_t>& point)
	{
		al_get_mouse_cursor_position(&point.x, &point.y);
	}
	
	export inline bool grab_mouse(const ALLEGRO::DISPLAY& display)
	{
		return al_grab_mouse((ALLEGRO::DISPLAY_DATA*)display.get());
	}

	export inline bool ungrab_mouse()
	{
		return al_ungrab_mouse();
	}

	export inline void set_mouse_wheel_precision(int32_t precision)
	{
		al_set_mouse_wheel_precision(precision);
	}

	export inline int32_t get_mouse_wheel_precision()
	{
		return al_get_mouse_wheel_precision();
	}

	export inline ALLEGRO::EVENT_SOURCE get_mouse_event_source()
	{
		return ALLEGRO::EVENT_SOURCE(al_get_mouse_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}
}
