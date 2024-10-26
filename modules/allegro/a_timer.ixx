export module allegro:timer;

import <memory>;
import <allegro5/timer.h>;
import :base;
import :events;
import :memory;

namespace ALLEGRO
{
	export using TIMER_DATA = ALLEGRO_TIMER;
	export using TIMER_DATA_PTR = std::add_pointer<TIMER_DATA>::type;
	export using TIMER = std::shared_ptr<TIMER_DATA>;
}

namespace al
{
	export inline auto usecs_to_secs(double x) -> double { return ((x) / 1000000.0); }
	export inline auto msecs_to_secs(double x) -> double { return ((x) / 1000.0); }
	export inline auto bps_to_secs(double x) -> double { return (1.0 / (x)); }
	export inline auto bpm_to_secs(double x) -> double { return (60.0 / (x)); }

	namespace internal
	{
		export inline auto destroy_timer(ALLEGRO::TIMER_DATA_PTR data) -> void
		{
			al_destroy_timer(data);
		}
	}

	export inline auto create_timer(double seconds) -> ALLEGRO::TIMER
	{
		return ALLEGRO::TIMER(::al_create_timer(seconds), internal::destroy_timer);
	}

	export inline auto start_timer(ALLEGRO::TIMER& timer) -> void
	{
		al_start_timer((ALLEGRO::TIMER_DATA_PTR)timer.get());
	}

	export inline auto stop_timer(ALLEGRO::TIMER& timer) -> void
	{
		al_stop_timer((ALLEGRO::TIMER_DATA_PTR)timer.get());
	}

	export inline auto resume_timer(ALLEGRO::TIMER& timer) -> void
	{
		al_resume_timer((ALLEGRO::TIMER_DATA_PTR)timer.get());
	}

	export inline auto get_timer_started(const ALLEGRO::TIMER& timer) -> bool
	{
		return al_get_timer_started((ALLEGRO::TIMER_DATA_PTR)timer.get());
	}

	export inline auto get_timer_speed(const ALLEGRO::TIMER& timer) -> double
	{
		return al_get_timer_speed((ALLEGRO::TIMER_DATA_PTR)timer.get());
	}

	export inline auto set_timer_speed(ALLEGRO::TIMER& timer, double speed_secs) -> void
	{
		al_set_timer_speed((ALLEGRO::TIMER_DATA_PTR)timer.get(), speed_secs);
	}

	export inline auto get_timer_count(const ALLEGRO::TIMER& timer) -> int64_t
	{
		return al_get_timer_count((ALLEGRO::TIMER_DATA_PTR)timer.get());
	}

	export inline auto set_timer_count(ALLEGRO::TIMER& timer, int64_t count) -> void
	{
		al_set_timer_count((ALLEGRO::TIMER_DATA_PTR)timer.get(), count);
	}

	export inline auto add_timer_count(ALLEGRO::TIMER& timer, int64_t diff) -> void
	{
		al_add_timer_count((ALLEGRO::TIMER_DATA_PTR)timer.get(), diff);
	}

	export inline auto get_timer_event_source(ALLEGRO::TIMER& timer) -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_timer_event_source((ALLEGRO::TIMER_DATA_PTR)timer.get()), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}
}
