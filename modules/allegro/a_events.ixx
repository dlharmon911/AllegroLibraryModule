export module allegro:events;

import <vector>;
import <memory>;
import <allegro5/events.h>;
import :base;
import :debug;
import :altime;
import :memory;

namespace ALLEGRO
{
    export using EVENT_QUEUE_DATA = ALLEGRO_EVENT_QUEUE;
    export using EVENT_QUEUE = std::shared_ptr<EVENT_QUEUE_DATA>;
    export using EVENT_SOURCE_DATA = ALLEGRO_EVENT_SOURCE;
    export using EVENT_SOURCE = std::shared_ptr<EVENT_SOURCE_DATA>;
    export using EVENT_TYPE = ALLEGRO_EVENT_TYPE;

    export enum
    {
        EVENT_TYPE_JOYSTICK_AXIS = ALLEGRO_EVENT_JOYSTICK_AXIS,
        EVENT_TYPE_JOYSTICK_BUTTON_DOWN = ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN,
        EVENT_TYPE_JOYSTICK_BUTTON_UP = ALLEGRO_EVENT_JOYSTICK_BUTTON_UP,
        EVENT_TYPE_JOYSTICK_CONFIGURATION = ALLEGRO_EVENT_JOYSTICK_CONFIGURATION,
        EVENT_TYPE_KEY_DOWN = ALLEGRO_EVENT_KEY_DOWN,
        EVENT_TYPE_KEY_CHAR = ALLEGRO_EVENT_KEY_CHAR,
        EVENT_TYPE_KEY_UP = ALLEGRO_EVENT_KEY_UP,
        EVENT_TYPE_MOUSE_AXES = ALLEGRO_EVENT_MOUSE_AXES,
        EVENT_TYPE_MOUSE_BUTTON_DOWN = ALLEGRO_EVENT_MOUSE_BUTTON_DOWN,
        EVENT_TYPE_MOUSE_BUTTON_UP = ALLEGRO_EVENT_MOUSE_BUTTON_UP,
        EVENT_TYPE_MOUSE_ENTER_DISPLAY = ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY,
        EVENT_TYPE_MOUSE_LEAVE_DISPLAY = ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY,
        EVENT_TYPE_MOUSE_WARPED = ALLEGRO_EVENT_MOUSE_WARPED,
        EVENT_TYPE_TIMER = ALLEGRO_EVENT_TIMER,
        EVENT_TYPE_DISPLAY_EXPOSE = ALLEGRO_EVENT_DISPLAY_EXPOSE,
        EVENT_TYPE_DISPLAY_RESIZE = ALLEGRO_EVENT_DISPLAY_RESIZE,
        EVENT_TYPE_DISPLAY_CLOSE = ALLEGRO_EVENT_DISPLAY_CLOSE,
        EVENT_TYPE_DISPLAY_LOST = ALLEGRO_EVENT_DISPLAY_LOST,
        EVENT_TYPE_DISPLAY_FOUND = ALLEGRO_EVENT_DISPLAY_FOUND,
        EVENT_TYPE_DISPLAY_SWITCH_IN = ALLEGRO_EVENT_DISPLAY_SWITCH_IN,
        EVENT_TYPE_DISPLAY_SWITCH_OUT = ALLEGRO_EVENT_DISPLAY_SWITCH_OUT,
        EVENT_TYPE_DISPLAY_ORIENTATION = ALLEGRO_EVENT_DISPLAY_ORIENTATION,
        EVENT_TYPE_DISPLAY_HALT_DRAWING = ALLEGRO_EVENT_DISPLAY_HALT_DRAWING,
        EVENT_TYPE_DISPLAY_RESUME_DRAWING = ALLEGRO_EVENT_DISPLAY_RESUME_DRAWING,
        EVENT_TYPE_TOUCH_BEGIN = ALLEGRO_EVENT_TOUCH_BEGIN,
        EVENT_TYPE_TOUCH_END = ALLEGRO_EVENT_TOUCH_END,
        EVENT_TYPE_TOUCH_MOVE = ALLEGRO_EVENT_TOUCH_MOVE,
        EVENT_TYPE_TOUCH_CANCEL = ALLEGRO_EVENT_TOUCH_CANCEL,
        EVENT_TYPE_DISPLAY_CONNECTED = ALLEGRO_EVENT_DISPLAY_CONNECTED,
        EVENT_TYPE_DISPLAY_DISCONNECTED = ALLEGRO_EVENT_DISPLAY_DISCONNECTED
    };

    export using ANY_EVENT = ::ALLEGRO_ANY_EVENT;
    export using DISPLAY_EVENT = ::ALLEGRO_DISPLAY_EVENT;
    export using JOYSTICK_EVENT = ::ALLEGRO_JOYSTICK_EVENT;
    export using KEYBOARD_EVENT = ::ALLEGRO_KEYBOARD_EVENT;
    export using MOUSE_EVENT = ::ALLEGRO_MOUSE_EVENT;
    export using TIMER_EVENT = ::ALLEGRO_TIMER_EVENT;
    export using TOUCH_EVENT = ::ALLEGRO_TOUCH_EVENT;
    export using USER_EVENT = ::ALLEGRO_USER_EVENT;
    export using DROP_EVENT = ::ALLEGRO_DROP_EVENT;
    export using EVENT = ::ALLEGRO_EVENT;
}

namespace al
{
    namespace internal
    {
        export inline void destroy_event_queue(ALLEGRO::EVENT_QUEUE_DATA* data)
        {
            al_destroy_event_queue(data);
        }

        export inline void destroy_user_event_source(ALLEGRO::EVENT_SOURCE_DATA* data)
        {
            al_destroy_user_event_source(data);
        }
    }

    export inline ALLEGRO::EVENT_SOURCE init_user_event_source()
    { 
        ALLEGRO_EVENT_SOURCE* source = new ALLEGRO_EVENT_SOURCE;

        //ALLEGRO_ASSERT(source);

        al_init_user_event_source(source);

        return ALLEGRO::EVENT_SOURCE(source, internal::destroy_user_event_source);
    }

    export inline bool emit_user_event(ALLEGRO::EVENT_SOURCE& source, ALLEGRO::EVENT* user_event, void (*dtor)(ALLEGRO::USER_EVENT*))
    {
        return al_emit_user_event(source.get(), user_event, dtor);
    }

    export inline void unref_user_event(ALLEGRO::USER_EVENT* event)
    {
        al_unref_user_event(event);
    }

    export inline void set_event_source_data(ALLEGRO::EVENT_SOURCE& source, intptr_t data)
    {
        al_set_event_source_data(source.get(), data);
    }

    export inline intptr_t get_event_source_data(ALLEGRO::EVENT_SOURCE& source)
    {
        return al_get_event_source_data(source.get());
    }

    export inline ALLEGRO::EVENT_QUEUE create_event_queue()
    {
        return ALLEGRO::EVENT_QUEUE(::al_create_event_queue(), internal::destroy_event_queue);
    }

    export inline bool is_event_source_registered(const ALLEGRO::EVENT_QUEUE& queue, const ALLEGRO::EVENT_SOURCE& source)
    {
        return al_is_event_source_registered(queue.get(), source.get());
    }

    export inline void register_event_source(ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT_SOURCE source)
    {
        al_register_event_source(queue.get(), source.get());
    }

    export inline void unregister_event_source(ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT_SOURCE source)
    {
        al_unregister_event_source(queue.get(), source.get());
    }

    export inline void pause_event_queue(ALLEGRO::EVENT_QUEUE& queue, bool pause)
    {
        al_pause_event_queue(queue.get(), pause);
    }

    export inline bool is_event_queue_paused(const ALLEGRO::EVENT_QUEUE& queue)
    {
        return al_is_event_queue_paused(queue.get());
    }

    export inline bool is_event_queue_empty(const ALLEGRO::EVENT_QUEUE& queue)
    {
        return al_is_event_queue_empty(queue.get());
    }

    export inline bool get_next_event(ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event)
    {
        return al_get_next_event(queue.get(), &ret_event);
    }

    export inline bool peek_next_event(const ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event)
    {
        return al_peek_next_event(queue.get(), &ret_event);
    }

    export inline bool drop_next_event(ALLEGRO::EVENT_QUEUE& queue)
    {
        return al_drop_next_event(queue.get());
    }

    export inline void flush_event_queue(ALLEGRO::EVENT_QUEUE& queue)
    {
        al_flush_event_queue(queue.get());
    }

    export inline void wait_for_event(ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event)
    {
        al_wait_for_event(queue.get(), &ret_event);
    }

    export inline bool wait_for_event_timed(ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event, float seconds)
    {
        return al_wait_for_event_timed(queue.get(), &ret_event, seconds);
    }

    export inline bool wait_for_event_until(ALLEGRO::EVENT_QUEUE& queue, ALLEGRO::EVENT& ret_event, ALLEGRO::TIMEOUT& timeout)
    {
        return al_wait_for_event_until(queue.get(), &ret_event, &timeout);
    }
}
