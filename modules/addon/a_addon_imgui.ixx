module;

//#define ImDrawIdx  int
#include <imgui.h>

export module allegro.imgui_addon;

import <cstdint>;
import <string>;
import <memory>;
import allegro;
import <cstdarg>;
export import <imgui.h>;
import <imgui_impl_allegro5.h>;


namespace al
{
	static ALLEGRO::COLOR background = { 1.0f, 1.0f, 1.0f, 1.0f };

	namespace imgui_addon
	{
		namespace internal
		{
			bool initialized = false;
		}

		void shutdown();

		export inline bool init(const ALLEGRO::DISPLAY& display, bool style_light, ImGuiConfigFlags flags = ImGuiConfigFlags_None)
		{
			bool rv = internal::initialized;

			if (!rv)
			{
				ImGui::DebugCheckVersionAndDataLayout(IMGUI_VERSION, sizeof(ImGuiIO), sizeof(ImGuiStyle), sizeof(ImVec2), sizeof(ImVec4), sizeof(ImDrawVert), sizeof(ImDrawIdx));
				ImGui::CreateContext();
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				io.ConfigFlags |= flags;

				if (style_light)
				{
					ImGui::StyleColorsLight();
				}
				else
				{
					ImGui::StyleColorsDark();
				}

				rv = ImGui_ImplAllegro5_Init((ALLEGRO::INTERNAL::DISPLAY_DATA_PTR)display.get());

				if (rv)
				{
					atexit(shutdown);
				}
			}

			return rv;
		}

		export inline bool is_initialized()
		{
			return internal::initialized;
		}

		export inline void shutdown()
		{
			if (internal::initialized)
			{
				ImGui_ImplAllegro5_Shutdown();
				ImGui::DestroyContext();
				internal::initialized = false;
			}
		}

		export inline uint32_t get_version()
		{
			return 1;
		}
	}

	export void imgui_begin_drawing()
	{
		ImGui_ImplAllegro5_NewFrame();
	}

	export void imgui_new_frame()
	{
		ImGui::NewFrame();
	}

	export void imgui_render_frame()
	{
		ImGui::Render();
	}

	export bool imgui_process_event(const ALLEGRO::EVENT& event)
	{
		return ImGui_ImplAllegro5_ProcessEvent(event);
	}

	export void imgui_set_background_color(ALLEGRO::COLOR color)
	{
		background = color;
	}

	export void imgui_end_drawing()
	{
		al::clear_to_color(background);
		ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
	}

	export void imgui_invalidate_device_objects()
	{
		ImGui_ImplAllegro5_InvalidateDeviceObjects();
	}

	export void imgui_create_device_objects()
	{
		ImGui_ImplAllegro5_CreateDeviceObjects();
	}
}

namespace IMGUI
{
	export const char* const VERSION{ static_cast<const char*>(IMGUI_VERSION) };
	export constexpr int32_t VERSION_NUM{ IMGUI_VERSION_NUM };
}
