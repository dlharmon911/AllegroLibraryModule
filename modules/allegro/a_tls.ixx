export module allegro:tls;

import <allegro5/tls.h>;

namespace ALLEGRO
{
    export using STATE = ALLEGRO_STATE;
    export using STATE_FLAGS = ALLEGRO_STATE_FLAGS;

    export  enum
    {
        STATE_NEW_DISPLAY_PARAMETERS = ALLEGRO_STATE_NEW_DISPLAY_PARAMETERS,
        STATE_NEW_BITMAP_PARAMETERS = ALLEGRO_STATE_NEW_BITMAP_PARAMETERS,
        STATE_DISPLAY = ALLEGRO_STATE_DISPLAY,
        STATE_TARGET_BITMAP = ALLEGRO_STATE_TARGET_BITMAP,
        STATE_BLENDER = ALLEGRO_STATE_BLENDER,
        STATE_NEW_FILE_INTERFACE = ALLEGRO_STATE_NEW_FILE_INTERFACE,
        STATE_TRANSFORM = ALLEGRO_STATE_TRANSFORM,
        STATE_PROJECTION_TRANSFORM = ALLEGRO_STATE_PROJECTION_TRANSFORM,
        STATE_BITMAP = ALLEGRO_STATE_BITMAP,
        STATE_ALL = ALLEGRO_STATE_ALL
    };
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


