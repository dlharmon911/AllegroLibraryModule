export module allegro.audio_addon;

import <string>;
import <cstdint>;
import <memory>;
import allegro;
import <allegro5/allegro_audio.h>;

namespace ALLEGRO
{
	export enum
	{
		EVENT_AUDIO_STREAM_FRAGMENT = ALLEGRO_EVENT_AUDIO_STREAM_FRAGMENT,
		EVENT_AUDIO_STREAM_FINISHED = ALLEGRO_EVENT_AUDIO_STREAM_FINISHED,
#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
		EVENT_AUDIO_RECORDER_FRAGMENT = ALLEGRO_EVENT_AUDIO_RECORDER_FRAGMENT,
#endif
	};

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
	export using AUDIO_RECORDER_EVENT = ALLEGRO_AUDIO_RECORDER_EVENT;
#endif

	export enum
	{
		AUDIO_DEPTH_INT8 = ALLEGRO_AUDIO_DEPTH_INT8,
		AUDIO_DEPTH_INT16 = ALLEGRO_AUDIO_DEPTH_INT16,
		AUDIO_DEPTH_INT24 = ALLEGRO_AUDIO_DEPTH_INT24,
		AUDIO_DEPTH_FLOAT32 = ALLEGRO_AUDIO_DEPTH_FLOAT32,
		AUDIO_DEPTH_UNSIGNED = ALLEGRO_AUDIO_DEPTH_UNSIGNED,
		AUDIO_DEPTH_UINT8 = ALLEGRO_AUDIO_DEPTH_UINT8,
		AUDIO_DEPTH_UINT16 = ALLEGRO_AUDIO_DEPTH_UINT16,
		AUDIO_DEPTH_UINT24 = ALLEGRO_AUDIO_DEPTH_UINT24
	};

	export enum
	{
		CHANNEL_CONF_1 = ALLEGRO_CHANNEL_CONF_1,
		CHANNEL_CONF_2 = ALLEGRO_CHANNEL_CONF_2,
		CHANNEL_CONF_3 = ALLEGRO_CHANNEL_CONF_3,
		CHANNEL_CONF_4 = ALLEGRO_CHANNEL_CONF_4,
		CHANNEL_CONF_5_1 = ALLEGRO_CHANNEL_CONF_5_1,
		CHANNEL_CONF_6_1 = ALLEGRO_CHANNEL_CONF_6_1,
		CHANNEL_CONF_7_1 = ALLEGRO_CHANNEL_CONF_7_1,
		MAX_CHANNELS = ALLEGRO_MAX_CHANNELS
	};

	export enum
	{
		PLAYMODE_ONCE = ALLEGRO_PLAYMODE_ONCE,
		PLAYMODE_LOOP = ALLEGRO_PLAYMODE_LOOP,
		PLAYMODE_BIDIR = ALLEGRO_PLAYMODE_BIDIR,
		PLAYMODE_LOOP_ONCE = ALLEGRO_PLAYMODE_LOOP_ONCE
	};

	export enum
	{
		MIXER_QUALITY_POINT = ALLEGRO_MIXER_QUALITY_POINT,
		MIXER_QUALITY_LINEAR = ALLEGRO_MIXER_QUALITY_LINEAR,
		MIXER_QUALITY_CUBIC = ALLEGRO_MIXER_QUALITY_CUBIC
	};

	export inline constexpr float AUDIO_PAN_NONE = ALLEGRO_AUDIO_PAN_NONE;

	export using SAMPLE_ID = ALLEGRO_SAMPLE_ID;

	export using SAMPLE_DATA = ALLEGRO_SAMPLE;
	export using SAMPLE_DATA_PTR = std::add_pointer<SAMPLE_DATA>::type;
	export using SAMPLE = std::shared_ptr<SAMPLE_DATA>;

	export using SAMPLE_INSTANCE_DATA = ALLEGRO_SAMPLE_INSTANCE;
	export using SAMPLE_INSTANCE_DATA_PTR = std::add_pointer<SAMPLE_INSTANCE_DATA>::type;
	export using SAMPLE_INSTANCE = std::shared_ptr<SAMPLE_INSTANCE_DATA >;

	export using AUDIO_STREAM_DATA = ALLEGRO_AUDIO_STREAM;
	export using AUDIO_STREAM_DATA_PTR = std::add_pointer<AUDIO_STREAM_DATA>::type;
	export using AUDIO_STREAM = std::shared_ptr<AUDIO_STREAM_DATA>;

	export using MIXER_DATA = ALLEGRO_MIXER;
	export using MIXER_DATA_PTR = std::add_pointer<MIXER_DATA>::type;
	export using MIXER = std::shared_ptr<MIXER_DATA>;

	export using VOICE_DATA = ALLEGRO_VOICE;
	export using VOICE_DATA_PTR = std::add_pointer<VOICE_DATA>::type;
	export using VOICE = std::shared_ptr<VOICE_DATA>;

	export using AUDIO_DEVICE_DATA = const ALLEGRO_AUDIO_DEVICE;
	export using AUDIO_DEVICE_DATA_PTR = std::add_pointer<AUDIO_DEVICE_DATA>::type;
	export using AUDIO_DEVICE = std::shared_ptr<const AUDIO_DEVICE_DATA>;

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
	export using AUDIO_RECORDER_DATA = ALLEGRO_AUDIO_RECORDER;
	export using AUDIO_RECORDER = std::shared_ptr<AUDIO_RECORDER_DATA>;
#endif

	export using AUDIO_DEPTH = ALLEGRO_AUDIO_DEPTH;
	export using CHANNEL_CONF = ALLEGRO_CHANNEL_CONF;
	export using PLAYMODE = ALLEGRO_PLAYMODE;
	export using MIXER_QUALITY = ALLEGRO_MIXER_QUALITY;
}

namespace al
{
	namespace audio_addon
	{
		export inline auto init() -> bool
		{
			return al_install_audio();
		}

		export inline auto shutdown() -> void
		{
			return al_uninstall_audio();
		}

		export inline auto is_installed() -> bool
		{
			return al_is_audio_installed();
		}

		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_audio_version();
		}
	}

	namespace internal
	{
		export inline auto destroy_sample(ALLEGRO::SAMPLE_DATA_PTR data) -> void
		{
			al_destroy_sample(data);
		}

		export inline auto destroy_sample_instance(ALLEGRO::SAMPLE_INSTANCE_DATA_PTR data) -> void
		{
			al_destroy_sample_instance(data);
		}

		export inline auto destroy_audio_stream(ALLEGRO::AUDIO_STREAM_DATA_PTR data) -> void
		{
			al_destroy_audio_stream(data);
		}

		export inline auto destroy_mixer(ALLEGRO::MIXER_DATA_PTR data) -> void
		{
			al_destroy_mixer(data);
		}

		export inline auto destroy_voice(ALLEGRO::VOICE_DATA_PTR data) -> void
		{
			al_destroy_voice(data);
		}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
		export inline auto destroy_audio_recorder(ALLEGRO::AUDIO_RECORDER_DATA_PTR data)
		{
			al_destroy_audio_recorder(data);
		}
#endif
	}

	export inline auto create_sample(void* buffer, uint32_t samples, uint32_t freq, ALLEGRO::AUDIO_DEPTH depth, ALLEGRO::CHANNEL_CONF chan_conf, bool free_buf) -> ALLEGRO::SAMPLE
	{
		return ALLEGRO::SAMPLE(::al_create_sample(buffer, samples, freq, depth, chan_conf, free_buf), internal::destroy_sample);
	}

	export inline auto create_sample_instance(ALLEGRO::SAMPLE& sample) -> ALLEGRO::SAMPLE_INSTANCE
	{
		return ALLEGRO::SAMPLE_INSTANCE(::al_create_sample_instance((ALLEGRO::SAMPLE_DATA_PTR)sample.get()), internal::destroy_sample_instance);
	}

	export inline auto get_sample_frequency(const ALLEGRO::SAMPLE& sample) -> uint32_t
	{
		return al_get_sample_frequency((ALLEGRO::SAMPLE_DATA_PTR)sample.get());
	}

	export inline auto get_sample_length(const ALLEGRO::SAMPLE& sample) -> uint32_t
	{
		return al_get_sample_length((ALLEGRO::SAMPLE_DATA_PTR)sample.get());
	}

	export inline auto get_sample_depth(const ALLEGRO::SAMPLE& sample) -> ALLEGRO::AUDIO_DEPTH
	{
		return al_get_sample_depth((ALLEGRO::SAMPLE_DATA_PTR)sample.get());
	}

	export inline auto get_sample_channels(const ALLEGRO::SAMPLE& sample) -> ALLEGRO::CHANNEL_CONF
	{
		return al_get_sample_channels((ALLEGRO::SAMPLE_DATA_PTR)sample.get());
	}

	export inline auto get_sample_data(const ALLEGRO::SAMPLE& sample) -> void*
	{
		return al_get_sample_data((ALLEGRO::SAMPLE_DATA_PTR)sample.get());
	}
	export inline auto get_sample_instance_frequency(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> uint32_t
	{
		return al_get_sample_instance_frequency((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_length(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> uint32_t
	{
		return al_get_sample_instance_length((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_position(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> uint32_t
	{
		return al_get_sample_instance_position((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_speed(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> float
	{
		return al_get_sample_instance_speed((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_gain(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> float
	{
		return al_get_sample_instance_gain((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_pan(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> float
	{
		return al_get_sample_instance_pan((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_time(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> float
	{
		return al_get_sample_instance_time((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_depth(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> ALLEGRO::AUDIO_DEPTH
	{
		return al_get_sample_instance_depth((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_channels(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> ALLEGRO::CHANNEL_CONF
	{
		return al_get_sample_instance_channels((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_playmode(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> ALLEGRO::PLAYMODE
	{
		return al_get_sample_instance_playmode((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_playing(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> bool
	{
		return al_get_sample_instance_playing((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto get_sample_instance_attached(const ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> bool
	{
		return al_get_sample_instance_attached((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto set_sample_instance_position(ALLEGRO::SAMPLE_INSTANCE& sample_instance, uint32_t value) -> bool
	{
		return al_set_sample_instance_position((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), value);
	}

	export inline auto set_sample_instance_length(ALLEGRO::SAMPLE_INSTANCE& sample_instance, uint32_t value) -> bool
	{
		return al_set_sample_instance_length((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), value);
	}

	export inline auto set_sample_instance_speed(ALLEGRO::SAMPLE_INSTANCE& sample_instance, float value) -> bool
	{
		return al_set_sample_instance_speed((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), value);
	}

	export inline auto set_sample_instance_gain(ALLEGRO::SAMPLE_INSTANCE& sample_instance, float value) -> bool
	{
		return al_set_sample_instance_gain((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), value);
	}

	export inline auto set_sample_instance_pan(ALLEGRO::SAMPLE_INSTANCE& sample_instance, float value) -> bool
	{
		return al_set_sample_instance_pan((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), value);
	}

	export inline auto set_sample_instance_playmode(ALLEGRO::SAMPLE_INSTANCE& sample_instance, ALLEGRO::PLAYMODE value) -> bool
	{
		return al_set_sample_instance_playmode((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), value);
	}

	export inline auto set_sample_instance_playing(ALLEGRO::SAMPLE_INSTANCE& sample_instance, bool value) -> bool
	{
		return al_set_sample_instance_playing((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), value);
	}

	export inline auto detach_sample_instance(ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> bool
	{
		return al_detach_sample_instance((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto set_sample(ALLEGRO::SAMPLE_INSTANCE& sample_instance, ALLEGRO::SAMPLE& data) -> bool
	{
		return al_set_sample((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), (ALLEGRO::SAMPLE_DATA_PTR)data.get());
	}

	export inline auto get_sample(ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> ALLEGRO::SAMPLE
	{
		return ALLEGRO::SAMPLE(::al_get_sample((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get()), internal::deleter_empty<ALLEGRO::SAMPLE_DATA>);
	}

	export inline auto play_sample_instance(ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> bool
	{
		return al_play_sample_instance((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

	export inline auto stop_sample_instance(ALLEGRO::SAMPLE_INSTANCE& sample_instance) -> bool
	{
		return al_stop_sample_instance((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get());
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
	export inline auto set_sample_instance_channel_matrix(ALLEGRO::SAMPLE_INSTANCE& sample_instance, const float* matrix)
	{
		return al_set_sample_instance_channel_matrix(sample_instance.get(), matrix);
	}
#endif

	export inline auto create_audio_stream(size_t buffer_count, uint32_t samples, uint32_t freq, ALLEGRO::AUDIO_DEPTH depth, ALLEGRO::CHANNEL_CONF chan_conf) -> ALLEGRO::AUDIO_STREAM
	{
		return ALLEGRO::AUDIO_STREAM(al_create_audio_stream(buffer_count, samples, freq, depth, chan_conf), internal::destroy_audio_stream);
	}

	export inline auto drain_audio_stream(ALLEGRO::AUDIO_STREAM& stream)
	{
		al_drain_audio_stream((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_frequency(const ALLEGRO::AUDIO_STREAM& stream) -> uint32_t
	{
		return al_get_audio_stream_frequency((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_length(const ALLEGRO::AUDIO_STREAM& stream) -> uint32_t
	{
		return al_get_audio_stream_length((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_fragments(const ALLEGRO::AUDIO_STREAM& stream) -> uint32_t
	{
		return al_get_audio_stream_fragments((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_available_audio_stream_fragments(const ALLEGRO::AUDIO_STREAM& stream) -> uint32_t
	{
		return al_get_available_audio_stream_fragments((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_speed(const ALLEGRO::AUDIO_STREAM& stream)
	{
		return al_get_audio_stream_speed((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_gain(const ALLEGRO::AUDIO_STREAM& stream)
	{
		return al_get_audio_stream_gain((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_pan(const ALLEGRO::AUDIO_STREAM& stream)
	{
		return al_get_audio_stream_pan((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_channels(const ALLEGRO::AUDIO_STREAM& stream) -> ALLEGRO::CHANNEL_CONF
	{
		return al_get_audio_stream_channels((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_depth(const ALLEGRO::AUDIO_STREAM& stream) -> ALLEGRO::AUDIO_DEPTH
	{
		return al_get_audio_stream_depth((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_playmode(const ALLEGRO::AUDIO_STREAM& stream) -> ALLEGRO::PLAYMODE
	{
		return al_get_audio_stream_playmode((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_playing(const ALLEGRO::AUDIO_STREAM& stream) -> bool
	{
		return al_get_audio_stream_playing((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_attached(const ALLEGRO::AUDIO_STREAM& stream) -> bool
	{
		return al_get_audio_stream_attached((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_played_samples(const ALLEGRO::AUDIO_STREAM& stream) -> uint64_t
	{
		return al_get_audio_stream_played_samples((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_fragment(const ALLEGRO::AUDIO_STREAM& stream) -> void*
	{
		return al_get_audio_stream_fragment((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto set_audio_stream_speed(ALLEGRO::AUDIO_STREAM& stream, float value) -> bool
	{
		return al_set_audio_stream_speed((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), value);
	}

	export inline auto set_audio_stream_gain(ALLEGRO::AUDIO_STREAM& stream, float value) -> bool
	{
		return al_set_audio_stream_gain((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), value);
	}

	export inline auto set_audio_stream_pan(ALLEGRO::AUDIO_STREAM& stream, float value) -> bool
	{
		return al_set_audio_stream_pan((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), value);
	}

	export inline auto set_audio_stream_playmode(ALLEGRO::AUDIO_STREAM& stream, ALLEGRO::PLAYMODE value) -> bool
	{
		return al_set_audio_stream_playmode((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), value);
	}

	export inline auto set_audio_stream_playing(ALLEGRO::AUDIO_STREAM& stream, bool value) -> bool
	{
		return al_set_audio_stream_playing((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), value);
	}

	export inline auto detach_audio_stream(ALLEGRO::AUDIO_STREAM& stream) -> bool
	{
		return al_detach_audio_stream((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto set_audio_stream_fragment(ALLEGRO::AUDIO_STREAM& stream, void* value) -> bool
	{
		return al_set_audio_stream_fragment((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), value);
	}

	export inline auto rewind_audio_stream(ALLEGRO::AUDIO_STREAM& stream) -> bool
	{
		return al_rewind_audio_stream((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto seek_audio_stream_secs(ALLEGRO::AUDIO_STREAM& stream, double time) -> bool
	{
		return al_seek_audio_stream_secs((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), time);
	}

	export inline auto get_audio_stream_position_secs(ALLEGRO::AUDIO_STREAM& stream) -> double
	{
		return al_get_audio_stream_position_secs((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto get_audio_stream_length_secs(ALLEGRO::AUDIO_STREAM& stream) -> double
	{
		return al_get_audio_stream_length_secs((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get());
	}

	export inline auto set_audio_stream_loop_secs(ALLEGRO::AUDIO_STREAM& stream, double start, double end) -> bool
	{
		return al_set_audio_stream_loop_secs((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), start, end);
	}

	export inline auto get_audio_stream_event_source(ALLEGRO::AUDIO_STREAM& stream) -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_audio_stream_event_source((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get()), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
	export inline auto set_audio_stream_channel_matrix(ALLEGRO::AUDIO_STREAM& stream, const float* matrix)
	{
		return al_set_audio_stream_channel_matrix((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), matrix);
	}

	export inline auto play_audio_stream(const char* filename) -> ALLEGRO::AUDIO_STREAM
	{
		return ALLEGRO::AUDIO_STREAM(al_play_audio_stream(filename), internal::deleter_empty<ALLEGRO::AUDIO_STREAM_DATA>);
	}

	export inline auto play_audio_stream_f(ALLEGRO::FILE& fp, const char* ident) -> ALLEGRO::AUDIO_STREAM
	{
		return ALLEGRO::AUDIO_STREAM(al_play_audio_stream_f(fp.get(), ident), internal::deleter_empty<ALLEGRO::AUDIO_STREAM_DATA>);
	}
#endif

	export inline auto create_mixer(uint32_t freq, ALLEGRO::AUDIO_DEPTH depth, ALLEGRO::CHANNEL_CONF chan_conf) -> ALLEGRO::MIXER
	{
		return ALLEGRO::MIXER(al_create_mixer(freq, depth, chan_conf), internal::destroy_mixer);
	}

	export inline auto attach_sample_instance_to_mixer(ALLEGRO::SAMPLE_INSTANCE& sample_instance, ALLEGRO::MIXER& mixer)
	{
		return al_attach_sample_instance_to_mixer((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), (ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto attach_audio_stream_to_mixer(ALLEGRO::AUDIO_STREAM& stream, ALLEGRO::MIXER& mixer)
	{
		return al_attach_audio_stream_to_mixer((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), (ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto attach_mixer_to_mixer(ALLEGRO::MIXER& stream, ALLEGRO::MIXER& mixer) -> bool
	{
		return al_attach_mixer_to_mixer((ALLEGRO::MIXER_DATA_PTR)stream.get(), (ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto set_mixer_postprocess_callback(ALLEGRO::MIXER& mixer, void (*cb)(void* buf, uint32_t samples, void* data), void* data) -> bool
	{
		return al_set_mixer_postprocess_callback((ALLEGRO::MIXER_DATA_PTR)mixer.get(), cb, data);
	}

	export inline auto get_mixer_frequency(const ALLEGRO::MIXER& mixer) -> uint32_t
	{
		return al_get_mixer_frequency((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto get_mixer_channels(const ALLEGRO::MIXER& mixer) -> ALLEGRO::CHANNEL_CONF
	{
		return al_get_mixer_channels((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto get_mixer_depth(const ALLEGRO::MIXER& mixer) -> ALLEGRO::AUDIO_DEPTH
	{
		return al_get_mixer_depth((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto get_mixer_quality(const ALLEGRO::MIXER& mixer) -> ALLEGRO::MIXER_QUALITY
	{
		return al_get_mixer_quality((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto get_mixer_gain(const ALLEGRO::MIXER& mixer) -> float
	{
		return al_get_mixer_gain((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto get_mixer_playing(const ALLEGRO::MIXER& mixer) -> bool
	{
		return al_get_mixer_playing((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto get_mixer_attached(const ALLEGRO::MIXER& mixer) -> bool
	{
		return al_get_mixer_attached((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto mixer_has_attachments(const ALLEGRO::MIXER& mixer) -> bool
	{
		return al_mixer_has_attachments((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto set_mixer_frequency(ALLEGRO::MIXER& mixer, uint32_t value) -> bool
	{
		return al_set_mixer_frequency((ALLEGRO::MIXER_DATA_PTR)mixer.get(), value);
	}

	export inline auto set_mixer_quality(ALLEGRO::MIXER& mixer, ALLEGRO::MIXER_QUALITY value) -> bool
	{
		return al_set_mixer_quality((ALLEGRO::MIXER_DATA_PTR)mixer.get(), value);
	}

	export inline auto set_mixer_gain(ALLEGRO::MIXER& mixer, float value) -> bool
	{
		return al_set_mixer_gain((ALLEGRO::MIXER_DATA_PTR)mixer.get(), value);
	}

	export inline auto set_mixer_playing(ALLEGRO::MIXER& mixer, bool value) -> bool
	{
		return al_set_mixer_playing((ALLEGRO::MIXER_DATA_PTR)mixer.get(), value);
	}

	export inline auto detach_mixer(ALLEGRO::MIXER& mixer) -> bool
	{
		al_detach_mixer((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto create_voice(uint32_t freq, ALLEGRO::AUDIO_DEPTH depth, ALLEGRO::CHANNEL_CONF chan_conf) -> ALLEGRO::VOICE
	{
		return ALLEGRO::VOICE(al_create_voice(freq, depth, chan_conf), internal::destroy_voice);
	}

	export inline auto attach_sample_instance_to_voice(ALLEGRO::SAMPLE_INSTANCE& sample_instance, ALLEGRO::VOICE& voice) -> bool
	{
		return al_attach_sample_instance_to_voice((ALLEGRO::SAMPLE_INSTANCE_DATA_PTR)sample_instance.get(), (ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto attach_audio_stream_to_voice(ALLEGRO::AUDIO_STREAM& stream, ALLEGRO::VOICE& voice) -> bool
	{
		return al_attach_audio_stream_to_voice((ALLEGRO::AUDIO_STREAM_DATA_PTR)stream.get(), (ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto attach_mixer_to_voice(ALLEGRO::MIXER& mixer, ALLEGRO::VOICE& voice) -> bool
	{
		return al_attach_mixer_to_voice((ALLEGRO::MIXER_DATA_PTR)mixer.get(), (ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto detach_voice(ALLEGRO::VOICE& voice) -> void
	{
		al_detach_voice((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto get_voice_frequency(const ALLEGRO::VOICE& voice) -> uint32_t
	{
		return al_get_voice_frequency((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto get_voice_position(const ALLEGRO::VOICE& voice) -> uint32_t
	{
		return al_get_voice_position((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto get_voice_channels(const ALLEGRO::VOICE& voice) -> ALLEGRO::CHANNEL_CONF
	{
		return al_get_voice_channels((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto get_voice_depth(const ALLEGRO::VOICE& voice) -> ALLEGRO::AUDIO_DEPTH
	{
		return al_get_voice_depth((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto get_voice_playing(const ALLEGRO::VOICE& voice) -> bool
	{
		return al_get_voice_playing((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto voice_has_attachments(const ALLEGRO::VOICE& voice) -> bool
	{
		return al_voice_has_attachments((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

	export inline auto set_voice_position(ALLEGRO::VOICE& voice, uint32_t value) -> bool
	{
		return al_set_voice_position((ALLEGRO::VOICE_DATA_PTR)voice.get(), value);
	}

	export inline auto set_voice_playing(ALLEGRO::VOICE& voice, bool value) -> bool
	{
		return al_set_voice_playing((ALLEGRO::VOICE_DATA_PTR)voice.get(), value);
	}

	export inline auto get_channel_count(ALLEGRO::CHANNEL_CONF conf) -> size_t
	{
		return al_get_channel_count(conf);
	}

	export inline auto get_audio_depth_size(ALLEGRO::AUDIO_DEPTH conf) -> size_t
	{
		return al_get_audio_depth_size(conf);
	}

	export inline auto fill_silence(void* buf, uint32_t samples, ALLEGRO::AUDIO_DEPTH depth, ALLEGRO::CHANNEL_CONF chan_conf) -> void
	{
		al_fill_silence(buf, samples, depth, chan_conf);
	}

	export inline auto get_num_audio_output_devices() -> int32_t
	{
		return al_get_num_audio_output_devices();
	}

	export inline auto get_audio_output_device(int32_t index) -> const ALLEGRO::AUDIO_DEVICE
	{
		return ALLEGRO::AUDIO_DEVICE(al_get_audio_output_device(index), internal::deleter_empty<ALLEGRO::AUDIO_DEVICE_DATA>);
	}

	export inline auto get_audio_device_name(const ALLEGRO::AUDIO_DEVICE& device) -> const char*
	{
		return al_get_audio_device_name((ALLEGRO::AUDIO_DEVICE_DATA_PTR)device.get());
	}

	export inline auto reserve_samples(int32_t reserve_samples) -> bool
	{
		return al_reserve_samples(reserve_samples);
	}

	export inline auto get_default_mixer() -> ALLEGRO::MIXER
	{
		return ALLEGRO::MIXER(al_get_default_mixer(), internal::deleter_empty<ALLEGRO::MIXER_DATA>);
	}

	export inline auto set_default_mixer(ALLEGRO::MIXER& mixer) -> bool
	{
		return al_set_default_mixer((ALLEGRO::MIXER_DATA_PTR)mixer.get());
	}

	export inline auto restore_default_mixer() -> bool
	{
		return al_restore_default_mixer();
	}

	export inline auto play_sample(ALLEGRO::SAMPLE& data, float gain, float pan, float speed, ALLEGRO::PLAYMODE loop, ALLEGRO::SAMPLE_ID& ret_id) -> bool
	{
		return al_play_sample((ALLEGRO::SAMPLE_DATA_PTR)data.get(), gain, pan, speed, loop, &ret_id);
	}

	export inline auto stop_sample(ALLEGRO::SAMPLE_ID& spl_id) -> void
	{
		al_stop_sample(&spl_id);
	}

	export inline auto stop_samples() -> void
	{
		al_stop_samples();
	}

	export inline auto get_default_voice() -> ALLEGRO::VOICE
	{
		return ALLEGRO::VOICE(al_get_default_voice(), internal::deleter_empty<ALLEGRO::VOICE_DATA>);
	}

	export inline auto set_default_voice(ALLEGRO::VOICE& voice) -> void
	{
		al_set_default_voice((ALLEGRO::VOICE_DATA_PTR)voice.get());
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
	export inline auto_INSTANCE lock_sample_id(ALLEGRO::SAMPLE_ID& spl_id) -> ALLEGRO::SAMPLE
	{
		ALLEGRO::SAMPLE_INSTANCE(al_lock_sample_id(&spl_id), internal::deleter_empty<ALLEGRO::SAMPLE_INSTANCE_DATA>);
	}

	export inline auto unlock_sample_id(ALLEGRO::SAMPLE_ID& spl_id) -> void
	{
		al_unlock_sample_id(&spl_id);
	}
#endif

	export inline auto register_sample_loader(const char* ext, ALLEGRO::SAMPLE_DATA_PTR(*loader)(const char* filename)) -> bool
	{
		return al_register_sample_loader(ext, loader);
	}

	export inline auto register_sample_saver(const char* ext, bool (*saver)(const char* filename, ALLEGRO::SAMPLE_DATA_PTR sample_instance)) -> bool
	{
		return al_register_sample_saver(ext, saver);
	}

	export inline auto register_audio_stream_loader(const char* ext, ALLEGRO::AUDIO_STREAM_DATA_PTR(*stream_loader)(const char* filename, size_t buffer_count, uint32_t samples)) -> bool
	{
		return al_register_audio_stream_loader(ext, stream_loader);
	}

	export inline auto register_sample_loader_f(const char* ext, ALLEGRO::SAMPLE_DATA_PTR(*loader)(ALLEGRO::FILE_DATA_PTR fp)) -> bool
	{
		return al_register_sample_loader_f(ext, loader);
	}

	export inline auto register_sample_saver_f(const char* ext, bool (*saver)(ALLEGRO::FILE_DATA_PTR fp, ALLEGRO::SAMPLE_DATA_PTR sample_instance)) -> bool
	{
		return al_register_sample_saver_f(ext, saver);
	}

	export inline auto register_audio_stream_loader_f(const char* ext, ALLEGRO::AUDIO_STREAM_DATA_PTR(*stream_loader)(ALLEGRO::FILE_DATA_PTR fp, size_t buffer_count, uint32_t samples)) -> bool
	{
		return al_register_audio_stream_loader_f(ext, stream_loader);
	}

	export inline auto register_sample_identifier(const char* ext, bool (*identifier)(ALLEGRO::FILE_DATA_PTR fp))
	{
		return al_register_sample_identifier(ext, identifier);
	}

	export inline auto load_sample(const char* filename) -> ALLEGRO::SAMPLE
	{
		return ALLEGRO::SAMPLE(al_load_sample(filename), internal::destroy_sample);
	}

	export inline auto save_sample(const char* filename, ALLEGRO::SAMPLE& sample_instance)
	{
		return al_save_sample(filename, (ALLEGRO::SAMPLE_DATA_PTR)sample_instance.get());
	}

	export inline auto load_audio_stream(const char* filename, size_t buffer_count, uint32_t samples)
	{
		return ALLEGRO::AUDIO_STREAM(al_load_audio_stream(filename, buffer_count, samples), internal::destroy_audio_stream);
	}

	export inline auto load_sample_f(ALLEGRO::FILE& fp, const char* ident) -> ALLEGRO::SAMPLE
	{
		return ALLEGRO::SAMPLE(al_load_sample_f((ALLEGRO::FILE_DATA_PTR)fp.get(), ident), internal::destroy_sample);
	}

	export inline auto save_sample_f(ALLEGRO::FILE& fp, const char* ident, ALLEGRO::SAMPLE& sample_instance) -> bool
	{
		return al_save_sample_f((ALLEGRO::FILE_DATA_PTR)fp.get(), ident, (ALLEGRO::SAMPLE_DATA_PTR)sample_instance.get());
	}

	export inline auto load_audio_stream_f(ALLEGRO::FILE& fp, const char* ident, size_t buffer_count, uint32_t samples)
	{
		return ALLEGRO::AUDIO_STREAM(al_load_audio_stream_f((ALLEGRO::FILE_DATA_PTR)fp.get(), ident, buffer_count, samples), internal::destroy_audio_stream);
	}

	export inline auto identify_sample_f(ALLEGRO::FILE& fp) -> const char*
	{
		return al_identify_sample_f((ALLEGRO::FILE_DATA_PTR)fp.get());
	}

	export inline auto identify_sample(const char* filename) -> const char*
	{
		return al_identify_sample(filename);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_KCM_AUDIO_SRC)
	export inline auto create_audio_recorder(size_t fragment_count, uint32_t samples, uint32_t freq, ALLEGRO::AUDIO_DEPTH depth, ALLEGRO::CHANNEL_CONF chan_conf) -> ALLEGRO::AUDIO_RECORDER
	{
		return ALLEGRO::AUDIO_RECORDER(al_create_audio_recorder(fragment_count, samples, freq, depth, chan_conf), internal::destroy_audio_recorder);
	}

	export inline auto start_audio_recorder(ALLEGRO::AUDIO_RECORDER& recorder) -> bool
	{
		return al_start_audio_recorder((ALLEGRO::AUDIO_RECORDER_DATA_PTR)recorder.get());
	}

	export inline auto stop_audio_recorder(ALLEGRO::AUDIO_RECORDER& recorder) -> void
	{
		al_stop_audio_recorder((ALLEGRO::AUDIO_RECORDER_DATA_PTR)recorder.get());
	}

	export inline auto is_audio_recorder_recording(ALLEGRO::AUDIO_RECORDER& recorder) -> bool
	{
		return al_is_audio_recorder_recording((ALLEGRO::AUDIO_RECORDER_DATA_PTR)recorder.get());
	}

	export inline auto get_audio_recorder_event_source(ALLEGRO::AUDIO_RECORDER& recorder) -> ALLEGRO::EVENT_SOURCE
	{
		return ALLEGRO::EVENT_SOURCE(al_get_audio_recorder_event_source((ALLEGRO::AUDIO_RECORDER_DATA_PTR)recorder.get()), al::internal::deleter_empty<ALLEGRO::EVENT_SOURCE_DATA>);
	}

	export inline auto get_audio_recorder_event(ALLEGRO::EVENT& event) -> ALLEGRO::AUDIO_RECORDER_EVENT&
	{
		return *al_get_audio_recorder_event(&event);
	}
#endif
}
