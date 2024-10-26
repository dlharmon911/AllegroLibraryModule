export module allegro:transformations;

import <string>;
import <allegro5/transformations.h>;
import :base;
import :bitmap;

namespace ALLEGRO
{
	export using TRANSFORM = ALLEGRO_TRANSFORM;
}

namespace al
{
	export inline auto use_transform(const ALLEGRO::TRANSFORM& trans) -> void
	{
		return al_use_transform(&trans);
	}

	export inline auto use_projection_transform(const ALLEGRO::TRANSFORM& trans) -> void
	{
		return al_use_projection_transform(&trans);
	}

	export inline auto copy_transform(ALLEGRO::TRANSFORM& dest, const ALLEGRO::TRANSFORM& src) -> void
	{
		al_copy_transform(&dest, &src);
	}

	export inline auto identity_transform(ALLEGRO::TRANSFORM& trans) -> void
	{
		return al_identity_transform(&trans);
	}

	export inline auto build_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float>& translation, const ALLEGRO::POINT<float>& scale, float theta) -> void
	{
		al_build_transform(&trans, translation.x, translation.y, scale.x, scale.y, theta);
	}

	export inline auto build_camera_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& position, const ALLEGRO::VECTOR3<float>& look, const ALLEGRO::VECTOR3<float>& up) -> void
	{
		al_build_camera_transform(&trans, position.x, position.y, position.z, look.x, look.y, look.z, up.x, up.y, up.z);
	}

	export inline auto translate_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float>& translation) -> void
	{
		al_translate_transform(&trans, translation.x, translation.y);
	}

	export inline auto translate_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& translation) -> void
	{
		al_translate_transform_3d(&trans, translation.x, translation.y, translation.z);
	}

	export inline auto rotate_transform(ALLEGRO::TRANSFORM& trans, float theta) -> void
	{
		al_rotate_transform(&trans, theta);
	}

	export inline auto rotate_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& v, float angle) -> void
	{
		al_rotate_transform_3d(&trans, v.x, v.y, v.z, angle);
	}

	export inline auto scale_transform(ALLEGRO::TRANSFORM& trans, ALLEGRO::POINT<float>& scale) -> void
	{
		al_scale_transform(&trans, scale.x, scale.y);
	}

	export inline auto scale_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& scale) -> void
	{
		al_scale_transform_3d(&trans, scale.x, scale.y, scale.y);
	}

	export inline auto transform_coordinates(const ALLEGRO::TRANSFORM& trans, ALLEGRO::POINT<float>& point32_t) -> void
	{
		al_transform_coordinates(&trans, &point32_t.x, &point32_t.y);
	}

	export inline auto transform_coordinates_3d(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR3<float>& point32_t) -> void
	{
		al_transform_coordinates_3d(&trans, &point32_t.x, &point32_t.y, &point32_t.z);
	}

	export inline auto transform_coordinates_4d(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR4<float>& point32_t) -> void
	{
		al_transform_coordinates_4d(&trans, &point32_t.x, &point32_t.y, &point32_t.z, &point32_t.w);
	}

	export inline auto transform_coordinates_3d_projective(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR3<float>& point32_t) -> void
	{
		al_transform_coordinates_3d_projective(&trans, &point32_t.x, &point32_t.y, &point32_t.z);
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

	export inline auto orthographic_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float>& top_left, const ALLEGRO::POINT<float>& bottom_right, float near, float far) -> void
	{
		al_orthographic_transform(&trans, top_left.x, top_left.y, near, bottom_right.x, bottom_right.y, far);
	}

	export inline auto perspective_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float>& top_left, const ALLEGRO::POINT<float>& bottom_right, float near, float far) -> void
	{
		al_perspective_transform(&trans, top_left.x, top_left.y, near, bottom_right.x, bottom_right.y, far);
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

