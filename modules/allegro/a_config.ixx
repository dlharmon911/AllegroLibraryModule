export module allegro:config;

import <memory>;
import <string>;
import <allegro5/config.h>;
import :base;
import :memory;

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
		export inline void destroy_config(ALLEGRO::CONFIG_DATA* data)
		{
			al_destroy_config(data);
		}
	}

	export inline ALLEGRO::CONFIG create_config()
	{
		return ALLEGRO::CONFIG(al_create_config(), internal::destroy_config);
	}

	export inline void add_config_section(ALLEGRO::CONFIG& config, const std::string& name)
	{
		al_add_config_section(config.get(), name.c_str());
	}

	export inline void set_config_value(ALLEGRO::CONFIG& config, const std::string& section, const std::string& key, const std::string& value)
	{
		al_set_config_value(config.get(), section.c_str(), key.c_str(), value.c_str());
	}

	export inline void add_config_comment(ALLEGRO::CONFIG& config, const std::string& section, const std::string& comment)
	{
		al_add_config_comment(config.get(), section.c_str(), comment.c_str());
	}

	export inline const std::string get_config_value(const ALLEGRO::CONFIG& config, const std::string& section, const std::string& key)
	{
		const char* v = al_get_config_value(config.get(), section.c_str(), key.c_str());

		if (v)
		{
			return std::string(v);
		}

		return std::string();
	}

	export inline ALLEGRO::CONFIG load_config_file(const std::string& filename)
	{
		return ALLEGRO::CONFIG(al_load_config_file(filename.c_str()), internal::destroy_config);
	}

	export inline ALLEGRO::CONFIG load_config_file_f(ALLEGRO_FILE* file)
	{
		return ALLEGRO::CONFIG(al_load_config_file_f(file), internal::destroy_config);
	}

	export inline bool save_config_file(const std::string& filename, const ALLEGRO::CONFIG& config)
	{
		return al_save_config_file(filename.c_str(), config.get());
	}

	export inline bool save_config_file_f(ALLEGRO_FILE* file, const ALLEGRO::CONFIG& config)
	{
		return al_save_config_file_f(file, config.get());
	}

	export inline void merge_config_into(ALLEGRO::CONFIG& master, const ALLEGRO::CONFIG& add)
	{
		al_merge_config_into(master.get(), add.get());
	}

	export inline ALLEGRO::CONFIG merge_config(const ALLEGRO::CONFIG& cfg1, const ALLEGRO::CONFIG& cfg2)
	{
		return ALLEGRO::CONFIG(al_merge_config(cfg1.get(), cfg2.get()), internal::destroy_config);
	}

	export inline bool remove_config_section(ALLEGRO::CONFIG& config, const std::string& section)
	{
		return al_remove_config_section(config.get(), section.c_str());
	}

	export inline bool remove_config_key(ALLEGRO::CONFIG& config, const std::string& section, const std::string& key)
	{
		return al_remove_config_key(config.get(), section.c_str(), key.c_str());
	}

	export inline const std::string get_first_config_section(const ALLEGRO::CONFIG& config, ALLEGRO::CONFIG_SECTION& iterator)
	{
		ALLEGRO_CONFIG_SECTION* section = &iterator;
		const char* v = al_get_first_config_section(config.get(), &section);

		if (v)
		{
			return std::string(v);
		}

		return std::string();
	}

	export inline const std::string get_next_config_section(ALLEGRO::CONFIG_SECTION& iterator)
	{
		ALLEGRO_CONFIG_SECTION* section = &iterator;
		const char* v = al_get_next_config_section(&section);

		if (v)
		{
			return std::string(v);
		}

		return std::string();
	}

	export inline const std::string get_first_config_entry(const ALLEGRO::CONFIG& config, const std::string& section, ALLEGRO::CONFIG_ENTRY& iterator)
	{
		ALLEGRO_CONFIG_ENTRY* entry = &iterator;
		const char* v = al_get_first_config_entry(config.get(), section.c_str(), &entry);

		if (v)
		{
			return std::string(v);
		}

		return std::string();
	}

	export inline const std::string get_next_config_entry(ALLEGRO::CONFIG_ENTRY& iterator)
	{
		ALLEGRO_CONFIG_ENTRY* entry = &iterator;
		const char* v = al_get_next_config_entry(&entry);

		if (v)
		{
			return std::string(v);
		}

		return std::string();
	}
}

