export module allegro:config;

import <memory>;
import <string>;
import <allegro5/config.h>;
import :base;
import :memory;
import :file;

namespace ALLEGRO
{
	export using CONFIG_DATA = ALLEGRO_CONFIG;
	export using CONFIG = std::shared_ptr<CONFIG_DATA>;
	export using CONFIG_SECTION = ALLEGRO_CONFIG_SECTION;
	export using CONFIG_ENTRY = ALLEGRO_CONFIG_ENTRY;
}

namespace al
{
	namespace internal
	{
		export inline auto create_config() -> ALLEGRO::CONFIG_DATA*
		{
			return al_create_config();
		}

		export inline auto destroy_config(ALLEGRO::CONFIG_DATA* data) -> void
		{
			al_destroy_config(data);
		}
	}

	export inline auto create_config() -> ALLEGRO::CONFIG
	{
		return ALLEGRO::CONFIG(al_create_config(), internal::destroy_config);
	}

	export inline auto add_config_section(ALLEGRO::CONFIG& config, const char* name) -> void
	{
		al_add_config_section((ALLEGRO::CONFIG_DATA*)config.get(), name);
	}

	export inline auto set_config_value(ALLEGRO::CONFIG& config, const char* section, const char* key, const char* value) -> void
	{
		al_set_config_value((ALLEGRO::CONFIG_DATA*)config.get(), section, key, value);
	}

	export inline auto add_config_comment(ALLEGRO::CONFIG& config, const char* section, const char* comment) -> void
	{
		al_add_config_comment((ALLEGRO::CONFIG_DATA*)config.get(), section, comment);
	}

	export inline auto get_config_value(const ALLEGRO::CONFIG& config, const char* section, const char* key) -> const char*
	{
		return al_get_config_value((ALLEGRO::CONFIG_DATA*)config.get(), section, key);
	}

	export inline auto load_config_file(const char* filename) -> ALLEGRO::CONFIG
	{
		return ALLEGRO::CONFIG(al_load_config_file(filename), internal::destroy_config);
	}

	export inline auto load_config_file_f(const ALLEGRO::FILE& file) -> ALLEGRO::CONFIG
	{
		return ALLEGRO::CONFIG(al_load_config_file_f((ALLEGRO::FILE_DATA*)file.get()), internal::destroy_config);
	}

	export inline auto save_config_file(const char* filename, const ALLEGRO::CONFIG& config) -> bool
	{
		return al_save_config_file(filename, (ALLEGRO::CONFIG_DATA*)config.get());
	}

	export inline auto save_config_file_f(const ALLEGRO::FILE& file, const ALLEGRO::CONFIG& config) -> bool
	{
		return al_save_config_file_f((ALLEGRO::FILE_DATA*)file.get(), (ALLEGRO::CONFIG_DATA*)config.get());
	}

	export inline auto merge_config_into(ALLEGRO::CONFIG& master, const ALLEGRO::CONFIG& add) -> void
	{
		al_merge_config_into((ALLEGRO::CONFIG_DATA*)master.get(), (ALLEGRO::CONFIG_DATA*)add.get());
	}

	export inline auto merge_config(const ALLEGRO::CONFIG& cfg1, const ALLEGRO::CONFIG& cfg2) -> ALLEGRO::CONFIG
	{
		return ALLEGRO::CONFIG(al_merge_config((ALLEGRO::CONFIG_DATA*)cfg1.get(), (ALLEGRO::CONFIG_DATA*)cfg2.get()), internal::destroy_config);
	}

	export inline auto remove_config_section(ALLEGRO::CONFIG& config, const char* section) -> bool
	{
		return al_remove_config_section((ALLEGRO::CONFIG_DATA*)config.get(), section);
	}

	export inline auto remove_config_key(ALLEGRO::CONFIG& config, const char* section, const char* key) -> bool
	{
		return al_remove_config_key((ALLEGRO::CONFIG_DATA*)config.get(), section, key);
	}

	export inline auto get_first_config_section(const ALLEGRO::CONFIG& config, ALLEGRO::CONFIG_SECTION& iterator) -> const char*
	{
		ALLEGRO_CONFIG_SECTION* section{ &iterator };
		return al_get_first_config_section((ALLEGRO::CONFIG_DATA*)config.get(), &section);
	}

	export inline auto get_next_config_section(ALLEGRO::CONFIG_SECTION& iterator) -> const char*
	{
		ALLEGRO_CONFIG_SECTION* section{ &iterator };
		return al_get_next_config_section(&section);
	}

	export inline auto get_first_config_entry(const ALLEGRO::CONFIG& config, const char* section, ALLEGRO::CONFIG_ENTRY& iterator) -> const char*
	{
		ALLEGRO_CONFIG_ENTRY* entry{ &iterator };
		return al_get_first_config_entry((ALLEGRO::CONFIG_DATA*)config.get(), section, &entry);
	}

	export inline auto get_next_config_entry(ALLEGRO::CONFIG_ENTRY& iterator) -> const char*
	{
		ALLEGRO_CONFIG_ENTRY* entry{ &iterator };
		return al_get_next_config_entry(&entry);
	}
}

