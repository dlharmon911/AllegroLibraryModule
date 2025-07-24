export module allegro:bitmap.io;

import std;
import <allegro5/bitmap_io.h>;
import :base;
import :bitmap;
import :file;

namespace ALLEGRO
{
	export constexpr int32_t BITMAP_KEEP_BITMAP_FORMAT{ ALLEGRO_KEEP_BITMAP_FORMAT };
	export constexpr int32_t BITMAP_NO_PREMULTIPLIED_ALPHA{ ALLEGRO_NO_PREMULTIPLIED_ALPHA };
	export constexpr int32_t BITMAP_KEEP_INDEX{ ALLEGRO_KEEP_INDEX };

	export using IIO_LOADER_FUNCTION = auto (const char* filename, int32_t flags)->ALLEGRO::INTERNAL::BITMAP_DATA_PTR;
	export using IIO_FS_LOADER_FUNCTION = auto (ALLEGRO::INTERNAL::FILE_DATA_PTR file, int32_t flags)->ALLEGRO::INTERNAL::BITMAP_DATA_PTR;
	export using IIO_SAVER_FUNCTION = auto (const char* filename, ALLEGRO::INTERNAL::BITMAP_DATA_PTR bitmap) -> bool;
	export using IIO_FS_SAVER_FUNCTION = auto (ALLEGRO::INTERNAL::FILE_DATA_PTR file, ALLEGRO::INTERNAL::BITMAP_DATA_PTR bitmap) -> bool;
	export using IIO_IDENTIFIER_FUNCTION = auto (ALLEGRO::INTERNAL::FILE_DATA_PTR f) -> bool;
}

namespace al
{
	export inline auto register_bitmap_loader(const char* ext, ALLEGRO::IIO_LOADER_FUNCTION* loader) -> bool
	{
		return al_register_bitmap_loader(ext, loader);
	}

	export inline auto register_bitmap_saver(const char* ext, ALLEGRO::IIO_SAVER_FUNCTION* saver) -> bool
	{
		return al_register_bitmap_saver(ext, saver);
	}

	export inline auto register_bitmap_loader_f(const char* ext, ALLEGRO::IIO_FS_LOADER_FUNCTION* loader) -> bool
	{
		return al_register_bitmap_loader_f(ext, loader);
	}

	export inline auto register_bitmap_saver_f(const char* ext, ALLEGRO::IIO_FS_SAVER_FUNCTION* saver) -> bool
	{
		return al_register_bitmap_saver_f(ext, saver);
	}

	export inline auto register_bitmap_identifier(const char* ext, ALLEGRO::IIO_IDENTIFIER_FUNCTION* identifier) -> bool
	{
		return al_register_bitmap_identifier(ext, identifier);
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
		return ALLEGRO::BITMAP(al_load_bitmap_f(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), ident), internal::destroy_bitmap);
	}

	export inline auto load_bitmap_flags_f(const ALLEGRO::FILE& file, const char* ident, int32_t flags) -> ALLEGRO::BITMAP
	{
		return ALLEGRO::BITMAP(al_load_bitmap_flags_f(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), ident, flags), internal::destroy_bitmap);
	}

	export inline auto save_bitmap(const char* filename, const ALLEGRO::BITMAP& bitmap) -> bool
	{
		return al_save_bitmap(filename, static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export inline auto save_bitmap_f(const ALLEGRO::FILE& file, const char* ident, const ALLEGRO::BITMAP& bitmap) -> bool
	{
		return al_save_bitmap_f(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), ident, static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(bitmap.get()));
	}

	export inline auto identify_bitmap_f(const ALLEGRO::FILE& file) -> const char*
	{
		return al_identify_bitmap_f(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()));
	}

	export inline auto identify_bitmap(const char* filename) -> const char*
	{
		return al_identify_bitmap(filename);
	}
}
