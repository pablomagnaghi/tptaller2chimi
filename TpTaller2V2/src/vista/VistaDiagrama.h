/*
 * Diagrama.h
 *
 *  Created on: 02/04/2012
 *      Author: Guagnini Enzo 88325
 */

#ifndef VISTADIAGRAMA_H_
#define VISTADIAGRAMA_H_

#include "../modelo/Diagrama.h"
#include <list>
#include <vector>
#include "VistaConstantes.h"
#include "./componentes/VistaComponente.h"
#include "./componentes/VistaAtributo.h"
#include "./componentes/VistaEntidad.h"
#include "./componentes/VistaRelacion.h"
#include "./componentes/VistaUnion.h"
#include "gtkmm.h"

using namespace std;

class VistaDiagrama: public Gtk::DrawingArea, public Diagrama {
private:
	double zoom;
	int ancho;
	int alto;

	std::vector<VistaComponente *> componentes;
	std::vector<VistaComponente *> componentes_seleccionados;

	// Para controlar el drag and drop
	bool mouse_apretado;
	gdouble x_button_press;
	gdouble y_button_press;

	// Redefinicion del metodo de Gtk::DrawingArea q se llama cada vez q debe dibujarse la hoja.
	bool on_expose_event(GdkEventExpose* e);

	// Se lanza cada vez que el mouse interactua con la hoja presionando alguno de sus botones
	bool on_button_press_event(GdkEventButton* event);

	// Se lanza cada vez que el mouse interactua con la hoja soltando alguno de sus botones
	bool on_button_release_event(GdkEventButton* event);

	friend class TreePanel;
	friend class VistaProyecto;

	void configurar_drag_and_drop();

	// Señales para Drag and Drop
	// Origen
	// Cuando comienza a arrastrar un objeto
	void drag_begin(const Glib::RefPtr<Gdk::DragContext>&);
	// Cuando realiza el movimiento de arrastre de objeto
	bool drag_motion(const Glib::RefPtr<Gdk::DragContext>& context, gint x,
			int y, guint time);
	// Cuando se obtienen los datos del origen
	void drag_data_get(const Glib::RefPtr<Gdk::DragContext>&,
			Gtk::SelectionData& selection_data, guint, guint);
	// Cuando ya se soltó el objeto y se pasaron los datos al destino
	bool drag_drop(const Glib::RefPtr<Gdk::DragContext>& context, gint x, gint y,
			guint time);
	// Cuando finaliza el arrastre
	void drag_end(const Glib::RefPtr<Gdk::DragContext>&);
	// Cuando se debe eliminar los datos al MOVER
	void drag_data_delete(const Glib::RefPtr<Gdk::DragContext>&);
	// Cuando el objeto arrastrado se suelta en un objeto que no es destino
	bool drag_failed(const Glib::RefPtr<Gdk::DragContext>&, Gtk::DragResult);
	// Cuando el arrastre sale del objeto donde comenzo
	void drag_leave(const Glib::RefPtr<Gdk::DragContext>&,guint);

	// Destino
	// Cuando el destino recibe los datos del objeto arrastrado
	void drag_data_received(const Glib::RefPtr<Gdk::DragContext>& context, gint,
			int, const Gtk::SelectionData& selection_data, guint, guint time);

	void test_cargar_componentes_visuales();
	void seleccionar_componente_clickeado(gdouble x, gdouble y);

public:

	VistaDiagrama(string nom);
	virtual ~VistaDiagrama();

	void setZoom(double z);

	virtual VistaDiagrama* crearDiagramaHijo(string nombre);
	int getAlto();
	int getAncho();
};

#endif /* VISTADIAGRAMA_H_ */
