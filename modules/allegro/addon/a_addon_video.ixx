export module allegro.video_addon;

import <string>;
import <cstdint>;
import <memory>;
import allegro;
import allegro.audio_addon;
import <allegro5/allegro_video.h>;

namespace al
{
	namespace video_addon
	{
		export inline bool init()
		{
			return al_init_video_addon();
		}

		export inline bool is_initialized()
		{
			return al_is_video_addon_initialized();
		}

		export inline void shutdown()
		{
			al_shutdown_video_addon();
		}

		export inline uint32_t get_version()
		{
			return al_get_allegro_video_version();
		}
	}
}

namespace ALLEGRO
{
	export enum
	{
		EVENT_TYPE_VIDEO_FRAME_SHOW = ALLEGRO_EVENT_VIDEO_FRAME_SHOW,
		EVENT_TYPE_VIDEO_FINISHED = ALLEGRO_EVENT_VIDEO_FINISHED
	};

	export using VIDEO_POSITION_TYPE = ALLEGRO_VIDEO_POSITION_TYPE;
	export enum
	{
		VIDEO_POSITION_ACTUAL = ALLEGRO_VIDEO_POSITION_ACTUAL,
		VIDEO_POSITION_VIDEO_DECODE = ALLEGRO_VIDEO_POSITION_VIDEO_DECODE,
		VIDEO_POSITION_AUDIO_DECODE = ALLEGRO_VIDEO_POSITION_AUDIO_DECODE
	};


	export using VIDEO_DATA = ALLEGRO_VIDEO;
	export using VIDEO = ALLEGRO::OBJECT_TYPE;
}

namespace al
{
	namespace internal
	{
		export inline void destroy_video(ALLEGRO::VIDEO_DATA *video)
		{
			al_close_video(video);
		}
	}

	export inline ALLEGRO::VIDEO open_video(const char* filename)
	{
		return ALLEGRO::VIDEO(al_open_video(filename), internal::destroy_video);
	}

	export inline void start_video(ALLEGRO::VIDEO& video, ALLEGRO::MIXER& mixer)
	{
		al_start_video((ALLEGRO::VIDEO_DATA*)video.get(), (ALLEGRO::MIXER_DATA*)mixer.get());
	}

	export inline void start_video_with_voice(ALLEGRO::VIDEO& video, ALLEGRO::VOICE& voice)
	{
		al_start_video_with_voice((ALLEGRO::VIDEO_DATA*)video.get(), (ALLEGRO::VOICE_DATA*)voice.get());
	}

	export inline ALLEGRO::EVENT_SOURCE get_video_event_source(ALLEGRO::VIDEO& video)
	{
		return ALLEGRO::EVENT_SOURCE(al_get_video_event_source((ALLEGRO::VIDEO_DATA*)video.get()), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}

	export inline void set_video_playing(ALLEGRO::VIDEO& video, bool playing)
	{
		al_set_video_playing((ALLEGRO::VIDEO_DATA*)video.get(), playing);
	}

	export inline bool is_video_playing(ALLEGRO::VIDEO& video)
	{
		return al_is_video_playing((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline double get_video_audio_rate(ALLEGRO::VIDEO& video)
	{
		return al_get_video_audio_rate((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline double get_video_fps(ALLEGRO::VIDEO& video)
	{
		return al_get_video_fps((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline float get_video_scaled_width(ALLEGRO::VIDEO& video)
	{
		return al_get_video_scaled_width((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline float get_video_scaled_height(ALLEGRO::VIDEO& video)
	{
		return al_get_video_scaled_height((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline ALLEGRO::BITMAP get_video_frame(ALLEGRO::VIDEO& video)
	{
		return ALLEGRO::BITMAP(al_get_video_frame((ALLEGRO::VIDEO_DATA*)video.get()), internal::deleter_empty<ALLEGRO::BITMAP_DATA>);
	}

	export inline double get_video_position(ALLEGRO::VIDEO& video, ALLEGRO::VIDEO_POSITION_TYPE which)
	{
		return al_get_video_position((ALLEGRO::VIDEO_DATA*)video.get(), which);
	}

	export inline bool seek_video(ALLEGRO::VIDEO& video, double pos_in_seconds)
	{
		return al_seek_video((ALLEGRO::VIDEO_DATA*)video.get(), pos_in_seconds);
	}

	export inline const char* identify_video_f(ALLEGRO::FILE& fp)
	{
		return al_identify_video_f((ALLEGRO::FILE_DATA*)fp.get());
	}

	export inline const char* identify_video(const char* filename)
	{
		return al_identify_video(filename);
	}
}

