#ifndef CONTROLADORPANELHERRAMIENTAS_H_
#define CONTROLADORPANELHERRAMIENTAS_H_

#include <gtkmm.h>
#include "../vista/VistaDiagrama.h"
#include "../vista/VistaProyecto.h"
#include "ComponentsBuilder.h"


class Ide;

class ControladorPanelHerramientas {
private:
	Ide * ide;
	Gtk::Window * ventanaPrincipal;
	Glib::RefPtr<Gtk::Builder> m_builder;

	Gtk::ToolButton * botonAgregarEntidad;
	Gtk::ToolButton * botonAgregarRelacion;
	Gtk::ToolButton * botonAgregarJerarquia;
	Gtk::ToolButton * botonAgregarUnion;
	Gtk::ToolButton * botonAgregarComentario;

	void on_boton_Agregar_Entidad_click();
	void on_boton_Agregar_Relacion_click();
	void on_boton_Agregar_Jerarquia_click();
	void on_boton_Agregar_Union_click();
	void on_boton_Agregar_Comentario_click();

	void enlazar_botones_de_menu(const Glib::RefPtr<Gtk::Builder>& builder);
public:
	ControladorPanelHerramientas(const Glib::RefPtr<Gtk::Builder>& builder, Gtk::Window * ventana);
	virtual ~ControladorPanelHerramientas();
	void setIde(Ide* ide);
	void activarBotones();
	void desactivarBotones();
};

#endif /* CONTROLADORPANELHERRAMIENTAS_H_ */
