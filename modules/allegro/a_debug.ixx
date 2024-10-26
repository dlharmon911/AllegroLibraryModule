export module allegro:debug;

import <allegro5/debug.h>;
import <cassert>;
import <map>;
import <string>;
import <memory>;
import <cstdarg>;

import :base;

namespace al
{
	export inline auto _trace_prefix(const char* channel, int level, const char* file, int line, const char* function) -> bool
	{
		return _al_trace_prefix(channel, level, file, line, function);
	}

	export inline auto _trace_suffix(const char* msg, ...) -> void
	{
		va_list args{};
		int32_t len{ -1 };
		char* buffer{ nullptr };

		va_start(args, msg);
		len = _vscprintf(msg, args) + 1;
		
		buffer = (char*)malloc(len * sizeof(char));

		if (buffer)
		{
			vsprintf_s(buffer, len, msg, args);
			_al_trace_suffix("%s", msg);
			free(buffer);
		}
		va_end(args);
	}

	export inline auto _user_assert_handler(const char* expr, const char* file, int line, const char* func) -> void
	{
		_al_user_assert_handler(expr, file, line, func);
	}

	export inline auto register_assert_handler(void (*handler)(const char* expr, const char* file, int32_t line, const char* func)) -> void
	{
		al_register_assert_handler(handler);
	}

	export inline auto register_trace_handler(void (*handler)(const char*)) -> void
	{
		al_register_trace_handler(handler);
	}
}
