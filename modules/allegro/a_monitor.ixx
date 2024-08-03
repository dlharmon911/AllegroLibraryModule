export module allegro:monitor;

import <allegro5/monitor.h>;

namespace ALLEGRO
{
	export using MONITOR_INFO = ALLEGRO_MONITOR_INFO;

	export inline constexpr int32_t DEFAULT_DISPLAY_ADAPTER = ALLEGRO_DEFAULT_DISPLAY_ADAPTER;
}

namespace al
{
	export inline int32_t get_num_video_adapters()
	{
		return al_get_num_video_adapters();
	}

	export inline bool get_monitor_info(int32_t adapter, ALLEGRO::MONITOR_INFO& info)
	{
		return al_get_monitor_info(adapter, &info);
	}

	export inline int32_t get_monitor_dpi(int32_t adapter)
	{
		return al_get_monitor_dpi(adapter);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline int32_t get_monitor_refresh_rate(int32_t adapter)
	{
		return al_get_monitor_refresh_rate(adapter);
	}
#endif
}
