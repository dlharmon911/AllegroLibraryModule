module;

#include <allegro5/allegro5.h>
#include <allegro5/platform/alplatf.h>

#ifdef ALLEGRO_WINDOWS
#include <allegro5/allegro_windows.h>
#endif //!ALLEGRO_WINDOWS
#ifdef ALLEGRO_ANDROID
#include <allegro5/allegro_android.h>
#endif //!ALLEGRO_ANDROID
#ifdef ALLEGRO_IPHONE
#include <allegro5/allegro_iphone.h>
#endif //!ALLEGRO_IPHONE
#ifdef ALLEGRO_UNIX
#include <allegro5/allegro_x.h>
#endif //!ALLEGRO_UNIX

export module allegro:platform;

import <string>;
import :base;
import :bitmap;
import :display;

namespace ALLEGRO
{
    export enum
    {
        LITTLE_ENDIAN,
        BIG_ENDIAN
    };

    export enum
    {
        PLATFORM_WINDOWS,
        PLATFORM_ANDROID,
        PLATFORM_IPHONE,
        PLATFORM_X11
    };

#ifdef ALLEGRO_WINDOWS
    using WINDOW_CALLBACK_FUNCTION_PTR = bool (*)(ALLEGRO::DISPLAY_DATA_PTR display, UINT message, WPARAM wparam, LPARAM lparam, LRESULT* result, void* userdata);
#endif

#ifdef ALLEGRO_IPHONE
    enum 
    {
        IPHONE_STATUSBAR_ORIENTATION_PORTRAIT = ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_PORTRAIT,
        IPHONE_STATUSBAR_ORIENTATION_PORTRAIT_UPSIDE_DOWN = ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_PORTRAIT_UPSIDE_DOWN,
        IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_RIGHT = ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_RIGHT,
        IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_LEFT = ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_LEFT
    };
#endif //!ALLEGRO_IPHONE
}

namespace al
{
    export auto get_platform_endianness() -> int32_t
    {
        return
#ifdef ALLEGRO_LITTLE_ENDIAN
            ALLEGRO::LITTLE_ENDIAN;
#endif
        ALLEGRO::BIG_ENDIAN;
    }

    export inline auto get_platform_type() -> int32_t
    {
#ifdef ALLEGRO_WINDOWS
        return ALLEGRO::PLATFORM_WINDOWS;
#endif //!ALLEGRO_WINDOWS
#ifdef ALLEGRO_ANDROID
        return ALLEGRO::PLATFORM_ANDROID;
#endif //!ALLEGRO_ANDROID
#ifdef ALLEGRO_IPHONE
        return ALLEGRO::PLATFORM_IPHONE;
#endif //!ALLEGRO_IPHONE
#ifdef ALLEGRO_UNIX
        return ALLEGRO::PLATFORM_X11;
#endif //!ALLEGRO_UNIX
    }

#ifdef ALLEGRO_WINDOWS

    namespace windows
    {
        export inline auto get_window_handle(ALLEGRO::DISPLAY& display) -> HWND
        {
            return al_get_win_window_handle((ALLEGRO::DISPLAY_DATA_PTR)display.get());
        }

        export inline auto add_window_callback(ALLEGRO::DISPLAY& display, ALLEGRO::WINDOW_CALLBACK_FUNCTION_PTR callback, void* userdata) -> bool
        {
            return al_win_add_window_callback((ALLEGRO::DISPLAY_DATA_PTR)display.get(), callback, userdata);
        }

        export inline auto remove_window_callback(ALLEGRO::DISPLAY& display, ALLEGRO::WINDOW_CALLBACK_FUNCTION_PTR callback, void* userdata) -> bool
        {
            return al_win_remove_window_callback((ALLEGRO::DISPLAY_DATA_PTR)display.get(), callback, userdata);
        }
    }
#endif //!ALLEGRO_WINDOWS


#ifdef ALLEGRO_ANDROID
    namespace android
    {
        export inline auto set_apk_file_interface() -> void
        {
            al_android_set_apk_file_interface();
        }
        
        export inline auto get_os_version() -> const char*
        {
            return (const char*)al_android_get_os_version();
        }
        
        export inline auto set_apk_fs_interface() -> void
        {
            al_android_set_apk_fs_interface();
        }

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
        export inline auto get_jni_env() -> JNIEnv*
        {
            return al_android_get_jni_env();
        }

        export inline auto get_activity() -> jobject
        {
            return al_android_get_activity();
        }
#endif

        /* XXX decide if this should be public */
        export inline auto _set_capture_volume_keys(ALLEGRO::DISPLAY& display, bool onoff) -> void
        {
            _al_android_set_capture_volume_keys(display.get(), onoff);
        }
    }
#endif //!ALLEGRO_ANDROID
#ifdef ALLEGRO_IPHONE
    namespace iphone
    {
        export inline auto set_statusbar_orientation(int32_t orientation) -> void
        {
            al_iphone_set_statusbar_orientation(orientation);
        }

        export inline auto get_last_shake_time() -> double
        {
            return al_iphone_get_last_shake_time();
        }
        
        export inline auto get_battery_level() -> float
        {
            return al_iphone_get_battery_level();
        }
    }
#endif //!ALLEGRO_IPHONE

#ifdef ALLEGRO_UNIX
    namespace x11
    {
        export inline auto get_window_id(ALLEGRO::DISPLAY& display) -> XID
        {
            return al_get_x_window_id(display.get());
        }

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
        export inline auto set_initial_icon(ALLEGRO::BITMAP& bitmap) -> bool
        {
            return al_x_set_initial_icon((ALLEGRO::BITMAP_DATA_PTR)bitmap.get());
        }
#endif
}
#endif //!ALLEGRO_UNIX

}
