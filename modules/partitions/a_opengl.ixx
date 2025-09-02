module;

#include <allegro5/allegro5.h>

#ifdef ALLEGRO_CFG_OPENGL
#include <allegro5/allegro_opengl.h>
#endif

export module allegro:opengl;

import std;
import <cstdint>;
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
	export auto get_opengl_version() -> uint32_t
	{
		return al_get_opengl_version();
	}

	export auto have_opengl_extension(const char* extension) -> bool
	{
		return al_have_opengl_extension(extension);
	}

	export auto get_opengl_proc_address(const char* name) -> void*
	{
		return al_get_opengl_proc_address(name);
	}

	export auto get_opengl_extension_list() -> ALLEGRO::OGL_EXT_LIST_PTR
	{
		return static_cast<ALLEGRO::OGL_EXT_LIST_PTR>(al_get_opengl_extension_list());
	}

	export auto get_opengl_texture(const ALLEGRO::BITMAP& bitmap) -> uint32_t
	{
		return al_get_opengl_texture(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export auto remove_opengl_fbo(const ALLEGRO::BITMAP& bitmap) -> void
	{
		return al_remove_opengl_fbo(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export auto get_opengl_fbo(const ALLEGRO::BITMAP& bitmap) -> uint32_t
	{
		return al_get_opengl_fbo(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export auto get_opengl_texture_size(const ALLEGRO::BITMAP& bitmap, ALLEGRO::VECTOR_2D<int32_t>& size) -> bool
	{
		std::array<int32_t, ALLEGRO::VECTOR_2D_ARRAY_SIZE> array{};
		bool rv = al_get_opengl_texture_size(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), &array[0], &array[1]);

		size = array;

		return rv;
	}

	export auto get_opengl_texture_size(const ALLEGRO::BITMAP& bitmap, int32_t& width, int32_t& height) -> bool
	{
		return al_get_opengl_texture_size(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), &width, &height);
	}

	export auto get_opengl_texture_position(const ALLEGRO::BITMAP& bitmap, ALLEGRO::VECTOR_2D<int32_t>& position) -> void
	{
		std::array<int32_t, ALLEGRO::VECTOR_2D_ARRAY_SIZE> array{};

		al_get_opengl_texture_position(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), &array[0], &array[1]);

		position = array;
	}

	export auto get_opengl_texture_position(const ALLEGRO::BITMAP& bitmap, int32_t& x, int32_t& y) -> void
	{
		al_get_opengl_texture_position(static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()), &x, &y);
	}

	export auto get_opengl_program_object(const ALLEGRO::SHADER& shader) -> uint32_t
	{
		return al_get_opengl_program_object(static_cast<ALLEGRO::INTERNAL::SHADER_DATA_PTR>(shader.get()));
	}

	export auto set_current_opengl_context(const ALLEGRO::DISPLAY& display) -> void
	{
		return al_set_current_opengl_context(static_cast<ALLEGRO::INTERNAL::DISPLAY_DATA_PTR>(display.get()));
	}

	export auto get_opengl_variant() -> int32_t
	{
		return al_get_opengl_variant();
	}
#endif
}
