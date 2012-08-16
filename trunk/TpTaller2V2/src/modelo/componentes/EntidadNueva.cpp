#include "EntidadNueva.h"

EntidadNueva::EntidadNueva() {
	this->nombre = "Entidad Nueva";

}

EntidadNueva::~EntidadNueva() {
	this->borrarAtributos();
	this->borrarIdentificadores();
}

void EntidadNueva::setEsDebil(bool esDebil) {
	this->esDebil = esDebil;
}

bool EntidadNueva::getEsDebil() {
	return this->esDebil;
}

void EntidadNueva::agregarAtributo(Atributo* atributo) throw (NullPointer) {
	if (atributo == NULL) {
		throw NullPointer("Puntero nulo en agregarAtributo en EntidadNueva");
	}
	this->atributos.push_back(atributo);
}

void EntidadNueva::quitarAtributo(Atributo* atributo) throw (NullPointer) {
	if (atributo == NULL) {
		throw NullPointer("Puntero nulo en quitarAtributo en EntidadNueva");
	}
	remove(this->atributos.begin(), this->atributos.end(), atributo);
}


void EntidadNueva::agregarJerarquiaPadre(Jerarquia *j) throw (NullPointer) {
	if (j == NULL) {
		throw NullPointer("Puntero nulo en agregarJerarquiaPadre en EntidadNueva");
	}
	this->jerarquiasPadre.push_back(j);
}

void EntidadNueva::quitarJerarquiaPadre(Jerarquia *j) throw (NullPointer) {
	if (j == NULL) {
		throw NullPointer("Puntero nulo en quitarJerarquiaPadre en EntidadNueva");
	}
	remove(this->jerarquiasPadre.begin(), this->jerarquiasPadre.end(), j);
}

void EntidadNueva::agregarIdentificador(Identificador *identificador) throw (NullPointer) {
	if (identificador == NULL) {
		throw NullPointer("Puntero nulo en agregarIdentificador en EntidadNueva");
	}
	this->identificadores.push_back(identificador);
}

void EntidadNueva::quitarIdentificador(Identificador *identificador) throw (NullPointer) {
	if (identificador == NULL) {
		throw NullPointer("Puntero nulo en quitarIdentificador en EntidadNueva");
	}
	remove(this->identificadores.begin(), this->identificadores.end(), identificador);
}

std::string EntidadNueva::getTipo() const {
	return tipo;
}

void EntidadNueva::setTipo(const std::string& tipo) {
	this->tipo = tipo;
}

// ITERADORES

std::vector<Atributo*>::iterator EntidadNueva::atributosBegin() {
	return this->atributos.begin();
}

std::vector<Atributo*>::iterator EntidadNueva::atributosEnd() {
	return this->atributos.end();
}

std::vector<Jerarquia*>::iterator EntidadNueva::jerarquiasPadreBegin(){
	return this->jerarquiasPadre.begin();
}

std::vector<Jerarquia*>::iterator EntidadNueva::jerarquiasPadreEnd(){
	return this->jerarquiasPadre.end();
}

std::vector<Identificador*>::iterator EntidadNueva::identificadoresBegin() {
	return this->identificadores.begin();
}

std::vector<Identificador*>::iterator EntidadNueva::identificadoresEnd() {
	return this->identificadores.end();
}

void EntidadNueva::borrarAtributos() {
	std::vector<Atributo*>::iterator it = this->atributos.begin();
	while (it != this->atributos.end()) {
		delete (*it);
		it++;
	}
	this->atributos.clear();
}

void EntidadNueva::borrarIdentificadores() {
	std::vector<Identificador*>::iterator it = this->identificadores.begin();
	while (it != this->identificadores.end()) {
		delete (*it);
		it++;
	}
	this->identificadores.clear();
}

Atributo* EntidadNueva::getAtributoByCodigo(int codigo) {
	Atributo* atributo = NULL;
	std::vector<Atributo*>::iterator it = this->atributos.begin();
	while (it != this->atributos.end()) {
		if ((*it)->getCodigo() == codigo) {
			atributo = *it;
		}
		it++;
	}
	return atributo;
}

bool EntidadNueva::existeAtributo(const std::string& nombre){
	std::string nombreMin = toLowerCase(nombre);
	std::vector<Atributo*>::iterator it = this->atributos.begin();
	while (it != this->atributos.end()) {
		if (toLowerCase((*it)->getNombre()).compare(nombreMin) == 0) {
			return true;
		}
		it++;
	}
	return false;
}

// PERSISTENCIA COMP

/*
 // PERSISTENCIA COMP

 //CARGAR

 EntidadNueva::EntidadNueva(XmlNodo* nodo) {

 this->obtenerPropiedadesXmlCOMP(nodo);

 XmlNodo nodoAux = nodo->getHijo();

 this->obtenerComponentesXmlCOMP(&nodoAux);
 }

 void EntidadNueva::obtenerComponentesIdentificadorXmlCOMP(XmlNodo* nodo, Identificador* identificador) {
 XmlNodo nodoAux = nodo->getHijo();

 while (nodoAux.esValido()) {
 if (nodoAux.getNombre() == "atributo") {
 identificador->agregarCodigoAtributo(nodoAux.getContenidoInt());
 }
 if (nodoAux.getNombre() == "relacion")	{
 identificador->agregarCodigoRelacion(nodoAux.getContenidoInt());
 }
 nodoAux = nodoAux.getHermano();
 }
 }

 void EntidadNueva::obtenerComponentesXmlCOMP(XmlNodo* nodo) {
 while (nodo->esValido()) {
 if (nodo->getNombre() == "atributo") {
 Atributo *atributo = new Atributo(nodo);
 this->agregarAtributo(atributo);
 }
 if (nodo->getNombre() == "identificador") {
 Identificador *identificador = new Identificador();
 this->obtenerComponentesIdentificadorXmlCOMP(nodo, identificador);
 this->agregarIdentificador(identificador);
 }
 if (nodo->getNombre() == "relacion")	{
 this->agregarCodigoRelacion(nodo->getContenidoInt());
 }
 if ( nodo->getNombre() == "jerarquia" )	{
 this->agregarCodigoJerarquia(nodo->getContenidoInt());
 }
 *nodo = nodo->getHermano();
 }
 }

 void EntidadNueva::obtenerPropiedadesXmlCOMP(XmlNodo* nodo) {
 Componente::obtenerPropiedadesXmlCOMP(nodo);
 this->tipo = nodo->getPropiedad("tipo");
 }

*/

// GUARDAR

XmlNodo EntidadNueva::guardarXmlCOMP() {
	 XmlNodo nodo("entidad_nueva");

	 this->agregarPropiedadesXmlCOMP(&nodo);

	 this->guardarAtributosXmlCOMP(&nodo);
	 this->guardarIdentificadoresXmlCOMP(&nodo);

	 return nodo;
}

void EntidadNueva::agregarPropiedadesXmlCOMP(XmlNodo* nodo) {
	Componente::agregarPropiedadesXmlCOMP(nodo);
	nodo->setPropiedad("tipo",this->tipo);
}

void EntidadNueva::guardarAtributosXmlCOMP(XmlNodo *nodo) {
	std::vector<Atributo*>::iterator i;

	for(i = this->atributos.begin(); i != this->atributos.end(); ++i)
		nodo->agregarHijo((*i)->guardarXmlCOMP());
}

void EntidadNueva::guardarIdentificadoresXmlCOMP(XmlNodo *nodo) {
	std::vector<Identificador*>::iterator i;

	for(i = this->identificadores.begin(); i != this->identificadores.end(); ++i) {
		XmlNodo nodoIdentificador("identificador");

		this->guardarAtributosIdentificadorXmlCOMP(&nodoIdentificador, (*i));
		this->guardarRelacionesIdentificadorXmlCOMP(&nodoIdentificador, (*i));

		nodo->agregarHijo(nodoIdentificador);
	}
}

void EntidadNueva::guardarAtributosIdentificadorXmlCOMP(XmlNodo *nodo, Identificador *identificador) {
	std::vector<int>::iterator i;

	for(i = identificador->codigoAtributosBegin(); i != identificador->codigoAtributosEnd(); ++i) {
		XmlNodo nodoAtributo("atributo");
		nodoAtributo.setContenido(*i);
		nodo->agregarHijo(nodoAtributo);
	}
}

void EntidadNueva::guardarRelacionesIdentificadorXmlCOMP(XmlNodo *nodo, Identificador *identificador) {
	std::vector<int>::iterator i;
	for(i = identificador->codigoRelacionesBegin(); i != identificador->codigoRelacionesEnd(); ++i) {
		XmlNodo nodoRelacion("relacion");
		nodoRelacion.setContenido(*i);
		nodo->agregarHijo(nodoRelacion);
	}
}
