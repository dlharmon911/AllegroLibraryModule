export module allegro:base;

import std;
import <allegro5/base.h>;
export import <cstdint>;

export using cptr_t = std::add_pointer_t<char>;
export using vptr_t = std::add_pointer_t<void>;

namespace ALLEGRO
{
	export constexpr uint8_t VERSION = ALLEGRO_VERSION;
	export constexpr uint8_t SUB_VERSION = ALLEGRO_SUB_VERSION;
	export constexpr uint8_t WIP_VERSION = ALLEGRO_WIP_VERSION;
	export constexpr uint8_t UNSTABLE_BIT = ALLEGRO_UNSTABLE_BIT;
	export constexpr uint8_t RELEASE_NUMBER = ALLEGRO_RELEASE_NUMBER;
	export const char* VERSION_STR = (const char*)ALLEGRO_VERSION_STR;
	export const char* DATE_STR = (const char*)ALLEGRO_DATE_STR;
	export constexpr int32_t DATE = ALLEGRO_DATE;
	export constexpr int32_t VERSION_INT = ALLEGRO_VERSION_INT;
	export constexpr int32_t FILE_EOF{ -1 };
}

namespace al
{
	export constexpr auto generate_id(uint32_t a, uint32_t b, uint32_t c, uint32_t d) -> uint32_t
	{
		return (((a) << 24) | ((b) << 16) | ((c) << 8) | (d));
	}

	export inline auto run_main(int32_t argc, char** argv, std::function<auto(int32_t, char**)->int32_t>& func_main) -> int32_t
	{
		return al_run_main(argc, argv, func_main.target<auto(int32_t, char**)->int32_t>());
	}
}
