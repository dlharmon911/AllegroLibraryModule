export module allegro.font_addon;

import <string>;
import <memory>;
import allegro;
import <cstdarg>;
import <allegro5/allegro_font.h>;

namespace ALLEGRO
{
	export using FONT_DATA = ALLEGRO_FONT;
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
		export inline bool init()
		{
			return al_init_font_addon();
		}

		export inline bool is_initialized()
		{
			return al_is_font_addon_initialized();
		}

		export inline void shutdown()
		{
			return al_shutdown_font_addon();
		}

		export inline uint32_t get_version()
		{
			return al_get_allegro_font_version();
		}
	}

	namespace internal
	{
		export inline void destroy_font(ALLEGRO::FONT_DATA* data)
		{
			al_destroy_font(data);
		}
	}

	export inline bool register_font_loader(const char* ext, ALLEGRO::FONT_DATA* (*loader)(const char* filename, int32_t size, int32_t flags))
	{
		return al_register_font_loader(ext, loader);
	}

	export inline ALLEGRO::FONT load_bitmap_font(const char* filename)
	{
		return ALLEGRO::FONT(al_load_bitmap_font(filename), internal::destroy_font);
	}

	export inline ALLEGRO::FONT load_bitmap_font_flags(const char* filename, int32_t flags)
	{
		return ALLEGRO::FONT(al_load_bitmap_font_flags(filename, flags), internal::destroy_font);
	}

	export inline ALLEGRO::FONT load_font(const char* filename, int32_t size, int32_t flags)
	{
		return ALLEGRO::FONT(al_load_font(filename, size, flags), internal::destroy_font);
	}

	export inline ALLEGRO::FONT grab_font_from_bitmap(ALLEGRO::BITMAP& bmp, int32_t n, const int32_t ranges[])
	{
		return ALLEGRO::FONT(al_grab_font_from_bitmap(bmp.get(), n, ranges), internal::destroy_font);
	}

	export inline ALLEGRO::FONT create_builtin_font()
	{
		return ALLEGRO::FONT(al_create_builtin_font(), internal::destroy_font);
	}

	export inline void draw_ustr(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float> pos, int32_t flags, const ALLEGRO::USTRING& ustring)
	{
		return al_draw_ustr(font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, flags, ustring.get());
	}

	export inline void draw_text(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float> pos, int32_t flags, const char* text)
	{
		return al_draw_text(font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, flags, text);
	}

	export inline void draw_justified_text(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, float x1, float x2, float y, float diff, int32_t flags, const char* text)
	{
		return al_draw_justified_text(font.get(), (ALLEGRO::COLOR_DATA)color, x1, x2, y, diff, flags, text);
	}

	export inline void draw_justified_ustr(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, float x1, float x2, float y, float diff, int32_t flags, const ALLEGRO::USTRING& ustring)
	{
		return al_draw_justified_ustr(font.get(), (ALLEGRO::COLOR_DATA)color, x1, x2, y, diff, flags, ustring.get());
	}

	export inline void draw_textf(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float> pos, int32_t flags, char const* format, ...)
	{
		va_list args;
		int len;
		char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) // _vscprintf doesn't count
			+ 1; // terminating '\0'
		buffer = (char*)malloc(len * sizeof(char));

		if (NULL != buffer)
		{
			vsprintf_s(buffer, len, format, args);
			al_draw_text(font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, flags, buffer);
			free(buffer);
		}
		va_end(args);
	}

	export inline void draw_justified_textf(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, float x1, float x2, float y, float diff, int32_t flags, char const* format, ...)
	{
		va_list args;
		int len;
		char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) // _vscprintf doesn't count
			+ 1; // terminating '\0'
		buffer = (char*)malloc(len * sizeof(char));

		if (NULL != buffer)
		{
			vsprintf_s(buffer, len, format, args);
			al_draw_justified_text(font.get(), (ALLEGRO::COLOR_DATA)color, x1, x2, y, diff, flags, buffer);
			free(buffer);
		}
		va_end(args);
	}

	export inline int32_t get_text_width(const ALLEGRO::FONT& font, const char* str)
	{
		return al_get_text_width(font.get(), str);
	}

	export inline int32_t get_ustr_width(const ALLEGRO::FONT& font, const ALLEGRO::USTRING& ustring)
	{
		return al_get_ustr_width(font.get(), ustring.get());
	}

	export inline int32_t get_font_line_height(const ALLEGRO::FONT& font)
	{
		return al_get_font_line_height(font.get());
	}

	export inline int32_t get_font_ascent(const ALLEGRO::FONT& font)
	{
		return al_get_font_ascent(font.get());
	}

	export inline int32_t get_font_descent(const ALLEGRO::FONT& font)
	{
		return al_get_font_descent(font.get());
	}

	export inline void get_ustr_dimensions(const ALLEGRO::FONT& font, const ALLEGRO::USTRING& ustring, ALLEGRO::BOX<int32_t>& box)
	{
		return al_get_ustr_dimensions(font.get(), ustring.get(), &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}

	export inline void get_text_dimensions(const ALLEGRO::FONT& font, const char* text, ALLEGRO::BOX<int32_t>& box)
	{
		return al_get_text_dimensions(font.get(), text, &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}

	export inline int32_t get_font_ranges(ALLEGRO::FONT& font, int32_t ranges_count, int32_t* ranges)
	{
		return al_get_font_ranges(font.get(), ranges_count, ranges);
	}

	export inline void draw_glyph(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float> pos, int32_t codepoint)
	{
		al_draw_glyph(font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, codepoint);
	}

	export inline int32_t get_glyph_width(const ALLEGRO::FONT& font, int32_t codepoint)
	{
		return al_get_glyph_width(font.get(), codepoint);
	}

	export inline bool get_glyph_dimensions(const ALLEGRO::FONT& font, int32_t codepoint, ALLEGRO::BOX<int32_t>& box)
	{
		return al_get_glyph_dimensions(font.get(), codepoint, &box.top_left.x, &box.top_left.y, &box.bottom_right.x, &box.bottom_right.y);
	}

	export inline int32_t get_glyph_advance(const ALLEGRO::FONT& font, int32_t codepoint1, int32_t codepoint2)
	{
		return al_get_glyph_advance(font.get(), codepoint1, codepoint2);
	}

#if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_FONT_SRC)
	export inline bool get_glyph(const ALLEGRO::FONT& font, int32_t prev_codepoint, int32_t codepoint, ALLEGRO_GLYPH& glyph)
	{
		return al_get_glyph(font.get(), prev_codepoint, codepoint, &glyph);
	}
#endif

	export inline void draw_multiline_text(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float> pos, float max_width, float line_height, int32_t flags, const char* text)
	{
		al_draw_multiline_text(font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, max_width, line_height, flags, text);
	}

	export inline void draw_multiline_textf(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float> pos, float max_width, float line_height, int32_t flags, const char* format, ...)
	{
		va_list args;
		int len;
		char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) // _vscprintf doesn't count
			+ 1; // terminating '\0'
		buffer = (char*)malloc(len * sizeof(char));

		if (NULL != buffer)
		{
			vsprintf_s(buffer, len, format, args);
			al_draw_multiline_text(font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, max_width, line_height, flags, buffer);
			free(buffer);
		}
		va_end(args);
	}
	export inline void draw_multiline_ustr(const ALLEGRO::FONT& font, ALLEGRO::COLOR color, const ALLEGRO::POINT<float> pos, float max_width, float line_height, int32_t flags, const ALLEGRO::USTRING& ustring)
	{
		al_draw_multiline_ustr(font.get(), (ALLEGRO::COLOR_DATA)color, pos.x, pos.y, max_width, line_height, flags, ustring.get());
	}

	export inline void do_multiline_text(const ALLEGRO::FONT& font, float max_width, const char* text, bool (*cb)(int32_t line_num, const char* line, int32_t size, void* extra), void* extra)
	{
		al_do_multiline_text(font.get(), max_width, text, cb, extra);
	}

	export inline void do_multiline_ustr(const ALLEGRO::FONT& font, float max_width, const ALLEGRO::USTRING& ustring, bool (*cb)(int32_t line_num, const ALLEGRO::USTRING_DATA* line, void* extra), void* extra)
	{
		al_do_multiline_ustr(font.get(), max_width, ustring.get(), cb, extra);
	}

	export inline void set_fallback_font(ALLEGRO::FONT& font, ALLEGRO::FONT& fallback)
	{
		al_set_fallback_font(font.get(), fallback.get());
	}

	export inline ALLEGRO::FONT get_fallback_font(ALLEGRO::FONT& font)
	{
		ALLEGRO::FONT(al_get_fallback_font(font.get()), internal::deleter_empty<ALLEGRO::FONT_DATA>);
	}

#ifdef ALLEGRO_GLYPH
	export inline uint32_t get_glyph()
	{
		return al_get_glyph();
	}
#endif
}

