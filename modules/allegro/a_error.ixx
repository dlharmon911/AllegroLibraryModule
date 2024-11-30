export module allegro:error;

import <cassert>;
import <memory>;
import <allegro5/error.h>;
import :base;

namespace ALLEGRO
{
	export template<typename T> inline auto ASSERT(const std::shared_ptr<T>& x) -> void
	{
		assert((bool)x);
	}

	export inline auto ASSERT(const void* x) -> void
	{
		assert(x);
	}

	export inline auto ASSERT(bool x) -> void
	{
		assert(x);
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