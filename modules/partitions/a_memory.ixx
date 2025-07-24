export module allegro:memory;

import std;
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
		export template <typename T> auto deleter_empty(T* object) -> void {}

		export template <typename T> auto deleter_default(T* object) -> void
		{
			if (object)
			{
				delete object;
			}
		}

		export template <typename T> auto deleter_array(T* object) -> void
		{
			if (object)
			{
				delete[] object;
			}
		}
	}

	export inline auto set_memory_interface(ALLEGRO::MEMORY_INTERFACE& iface) -> void
	{
		al_set_memory_interface(&iface);
	}

	export inline auto malloc_with_context(size_t n, int32_t line, const char* file, const char* func) -> void*
	{
		return al_malloc_with_context(n, line, file, func);
	}

	export inline auto free_with_context(void* ptr, int32_t line, const char* file, const char* func) -> void
	{
		al_free_with_context(ptr, line, file, func);
	}

	export inline auto realloc_with_context(void* ptr, size_t n, int32_t line, const char* file, const char* func) -> void*
	{
		return al_realloc_with_context(ptr, n, line, file, func);
	}

	export inline auto calloc_with_context(size_t count, size_t n, int32_t line, const char* file, const char* func) -> void*
	{
		return al_calloc_with_context(count, n, line, file, func);
	}
}
