export module allegro:touch_input;

import <memory>;
import <allegro5/touch_input.h>;
import :base;
import :events;
import :memory;

namespace ALLEGRO
{
	export inline int32_t get_touch_input_max_touch_count()
	{
		return ALLEGRO_TOUCH_INPUT_MAX_TOUCH_COUNT;
	}

	export using TOUCH_INPUT = ALLEGRO_TOUCH_INPUT;
	export using TOUCH_INPUT_STATE = ALLEGRO_TOUCH_INPUT_STATE;
	export using TOUCH_STATE = ALLEGRO_TOUCH_STATE;

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export using MOUSE_EMULATION_MODE = ALLEGRO_MOUSE_EMULATION_MODE;
	export enum
	{
		MOUSE_EMULATION_NONE = ALLEGRO_MOUSE_EMULATION_NONE,
		MOUSE_EMULATION_TRANSPARENT = ALLEGRO_MOUSE_EMULATION_TRANSPARENT,
		MOUSE_EMULATION_INCLUSIVE = ALLEGRO_MOUSE_EMULATION_INCLUSIVE,
		MOUSE_EMULATION_EXCLUSIVE = ALLEGRO_MOUSE_EMULATION_EXCLUSIVE,
		MOUSE_EMULATION_5_0_x = ALLEGRO_MOUSE_EMULATION_5_0_x
	};
#endif
}

namespace al
{
	export inline bool is_touch_input_installed()
	{
		return al_is_touch_input_installed();
	}

	export inline bool install_touch_input()
	{
		return al_install_touch_input();
	}

	export inline void uninstall_touch_input()
	{
		return al_uninstall_touch_input();
	}

	export inline void get_touch_input_state(ALLEGRO::TOUCH_INPUT_STATE& ret_state)
	{
		al_get_touch_input_state(&ret_state);
	}

	export inline ALLEGRO::EVENT_SOURCE get_touch_input_event_source()
	{
		return ALLEGRO::EVENT_SOURCE(al_get_touch_input_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline void set_mouse_emulation_mode(int32_t mode)
	{
		return al_set_mouse_emulation_mode(mode);
	}

	export inline int32_t get_mouse_emulation_mode()
	{
		return al_get_mouse_emulation_mode();
	}

	export inline ALLEGRO::EVENT_SOURCE get_touch_input_mouse_emulation_event_source()
	{
		return ALLEGRO::EVENT_SOURCE(al_get_touch_input_mouse_emulation_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE::type>);
	}
#endif
}