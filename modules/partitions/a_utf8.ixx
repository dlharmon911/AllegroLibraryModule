module;

export module allegro:utf8;

import std;
import <cstdarg>;
import <cstdio>;
import <allegro5/utf8.h>;
import :base;
import :color;
import :memory;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using USTRING_DATA = typename ALLEGRO_USTR;
		export using USTRING_DATA_PTR = std::add_pointer<USTRING_DATA>::type;
	}

	export using USTRING = typename std::shared_ptr<INTERNAL::USTRING_DATA>;
}

namespace al
{
	namespace internal
	{
		export inline auto ustr_free(ALLEGRO::INTERNAL::USTRING_DATA_PTR data) -> void
		{
			al_ustr_free(data);
		}
	}

	inline auto make_const_ustring(const ALLEGRO::INTERNAL::USTRING_DATA_PTR data) -> const ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(const_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(data), internal::deleter_empty<ALLEGRO::INTERNAL::USTRING_DATA>);
	}

	export inline auto ustr_new(const char* string) -> ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(al_ustr_new(string), al_ustr_free);
	}

	export inline auto ustr_new_from_buffer(const char* string, size_t size) -> ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(al_ustr_new_from_buffer(string, size), al_ustr_free);
	}

	export inline auto ustr_newf(const char* format, ...) -> ALLEGRO::USTRING
	{
		ALLEGRO::USTRING ustring{ ustr_new((const char*)"") };
		bool result;
		va_list arglist;

		va_start(arglist, format);
		result = al_ustr_vappendf(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), format, arglist);
		va_end(arglist);

		if (!result)
		{
			ustring.reset();
		}

		return ustring;
	}

	export inline auto c_str(const ALLEGRO::USTRING& ustring) -> const char*
	{
		return (const char*)al_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_to_buffer(const ALLEGRO::USTRING& ustring, char* buffer, int32_t size) -> void
	{
		al_ustr_to_buffer(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), buffer, size);
	}

	export inline auto cstr_dup(const ALLEGRO::USTRING& ustring) -> char*
	{
		return al_cstr_dup(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_dup(const ALLEGRO::USTRING& ustring) -> ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(al_ustr_dup(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get())), al_ustr_free);
	}

	export inline auto ustr_dup_substr(const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t end_pos) -> ALLEGRO::USTRING
	{
		ALLEGRO::INTERNAL::USTRING_DATA_PTR data{ al_ustr_dup_substr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, end_pos) };
		ALLEGRO::USTRING rv = ALLEGRO::USTRING(data, al_ustr_free);

		return rv;
	}

	export inline auto ustr_empty_string() -> const ALLEGRO::USTRING
	{
		return make_const_ustring(const_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(al_ustr_empty_string()));
	}

	export inline auto ref_cstr(ALLEGRO_USTR_INFO& info, const char* s) -> const ALLEGRO::USTRING
	{
		return make_const_ustring(const_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(al_ref_cstr(&info, s)));
	}

	export inline auto ref_buffer(ALLEGRO_USTR_INFO& info, const char* s, size_t size) -> const ALLEGRO::USTRING
	{
		return make_const_ustring(const_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(al_ref_buffer(&info, s, size)));
	}

	export inline auto ref_ustr(ALLEGRO_USTR_INFO& info, const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t end_pos) -> const ALLEGRO::USTRING
	{
		return make_const_ustring(const_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(al_ref_ustr(&info, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, end_pos)));
	}

	export inline auto ref_info(const ALLEGRO_USTR_INFO& info) -> const ALLEGRO::USTRING
	{
		return make_const_ustring(const_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(&info));
	}

	export inline auto ustr_size(const ALLEGRO::USTRING& ustring) -> size_t
	{
		return al_ustr_size(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_length(const ALLEGRO::USTRING& ustring) -> size_t
	{
		return al_ustr_length(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_offset(const ALLEGRO::USTRING& ustring, int32_t index) -> int32_t
	{
		return al_ustr_offset(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), index);
	}

	export inline auto ustr_next(const ALLEGRO::USTRING& ustring, int32_t& pos) -> bool
	{
		return al_ustr_next(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), &pos);
	}

	export inline auto ustr_prev(const ALLEGRO::USTRING& ustring, int32_t& pos) -> bool
	{
		return al_ustr_prev(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), &pos);
	}

	export inline auto ustr_get(const ALLEGRO::USTRING& ustring, int32_t pos) -> int32_t
	{
		return al_ustr_get(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), pos);
	}

	export inline auto ustr_get_next(const ALLEGRO::USTRING& ustring, int32_t& pos) -> int32_t
	{
		return al_ustr_get_next(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), &pos);
	}

	export inline auto ustr_prev_get(const ALLEGRO::USTRING& ustring, int32_t& pos) -> int32_t
	{
		return al_ustr_prev_get(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), &pos);
	}

	export inline auto ustr_insert(ALLEGRO::USTRING& ustring1, int32_t pos, const ALLEGRO::USTRING& ustring2) -> bool
	{
		return al_ustr_insert(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), pos, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_insert_cstr(ALLEGRO::USTRING& ustring, int32_t pos, const char* string) -> bool
	{
		return al_ustr_insert_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), pos, string);
	}

	export inline auto ustr_insert_chr(ALLEGRO::USTRING& ustring, int32_t pos, int32_t c) -> size_t
	{
		return al_ustr_insert_chr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), pos, c);
	}

	export inline auto ustr_append(ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2) -> bool
	{
		return al_ustr_append(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_append_cstr(ALLEGRO::USTRING& ustring, const char* string) -> bool
	{
		return al_ustr_append_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), string);
	}

	export inline auto ustr_append_chr(ALLEGRO::USTRING& ustring, int32_t c) -> size_t
	{
		return al_ustr_append_chr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), c);
	}

	export inline auto ustr_appendf(ALLEGRO::USTRING& ustring, const char* format, ...) -> bool
	{
		bool result;
		va_list arglist;
		va_start(arglist, format);
		result = al_ustr_vappendf(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), format, arglist);
		va_end(arglist);
		return result;
	}

	export inline auto ustr_vappendf(ALLEGRO::USTRING& ustring, const char* format, va_list ap) -> bool
	{
		return al_ustr_vappendf(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), format, ap);
	}

	export inline auto ustr_remove_chr(ALLEGRO::USTRING& ustring, int32_t pos) -> bool
	{
		return al_ustr_remove_chr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), pos);
	}

	export inline auto ustr_remove_range(ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t end_pos) -> bool
	{
		return al_ustr_remove_range(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, end_pos);
	}

	export inline auto ustr_truncate(ALLEGRO::USTRING& ustring, int32_t start_pos) -> bool
	{
		return al_ustr_truncate(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos);
	}

	export inline auto ustr_ltrim_ws(ALLEGRO::USTRING& ustring) -> bool
	{
		return al_ustr_ltrim_ws(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_rtrim_ws(ALLEGRO::USTRING& ustring) -> bool
	{
		return al_ustr_rtrim_ws(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_trim_ws(ALLEGRO::USTRING& ustring) -> bool
	{
		return al_ustr_trim_ws(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_assign(ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2) -> bool
	{
		return al_ustr_assign(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_assign_substr(ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2, int32_t start_pos, int32_t end_pos) -> bool
	{
		return al_ustr_assign_substr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()), start_pos, end_pos);
	}

	export inline auto ustr_assign_cstr(ALLEGRO::USTRING& ustring, const char* string) -> bool
	{
		return al_ustr_assign_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), string);
	}

	export inline auto ustr_set_chr(ALLEGRO::USTRING& ustring, int32_t pos, int32_t c) -> size_t
	{
		return al_ustr_set_chr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), pos, c);
	}

	export inline auto ustr_replace_range(ALLEGRO::USTRING& ustring1, int32_t start_pos1, int32_t end_pos1, const ALLEGRO::USTRING& ustring2) -> bool
	{
		return al_ustr_replace_range(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), start_pos1, end_pos1, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_find_chr(const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t c) -> int32_t
	{
		return al_ustr_find_chr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, c);
	}

	export inline auto ustr_rfind_chr(const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t c) -> int32_t
	{
		return al_ustr_rfind_chr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, c);
	}

	export inline auto ustr_find_set(const ALLEGRO::USTRING& ustring, int32_t start_pos, const ALLEGRO::USTRING& accept) -> int32_t
	{
		return al_ustr_find_set(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(accept.get()));
	}

	export inline auto ustr_find_set_cstr(const ALLEGRO::USTRING& ustring, int32_t start_pos, const char* accept) -> int32_t
	{
		return al_ustr_find_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, accept);
	}

	export inline auto ustr_find_cset(const ALLEGRO::USTRING& ustring, int32_t start_pos, const ALLEGRO::USTRING& reject) -> int32_t
	{
		return al_ustr_find_cset(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(reject.get()));
	}

	export inline auto ustr_find_cset_cstr(const ALLEGRO::USTRING& ustring, int32_t start_pos, const char* reject) -> int32_t
	{
		return al_ustr_find_cset_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, reject);
	}

	export inline auto ustr_find_str(const ALLEGRO::USTRING& haystack, int32_t start_pos, const ALLEGRO::USTRING& needle) -> int32_t
	{
		return al_ustr_find_str(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(haystack.get()), start_pos, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(needle.get()));
	}

	export inline auto ustr_find_cstr(const ALLEGRO::USTRING& haystack, int32_t start_pos, const char* needle) -> int32_t
	{
		return al_ustr_find_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(haystack.get()), start_pos, needle);
	}

	export inline auto ustr_rfind_str(const ALLEGRO::USTRING& haystack, int32_t start_pos, const ALLEGRO::USTRING& needle) -> int32_t
	{
		return al_ustr_rfind_str(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(haystack.get()), start_pos, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(needle.get()));
	}

	export inline auto ustr_rfind_cstr(const ALLEGRO::USTRING& haystack, int32_t start_pos, const char* needle) -> int32_t
	{
		return al_ustr_rfind_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(haystack.get()), start_pos, needle);
	}

	export inline auto ustr_find_replace(ALLEGRO::USTRING& ustring, int32_t start_pos, const ALLEGRO::USTRING& find, const ALLEGRO::USTRING& replace) -> bool
	{
		return al_ustr_find_replace(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(find.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(replace.get()));
	}

	export inline auto ustr_find_replace_cstr(ALLEGRO::USTRING& ustring, int32_t start_pos, const char* find, const char* replace) -> bool
	{
		return al_ustr_find_replace_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), start_pos, find, replace);
	}

	export inline auto ustr_equal(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2) -> bool
	{
		return al_ustr_equal(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_compare(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2) -> int32_t
	{
		return al_ustr_compare(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_ncompare(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2, int32_t n) -> int32_t
	{
		return al_ustr_ncompare(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()), n);
	}

	export inline auto ustr_has_prefix(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2) -> bool
	{
		return al_ustr_has_prefix(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_has_prefix_cstr(const ALLEGRO::USTRING& ustring, const char* string) -> bool
	{
		return al_ustr_has_prefix_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), string);
	}

	export inline auto ustr_has_suffix(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2) -> bool
	{
		return al_ustr_has_suffix(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring1.get()), static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring2.get()));
	}

	export inline auto ustr_has_suffix_cstr(const ALLEGRO::USTRING& ustring, const char* string) -> bool
	{
		return al_ustr_has_suffix_cstr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), string);
	}

	export inline auto utf8_width(int32_t c) -> size_t
	{
		return al_utf8_width(c);
	}

	export inline auto utf8_encode(char s[], int32_t c) -> size_t
	{
		return al_utf8_encode(s, c);
	}

	export inline auto ustr_new_from_utf16(uint16_t const* s) -> ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(al_ustr_new_from_utf16(s), al_ustr_free);
	}

	export inline auto ustr_size_utf16(const ALLEGRO::USTRING& ustring) -> size_t
	{
		return al_ustr_size_utf16(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()));
	}

	export inline auto ustr_encode_utf16(const ALLEGRO::USTRING& ustring, uint16_t* s, size_t n) -> size_t
	{
		return al_ustr_encode_utf16(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(ustring.get()), s, n);
	}

	export inline auto utf16_width(int32_t c) -> size_t
	{
		return al_utf16_width(c);
	}

	export inline auto utf16_encode(uint16_t s[], int32_t c) -> size_t
	{
		return al_utf16_encode(s, c);
	}

	export inline auto create_ustring_from_char(int32_t c) -> ALLEGRO::USTRING
	{
		ALLEGRO::USTRING u(al_ustr_dup(al_ustr_empty_string()), al_ustr_free);

		if (u)
		{
			if (al_ustr_append_chr(static_cast<ALLEGRO::INTERNAL::USTRING_DATA_PTR>(u.get()), c) == 0)
			{
				u.reset();
			}
		}

		return u;
	}

	export inline auto create_ustring_from_string(const char* string) -> ALLEGRO::USTRING
	{
		return ALLEGRO::USTRING(al_ustr_new(string), al_ustr_free);
	}

	static auto ustr_get_char_size(int32_t c) -> size_t
	{
		static const int32_t MinimumValue = 0;
		static const int32_t MaximumValue = 0x10ffff;

		if (c >= MinimumValue && c <= MaximumValue)
		{
			if (c <= 0x007f) return 1;
			if (c <= 0x07ff) return 2;
			if (c <= 0xffff) return 3;

			return 4;
		}

		return 0;
	}
}

namespace std
{
	export template <> struct hash<ALLEGRO::USTRING>
	{
	public:
		auto operator ()(const ALLEGRO::USTRING& str) const -> std::size_t
		{
			if (!str)
			{
				return 0;
			}

			return std::hash<const char*>{}((const char*)al::c_str(str));
		}
	};
}

export template <class E, class TR = std::char_traits<E>>
std::basic_ostream<E, TR>& operator << (std::basic_ostream<E, TR>& stream, const ALLEGRO::USTRING& str)
{
	if (str)
	{
		stream.write(al_cstr(str.get()), al_ustr_size(str.get()));
	}

	return stream;
}

export template <class E, class TR = std::char_traits<E>>
std::basic_istream<E, TR>& operator >> (std::basic_istream<E, TR>& stream, ALLEGRO::USTRING& str)
{
	str.reset(al_ustr_new(""), al_ustr_free);

	int32_t c = stream.get();

	while (c != 0)
	{
		if (c == ALLEGRO::FILE_EOF)
		{
			return stream;
		}

		size_t s = al::ustr_get_char_size(c);

		for (size_t i = 0; i < s; ++i)
		{
			al::ustr_append_chr(str, c);
			c = stream.get();
		}
	}

	return stream;
}
