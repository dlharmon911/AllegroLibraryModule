export module allegro:debug;

import std;
import <allegro5/debug.h>;
import :base;

namespace al
{
	export inline auto _trace_prefix(const char* channel, int32_t level, const char* file, int32_t line, const char* function) -> bool
	{
		return _al_trace_prefix(channel, level, file, line, function);
	}

	export template <typename... Args> inline auto _trace_suffix_args(const char* format, Args&&... args) -> void
	{
		auto buffer = internal::to_string(format, std::forward<Args>(args)...);
		_al_trace_suffix(buffer.c_str());
	}

	export inline auto _user_assert_handler(const char* expr, const char* file, int32_t line, const char* func) -> void
	{
		_al_user_assert_handler(expr, file, line, func);
	}

	export inline auto register_assert_handler(void (*handler)(const char* expr, const char* file, int32_t line, const char* func)) -> void
	{
		al_register_assert_handler((void (*)(const char*, const char*, int32_t, const char*))handler);
	}

	export inline auto register_trace_handler(void (*handler)(const char*)) -> void
	{
		al_register_trace_handler((void (*)(const char*))handler);
	}
}
