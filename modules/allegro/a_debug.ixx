export module allegro:debug;

import <allegro5/debug.h>;
import <cassert>;
import <map>;
import <string>;
import <memory>;
import <cstdarg>;

namespace al
{
	export inline bool _trace_prefix(const char* channel, int level, const char* file, int line, const char* function)
	{
		return _al_trace_prefix(channel, level, file, line, function);
	}

	export inline void _trace_suffix(const char* msg, ...)
	{
		va_list args;
		int len;
		char* buffer;

		va_start(args, msg);
		len = _vscprintf(msg, args) // _vscprintf doesn't count
			+ 1; // terminating '\0'
		buffer = (char*)malloc(len * sizeof(char));

		if (NULL != buffer)
		{
			vsprintf_s(buffer, len, msg, args);
			_al_trace_suffix("%s", msg);
			free(buffer);
		}
		va_end(args);
	}

	export inline void _user_assert_handler(const char* expr, const char* file, int line, const char* func)
	{
		_al_user_assert_handler(expr, file, line, func);
	}

	export inline void register_assert_handler(void (*handler)(char const* expr, char const* file, int32_t line, char const* func))
	{
		al_register_assert_handler(handler);
	}

	export inline void register_trace_handler(void (*handler)(char const*))
	{
		al_register_trace_handler(handler);
	}
}
