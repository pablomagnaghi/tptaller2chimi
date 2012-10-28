#ifndef VISTAENTIDADGLOBAL_H_
#define VISTAENTIDADGLOBAL_H_

#include "VistaEntidad.h"
#include "../../modelo/componentes/EntidadGlobal.h"

class VistaEntidadGlobal: public VistaEntidad {
private:
	EntidadGlobal * entidad;

	void calcular_ancho_a_partir_del_nombre();
	void dibujarFiguraDeEntidad(Cairo::RefPtr<Cairo::Context> cr);
	void dibujarCirculosDeRedimension(Cairo::RefPtr<Cairo::Context> cr);
	bool prop_lanzada;
public:
	VistaEntidadGlobal(EntidadGlobal *);
	virtual ~VistaEntidadGlobal();

	virtual bool contieneEsteComponente(Componente *);

	//Dibuja el objeto en el contexto cairo pasado como parametro.
	virtual void dibujar(Cairo::RefPtr<Cairo::Context> cr);

	//Lanza el asistente de prpiedades del objeto en cuestion.
	virtual bool lanzarProp();

	// Verifica si el punto cae dentro de este componente
	virtual bool contieneAEstePunto(double x, double y);

	virtual void calcularDimensionesAPartirDeTexto(Cairo::TextExtents * textExtents);

	// Verifica si el punto cae dentro de un punto para redimensionar el elemento
	virtual bool esPuntoDeRedimension(double x, double y);

	virtual void setMouseArriba(double x, double y);

	virtual void redimensionar(double x, double y);

	void setNombre(const std::string & nombre);
	virtual std::string getNombre() const;


};

#endif /* VISTAENTIDADGLOBAL_H_ */
