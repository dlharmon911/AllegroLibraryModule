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
	export inline auto _trace_prefix(const_cptr_t channel, int32_t level, const_cptr_t file, int32_t line, const_cptr_t function) -> bool
	{
		return _al_trace_prefix(channel, level, file, line, function);
	}

	export inline auto _trace_suffix(const_cptr_t msg, ...) -> void
	{
		va_list args{};
		int32_t len{ -1 };
		cptr_t buffer{ nullptr };

		va_start(args, msg);
		len = _vscprintf(msg, args) + 1;
		
		buffer = (cptr_t)malloc(len * sizeof(char));

		if (buffer)
		{
			vsprintf_s(buffer, len, msg, args);
			_al_trace_suffix("%s", msg);
			free(buffer);
		}
		va_end(args);
	}

	export inline auto _user_assert_handler(const_cptr_t expr, const_cptr_t file, int32_t line, const_cptr_t func) -> void
	{
		_al_user_assert_handler(expr, file, line, func);
	}

	export inline auto register_assert_handler(void (*handler)(const_cptr_t expr, const_cptr_t file, int32_t line, const_cptr_t func)) -> void
	{
		al_register_assert_handler((void (*)(const_cptr_t, const_cptr_t, int32_t, const_cptr_t))handler);
	}

	export inline auto register_trace_handler(void (*handler)(const_cptr_t)) -> void
	{
		al_register_trace_handler((void (*)(const_cptr_t))handler);
	}
}
