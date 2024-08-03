export module allegro:debug;

import <allegro5/debug.h>;

namespace al
{
	export inline void register_assert_handler(void (*handler)(char const* expr, char const* file, int32_t line, char const* func))
	{
		al_register_assert_handler(handler);
	}

	export inline void register_trace_handler(void (*handler)(char const*))
	{
		al_register_trace_handler(handler);
	}
}
