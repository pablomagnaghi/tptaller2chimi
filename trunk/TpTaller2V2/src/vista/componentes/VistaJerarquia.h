#ifndef VISTAJERARQUIA_H_
#define VISTAJERARQUIA_H_

#include "VistaComponente.h"
#include "VistaEntidadNueva.h"
#include "../../controlador/AsistenteJerarquia.h"

#include "../../modelo/componentes/Jerarquia.h"

#include <vector>

class VistaEntidadNueva;

class VistaJerarquia: public VistaComponente {
private:
	bool prop_lanzada;
	Jerarquia * jerarquia;
	VistaEntidad * padre;
	std::vector<VistaEntidadNueva *> hijos;

	void dibujarLineaMedia(Cairo::RefPtr<Cairo::Context> cr, double ymin, double ymax);
public:
	VistaJerarquia(Jerarquia * jerarquiaModelo);
	virtual ~VistaJerarquia();

	virtual void dibujar(Cairo::RefPtr<Cairo::Context> cr);
	virtual bool esSeleccionado(double x, double y);
	virtual void finSeleccionado(double x, double y);
	virtual bool lanzarProp();
	void resetearLanzarProp();
	virtual bool contieneAEstePunto(double x, double y);
	virtual void calcularDimensionesAPartirDeTexto(Cairo::TextExtents * textExtents);
	virtual bool esPuntoDeRedimension(double x, double y);
	virtual void setMouseArriba(double x, double y);
	virtual void redimensionar(double x, double y);
	void setNombre(const std::string & nombre);
	virtual std::string getNombre() const;
	virtual bool contieneEsteComponente(Componente *);
	virtual bool obtenerInterseccionConLinea(double pos_ini_x, double pos_ini_y, double pos_fin_x,
			double pos_fin_y, double & x, double & y);

	// Interfaz para modificar la Jerarquia
	void agregarEntidadEspecializada(VistaEntidadNueva *);
	void removerEntidadEspecializada(VistaEntidadNueva *);
	std::vector<VistaEntidadNueva *>::iterator entidadesEspecializadasBegin();
	std::vector<VistaEntidadNueva *>::iterator entidadesEspecializadasEnd();
	void setEntidadPadre(VistaEntidad *);
	VistaEntidad * getEntidadPadre();

};

#endif /* VISTAJERARQUIA_H_ */
