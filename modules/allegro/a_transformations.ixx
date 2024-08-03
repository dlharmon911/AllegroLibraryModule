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
	export inline void use_transform(const ALLEGRO::TRANSFORM& trans)
	{
		return al_use_transform(&trans);
	}

	export inline void use_projection_transform(const ALLEGRO::TRANSFORM& trans)
	{
		return al_use_projection_transform(&trans);
	}

	export inline void copy_transform(ALLEGRO::TRANSFORM& dest, const ALLEGRO::TRANSFORM& src)
	{
		al_copy_transform(&dest, &src);
	}

	export inline void identity_transform(ALLEGRO::TRANSFORM& trans)
	{
		return al_identity_transform(&trans);
	}

	export inline void build_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float> translation, const ALLEGRO::POINT<float> scale, float theta)
	{
		al_build_transform(&trans, translation.x, translation.y, scale.x, scale.y, theta);
	}

	export inline void build_camera_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& position, const ALLEGRO::VECTOR3<float>& look, const ALLEGRO::VECTOR3<float>& up)
	{
		al_build_camera_transform(&trans, position.x, position.y, position.z, look.x, look.y, look.z, up.x, up.y, up.z);
	}

	export inline void translate_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float> translation)
	{
		al_translate_transform(&trans, translation.x, translation.y);
	}

	export inline void translate_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& translation)
	{
		al_translate_transform_3d(&trans, translation.x, translation.y, translation.z);
	}

	export inline void rotate_transform(ALLEGRO::TRANSFORM& trans, float theta)
	{
		al_rotate_transform(&trans, theta);
	}

	export inline void rotate_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& v, float angle)
	{
		al_rotate_transform_3d(&trans, v.x, v.y, v.z, angle);
	}

	export inline void scale_transform(ALLEGRO::TRANSFORM& trans, ALLEGRO::POINT<float>& scale)
	{
		al_scale_transform(&trans, scale.x, scale.y);
	}

	export inline void scale_transform_3d(ALLEGRO::TRANSFORM& trans, const ALLEGRO::VECTOR3<float>& scale)
	{
		al_scale_transform_3d(&trans, scale.x, scale.y, scale.y);
	}

	export inline void transform_coordinates(const ALLEGRO::TRANSFORM& trans, ALLEGRO::POINT<float>& point32_t)
	{
		al_transform_coordinates(&trans, &point32_t.x, &point32_t.y);
	}

	export inline void transform_coordinates_3d(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR3<float>& point32_t)
	{
		al_transform_coordinates_3d(&trans, &point32_t.x, &point32_t.y, &point32_t.z);
	}

	export inline void transform_coordinates_4d(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR4<float>& point32_t)
	{
		al_transform_coordinates_4d(&trans, &point32_t.x, &point32_t.y, &point32_t.z, &point32_t.w);
	}

	export inline void transform_coordinates_3d_projective(const ALLEGRO::TRANSFORM& trans, ALLEGRO::VECTOR3<float>& point32_t)
	{
		al_transform_coordinates_3d_projective(&trans, &point32_t.x, &point32_t.y, &point32_t.z);
	}

	export inline void compose_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::TRANSFORM& other)
	{
		al_compose_transform(&trans, &other);
	}

	export inline const ALLEGRO::TRANSFORM& get_current_transform()
	{
		return *al_get_current_transform();
	}

	export inline const ALLEGRO::TRANSFORM& get_current_inverse_transform()
	{
		return *al_get_current_inverse_transform();
	}

	export inline const ALLEGRO::TRANSFORM& get_current_projection_transform()
	{
		return *al_get_current_projection_transform();
	}

	export inline void invert_transform(ALLEGRO::TRANSFORM& trans)
	{
		al_invert_transform(&trans);
	}

	export inline void transpose_transform(ALLEGRO::TRANSFORM& trans)
	{
		al_transpose_transform(&trans);
	}

	export inline int32_t check_inverse(const ALLEGRO::TRANSFORM& trans, float tolerance)
	{
		return al_check_inverse(&trans, tolerance);
	}

	export inline void orthographic_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float> top_left, const ALLEGRO::POINT<float> bottom_right, float near, float far)
	{
		al_orthographic_transform(&trans, top_left.x, top_left.y, near, bottom_right.x, bottom_right.y, far);
	}

	export inline void perspective_transform(ALLEGRO::TRANSFORM& trans, const ALLEGRO::POINT<float> top_left, const ALLEGRO::POINT<float> bottom_right, float near, float far)
	{
		al_perspective_transform(&trans, top_left.x, top_left.y, near, bottom_right.x, bottom_right.y, far);
	}

	export inline void horizontal_shear_transform(ALLEGRO::TRANSFORM& trans, float theta)
	{
		al_horizontal_shear_transform(&trans, theta);
	}

	export inline void vertical_shear_transform(ALLEGRO::TRANSFORM& trans, float theta)
	{
		al_vertical_shear_transform(&trans, theta);
	}
}

