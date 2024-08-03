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
	export using PATH = std::shared_ptr<ALLEGRO::PATH_DATA>;
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

	export inline ALLEGRO::PATH create_path(const std::string& str)
	{
		return ALLEGRO::PATH(al_create_path(str.c_str()), internal::destroy_path);
	}

	export inline ALLEGRO::PATH create_path_for_directory(const std::string& str)
	{
		return ALLEGRO::PATH(al_create_path_for_directory(str.c_str()), internal::destroy_path);
	}

	export inline ALLEGRO::PATH clone_path(const ALLEGRO::PATH& path)
	{
		return ALLEGRO::PATH(al_clone_path(path.get()), internal::destroy_path);
	}

	export inline int32_t get_path_num_components(const ALLEGRO::PATH& path)
	{
		return al_get_path_num_components(path.get());
	}

	export inline std::string get_path_component(const ALLEGRO::PATH& path, int32_t i)
	{
		return std::string(al_get_path_component(path.get(), i));
	}
	
	export inline void replace_path_component(ALLEGRO::PATH& path, int32_t i, const std::string& s)
	{
		al_replace_path_component(path.get(), i, s.c_str());
	}
	
	export inline void remove_path_component(ALLEGRO::PATH& path, int32_t i)
	{
		al_remove_path_component(path.get(), i);
	}
	
	export inline void insert_path_component(ALLEGRO::PATH& path, int32_t i, const std::string& s)
	{
		al_insert_path_component(path.get(), i, s.c_str());
	}
	
	export inline std::string get_path_tail(const ALLEGRO::PATH& path)
	{
		return std::string(al_get_path_tail(path.get()));
	}
	
	export inline void drop_path_tail(ALLEGRO::PATH& path)
	{
		al_drop_path_tail(path.get());
	}
	
	export inline void append_path_component(ALLEGRO::PATH& path, const std::string& s)
	{
		al_append_path_component(path.get(), s.c_str());
	}
	
	export inline bool join_paths(ALLEGRO::PATH& path, const ALLEGRO::PATH& tail)
	{
		return al_join_paths(path.get(), tail.get());
	}
	
	export inline bool rebase_path(const ALLEGRO::PATH& head, ALLEGRO::PATH& tail)
	{
		return al_rebase_path(head.get(), tail.get());
	}
	
	export inline std::string al_path_cstr(const ALLEGRO::PATH& path, char delim)
	{
		return std::string(al_path_cstr(path.get(), delim));
	}
	
	export inline ALLEGRO::USTRING path_ustr(const ALLEGRO::PATH& path, char delim)
	{
		return ALLEGRO::USTRING(al_ustr_dup(al_path_ustr(path.get(), delim)), al_ustr_free);
	}
	
	export inline void set_path_drive(ALLEGRO::PATH& path, const std::string& drive)
	{
		al_set_path_drive(path.get(), drive.c_str());
	}
	
	export inline std::string get_path_drive(const ALLEGRO::PATH& path)
	{
		return std::string(al_get_path_drive(path.get()));
	}
	
	export inline void set_path_filename(ALLEGRO::PATH& path, const std::string& filename)
	{
		al_set_path_filename(path.get(), filename.c_str());
	}
	
	export inline std::string get_path_filename(const ALLEGRO::PATH& path)
	{
		return std::string(al_get_path_filename(path.get()));
	}
	
	export inline std::string get_path_extension(const ALLEGRO::PATH& path)
	{
		return std::string(al_get_path_extension(path.get()));
	}
	
	export inline bool set_path_extension(ALLEGRO::PATH& path, const std::string& extension)
	{
		return al_set_path_extension(path.get(), extension.c_str());
	}
	
	export inline std::string get_path_basename(const ALLEGRO::PATH& path)
	{
		return std::string(al_get_path_basename(path.get()));
	}

	export inline bool make_path_canonical(ALLEGRO::PATH& path)
	{
		return al_make_path_canonical(path.get());
	}
}

