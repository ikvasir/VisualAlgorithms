#include "scene_properties_common_graph.h"

scene_properties_common_graph::scene_properties_common_graph(Qt3DCore::QEntity* root,QWidget *parent)
	: QWidget(parent)
{
	scene_entities_common_graph_ = new scene_entities_common_graph(root, this);

	QTreeWidget* tree_widget = new QTreeWidget(this);

	ADD_ROOT(tree_widget, vertex)
		ADD_LEAF_BEGIN(common_graph, vertex, mesh)
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, sphere, radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, sphere, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, sphere, slices);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cone, bottom_radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cone, length);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cone, top_radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cone, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cone, slices);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cone, has_bottom_endcap);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cone, has_top_endcap);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cuboid, x_extent);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cuboid, y_extent);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cuboid, z_extent);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cylinder, length);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cylinder, radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cylinder, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, cylinder, slices);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, plane, height);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, plane, width);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, torus, minor_radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, torus, radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, torus, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, mesh, torus, slices);
		ADD_LEAF_END(common_graph, vertex, mesh)
		ADD_LEAF_BEGIN(common_graph,vertex, material)
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_map, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular, alpha_blending);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, diffuse_specular, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, gooch, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, gooch, warm);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, gooch, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, gooch, cool);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, gooch, alpha);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, gooch, beta);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, gooch, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, metal_rough, base_color);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, metal_rough, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, morph_phong, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, morph_phong, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, morph_phong, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, morph_phong, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, morph_phong, interpolator);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, normal_diffuse_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, normal_diffuse_map, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, normal_diffuse_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, normal_diffuse_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, normal_diffuse_specular_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, normal_diffuse_specular_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, normal_diffuse_specular_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong_alpha, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong_alpha, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong_alpha, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong_alpha, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, phong_alpha, alpha);
			ADD_CONNECTION_PROPERTY_TO_STATE(vertex, material, texture, alpha_blending);
		ADD_LEAF_END(common_graph, vertex, material)
	
	ADD_ROOT(tree_widget,edge)
		
		ADD_LEAF_BEGIN(common_graph,edge, material)
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, alpha_blending);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, diffuse_specular, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, warm);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, cool);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, alpha);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, beta);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, gooch, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, metal_rough, base_color);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, metal_rough, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, morph_phong, interpolator);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_specular_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_specular_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, normal_diffuse_specular_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, phong_alpha, alpha);
			ADD_CONNECTION_PROPERTY_TO_STATE(edge, material, texture, alpha_blending);
		ADD_LEAF_END(common_graph, edge, material)

	ADD_ROOT(tree_widget, plane)

		/*ADD_LEAF_BEGIN(common_graph,plane, mesh)
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, sphere, radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, sphere, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, sphere, slices);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, bottom_radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, length);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, top_radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, slices);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, has_bottom_endcap);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cone, has_top_endcap);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cuboid, x_extent);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cuboid, y_extent);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cuboid, z_extent);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, length);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, cylinder, slices);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, plane, height);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, plane, width);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, minor_radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, radius);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, rings);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, mesh, torus, slices);
		ADD_LEAF_END(common_graph, plane, mesh)*/

		ADD_LEAF_BEGIN(common_graph, plane, material)
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, alpha_blending);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, diffuse_specular, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, warm);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, cool);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, alpha);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, beta);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, gooch, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, metal_rough, base_color);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, metal_rough, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, morph_phong, interpolator);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_specular_map, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_specular_map, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, normal_diffuse_specular_map, texture_scale);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, ambient);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, diffuse);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, specular);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, shininess);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, phong_alpha, alpha);
			ADD_CONNECTION_PROPERTY_TO_STATE(plane, material, texture, alpha_blending);
		ADD_LEAF_END(common_graph, plane, material)

	ADD_ROOT(tree_widget, camera)

	    ADD_LEAF_BEGIN(common_graph, camera, camera)
			ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, aspect_ratio);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, bottom);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, exposure);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, far_plane);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, near_plane);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, field_of_view);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, left);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, right);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, top);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, position);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, view_center);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, up_vector);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, projection_type);
		    ADD_CONNECTION_PROPERTY_TO_STATE(camera, camera, camera, projection_matrix);
		ADD_LEAF_END(common_graph, camera, camera)
				camera_camera_ptr = camera_camera;

		ADD_LEAF_BEGIN(common_graph, camera, camera_controller)
			ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,first_person, acceleration);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,first_person, deceleration);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,first_person, linear_speed);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,first_person, look_speed);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,first_person, camera);					
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,orbit, acceleration);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,orbit, deceleration);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,orbit, linear_speed);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,orbit, look_speed);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,orbit, camera);
            ADD_CONNECTION_PROPERTY_TO_STATE(camera,camera_controller,orbit, zoom_in_limit);
			ADD_LEAF_END(common_graph, camera, camera_controller)

	ADD_ROOT(tree_widget, light)

		ADD_LEAF_BEGIN(common_graph, light, light)
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, point, color);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, point, intensity);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, point, constant_attenuation);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, point, linear_attenuation);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, point, quadratic_attenuation);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, point, possition);

			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, directional, color);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, directional, intensity);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, directional, world_direction);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, directional, possition);

			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, color);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, intensity);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, constant_attenuation);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, linear_attenuation);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, quadratic_attenuation);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, cut_off_angle);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, local_direction);
			ADD_CONNECTION_PROPERTY_TO_STATE(light, light, spot, possition);
		ADD_LEAF_END(common_graph, light, light)



	

//////////////////////////////////////////////////////////////////////////////////
	tree_widget->headerItem()->setText(0,"Common graph scene entities:");
	tree_widget->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
	tree_widget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

	tree_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tree_widget->resizeColumnToContents(1);
	QScrollBar* scroll = tree_widget->verticalScrollBar();
	
	QHBoxLayout* this_layout = new QHBoxLayout;
	this_layout->addWidget(scroll);
	this_layout->addWidget(tree_widget);

	setLayout(this_layout);
	this->setMinimumHeight(550);

//////////////////////////////////////////////////////////////////////////////////

	
connect(this, &scene_properties_common_graph::scene_properties_common_graph_type_signal,
	scene_entities_common_graph_, &scene_entities_common_graph::scene_entities_common_graph_type_slot);
	
connect(this, &scene_properties_common_graph::scene_properties_common_graph_camera_signal,
	scene_entities_common_graph_, &scene_entities_common_graph::scene_entities_common_graph_camera_slot);

connect(this, &scene_properties_common_graph::scene_properties_common_graph_camera_signal,
	camera_camera, &property_camera::property_camera_camera_slot);


/////////////////////////////////////////////////////////////////////////////////////////////////
connect(this, &scene_properties_common_graph::scene_properties_common_graph_viewport_size_signal,
	scene_entities_common_graph_, &scene_entities_common_graph::scene_entities_common_graph_viewport_size_slot);

/////////////////////////////////////////////////////////////////////////////////////////////////
connect(component_states_light, &component_states::component_states_light_possition_signal,
     	scene_entities_common_graph_, &scene_entities_common_graph::scene_entities_common_graph_light_possition_slot);


/////////////////////////////////////////////////////////////////////////////////////////////////
connect(light_light, &property_light::property_light_possition_signal,
	this, [this] {
		auto pos = camera_camera_ptr->property_camera_possition();
		emit scene_properties_common_graph_light_possition(pos);

		auto dir = camera_camera_ptr->property_camera_direction();
		emit scene_properties_common_graph_light_direction(dir);
		
		
	});

connect(this, &scene_properties_common_graph::scene_properties_common_graph_light_possition,
	light_light, &property_light::property_light_possition_slot);

connect(this, &scene_properties_common_graph::scene_properties_common_graph_light_possition,
	component_states_light, &component_states::component_states_light_possition_slot);

connect(this, &scene_properties_common_graph::scene_properties_common_graph_light_direction,
	light_light, &property_light::property_light_direction_slot);

connect(this, &scene_properties_common_graph::scene_properties_common_graph_light_direction,
	component_states_light, &component_states::component_states_light_direction_slot);

}

scene_properties_common_graph::~scene_properties_common_graph()
{
}
