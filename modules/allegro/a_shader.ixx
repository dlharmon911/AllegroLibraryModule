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
	export inline auto SHADER_VAR_COLOR = (const char*)ALLEGRO_SHADER_VAR_COLOR;
	export inline auto SHADER_VAR_POS = (const char*)ALLEGRO_SHADER_VAR_POS;
	export inline auto SHADER_VAR_PROJVIEW_MATRIX = (const char*)ALLEGRO_SHADER_VAR_PROJVIEW_MATRIX;
	export inline auto SHADER_VAR_TEX = (const char*)ALLEGRO_SHADER_VAR_TEX;
	export inline auto SHADER_VAR_TEXCOORD = (const char*)ALLEGRO_SHADER_VAR_TEXCOORD;
	export inline auto SHADER_VAR_TEX_MATRIX = (const char*)ALLEGRO_SHADER_VAR_TEX_MATRIX;
	export inline auto SHADER_VAR_USER_ATTR = (const char*)ALLEGRO_SHADER_VAR_USER_ATTR;
	export inline auto SHADER_VAR_USE_TEX = (const char*)ALLEGRO_SHADER_VAR_USE_TEX;
	export inline auto SHADER_VAR_USE_TEX_MATRIX = (const char*)ALLEGRO_SHADER_VAR_USE_TEX_MATRIX;
	export inline auto SHADER_VAR_ALPHA_TEST = (const char*)ALLEGRO_SHADER_VAR_ALPHA_TEST;
	export inline auto SHADER_VAR_ALPHA_FUNCTION = (const char*)ALLEGRO_SHADER_VAR_ALPHA_FUNCTION;
	export inline auto SHADER_VAR_ALPHA_TEST_VALUE = (const char*)ALLEGRO_SHADER_VAR_ALPHA_TEST_VALUE;

	export using SHADER_DATA = ALLEGRO_SHADER;
	export using SHADER_DATA_PTR = std::add_pointer<SHADER_DATA>::type;
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
		export inline auto destroy_shader(ALLEGRO::SHADER_DATA_PTR data) -> void
		{
			al_destroy_shader(data);
		}
	}

	export inline auto create_shader(int32_t platform) -> ALLEGRO::SHADER
	{
		return ALLEGRO::SHADER(al_create_shader((ALLEGRO_SHADER_PLATFORM)platform), internal::destroy_shader);
	}

	export inline auto attach_shader_source(ALLEGRO::SHADER& shader, int32_t type, const char* source) -> bool
	{
		return al_attach_shader_source((ALLEGRO::SHADER_DATA_PTR)shader.get(), (ALLEGRO_SHADER_TYPE)type, source);
	}

	export inline auto attach_shader_source_file(ALLEGRO::SHADER& shader, int32_t type, const char* filename) -> bool
	{
		return al_attach_shader_source_file((ALLEGRO::SHADER_DATA_PTR)shader.get(), (ALLEGRO_SHADER_TYPE)type, filename);
	}

	export inline auto build_shader(ALLEGRO::SHADER& shader) -> bool
	{
		return al_build_shader((ALLEGRO::SHADER_DATA_PTR)shader.get());
	}

	static ALLEGRO::SHADER null_shader;

	export inline auto get_shader_log(ALLEGRO::SHADER& shader) -> const char*
	{
		return (const char*)al_get_shader_log((ALLEGRO::SHADER_DATA_PTR)shader.get());
	}

	export inline auto get_shader_platform(ALLEGRO::SHADER& shader) -> int32_t
	{
		return (int32_t)al_get_shader_platform((ALLEGRO::SHADER_DATA_PTR)shader.get());
	}

	export inline auto use_shader(ALLEGRO::SHADER& shader = null_shader) -> bool
	{
		return al_use_shader((ALLEGRO::SHADER_DATA_PTR)shader.get());
	}

	export inline auto get_current_shader() -> ALLEGRO::SHADER
	{
		return ALLEGRO::SHADER(al_get_current_shader(), internal::deleter_empty<ALLEGRO::SHADER_DATA>);
	}

	export inline auto set_shader_sampler(const char* name, ALLEGRO::BITMAP& bitmap, int32_t unit) -> bool
	{
		return al_set_shader_sampler(name, (ALLEGRO::BITMAP_DATA_PTR)bitmap.get(), unit);
	}

	export inline auto set_shader_matrix(const char* name, const ALLEGRO::TRANSFORM& matrix) -> bool
	{
		return al_set_shader_matrix(name, &matrix);
	}

	export inline auto set_shader_int(const char* name, int32_t i) -> bool
	{
		return al_set_shader_int(name, i);
	}

	export inline auto set_shader_float(const char* name, float f) -> bool
	{
		return al_set_shader_float(name, f);
	}

	export inline auto set_shader_int_vector(const char* name, int32_t num_components, const int32_t* i, int32_t num_elems) -> bool
	{
		return al_set_shader_int_vector(name, num_components, i, num_elems);
	}

	export inline auto set_shader_float_vector(const char* name, int32_t num_components, const float* f, int32_t num_elems) -> bool
	{
		return al_set_shader_float_vector(name, num_components, f, num_elems);
	}

	export inline auto set_shader_bool(const char* name, bool b) -> bool
	{
		return al_set_shader_bool(name, b);
	}

	export inline auto get_default_shader_source(ALLEGRO_SHADER_PLATFORM platform, int32_t type) -> const char*
	{
		return (const char*)al_get_default_shader_source(platform, (ALLEGRO_SHADER_TYPE)type);
	}
}
