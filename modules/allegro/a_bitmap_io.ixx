export module allegro:bitmap.io;

import <string>;
import <allegro5/bitmap_io.h>;
import :base;
import :bitmap;
import :file;

using loader_func_t = ALLEGRO::BITMAP_DATA* (*)(const char* filename, int32_t flags);
using fs_loader_func_t = ALLEGRO::BITMAP_DATA * (*)(ALLEGRO::FILE_DATA* fp, int32_t flags);
using saver_func_t = bool (*)(const char* filename, ALLEGRO::BITMAP_DATA* bitmap);
using fs_saver_func_t = bool (*)(ALLEGRO::FILE_DATA* fp, ALLEGRO::BITMAP_DATA* bitmap);
using identifier_func_t = bool (*)(ALLEGRO::FILE_DATA* f);

namespace ALLEGRO
{
	export enum
	{
		BITMAP_KEEP_BITMAP_FORMAT = ::ALLEGRO_KEEP_BITMAP_FORMAT,
		BITMAP_NO_PREMULTIPLIED_ALPHA = ::ALLEGRO_NO_PREMULTIPLIED_ALPHA,
		BITMAP_KEEP_INDEX = ::ALLEGRO_KEEP_INDEX
	};

	export using IIO_LOADER_FUNCTION = void* (*)(const char* filename, int32_t flags);
	export using IIO_FS_LOADER_FUNCTION = void* (*)(ALLEGRO::FILE_DATA* fp, int32_t flags);
	export using IIO_SAVER_FUNCTION = bool (*)(const char* filename, void* bitmap);
	export using IIO_FS_SAVER_FUNCTION = bool (*)(ALLEGRO::FILE_DATA* fp, void* bitmap);
	export using IIO_IDENTIFIER_FUNCTION = bool (*)(ALLEGRO::FILE_DATA* f);
}

namespace al
{
	export inline bool register_bitmap_loader(const char* ext, ALLEGRO::IIO_LOADER_FUNCTION loader)
	{
		return al_register_bitmap_loader(ext, (loader_func_t)loader);
	}

	export inline bool register_bitmap_saver(const char* ext, ALLEGRO::IIO_SAVER_FUNCTION saver)
	{
		return al_register_bitmap_saver(ext, (saver_func_t)saver);
	}

	export inline bool register_bitmap_loader_f(const std::string& ext, ALLEGRO::IIO_FS_LOADER_FUNCTION loader)
	{
		return al_register_bitmap_loader_f(ext.c_str(), (fs_loader_func_t)loader);
	}

	export inline bool register_bitmap_saver_f(const std::string& ext, ALLEGRO::IIO_FS_SAVER_FUNCTION saver)
	{
		return al_register_bitmap_saver_f(ext.c_str(), (fs_saver_func_t)saver);
	}

	export inline bool register_bitmap_identifier(const std::string& ext, ALLEGRO::IIO_IDENTIFIER_FUNCTION identifier)
	{
		return al_register_bitmap_identifier(ext.c_str(), (identifier_func_t)identifier);
	}

	export inline ALLEGRO::BITMAP load_bitmap(const std::string& filename)
	{
		return ALLEGRO::BITMAP(al_load_bitmap(filename.c_str()), internal::destroy_bitmap);
	}

	export inline ALLEGRO::BITMAP load_bitmap_flags(const std::string& filename, int32_t flags)
	{
		return ALLEGRO::BITMAP(al_load_bitmap_flags(filename.c_str(), flags), internal::destroy_bitmap);
	}

	export inline ALLEGRO::BITMAP load_bitmap_f(ALLEGRO::FILE_DATA* fp, const std::string& ident)
	{
		return ALLEGRO::BITMAP(al_load_bitmap_f(fp, ident.c_str()), internal::destroy_bitmap);
	}

	export inline ALLEGRO::BITMAP load_bitmap_flags_f(ALLEGRO::FILE_DATA* fp, const std::string& ident, int32_t flags)
	{
		return ALLEGRO::BITMAP(al_load_bitmap_flags_f(fp, ident.c_str(), flags), internal::destroy_bitmap);
	}

	export inline bool save_bitmap(const std::string& filename, const ALLEGRO::BITMAP& bitmap)
	{
		return al_save_bitmap(filename.c_str(), bitmap.get());
	}

	export inline bool save_bitmap_f(ALLEGRO::FILE_DATA* fp, const std::string& ident, const ALLEGRO::BITMAP& bitmap)
	{
		return al_save_bitmap_f(fp, ident.c_str(), bitmap.get());
	}

	export inline std::string identify_bitmap_f(ALLEGRO::FILE_DATA* fp)
	{
		return al_identify_bitmap_f(fp);
	}

	export inline std::string identify_bitmap(char const* filename)
	{
		return al_identify_bitmap(filename);
	}
}
