/*
 * Diagrama.cpp
 *
 *  Created on: 02/04/2012
 *      Author: Guagnini Enzo 88325
 */

#include "Diagrama.h"

Diagrama::Diagrama() {
	this->set_size_request(A4_ANCHO, A4_ALTO);
}

Diagrama::~Diagrama() {
	// TODO Auto-generated destructor stub
}


bool Diagrama::on_expose_event(GdkEventExpose* e){
	Cairo::RefPtr<Cairo::Context> cr = this->get_window()->create_cairo_context();
	cr->set_source_rgba(1, 1, 1, 1);   // white
	cr->paint();
	/*if (this->imagenfondo != ""){
		try{
			Cairo::RefPtr<Cairo::ImageSurface> surface =
					Cairo::ImageSurface::create_from_png(this->imagenfondo);
			if (surface){
				cr->set_source(surface,0,0);
				cr->paint();
			}
		} catch (Glib::Error e){
			this->imagenfondo = "";
		} catch (std::exception e1){
			this->imagenfondo = "";
		}
	}
	cr->stroke();
	list<Disenio_Objeto*>::iterator it1 = this->listaObjetos.begin();
	list<Disenio_Objeto*>::iterator it2 = this->listaObjetos.end();
	while(it1 != it2){
		(*it1)->dibujar(cr);
		it1++;
	}*/
	return true;
}

bool Diagrama::on_button_press_event(GdkEventButton* event){
	/*//Dependiendo del boton seleccionado en el panel ejecutamos diferentes acciones
	int accion = this->panelAcciones->getBotonSeleccionado();
	(this->*acciones[accion])(event);
	this->redibujar();
	return true;*/
}

bool Diagrama::on_button_release_event(GdkEventButton* event){
	/*//Dependiendo del boton seleccionado en el panel ejecutamos diferentes acciones
	int accion = this->panelAcciones->getBotonSeleccionado();
	(this->*acciones[accion])(event);
	return true;*/
}
