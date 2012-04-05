/*
 * Diagrama.cpp
 *
 *  Created on: 02/04/2012
 *      Author: Guagnini Enzo 88325
 */

#include "Diagrama.h"

Diagrama::Diagrama(string nom) : nombre(nom) {
	this->zoom = ZOOM_DEFECTO;
	int ancho = A4_ANCHO * zoom;
	int alto = A4_ALTO * zoom;
	this->set_size_request(ancho,alto);
}

Diagrama::~Diagrama() {
	// TODO Auto-generated destructor stub
}


bool Diagrama::on_expose_event(GdkEventExpose* e){
	int ancho = A4_ANCHO * zoom;
	int alto = A4_ALTO * zoom;
	this->set_size_request(ancho,alto);
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

Diagrama* Diagrama::crearSubdiagrama(string nombre){
	Diagrama* diag = new Diagrama(nombre);
	this->l_sub_diagramas.push_back(diag);
	return diag;
}

void Diagrama::setZoom(double z){
	if ((z >= ZOOM_MIN) && (z<=ZOOM_MAX)){
		this->zoom = z;
		this->ancho = A4_ANCHO * z;
		this->alto = A4_ALTO * z;
	}
}

int Diagrama::getAlto(){
	return this->alto;
}

int Diagrama::getAncho(){
	return this->ancho;
}
