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
	export inline const std::string SHADER_VAR_COLOR = ALLEGRO_SHADER_VAR_COLOR;
	export inline const std::string SHADER_VAR_POS = ALLEGRO_SHADER_VAR_POS;
	export inline const std::string SHADER_VAR_PROJVIEW_MATRIX = ALLEGRO_SHADER_VAR_PROJVIEW_MATRIX;
	export inline const std::string SHADER_VAR_TEX = ALLEGRO_SHADER_VAR_TEX;
	export inline const std::string SHADER_VAR_TEXCOORD = ALLEGRO_SHADER_VAR_TEXCOORD;
	export inline const std::string SHADER_VAR_TEX_MATRIX = ALLEGRO_SHADER_VAR_TEX_MATRIX;
	export inline const std::string SHADER_VAR_USER_ATTR = ALLEGRO_SHADER_VAR_USER_ATTR;
	export inline const std::string SHADER_VAR_USE_TEX = ALLEGRO_SHADER_VAR_USE_TEX;
	export inline const std::string SHADER_VAR_USE_TEX_MATRIX = ALLEGRO_SHADER_VAR_USE_TEX_MATRIX;
	export inline const std::string SHADER_VAR_ALPHA_TEST = ALLEGRO_SHADER_VAR_ALPHA_TEST;
	export inline const std::string SHADER_VAR_ALPHA_FUNCTION = ALLEGRO_SHADER_VAR_ALPHA_FUNCTION;
	export inline const std::string SHADER_VAR_ALPHA_TEST_VALUE = ALLEGRO_SHADER_VAR_ALPHA_TEST_VALUE;

	export using SHADER_DATA = ALLEGRO_SHADER;
	export using SHADER = std::shared_ptr<ALLEGRO::SHADER_DATA>;

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

	export inline bool attach_shader_source(ALLEGRO::SHADER& shader, ALLEGRO_SHADER_TYPE type, const std::string& source)
	{
		return al_attach_shader_source(shader.get(), type, source.c_str());
	}

	export inline bool attach_shader_source_file(ALLEGRO::SHADER& shader, ALLEGRO_SHADER_TYPE type, const std::string& filename)
	{
		return al_attach_shader_source_file(shader.get(), type, filename.c_str());
	}

	export inline bool build_shader(ALLEGRO::SHADER& shader)
	{
		return al_build_shader(shader.get());
	}

	export inline std::string get_shader_log(ALLEGRO::SHADER& shader)
	{
		return al_get_shader_log(shader.get());
	}

	export inline ALLEGRO_SHADER_PLATFORM get_shader_platform(ALLEGRO::SHADER& shader)
	{
		return al_get_shader_platform(shader.get());
	}

	export inline bool use_shader(ALLEGRO::SHADER& shader)
	{
		return al_use_shader(shader.get());
	}

	export inline ALLEGRO::SHADER get_current_shader()
	{
		return ALLEGRO::SHADER(al_get_current_shader(), internal::deleter_empty<ALLEGRO::SHADER_DATA>);
	}

	export inline bool set_shader_sampler(const std::string& name, ALLEGRO::BITMAP& bitmap, int32_t unit)
	{
		return al_set_shader_sampler(name.c_str(), bitmap.get(), unit);
	}

	export inline bool set_shader_matrix(const std::string& name, const ALLEGRO::TRANSFORM& matrix)
	{
		return al_set_shader_matrix(name.c_str(), &matrix);
	}

	export inline bool set_shader_int(const std::string& name, int32_t i)
	{
		return al_set_shader_int(name.c_str(), i);
	}

	export inline bool set_shader_float(const std::string& name, float f)
	{
		return al_set_shader_float(name.c_str(), f);
	}

	export inline bool set_shader_int_vector(const std::string& name, int32_t num_components, const int32_t* i, int32_t num_elems)
	{
		return al_set_shader_int_vector(name.c_str(), num_components, i, num_elems);
	}

	export inline bool set_shader_float_vector(const std::string& name, int32_t num_components, const float* f, int32_t num_elems)
	{
		return al_set_shader_float_vector(name.c_str(), num_components, f, num_elems);
	}

	export inline bool set_shader_bool(const std::string& name, bool b)
	{
		return al_set_shader_bool(name.c_str(), b);
	}

	export inline std::string get_default_shader_source(ALLEGRO_SHADER_PLATFORM platform, ALLEGRO_SHADER_TYPE type)
	{
		return std::string(al_get_default_shader_source(platform, type));
	}
}
