#pragma once


#include <QWidget>
#include "enums.h"

#include <qcombobox.h>
#include <qlabel.h>
#include <qgridlayout.h>
#include <qstackedlayout.h>
#include <qcheckbox.h>
#include <qspinbox.h>

#include "property_macros.h"

#include <qjsonobject.h>
#include <qfile.h>
#include <qdir.h>
#include <qjsondocument.h>
#include <qjsonvalue.h>
#include <qbytearray.h>

class property_mesh : public QWidget
{
	Q_OBJECT

public:
	property_mesh(QString parentPath, QWidget *parent = Q_NULLPTR);
	~property_mesh();

private:
	QComboBox* combobox_mesh;
	QString parentPath_;
	ADD_JSON_LOADER(sphere)
	ADD_JSON_LOADER(cone)
	ADD_JSON_LOADER(cuboid)
	ADD_JSON_LOADER(cylinder)
	ADD_JSON_LOADER(plane)
	ADD_JSON_LOADER(torus)


signals:

	void property_mesh_type_signal(int);


	ADD_SIGNAL_FOR_ENTITY(mesh, sphere, radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, sphere, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh, sphere, slices, int);

	ADD_SIGNAL_FOR_ENTITY(mesh, cone, bottom_radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, length, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, top_radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, slices, int);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, has_bottom_endcap, bool);
	ADD_SIGNAL_FOR_ENTITY(mesh, cone, has_top_endcap, bool);

	ADD_SIGNAL_FOR_ENTITY(mesh,cuboid, x_extent,double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cuboid, y_extent, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cuboid, z_extent, double);

	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, length, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh,cylinder, slices, int);

	ADD_SIGNAL_FOR_ENTITY(mesh,plane, height, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,plane, width, double);

	ADD_SIGNAL_FOR_ENTITY(mesh,torus, minor_radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,torus, radius, double);
	ADD_SIGNAL_FOR_ENTITY(mesh,torus, rings, int);
	ADD_SIGNAL_FOR_ENTITY(mesh,torus, slices, int);


};
