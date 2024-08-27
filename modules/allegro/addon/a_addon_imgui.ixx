export module allegro.imgui_addon;

import <string>;
import <memory>;
import allegro;
import <cstdarg>;
export import <imgui/imgui.h>;
import <imgui/imgui_impl_allegro5.h>;

namespace al
{
	static ALLEGRO::COLOR background = { 1.0f, 1.0f, 1.0f, 1.0f };

	namespace imgui_addon
	{
		static bool initialized = false;

		void shutdown();

		export inline bool init(ALLEGRO::DISPLAY& display, bool style_light, ImGuiConfigFlags flags = ImGuiConfigFlags_None)
		{
			bool rv = initialized;

			if (!rv)
			{
				IMGUI_CHECKVERSION();
				ImGui::CreateContext();
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				io.ConfigFlags = flags;

				if (style_light)
				{
					ImGui::StyleColorsLight();
				}
				else
				{
					ImGui::StyleColorsDark();
				}

				rv = ImGui_ImplAllegro5_Init((ALLEGRO::DISPLAY_DATA*)display.get());

				if (rv)
				{
					atexit(shutdown);
				}
			}

			return rv;
		}

		export inline bool is_initialized()
		{
			return initialized;
		}

		export inline void shutdown()
		{
			if (initialized)
			{
				ImGui_ImplAllegro5_Shutdown();
				ImGui::DestroyContext();
				initialized = false;
			}
		}

		export inline uint32_t get_version()
		{
			return 1;
		}
	}

	export void begin_imgui_drawing()
	{
		ImGui_ImplAllegro5_NewFrame();
	}

	export void new_imgui_frame()
	{
		ImGui::NewFrame();
	}

	export void render_imgui_frame()
	{
		ImGui::Render();
	}

	export bool process_imgui_event(ALLEGRO::EVENT& event)
	{
		return ImGui_ImplAllegro5_ProcessEvent(&event);
	}

	export void set_imgui_background_color(ALLEGRO::COLOR color)
	{
		background = color;
	}

	export void end_imgui_drawing()
	{
		al::clear_to_color(background);
		ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
	}

	export void invalidate_imgui_device()
	{
		ImGui_ImplAllegro5_InvalidateDeviceObjects();
	}

	export void create_imgui_device_objects()
	{
		ImGui_ImplAllegro5_CreateDeviceObjects();
	}
}

