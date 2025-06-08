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
	namespace INTERNAL
	{
		export using FS_ENTRY_DATA = typename ALLEGRO_FS_ENTRY;
		export using FS_ENTRY_DATA_PTR = std::add_pointer<FS_ENTRY_DATA>::type;
		export using FS_INTERFACE_DATA = typename ALLEGRO_FS_INTERFACE;
		export using FS_INTERFACE_DATA_PTR = std::add_pointer<FS_INTERFACE_DATA>::type;
	}

	export using FS_ENTRY = typename std::shared_ptr<INTERNAL::FS_ENTRY_DATA>;
	export using FS_INTERFACE = typename std::shared_ptr<const INTERNAL::FS_INTERFACE_DATA>;
	export using FILE_MODE = typename ALLEGRO_FILE_MODE;
	export using FOR_EACH_FS_ENTRY_RESULT = typename ALLEGRO_FOR_EACH_FS_ENTRY_RESULT;

	export constexpr int32_t FILE_MODE_READ{ ALLEGRO_FILEMODE_READ };
	export constexpr int32_t FILE_MODE_WRITE{ ALLEGRO_FILEMODE_WRITE };
	export constexpr int32_t FILE_MODE_EXECUTE{ ALLEGRO_FILEMODE_EXECUTE };
	export constexpr int32_t FILE_MODE_HIDDEN{ ALLEGRO_FILEMODE_HIDDEN };
	export constexpr int32_t FILE_MODE_ISFILE{ ALLEGRO_FILEMODE_ISFILE };
	export constexpr int32_t FILE_MODE_ISDIR{ ALLEGRO_FILEMODE_ISDIR };

	export constexpr int32_t FOR_EACH_FS_ENTRY_ERROR{ ALLEGRO_FOR_EACH_FS_ENTRY_ERROR };
	export constexpr int32_t FOR_EACH_FS_ENTRY_OK{ ALLEGRO_FOR_EACH_FS_ENTRY_OK };
	export constexpr int32_t FOR_EACH_FS_ENTRY_SKIP{ ALLEGRO_FOR_EACH_FS_ENTRY_SKIP };
	export constexpr int32_t FOR_EACH_FS_ENTRY_STOP{ ALLEGRO_FOR_EACH_FS_ENTRY_STOP };
}

namespace al
{
	namespace internal
	{
		export inline auto create_fs_entry(const char* path) -> ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR
		{
			return al_create_fs_entry(path);
		}

		export inline auto destroy_fs_entry(ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR data) -> void
		{
			al_destroy_fs_entry(data);
		}
	}

	export inline auto create_fs_entry(const char* path) -> ALLEGRO::FS_ENTRY
	{
		return ALLEGRO::FS_ENTRY(al_create_fs_entry(path), internal::destroy_fs_entry);
	}

	export inline auto get_fs_entry_name(const ALLEGRO::FS_ENTRY& entry) -> const char*
	{
		return (const char*)al_get_fs_entry_name((ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR)entry.get());
	}

	export inline auto update_fs_entry(const ALLEGRO::FS_ENTRY& entry) -> bool
	{
		return al_update_fs_entry(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto get_fs_entry_mode(const ALLEGRO::FS_ENTRY& entry) -> uint32_t
	{
		return al_get_fs_entry_mode(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto get_fs_entry_atime(const ALLEGRO::FS_ENTRY& entry) -> time_t
	{
		return al_get_fs_entry_atime(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto get_fs_entry_mtime(const ALLEGRO::FS_ENTRY& entry) -> time_t
	{
		return al_get_fs_entry_mtime(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto get_fs_entry_ctime(const ALLEGRO::FS_ENTRY& entry) -> time_t
	{
		return al_get_fs_entry_ctime(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto get_fs_entry_size(const ALLEGRO::FS_ENTRY& entry) -> off_t
	{
		return al_get_fs_entry_size(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto fs_entry_exists(const ALLEGRO::FS_ENTRY& entry) -> bool
	{
		return al_fs_entry_exists(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto remove_fs_entry(const ALLEGRO::FS_ENTRY& entry) -> bool
	{
		return al_remove_fs_entry(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto open_directory(const ALLEGRO::FS_ENTRY& entry) -> bool
	{
		return al_open_directory(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
	}

	export inline auto read_directory(const ALLEGRO::FS_ENTRY& entry) -> ALLEGRO::FS_ENTRY
	{
		return ALLEGRO::FS_ENTRY(al_read_directory(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get())), internal::destroy_fs_entry);
	}

	export inline auto close_directory(const ALLEGRO::FS_ENTRY& entry) -> bool
	{
		return al_close_directory(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()));
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

	export inline auto open_fs_entry(const ALLEGRO::FS_ENTRY& entry, const char* mode) -> ALLEGRO::FILE
	{
		return ALLEGRO::FILE(al_open_fs_entry(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(entry.get()), mode), internal::destroy_file);
	}

	export inline auto for_each_fs_entry(ALLEGRO::FS_ENTRY& dir, int32_t(*callback)(ALLEGRO_FS_ENTRY* entry, void* extra), void* extra) -> int32_t
	{
		return al_for_each_fs_entry(static_cast<ALLEGRO::INTERNAL::FS_ENTRY_DATA_PTR>(dir.get()), callback, extra);
	}

	export inline auto get_fs_interface() -> ALLEGRO::FS_INTERFACE
	{
		return ALLEGRO::FS_INTERFACE(al_get_fs_interface(), al::internal::deleter_empty<const ALLEGRO_FS_INTERFACE>);
	}

	export inline auto set_fs_interface(const ALLEGRO::FS_INTERFACE& vtable) -> void
	{
		al_set_fs_interface(const_cast<const ALLEGRO::INTERNAL::FS_INTERFACE_DATA_PTR>(vtable.get()));
	}

	export inline auto set_standard_fs_interface() -> void
	{
		al_set_standard_fs_interface();
	}
}
