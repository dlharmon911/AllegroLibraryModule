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
	export using FS_ENTRY = std::shared_ptr<FS_ENTRY_DATA>;
	export using FS_INTERFACE_DATA = const ALLEGRO_FS_INTERFACE;
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
		export inline void destroy_fs_entry(ALLEGRO::FS_ENTRY_DATA* data)
		{
			al_destroy_fs_entry(data);
		}
	}

	export inline ALLEGRO::FS_ENTRY create_fs_entry(const char* path)
	{
		return ALLEGRO::FS_ENTRY(al_create_fs_entry(path), internal::destroy_fs_entry);
	}

	export inline const char* get_fs_entry_name(ALLEGRO::FS_ENTRY& e)
	{
		return al_get_fs_entry_name(e.get());
	}

	export inline bool update_fs_entry(ALLEGRO::FS_ENTRY& e)
	{
		return al_update_fs_entry(e.get());
	}

	export inline uint32_t get_fs_entry_mode(ALLEGRO::FS_ENTRY& e)
	{
		return al_get_fs_entry_mode(e.get());
	}

	export inline time_t get_fs_entry_atime(ALLEGRO::FS_ENTRY& e)
	{
		return al_get_fs_entry_atime(e.get());
	}

	export inline time_t get_fs_entry_mtime(ALLEGRO::FS_ENTRY& e)
	{
		return al_get_fs_entry_mtime(e.get());
	}

	export inline time_t get_fs_entry_ctime(ALLEGRO::FS_ENTRY& e)
	{
		return al_get_fs_entry_ctime(e.get());
	}

	export inline off_t get_fs_entry_size(ALLEGRO::FS_ENTRY& e)
	{
		return al_get_fs_entry_size(e.get());
	}

	export inline bool fs_entry_exists(ALLEGRO::FS_ENTRY& e)
	{
		return al_fs_entry_exists(e.get());
	}

	export inline bool remove_fs_entry(ALLEGRO::FS_ENTRY& e)
	{
		return al_remove_fs_entry(e.get());
	}

	export inline bool open_directory(ALLEGRO::FS_ENTRY& e)
	{
		return al_open_directory(e.get());
	}

	export inline ALLEGRO::FS_ENTRY read_directory(ALLEGRO::FS_ENTRY& e)
	{
		return ALLEGRO::FS_ENTRY(al_read_directory(e.get()), internal::destroy_fs_entry);
	}

	export inline bool close_directory(ALLEGRO::FS_ENTRY& e)
	{
		return al_close_directory(e.get());
	}

	export inline bool filename_exists(const char* path)
	{
		return al_filename_exists(path);
	}

	export inline bool remove_filename(const char* path)
	{
		return al_remove_filename(path);
	}

	export inline const char* get_current_directory()
	{
		return al_get_current_directory();
	}

	export inline bool change_directory(const char* path)
	{
		return al_change_directory(path);
	}

	export inline bool make_directory(const char* path)
	{
		return al_make_directory(path);
	}

	export inline ALLEGRO::FILE open_fs_entry(ALLEGRO::FS_ENTRY& e, const char* mode)
	{
		return ALLEGRO::FILE(al_open_fs_entry(e.get(), mode), internal::destroy_file);
	}

	export inline int32_t for_each_fs_entry(ALLEGRO::FS_ENTRY& dir, int32_t(*callback)(ALLEGRO_FS_ENTRY* entry, void* extra), void* extra)
	{
		return al_for_each_fs_entry(dir.get(), callback, extra);
	}

	export inline const ALLEGRO::FS_INTERFACE get_fs_interface()
	{
		return ALLEGRO::FS_INTERFACE(al_get_fs_interface(), al::internal::deleter_empty<const ALLEGRO_FS_INTERFACE>);
	}

	export inline void set_fs_interface(const ALLEGRO::FS_INTERFACE& vtable)
	{
		al_set_fs_interface(vtable.get());
	}

	export inline void set_standard_fs_interface()
	{
		al_set_standard_fs_interface();
	}
}
