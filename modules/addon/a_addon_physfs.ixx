export module allegro.physfs_addon;

import allegro;
import <locale>;
import <string>;
import <allegro5/allegro_physfs.h>;
export import <physfs.h>;

namespace al
{
	namespace physfs_addon
	{
		bool initialized = false;

		auto shutdown() -> void;

		export inline auto init(const std::string& argv0) -> bool
		{
			if (!initialized)
			{
				if (PHYSFS_init(argv0.c_str()))
				{
					atexit(shutdown);
					initialized = true;
				}
			}
			return initialized;
		}

		export inline auto is_initialized() -> bool
		{
			return initialized;
		}

		export inline auto shutdown() -> void
		{
			if (initialized)
			{
				PHYSFS_deinit();
			}
			initialized = false;
		}

		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_physfs_version();
		}
	}

	export inline auto set_physfs_file_interface() -> void
	{
		al_set_physfs_file_interface();
	}

	export inline auto is_physfs_archive_extension(const std::string& extension) -> bool
	{
		static std::locale loc{};
		const PHYSFS_ArchiveInfo** i{ nullptr };

		std::string a(extension);

		for (auto& c : a)
		{
			c = std::tolower(c);
		}

		for (i = PHYSFS_supportedArchiveTypes(); *i != nullptr; i++)
		{
			std::string b{ (*i)->extension };

			for (auto& c : b)
			{
				c = std::tolower(c);
			}

			if (a == b)
			{
				return true;
			}
		}

		return false;
	}
}
