export module allegro:threads;

import <memory>;
import <allegro5/threads.h>;
import :base;
import :memory;
import :altime;

namespace ALLEGRO
{
	export using THREAD_DATA = ALLEGRO_THREAD;
	export using THREAD = std::shared_ptr<THREAD_DATA>;
	export using MUTEX_DATA = ALLEGRO_MUTEX;
	export using MUTEX = std::shared_ptr<MUTEX_DATA>;
	export using COND_DATA = ALLEGRO_COND;
	export using COND = std::shared_ptr<COND_DATA>;
}

namespace al
{
	namespace internal
	{
		export inline void destroy_thread(ALLEGRO::THREAD_DATA* data)
		{
			al_destroy_thread(data);
		}

		export inline void destroy_mutex(ALLEGRO::MUTEX_DATA* data)
		{
			al_destroy_mutex(data);
		}

		export inline void destroy_cond(ALLEGRO::COND_DATA* data)
		{
			al_destroy_cond(data);
		}
	}

	export inline ALLEGRO::THREAD create_thread(void* (*proc)(ALLEGRO::THREAD_DATA* thread, void* arg), void* arg)
	{
		return ALLEGRO::THREAD(al_create_thread(proc, arg), internal::destroy_thread);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline ALLEGRO::THREAD create_thread_with_stacksize(void* (*proc)(ALLEGRO::THREAD_DATA* thread, void* arg), void* arg, size_t stacksize)
	{
		return ALLEGRO::THREAD(al_create_thread_with_stacksize(proc, arg, stacksize), internal::destroy_thread);
	}
#endif

	export inline void start_thread(ALLEGRO::THREAD& outer)
	{
		al_start_thread((ALLEGRO::THREAD_DATA*)outer.get());
	}

	export inline void join_thread(ALLEGRO::THREAD& outer, void** ret_value)
	{
		return al_join_thread((ALLEGRO::THREAD_DATA*)outer.get(), ret_value);
	}

	export inline void set_thread_should_stop(ALLEGRO::THREAD& outer)
	{
		al_set_thread_should_stop((ALLEGRO::THREAD_DATA*)outer.get());
	}

	export inline bool get_thread_should_stop(ALLEGRO::THREAD& outer)
	{
		return al_get_thread_should_stop((ALLEGRO::THREAD_DATA*)outer.get());
	}

	export inline void run_detached_thread(void* (*proc)(void* arg), void* arg)
	{
		al_run_detached_thread(proc, arg);
	}

	export inline ALLEGRO::MUTEX create_mutex()
	{
		return ALLEGRO::MUTEX(al_create_mutex(), internal::destroy_mutex);
	}

	export inline ALLEGRO::MUTEX create_mutex_recursive()
	{
		return ALLEGRO::MUTEX(al_create_mutex_recursive(), internal::destroy_mutex);
	}

	export inline void lock_mutex(ALLEGRO::MUTEX& mutex)
	{
		al_lock_mutex((ALLEGRO::MUTEX_DATA*)mutex.get());
	}

	export inline void unlock_mutex(ALLEGRO::MUTEX& mutex)
	{
		al_unlock_mutex((ALLEGRO::MUTEX_DATA*)mutex.get());
	}

	export inline ALLEGRO::COND create_cond()
	{
		return ALLEGRO::COND(al_create_cond(), internal::destroy_cond);
	}

	export inline void wait_cond(ALLEGRO::COND& cond, ALLEGRO::MUTEX& mutex)
	{
		return al_wait_cond((ALLEGRO::COND_DATA*)cond.get(), (ALLEGRO::MUTEX_DATA*)mutex.get());
	}

	export inline int32_t wait_cond_until(ALLEGRO::COND& cond, ALLEGRO::MUTEX& mutex, const ALLEGRO::TIMEOUT& timeout)
	{
		return al_wait_cond_until((ALLEGRO::COND_DATA*)cond.get(), (ALLEGRO::MUTEX_DATA*)mutex.get(), &timeout);
	}

	export inline void broadcast_cond(ALLEGRO::COND& cond)
	{
		return al_broadcast_cond((ALLEGRO::COND_DATA*)cond.get());
	}

	export inline void signal_cond(ALLEGRO::COND& cond)
	{
		return al_signal_cond((ALLEGRO::COND_DATA*)cond.get());
	}
}
