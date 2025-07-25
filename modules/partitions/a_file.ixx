export module allegro:file;

import std;
import <cstdarg>;
import <cstdio>;
import <allegro5/file.h>;
import :base;
import :utf8;
import :path;
import :memory;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using FILE_DATA = typename ALLEGRO_FILE;
		export using FILE_DATA_PTR = std::add_pointer<FILE_DATA>::type;
	}

	export using FILE = typename std::shared_ptr<INTERNAL::FILE_DATA>;
	export using FILE_INTERFACE = typename ALLEGRO_FILE_INTERFACE;
	export using FILE_SEEK = typename ALLEGRO_SEEK;

	export constexpr int32_t FILE_SEEK_SET{ ALLEGRO_SEEK_SET };
	export constexpr int32_t FILE_SEEK_CUR{ ALLEGRO_SEEK_CUR };
	export constexpr int32_t FILE_SEEK_END{ ALLEGRO_SEEK_END };
}

namespace al
{
	namespace internal
	{
		export inline auto fopen(const char* path, const char* mode) -> ALLEGRO::INTERNAL::FILE_DATA_PTR
		{
			return al_fopen(path, mode);
		}

		export inline auto destroy_file(ALLEGRO::INTERNAL::FILE_DATA_PTR file) -> void
		{
			al_fclose(file);
		}
	}

	export inline auto fopen(const char* path, const char* mode) -> ALLEGRO::FILE
	{
		return ALLEGRO::FILE(al_fopen(path, mode), internal::destroy_file);
	}

	export inline auto fopen_interface(const ALLEGRO::FILE_INTERFACE& vtable, const char* path, const char* mode) -> ALLEGRO::FILE
	{
		return ALLEGRO::FILE(al_fopen_interface(&vtable, path, mode), internal::destroy_file);
	}

	export inline auto create_file_handle(const ALLEGRO::FILE_INTERFACE& vtable, void* userdata) -> ALLEGRO::FILE
	{
		return ALLEGRO::FILE(al_create_file_handle(&vtable, userdata), internal::destroy_file);
	}

	export inline auto fread(const ALLEGRO::FILE& file, void* ptr, size_t size) -> size_t
	{
		return al_fread(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), ptr, size);
	}

	export inline auto fwrite(const ALLEGRO::FILE& file, const void* ptr, size_t size) -> size_t
	{
		return al_fwrite(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), ptr, size);
	}

	export inline auto fflush(const ALLEGRO::FILE& file) -> bool
	{
		return al_fflush(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto ftell(const ALLEGRO::FILE& file) -> int64_t
	{
		return al_ftell(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fseek(const ALLEGRO::FILE& file, int64_t offset, int32_t whence) -> bool
	{
		return al_fseek(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), offset, whence);
	}

	export inline auto feof(const ALLEGRO::FILE& file) -> bool
	{
		return al_feof(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto ferror(const ALLEGRO::FILE& file) -> int32_t
	{
		return al_ferror(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto ferrmsg(const ALLEGRO::FILE& file) -> const char*
	{
		return (const char*)al_ferrmsg(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fclearerr(const ALLEGRO::FILE& file) -> void
	{
		al_fclearerr(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fungetc(const ALLEGRO::FILE& file, int32_t c) -> int32_t
	{
		return al_fungetc(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), c);
	}

	export inline auto fsize(const ALLEGRO::FILE& file) -> int64_t
	{
		return al_fsize(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fgetc(const ALLEGRO::FILE& file) -> int32_t
	{
		return al_fgetc(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fputc(const ALLEGRO::FILE& file, int32_t c) -> int32_t
	{
		return al_fputc(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), c);
	}

	export inline auto fread16le(const ALLEGRO::FILE& file) -> int16_t
	{
		return al_fread16le(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fread16be(const ALLEGRO::FILE& file) -> int16_t
	{
		return al_fread16be(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fwrite16le(const ALLEGRO::FILE& file, int16_t w) -> size_t
	{
		return al_fwrite16le(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), w);
	}

	export inline auto fwrite16be(const ALLEGRO::FILE& file, int16_t w) -> size_t
	{
		return al_fwrite16be(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), w);
	}

	export inline auto fread32le(const ALLEGRO::FILE& file) -> int32_t
	{
		return al_fread32le(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fread32be(const ALLEGRO::FILE& file) -> int32_t
	{
		return al_fread32be(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto fwrite32le(const ALLEGRO::FILE& file, int32_t l) -> size_t
	{
		return al_fwrite32le(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), l);
	}

	export inline auto fwrite32be(const ALLEGRO::FILE& file, int32_t l) -> size_t
	{
		return al_fwrite32be(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), l);
	}

	export inline auto fgets(const ALLEGRO::FILE& file, char* buffer, size_t max) -> char*
	{
		return al_fgets(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), buffer, max);
	}

	export inline auto fget_ustr(const ALLEGRO::FILE& file) -> ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(al_fget_ustr(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get())), al_ustr_free);
	}

	export inline auto fputs(const ALLEGRO::FILE& file, const char* p) -> int32_t
	{
		return al_fputs(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), p);
	}

	export inline auto fput_ustr(const ALLEGRO::FILE& file, const ALLEGRO::USTRING& p) -> size_t
	{
		return al_fwrite(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), (const void*)al::c_str(p), al::ustr_size(p));
	}

	export inline auto fprintf(const ALLEGRO::FILE& file, const char* format, ...) -> int32_t
	{
		int32_t result{ -1 };
		va_list arglist{};

		va_start(arglist, format);
		result = al_vfprintf(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), format, arglist);
		va_end(arglist);
		return result;
	}

	export inline auto vfprintf(const ALLEGRO::FILE& file, const char* format, va_list args) -> int32_t
	{
		return al_vfprintf(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), format, args);
	}

	export inline auto fopen_fd(int32_t fd, const char* mode) -> ALLEGRO::FILE
	{
		return ALLEGRO::FILE(al_fopen_fd(fd, mode), internal::destroy_file);
	}

	export inline auto make_temp_file(const char* filename_template, ALLEGRO::PATH& return_path) -> ALLEGRO::FILE
	{
		ALLEGRO::FILE file{ nullptr };

		if (return_path)
		{
			ALLEGRO::INTERNAL::PATH_DATA_PTR path = (ALLEGRO::INTERNAL::PATH_DATA_PTR)return_path.get();
			file.reset(al_make_temp_file(filename_template, &path), internal::destroy_file);
			return_path.reset(path, internal::destroy_path);
		}

		return file;
	}

	export inline auto fopen_slice(const ALLEGRO::FILE& file, size_t initial_size, const char* mode) -> ALLEGRO::FILE
	{
		return ALLEGRO::FILE(al_fopen_slice(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), initial_size, mode), internal::destroy_file);
	}

	export inline auto get_new_file_interface() -> const ALLEGRO::FILE_INTERFACE&
	{
		return *al_get_new_file_interface();
	}

	export inline auto set_new_file_interface(const ALLEGRO::FILE_INTERFACE& interface) -> void
	{
		al_set_new_file_interface(&interface);
	}

	export inline auto set_standard_file_interface() -> void
	{
		al_set_standard_file_interface();
	}

	export inline auto get_file_userdata(const ALLEGRO::FILE& file) -> void*
	{
		return al_get_file_userdata(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}
}
