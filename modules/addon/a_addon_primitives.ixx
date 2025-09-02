export module allegro.primitives_addon;

import std;
import allegro;
import <allegro5/allegro_primitives.h>;

namespace ALLEGRO
{
	namespace INTERNAL
	{
		export using VERTEX_DECL_DATA = typename ALLEGRO_VERTEX_DECL;
		export using VERTEX_DECL_DATA_PTR = std::add_pointer<VERTEX_DECL_DATA>::type;
		export using VERTEX_BUFFER_DATA = typename ALLEGRO_VERTEX_BUFFER;
		export using VERTEX_BUFFER_DATA_PTR = std::add_pointer<VERTEX_BUFFER_DATA>::type;
		export using INDEX_BUFFER_DATA = typename ALLEGRO_INDEX_BUFFER;
		export using INDEX_BUFFER_DATA_PTR = std::add_pointer<INDEX_BUFFER_DATA>::type;
	}

	export using VERTEX = typename ALLEGRO_VERTEX;

	export using VERTEX_ELEMENT = typename ALLEGRO_VERTEX_ELEMENT;
	export using VERTEX_ELEMENT_PTR = std::add_pointer<VERTEX_ELEMENT>::type;
	export using VERTEX_DECL = typename std::shared_ptr<INTERNAL::VERTEX_DECL_DATA>;
	export using VERTEX_BUFFER = typename std::shared_ptr<INTERNAL::VERTEX_BUFFER_DATA>;
	export using INDEX_BUFFER = typename std::shared_ptr<INTERNAL::INDEX_BUFFER_DATA>;

	export using PRIM_TYPE = typename ALLEGRO_PRIM_TYPE;
	export using PRIM_ATTR = typename ALLEGRO_PRIM_ATTR;
	export using PRIM_STORAGE = typename ALLEGRO_PRIM_STORAGE;
	export using PRIM_LINE_JOIN = typename ALLEGRO_LINE_JOIN;
	export using PRIM_LINE_CAP = typename ALLEGRO_LINE_CAP;
	export using PRIM_BUFFER_FLAGS = typename ALLEGRO_PRIM_BUFFER_FLAGS;

	export constexpr int32_t PRIM_LINE_LIST{ ALLEGRO_PRIM_LINE_LIST };
	export constexpr int32_t PRIM_LINE_STRIP{ ALLEGRO_PRIM_LINE_STRIP };
	export constexpr int32_t PRIM_LINE_LOOP{ ALLEGRO_PRIM_LINE_LOOP };
	export constexpr int32_t PRIM_TRIANGLE_LIST{ ALLEGRO_PRIM_TRIANGLE_LIST };
	export constexpr int32_t PRIM_TRIANGLE_STRIP{ ALLEGRO_PRIM_TRIANGLE_STRIP };
	export constexpr int32_t PRIM_TRIANGLE_FAN{ ALLEGRO_PRIM_TRIANGLE_FAN };
	export constexpr int32_t PRIM_POINT_LIST{ ALLEGRO_PRIM_POINT_LIST };
	export constexpr int32_t PRIM_NUM_TYPES{ ALLEGRO_PRIM_NUM_TYPES };

	export constexpr int32_t PRIM_MAX_USER_ATTR{ ALLEGRO_PRIM_MAX_USER_ATTR };

	export constexpr int32_t PRIM_POSITION{ ALLEGRO_PRIM_POSITION };
	export constexpr int32_t PRIM_COLOR_ATTR{ ALLEGRO_PRIM_COLOR_ATTR };
	export constexpr int32_t PRIM_TEX_COORD{ ALLEGRO_PRIM_TEX_COORD };
	export constexpr int32_t PRIM_TEX_COORD_PIXEL{ ALLEGRO_PRIM_TEX_COORD_PIXEL };
	export constexpr int32_t PRIM_USER_ATTR{ ALLEGRO_PRIM_USER_ATTR };
	export constexpr int32_t PRIM_ATTR_NUM{ ALLEGRO_PRIM_ATTR_NUM };

	export constexpr int32_t PRIM_FLOAT_2{ ALLEGRO_PRIM_FLOAT_2 };
	export constexpr int32_t PRIM_FLOAT_3{ ALLEGRO_PRIM_FLOAT_3 };
	export constexpr int32_t PRIM_SHORT_2{ ALLEGRO_PRIM_SHORT_2 };
	export constexpr int32_t PRIM_FLOAT_1{ ALLEGRO_PRIM_FLOAT_1 };
	export constexpr int32_t PRIM_FLOAT_4{ ALLEGRO_PRIM_FLOAT_4 };
	export constexpr int32_t PRIM_UBYTE_4{ ALLEGRO_PRIM_UBYTE_4 };
	export constexpr int32_t PRIM_SHORT_4{ ALLEGRO_PRIM_SHORT_4 };
	export constexpr int32_t PRIM_NORMALIZED_UBYTE_4{ ALLEGRO_PRIM_NORMALIZED_UBYTE_4 };
	export constexpr int32_t PRIM_NORMALIZED_SHORT_2{ ALLEGRO_PRIM_NORMALIZED_SHORT_2 };
	export constexpr int32_t PRIM_NORMALIZED_SHORT_4{ ALLEGRO_PRIM_NORMALIZED_SHORT_4 };
	export constexpr int32_t PRIM_NORMALIZED_USHORT_2{ ALLEGRO_PRIM_NORMALIZED_USHORT_2 };
	export constexpr int32_t PRIM_NORMALIZED_USHORT_4{ ALLEGRO_PRIM_NORMALIZED_USHORT_4 };
	export constexpr int32_t PRIM_HALF_FLOAT_2{ ALLEGRO_PRIM_HALF_FLOAT_2 };
	export constexpr int32_t PRIM_HALF_FLOAT_4{ ALLEGRO_PRIM_HALF_FLOAT_4 };

	export constexpr int32_t PRIM_LINE_JOIN_NONE{ ALLEGRO_LINE_JOIN_NONE };
	export constexpr int32_t PRIM_LINE_JOIN_BEVEL{ ALLEGRO_LINE_JOIN_BEVEL };
	export constexpr int32_t PRIM_LINE_JOIN_ROUND{ ALLEGRO_LINE_JOIN_ROUND };
	export constexpr int32_t PRIM_LINE_JOIN_MITER{ ALLEGRO_LINE_JOIN_MITER };
	export constexpr int32_t PRIM_LINE_JOIN_MITRE{ ALLEGRO_LINE_JOIN_MITRE };

	export constexpr int32_t PRIM_LINE_CAP_NONE{ ALLEGRO_LINE_CAP_NONE };
	export constexpr int32_t PRIM_LINE_CAP_SQUARE{ ALLEGRO_LINE_CAP_SQUARE };
	export constexpr int32_t PRIM_LINE_CAP_ROUND{ ALLEGRO_LINE_CAP_ROUND };
	export constexpr int32_t PRIM_LINE_CAP_TRIANGLE{ ALLEGRO_LINE_CAP_TRIANGLE };
	export constexpr int32_t PRIM_LINE_CAP_CLOSED{ ALLEGRO_LINE_CAP_CLOSED };

	export constexpr int32_t PRIM_BUFFER_STREAM{ ALLEGRO_PRIM_BUFFER_STREAM };
	export constexpr int32_t PRIM_BUFFER_STATIC{ ALLEGRO_PRIM_BUFFER_STATIC };
	export constexpr int32_t PRIM_BUFFER_DYNAMIC{ ALLEGRO_PRIM_BUFFER_DYNAMIC };
	export constexpr int32_t PRIM_BUFFER_READWRITE{ ALLEGRO_PRIM_BUFFER_READWRITE };

	export inline constexpr size_t VERTEX_CACHE_SIZE = ALLEGRO_VERTEX_CACHE_SIZE;
	export inline constexpr int32_t PRIM_QUALITY = ALLEGRO_PRIM_QUALITY;
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
		export inline auto destroy_vertex_decl(ALLEGRO::INTERNAL::VERTEX_DECL_DATA_PTR data) -> void
		{
			al_destroy_vertex_decl(data);
		}

		export inline auto destroy_vertex_buffer(ALLEGRO::INTERNAL::VERTEX_BUFFER_DATA_PTR data) -> void
		{
			al_destroy_vertex_buffer(data);
		}

		export inline auto destroy_index_buffer(ALLEGRO::INTERNAL::INDEX_BUFFER_DATA_PTR data) -> void
		{
			al_destroy_index_buffer(data);
		}
	}

	export inline auto draw_prim(const void* vtxs, const ALLEGRO::VERTEX_DECL& decl, ALLEGRO::BITMAP& texture, int32_t start, int32_t end, int32_t type) -> int32_t
	{
		return al_draw_prim(vtxs, static_cast<ALLEGRO::INTERNAL::VERTEX_DECL_DATA_PTR>(decl.get()), static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(texture.get()), start, end, type);
	}

	export inline auto draw_indexed_prim(const void* vtxs, const ALLEGRO::VERTEX_DECL& decl, ALLEGRO::BITMAP& texture, const int32_t* indices, int32_t num_vtx, int32_t type) -> int32_t
	{
		return al_draw_indexed_prim(vtxs, static_cast<ALLEGRO::INTERNAL::VERTEX_DECL_DATA_PTR>(decl.get()), static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(texture.get()), indices, num_vtx, type);
	}

	export inline auto draw_vertex_buffer(const ALLEGRO::VERTEX_BUFFER& vertex_buffer, const ALLEGRO::BITMAP& texture, size_t start, size_t end, int32_t type) -> int32_t
	{
		return al_draw_vertex_buffer(static_cast<ALLEGRO::INTERNAL::VERTEX_BUFFER_DATA_PTR>(vertex_buffer.get()), static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(texture.get()), static_cast<int32_t>(start), static_cast<int32_t>(end), type);
	}

	export inline auto draw_indexed_buffer(const ALLEGRO::VERTEX_BUFFER& vertex_buffer, const ALLEGRO::BITMAP& texture, const ALLEGRO::INDEX_BUFFER& index_buffer, size_t start, size_t end, int32_t type)
	{
		return al_draw_indexed_buffer(static_cast<ALLEGRO::INTERNAL::VERTEX_BUFFER_DATA_PTR>(vertex_buffer.get()), static_cast<ALLEGRO::INTERNAL::BITMAP_DATA_PTR>(texture.get()), static_cast<ALLEGRO::INTERNAL::INDEX_BUFFER_DATA_PTR>(index_buffer.get()), static_cast<int32_t>(start), static_cast<int32_t>(end), type);
	}

	export inline auto create_vertex_decl(const ALLEGRO::VERTEX_ELEMENT_PTR elements, int32_t stride) -> ALLEGRO::VERTEX_DECL
	{
		return ALLEGRO::VERTEX_DECL(al_create_vertex_decl(elements, stride), internal::destroy_vertex_decl);
	}

	export template <typename T> auto create_vertex_buffer(const ALLEGRO::VERTEX_DECL& decl, const T* initial_data, size_t num_vertices, int32_t flags) -> ALLEGRO::VERTEX_BUFFER
	{
		return ALLEGRO::VERTEX_BUFFER(al_create_vertex_buffer(static_cast<ALLEGRO::INTERNAL::VERTEX_DECL_DATA_PTR>(decl.get()), reinterpret_cast<const void*>(initial_data), static_cast<int32_t>(num_vertices), flags), internal::destroy_vertex_buffer);
	}

	export template <typename T> auto create_vertex_buffer(const ALLEGRO::VERTEX_DECL& decl, const std::span<T>& initial_data, int32_t flags) -> ALLEGRO::VERTEX_BUFFER
	{
		return ALLEGRO::VERTEX_BUFFER(al_create_vertex_buffer(static_cast<ALLEGRO::INTERNAL::VERTEX_DECL_DATA_PTR>(decl.get()), reinterpret_cast<const void*>(initial_data.data()), static_cast<int32_t>(initial_data.size()), flags), internal::destroy_vertex_buffer);
	}

	export inline auto lock_vertex_buffer(ALLEGRO::VERTEX_BUFFER& vertex_buffer, int32_t offset, int32_t length, int32_t flags) -> void*
	{
		return al_lock_vertex_buffer(static_cast<ALLEGRO::INTERNAL::VERTEX_BUFFER_DATA_PTR>(vertex_buffer.get()), offset, length, flags);
	}

	export inline auto unlock_vertex_buffer(ALLEGRO::VERTEX_BUFFER& vertex_buffer) -> void
	{
		al_unlock_vertex_buffer(static_cast<ALLEGRO::INTERNAL::VERTEX_BUFFER_DATA_PTR>(vertex_buffer.get()));
	}

	export inline auto get_vertex_buffer_size(const ALLEGRO::VERTEX_BUFFER& vertex_buffer) -> int32_t
	{
		return al_get_vertex_buffer_size(static_cast<ALLEGRO::INTERNAL::VERTEX_BUFFER_DATA_PTR>(vertex_buffer.get()));
	}

	export template <typename T> auto create_index_buffer(size_t index_size, const T* initial_data, size_t num_indices, int32_t flags) -> ALLEGRO::INDEX_BUFFER
	{
		return ALLEGRO::INDEX_BUFFER(al_create_index_buffer(static_cast<int32_t>(index_size), reinterpret_cast<const void*>(initial_data), static_cast<int32_t>(num_indices), flags), internal::destroy_index_buffer);
	}

	export template <typename T> auto create_index_buffer(size_t index_size, const std::span<T>& initial_data, int32_t flags) -> ALLEGRO::INDEX_BUFFER
	{
		return ALLEGRO::INDEX_BUFFER(al_create_index_buffer(static_cast<int32_t>(index_size), reinterpret_cast<const void*>(initial_data.data()), static_cast<int32_t>(initial_data.size()), flags), internal::destroy_index_buffer);
	}

	export inline auto lock_index_buffer(ALLEGRO::INDEX_BUFFER& index_buffer, int32_t offset, int32_t length, int32_t flags) -> void*
	{
		return al_lock_index_buffer(static_cast<ALLEGRO::INTERNAL::INDEX_BUFFER_DATA_PTR>(index_buffer.get()), offset, length, flags);
	}

	export inline auto unlock_index_buffer(ALLEGRO::INDEX_BUFFER& index_buffer) -> void
	{
		al_unlock_index_buffer(static_cast<ALLEGRO::INTERNAL::INDEX_BUFFER_DATA_PTR>(index_buffer.get()));
	}

	export inline auto get_index_buffer_size(ALLEGRO::INDEX_BUFFER& index_buffer) -> int32_t
	{
		return al_get_index_buffer_size(static_cast<ALLEGRO::INTERNAL::INDEX_BUFFER_DATA_PTR>(index_buffer.get()));
	}

	export inline auto triangulate_polygon(const float* vertices, size_t vertex_stride, const int32_t* vertex_counts, void (*emit_triangle)(int32_t, int32_t, int32_t, void*), void* userdata) -> bool
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

	export inline auto draw_line(const ALLEGRO::VECTOR_2D<float>& pos1, const ALLEGRO::VECTOR_2D<float>& pos2, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_line(pos1.get_x(), pos1.get_y(), pos2.get_x(), pos2.get_y(), color, thickness);
	}

	export inline auto draw_line(float pos1_x, float pos1_y, float pos2_x, float pos2_y, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_line(pos1_x, pos1_y, pos2_x, pos2_y, color, thickness);
	}

	export inline auto draw_triangle(const ALLEGRO::VECTOR_2D<float>& pos1, const ALLEGRO::VECTOR_2D<float>& pos2, const ALLEGRO::VECTOR_2D<float>& pos3, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_triangle(pos1.get_x(), pos1.get_y(), pos2.get_x(), pos2.get_y(), pos3.get_x(), pos3.get_y(), color, thickness);
	}

	export inline auto draw_rectangle(const ALLEGRO::VECTOR_2D<float>& pos1, const ALLEGRO::VECTOR_2D<float>& pos2, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_rectangle(pos1.get_x(), pos1.get_y(), pos2.get_x(), pos2.get_y(), color, thickness);
	}

	export inline auto draw_rectangle(float pos1_x, float pos1_y, float pos2_x, float pos2_y, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_rectangle(pos1_x, pos1_y, pos2_x, pos2_y, color, thickness);
	}

	export inline auto draw_rounded_rectangle(const ALLEGRO::VECTOR_2D<float>& pos1, const ALLEGRO::VECTOR_2D<float>& pos2, const ALLEGRO::VECTOR_2D<float>& radii, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_rounded_rectangle(pos1.get_x(), pos1.get_y(), pos2.get_x(), pos2.get_y(), radii.get_x(), radii.get_y(), color, thickness);
	}

	export inline auto draw_rounded_rectangle(float pos1_x, float pos1_y, float pos2_x, float pos2_y, float radii_x, float radii_y, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_rounded_rectangle(pos1_x, pos1_y, pos2_x, pos2_y, radii_x, radii_y, color, thickness);
	}

	export inline auto calculate_arc(float* dest, int32_t stride, const ALLEGRO::VECTOR_2D<float>& center, const ALLEGRO::VECTOR_2D<float>& radii, float start_theta, float delta_theta, float thickness, int32_t num_points) -> void
	{
		al_calculate_arc(dest, stride, center.get_x(), center.get_y(), radii.get_x(), radii.get_y(), start_theta, delta_theta, thickness, num_points);
	}

	export inline auto calculate_arc(float* dest, int32_t stride, float center_x, float center_y, float radii_x, float radii_y, float start_theta, float delta_theta, float thickness, int32_t num_points) -> void
	{
		al_calculate_arc(dest, stride, center_x, center_y, radii_x, radii_y, start_theta, delta_theta, thickness, num_points);
	}

	export inline auto draw_circle(const ALLEGRO::VECTOR_2D<float>& center, float r, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_circle(center.get_x(), center.get_y(), r, color, thickness);
	}

	export inline auto draw_circle(float center_x, float center_y, float r, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_circle(center_x, center_y, r, color, thickness);
	}

	export inline auto draw_ellipse(const ALLEGRO::VECTOR_2D<float>& center, const ALLEGRO::VECTOR_2D<float>& radii, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_ellipse(center.get_x(), center.get_y(), radii.get_x(), radii.get_y(), color, thickness);
	}

	export inline auto draw_ellipse(float center_x, float center_y, float radii_x, float radii_y, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_ellipse(center_x, center_y, radii_x, radii_y, color, thickness);
	}

	export inline auto draw_arc(const ALLEGRO::VECTOR_2D<float>& center, float r, float start_theta, float delta_theta, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_arc(center.get_x(), center.get_y(), r, start_theta, delta_theta, color, thickness);
	}

	export inline auto draw_arc(float center_x, float center_y, float r, float start_theta, float delta_theta, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_arc(center_x, center_y, r, start_theta, delta_theta, color, thickness);
	}

	export inline auto draw_elliptical_arc(const ALLEGRO::VECTOR_2D<float>& center, const ALLEGRO::VECTOR_2D<float>& radii, float start_theta, float delta_theta, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_elliptical_arc(center.get_x(), center.get_y(), radii.get_x(), radii.get_y(), start_theta, delta_theta, color, thickness);
	}

	export inline auto draw_elliptical_arc(float center_x, float center_y, float radii_x, float radii_y, float start_theta, float delta_theta, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_elliptical_arc(center_x, center_y, radii_x, radii_y, start_theta, delta_theta, color, thickness);
	}

	export inline auto draw_pieslice(const ALLEGRO::VECTOR_2D<float>& center, float r, float start_theta, float delta_theta, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_pieslice(center.get_x(), center.get_y(), r, start_theta, delta_theta, color, thickness);
	}

	export inline auto draw_pieslice(float center_x, float center_y, float r, float start_theta, float delta_theta, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_pieslice(center_x, center_y, r, start_theta, delta_theta, color, thickness);
	}

	export inline auto calculate_spline(float* dest, int32_t stride, const std::array<float, 8>& points, float thickness, int32_t num_segments) -> void
	{
		al_calculate_spline(dest, stride, points.data(), thickness, num_segments);
	}

	export inline auto draw_spline(const std::array<float, 8>& points, const ALLEGRO::COLOR& color, float thickness) -> void
	{
		al_draw_spline(points.data(), color, thickness);
	}

	export inline auto calculate_ribbon(float* dest, int32_t dest_stride, const float* points, int32_t points_stride, float thickness, int32_t num_segments) -> void
	{
		al_calculate_ribbon(dest, dest_stride, points, points_stride, thickness, num_segments);
	}

	export inline auto draw_ribbon(const float* points, int32_t points_stride, const ALLEGRO::COLOR& color, float thickness, int32_t num_segments) -> void
	{
		al_draw_ribbon(points, points_stride, color, thickness, num_segments);
	}

	export inline auto draw_filled_triangle(const ALLEGRO::VECTOR_2D<float>& pos1, const ALLEGRO::VECTOR_2D<float>& pos2, const ALLEGRO::VECTOR_2D<float>& pos3, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_triangle(pos1.get_x(), pos1.get_y(), pos2.get_x(), pos2.get_y(), pos3.get_x(), pos3.get_y(), color);
	}

	export inline auto draw_filled_triangle(float pos1_x, float pos1_y, float pos2_x, float pos2_y, float pos3_x, float pos3_y, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_triangle(pos1_x, pos1_y, pos2_x, pos2_y, pos3_x, pos3_y, color);
	}

	export inline auto draw_filled_rectangle(const ALLEGRO::VECTOR_2D<float>& pos1, const ALLEGRO::VECTOR_2D<float>& pos2, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_rectangle(pos1.get_x(), pos1.get_y(), pos2.get_x(), pos2.get_y(), color);
	}

	export inline auto draw_filled_rectangle(float pos1_x, float pos1_y, float pos2_x, float pos2_y, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_rectangle(pos1_x, pos1_y, pos2_x, pos2_y, color);
	}

	export inline auto draw_filled_ellipse(const ALLEGRO::VECTOR_2D<float>& center, const ALLEGRO::VECTOR_2D<float>& radii, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_ellipse(center.get_x(), center.get_y(), radii.get_x(), radii.get_y(), color);
	}

	export inline auto draw_filled_ellipse(float center_x, float center_y, float radii_x, float radii_y, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_ellipse(center_x, center_y, radii_x, radii_y, color);
	}

	export inline auto draw_filled_circle(const ALLEGRO::VECTOR_2D<float>& center, float r, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_circle(center.get_x(), center.get_y(), r, color);
	}

	export inline auto draw_filled_circle(float center_x, float center_y, float r, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_circle(center_x, center_y, r, color);
	}

	export inline auto draw_filled_pieslice(const ALLEGRO::VECTOR_2D<float>& center, float r, float start_theta, float delta_theta, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_pieslice(center.get_x(), center.get_y(), r, start_theta, delta_theta, color);
	}

	export inline auto draw_filled_pieslice(float center_x, float center_y, float r, float start_theta, float delta_theta, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_pieslice(center_x, center_y, r, start_theta, delta_theta, color);
	}

	export inline auto draw_filled_rounded_rectangle(const ALLEGRO::VECTOR_2D<float>& pos1, const ALLEGRO::VECTOR_2D<float>& pos2, const ALLEGRO::VECTOR_2D<float>& radii, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_rounded_rectangle(pos1.get_x(), pos1.get_y(), pos2.get_x(), pos2.get_y(), radii.get_x(), radii.get_y(), color);
	}

	export inline auto draw_filled_rounded_rectangle(float pos1_x, float pos1_y, float pos2_x, float pos2_y, float radii_x, float radii_y, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_rounded_rectangle(pos1_x, pos1_y, pos2_x, pos2_y, radii_x, radii_y, color);
	}

	export inline auto draw_polyline(const std::span<float>& vertices, int32_t vertex_count, int32_t join_style, int32_t cap_style, const ALLEGRO::COLOR& color, float thickness, float miter_limit) -> void
	{
		al_draw_polyline(vertices.data(), static_cast<int>(vertices.size()), vertex_count, join_style, cap_style, color, thickness, miter_limit);
	}

	export inline auto draw_polygon(const std::span<float>& vertices, int32_t join_style, const ALLEGRO::COLOR& color, float thickness, float miter_limit) -> void
	{
		al_draw_polygon(vertices.data(), static_cast<int>(vertices.size()), join_style, color, thickness, miter_limit);
	}

	export inline auto draw_filled_polygon(const std::span<float>& vertices, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_polygon(vertices.data(), static_cast<int>(vertices.size()), color);
	}

	export inline auto draw_filled_polygon_with_holes(const float* vertices, const int32_t* vertex_counts, ALLEGRO::COLOR color) -> void
	{
		al_draw_filled_polygon_with_holes(vertices, vertex_counts, color);
	}
}
