export module allegro:blender;

import <tuple>;
import <allegro5/blender.h>;
import :base;
import :color;

namespace ALLEGRO
{
	export enum
	{
		BLEND_MODE_ZERO = ALLEGRO_ZERO,
		BLEND_MODE_ONE = ALLEGRO_ONE,
		BLEND_MODE_ALPHA = ALLEGRO_ALPHA,
		BLEND_MODE_INVERSE_ALPHA = ALLEGRO_INVERSE_ALPHA,
		BLEND_MODE_SRC_COLOR = ALLEGRO_SRC_COLOR,
		BLEND_MODE_DEST_COLOR = ALLEGRO_DEST_COLOR,
		BLEND_MODE_INVERSE_SRC_COLOR = ALLEGRO_INVERSE_SRC_COLOR,
		BLEND_MODE_INVERSE_DEST_COLOR = ALLEGRO_INVERSE_DEST_COLOR,
		BLEND_MODE_CONST_COLOR = ALLEGRO_CONST_COLOR,
		BLEND_MODE_INVERSE_CONST_COLOR = ALLEGRO_INVERSE_CONST_COLOR,
		BLEND_MODE_COUNT
	};

	export enum
	{
		BLEND_OPERATION_ADD = ALLEGRO_ADD,
		BLEND_OPERATION_SRC_MINUS_DEST = ALLEGRO_SRC_MINUS_DEST,
		BLEND_OPERATION_DEST_MINUS_SRC = ALLEGRO_DEST_MINUS_SRC,
		BLEND_OPERATION_COUNT
	};

	export typedef struct BLENDER
	{
		int32_t operation;
		int32_t source;
		int32_t destination;
	} BLENDER;
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
		al_set_blend_color((ALLEGRO::COLOR_DATA)color);
	}

	export inline auto get_blend_color() -> ALLEGRO::COLOR
	{
		return (ALLEGRO::COLOR)al_get_blend_color();
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
