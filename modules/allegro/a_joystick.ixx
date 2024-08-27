export module allegro:joystick;

import <string>;
import <memory>;
import <allegro5/joystick.h>;
import :base;
import :events;
import :memory;

namespace ALLEGRO
{
	export using JOYSTICK_DATA = ALLEGRO_JOYSTICK;
	export using JOYSTICK = std::shared_ptr<JOYSTICK_DATA>;
	export using JOYSTICK_STATE = ALLEGRO_JOYSTICK_STATE;

	export enum JOYFLAGS
	{
		JOYFLAG_DIGITAL = ALLEGRO_JOYFLAG_DIGITAL,
		JOYFLAG_ANALOGUE = ALLEGRO_JOYFLAG_ANALOGUE
	};
}

namespace al
{
	export inline bool install_joystick()
	{
		return al_install_joystick();
	}

	export inline void uninstall_joystick()
	{
		return al_uninstall_joystick();
	}

	export inline bool is_joystick_installed()
	{
		return al_is_joystick_installed();
	}

	export inline bool reconfigure_joysticks()
	{
		return al_reconfigure_joysticks();
	}

	export inline int32_t get_num_joysticks()
	{
		return al_get_num_joysticks();
	}

	export inline ALLEGRO::JOYSTICK get_joystick(int32_t joynumber)
	{
		return ALLEGRO::JOYSTICK(al_get_joystick(joynumber), al_release_joystick);
	}

	export inline bool get_joystick_active(ALLEGRO::JOYSTICK& joystick)
	{
		return al_get_joystick_active((ALLEGRO::JOYSTICK_DATA*)joystick.get());
	}

	export inline const char* get_joystick_name(ALLEGRO::JOYSTICK& joystick)
	{
		return al_get_joystick_name((ALLEGRO::JOYSTICK_DATA*)joystick.get());
	}

	export inline int32_t get_joystick_num_sticks(ALLEGRO::JOYSTICK& joystick)
	{
		return al_get_joystick_num_sticks((ALLEGRO::JOYSTICK_DATA*)joystick.get());
	}

	export inline int32_t get_joystick_stick_flags(ALLEGRO::JOYSTICK& joystick, int32_t stick)
	{
		return al_get_joystick_stick_flags((ALLEGRO::JOYSTICK_DATA*)joystick.get(), stick);
	}

	export inline const char* get_joystick_stick_name(ALLEGRO::JOYSTICK& joystick, int32_t stick)
	{
		return al_get_joystick_stick_name((ALLEGRO::JOYSTICK_DATA*)joystick.get(), stick);
	}

	export inline int32_t get_joystick_num_axes(ALLEGRO::JOYSTICK& joystick, int32_t stick)
	{
		return al_get_joystick_num_axes((ALLEGRO::JOYSTICK_DATA*)joystick.get(), stick);
	}

	export inline const char* get_joystick_axis_name(ALLEGRO::JOYSTICK& joystick, int32_t stick, int32_t axis)
	{
		return al_get_joystick_axis_name((ALLEGRO::JOYSTICK_DATA*)joystick.get(), stick, axis);
	}

	export inline int32_t get_joystick_num_buttons(ALLEGRO::JOYSTICK& joystick)
	{
		return al_get_joystick_num_buttons((ALLEGRO::JOYSTICK_DATA*)joystick.get());
	}

	export inline const char* get_joystick_button_name(ALLEGRO::JOYSTICK& joystick, int32_t button)
	{
		return al_get_joystick_button_name((ALLEGRO::JOYSTICK_DATA*)joystick.get(), button);
	}

	export inline void get_joystick_state(ALLEGRO::JOYSTICK& joystick, ALLEGRO::JOYSTICK_STATE& state)
	{
		al_get_joystick_state((ALLEGRO::JOYSTICK_DATA*)joystick.get(), &state);
	}

	export inline ALLEGRO::EVENT_SOURCE get_joystick_event_source()
	{
		return ALLEGRO::EVENT_SOURCE(al_get_joystick_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}
}
