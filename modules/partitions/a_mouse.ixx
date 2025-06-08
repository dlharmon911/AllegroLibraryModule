export module allegro:mouse;

import <memory>;
import <allegro5\mouse.h>;
import :base;
import :events;
import :display;
import :memory;
import :vector_2d;

namespace ALLEGRO
{
	export using MOUSE = ALLEGRO_MOUSE;
	export using MOUSE_STATE = ALLEGRO_MOUSE_STATE;

	export constexpr int32_t MOUSE_BUTTON_LEFT = ::ALLEGRO_MOUSE_BUTTON_LEFT;
	export constexpr int32_t MOUSE_BUTTON_RIGHT = ::ALLEGRO_MOUSE_BUTTON_RIGHT;
	export constexpr int32_t MOUSE_BUTTON_MIDDLE = ::ALLEGRO_MOUSE_BUTTON_MIDDLE;
}

namespace al
{
	export inline constexpr auto get_mouse_max_extra_axes() -> int32_t
	{
		return static_cast<int32_t>(ALLEGRO_MOUSE_MAX_EXTRA_AXES);
	}

	export inline auto is_mouse_installed() -> bool
	{
		return al_is_mouse_installed();
	}

	export inline auto install_mouse() -> bool
	{
		return al_install_mouse();
	}

	export inline auto uninstall_mouse() -> void
	{
		al_uninstall_mouse();
	}

	export inline auto get_mouse_num_buttons() -> uint32_t
	{
		return al_get_mouse_num_buttons();
	}

	export inline auto get_mouse_num_axes() -> uint32_t
	{
		return al_get_mouse_num_axes();
	}

	export inline auto set_mouse_xy(const ALLEGRO::DISPLAY& display, const ALLEGRO::VECTOR_2D<int32_t>& point) -> bool
	{
		return al_set_mouse_xy(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), point.get_x(), point.get_y());
	}

	export inline auto set_mouse_z(int32_t z) -> bool
	{
		return al_set_mouse_z(z);
	}

	export inline auto set_mouse_w(int32_t w) -> bool
	{
		return al_set_mouse_w(w);
	}

	export inline auto set_mouse_axis(int32_t axis, int32_t value) -> bool
	{
		return al_set_mouse_axis(axis, value);
	}

	export inline auto get_mouse_state(ALLEGRO::MOUSE_STATE& ret_state) -> void
	{
		al_get_mouse_state(&ret_state);
	}

	export inline auto is_mouse_button_down(const ALLEGRO::MOUSE_STATE& state, int32_t button) -> bool
	{
		return al_mouse_button_down(&state, button);
	}

	export inline auto get_mouse_state_axis(const ALLEGRO::MOUSE_STATE& state, int32_t axis) -> int32_t
	{
		return al_get_mouse_state_axis(&state, axis);
	}

	export inline auto can_get_mouse_cursor_position() -> bool
	{
		return al_can_get_mouse_cursor_position();
	}

	export inline auto get_mouse_cursor_position(ALLEGRO::VECTOR_2D<int32_t>& point) -> bool
	{
		std::array<int32_t, 2> point_array{};

		al_get_mouse_cursor_position(&point_array[0], &point_array[1]);

		point = point_array;
	}

	export inline auto grab_mouse(const ALLEGRO::DISPLAY& display) -> bool
	{
		return al_grab_mouse(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export inline auto ungrab_mouse() -> bool
	{
		return al_ungrab_mouse();
	}

	export inline auto set_mouse_wheel_precision(int32_t precision) -> void
	{
		al_set_mouse_wheel_precision(precision);
	}

	export inline auto get_mouse_wheel_precision() -> int32_t
	{
		return al_get_mouse_wheel_precision();
	}

	export inline auto get_mouse_event_source() -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_mouse_event_source(), al::internal::deleter_empty<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA>);
	}
}
