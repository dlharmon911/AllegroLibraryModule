export module allegro:clipboard;

import <string>;
import <allegro5/clipboard.h>;
import :base;
import :display;
import :memory;
import :debug;

namespace al
{
	export inline auto get_clipboard_text(const ALLEGRO::DISPLAY& display) -> cptr_t
	{
		cptr_t text{ al_get_clipboard_text((ALLEGRO::DISPLAY_DATA_PTR)display.get()) };
		cptr_t rv{ nullptr };

		if (text)
		{
			rv = text;
			al::free_with_context(text, __LINE__, (const_cptr_t)__FILE__, (const_cptr_t)__func__);
		}

		return rv;
	}

	export inline auto set_clipboard_text(const ALLEGRO::DISPLAY& display, const_cptr_t text) -> void
	{
		al_set_clipboard_text((ALLEGRO::DISPLAY_DATA_PTR)display.get(), text);
	}

	export inline auto clipboard_has_text(const ALLEGRO::DISPLAY& display) -> bool
	{
		return al_clipboard_has_text((ALLEGRO::DISPLAY_DATA_PTR)display.get());
	}
}

