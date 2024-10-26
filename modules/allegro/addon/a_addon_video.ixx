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

		export inline auto shutdown()
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
	export using VIDEO_DATA_PTR = std::add_pointer<VIDEO_DATA>::type;
	export using VIDEO = std::shared_ptr<VIDEO_DATA>;
}

namespace al
{
	namespace internal
	{
		export inline auto destroy_video(ALLEGRO::VIDEO_DATA *video) -> void
		{
			al_close_video(video);
		}
	}

	export inline auto open_video(const char* filename) -> ALLEGRO::VIDEO
	{
		return ALLEGRO::VIDEO(al_open_video(filename), internal::destroy_video);
	}

	export inline auto start_video(ALLEGRO::VIDEO& video, ALLEGRO::MIXER& mixer) -> void
	{
		al_start_video((ALLEGRO::VIDEO_DATA*)video.get(), (ALLEGRO::MIXER_DATA*)mixer.get());
	}

	export inline auto start_video_with_voice(ALLEGRO::VIDEO& video, ALLEGRO::VOICE& voice) -> void
	{
		al_start_video_with_voice((ALLEGRO::VIDEO_DATA*)video.get(), (ALLEGRO::VOICE_DATA*)voice.get());
	}

	export inline auto get_video_event_source(ALLEGRO::VIDEO& video) -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_video_event_source((ALLEGRO::VIDEO_DATA*)video.get()), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}

	export inline auto set_video_playing(ALLEGRO::VIDEO& video, bool playing) -> void
	{
		al_set_video_playing((ALLEGRO::VIDEO_DATA*)video.get(), playing);
	}

	export inline auto is_video_playing(ALLEGRO::VIDEO& video) -> bool
	{
		return al_is_video_playing((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline auto get_video_audio_rate(ALLEGRO::VIDEO& video) -> double
	{
		return al_get_video_audio_rate((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline auto get_video_fps(ALLEGRO::VIDEO& video) -> double
	{
		return al_get_video_fps((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline auto get_video_scaled_width(ALLEGRO::VIDEO& video) -> float
	{
		return al_get_video_scaled_width((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline auto get_video_scaled_height(ALLEGRO::VIDEO& video) -> float
	{
		return al_get_video_scaled_height((ALLEGRO::VIDEO_DATA*)video.get());
	}

	export inline auto get_video_frame(ALLEGRO::VIDEO& video) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_get_video_frame((ALLEGRO::VIDEO_DATA*)video.get()), internal::deleter_empty<ALLEGRO::BITMAP_DATA>);
	}

	export inline auto get_video_position(ALLEGRO::VIDEO& video, ALLEGRO::VIDEO_POSITION_TYPE which) -> double
	{
		return al_get_video_position((ALLEGRO::VIDEO_DATA*)video.get(), which);
	}

	export inline auto seek_video(ALLEGRO::VIDEO& video, double pos_in_seconds) -> bool
	{
		return al_seek_video((ALLEGRO::VIDEO_DATA*)video.get(), pos_in_seconds);
	}

	export inline auto identify_video_f(ALLEGRO::FILE& fp) -> const char*
	{
		return al_identify_video_f((ALLEGRO::FILE_DATA_PTR)fp.get());
	}

	export inline auto identify_video(const char* filename) -> const char*
	{
		return al_identify_video(filename);
	}
}

