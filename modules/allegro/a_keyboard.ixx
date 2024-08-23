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
	export inline bool is_keyboard_installed()
	{
		return al_is_keyboard_installed();
	}

	export inline bool install_keyboard()
	{
		return al_install_keyboard();
	}

	export inline void uninstall_keyboard()
	{
		return al_uninstall_keyboard();
	}

	export inline bool can_set_keyboard_leds()
	{
		return al_can_set_keyboard_leds();
	}

	export inline bool set_keyboard_leds(int32_t leds)
	{
		return al_set_keyboard_leds(leds);
	}

	export inline const char* keycode_to_name(int32_t keycode)
	{
		return al_keycode_to_name(keycode);
	}

	export inline void get_keyboard_state(ALLEGRO::KEYBOARD_STATE& ret_state)
	{
		al_get_keyboard_state(&ret_state);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline void clear_keyboard_state(ALLEGRO::DISPLAY& display)
	{
		al_clear_keyboard_state(dispaly.get());
	}
#endif

	export inline bool key_down(const ALLEGRO::KEYBOARD_STATE& state, int32_t keycode)
	{
		return al_key_down(&state, keycode);
	}

	export inline ALLEGRO::EVENT_SOURCE get_keyboard_event_source()
	{
		return ALLEGRO::EVENT_SOURCE(al_get_keyboard_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}
}
