export module allegro:events;

import std;
import <allegro5/events.h>;
import :base;
import :debug;
import :error;
import :altime;
import :memory;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using EVENT_QUEUE_DATA = typename ALLEGRO_EVENT_QUEUE;
		export using EVENT_QUEUE_DATA_PTR = std::add_pointer<EVENT_QUEUE_DATA>::type;
		export using EVENT_SOURCE_DATA = typename ALLEGRO_EVENT_SOURCE;
		export using EVENT_SOURCE_DATA_PTR = std::add_pointer<EVENT_SOURCE_DATA>::type;
	}

	export using EVENT_QUEUE = typename std::shared_ptr<INTERNAL::EVENT_QUEUE_DATA>;
	export using EVENT_SOURCE = typename std::shared_ptr<INTERNAL::EVENT_SOURCE_DATA>;
	export using EVENT_TYPE = typename ALLEGRO_EVENT_TYPE;

	export constexpr int32_t EVENT_TYPE_JOYSTICK_AXIS{ ALLEGRO_EVENT_JOYSTICK_AXIS };
	export constexpr int32_t EVENT_TYPE_JOYSTICK_BUTTON_DOWN{ ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN };
	export constexpr int32_t EVENT_TYPE_JOYSTICK_BUTTON_UP{ ALLEGRO_EVENT_JOYSTICK_BUTTON_UP };
	export constexpr int32_t EVENT_TYPE_JOYSTICK_CONFIGURATION{ ALLEGRO_EVENT_JOYSTICK_CONFIGURATION };
	export constexpr int32_t EVENT_TYPE_KEY_DOWN{ ALLEGRO_EVENT_KEY_DOWN };
	export constexpr int32_t EVENT_TYPE_KEY_CHAR{ ALLEGRO_EVENT_KEY_CHAR };
	export constexpr int32_t EVENT_TYPE_KEY_UP{ ALLEGRO_EVENT_KEY_UP };
	export constexpr int32_t EVENT_TYPE_MOUSE_AXES{ ALLEGRO_EVENT_MOUSE_AXES };
	export constexpr int32_t EVENT_TYPE_MOUSE_BUTTON_DOWN{ ALLEGRO_EVENT_MOUSE_BUTTON_DOWN };
	export constexpr int32_t EVENT_TYPE_MOUSE_BUTTON_UP{ ALLEGRO_EVENT_MOUSE_BUTTON_UP };
	export constexpr int32_t EVENT_TYPE_MOUSE_ENTER_DISPLAY{ ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY };
	export constexpr int32_t EVENT_TYPE_MOUSE_LEAVE_DISPLAY{ ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY };
	export constexpr int32_t EVENT_TYPE_MOUSE_WARPED{ ALLEGRO_EVENT_MOUSE_WARPED };
	export constexpr int32_t EVENT_TYPE_TIMER{ ALLEGRO_EVENT_TIMER };
	export constexpr int32_t EVENT_TYPE_DISPLAY_EXPOSE{ ALLEGRO_EVENT_DISPLAY_EXPOSE };
	export constexpr int32_t EVENT_TYPE_DISPLAY_RESIZE{ ALLEGRO_EVENT_DISPLAY_RESIZE };
	export constexpr int32_t EVENT_TYPE_DISPLAY_CLOSE{ ALLEGRO_EVENT_DISPLAY_CLOSE };
	export constexpr int32_t EVENT_TYPE_DISPLAY_LOST{ ALLEGRO_EVENT_DISPLAY_LOST };
	export constexpr int32_t EVENT_TYPE_DISPLAY_FOUND{ ALLEGRO_EVENT_DISPLAY_FOUND };
	export constexpr int32_t EVENT_TYPE_DISPLAY_SWITCH_IN{ ALLEGRO_EVENT_DISPLAY_SWITCH_IN };
	export constexpr int32_t EVENT_TYPE_DISPLAY_SWITCH_OUT{ ALLEGRO_EVENT_DISPLAY_SWITCH_OUT };
	export constexpr int32_t EVENT_TYPE_DISPLAY_ORIENTATION{ ALLEGRO_EVENT_DISPLAY_ORIENTATION };
	export constexpr int32_t EVENT_TYPE_DISPLAY_HALT_DRAWING{ ALLEGRO_EVENT_DISPLAY_HALT_DRAWING };
	export constexpr int32_t EVENT_TYPE_DISPLAY_RESUME_DRAWING{ ALLEGRO_EVENT_DISPLAY_RESUME_DRAWING };
	export constexpr int32_t EVENT_TYPE_TOUCH_BEGIN{ ALLEGRO_EVENT_TOUCH_BEGIN };
	export constexpr int32_t EVENT_TYPE_TOUCH_END{ ALLEGRO_EVENT_TOUCH_END };
	export constexpr int32_t EVENT_TYPE_TOUCH_MOVE{ ALLEGRO_EVENT_TOUCH_MOVE };
	export constexpr int32_t EVENT_TYPE_TOUCH_CANCEL{ ALLEGRO_EVENT_TOUCH_CANCEL };
	export constexpr int32_t EVENT_TYPE_DISPLAY_CONNECTED{ ALLEGRO_EVENT_DISPLAY_CONNECTED };
	export constexpr int32_t EVENT_TYPE_DISPLAY_DISCONNECTED{ ALLEGRO_EVENT_DISPLAY_DISCONNECTED };
	export constexpr int32_t EVENT_TYPE_DROP{ ALLEGRO_EVENT_DROP };

	export using ANY_EVENT = typename ALLEGRO_ANY_EVENT;
	export using DISPLAY_EVENT = typename ALLEGRO_DISPLAY_EVENT;
	export using JOYSTICK_EVENT = typename ALLEGRO_JOYSTICK_EVENT;
	export using KEYBOARD_EVENT = typename ALLEGRO_KEYBOARD_EVENT;
	export using MOUSE_EVENT = typename ALLEGRO_MOUSE_EVENT;
	export using TIMER_EVENT = typename ALLEGRO_TIMER_EVENT;
	export using TOUCH_EVENT = typename ALLEGRO_TOUCH_EVENT;
	export using USER_EVENT = typename ALLEGRO_USER_EVENT;
	export using DROP_EVENT = typename ALLEGRO_DROP_EVENT;
	export using EVENT = typename ALLEGRO_EVENT;
}

namespace al
{
	namespace internal
	{
		export inline auto create_event_queue() -> ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR
		{
			return al_create_event_queue();
		}

		export inline auto destroy_event_queue(ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR data) -> void
		{
			al_destroy_event_queue(data);
		}

		export inline auto destroy_user_event_source(ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR data) -> void
		{
			al_destroy_user_event_source(data);
		}
	}

	export inline auto init_user_event_source() -> ALLEGRO::EVENT_SOURCE
	{
		ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR source{ new ALLEGRO::INTERNAL::EVENT_SOURCE_DATA };

		ALLEGRO::ASSERT(source);

		al_init_user_event_source(source);

		return ALLEGRO::EVENT_SOURCE(source, internal::destroy_user_event_source);
	}

	export inline auto emit_user_event(const ALLEGRO::EVENT_SOURCE& source, ALLEGRO::EVENT& user_event, void (*dtor)(ALLEGRO::USER_EVENT*)) -> bool
	{
		return al_emit_user_event(static_cast<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR>(source.get()), &user_event, dtor);
	}

	export inline auto unref_user_event(ALLEGRO::USER_EVENT& event) -> void
	{
		al_unref_user_event(&event);
	}

	export inline auto set_event_source_data(const ALLEGRO::EVENT_SOURCE& source, intptr_t data) -> void
	{
		al_set_event_source_data(static_cast<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR>(source.get()), data);
	}

	export inline auto get_event_source_data(const ALLEGRO::EVENT_SOURCE& source) -> intptr_t
	{
		return al_get_event_source_data(static_cast<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR>(source.get()));
	}

	export inline auto create_event_queue() -> ALLEGRO::EVENT_QUEUE
	{
		return ALLEGRO::EVENT_QUEUE(::al_create_event_queue(), internal::destroy_event_queue);
	}

	export inline auto is_event_source_registered(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT_SOURCE source) -> bool
	{
		return al_is_event_source_registered(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), static_cast<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR>(source.get()));
	}

	export inline auto register_event_source(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT_SOURCE source) -> void
	{
		al_register_event_source(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), static_cast<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR>(source.get()));
	}

	export inline auto unregister_event_source(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT_SOURCE source) -> void
	{
		al_unregister_event_source(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), static_cast<ALLEGRO::INTERNAL::EVENT_SOURCE_DATA_PTR>(source.get()));
	}

	export inline auto pause_event_queue(const ALLEGRO::EVENT_QUEUE& queue, bool pause) -> void
	{
		al_pause_event_queue(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), pause);
	}

	export inline auto is_event_queue_paused(const ALLEGRO::EVENT_QUEUE& queue) -> bool
	{
		return al_is_event_queue_paused(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()));
	}

	export inline auto is_event_queue_empty(const ALLEGRO::EVENT_QUEUE& queue) -> bool
	{
		return al_is_event_queue_empty(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()));
	}

	export inline auto get_next_event(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event) -> bool
	{
		return al_get_next_event(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), &ret_event);
	}

	export inline auto peek_next_event(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event) -> bool
	{
		return al_peek_next_event(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), &ret_event);
	}

	export inline auto drop_next_event(const ALLEGRO::EVENT_QUEUE& queue) -> bool
	{
		return al_drop_next_event(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()));
	}

	export inline auto flush_event_queue(const ALLEGRO::EVENT_QUEUE& queue) -> void
	{
		al_flush_event_queue(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()));
	}

	export inline auto wait_for_event(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event) -> void
	{
		al_wait_for_event(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), &ret_event);
	}

	export inline auto wait_for_event_timed(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event, float seconds) -> bool
	{
		return al_wait_for_event_timed(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), &ret_event, seconds);
	}

	export inline auto wait_for_event_until(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event, ALLEGRO::TIMEOUT& timeout) -> bool
	{
		return al_wait_for_event_until(static_cast<ALLEGRO::INTERNAL::EVENT_QUEUE_DATA_PTR>(queue.get()), &ret_event, &timeout);
	}
}
