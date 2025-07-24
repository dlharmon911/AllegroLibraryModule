export module allegro:array;

import std;
import <allegro5/cpu.h>;
import :base;

namespace ALLEGRO
{
	using ARRAY = struct ARRAY_TAG
	{
		size_t size{ 0 };
		void* data{ nullptr };
	};
}
