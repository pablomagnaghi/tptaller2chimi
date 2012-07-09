#include "UnionEntidadRelacion.h"

UnionEntidadRelacion::UnionEntidadRelacion(Entidad * e, Relacion * r) {
	this->entidad = e;
	this->relacion = r;

	e->agregarUnion(this);
	r->agregarUnionAEntidad(this);
}

UnionEntidadRelacion::~UnionEntidadRelacion() {

}

const std::string UnionEntidadRelacion::getCardinalidadMinima() const {
	return this->cardinalidadMinima;
}

void UnionEntidadRelacion::setCardinalidadMinima(
		const std::string & cardinalidad) {
	this->cardinalidadMinima = cardinalidad;
}

const std::string UnionEntidadRelacion::getCardinalidadMaxima() const {
	return this->cardinalidadMaxima;
}

void UnionEntidadRelacion::setCardinalidadMaxima(
		const std::string & cardinalidad) {
	this->cardinalidadMaxima = cardinalidad;
}

Entidad * UnionEntidadRelacion::getEntidad(){
	return this->entidad;
}

Relacion * UnionEntidadRelacion::getRelacion(){
	return this->relacion;
}

// PERSISTENCIA COMP
/*
 EntidadRelacion::EntidadRelacion(XmlNodo* nodo) {
 this->codigoEntidad = nodo->getPropiedadInt("entidad");
 this->cardinalidadMinima = nodo->getPropiedad("cardinalidad_minima");
 this->cardinalidadMaxima = nodo->getPropiedad("cardinalidad_maxima");
 this->rol = nodo->getPropiedad("rol");
 }

 XmlNodo EntidadRelacion::guardarXmlCOMP() {
 XmlNodo nodo("entidad_relacion");

 nodo.setPropiedad("entidad",this->codigoEntidad);
 nodo.setPropiedad("cardinalidad_minima",this->cardinalidadMinima);
 nodo.setPropiedad("cardinalidad_maxima",this->cardinalidadMaxima);
 if (this->rol.size())
 nodo.setPropiedad("rol",this->rol);

 return nodo;
 }
 */
