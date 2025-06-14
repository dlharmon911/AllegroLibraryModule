module;

#include <allegro5/allegro5.h>

#ifdef ALLEGRO_CFG_OPENGL
#include <allegro5/allegro_opengl.h>
#endif

export module allegro:opengl;

import <cassert>;
import <memory>;
import :base;
import :bitmap;
import :display;
import :shader;
import :vector_2d;

namespace ALLEGRO
{
#ifdef ALLEGRO_CFG_OPENGL
	export using OGL_EXT_LIST = ALLEGRO_OGL_EXT_LIST;
	export using OGL_EXT_LIST_PTR = std::add_pointer<ALLEGRO_OGL_EXT_LIST>::type;
#endif
}

namespace al
{
#ifdef ALLEGRO_CFG_OPENGL
	auto get_opengl_version() -> uint32_t
	{
		return al_get_opengl_version();
	}

	auto have_opengl_extension(const char* extension) -> bool
	{
		return al_have_opengl_extension(extension);
	}

	auto get_opengl_proc_address(const char* name) -> void*
	{
		return al_get_opengl_proc_address(name);
	}

	auto get_opengl_extension_list() -> ALLEGRO::OGL_EXT_LIST_PTR
	{
		return static_cast<ALLEGRO::OGL_EXT_LIST_PTR>(al_get_opengl_extension_list());
	}

	auto get_opengl_texture(const ALLEGRO::BITMAP& bitmap) -> GLuint
	{
		return al_get_opengl_texture(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	auto remove_opengl_fbo(const ALLEGRO::BITMAP& bitmap) -> void
	{
		return al_remove_opengl_fbo(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	auto get_opengl_fbo(const ALLEGRO::BITMAP& bitmap) -> GLuint
	{
		return al_get_opengl_fbo(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	auto get_opengl_texture_size(const ALLEGRO::BITMAP& bitmap, ALLEGRO::VECTOR_2D<int32_t>& size) -> bool
	{
		std::array<int32_t, ALLEGRO::INTERNAL::VECTOR_2D_ARRAY_SIZE> array{};
		bool rv = al_get_opengl_texture_size(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), &array[0], &array[1]);

		size = array;

		return rv;
	}

	auto get_opengl_texture_position(const ALLEGRO::BITMAP& bitmap, ALLEGRO::VECTOR_2D<int32_t>& position) -> void
	{
		std::array<int32_t, ALLEGRO::INTERNAL::VECTOR_2D_ARRAY_SIZE> array{};

		al_get_opengl_texture_position(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), &array[0], &array[1]);

		position = array;

	}

	auto get_opengl_program_object(const ALLEGRO::SHADER& shader) -> GLuint
	{
		return al_get_opengl_program_object(static_cast<ALLEGRO::INTERNAL::SHADER_DATA_PTR>(shader.get()));
	}

	auto set_current_opengl_context(const ALLEGRO::DISPLAY& display) -> void
	{
		return al_set_current_opengl_context(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	auto get_opengl_variant() -> int32_t
	{
		return al_get_opengl_variant();
	}
#endif
}
