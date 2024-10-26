export module allegro:bitmap.io;

import <string>;
import <allegro5/bitmap_io.h>;
import :base;
import :bitmap;
import :file;

using loader_func_t = auto (*)(const char* filename, int32_t flags) -> ALLEGRO::BITMAP_DATA*;
using fs_loader_func_t = auto (*)(ALLEGRO::FILE_DATA* file, int32_t flags) -> ALLEGRO::BITMAP_DATA*;
using saver_func_t = auto (*)(const char* filename, ALLEGRO::BITMAP_DATA* bitmap) -> bool;
using fs_saver_func_t = auto (*)(ALLEGRO::FILE_DATA* file, ALLEGRO::BITMAP_DATA* bitmap) -> bool;
using identifier_func_t = auto (*)(ALLEGRO::FILE_DATA* f) -> bool;

namespace ALLEGRO
{
	export enum
	{
		BITMAP_KEEP_BITMAP_FORMAT = ::ALLEGRO_KEEP_BITMAP_FORMAT,
		BITMAP_NO_PREMULTIPLIED_ALPHA = ::ALLEGRO_NO_PREMULTIPLIED_ALPHA,
		BITMAP_KEEP_INDEX = ::ALLEGRO_KEEP_INDEX
	};

	export using IIO_LOADER_FUNCTION = auto (*)(const char* filename, int32_t flags) -> void*;
	export using IIO_FS_LOADER_FUNCTION = auto (*)(ALLEGRO::FILE_DATA* file, int32_t flags) -> void*;
	export using IIO_SAVER_FUNCTION = auto (*)(const char* filename, void* bitmap) -> bool;
	export using IIO_FS_SAVER_FUNCTION = auto (*)(ALLEGRO::FILE_DATA* file, void* bitmap) -> bool;
	export using IIO_IDENTIFIER_FUNCTION = auto (*)(ALLEGRO::FILE_DATA* f) -> bool;
}

namespace al
{
	export inline auto register_bitmap_loader(const char* ext, ALLEGRO::IIO_LOADER_FUNCTION loader) -> bool
	{
		return al_register_bitmap_loader(ext, (loader_func_t)loader);
	}

	export inline auto register_bitmap_saver(const char* ext, ALLEGRO::IIO_SAVER_FUNCTION saver) -> bool
	{
		return al_register_bitmap_saver(ext, (saver_func_t)saver);
	}

	export inline auto register_bitmap_loader_f(const char* ext, ALLEGRO::IIO_FS_LOADER_FUNCTION loader) -> bool
	{
		return al_register_bitmap_loader_f(ext, (fs_loader_func_t)loader);
	}

	export inline auto register_bitmap_saver_f(const char* ext, ALLEGRO::IIO_FS_SAVER_FUNCTION saver) -> bool
	{
		return al_register_bitmap_saver_f(ext, (fs_saver_func_t)saver);
	}

	export inline auto register_bitmap_identifier(const char* ext, ALLEGRO::IIO_IDENTIFIER_FUNCTION identifier) -> bool
	{
		return al_register_bitmap_identifier(ext, (identifier_func_t)identifier);
	}

	export inline auto load_bitmap(const char* filename) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_load_bitmap(filename), internal::destroy_bitmap);
	}

	export inline auto load_bitmap_flags(const char* filename, int32_t flags) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_load_bitmap_flags(filename, flags), internal::destroy_bitmap);
	}

	export inline auto load_bitmap_f(const ALLEGRO::FILE& file, const char* ident) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_load_bitmap_f((ALLEGRO::FILE_DATA*)file.get(), ident), internal::destroy_bitmap);
	}

	export inline auto load_bitmap_flags_f(const ALLEGRO::FILE& file, const char* ident, int32_t flags) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_load_bitmap_flags_f((ALLEGRO::FILE_DATA*)file.get(), ident, flags), internal::destroy_bitmap);
	}

	export inline auto save_bitmap(const char* filename, const ALLEGRO::BITMAP& bitmap) -> bool
	{
		return al_save_bitmap(filename, (ALLEGRO::BITMAP_DATA*)bitmap.get());
	}

	export inline auto save_bitmap_f(const ALLEGRO::FILE& file, const char* ident, const ALLEGRO::BITMAP& bitmap) -> bool
	{
		return al_save_bitmap_f((ALLEGRO::FILE_DATA*)file.get(), ident, (ALLEGRO::BITMAP_DATA*)bitmap.get());
	}

	export inline auto identify_bitmap_f(const ALLEGRO::FILE& file) -> const char*
	{
		return al_identify_bitmap_f((ALLEGRO::FILE_DATA*)file.get());
	}

	export inline auto identify_bitmap(const char* filename) -> const char*
	{
		return al_identify_bitmap(filename);
	}
}
