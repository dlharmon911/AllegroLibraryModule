export module allegro:shader;

import <memory>;
import <string>;
import <allegro5/shader.h>;
import :base;
import :bitmap;
import :memory;
import :transformations;

namespace ALLEGRO
{
	export inline const char* SHADER_VAR_COLOR = ALLEGRO_SHADER_VAR_COLOR;
	export inline const char* SHADER_VAR_POS = ALLEGRO_SHADER_VAR_POS;
	export inline const char* SHADER_VAR_PROJVIEW_MATRIX = ALLEGRO_SHADER_VAR_PROJVIEW_MATRIX;
	export inline const char* SHADER_VAR_TEX = ALLEGRO_SHADER_VAR_TEX;
	export inline const char* SHADER_VAR_TEXCOORD = ALLEGRO_SHADER_VAR_TEXCOORD;
	export inline const char* SHADER_VAR_TEX_MATRIX = ALLEGRO_SHADER_VAR_TEX_MATRIX;
	export inline const char* SHADER_VAR_USER_ATTR = ALLEGRO_SHADER_VAR_USER_ATTR;
	export inline const char* SHADER_VAR_USE_TEX = ALLEGRO_SHADER_VAR_USE_TEX;
	export inline const char* SHADER_VAR_USE_TEX_MATRIX = ALLEGRO_SHADER_VAR_USE_TEX_MATRIX;
	export inline const char* SHADER_VAR_ALPHA_TEST = ALLEGRO_SHADER_VAR_ALPHA_TEST;
	export inline const char* SHADER_VAR_ALPHA_FUNCTION = ALLEGRO_SHADER_VAR_ALPHA_FUNCTION;
	export inline const char* SHADER_VAR_ALPHA_TEST_VALUE = ALLEGRO_SHADER_VAR_ALPHA_TEST_VALUE;

	export using SHADER_DATA = ALLEGRO_SHADER;
	export using SHADER = std::shared_ptr<SHADER_DATA>;

	export using SHADER_TYPE = ALLEGRO_SHADER_TYPE;
	export enum
	{
		VERTEX_SHADER = ALLEGRO_VERTEX_SHADER,
		PIXEL_SHADER = ALLEGRO_PIXEL_SHADER
	};

	export using SHADER_PLATFORM = ALLEGRO_SHADER_PLATFORM;
	export enum
	{
		SHADER_AUTO = ALLEGRO_SHADER_AUTO,
		SHADER_GLSL = ALLEGRO_SHADER_GLSL,
		SHADER_HLSL = ALLEGRO_SHADER_HLSL,
		SHADER_AUTO_MINIMAL = ALLEGRO_SHADER_AUTO_MINIMAL,
		SHADER_GLSL_MINIMAL = ALLEGRO_SHADER_GLSL_MINIMAL,
		SHADER_HLSL_MINIMAL = ALLEGRO_SHADER_HLSL_MINIMAL,
		SHADER_HLSL_SM_3_0 = ALLEGRO_SHADER_HLSL_SM_3_0,
	};
}

namespace al
{
	namespace internal
	{
		export inline void destroy_shader(ALLEGRO::SHADER_DATA* data)
		{
			al_destroy_shader(data);
		}
	}

	export inline ALLEGRO::SHADER create_shader(ALLEGRO::SHADER_PLATFORM platform)
	{
		return ALLEGRO::SHADER(al_create_shader(platform), internal::destroy_shader);
	}

	export inline bool attach_shader_source(ALLEGRO::SHADER& shader, ALLEGRO_SHADER_TYPE type, const char* source)
	{
		return al_attach_shader_source((ALLEGRO::SHADER_DATA*)shader.get(), type, source);
	}

	export inline bool attach_shader_source_file(ALLEGRO::SHADER& shader, ALLEGRO_SHADER_TYPE type, const char* filename)
	{
		return al_attach_shader_source_file((ALLEGRO::SHADER_DATA*)shader.get(), type, filename);
	}

	export inline bool build_shader(ALLEGRO::SHADER& shader)
	{
		return al_build_shader((ALLEGRO::SHADER_DATA*)shader.get());
	}

	export inline const char* get_shader_log(ALLEGRO::SHADER& shader)
	{
		return al_get_shader_log((ALLEGRO::SHADER_DATA*)shader.get());
	}

	export inline ALLEGRO_SHADER_PLATFORM get_shader_platform(ALLEGRO::SHADER& shader)
	{
		return al_get_shader_platform((ALLEGRO::SHADER_DATA*)shader.get());
	}

	export inline bool use_shader(ALLEGRO::SHADER& shader)
	{
		return al_use_shader((ALLEGRO::SHADER_DATA*)shader.get());
	}

	export inline ALLEGRO::SHADER get_current_shader()
	{
		return ALLEGRO::SHADER(al_get_current_shader(), internal::deleter_empty<ALLEGRO::SHADER_DATA>);
	}

	export inline bool set_shader_sampler(const char* name, ALLEGRO::BITMAP& bitmap, int32_t unit)
	{
		return al_set_shader_sampler(name, (ALLEGRO::BITMAP_DATA*)bitmap.get(), unit);
	}

	export inline bool set_shader_matrix(const char* name, const ALLEGRO::TRANSFORM& matrix)
	{
		return al_set_shader_matrix(name, &matrix);
	}

	export inline bool set_shader_int(const char* name, int32_t i)
	{
		return al_set_shader_int(name, i);
	}

	export inline bool set_shader_float(const char* name, float f)
	{
		return al_set_shader_float(name, f);
	}

	export inline bool set_shader_int_vector(const char* name, int32_t num_components, const int32_t* i, int32_t num_elems)
	{
		return al_set_shader_int_vector(name, num_components, i, num_elems);
	}

	export inline bool set_shader_float_vector(const char* name, int32_t num_components, const float* f, int32_t num_elems)
	{
		return al_set_shader_float_vector(name, num_components, f, num_elems);
	}

	export inline bool set_shader_bool(const char* name, bool b)
	{
		return al_set_shader_bool(name, b);
	}

	export inline const char* get_default_shader_source(ALLEGRO_SHADER_PLATFORM platform, ALLEGRO_SHADER_TYPE type)
	{
		return al_get_default_shader_source(platform, type);
	}
}
