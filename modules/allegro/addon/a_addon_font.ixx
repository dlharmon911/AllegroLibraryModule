export module allegro.font_addon;

import <string>;
import <memory>;
import allegro;
import <cstdarg>;
import <allegro5/allegro_font.h>;

namespace ALLEGRO
{
	export using FONT_DATA = ALLEGRO_FONT;
	export using FONT_DATA_PTR = std::add_pointer<FONT_DATA>::type;
	export using FONT = std::shared_ptr<FONT_DATA>;

#ifdef ALLEGRO_GLYPH
	export using FONT_GLYPH = ALLEGRO_GLYPH;
#endif

	export enum
	{
		FLAG_NO_KERNING = ALLEGRO_NO_KERNING,
		FLAG_ALIGN_LEFT = ALLEGRO_ALIGN_LEFT,
		FLAG_ALIGN_CENTRE = ALLEGRO_ALIGN_CENTRE,
		FLAG_ALIGN_CENTER = ALLEGRO_ALIGN_CENTER,
		FLAG_ALIGN_RIGHT = ALLEGRO_ALIGN_RIGHT,
		FLAG_ALIGN_INTEGER = ALLEGRO_ALIGN_INTEGER,
		FLAG_NO_PREMULTIPLIED_ALPHA = ALLEGRO_NO_PREMULTIPLIED_ALPHA
	};
}

namespace al
{
	namespace font_addon
	{
		export inline auto init() -> bool
		{
			return al_init_font_addon();
		}

		export inline auto is_initialized() -> bool
		{
			return al_is_font_addon_initialized();
		}

		export inline auto shutdown() -> void
		{
			return al_shutdown_font_addon();
		}

		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_font_version();
		}
	}

	namespace internal
	{
		export inline auto destroy_font(ALLEGRO::FONT_DATA_PTR  data) -> void
		{
			al_destroy_font(data);
		}
	}

	export inline auto register_font_loader(const char* ext, ALLEGRO::FONT_DATA_PTR(*loader)(const char* filename, int32_t size, int32_t flags)) -> bool
	{
		return al_register_font_loader(ext, (ALLEGRO::FONT_DATA_PTR(*)(const char* filename, int32_t size, int32_t flags))loader);
	}

	export inline auto load_bitmap_font(const char* filename) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_load_bitmap_font(filename), internal::destroy_font);
	}

	export inline auto load_bitmap_font_flags(const char* filename, int32_t flags) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_load_bitmap_font_flags(filename, flags), internal::destroy_font);
	}

	export inline auto load_font(const char* filename, int32_t size, int32_t flags) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_load_font(filename, size, flags), internal::destroy_font);
	}

	export inline auto grab_font_from_bitmap(ALLEGRO::BITMAP& bmp, int32_t n, const int32_t ranges[]) -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_grab_font_from_bitmap((ALLEGRO::BITMAP_DATA_PTR)bmp.get(), n, ranges), internal::destroy_font);
	}

	export inline auto create_builtin_font() -> ALLEGRO::FONT
	{
		return ALLEGRO::FONT(al_create_builtin_font(), internal::destroy_font);
	}

	export inline auto draw_ustr(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float>& pos, int32_t flags, const ALLEGRO::USTRING& ustring) -> void
	{
		return al_draw_ustr((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, flags, (ALLEGRO::USTRING_DATA_PTR)ustring.get());
	}

	export inline auto draw_text(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float>& pos, int32_t flags, const char* text) -> void
	{
		return al_draw_text((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, flags, text);
	}

	export inline auto draw_justified_text(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, float x1, float x2, float y, float diff, int32_t flags, const char* text) -> void
	{
		return al_draw_justified_text((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, x1, x2, y, diff, flags, text);
	}

	export inline auto draw_justified_ustr(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, float x1, float x2, float y, float diff, int32_t flags, const ALLEGRO::USTRING& ustring) -> void
	{
		return al_draw_justified_ustr((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, x1, x2, y, diff, flags, (ALLEGRO::USTRING_DATA_PTR)ustring.get());
	}

	export inline auto draw_textf(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float>& pos, int32_t flags, const char* format, ...) -> void
	{
		va_list args;
		int32_t len;
		char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) // _vscprintf doesn't count
			+ 1; // terminating '\0'
		buffer = (char*)malloc(len * sizeof(char));

		if (NULL != buffer)
		{
			vsprintf_s(buffer, len, format, args);
			al_draw_text((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, flags, buffer);
			free(buffer);
		}
		va_end(args);
	}

	export inline auto draw_justified_textf(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, float x1, float x2, float y, float diff, int32_t flags, const char* format, ...) -> void
	{
		va_list args;
		int32_t len;
		char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) // _vscprintf doesn't count
			+ 1; // terminating '\0'
		buffer = (char*)malloc(len * sizeof(char));

		if (NULL != buffer)
		{
			vsprintf_s(buffer, len, format, args);
			al_draw_justified_text((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, x1, x2, y, diff, flags, buffer);
			free(buffer);
		}
		va_end(args);
	}

	export inline auto get_text_width(const ALLEGRO::FONT& font, const char* str) -> int32_t
	{
		return al_get_text_width((ALLEGRO::FONT_DATA_PTR)font.get(), str);
	}

	export inline auto get_ustr_width(const ALLEGRO::FONT& font, const ALLEGRO::USTRING& ustring) -> int32_t
	{
		return al_get_ustr_width((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::USTRING_DATA_PTR)ustring.get());
	}

	export inline auto get_font_line_height(const ALLEGRO::FONT& font) -> int32_t
	{
		return al_get_font_line_height((ALLEGRO::FONT_DATA_PTR)font.get());
	}

	export inline auto get_font_ascent(const ALLEGRO::FONT& font) -> int32_t
	{
		return al_get_font_ascent((ALLEGRO::FONT_DATA_PTR)font.get());
	}

	export inline auto get_font_descent(const ALLEGRO::FONT& font) -> int32_t
	{
		return al_get_font_descent((ALLEGRO::FONT_DATA_PTR)font.get());
	}

	export inline auto get_ustr_dimensions(const ALLEGRO::FONT& font, const ALLEGRO::USTRING& ustring, ALLEGRO::BOX<int32_t>& box) -> void
	{
		return al_get_ustr_dimensions((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::USTRING_DATA_PTR)ustring.get(), &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}

	export inline auto get_text_dimensions(const ALLEGRO::FONT& font, const char* text, ALLEGRO::BOX<int32_t>& box) -> void
	{
		return al_get_text_dimensions((ALLEGRO::FONT_DATA_PTR)font.get(), text, &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}

	export inline auto get_font_ranges(ALLEGRO::FONT& font, int32_t ranges_count, int32_t* ranges) -> int32_t
	{
		return al_get_font_ranges((ALLEGRO::FONT_DATA_PTR)font.get(), ranges_count, ranges);
	}

	export inline auto draw_glyph(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float>& pos, int32_t codepoint) -> void
	{
		al_draw_glyph((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, codepoint);
	}

	export inline auto get_glyph_width(const ALLEGRO::FONT& font, int32_t codepoint) -> int32_t
	{
		return al_get_glyph_width((ALLEGRO::FONT_DATA_PTR)font.get(), codepoint);
	}

	export inline auto get_glyph_dimensions(const ALLEGRO::FONT& font, int32_t codepoint, ALLEGRO::BOX<int32_t>& box) -> bool
	{
		return al_get_glyph_dimensions((ALLEGRO::FONT_DATA_PTR)font.get(), codepoint, &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}

	export inline auto get_glyph_advance(const ALLEGRO::FONT& font, int32_t codepoint1, int32_t codepoint2) -> int32_t
	{
		return al_get_glyph_advance((ALLEGRO::FONT_DATA_PTR)font.get(), codepoint1, codepoint2);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_FONT_SRC)
	export inline auto get_glyph(const ALLEGRO::FONT& font, int32_t prev_codepoint, int32_t codepoint, ALLEGRO_GLYPH& glyph) -> bool
	{
		return al_get_glyph(font.get(), prev_codepoint, codepoint, &glyph);
	}
#endif

	export inline auto draw_multiline_text(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float>& pos, float max_width, float line_height, int32_t flags, const char* text) -> void
	{
		al_draw_multiline_text((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, max_width, line_height, flags, text);
	}

	export inline auto draw_multiline_textf(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float>& pos, float max_width, float line_height, int32_t flags, const char* format, ...) -> void
	{
		va_list args;
		int32_t len;
		char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) // _vscprintf doesn't count
			+ 1; // terminating '\0'
		buffer = (char*)malloc(len * sizeof(char));

		if (NULL != buffer)
		{
			vsprintf_s(buffer, len, format, args);
			al_draw_multiline_text((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, max_width, line_height, flags, buffer);
			free(buffer);
		}
		va_end(args);
	}

	export inline auto draw_multiline_ustr(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float>& pos, float max_width, float line_height, int32_t flags, const ALLEGRO::USTRING& ustring) -> void
	{
		al_draw_multiline_ustr((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, max_width, line_height, flags, (ALLEGRO::USTRING_DATA_PTR)ustring.get());
	}

	export inline auto do_multiline_text(const ALLEGRO::FONT& font, float max_width, const char* text, bool (*callback)(int32_t line_num, const char* line, int32_t size, void* extra), void* extra) -> void
	{
		al_do_multiline_text((ALLEGRO::FONT_DATA_PTR)font.get(), max_width, text, (bool(*)(int32_t line_num, const char* line, int32_t size, void* extra))callback, extra);
	}

	export inline auto do_multiline_ustr(const ALLEGRO::FONT& font, float max_width, const ALLEGRO::USTRING& ustring, bool (*callback)(int32_t line_num, const ALLEGRO::USTRING_DATA_PTR line, void* extra), void* extra) -> void
	{
		al_do_multiline_ustr((ALLEGRO::FONT_DATA_PTR)font.get(), max_width, (ALLEGRO::USTRING_DATA_PTR)ustring.get(), (bool (*)(int32_t line_num, const ALLEGRO::USTRING_DATA * line, void* extra))callback, extra);
	}

	export inline auto set_fallback_font(ALLEGRO::FONT& font, ALLEGRO::FONT& fallback) -> void
	{
		al_set_fallback_font((ALLEGRO::FONT_DATA_PTR)font.get(), (ALLEGRO::FONT_DATA_PTR)fallback.get());
	}

	export inline auto get_fallback_font(ALLEGRO::FONT& font) -> ALLEGRO::FONT
	{
		ALLEGRO::FONT(al_get_fallback_font((ALLEGRO::FONT_DATA_PTR)font.get()), internal::deleter_empty<ALLEGRO::FONT_DATA>);
	}

#ifdef ALLEGRO_GLYPH
	export inline auto get_glyph() -> uint32_t
	{
		return al_get_glyph();
	}
#endif
}