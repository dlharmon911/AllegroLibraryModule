export module allegro.primitives_addon;

import <memory>;
import allegro;
import <allegro5/allegro_primitives.h>;

namespace ALLEGRO
{
	export using PRIM_TYPE = ALLEGRO_PRIM_TYPE;
	export using PRIM_ATTR = ALLEGRO_PRIM_ATTR;
	export using PRIM_STORAGE = ALLEGRO_PRIM_STORAGE;
	export using PRIM_LINE_JOIN = ALLEGRO_LINE_JOIN;
	export using PRIM_LINE_CAP = ALLEGRO_LINE_CAP;
	export using PRIM_BUFFER_FLAGS = ALLEGRO_PRIM_BUFFER_FLAGS;

	export enum
	{
		PRIM_LINE_LIST = ALLEGRO_PRIM_LINE_LIST,
		PRIM_LINE_STRIP = ALLEGRO_PRIM_LINE_STRIP,
		PRIM_LINE_LOOP = ALLEGRO_PRIM_LINE_LOOP,
		PRIM_TRIANGLE_LIST = ALLEGRO_PRIM_TRIANGLE_LIST,
		PRIM_TRIANGLE_STRIP = ALLEGRO_PRIM_TRIANGLE_STRIP,
		PRIM_TRIANGLE_FAN = ALLEGRO_PRIM_TRIANGLE_FAN,
		PRIM_POINT_LIST = ALLEGRO_PRIM_POINT_LIST,
		PRIM_NUM_TYPES = ALLEGRO_PRIM_NUM_TYPES
	};

	export enum
	{
		PRIM_MAX_USER_ATTR = ALLEGRO_PRIM_MAX_USER_ATTR
	};

	export enum
	{
		PRIM_POSITION = ALLEGRO_PRIM_POSITION,
		PRIM_COLOR_ATTR = ALLEGRO_PRIM_COLOR_ATTR,
		PRIM_TEX_COORD = ALLEGRO_PRIM_TEX_COORD,
		PRIM_TEX_COORD_PIXEL = ALLEGRO_PRIM_TEX_COORD_PIXEL,
		PRIM_USER_ATTR = ALLEGRO_PRIM_USER_ATTR,
		PRIM_ATTR_NUM = ALLEGRO_PRIM_ATTR_NUM
	};

	export enum
	{
		PRIM_FLOAT_2= ALLEGRO_PRIM_FLOAT_2,
		PRIM_FLOAT_3 = ALLEGRO_PRIM_FLOAT_3,
		PRIM_SHORT_2 = ALLEGRO_PRIM_SHORT_2,
		PRIM_FLOAT_1 = ALLEGRO_PRIM_FLOAT_1,
		PRIM_FLOAT_4 = ALLEGRO_PRIM_FLOAT_4,
		PRIM_UBYTE_4 = ALLEGRO_PRIM_UBYTE_4,
		PRIM_SHORT_4 = ALLEGRO_PRIM_SHORT_4,
		PRIM_NORMALIZED_UBYTE_4 = ALLEGRO_PRIM_NORMALIZED_UBYTE_4,
		PRIM_NORMALIZED_SHORT_2 = ALLEGRO_PRIM_NORMALIZED_SHORT_2,
		PRIM_NORMALIZED_SHORT_4 = ALLEGRO_PRIM_NORMALIZED_SHORT_4,
		PRIM_NORMALIZED_USHORT_2 = ALLEGRO_PRIM_NORMALIZED_USHORT_2,
		PRIM_NORMALIZED_USHORT_4 = ALLEGRO_PRIM_NORMALIZED_USHORT_4,
		PRIM_HALF_FLOAT_2 = ALLEGRO_PRIM_HALF_FLOAT_2,
		PRIM_HALF_FLOAT_4 = ALLEGRO_PRIM_HALF_FLOAT_4
	};

	export enum
	{
		PRIM_LINE_JOIN_NONE = ALLEGRO_LINE_JOIN_NONE,
		PRIM_LINE_JOIN_BEVEL = ALLEGRO_LINE_JOIN_BEVEL,
		PRIM_LINE_JOIN_ROUND = ALLEGRO_LINE_JOIN_ROUND,
		PRIM_LINE_JOIN_MITER = ALLEGRO_LINE_JOIN_MITER,
		PRIM_LINE_JOIN_MITRE = ALLEGRO_LINE_JOIN_MITRE
	};

	export enum
	{
		PRIM_LINE_CAP_NONE= ALLEGRO_LINE_CAP_NONE,
		PRIM_LINE_CAP_SQUARE = ALLEGRO_LINE_CAP_SQUARE,
		PRIM_LINE_CAP_ROUND = ALLEGRO_LINE_CAP_ROUND,
		PRIM_LINE_CAP_TRIANGLE = ALLEGRO_LINE_CAP_TRIANGLE,
		PRIM_LINE_CAP_CLOSED = ALLEGRO_LINE_CAP_CLOSED
	};

	export enum
	{
		PRIM_BUFFER_STREAM = ALLEGRO_PRIM_BUFFER_STREAM,
		PRIM_BUFFER_STATIC = ALLEGRO_PRIM_BUFFER_STATIC,
		PRIM_BUFFER_DYNAMIC = ALLEGRO_PRIM_BUFFER_DYNAMIC,
		PRIM_BUFFER_READWRITE = ALLEGRO_PRIM_BUFFER_READWRITE
	};

	export inline constexpr size_t VERTEX_CACHE_SIZE = ALLEGRO_VERTEX_CACHE_SIZE;
	export inline constexpr int32_t PRIM_QUALITY = ALLEGRO_PRIM_QUALITY;

	export using VERTEX_ELEMENT = ALLEGRO_VERTEX_ELEMENT;
	export using VERTEX_ELEMENT_PTR = std::add_pointer<VERTEX_ELEMENT>::type;
	export using VERTEX = ALLEGRO_VERTEX;

	export using VERTEX_DECL_DATA = ALLEGRO_VERTEX_DECL;
	export using VERTEX_DECL_DATA_PTR = std::add_pointer<VERTEX_DECL_DATA>::type;
	export using VERTEX_DECL = std::shared_ptr<VERTEX_DECL_DATA>;

	export using VERTEX_BUFFER_DATA = ALLEGRO_VERTEX_BUFFER;
	export using VERTEX_BUFFER_DATA_PTR = std::add_pointer<VERTEX_BUFFER_DATA>::type;
	export using VERTEX_BUFFER = std::shared_ptr<VERTEX_BUFFER_DATA>;

	export using INDEX_BUFFER_DATA = ALLEGRO_INDEX_BUFFER;
	export using INDEX_BUFFER_DATA_PTR = std::add_pointer<INDEX_BUFFER_DATA>::type;
	export using INDEX_BUFFER = std::shared_ptr<INDEX_BUFFER_DATA>;
}

namespace al
{
	namespace primitives_addon
	{
		export inline auto init() -> bool
		{
			return al_init_primitives_addon();
		}

		export inline auto is_initialized() -> bool
		{
			return al_is_primitives_addon_initialized();
		}

		export inline auto shutdown() -> void
		{
			al_shutdown_primitives_addon();
		}

		export inline auto get_version() -> uint32_t
		{
			return al_get_allegro_primitives_version();
		}
	}

	namespace internal
	{
		export inline auto destroy_vertex_decl(ALLEGRO::VERTEX_DECL_DATA_PTR data) -> void
		{
			al_destroy_vertex_decl(data);
		}

		export inline auto destroy_vertex_buffer(ALLEGRO::VERTEX_BUFFER_DATA_PTR data) -> void
		{
			al_destroy_vertex_buffer(data);
		}

		export inline auto destroy_index_buffer(ALLEGRO::INDEX_BUFFER_DATA_PTR data) -> void
		{
			al_destroy_index_buffer(data);
		}
	}

	export inline auto draw_prim(const_vptr_t vtxs, const ALLEGRO::VERTEX_DECL& decl, ALLEGRO::BITMAP& texture, int32_t start, int32_t end, int32_t type) -> int32_t
	{
		return al_draw_prim(vtxs, (ALLEGRO::VERTEX_DECL_DATA_PTR)decl.get(), (ALLEGRO::BITMAP_DATA_PTR)texture.get(), start, end, type);
	}

	export inline auto draw_indexed_prim(const_vptr_t vtxs, const ALLEGRO::VERTEX_DECL& decl, ALLEGRO::BITMAP& texture, const int32_t* indices, int32_t num_vtx, int32_t type) -> int32_t
	{
		return al_draw_indexed_prim(vtxs, (ALLEGRO::VERTEX_DECL_DATA_PTR)decl.get(), (ALLEGRO::BITMAP_DATA_PTR)texture.get(), indices, num_vtx, type);
	}

	export inline auto draw_vertex_buffer(ALLEGRO::VERTEX_BUFFER& vertex_buffer, ALLEGRO::BITMAP& texture, int32_t start, int32_t end, int32_t type) -> int32_t
	{
		return al_draw_vertex_buffer((ALLEGRO::VERTEX_BUFFER_DATA_PTR)vertex_buffer.get(), (ALLEGRO::BITMAP_DATA_PTR)texture.get(), start, end, type);
	}

	export inline auto draw_indexed_buffer(ALLEGRO::VERTEX_BUFFER& vertex_buffer, ALLEGRO::BITMAP& texture, ALLEGRO::INDEX_BUFFER& index_buffer, int32_t start, int32_t end, int32_t type)
	{
		return al_draw_indexed_buffer((ALLEGRO::VERTEX_BUFFER_DATA_PTR)vertex_buffer.get(), (ALLEGRO::BITMAP_DATA_PTR)texture.get(), (ALLEGRO::INDEX_BUFFER_DATA_PTR)index_buffer.get(), start, end, type);
	}
	
	export inline auto create_vertex_decl(const ALLEGRO::VERTEX_ELEMENT_PTR elements, int32_t stride) -> ALLEGRO::VERTEX_DECL
	{
		return ALLEGRO::VERTEX_DECL(al_create_vertex_decl(elements, stride), internal::destroy_vertex_decl);
	}

	export inline auto create_vertex_buffer(ALLEGRO::VERTEX_DECL& decl, const_vptr_t initial_data, int32_t num_vertices, int32_t flags) -> ALLEGRO::VERTEX_BUFFER
	{
		return ALLEGRO::VERTEX_BUFFER(al_create_vertex_buffer((ALLEGRO::VERTEX_DECL_DATA_PTR)decl.get(), initial_data, num_vertices, flags), internal::destroy_vertex_buffer);
	}

	export inline auto lock_vertex_buffer(ALLEGRO::VERTEX_BUFFER& buffer, int32_t offset, int32_t length, int32_t flags) -> vptr_t
	{
		return al_lock_vertex_buffer((ALLEGRO::VERTEX_BUFFER_DATA_PTR)buffer.get(), offset, length, flags);
	}

	export inline auto unlock_vertex_buffer(ALLEGRO::VERTEX_BUFFER& buffer) -> void
	{
		al_unlock_vertex_buffer((ALLEGRO::VERTEX_BUFFER_DATA_PTR)buffer.get());
	}

	export inline auto get_vertex_buffer_size(const ALLEGRO::VERTEX_BUFFER& buffer) -> int32_t
	{
		return al_get_vertex_buffer_size((ALLEGRO::VERTEX_BUFFER_DATA_PTR)buffer.get());
	}

	export inline auto create_index_buffer(int32_t index_size, const_vptr_t initial_data, int32_t num_indices, int32_t flags) -> ALLEGRO::INDEX_BUFFER
	{
		return ALLEGRO::INDEX_BUFFER(al_create_index_buffer(index_size, initial_data, num_indices, flags), internal::destroy_index_buffer);
	}

	export inline auto lock_index_buffer(ALLEGRO::INDEX_BUFFER& buffer, int32_t offset, int32_t length, int32_t flags) -> vptr_t
	{
		return al_lock_index_buffer((ALLEGRO::INDEX_BUFFER_DATA_PTR)buffer.get(), offset, length, flags);
	}

	export inline auto unlock_index_buffer(ALLEGRO::INDEX_BUFFER& buffer) -> void
	{
		al_unlock_index_buffer((ALLEGRO::INDEX_BUFFER_DATA_PTR)buffer.get());
	}

	export inline auto get_index_buffer_size(ALLEGRO::INDEX_BUFFER& buffer) -> int32_t
	{
		return al_get_index_buffer_size((ALLEGRO::INDEX_BUFFER_DATA_PTR)buffer.get());
	}
	export inline auto triangulate_polygon(const float* vertices, size_t vertex_stride, const int32_t* vertex_counts, void (*emit_triangle)(int32_t, int32_t, int32_t, vptr_t), vptr_t userdata) -> bool
	{
		return al_triangulate_polygon(vertices, vertex_stride, vertex_counts, emit_triangle, userdata);
	}

	export inline auto draw_soft_triangle(ALLEGRO::VERTEX& v1, ALLEGRO::VERTEX& v2, ALLEGRO::VERTEX& v3, uintptr_t state, void (*init)(uintptr_t, ALLEGRO::VERTEX*, ALLEGRO::VERTEX*, ALLEGRO::VERTEX*), void (*first)(uintptr_t, int32_t, int32_t, int32_t, int32_t), void (*step)(uintptr_t, int32_t), void (*draw)(uintptr_t, int32_t, int32_t, int32_t)) -> void
	{
		al_draw_soft_triangle(&v1, &v2, &v3, state, init, first, step, draw);
	}

	export inline auto draw_soft_line(ALLEGRO::VERTEX& v1, ALLEGRO::VERTEX& v2, uintptr_t state, void (*first)(uintptr_t, int32_t, int32_t, ALLEGRO::VERTEX*, ALLEGRO::VERTEX*), void (*step)(uintptr_t, int32_t), void (*draw)(uintptr_t, int32_t, int32_t)) -> void
	{
		al_draw_soft_line(&v1, &v2, state, first, step, draw);
	}

	export inline auto draw_line(const ALLEGRO::POINT<float>& pos1, const ALLEGRO::POINT<float>& pos2, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_line(pos1.x, pos1.y, pos2.x, pos2.y, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto draw_triangle(const ALLEGRO::POINT<float>& pos1, const ALLEGRO::POINT<float>& pos2, const ALLEGRO::POINT<float>& pos3, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_triangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto draw_rectangle(const ALLEGRO::POINT<float>& pos1, const ALLEGRO::POINT<float>& pos2, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_rectangle(pos1.x, pos1.y, pos2.x, pos2.y, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto draw_rounded_rectangle(const ALLEGRO::POINT<float>& pos1, const ALLEGRO::POINT<float>& pos2, const ALLEGRO::POINT<float>& radii, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_rounded_rectangle(pos1.x, pos1.y, pos2.x, pos2.y, radii.x, radii.y, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto calculate_arc(float* dest, int32_t stride, const ALLEGRO::POINT<float>& center, const ALLEGRO::POINT<float>& radii, float start_theta, float delta_theta, float thickness, int32_t num_points) -> void
	{
		al_calculate_arc(dest, stride, center.x, center.y, radii.x, radii.y, start_theta, delta_theta, thickness, num_points);
	}

	export inline auto draw_circle(const ALLEGRO::POINT<float>& center, float r, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_circle(center.x, center.y, r, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto draw_ellipse(const ALLEGRO::POINT<float>& center, const ALLEGRO::POINT<float>& radii, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_ellipse(center.x, center.y, radii.x, radii.y, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto draw_arc(const ALLEGRO::POINT<float>& center, float r, float start_theta, float delta_theta, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_arc(center.x, center.y, r, start_theta, delta_theta, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto draw_elliptical_arc(const ALLEGRO::POINT<float>& center, const ALLEGRO::POINT<float>& radii, float start_theta, float delta_theta, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_elliptical_arc(center.x, center.y, radii.x, radii.y, start_theta, delta_theta, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto draw_pieslice(const ALLEGRO::POINT<float>& center, float r, float start_theta, float delta_theta, ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_pieslice(center.x, center.y, r, start_theta, delta_theta, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto calculate_spline(float* dest, int32_t stride, const float points[8], float thickness, int32_t num_segments) -> void
	{
		al_calculate_spline(dest, stride, points, thickness, num_segments);
	}

	export inline auto draw_spline(const float points[8], ALLEGRO::COLOR color, float thickness) -> void
	{
		al_draw_spline(points, (ALLEGRO::COLOR_DATA)color, thickness);
	}

	export inline auto calculate_ribbon(float* dest, int32_t dest_stride, const float* points, int32_t points_stride, float thickness, int32_t num_segments) -> void
	{
		al_calculate_ribbon(dest, dest_stride, points, points_stride, thickness, num_segments);
	}

	export inline auto draw_ribbon(const float* points, int32_t points_stride, ALLEGRO::COLOR color, float thickness, int32_t num_segments) -> void
	{
		al_draw_ribbon(points, points_stride, (ALLEGRO::COLOR_DATA)color, thickness, num_segments);
	}

	export inline auto draw_filled_triangle(const ALLEGRO::POINT<float>& pos1, const ALLEGRO::POINT<float>& pos2, const ALLEGRO::POINT<float>& pos3, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_triangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, (ALLEGRO::COLOR_DATA)color);
	}

	export inline auto draw_filled_rectangle(const ALLEGRO::POINT<float>& pos1, const ALLEGRO::POINT<float>& pos2, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_rectangle(pos1.x, pos2.y, pos2.x, pos2.y, (ALLEGRO::COLOR_DATA)color);
	}

	export inline auto draw_filled_ellipse(const ALLEGRO::POINT<float>& center, const ALLEGRO::POINT<float>& radii, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_ellipse(center.x, center.y, radii.x, radii.y, (ALLEGRO::COLOR_DATA)color);
	}

	export inline auto draw_filled_circle(const ALLEGRO::POINT<float>& center, float r, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_circle(center.x, center.y, r, (ALLEGRO::COLOR_DATA)color);
	}

	export inline auto draw_filled_pieslice(const ALLEGRO::POINT<float>& center, float r, float start_theta, float delta_theta, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_pieslice(center.x, center.y, r, start_theta, delta_theta, (ALLEGRO::COLOR_DATA)color);
	}

	export inline auto draw_filled_rounded_rectangle(const ALLEGRO::POINT<float>& pos1, const ALLEGRO::POINT<float>& pos2, const ALLEGRO::POINT<float>& radii, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_rounded_rectangle(pos1.x, pos1.y, pos2.x, pos2.y, radii.x, radii.y, (ALLEGRO::COLOR_DATA)color);
	}

	export inline auto draw_polyline(const float* vertices, int32_t vertex_stride, int32_t vertex_count, int32_t join_style, int32_t cap_style, ALLEGRO::COLOR color, float thickness, float miter_limit) -> void
	{
		al_draw_polyline(vertices, vertex_stride, vertex_count, join_style, cap_style, (ALLEGRO::COLOR_DATA)color, thickness, miter_limit);
	}

	export inline auto draw_polygon(const float* vertices, int32_t vertex_count, int32_t join_style, ALLEGRO::COLOR color, float thickness, float miter_limit) -> void
	{
		al_draw_polygon(vertices, vertex_count, join_style, (ALLEGRO::COLOR_DATA)color, thickness, miter_limit);
	}

	export inline auto draw_filled_polygon(const float* vertices, int32_t vertex_count, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_polygon(vertices, vertex_count, (ALLEGRO::COLOR_DATA)color);
	}

	export inline auto draw_filled_polygon_with_holes(const float* vertices, const int32_t* vertex_counts, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_polygon_with_holes(vertices, vertex_counts, (ALLEGRO::COLOR_DATA)color);
	}
}
