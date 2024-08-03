export module allegro:memory;

import <memory>;
import <allegro5/memory.h>;
import :base;

namespace ALLEGRO
{
	export using MEMORY_INTERFACE = ALLEGRO_MEMORY_INTERFACE;
}

namespace al
{
	namespace internal
	{
		export template <typename T>
			void deleter_empty(T* object) {}

		export template <typename T>
			void deleter_default(T* object)
		{
			if (object)
			{
				delete object;
			}
		}

		export template <typename T>
			void deleter_array(T* object)
		{
			if (object)
			{
				delete[] object;
			}
		}
	}

	export inline void set_memory_interface(ALLEGRO::MEMORY_INTERFACE& iface)
	{
		al_set_memory_interface(&iface);
	}

	export inline void* malloc_with_context(size_t n, int32_t line, const char* file, const char* func)
	{
		return al_malloc_with_context(n, line, file, func);
	}

	export inline void free_with_context(void* ptr, int32_t line, const char* file, const char* func)
	{
		al_free_with_context(ptr, line, file, func);
	}

	export inline void* realloc_with_context(void* ptr, size_t n, int32_t line, const char* file, const char* func)
	{
		return al_realloc_with_context(ptr, n, line, file, func);
	}

	export inline void* calloc_with_context(size_t count, size_t n, int32_t line, const char* file, const char* func)
	{
		return al_calloc_with_context(count, n, line, file, func);
	}
}
