export module allegro:touch_input;

import <memory>;
import <allegro5/touch_input.h>;
import :base;
import :events;
import :memory;

namespace ALLEGRO
{
	export using TOUCH_INPUT = typename ALLEGRO_TOUCH_INPUT;
	export using TOUCH_INPUT_STATE = typename ALLEGRO_TOUCH_INPUT_STATE;
	export using TOUCH_STATE = typename ALLEGRO_TOUCH_STATE;

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export constexpr int32_t MOUSE_EMULATION_NONE{ ALLEGRO_MOUSE_EMULATION_NONE };
	export constexpr int32_t MOUSE_EMULATION_TRANSPARENT{ ALLEGRO_MOUSE_EMULATION_TRANSPARENT };
	export constexpr int32_t MOUSE_EMULATION_INCLUSIVE{ ALLEGRO_MOUSE_EMULATION_INCLUSIVE };
	export constexpr int32_t MOUSE_EMULATION_EXCLUSIVE{ ALLEGRO_MOUSE_EMULATION_EXCLUSIVE };
	export constexpr int32_t MOUSE_EMULATION_5_0_x{ ALLEGRO_MOUSE_EMULATION_5_0_x };
#endif
}

namespace al
{
	export inline auto get_touch_input_max_touch_count() -> int32_t
	{
		return ALLEGRO_TOUCH_INPUT_MAX_TOUCH_COUNT;
	}

	export inline auto is_touch_input_installed() -> bool
	{
		return al_is_touch_input_installed();
	}

	export inline auto install_touch_input() -> bool
	{
		return al_install_touch_input();
	}

	export inline auto uninstall_touch_input() -> void
	{
		return al_uninstall_touch_input();
	}

	export inline auto get_touch_input_state(ALLEGRO::TOUCH_INPUT_STATE& ret_state) -> void
	{
		al_get_touch_input_state(&ret_state);
	}

	export inline auto get_touch_input_event_source() -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_touch_input_event_source(), al::internal::deleter_empty<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA>);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto set_mouse_emulation_mode(int32_t mode) -> void
	{
		return al_set_mouse_emulation_mode(mode);
	}

	export inline auto get_mouse_emulation_mode() -> int32_t
	{
		return al_get_mouse_emulation_mode();
	}

	export inline auto get_touch_input_mouse_emulation_event_source() -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_touch_input_mouse_emulation_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE::type>);
	}
#endif
}
