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
	export using JOYSTICK_DATA_PTR = std::add_pointer<JOYSTICK_DATA>::type;
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
	export inline auto install_joystick() -> bool
	{
		return al_install_joystick();
	}

	export inline void uninstall_joystick()
	{
		return al_uninstall_joystick();
	}

	export inline auto is_joystick_installed() -> bool
	{
		return al_is_joystick_installed();
	}

	export inline auto reconfigure_joysticks() -> bool
	{
		return al_reconfigure_joysticks();
	}

	export inline auto get_num_joysticks() -> int32_t
	{
		return al_get_num_joysticks();
	}

	export inline auto get_joystick(int32_t joynumber) -> ALLEGRO::JOYSTICK
	{
		return ALLEGRO::JOYSTICK(al_get_joystick(joynumber), al_release_joystick);
	}

	export inline auto get_joystick_active(ALLEGRO::JOYSTICK& joystick) -> bool
	{
		return al_get_joystick_active((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get());
	}

	export inline auto get_joystick_name(ALLEGRO::JOYSTICK& joystick) -> const_cptr_t
	{
		return (const_cptr_t)al_get_joystick_name((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get());
	}

	export inline auto get_joystick_num_sticks(ALLEGRO::JOYSTICK& joystick) -> int32_t
	{
		return al_get_joystick_num_sticks((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get());
	}

	export inline auto get_joystick_stick_flags(ALLEGRO::JOYSTICK& joystick, int32_t stick) -> int32_t
	{
		return al_get_joystick_stick_flags((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get(), stick);
	}

	export inline auto get_joystick_stick_name(ALLEGRO::JOYSTICK& joystick, int32_t stick) -> const_cptr_t
	{
		return (const_cptr_t)al_get_joystick_stick_name((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get(), stick);
	}

	export inline auto get_joystick_num_axes(ALLEGRO::JOYSTICK& joystick, int32_t stick) -> int32_t
	{
		return al_get_joystick_num_axes((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get(), stick);
	}

	export inline auto get_joystick_axis_name(ALLEGRO::JOYSTICK& joystick, int32_t stick, int32_t axis) -> const_cptr_t
	{
		return (const_cptr_t)al_get_joystick_axis_name((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get(), stick, axis);
	}

	export inline auto get_joystick_num_buttons(ALLEGRO::JOYSTICK& joystick) -> int32_t
	{
		return al_get_joystick_num_buttons((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get());
	}

	export inline auto get_joystick_button_name(ALLEGRO::JOYSTICK& joystick, int32_t button) -> const_cptr_t
	{
		return (const_cptr_t)al_get_joystick_button_name((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get(), button);
	}

	export inline auto get_joystick_state(ALLEGRO::JOYSTICK& joystick, ALLEGRO::JOYSTICK_STATE& state) -> void
	{
		al_get_joystick_state((ALLEGRO::JOYSTICK_DATA_PTR)joystick.get(), &state);
	}

	export inline auto get_joystick_event_source() -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_joystick_event_source(), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}
}
