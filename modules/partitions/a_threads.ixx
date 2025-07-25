export module allegro:threads;

import std;
import <allegro5/threads.h>;
import :base;
import :memory;
import :altime;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using THREAD_DATA = typename ALLEGRO_THREAD;
		export using THREAD_DATA_PTR = std::add_pointer<THREAD_DATA>::type;
		export using MUTEX_DATA = typename ALLEGRO_MUTEX;
		export using MUTEX_DATA_PTR = std::add_pointer<MUTEX_DATA>::type;
		export using COND_DATA = typename ALLEGRO_COND;
		export using COND_DATA_PTR = std::add_pointer<COND_DATA>::type;
	}

	export using THREAD = typename std::shared_ptr<INTERNAL::THREAD_DATA>;
	export using MUTEX = typename std::shared_ptr<INTERNAL::MUTEX_DATA>;
	export using COND = typename std::shared_ptr<INTERNAL::COND_DATA>;
}

namespace al
{
	namespace internal
	{
		export inline auto destroy_thread(ALLEGRO::INTERNAL::THREAD_DATA_PTR data) -> void
		{
			al_destroy_thread(data);
		}

		export inline auto destroy_mutex(ALLEGRO::INTERNAL::MUTEX_DATA_PTR data) -> void
		{
			al_destroy_mutex(data);
		}

		export inline auto destroy_cond(ALLEGRO::INTERNAL::COND_DATA_PTR data) -> void
		{
			al_destroy_cond(data);
		}
	}

	export inline auto create_thread(void* (*proc)(ALLEGRO::INTERNAL::THREAD_DATA_PTR thread, void* arg), void* arg) -> ALLEGRO::THREAD
	{
		return ALLEGRO::THREAD(al_create_thread(proc, arg), internal::destroy_thread);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto create_thread_with_stacksize(void* (*proc)(ALLEGRO::THREAD_DATA_PTR thread, void* arg), void* arg, size_t stacksize) -> ALLEGRO::THREAD
	{
		return ALLEGRO::THREAD(al_create_thread_with_stacksize(proc, arg, stacksize), internal::destroy_thread);
	}
#endif

	export inline auto start_thread(ALLEGRO::THREAD& outer) -> void
	{
		al_start_thread(static_cast<ALLEGRO::INTERNAL::THREAD_DATA_PTR>(outer.get()));
	}

	export inline auto join_thread(ALLEGRO::THREAD& outer, void** ret_value) -> void
	{
		return al_join_thread(static_cast<ALLEGRO::INTERNAL::THREAD_DATA_PTR>(outer.get()), ret_value);
	}

	export inline auto set_thread_should_stop(ALLEGRO::THREAD& outer) -> void
	{
		al_set_thread_should_stop(static_cast<ALLEGRO::INTERNAL::THREAD_DATA_PTR>(outer.get()));
	}

	export inline auto get_thread_should_stop(ALLEGRO::THREAD& outer) -> bool
	{
		return al_get_thread_should_stop(static_cast<ALLEGRO::INTERNAL::THREAD_DATA_PTR>(outer.get()));
	}

	export inline auto run_detached_thread(void* (*proc)(void* arg), void* arg) -> void
	{
		al_run_detached_thread(proc, arg);
	}

	export inline auto create_mutex() -> ALLEGRO::MUTEX
	{
		return ALLEGRO::MUTEX(al_create_mutex(), internal::destroy_mutex);
	}

	export inline auto create_mutex_recursive() -> ALLEGRO::MUTEX
	{
		return ALLEGRO::MUTEX(al_create_mutex_recursive(), internal::destroy_mutex);
	}

	export inline auto lock_mutex(ALLEGRO::MUTEX& mutex) -> void
	{
		al_lock_mutex(static_cast<ALLEGRO::INTERNAL::MUTEX_DATA_PTR>(mutex.get()));
	}

	export inline auto unlock_mutex(ALLEGRO::MUTEX& mutex) -> void
	{
		al_unlock_mutex(static_cast<ALLEGRO::INTERNAL::MUTEX_DATA_PTR>(mutex.get()));
	}

	export inline auto create_cond() -> ALLEGRO::COND
	{
		return ALLEGRO::COND(al_create_cond(), internal::destroy_cond);
	}

	export inline auto wait_cond(ALLEGRO::COND& cond, ALLEGRO::MUTEX& mutex) -> void
	{
		return al_wait_cond(static_cast<ALLEGRO::INTERNAL::COND_DATA_PTR>(cond.get()), static_cast<ALLEGRO::INTERNAL::MUTEX_DATA_PTR>(mutex.get()));
	}

	export inline auto wait_cond_until(ALLEGRO::COND& cond, ALLEGRO::MUTEX& mutex, const ALLEGRO::TIMEOUT& timeout) -> int32_t
	{
		return al_wait_cond_until(static_cast<ALLEGRO::INTERNAL::COND_DATA_PTR>(cond.get()), static_cast<ALLEGRO::INTERNAL::MUTEX_DATA_PTR>(mutex.get()), &timeout);
	}

	export inline auto broadcast_cond(ALLEGRO::COND& cond) -> void
	{
		return al_broadcast_cond(static_cast<ALLEGRO::INTERNAL::COND_DATA_PTR>(cond.get()));
	}

	export inline auto signal_cond(ALLEGRO::COND& cond) -> void
	{
		return al_signal_cond(static_cast<ALLEGRO::INTERNAL::COND_DATA_PTR>(cond.get()));
	}
}
