export module allegro:tls;

import std;
import <allegro5/tls.h>;

namespace ALLEGRO
{
	export using STATE = ALLEGRO_STATE;

	export constexpr int32_t STATE_FLAG_NEW_DISPLAY_PARAMETERS{ ALLEGRO_STATE_NEW_DISPLAY_PARAMETERS };
	export constexpr int32_t STATE_FLAG_NEW_BITMAP_PARAMETERS{ ALLEGRO_STATE_NEW_BITMAP_PARAMETERS };
	export constexpr int32_t STATE_FLAG_DISPLAY{ ALLEGRO_STATE_DISPLAY };
	export constexpr int32_t STATE_FLAG_TARGET_BITMAP{ ALLEGRO_STATE_TARGET_BITMAP };
	export constexpr int32_t STATE_FLAG_BLENDER{ ALLEGRO_STATE_BLENDER };
	export constexpr int32_t STATE_FLAG_NEW_FILE_INTERFACE{ ALLEGRO_STATE_NEW_FILE_INTERFACE };
	export constexpr int32_t STATE_FLAG_TRANSFORM{ ALLEGRO_STATE_TRANSFORM };
	export constexpr int32_t STATE_FLAG_PROJECTION_TRANSFORM{ ALLEGRO_STATE_PROJECTION_TRANSFORM };
	export constexpr int32_t STATE_FLAG_BITMAP{ ALLEGRO_STATE_BITMAP };
	export constexpr int32_t STATE_FLAG_ALL{ ALLEGRO_STATE_ALL };
}

namespace al
{
	export inline auto store_state(ALLEGRO::STATE& state, int32_t flags) -> void
	{
		return al_store_state(&state, flags);
	}

	export inline auto restore_state(ALLEGRO::STATE& state) -> void
	{
		al_restore_state(&state);
	}
}
