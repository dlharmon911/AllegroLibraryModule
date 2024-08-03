export module allegro:timer;

import <memory>;
import <allegro5/timer.h>;
import :base;
import :events;
import :memory;

namespace ALLEGRO
{
	export using TIMER_DATA = ALLEGRO_TIMER;
	export using TIMER = std::shared_ptr<TIMER_DATA>;
}

namespace al
{
	export inline double usecs_to_secs(double x) { return ((x) / 1000000.0); }
	export inline double msecs_to_secs(double x) { return ((x) / 1000.0); }
	export inline double bps_to_secs(double x) { return (1.0 / (x)); }
	export inline double bpm_to_secs(double x) { return (60.0 / (x)); }

	namespace internal
	{
		export inline void destroy_timer(ALLEGRO::TIMER_DATA* data)
		{
			al_destroy_timer(data);
		}
	}

	export inline ALLEGRO::TIMER create_timer(double seconds)
	{
		return ALLEGRO::TIMER(::al_create_timer(seconds), internal::destroy_timer);
	}

	export inline void start_timer(ALLEGRO::TIMER& timer)
	{
		al_start_timer(timer.get());
	}

	export inline void stop_timer(ALLEGRO::TIMER& timer)
	{
		al_stop_timer(timer.get());
	}

	export inline void resume_timer(ALLEGRO::TIMER& timer)
	{
		al_resume_timer(timer.get());
	}

	export inline bool get_timer_started(const ALLEGRO::TIMER& timer)
	{
		return al_get_timer_started(timer.get());
	}

	export inline double get_timer_speed(const ALLEGRO::TIMER& timer)
	{
		return al_get_timer_speed(timer.get());
	}

	export inline void set_timer_speed(ALLEGRO::TIMER& timer, double speed_secs)
	{
		al_set_timer_speed(timer.get(), speed_secs);
	}

	export inline int64_t get_timer_count(const ALLEGRO::TIMER& timer)
	{
		return al_get_timer_count(timer.get());
	}

	export inline void set_timer_count(ALLEGRO::TIMER& timer, int64_t count)
	{
		al_set_timer_count(timer.get(), count);
	}

	export inline void add_timer_count(ALLEGRO::TIMER& timer, int64_t diff)
	{
		al_add_timer_count(timer.get(), diff);
	}

	export inline ALLEGRO::EVENT_SOURCE get_timer_event_source(ALLEGRO::TIMER& timer)
	{
		return ALLEGRO::EVENT_SOURCE(al_get_timer_event_source(timer.get()), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}
}
