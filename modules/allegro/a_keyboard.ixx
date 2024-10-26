export module allegro:keyboard;

import <string>;
import <memory>;
import <allegro5\keyboard.h>;
import :base;
import :display;
import :events;
import :memory;

export import :keycodes;

namespace ALLEGRO
{
	export using KEYBOARD = ALLEGRO_KEYBOARD;
	export using KEYBOARD_STATE = ALLEGRO_KEYBOARD_STATE;
}

namespace al
{
	export inline auto is_keyboard_installed() -> bool
	{
		return al_is_keyboard_installed();
	}

	export inline auto install_keyboard() -> bool
	{
		return al_install_keyboard();
	}

	export inline auto uninstall_keyboard() -> void
	{
		return al_uninstall_keyboard();
	}

	export inline auto can_set_keyboard_leds() -> bool
	{
		return al_can_set_keyboard_leds();
	}

	export inline auto set_keyboard_leds(int32_t leds) -> bool
	{
		return al_set_keyboard_leds(leds);
	}

	export inline auto keycode_to_name(int32_t keycode) -> const char*
	{
		return (const char*)al_keycode_to_name(keycode);
	}

	export inline auto get_keyboard_state(ALLEGRO::KEYBOARD_STATE& ret_state) -> void
	{
		al_get_keyboard_state(&ret_state);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto clear_keyboard_state(ALLEGRO::DISPLAY& display) -> void
	{
		al_clear_keyboard_state(dispaly.get());
	}
#endif

	export inline auto key_down(const ALLEGRO::KEYBOARD_STATE& state, int32_t keycode) -> bool
	{
		return al_key_down(&state, keycode);
	}

	export inline auto get_keyboard_event_source() -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_keyboard_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}
}
