export module allegro:utf8;

import <string>;
import <memory>;
import <cstdarg>;
import <allegro5/utf8.h>;
import :base;
import :color;
import :memory;

namespace ALLEGRO
{
    export using USTRING_DATA = ::ALLEGRO_USTR;
    export using USTRING = std::shared_ptr<USTRING_DATA>;
}

namespace al
{
    const ALLEGRO::USTRING make_const_ustring(const ALLEGRO::USTRING_DATA* data)
    {
        return ALLEGRO::USTRING(const_cast<ALLEGRO::USTRING_DATA*>(data), internal::deleter_empty<ALLEGRO::USTRING_DATA>);
    }

	export inline ALLEGRO::USTRING ustr_new(const std::string& string)
	{
		return ALLEGRO::USTRING(al_ustr_new(string.c_str()), al_ustr_free);
	}

    export inline ALLEGRO::USTRING ustr_new_from_buffer(const std::string& string, size_t size)
    {
        return ALLEGRO::USTRING(al_ustr_new_from_buffer(string.c_str(), size), al_ustr_free);
    }

    export inline ALLEGRO::USTRING ustr_newf(const char* format, ...)
    {
        ALLEGRO::USTRING rv = ustr_new("");

        bool result;
        va_list arglist;
        va_start(arglist, format);
        result = al_ustr_vappendf(rv.get(), format, arglist);
        va_end(arglist);

        if (!result)
        {
            rv.reset();
        }

        return rv;
    }

    export inline const char* cstr(const ALLEGRO::USTRING& ustring)
    {
        return al_cstr(ustring.get());
    }

    export inline std::string str(const ALLEGRO::USTRING& ustring)
    {
        return std::string(al_cstr(ustring.get()));
    }

    export inline void ustr_to_buffer(const ALLEGRO::USTRING& ustring, char* buffer, int32_t size)
    {
        al_ustr_to_buffer(ustring.get(), buffer, size);
    }

    export inline std::string cstr_dup(const ALLEGRO::USTRING& ustring)
    {
        return std::string(al_cstr_dup(ustring.get()));
    }

    export inline ALLEGRO::USTRING ustr_dup(const ALLEGRO::USTRING& ustring)
    {
        return ALLEGRO::USTRING(al_ustr_dup(ustring.get()), al_ustr_free);
    }

    export inline ALLEGRO::USTRING ustr_dup_substr(const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t end_pos)
    {
        return ALLEGRO::USTRING(al_ustr_dup_substr(ustring.get(), start_pos, end_pos), al_ustr_free);
    }

    export inline const ALLEGRO::USTRING ustr_empty_string()
    {
        return make_const_ustring(al_ustr_empty_string());
    }

    export inline const ALLEGRO::USTRING ref_cstr(ALLEGRO_USTR_INFO& info, const char* s)
    {
        return make_const_ustring(al_ref_cstr(&info, s));
    }

    export inline const ALLEGRO::USTRING ref_buffer(ALLEGRO_USTR_INFO& info, const char* s, size_t size)
    {
        return make_const_ustring(al_ref_buffer(&info, s, size));
    }

    export inline const ALLEGRO::USTRING ref_ustr(ALLEGRO_USTR_INFO& info, const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t end_pos)
    {
        return make_const_ustring(al_ref_ustr(&info, ustring.get(), start_pos, end_pos));
    }

    export inline const ALLEGRO::USTRING ref_info(const ALLEGRO_USTR_INFO& info)
    {
        return make_const_ustring(&info);
    }

    export inline size_t ustr_size(const ALLEGRO::USTRING& ustring)
    {
        return al_ustr_size(ustring.get());
    }

    export inline size_t ustr_length(const ALLEGRO::USTRING& ustring)
    {
        return al_ustr_length(ustring.get());
    }

    export inline int32_t ustr_offset(const ALLEGRO::USTRING& ustring, int32_t index)
    {
        return al_ustr_offset(ustring.get(), index);
    }

    export inline bool ustr_next(const ALLEGRO::USTRING& ustring, int32_t& pos)
    {
        return al_ustr_next(ustring.get(), &pos);
    }

    export inline bool ustr_prev(const ALLEGRO::USTRING& ustring, int32_t& pos)
    {
        return al_ustr_prev(ustring.get(), &pos);
    }

    export inline int32_t ustr_get(const ALLEGRO::USTRING& ustring, int32_t pos)
    {
        return al_ustr_get(ustring.get(), pos);
    }

    export inline int32_t ustr_get_next(const ALLEGRO::USTRING& ustring, int32_t& pos)
    {
        return al_ustr_get_next(ustring.get(), &pos);
    }

    export inline int32_t ustr_prev_get(const ALLEGRO::USTRING& ustring, int32_t& pos)
    {
        return al_ustr_prev_get(ustring.get(), &pos);
    }

    export inline bool ustr_insert(ALLEGRO::USTRING& ustring1, int32_t pos, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_insert(ustring1.get(), pos, ustring2.get());
    }

    export inline bool ustr_insert_cstr(ALLEGRO::USTRING& ustring, int32_t pos, const std::string& string)
    {
        return al_ustr_insert_cstr(ustring.get(), pos, string.c_str());
    }

    export inline size_t ustr_insert_chr(ALLEGRO::USTRING& ustring, int32_t pos, int32_t c)
    {
        return al_ustr_insert_chr(ustring.get(), pos, c);
    }

    export inline bool ustr_append(ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_append(ustring1.get(), ustring2.get());
    }

    export inline bool ustr_append_cstr(ALLEGRO::USTRING& ustring, const std::string& string)
    {
        return al_ustr_append_cstr(ustring.get(), string.c_str());
    }

    export inline size_t ustr_append_chr(ALLEGRO::USTRING& ustring, int32_t c)
    {
        return al_ustr_append_chr(ustring.get(), c);
    }
    
    export inline bool ustr_appendf(ALLEGRO::USTRING& ustring, const char* format, ...)
    {
        bool result;
        va_list arglist;
        va_start(arglist, format);
        result = al_ustr_vappendf(ustring.get(), format, arglist);
        va_end(arglist);
        return result;
    }

    export inline bool ustr_vappendf(ALLEGRO::USTRING& ustring, const char* format, va_list ap)
    {
        return al_ustr_vappendf(ustring.get(), format, ap);
    }

    export inline bool ustr_remove_chr(ALLEGRO::USTRING& ustring, int32_t pos)
    {
        return al_ustr_remove_chr(ustring.get(), pos);
    }

    export inline bool ustr_remove_range(ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t end_pos)
    {
        return al_ustr_remove_range(ustring.get(), start_pos, end_pos);
    }

    export inline bool ustr_truncate(ALLEGRO::USTRING& ustring, int32_t start_pos)
    {
        return al_ustr_truncate(ustring.get(), start_pos);
    }

    export inline bool ustr_ltrim_ws(ALLEGRO::USTRING& ustring)
    {
        return al_ustr_ltrim_ws(ustring.get());
    }

    export inline bool ustr_rtrim_ws(ALLEGRO::USTRING& ustring)
    {
        return al_ustr_rtrim_ws(ustring.get());
    }

    export inline bool ustr_trim_ws(ALLEGRO::USTRING& ustring)
    {
        return al_ustr_trim_ws(ustring.get());
    }

    export inline bool ustr_assign(ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_assign(ustring1.get(), ustring2.get());
    }

    export inline bool ustr_assign_substr(ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2, int32_t start_pos, int32_t end_pos)
    {
        return al_ustr_assign_substr(ustring1.get(), ustring2.get(), start_pos, end_pos);
    }

    export inline bool ustr_assign_cstr(ALLEGRO::USTRING& ustring, const std::string& string)
    {
        return al_ustr_assign_cstr(ustring.get(), string.c_str());
    }

    export inline size_t ustr_set_chr(ALLEGRO::USTRING& ustring, int32_t pos, int32_t c)
    {
        return al_ustr_set_chr(ustring.get(), pos, c);
    }

    export inline bool ustr_replace_range(ALLEGRO::USTRING& ustring1, int32_t start_pos1, int32_t end_pos1, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_replace_range(ustring1.get(), start_pos1, end_pos1, ustring2.get());
    }

    export inline int32_t ustr_find_chr(const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t c)
    {
        return al_ustr_find_chr(ustring.get(), start_pos, c);
    }

    export inline int32_t ustr_rfind_chr(const ALLEGRO::USTRING& ustring, int32_t start_pos, int32_t c)
    {
        return al_ustr_rfind_chr(ustring.get(), start_pos, c);
    }

    export inline int32_t ustr_find_set(const ALLEGRO::USTRING& ustring, int32_t start_pos, const ALLEGRO::USTRING& accept)
    {
        return al_ustr_find_set(ustring.get(), start_pos, accept.get());
    }

    export inline int32_t ustr_find_set_cstr(const ALLEGRO::USTRING& ustring, int32_t start_pos, const std::string& accept)
    {
        return al_ustr_find_cstr(ustring.get(), start_pos, accept.c_str());
    }

    export inline int32_t ustr_find_cset(const ALLEGRO::USTRING& ustring, int32_t start_pos, const ALLEGRO::USTRING& reject)
    {
        return al_ustr_find_cset(ustring.get(), start_pos, reject.get());
    }

    export inline int32_t ustr_find_cset_cstr(const ALLEGRO::USTRING& ustring, int32_t start_pos, const std::string& reject)
    {
        return al_ustr_find_cset_cstr(ustring.get(), start_pos, reject.c_str());
    }

    export inline int32_t ustr_find_str(const ALLEGRO::USTRING& haystack, int32_t start_pos, const ALLEGRO::USTRING& needle)
    {
        return al_ustr_find_str(haystack.get(), start_pos, needle.get());
    }

    export inline int32_t ustr_find_cstr(const ALLEGRO::USTRING& haystack, int32_t start_pos, const std::string& needle)
    {
        return al_ustr_find_cstr(haystack.get(), start_pos, needle.c_str());
    }

    export inline int32_t ustr_rfind_str(const ALLEGRO::USTRING& haystack, int32_t start_pos, const ALLEGRO::USTRING& needle)
    {
        return al_ustr_rfind_str(haystack.get(), start_pos, needle.get());
    }

    export inline int32_t ustr_rfind_cstr(const ALLEGRO::USTRING& haystack, int32_t start_pos, const std::string& needle)
    {
        return al_ustr_rfind_cstr(haystack.get(), start_pos, needle.c_str());
    }

    export inline bool ustr_find_replace(ALLEGRO::USTRING& ustring, int32_t start_pos, const ALLEGRO::USTRING& find, const ALLEGRO::USTRING& replace)
    {
        return al_ustr_find_replace(ustring.get(), start_pos, find.get(), replace.get());
    }

    export inline bool ustr_find_replace_cstr(ALLEGRO::USTRING& ustring, int32_t start_pos, const std::string& find, const std::string& replace)
    {
        return al_ustr_find_replace_cstr(ustring.get(), start_pos, find.c_str(), replace.c_str());
    }

    export inline bool ustr_equal(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_equal(ustring1.get(), ustring2.get());
    }

    export inline int32_t ustr_compare(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_compare(ustring1.get(), ustring2.get());
    }

    export inline int32_t ustr_ncompare(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2, int32_t n)
    {
        return al_ustr_ncompare(ustring1.get(), ustring2.get(), n);
    }

    export inline bool ustr_has_prefix(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_has_prefix(ustring1.get(), ustring2.get());
    }

    export inline bool ustr_has_prefix_cstr(const ALLEGRO::USTRING& ustring, const std::string& string)
    {
        return al_ustr_has_prefix_cstr(ustring.get(), string.c_str());
    }

    export inline bool ustr_has_suffix(const ALLEGRO::USTRING& ustring1, const ALLEGRO::USTRING& ustring2)
    {
        return al_ustr_has_suffix(ustring1.get(), ustring2.get());
    }

    export inline bool ustr_has_suffix_cstr(const ALLEGRO::USTRING& ustring, const std::string& string)
    {
        return al_ustr_has_suffix_cstr(ustring.get(), string.c_str());
    }

    export inline size_t utf8_width(int32_t c)
    {
        return al_utf8_width(c);
    }

    export inline size_t utf8_encode(char s[], int32_t c)
    {
        return al_utf8_encode(s, c);
    }

    export inline ALLEGRO::USTRING ustr_new_from_utf16(uint16_t const* s)
    {
        return ALLEGRO::USTRING(al_ustr_new_from_utf16(s), al_ustr_free);
    }

    export inline size_t ustr_size_utf16(const ALLEGRO::USTRING& ustring)
    {
        return al_ustr_size_utf16(ustring.get());
    }

    export inline size_t ustr_encode_utf16(const ALLEGRO::USTRING& ustring, uint16_t* s, size_t n) 
    {
        return al_ustr_encode_utf16(ustring.get(), s, n);
    }

    export inline size_t utf16_width(int32_t c)
    {
        return al_utf16_width(c);
    }

    export inline size_t utf16_encode(uint16_t s[], int32_t c)
    {
        return al_utf16_encode(s, c);
    }
}
