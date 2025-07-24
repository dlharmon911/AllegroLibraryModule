export module allegro:blender;

import std;
import <allegro5/blender.h>;
import :base;
import :color;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export struct BLENDER_TAG
		{
			int32_t operation{ 0 };
			int32_t source{ 0 };
			int32_t destination{ 0 };
		};
	}

	using BLENDER = typename INTERNAL::BLENDER_TAG;

	export constexpr int32_t BLEND_MODE_ZERO{ ALLEGRO_ZERO };
	export constexpr int32_t BLEND_MODE_ONE{ ALLEGRO_ONE };
	export constexpr int32_t BLEND_MODE_ALPHA{ ALLEGRO_ALPHA };
	export constexpr int32_t BLEND_MODE_INVERSE_ALPHA{ ALLEGRO_INVERSE_ALPHA };
	export constexpr int32_t BLEND_MODE_SRC_COLOR{ ALLEGRO_SRC_COLOR };
	export constexpr int32_t BLEND_MODE_DEST_COLOR{ ALLEGRO_DEST_COLOR };
	export constexpr int32_t BLEND_MODE_INVERSE_SRC_COLOR{ ALLEGRO_INVERSE_SRC_COLOR };
	export constexpr int32_t BLEND_MODE_INVERSE_DEST_COLOR{ ALLEGRO_INVERSE_DEST_COLOR };
	export constexpr int32_t BLEND_MODE_CONST_COLOR{ ALLEGRO_CONST_COLOR };
	export constexpr int32_t BLEND_MODE_INVERSE_CONST_COLOR{ ALLEGRO_INVERSE_CONST_COLOR };
	export constexpr int32_t BLEND_MODE_COUNT{ ALLEGRO_NUM_BLEND_MODES };

	export constexpr int32_t BLEND_OPERATION_ADD{ ALLEGRO_ADD };
	export constexpr int32_t BLEND_OPERATION_SRC_MINUS_DEST{ ALLEGRO_SRC_MINUS_DEST };
	export constexpr int32_t BLEND_OPERATION_DEST_MINUS_SRC{ ALLEGRO_DEST_MINUS_SRC };
	export constexpr int32_t BLEND_OPERATION_COUNT{ ALLEGRO_NUM_BLEND_OPERATIONS };
}

namespace al
{
	export inline auto set_blender(const ALLEGRO::BLENDER& blender) -> void
	{
		al_set_blender(blender.operation, blender.source, blender.destination);
	}

	export inline auto get_blender() -> ALLEGRO::BLENDER
	{
		ALLEGRO::BLENDER blender;

		al_get_blender(&blender.operation, &blender.source, &blender.destination);

		return blender;
	}

	export inline auto set_blend_color(const ALLEGRO::COLOR& color) -> void
	{
		al_set_blend_color(static_cast<ALLEGRO_COLOR>(color));
	}

	export inline auto get_blend_color() -> ALLEGRO::COLOR
	{
		return static_cast<ALLEGRO::COLOR>(al_get_blend_color());
	}

	export inline auto set_separate_blender(const ALLEGRO::BLENDER& blender, const ALLEGRO::BLENDER& alpha) -> void
	{
		al_set_separate_blender(blender.operation, blender.source, blender.destination,
			alpha.operation, alpha.source, alpha.destination);
	}

	export inline auto get_separate_blender() -> std::tuple<ALLEGRO::BLENDER, ALLEGRO::BLENDER>
	{
		ALLEGRO::BLENDER blender;
		ALLEGRO::BLENDER alpha;

		al_get_separate_blender(&blender.operation, &blender.source, &blender.destination,
			&alpha.operation, &alpha.source, &alpha.destination);

		return std::make_tuple(blender, alpha);
	}
}
