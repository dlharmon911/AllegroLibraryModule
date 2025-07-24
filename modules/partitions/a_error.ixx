export module allegro:error;

import std;
import <cassert>;
import <allegro5/error.h>;
import :base;

namespace ALLEGRO
{
	inline auto do_assert(bool x) -> void
	{
#ifdef _MSC_VER
		__assume(x);
#else
		if (!x)
		{
			__builtin_unreachable();
		}
#endif
	}

	export inline auto ASSERT(bool x) -> void
	{
		do_assert(x);
	}

	export template<typename T> inline auto ASSERT(const std::shared_ptr<T>& x) -> void
	{
		do_assert(static_cast<bool>(x));
	}

	export inline auto ASSERT(const void* x) -> void
	{
		do_assert(static_cast<bool>(x));
	}
}

namespace al
{
	export inline auto get_errno() -> int32_t
	{
		return al_get_errno();
	}

	export inline auto set_errno(int32_t errnum) -> void
	{
		return al_set_errno(errnum);
	}
}
