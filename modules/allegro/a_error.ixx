export module allegro:error;

import <cassert>;
import <memory>;
import <allegro5/error.h>;
import :base;

namespace ALLEGRO
{

	export template<typename T> inline void ASSERT(const std::shared_ptr<T>& x)
	{
		assert((bool)x);
	}

	export inline void ASSERT(const void* x)
	{
		assert(x);
	}

	export inline void ASSERT(bool x)
	{
		assert(x);
	}
}

namespace al
{
	export inline int32_t get_errno()
	{
		return al_get_errno();
	}

	export inline void set_errno(int32_t errnum)
	{
		return al_set_errno(errnum);
	}
}
