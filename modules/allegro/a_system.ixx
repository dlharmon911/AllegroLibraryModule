export module allegro:system;

import <memory>;
import <string>;
import <functional>;
import <allegro5/system.h>;
import :base;
import :config;
import :path;
import :memory;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using SYSTEM_DATA = typename ALLEGRO_SYSTEM;
		export using SYSTEM_DATA_PTR = std::add_pointer<SYSTEM_DATA>::type;
	}

	export using SYSTEM = typename std::shared_ptr<INTERNAL::SYSTEM_DATA>;

	export constexpr int32_t SYSTEM_ID_UNKNOWN{ ALLEGRO_SYSTEM_ID_UNKNOWN };
	export constexpr int32_t SYSTEM_ID_XGLX{ ALLEGRO_SYSTEM_ID_XGLX };
	export constexpr int32_t SYSTEM_ID_WINDOWS{ ALLEGRO_SYSTEM_ID_WINDOWS };
	export constexpr int32_t SYSTEM_ID_MACOSX{ ALLEGRO_SYSTEM_ID_MACOSX };
	export constexpr int32_t SYSTEM_ID_ANDROID{ ALLEGRO_SYSTEM_ID_ANDROID };
	export constexpr int32_t SYSTEM_ID_IPHONE{ ALLEGRO_SYSTEM_ID_IPHONE };
	export constexpr int32_t SYSTEM_ID_GP2XWIZ{ ALLEGRO_SYSTEM_ID_GP2XWIZ };
	export constexpr int32_t SYSTEM_ID_RASPBERRYPI{ ALLEGRO_SYSTEM_ID_RASPBERRYPI };
	export constexpr int32_t SYSTEM_ID_SDL{ ALLEGRO_SYSTEM_ID_SDL };

	export constexpr int32_t RESOURCES_PATH{ ALLEGRO_RESOURCES_PATH };
	export constexpr int32_t TEMP_PATH{ ALLEGRO_TEMP_PATH };
	export constexpr int32_t USER_DATA_PATH{ ALLEGRO_USER_DATA_PATH };
	export constexpr int32_t USER_HOME_PATH{ ALLEGRO_USER_HOME_PATH };
	export constexpr int32_t USER_SETTINGS_PATH{ ALLEGRO_USER_SETTINGS_PATH };
	export constexpr int32_t USER_DOCUMENTS_PATH{ ALLEGRO_USER_DOCUMENTS_PATH };
	export constexpr int32_t EXENAME_PATH{ ALLEGRO_EXENAME_PATH };
	export constexpr int32_t LAST_PATH{ ALLEGRO_LAST_PATH };
}

namespace al
{
	export inline bool init()
	{
		return al_install_system(ALLEGRO_VERSION_INT, atexit);
	}

	export inline bool install_system(int32_t version, std::function<int32_t(void (*)(void))>& atexit_function)
	{
		return al_install_system(version, atexit_function.target<int32_t(void (*)(void))>());
	}

	export inline void uninstall_system()
	{
		al_uninstall_system();
	}

	export inline bool is_system_installed()
	{
		return al_is_system_installed();
	}

	export inline ALLEGRO::SYSTEM get_system_driver()
	{
		return ALLEGRO::SYSTEM(al_get_system_driver(), internal::deleter_empty<ALLEGRO::INTERNAL::SYSTEM_DATA>);
	}

	export inline ALLEGRO::CONFIG get_system_config()
	{
		return ALLEGRO::CONFIG(al_get_system_config(), internal::deleter_empty<ALLEGRO_CONFIG>);
	}

	export inline int32_t get_system_id()
	{
		return al_get_system_id();
	}

	export inline ALLEGRO::PATH get_standard_path(int32_t id)
	{
		return ALLEGRO::PATH(al_get_standard_path(id), internal::deleter_empty<ALLEGRO_PATH>);
	}

	export inline void set_exe_name(const char* path)
	{
		al_set_exe_name(path);
	}

	export inline void set_org_name(const char* org_name)
	{
		al_set_org_name(org_name);
	}

	export inline void set_app_name(const char* app_name)
	{
		al_set_app_name(app_name);
	}

	export inline const char* get_org_name()
	{
		return (const char*)al_get_org_name();
	}

	export inline const char* al_get_app_name()
	{
		return al_get_app_name();
	}

	export inline bool inhibit_screensaver(bool inhibit)
	{
		return al_inhibit_screensaver(inhibit);
	}
}
