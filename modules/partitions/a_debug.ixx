export module allegro:debug;

import std;
import <allegro5/debug.h>;
import <cstdarg>;
import <cstdio>;
import :base;

namespace al
{
	export inline auto _trace_prefix(const char* channel, int32_t level, const char* file, int32_t line, const char* function) -> bool
	{
		return _al_trace_prefix(channel, level, file, line, function);
	}

	export inline auto _trace_suffix(const char* format, va_list vargs) -> void
	{
		int32_t length{ 0 };
		std::shared_ptr<char[]> buffer{};

		length = 1 + _vscprintf(format, vargs);
		buffer = std::make_shared<char[]>(length);

		if (buffer)
		{
			vsprintf_s(buffer.get(), length, format, vargs);

			_al_trace_suffix("%s", buffer);

			buffer.reset();
		}
	}

	export inline auto _trace_suffix_args(const char* format, ...) -> void
	{
		va_list args{};

		va_start(args, format);

		_trace_suffix(format, args);

		va_end(args);
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
