export module allegro:path;

import <string>;
import <memory>;
import <allegro5/path.h>;
import :base;
import :memory;
import :utf8;

namespace ALLEGRO
{
	export inline constexpr char NATIVE_PATH_SEP = ALLEGRO_NATIVE_PATH_SEP;
	export inline constexpr char NATIVE_DRIVE_SEP = ALLEGRO_NATIVE_DRIVE_SEP;
	export using PATH_DATA = ALLEGRO_PATH;
	export using PATH = ALLEGRO::OBJECT_TYPE;
}

namespace al
{
	namespace internal
	{
		export inline void destroy_path(ALLEGRO::PATH_DATA* data)
		{
			al_destroy_path(data);
		}
	}

	export inline ALLEGRO::PATH create_path(const char* str)
	{
		return ALLEGRO::PATH(al_create_path(str), internal::destroy_path);
	}

	export inline ALLEGRO::PATH create_path_for_directory(const char* str)
	{
		return ALLEGRO::PATH(al_create_path_for_directory(str), internal::destroy_path);
	}

	export inline ALLEGRO::PATH clone_path(const ALLEGRO::PATH& path)
	{
		return ALLEGRO::PATH(al_clone_path((ALLEGRO::PATH_DATA*)path.get()), internal::destroy_path);
	}

	export inline int32_t get_path_num_components(const ALLEGRO::PATH& path)
	{
		return al_get_path_num_components((ALLEGRO::PATH_DATA*)path.get());
	}

	export inline const char* get_path_component(const ALLEGRO::PATH& path, int32_t i)
	{
		return al_get_path_component((ALLEGRO::PATH_DATA*)path.get(), i);
	}
	
	export inline void replace_path_component(ALLEGRO::PATH& path, int32_t i, const char* s)
	{
		al_replace_path_component((ALLEGRO::PATH_DATA*)path.get(), i, s);
	}
	
	export inline void remove_path_component(ALLEGRO::PATH& path, int32_t i)
	{
		al_remove_path_component((ALLEGRO::PATH_DATA*)path.get(), i);
	}
	
	export inline void insert_path_component(ALLEGRO::PATH& path, int32_t i, const char* s)
	{
		al_insert_path_component((ALLEGRO::PATH_DATA*)path.get(), i, s);
	}
	
	export inline const char* get_path_tail(const ALLEGRO::PATH& path)
	{
		return al_get_path_tail((ALLEGRO::PATH_DATA*)path.get());
	}
	
	export inline void drop_path_tail(ALLEGRO::PATH& path)
	{
		al_drop_path_tail((ALLEGRO::PATH_DATA*)path.get());
	}
	
	export inline void append_path_component(ALLEGRO::PATH& path, const char* s)
	{
		al_append_path_component((ALLEGRO::PATH_DATA*)path.get(), s);
	}
	
	export inline bool join_paths(ALLEGRO::PATH& path, const ALLEGRO::PATH& tail)
	{
		return al_join_paths((ALLEGRO::PATH_DATA*)path.get(), (ALLEGRO::PATH_DATA*)tail.get());
	}
	
	export inline bool rebase_path(const ALLEGRO::PATH& head, ALLEGRO::PATH& tail)
	{
		return al_rebase_path((ALLEGRO::PATH_DATA*)head.get(), (ALLEGRO::PATH_DATA*)tail.get());
	}
	
	export inline const char* path_cstr(const ALLEGRO::PATH& path, char delim)
	{
		return al_path_cstr((ALLEGRO::PATH_DATA*)path.get(), delim);
	}
	
	export inline ALLEGRO::USTRING path_ustr(const ALLEGRO::PATH& path, char delim)
	{
		return ALLEGRO::USTRING(al_ustr_dup(al_path_ustr((ALLEGRO::PATH_DATA*)path.get(), delim)), al_ustr_free);
	}
	
	export inline void set_path_drive(ALLEGRO::PATH& path, const char* drive)
	{
		al_set_path_drive((ALLEGRO::PATH_DATA*)path.get(), drive);
	}
	
	export inline const char* get_path_drive(const ALLEGRO::PATH& path)
	{
		return al_get_path_drive((ALLEGRO::PATH_DATA*)path.get());
	}
	
	export inline void set_path_filename(ALLEGRO::PATH& path, const char* filename)
	{
		al_set_path_filename((ALLEGRO::PATH_DATA*)path.get(), filename);
	}
	
	export inline const char* get_path_filename(const ALLEGRO::PATH& path)
	{
		return al_get_path_filename((ALLEGRO::PATH_DATA*)path.get());
	}
	
	export inline const char* get_path_extension(const ALLEGRO::PATH& path)
	{
		return al_get_path_extension((ALLEGRO::PATH_DATA*)path.get());
	}
	
	export inline bool set_path_extension(ALLEGRO::PATH& path, const char* extension)
	{
		return al_set_path_extension((ALLEGRO::PATH_DATA*)path.get(), extension);
	}
	
	export inline const char* get_path_basename(const ALLEGRO::PATH& path)
	{
		return al_get_path_basename((ALLEGRO::PATH_DATA*)path.get());
	}

	export inline bool make_path_canonical(ALLEGRO::PATH& path)
	{
		return al_make_path_canonical((ALLEGRO::PATH_DATA*)path.get());
	}
}

