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
	export using FILE = ALLEGRO::OBJECT_TYPE;
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
		return al_fread((ALLEGRO::FILE_DATA*)file.get(), ptr, size);
	}

	export inline size_t fwrite(ALLEGRO::FILE& file, const void* ptr, size_t size)
	{
		return al_fwrite((ALLEGRO::FILE_DATA*)file.get(), ptr, size);
	}

	export inline bool fflush(ALLEGRO::FILE& file)
	{
		return al_fflush((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline int64_t ftell(ALLEGRO::FILE& file)
	{
		return al_ftell((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline bool fseek(ALLEGRO::FILE& file, int64_t offset, int32_t whence)
	{
		return al_fseek((ALLEGRO::FILE_DATA*)file.get(), offset, whence);
	}

	export inline bool feof(ALLEGRO::FILE& file)
	{
		return al_feof((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline int32_t ferror(ALLEGRO::FILE& file)
	{
		return al_ferror((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline const char* ferrmsg(ALLEGRO::FILE& file)
	{
		return al_ferrmsg((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline void fclearerr(ALLEGRO::FILE& file)
	{
		return al_fclearerr((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline int32_t fungetc(ALLEGRO::FILE& file, int32_t c)
	{
		return al_fungetc((ALLEGRO::FILE_DATA*)file.get(), c);
	}

	export inline int64_t fsize(ALLEGRO::FILE& file)
	{
		return al_fsize((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline int32_t fgetc(ALLEGRO::FILE& file)
	{
		return al_fgetc((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline int32_t fputc(ALLEGRO::FILE& file, int32_t c)
	{
		return al_fputc((ALLEGRO::FILE_DATA*)file.get(), c);
	}

	export inline int16_t fread16le(ALLEGRO::FILE& file)
	{
		return al_fread16le((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline int16_t fread16be(ALLEGRO::FILE& file)
	{
		return al_fread16be((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline size_t fwrite16le(ALLEGRO::FILE& file, int16_t w)
	{
		return al_fwrite16le((ALLEGRO::FILE_DATA*)file.get(), w);
	}

	export inline size_t fwrite16be(ALLEGRO::FILE& file, int16_t w)
	{
		return al_fwrite16be((ALLEGRO::FILE_DATA*)file.get(), w);
	}

	export inline int32_t fread32le(ALLEGRO::FILE& file)
	{
		return al_fread32le((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline int32_t fread32be(ALLEGRO::FILE& file)
	{
		return al_fread32be((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline size_t fwrite32le(ALLEGRO::FILE& file, int32_t l)
	{
		return al_fwrite32le((ALLEGRO::FILE_DATA*)file.get(), l);
	}

	export inline size_t fwrite32be(ALLEGRO::FILE& file, int32_t l)
	{
		return al_fwrite32be((ALLEGRO::FILE_DATA*)file.get(), l);
	}

	export inline char* fgets(ALLEGRO::FILE& file, char* const buffer, size_t max)
	{
		return al_fgets((ALLEGRO::FILE_DATA*)file.get(), buffer, max);
	}

	export inline ALLEGRO::USTRING fget_ustr(ALLEGRO::FILE& file)
	{
		return ALLEGRO::USTRING(al_fget_ustr((ALLEGRO::FILE_DATA*)file.get()), al_ustr_free);
	}

	export inline int32_t fputs(ALLEGRO::FILE& file, const char* p)
	{
		return al_fputs((ALLEGRO::FILE_DATA*)file.get(), p);
	}

	export inline size_t fput_ustr(ALLEGRO::FILE& file, const ALLEGRO::USTRING& p)
	{
		return al_fwrite((ALLEGRO::FILE_DATA*)file.get(), (const void*)al::c_str(p), al::ustr_size(p));
	}

	export inline int32_t fprintf(ALLEGRO::FILE& file, const char* format, ...)
	{
		int32_t result;
		va_list arglist;
		va_start(arglist, format);
		result = al_vfprintf((ALLEGRO::FILE_DATA*)file.get(), format, arglist);
		va_end(arglist);
		return result;
	}

	export inline int32_t vfprintf(ALLEGRO::FILE& file, const char* format, va_list args)
	{
		return al_vfprintf((ALLEGRO::FILE_DATA*)file.get(), format, args);
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
			ALLEGRO_PATH* path = (ALLEGRO::PATH_DATA*)return_path.get();
			file.reset(al_make_temp_file(filename_template, &path), internal::destroy_file);
			return_path.reset(path, internal::destroy_path);
		}

		return file;
	}

	export inline ALLEGRO::FILE fopen_slice(ALLEGRO::FILE& file, size_t initial_size, const char* mode)
	{
		return ALLEGRO::FILE(al_fopen_slice((ALLEGRO::FILE_DATA*)file.get(), initial_size, mode), internal::destroy_file);
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
		return al_get_file_userdata((ALLEGRO::FILE_DATA*)file.get());
	}
}
