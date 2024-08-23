export module allegro:file;

import <string>;
import <memory>;
import <cstdarg>;
import <allegro5/file.h>;
import :base;
import :utf8;
import :path;
import :memory;

namespace ALLEGRO
{
	export using FILE_DATA = ALLEGRO_FILE;
	export using FILE = std::shared_ptr<FILE_DATA>;
	export using FILE_INTERFACE = ALLEGRO_FILE_INTERFACE;
	export using SEEK = ::ALLEGRO_SEEK;

	export enum
	{
		FILE_SEEK_SET = ::ALLEGRO_SEEK_SET,
		FILE_SEEK_CUR = ::ALLEGRO_SEEK_CUR,
		FILE_SEEK_END = ::ALLEGRO_SEEK_END
	};
}

namespace al
{
	namespace internal
	{
		export inline void destroy_file(ALLEGRO::FILE_DATA* file)
		{
			al_fclose(file);
		}
	}

	export inline ALLEGRO::FILE fopen(const char* path, const char* mode)
	{
		return ALLEGRO::FILE(al_fopen(path, mode), internal::destroy_file);
	}

	export inline ALLEGRO::FILE fopen_interface(const ALLEGRO::FILE_INTERFACE& vtable, const char* path, const char* mode)
	{
		return ALLEGRO::FILE(al_fopen_interface(&vtable, path, mode), internal::destroy_file);
	}

	export inline ALLEGRO::FILE create_file_handle(const ALLEGRO::FILE_INTERFACE& vtable, void* userdata)
	{
		return ALLEGRO::FILE(al_create_file_handle(&vtable, userdata), internal::destroy_file);
	}

	export inline size_t fread(ALLEGRO::FILE& file, void* ptr, size_t size)
	{
		return al_fread(file.get(), ptr, size);
	}

	export inline size_t fwrite(ALLEGRO::FILE& file, const void* ptr, size_t size)
	{
		return al_fwrite(file.get(), ptr, size);
	}

	export inline bool fflush(ALLEGRO::FILE& file)
	{
		return al_fflush(file.get());
	}

	export inline int64_t ftell(ALLEGRO::FILE& file)
	{
		return al_ftell(file.get());
	}

	export inline bool fseek(ALLEGRO::FILE& file, int64_t offset, int32_t whence)
	{
		return al_fseek(file.get(), offset, whence);
	}

	export inline bool feof(ALLEGRO::FILE& file)
	{
		return al_feof(file.get());
	}

	export inline int32_t ferror(ALLEGRO::FILE& file)
	{
		return al_ferror(file.get());
	}

	export inline const std::string ferrmsg(ALLEGRO::FILE& file)
	{
		return al_ferrmsg(file.get());
	}

	export inline void fclearerr(ALLEGRO::FILE& file)
	{
		return al_fclearerr(file.get());
	}

	export inline int32_t fungetc(ALLEGRO::FILE& file, int32_t c)
	{
		return al_fungetc(file.get(), c);
	}

	export inline int64_t fsize(ALLEGRO::FILE& file)
	{
		return al_fsize(file.get());
	}

	export inline int32_t fgetc(ALLEGRO::FILE& file)
	{
		return al_fgetc(file.get());
	}

	export inline int32_t fputc(ALLEGRO::FILE& file, int32_t c)
	{
		return al_fputc(file.get(), c);
	}

	export inline int16_t fread16le(ALLEGRO::FILE& file)
	{
		return al_fread16le(file.get());
	}

	export inline int16_t fread16be(ALLEGRO::FILE& file)
	{
		return al_fread16be(file.get());
	}

	export inline size_t fwrite16le(ALLEGRO::FILE& file, int16_t w)
	{
		return al_fwrite16le(file.get(), w);
	}

	export inline size_t fwrite16be(ALLEGRO::FILE& file, int16_t w)
	{
		return al_fwrite16be(file.get(), w);
	}

	export inline int32_t fread32le(ALLEGRO::FILE& file)
	{
		return al_fread32le(file.get());
	}

	export inline int32_t fread32be(ALLEGRO::FILE& file)
	{
		return al_fread32be(file.get());
	}

	export inline size_t fwrite32le(ALLEGRO::FILE& file, int32_t l)
	{
		return al_fwrite32le(file.get(), l);
	}

	export inline size_t fwrite32be(ALLEGRO::FILE& file, int32_t l)
	{
		return al_fwrite32be(file.get(), l);
	}

	export inline char* fgets(ALLEGRO::FILE& file, char* const buffer, size_t max)
	{
		return al_fgets(file.get(), buffer, max);
	}

	export inline ALLEGRO::USTRING fget_ustr(ALLEGRO::FILE& file)
	{
		return ALLEGRO::USTRING(al_fget_ustr(file.get()), al_ustr_free);
	}

	export inline int32_t fputs(ALLEGRO::FILE& file, const char* p)
	{
		return al_fputs(file.get(), p);
	}

	export inline int32_t fput_ustr(ALLEGRO::FILE& file, const ALLEGRO::USTRING& p)
	{
		return al_fputs(file.get(), al::cstr(p));
	}

	export inline int32_t fprintf(ALLEGRO::FILE& file, const char* format, ...)
	{
		int32_t result;
		va_list arglist;
		va_start(arglist, format);
		result = al_vfprintf(file.get(), format, arglist);
		va_end(arglist);
		return result;
	}

	export inline int32_t vfprintf(ALLEGRO::FILE& file, const char* format, va_list args)
	{
		return al_vfprintf(file.get(), format, args);
	}

	export inline ALLEGRO::FILE fopen_fd(int32_t fd, const char* mode)
	{
		return ALLEGRO::FILE(al_fopen_fd(fd, mode), internal::destroy_file);
	}

	export inline ALLEGRO::FILE make_temp_file(const char* filename_template, ALLEGRO::PATH& return_path)
	{
		ALLEGRO::FILE file;

		if (return_path)
		{
			ALLEGRO_PATH* path = return_path.get();
			file.reset(al_make_temp_file(filename_template, &path), internal::destroy_file);
			return_path.reset(path, internal::destroy_path);
		}

		return file;
	}

	export inline ALLEGRO::FILE fopen_slice(ALLEGRO::FILE& file, size_t initial_size, const char* mode)
	{
		return ALLEGRO::FILE(al_fopen_slice(file.get(), initial_size, mode), internal::destroy_file);
	}

	export inline const ALLEGRO::FILE_INTERFACE& get_new_file_interface()
	{
		return *al_get_new_file_interface();
	}

	export inline void set_new_file_interface(const ALLEGRO::FILE_INTERFACE& interface)
	{
		al_set_new_file_interface(&interface);
	}

	export inline void set_standard_file_interface()
	{
		al_set_standard_file_interface();
	}

	export inline void* get_file_userdata(ALLEGRO::FILE& file)
	{
		return al_get_file_userdata(file.get());
	}
}
