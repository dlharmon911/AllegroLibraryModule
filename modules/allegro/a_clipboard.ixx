export module allegro:clipboard;

import <string>;
import <allegro5/clipboard.h>;
import :base;
import :display;
import :memory;
import :debug;

namespace al
{
	export inline std::string get_clipboard_text(const ALLEGRO::DISPLAY& display)
	{
		char* text = al_get_clipboard_text(display.get());
		std::string rv;

		if (text)
		{
			rv = text;
			al::free_with_context(text, __LINE__, __FILE__, __func__);
		}

		return rv;
	}

	export inline void set_clipboard_text(const ALLEGRO::DISPLAY& display, const std::string& text)
	{
		al_set_clipboard_text(display.get(), text.c_str());
	}

	export inline bool clipboard_has_text(const ALLEGRO::DISPLAY& display)
	{
		return al_clipboard_has_text(display.get());
	}
}

