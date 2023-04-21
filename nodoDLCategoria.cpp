//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "nodoDLCategoria.h"

nodoDLCategoria::nodoDLCategoria() {
    this->nombreCategoria = "";
    this->sgte = NULL;
    this->ante = NULL;

}

nodoDLCategoria::nodoDLCategoria(string pNombre) {
    this->nombreCategoria = pNombre;
    this->sgte = NULL;
    this->ante = NULL;

}

string nodoDLCategoria::getNombreCategoria() {
    return this->nombreCategoria;
}

nodoDLCategoria* nodoDLCategoria::getSgte() {
    return this->sgte;
}

nodoDLCategoria* nodoDLCategoria::getAnte() {
    return this->ante;
}

void nodoDLCategoria::setNombreCategoria(string nombreCategoria) {
    this->nombreCategoria = nombreCategoria;
}

void nodoDLCategoria::setSgte(nodoDLCategoria* ptr) {
    this->sgte = ptr;
}

void nodoDLCategoria::setAnte(nodoDLCategoria* ptr) {
    this->ante = ptr;
}


