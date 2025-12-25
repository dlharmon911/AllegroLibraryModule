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

#ifdef ALLEGRO_BIG_ENDIAN
#define IS_BIG_ENDIAN 1
#define IS_LITTLE_ENDIAN 0
#else
#define IS_BIG_ENDIAN ((int32_t)0)
#define IS_LITTLE_ENDIAN  ((int32_t)1)
#endif


export module allegro:platform;

import std;
import :base;
import :bitmap;
import :display;

namespace ALLEGRO
{
	export constexpr int32_t LITTLE_ENDIAN{ IS_LITTLE_ENDIAN };
	export constexpr int32_t BIG_ENDIAN{ IS_BIG_ENDIAN };

	export constexpr int32_t PLATFORM_WINDOWS{ 0 };
	export constexpr int32_t PLATFORM_ANDROID{ 1 };
	export constexpr int32_t PLATFORM_IPHONE{ 2 };
	export constexpr int32_t PLATFORM_X11{ 3 };

#ifdef ALLEGRO_WINDOWS
	// Define a user data type for callbacks (can be customized)
	struct WINDOWCALLBACKUSERDATA {};

	// Use std::function for the callback type
	using WINDOW_CALLBACK_FUNCTION = std::function<bool(const ALLEGRO::DISPLAY& display, UINT message, WPARAM wparam, LPARAM lparam, LRESULT* result, WINDOWCALLBACKUSERDATA* userdata)>;
#endif

#ifdef ALLEGRO_IPHONE
	export constexpr int32_t IPHONE_STATUSBAR_ORIENTATION_PORTRAIT{ ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_PORTRAIT };
	export constexpr int32_t IPHONE_STATUSBAR_ORIENTATION_PORTRAIT_UPSIDE_DOWN{ ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_PORTRAIT_UPSIDE_DOWN };
	export constexpr int32_t IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_RIGHT{ ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_RIGHT };
	export constexpr int32_t IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_LEFT{ ALLEGRO_IPHONE_STATUSBAR_ORIENTATION_LANDSCAPE_LEFT };
#endif //!ALLEGRO_IPHONE
}

namespace al
{
	export auto get_platform_endianness() -> int32_t
	{
#ifdef ALLEGRO_LITTLE_ENDIAN
		return ALLEGRO::LITTLE_ENDIAN;
#else
		return ALLEGRO::BIG_ENDIAN;
#endif
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
			return al_get_win_window_handle(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
		}

		// Template to allow custom user data types, defaulting to WindowCallbackUserData
		export template<typename UserDataT = ALLEGRO::WINDOWCALLBACKUSERDATA> inline auto add_window_callback(ALLEGRO::DISPLAY& display, const std::function<bool(ALLEGRO::INTERNAL::DISPLAY_DATA_PTR, UINT, WPARAM, LPARAM, LRESULT*, UserDataT*)>& callback, UserDataT* userdata) -> bool
		{
			// For legacy API, extract function pointer if possible
			using RawCallback = bool(*)(ALLEGRO::INTERNAL::DISPLAY_DATA_PTR, UINT, WPARAM, LPARAM, LRESULT*, void*);
			RawCallback raw_cb = callback.template target<RawCallback>() ? *callback.template target<RawCallback>() : nullptr;
			return al_win_add_window_callback(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), raw_cb, static_cast<void*>(userdata));
		}

		export template<typename UserDataT = ALLEGRO::WINDOWCALLBACKUSERDATA> inline auto remove_window_callback(ALLEGRO::DISPLAY& display, const std::function<bool(ALLEGRO::INTERNAL::DISPLAY_DATA_PTR, UINT, WPARAM, LPARAM, LRESULT*, UserDataT*)>& callback, UserDataT* userdata) -> bool
		{
			using RawCallback = bool(*)(ALLEGRO::INTERNAL::DISPLAY_DATA_PTR, UINT, WPARAM, LPARAM, LRESULT*, void*);
			RawCallback raw_cb = callback.template target<RawCallback>() ? *callback.template target<RawCallback>() : nullptr;
			return al_win_remove_window_callback(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()), raw_cb, static_cast<void*>(userdata));
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
			return al_android_get_os_version();
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
			return al_x_set_initial_icon(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
		}
#endif
	}
#endif //!ALLEGRO_UNIX
}
