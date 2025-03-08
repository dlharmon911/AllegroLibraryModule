export module allegro:config;

import <memory>;
import <string>;
import <allegro5/config.h>;
import :base;
import :memory;
import :file;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using CONFIG_DATA = typename ALLEGRO_CONFIG;
		export using CONFIG_DATA_PTR = std::add_pointer<CONFIG_DATA>::type;
	}

	export using CONFIG = typename std::shared_ptr<INTERNAL::CONFIG_DATA>;
	export using CONFIG_SECTION = typename ALLEGRO_CONFIG_SECTION;
	export using CONFIG_SECTION_PTR = std::add_pointer<CONFIG_SECTION>::type;
	export using CONFIG_ENTRY = typename ALLEGRO_CONFIG_ENTRY;
	export using CONFIG_ENTRY_PTR = std::add_pointer<CONFIG_ENTRY>::type;
}

namespace al
{
	namespace internal
	{
		export inline auto create_config() -> ALLEGRO::INTERNAL::CONFIG_DATA_PTR
		{
			return al_create_config();
		}

		export inline auto destroy_config(ALLEGRO::INTERNAL::CONFIG_DATA_PTR data) -> void
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
		al_add_config_section(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), name);
	}

	export inline auto set_config_value(ALLEGRO::CONFIG& config, const char* section, const char* key, const char* value) -> void
	{
		al_set_config_value(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), section, key, value);
	}

	export inline auto add_config_comment(ALLEGRO::CONFIG& config, const char* section, const char* comment) -> void
	{
		al_add_config_comment(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), section, comment);
	}

	export inline auto get_config_value(const ALLEGRO::CONFIG& config, const char* section, const char* key) -> const char*
	{
		return (const char*)al_get_config_value(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), section, key);
	}

	export inline auto load_config_file(const char* filename) -> ALLEGRO::CONFIG
	{
		return ALLEGRO::CONFIG(al_load_config_file(filename), internal::destroy_config);
	}

	export inline auto load_config_file_f(const ALLEGRO::FILE& file) -> ALLEGRO::CONFIG
	{
		return ALLEGRO::CONFIG(al_load_config_file_f(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get())), internal::destroy_config);
	}

	export inline auto save_config_file(const char* filename, const ALLEGRO::CONFIG& config) -> bool
	{
		return al_save_config_file(filename, static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()));
	}

	export inline auto save_config_file_f(const ALLEGRO::FILE& file, const ALLEGRO::CONFIG& config) -> bool
	{
		return al_save_config_file_f(static_cast<ALLEGRO::INTERNAL::FILE_DATA_PTR>(file.get()), static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()));
	}

	export inline auto merge_config_into(ALLEGRO::CONFIG& master, const ALLEGRO::CONFIG& add) -> void
	{
		al_merge_config_into(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(master.get()), static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(add.get()));
	}

	export inline auto merge_config(const ALLEGRO::CONFIG& cfg1, const ALLEGRO::CONFIG& cfg2) -> ALLEGRO::CONFIG
	{
		return ALLEGRO::CONFIG(al_merge_config(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(cfg1.get()), static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(cfg2.get())), internal::destroy_config);
	}

	export inline auto remove_config_section(ALLEGRO::CONFIG& config, const char* section) -> bool
	{
		return al_remove_config_section(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), section);
	}

	export inline auto remove_config_key(ALLEGRO::CONFIG& config, const char* section, const char* key) -> bool
	{
		return al_remove_config_key(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), section, key);
	}

	export inline auto get_first_config_section(const ALLEGRO::CONFIG& config, ALLEGRO::CONFIG_SECTION& iterator) -> const char*
	{
		ALLEGRO::CONFIG_SECTION_PTR section{ &iterator };
		return (const char*)al_get_first_config_section(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), &section);
	}

	export inline auto get_next_config_section(ALLEGRO::CONFIG_SECTION& iterator) -> const char*
	{
		ALLEGRO::CONFIG_SECTION_PTR  section{ &iterator };
		return (const char*)al_get_next_config_section(&section);
	}

	export inline auto get_first_config_entry(const ALLEGRO::CONFIG& config, const char* section, ALLEGRO::CONFIG_ENTRY& iterator) -> const char*
	{
		ALLEGRO::CONFIG_ENTRY_PTR  entry{ &iterator };
		return (const char*)al_get_first_config_entry(static_cast<ALLEGRO::INTERNAL::CONFIG_DATA_PTR>(config.get()), section, &entry);
	}

	export inline auto get_next_config_entry(ALLEGRO::CONFIG_ENTRY& iterator) -> const char*
	{
		ALLEGRO::CONFIG_ENTRY_PTR  entry{ &iterator };
		return (const char*)al_get_next_config_entry(&entry);
	}
}
