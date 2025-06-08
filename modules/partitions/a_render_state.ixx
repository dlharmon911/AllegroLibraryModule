export module allegro:render_state;

import <allegro5/render_state.h>;
import :base;

namespace ALLEGRO
{
	export using RENDER_STATE = typename ALLEGRO_RENDER_STATE;
	export using RENDER_FUNCTION = typename ALLEGRO_RENDER_FUNCTION;
	export using WRITE_MASK_FLAGS = typename ALLEGRO_WRITE_MASK_FLAGS;

	export constexpr int32_t RENDER_STATE_ALPHA_TEST{ ALLEGRO_ALPHA_TEST };
	export constexpr int32_t RENDER_STATE_WRITE_MASK{ ALLEGRO_WRITE_MASK };
	export constexpr int32_t RENDER_STATE_DEPTH_TEST{ ALLEGRO_DEPTH_TEST };
	export constexpr int32_t RENDER_STATE_DEPTH_FUNCTION{ ALLEGRO_DEPTH_FUNCTION };
	export constexpr int32_t RENDER_STATE_ALPHA_FUNCTION{ ALLEGRO_ALPHA_FUNCTION };
	export constexpr int32_t RENDER_STATE_ALPHA_TEST_VALUE{ ALLEGRO_ALPHA_TEST_VALUE };

	export constexpr int32_t RENDER_FUNCTION_NEVER{ ALLEGRO_RENDER_NEVER };
	export constexpr int32_t RENDER_FUNCTION_ALWAYS{ ALLEGRO_RENDER_ALWAYS };
	export constexpr int32_t RENDER_FUNCTION_LESS{ ALLEGRO_RENDER_LESS };
	export constexpr int32_t RENDER_FUNCTION_EQUAL{ ALLEGRO_RENDER_EQUAL };
	export constexpr int32_t RENDER_FUNCTION_LESS_EQUAL{ ALLEGRO_RENDER_LESS_EQUAL };
	export constexpr int32_t RENDER_FUNCTION_GREATER{ ALLEGRO_RENDER_GREATER };
	export constexpr int32_t RENDER_FUNCTION_NOT_EQUAL{ ALLEGRO_RENDER_NOT_EQUAL };
	export constexpr int32_t RENDER_FUNCTION_GREATER_EQUAL{ ALLEGRO_RENDER_GREATER_EQUAL };

	export constexpr int32_t RENDER_MASK_RED{ ALLEGRO_MASK_RED };
	export constexpr int32_t RENDER_MASK_GREEN{ ALLEGRO_MASK_GREEN };
	export constexpr int32_t RENDER_MASK_BLUE{ ALLEGRO_MASK_BLUE };
	export constexpr int32_t RENDER_MASK_ALPHA{ ALLEGRO_MASK_ALPHA };
	export constexpr int32_t RENDER_MASK_DEPTH{ ALLEGRO_MASK_DEPTH };
	export constexpr int32_t RENDER_MASK_RGB{ ALLEGRO_MASK_RGB };
	export constexpr int32_t RENDER_MASK_RGBA{ ALLEGRO_MASK_RGBA };
}

namespace al
{
	export inline auto set_render_state(const ALLEGRO::RENDER_STATE& state, int32_t value) -> void
	{
		al_set_render_state(state, value);
	}
}
