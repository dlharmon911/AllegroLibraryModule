export module allegro:haptic;

import <memory>;
import <allegro5/haptic.h>;
import :base;
import :memory;
import :mouse;
import :keyboard;
import :display;
import :touch_input;

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
namespace ALLEGRO
{
	export enum
	{
		HAPTIC_RUMBLE = ALLEGRO_HAPTIC_RUMBLE,
		HAPTIC_PERIODIC = ALLEGRO_HAPTIC_PERIODIC,
		HAPTIC_CONSTANT = ALLEGRO_HAPTIC_CONSTANT,
		HAPTIC_SPRIN = ALLEGRO_HAPTIC_SPRING,
		HAPTIC_FRICTION = ALLEGRO_HAPTIC_FRICTION,
		HAPTIC_DAMPER = ALLEGRO_HAPTIC_DAMPER,
		HAPTIC_INERTIA = ALLEGRO_HAPTIC_INERTIA,
		HAPTIC_RAMP = ALLEGRO_HAPTIC_RAMP,
		HAPTIC_SQUARE = ALLEGRO_HAPTIC_SQUARE,
		HAPTIC_TRIANGLE = ALLEGRO_HAPTIC_TRIANGLE,
		HAPTIC_SINE = ALLEGRO_HAPTIC_SINE,
		HAPTIC_SAW_UP = ALLEGRO_HAPTIC_SAW_UP,
		HAPTIC_SAW_DOWN = ALLEGRO_HAPTIC_SAW_DOWN,
		HAPTIC_CUSTOM = ALLEGRO_HAPTIC_CUSTOM,
		HAPTIC_GAIN = ALLEGRO_HAPTIC_GAIN,
		HAPTIC_ANGLE = ALLEGRO_HAPTIC_ANGLE,
		HAPTIC_RADIUS = ALLEGRO_HAPTIC_RADIUS,
		HAPTIC_AZIMUTH = ALLEGRO_HAPTIC_AZIMUTH,
		HAPTIC_AUTOCENTER = ALLEGRO_HAPTIC_AUTOCENTER,
	};

	export using HAPTIC_DATA = ALLEGRO_HAPTIC;
	export using HAPTIC = ALLEGRO::OBJECT_TYPE;

	export using HAPTIC_DIRECTION = ALLEGRO_HAPTIC_DIRECTION;
	export using HAPTIC_REPLAY = ALLEGRO_HAPTIC_REPLAY;
	export using HAPTIC_ENVELOPE = ALLEGRO_HAPTIC_ENVELOPE;
	export using HAPTIC_CONSTANT_EFFECT = ALLEGRO_HAPTIC_CONSTANT_EFFECT;
	export using HAPTIC_RAMP_EFFECT = ALLEGRO_HAPTIC_RAMP_EFFECT;
	export using HAPTIC_CONDITION_EFFECT = ALLEGRO_HAPTIC_CONDITION_EFFECT;
	export using HAPTIC_PERIODIC_EFFECT = ALLEGRO_HAPTIC_PERIODIC_EFFECT;
	export using HAPTIC_RUMBLE_EFFECT = ALLEGRO_HAPTIC_RUMBLE_EFFECT;
	export using HAPTIC_EFFECT_UNION = ALLEGRO_HAPTIC_EFFECT_UNION;
	export using HAPTIC_EFFECT = ALLEGRO_HAPTIC_EFFECT;
	export using HAPTIC_EFFECT_ID = ALLEGRO_HAPTIC_EFFECT_ID;
}

namespace al
{
	export inline bool install_haptic()
	{
		return al_install_haptic();
	}

	export inline void uninstall_haptic()
	{
		return al_uninstall_haptic();
	}

	export inline bool is_haptic_installed()
	{
		return al_is_haptic_installed();
	}

	export inline bool is_mouse_haptic(ALLEGRO::MOUSE& mouse)
	{
		return al_is_mouse_haptic(&mouse);
	}

	export inline bool is_joystick_haptic(ALLEGRO::JOYSTICK& joystick)
	{
		return al_is_joystick_haptic(&joystick);
	}

	export inline bool is_keyboard_haptic(ALLEGRO::KEYBOARD& keyboard)
	{
		return al_is_keyboard_haptic(&keyboard);
	}

	export inline bool is_display_haptic(ALLEGRO::DISPLAY& display)
	{
		return al_is_display_haptic(&display);
	}

	export inline bool is_touch_input_haptic(ALLEGRO::TOUCH_INPUT& touch_input)
	{
		return al_is_touch_input_haptic(&touch_input);
	}

	export inline ALLEGRO::HAPTIC get_haptic_from_mouse(ALLEGRO::MOUSE& mouse)
	{
		return al_get_haptic_from_mouse(&mouse);
	}

	export inline ALLEGRO::HAPTIC get_haptic_from_joystick(ALLEGRO::JOYSTICK& joystick)
	{
		return al_get_haptic_from_joystick(&joystick);
	}

	export inline ALLEGRO::HAPTIC get_haptic_from_keyboard(ALLEGRO::KEYBOARD& keyboard)
	{
		return al_get_haptic_from_keyboard(&keyboard);
	}

	export inline ALLEGRO::HAPTIC get_haptic_from_display(ALLEGRO::DISPLAY& display)
	{
		return al_get_haptic_from_display(&display);
	}

	export inline ALLEGRO::HAPTIC get_haptic_from_touch_input(ALLEGRO::TOUCH_INPUT& touch_input)
	{
		return al_get_haptic_from_touch_input(&touch_input);
	}

	export inline bool release_haptic(ALLEGRO::HAPTIC& haptic));
	export inline bool is_haptic_active(ALLEGRO::HAPTIC& haptic));
	export inline int32_t get_haptic_capabilities(ALLEGRO::HAPTIC& haptic));
	export inline bool is_haptic_capable(ALLEGRO::HAPTIC& haptic, int32_t));
	export inline bool set_haptic_gain(ALLEGRO::HAPTIC& haptic, double));
	export inline double get_haptic_gain(ALLEGRO::HAPTIC& haptic));
	export inline bool set_haptic_autocenter(ALLEGRO::HAPTIC& haptic, double));
	export inline double get_haptic_autocenter(ALLEGRO::HAPTIC& haptic));
	export inline int32_t get_max_haptic_effects(ALLEGRO::HAPTIC& haptic));
	export inline bool is_haptic_effect_ok(ALLEGRO::HAPTIC& haptic, ALLEGRO::HAPTIC_EFFECT*));
	export inline bool upload_haptic_effect(ALLEGRO::HAPTIC& haptic, ALLEGRO::HAPTIC_EFFECT*, ALLEGRO::HAPTIC_EFFECT_ID*));
	export inline bool play_haptic_effect(ALLEGRO::HAPTIC_EFFECT_ID*, int32_t));
	export inline bool upload_and_play_haptic_effect(ALLEGRO::HAPTIC& haptic, ALLEGRO::HAPTIC_EFFECT*, ALLEGRO::HAPTIC_EFFECT_ID*, int32_t));
	export inline bool stop_haptic_effect(ALLEGRO::HAPTIC_EFFECT_ID*));
	export inline bool is_haptic_effect_playing(ALLEGRO::HAPTIC_EFFECT_ID*));
	export inline bool release_haptic_effect(ALLEGRO::HAPTIC_EFFECT_ID*));
	export inline double get_haptic_effect_duration(ALLEGRO::HAPTIC_EFFECT*));
	export inline bool rumble_haptic(ALLEGRO::HAPTIC& haptic, double, double, ALLEGRO::HAPTIC_EFFECT_ID*));

}
#endif
