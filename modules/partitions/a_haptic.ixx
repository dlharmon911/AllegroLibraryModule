export module allegro:haptic;

import <memory>;
import <allegro5/haptic.h>;
import :base;
import :memory;
import :mouse;
import :keyboard;
import :display;
import :joystick;
import :touch_input;

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using HAPTIC_DATA = typename ALLEGRO_HAPTIC;
		export using HAPTIC_DATA_PTR = std::add_pointer<HAPTIC_DATA>::type;
	}

	export using HAPTIC = typename std::shared_ptr<INTERNAL::HAPTIC_DATA>;

	export constexpr int32_t HAPTIC_RUMBLE{ ALLEGRO_HAPTIC_RUMBLE };
	export constexpr int32_t HAPTIC_PERIODIC{ ALLEGRO_HAPTIC_PERIODIC };
	export constexpr int32_t HAPTIC_CONSTANT{ ALLEGRO_HAPTIC_CONSTANT };
	export constexpr int32_t HAPTIC_SPRIN{ ALLEGRO_HAPTIC_SPRING };
	export constexpr int32_t HAPTIC_FRICTION{ ALLEGRO_HAPTIC_FRICTION };
	export constexpr int32_t HAPTIC_DAMPER{ ALLEGRO_HAPTIC_DAMPER };
	export constexpr int32_t HAPTIC_INERTIA{ ALLEGRO_HAPTIC_INERTIA };
	export constexpr int32_t HAPTIC_RAMP{ ALLEGRO_HAPTIC_RAMP };
	export constexpr int32_t HAPTIC_SQUARE{ ALLEGRO_HAPTIC_SQUARE };
	export constexpr int32_t HAPTIC_TRIANGLE{ ALLEGRO_HAPTIC_TRIANGLE };
	export constexpr int32_t HAPTIC_SINE{ ALLEGRO_HAPTIC_SINE };
	export constexpr int32_t HAPTIC_SAW_UP{ ALLEGRO_HAPTIC_SAW_UP };
	export constexpr int32_t HAPTIC_SAW_DOWN{ ALLEGRO_HAPTIC_SAW_DOWN };
	export constexpr int32_t HAPTIC_CUSTOM{ ALLEGRO_HAPTIC_CUSTOM };
	export constexpr int32_t HAPTIC_GAIN{ ALLEGRO_HAPTIC_GAIN };
	export constexpr int32_t HAPTIC_ANGLE{ ALLEGRO_HAPTIC_ANGLE };
	export constexpr int32_t HAPTIC_RADIUS{ ALLEGRO_HAPTIC_RADIUS };
	export constexpr int32_t HAPTIC_AZIMUTH{ ALLEGRO_HAPTIC_AZIMUTH };
	export constexpr int32_t HAPTIC_AUTOCENTER{ ALLEGRO_HAPTIC_AUTOCENTER };

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
	export using HAPTIC_EFFECT_PTR = std::add_pointer<HAPTIC_EFFECT>::type;
	export using HAPTIC_EFFECT_ID = ALLEGRO_HAPTIC_EFFECT_ID;
	export using HAPTIC_EFFECT_ID_PTR = std::add_pointer<HAPTIC_EFFECT_ID>::type;
}

namespace al
{
	export inline auto install_haptic() -> bool
	{
		return al_install_haptic();
	}

	export inline auto uninstall_haptic() -> void
	{
		return al_uninstall_haptic();
	}

	export inline auto is_haptic_installed() -> bool
	{
		return al_is_haptic_installed();
	}

	export inline auto is_mouse_haptic(ALLEGRO::MOUSE& mouse) -> bool
	{
		return al_is_mouse_haptic(&mouse);
	}

	export inline auto is_joystick_haptic(ALLEGRO::JOYSTICK& joystick) -> bool
	{
		return al_is_joystick_haptic(&joystick);
	}

	export inline auto is_keyboard_haptic(ALLEGRO::KEYBOARD& keyboard) -> bool
	{
		return al_is_keyboard_haptic(&keyboard);
	}

	export inline auto is_display_haptic(ALLEGRO::DISPLAY& display) -> bool
	{
		return al_is_display_haptic(&display);
	}

	export inline auto is_touch_input_haptic(ALLEGRO::TOUCH_INPUT& touch_input) -> bool
	{
		return al_is_touch_input_haptic(&touch_input);
	}

	export inline auto get_haptic_from_mouse(ALLEGRO::MOUSE& mouse) -> ALLEGRO::HAPTIC
	{
		return al_get_haptic_from_mouse(&mouse);
	}

	export inline auto get_haptic_from_joystick(ALLEGRO::JOYSTICK& joystick) -> ALLEGRO::HAPTIC
	{
		return al_get_haptic_from_joystick(&joystick);
	}

	export inline auto get_haptic_from_keyboard(ALLEGRO::KEYBOARD& keyboard) -> ALLEGRO::HAPTIC
	{
		return al_get_haptic_from_keyboard(&keyboard);
	}

	export inline auto get_haptic_from_display(ALLEGRO::DISPLAY& display) -> ALLEGRO::HAPTIC
	{
		return al_get_haptic_from_display(&display);
	}

	export inline auto get_haptic_from_touch_input(ALLEGRO::TOUCH_INPUT& touch_input) -> ALLEGRO::HAPTIC
	{
		return al_get_haptic_from_touch_input(&touch_input);
	}

	export inline auto release_haptic(ALLEGRO::HAPTIC& haptic) -> bool;
	export inline auto is_haptic_active(ALLEGRO::HAPTIC& haptic) -> bool;
	export inline auto get_haptic_capabilities(ALLEGRO::HAPTIC& haptic) -> int32_t;
	export inline auto is_haptic_capable(ALLEGRO::HAPTIC& haptic, int32_t)) -> bool;
	export inline auto set_haptic_gain(ALLEGRO::HAPTIC& haptic, double)) -> bool;
	export inline auto get_haptic_gain(ALLEGRO::HAPTIC& haptic) -> double;
	export inline auto set_haptic_autocenter(ALLEGRO::HAPTIC& haptic, double)) -> bool;
	export inline auto get_haptic_autocenter(ALLEGRO::HAPTIC& haptic) -> double;
	export inline auto get_max_haptic_effects(ALLEGRO::HAPTIC& haptic) -> int32_t;
	export inline auto is_haptic_effect_ok(ALLEGRO::HAPTIC& haptic, ALLEGRO::HAPTIC_EFFECT_PTR)) -> bool;
	export inline auto upload_haptic_effect(ALLEGRO::HAPTIC& haptic, ALLEGRO::HAPTIC_EFFECT_PTR, ALLEGRO::HAPTIC_EFFECT_ID_PTR)) -> bool;
	export inline auto play_haptic_effect(ALLEGRO::HAPTIC_EFFECT_ID_PTR, int32_t)) -> bool;
	export inline auto upload_and_play_haptic_effect(ALLEGRO::HAPTIC& haptic, ALLEGRO::HAPTIC_EFFECT_PTR, ALLEGRO::HAPTIC_EFFECT_ID_PTR, int32_t)) -> bool;
	export inline auto stop_haptic_effect(ALLEGRO::HAPTIC_EFFECT_ID_PTR)) -> bool;
	export inline auto is_haptic_effect_playing(ALLEGRO::HAPTIC_EFFECT_ID_PTR)) -> bool;
	export inline auto release_haptic_effect(ALLEGRO::HAPTIC_EFFECT_ID_PTR)) -> bool;
	export inline auto get_haptic_effect_duration(ALLEGRO::HAPTIC_EFFECT_PTR)) -> double;
	export inline auto rumble_haptic(ALLEGRO::HAPTIC& haptic, double, double, ALLEGRO::HAPTIC_EFFECT_ID_PTR)) -> bool;
}
#endif
