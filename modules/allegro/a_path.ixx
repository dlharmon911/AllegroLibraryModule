export module allegro:path;

import <string>;
import <memory>;
import <allegro5/path.h>;
import <type_traits>;
import :base;
import :memory;
import :utf8;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using PATH_DATA = ALLEGRO_PATH;
		export using PATH_DATA_PTR = std::add_pointer<PATH_DATA>::type;
	}

	export using PATH = std::shared_ptr<INTERNAL::PATH_DATA>;

	export inline constexpr char NATIVE_PATH_SEP = ALLEGRO_NATIVE_PATH_SEP;
	export inline constexpr char NATIVE_DRIVE_SEP = ALLEGRO_NATIVE_DRIVE_SEP;
}

namespace al
{
	namespace internal
	{
		export inline auto create_path(const char* str) -> ALLEGRO::INTERNAL::PATH_DATA_PTR
		{
			return al_create_path(str);
		}

		export inline auto destroy_path(ALLEGRO::INTERNAL::PATH_DATA_PTR data) -> void
		{
			al_destroy_path(data);
		}
	}

	export inline auto create_path(const char* str) -> ALLEGRO::PATH
	{
		return ALLEGRO::PATH(al_create_path(str), internal::destroy_path);
	}

	export inline auto create_path_for_directory(const char* str) -> ALLEGRO::PATH
	{
		return ALLEGRO::PATH(al_create_path_for_directory(str), internal::destroy_path);
	}

	export inline auto clone_path(const ALLEGRO::PATH& path) -> ALLEGRO::PATH
	{
		return ALLEGRO::PATH(al_clone_path(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get())), internal::destroy_path);
	}

	export inline auto get_path_num_components(const ALLEGRO::PATH& path) -> int32_t
	{
		return al_get_path_num_components(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}

	export inline auto get_path_component(const ALLEGRO::PATH& path, int32_t i) -> const char*
	{
		return (const char*)al_get_path_component(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), i);
	}

	export inline auto replace_path_component(ALLEGRO::PATH& path, int32_t i, const char* s) -> void
	{
		al_replace_path_component(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), i, s);
	}

	export inline auto remove_path_component(ALLEGRO::PATH& path, int32_t i) -> void
	{
		al_remove_path_component(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), i);
	}

	export inline auto insert_path_component(ALLEGRO::PATH& path, int32_t i, const char* s) -> void
	{
		al_insert_path_component(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), i, s);
	}

	export inline auto get_path_tail(const ALLEGRO::PATH& path) -> const char*
	{
		return (const char*)al_get_path_tail(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}

	export inline auto drop_path_tail(ALLEGRO::PATH& path) -> void
	{
		al_drop_path_tail(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}

	export inline auto append_path_component(ALLEGRO::PATH& path, const char* s) -> void
	{
		al_append_path_component(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), s);
	}

	export inline auto join_paths(ALLEGRO::PATH& path, const ALLEGRO::PATH& tail) -> bool
	{
		return al_join_paths(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), (ALLEGRO::INTERNAL::PATH_DATA_PTR)tail.get());
	}

	export inline auto rebase_path(const ALLEGRO::PATH& head, ALLEGRO::PATH& tail) -> bool
	{
		return al_rebase_path((ALLEGRO::INTERNAL::PATH_DATA_PTR)head.get(), (ALLEGRO::INTERNAL::PATH_DATA_PTR)tail.get());
	}

	export inline auto path_cstr(const ALLEGRO::PATH& path, char delim) -> const char*
	{
		return (const char*)al_path_cstr(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), delim);
	}

	export inline auto path_ustr(const ALLEGRO::PATH& path, char delim) -> ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(al_ustr_dup(al_path_ustr(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), delim)), al_ustr_free);
	}

	export inline auto set_path_drive(ALLEGRO::PATH& path, const char* drive) -> void
	{
		al_set_path_drive(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), drive);
	}

	export inline auto get_path_drive(const ALLEGRO::PATH& path) -> const char*
	{
		return (const char*)al_get_path_drive(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}

	export inline auto set_path_filename(ALLEGRO::PATH& path, const char* filename) -> void
	{
		al_set_path_filename(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), filename);
	}

	export inline auto get_path_filename(const ALLEGRO::PATH& path) -> const char*
	{
		return (const char*)al_get_path_filename(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}

	export inline auto get_path_extension(const ALLEGRO::PATH& path) -> const char*
	{
		return (const char*)al_get_path_extension(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}

	export inline auto set_path_extension(ALLEGRO::PATH& path, const char* extension) -> bool
	{
		return al_set_path_extension(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()), extension);
	}

	export inline auto get_path_basename(const ALLEGRO::PATH& path) -> const char*
	{
		return (const char*)al_get_path_basename(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}

	export inline auto make_path_canonical(ALLEGRO::PATH& path) -> bool
	{
		return al_make_path_canonical(static_cast<ALLEGRO::INTERNAL::PATH_DATA_PTR>(path.get()));
	}
}
