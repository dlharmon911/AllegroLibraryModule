export module allegro:monitor;

import std;
import <allegro5/monitor.h>;

namespace ALLEGRO
{
	export using MONITOR_INFO = ALLEGRO_MONITOR_INFO;

	export inline constexpr int32_t DEFAULT_DISPLAY_ADAPTER = ALLEGRO_DEFAULT_DISPLAY_ADAPTER;
}

namespace al
{
	export inline auto get_num_video_adapters() -> int32_t
	{
		return al_get_num_video_adapters();
	}

	export inline auto get_monitor_info(int32_t adapter, ALLEGRO::MONITOR_INFO& info) -> bool
	{
		return al_get_monitor_info(adapter, &info);
	}

	export inline auto get_monitor_dpi(int32_t adapter) -> int32_t
	{
		return al_get_monitor_dpi(adapter);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
	export inline auto get_monitor_refresh_rate(int32_t adapter) -> int32_t
	{
		return al_get_monitor_refresh_rate(adapter);
	}
#endif
}
