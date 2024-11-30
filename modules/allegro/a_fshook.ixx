export module allegro:fshook;

import <memory>;
import <string>;
import <allegro5/fshook.h>;

export using ::off_t;

import :base;
import :file;
import :path;
import :memory;

namespace ALLEGRO
{
	export using FS_ENTRY_DATA = ALLEGRO_FS_ENTRY;
	export using FS_ENTRY_DATA_PTR = std::add_pointer<FS_ENTRY_DATA>::type;
	export using FS_ENTRY = std::shared_ptr<FS_ENTRY_DATA>;
	export using FS_INTERFACE_DATA = ALLEGRO_FS_INTERFACE;
	export using FS_INTERFACE_DATA_PTR = std::add_pointer<FS_INTERFACE_DATA>::type;
	export using FS_INTERFACE = std::shared_ptr<const FS_INTERFACE_DATA>;
	export using FILE_MODE = ALLEGRO_FILE_MODE;
	export using FOR_EACH_FS_ENTRY_RESULT = ALLEGRO_FOR_EACH_FS_ENTRY_RESULT;

	export enum
	{
		FILEMODE_READ = ALLEGRO_FILEMODE_READ,
		FILEMODE_WRITE = ALLEGRO_FILEMODE_WRITE,
		FILEMODE_EXECUTE = ALLEGRO_FILEMODE_EXECUTE,
		FILEMODE_HIDDEN = ALLEGRO_FILEMODE_HIDDEN,
		FILEMODE_ISFILE = ALLEGRO_FILEMODE_ISFILE,
		FILEMODE_ISDIR = ALLEGRO_FILEMODE_ISDIR
	};

	export enum
	{
		FOR_EACH_FS_ENTRY_ERROR = ALLEGRO_FOR_EACH_FS_ENTRY_ERROR,
		FOR_EACH_FS_ENTRY_OK = ALLEGRO_FOR_EACH_FS_ENTRY_OK,
		FOR_EACH_FS_ENTRY_SKIP = ALLEGRO_FOR_EACH_FS_ENTRY_SKIP,
		FOR_EACH_FS_ENTRY_STOP = ALLEGRO_FOR_EACH_FS_ENTRY_STOP
	};
}

#ifndef EOF
export inline constexpr size_t EOF = -1;
#endif

namespace al
{
	namespace internal
	{
		export inline auto create_fs_entry(const char* path) -> ALLEGRO::FS_ENTRY_DATA_PTR
		{
			return al_create_fs_entry(path);
		}

		export inline auto destroy_fs_entry(ALLEGRO::FS_ENTRY_DATA_PTR data) -> void
		{
			al_destroy_fs_entry(data);
		}
	}

	export inline auto create_fs_entry(const char* path) -> ALLEGRO::FS_ENTRY
	{
		return ALLEGRO::FS_ENTRY(al_create_fs_entry(path), internal::destroy_fs_entry);
	}

	export inline auto get_fs_entry_name(const ALLEGRO::FS_ENTRY& e) -> const char*
	{
		return (const char*)al_get_fs_entry_name((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto update_fs_entry(const ALLEGRO::FS_ENTRY& e) -> bool
	{
		return al_update_fs_entry((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto get_fs_entry_mode(const ALLEGRO::FS_ENTRY& e) -> uint32_t
	{
		return al_get_fs_entry_mode((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto get_fs_entry_atime(const ALLEGRO::FS_ENTRY& e) -> time_t
	{
		return al_get_fs_entry_atime((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto get_fs_entry_mtime(const ALLEGRO::FS_ENTRY& e) -> time_t
	{
		return al_get_fs_entry_mtime((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto get_fs_entry_ctime(const ALLEGRO::FS_ENTRY& e) -> time_t
	{
		return al_get_fs_entry_ctime((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto get_fs_entry_size(const ALLEGRO::FS_ENTRY& e) -> off_t
	{
		return al_get_fs_entry_size((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto fs_entry_exists(const ALLEGRO::FS_ENTRY& e) -> bool
	{
		return al_fs_entry_exists((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto remove_fs_entry(const ALLEGRO::FS_ENTRY& e) -> bool
	{
		return al_remove_fs_entry((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto open_directory(const ALLEGRO::FS_ENTRY& e) -> bool
	{
		return al_open_directory((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto read_directory(const ALLEGRO::FS_ENTRY& e) -> ALLEGRO::FS_ENTRY
	{
		return ALLEGRO::FS_ENTRY(al_read_directory((ALLEGRO::FS_ENTRY_DATA_PTR)e.get()), internal::destroy_fs_entry);
	}

	export inline auto close_directory(const ALLEGRO::FS_ENTRY& e) -> bool
	{
		return al_close_directory((ALLEGRO::FS_ENTRY_DATA_PTR)e.get());
	}

	export inline auto filename_exists(const char* path) -> bool
	{
		return al_filename_exists(path);
	}

	export inline auto remove_filename(const char* path) -> bool
	{
		return al_remove_filename(path);
	}

	export inline auto get_current_directory() -> const char*
	{
		return al_get_current_directory();
	}

	export inline auto change_directory(const char* path) -> bool
	{
		return al_change_directory(path);
	}

	export inline auto make_directory(const char* path) -> bool
	{
		return al_make_directory(path);
	}

	export inline auto open_fs_entry(const ALLEGRO::FS_ENTRY& e, const char* mode) -> ALLEGRO::FILE
	{
		return ALLEGRO::FILE(al_open_fs_entry((ALLEGRO::FS_ENTRY_DATA_PTR)e.get(), mode), internal::destroy_file);
	}

	export inline auto for_each_fs_entry(ALLEGRO::FS_ENTRY& dir, int32_t(*callback)(ALLEGRO_FS_ENTRY* entry, void* extra), void* extra) -> int32_t
	{
		return al_for_each_fs_entry((ALLEGRO::FS_ENTRY_DATA_PTR)dir.get(), callback, extra);
	}

	export inline auto get_fs_interface() -> const ALLEGRO::FS_INTERFACE
	{
		return ALLEGRO::FS_INTERFACE(al_get_fs_interface(), al::internal::deleter_empty<const ALLEGRO_FS_INTERFACE>);
	}

	export inline auto set_fs_interface(const ALLEGRO::FS_INTERFACE& vtable) -> void
	{
		al_set_fs_interface((ALLEGRO::FS_INTERFACE_DATA_PTR)vtable.get());
	}

	export inline auto set_standard_fs_interface() -> void
	{
		al_set_standard_fs_interface();
	}
}