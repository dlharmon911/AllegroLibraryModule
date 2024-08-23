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
    export int32_t get_platform_endianness()
    {
        return
#ifdef ALLEGRO_LITTLE_ENDIAN
            ALLEGRO::LITTLE_ENDIAN;
#endif
        ALLEGRO::BIG_ENDIAN;
    }

    export inline int32_t get_platform_type()
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
        export inline HWND get_window_handle(ALLEGRO::DISPLAY& display)
        {
            return al_get_win_window_handle(display.get());
        }

        export inline bool add_window_callback(ALLEGRO::DISPLAY& display, bool (*callback)(ALLEGRO::DISPLAY_DATA* display, UINT message, WPARAM wparam, LPARAM lparam, LRESULT* result, void* userdata), void* userdata)
        {
            return al_win_add_window_callback(display.get(), callback, userdata);
        }

        export inline bool remove_window_callback(ALLEGRO::DISPLAY& display, bool (*callback)(ALLEGRO::DISPLAY_DATA* display, UINT message, WPARAM wparam, LPARAM lparam, LRESULT* result, void* userdata), void* userdata)
        {
            return al_win_remove_window_callback(display.get(), callback, userdata);
        }
    }
#endif //!ALLEGRO_WINDOWS


#ifdef ALLEGRO_ANDROID
    namespace android
    {
        export inline void set_apk_file_interface()
        {
            al_android_set_apk_file_interface();
        }
        
        export inline char* get_os_version()
        {
            return char*(al_android_get_os_version());
        }
        
        export inline void set_apk_fs_interface()
        {
            al_android_set_apk_fs_interface();
        }

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
        export inline JNIEnv* get_jni_env()
        {
            return al_android_get_jni_env();
        }

        export inline jobject get_activity()
        {
            return al_android_get_activity();
        }
#endif

        /* XXX decide if this should be public */
        export inline void _set_capture_volume_keys(ALLEGRO::DISPLAY& display, bool onoff)
        {
            _al_android_set_capture_volume_keys(display.get(), onoff);
        }
    }
#endif //!ALLEGRO_ANDROID
#ifdef ALLEGRO_IPHONE
    namespace iphone
    {
        export inline void set_statusbar_orientation(int orientation)
        {
            al_iphone_set_statusbar_orientation(orientation);
        }

        export inline double get_last_shake_time()
        {
            return al_iphone_get_last_shake_time();
        }
        
        export inline float get_battery_level()
        {
            return al_iphone_get_battery_level();
        }
    }
#endif //!ALLEGRO_IPHONE

#ifdef ALLEGRO_UNIX
    namespace x11
    {
        export inline XID get_window_id(ALLEGRO::DISPLAY& display)
        {
            return al_get_x_window_id(display.get());
        }

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
        export inline bool set_initial_icon(ALLEGRO::BITMAP& bitmap)
        {
            return al_x_set_initial_icon(bitmap.get());
        }
#endif
}
#endif //!ALLEGRO_UNIX

}
