export module allegro:transformations;

import std;
import <allegro5/transformations.h>;
import :base;
import :bitmap;
import :vector_2d;
import :vector_3d;
import :vector_4d;

namespace ALLEGRO
{
	export using TRANSFORM = typename ALLEGRO_TRANSFORM;
}

namespace al
{
	export inline auto use_transform(const ALLEGRO::TRANSFORM& trans) -> void
	{
		al_use_transform(&trans);
	}

	export inline auto use_projection_transform(const ALLEGRO::TRANSFORM& trans) -> void
	{
		al_use_projection_transform(&trans);
	}

	export inline auto copy_transform(ALLEGRO::TRANSFORM& dest, const ALLEGRO::TRANSFORM& src) -> void
	{
		al_copy_transform(&dest, &src);
	}

	export inline auto identity_transform(ALLEGRO::TRANSFORM& trans) -> void
	{
		al_identity_transform(&trans);
	}

	export inline auto build_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_2D<float>& translation, const ALLEGRO::VECTOR_2D<float>& scale, float theta) -> void
	{
		al_build_transform(&trans, translation.get_x(), translation.get_y(), scale.get_x(), scale.get_y(), theta);
	}

	export inline auto build_transform(ALLEGRO::TRANSFORM& trans, float translation_x, float translation_y, float scale_x, float scale_y, float theta) -> void
	{
		al_build_transform(&trans, translation_x, translation_y, scale_x, scale_y, theta);
	}

	export inline auto build_camera_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_3D<float>& position, const ALLEGRO::VECTOR_3D<float>& look, const ALLEGRO::VECTOR_3D<float>& up) -> void
	{
		al_build_camera_transform(&trans, position.get_x(), position.get_y(), position.get_z(), look.get_x(), look.get_y(), look.get_z(), up.get_x(), up.get_y(), up.get_z());
	}

	export inline auto build_camera_transform(ALLEGRO::TRANSFORM& trans, float pos_x, float pos_y, float pos_z, float look_x, float look_y, float look_z, float up_x, float up_y, float up_z) -> void
	{
		al_build_camera_transform(&trans, pos_x, pos_y, pos_z, look_x, look_y, look_z, up_x, up_y, up_z);
	}

	export inline auto translate_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_2D<float>& translation) -> void
	{
		al_translate_transform(&trans, translation.get_x(), translation.get_y());
	}

	export inline auto translate_transform(ALLEGRO::TRANSFORM& trans, float x, float y) -> void
	{
		al_translate_transform(&trans, x, y);
	}

	export inline auto translate_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_3D<float>& translation) -> void
	{
		al_translate_transform_3d(&trans, translation.get_x(), translation.get_y(), translation.get_z());
	}

	export inline auto translate_transform_3d(ALLEGRO::TRANSFORM& trans, float x, float y, float z) -> void
	{
		al_translate_transform_3d(&trans, x, y, z);
	}

	export inline auto rotate_transform(ALLEGRO::TRANSFORM& trans, float theta) -> void
	{
		al_rotate_transform(&trans, theta);
	}

	export inline auto rotate_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_3D<float>& v, float angle) -> void
	{
		al_rotate_transform_3d(&trans, v.get_x(), v.get_y(), v.get_z(), angle);
	}

	export inline auto rotate_transform_3d(ALLEGRO::TRANSFORM& trans, float x, float y, float z, float angle) -> void
	{
		al_rotate_transform_3d(&trans, x, y, z, angle);
	}

	export inline auto scale_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_2D<float>& scale) -> void
	{
		al_scale_transform(&trans, scale.get_x(), scale.get_y());
	}

	export inline auto scale_transform(ALLEGRO::TRANSFORM& trans, float x, float y) -> void
	{
		al_scale_transform(&trans, x, y);
	}

	export inline auto scale_transform_3d(ALLEGRO::TRANSFORM& trans, float x, float y, float z) -> void
	{
		al_scale_transform_3d(&trans, x, y, z);
	}

	export inline auto scale_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_3D<float>& scale) -> void
	{
		al_scale_transform_3d(&trans, scale.get_x(), scale.get_y(), scale.get_z());
	}

	export inline auto transform_coordinates(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR_2D<float>& vector) -> void
	{
		al_transform_coordinates(&trans, &vector[0], &vector[1]);
	}

	export inline auto transform_coordinates(const ALLEGRO::TRANSFORM& trans, float& x, float& y) -> void
	{
		al_transform_coordinates(&trans, &x, &y);
	}

	export inline auto transform_coordinates_3d(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR_3D<float>& vector) -> void
	{
		al_transform_coordinates_3d(&trans, &vector[0], &vector[1], &vector[2]);
	}

	export inline auto transform_coordinates_3d(const ALLEGRO::TRANSFORM& trans, float& x, float& y, float& z) -> void
	{
		al_transform_coordinates_3d(&trans, &x, &y, &z);
	}

	export inline auto transform_coordinates_4d(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR_4D<float>& vector) -> void
	{
		al_transform_coordinates_4d(&trans, &vector[0], &vector[1], &vector[2], &vector[3]);
	}

	export inline auto transform_coordinates_4d(const ALLEGRO::TRANSFORM& trans, float& x, float& y, float& z, float& w) -> void
	{
		al_transform_coordinates_4d(&trans, &x, &y, &z, &w);
	}

	export inline auto transform_coordinates_3d_projective(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR_3D<float>& vector) -> void
	{
		al_transform_coordinates_3d_projective(&trans, &vector[0], &vector[1], &vector[2]);
	}

	export inline auto compose_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::TRANSFORM& other) -> void
	{
		al_compose_transform(&trans, &other);
	}

	export inline auto get_current_transform() -> const ALLEGRO::TRANSFORM&
	{
		return *al_get_current_transform();
	}

	export inline auto get_current_inverse_transform() -> const ALLEGRO::TRANSFORM&
	{
		return *al_get_current_inverse_transform();
	}

	export inline auto get_current_projection_transform() -> const ALLEGRO::TRANSFORM&
	{
		return *al_get_current_projection_transform();
	}

	export inline auto invert_transform(ALLEGRO::TRANSFORM& trans) -> void
	{
		al_invert_transform(&trans);
	}

	export inline auto transpose_transform(ALLEGRO::TRANSFORM& trans) -> void
	{
		al_transpose_transform(&trans);
	}

	export inline auto check_inverse(const ALLEGRO::TRANSFORM& trans, float tolerance) -> int32_t
	{
		return al_check_inverse(&trans, tolerance);
	}

	export inline auto orthographic_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_2D<float>& top_left, const ALLEGRO::VECTOR_2D<float>& bottom_right, float near, float far) -> void
	{
		al_orthographic_transform(&trans, top_left.get_x(), top_left.get_y(), near, bottom_right.get_x(), bottom_right.get_y(), far);
	}

	export inline auto orthographic_transform(ALLEGRO::TRANSFORM& trans, float left, float top, float near, float right, float bottom, float far) -> void
	{
		al_orthographic_transform(&trans, left, top, near, right, bottom, far);
	}

	export inline auto perspective_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR_2D<float>& top_left, float near, const ALLEGRO::VECTOR_2D<float>& bottom_right, float far) -> void
	{
		al_perspective_transform(&trans, top_left.get_x(), top_left.get_y(), near, bottom_right.get_x(), bottom_right.get_y(), far);
	}

	export inline auto perspective_transform(ALLEGRO::TRANSFORM& trans, float left, float top, float near, float right, float bottom, float far) -> void
	{
		al_perspective_transform(&trans, left, top, near, right, bottom, far);
	}

	export inline auto horizontal_shear_transform(ALLEGRO::TRANSFORM& trans, float theta) -> void
	{
		al_horizontal_shear_transform(&trans, theta);
	}

	export inline auto vertical_shear_transform(ALLEGRO::TRANSFORM& trans, float theta) -> void
	{
		al_vertical_shear_transform(&trans, theta);
	}
}
