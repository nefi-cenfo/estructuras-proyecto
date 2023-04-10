//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "nodoDLCategoria.h"

nodoDLCategoria::nodoDLCategoria() {

}

nodoDLCategoria::nodoDLCategoria(string) {

}

string &nodoDLCategoria::getNombreCategoria() {
    return nombreCategoria;
}

nodoDLCategoria *nodoDLCategoria::getSgte() {
    return sgte;
}

nodoDLCategoria *nodoDLCategoria::getAnte() {
    return ante;
}

void nodoDLCategoria::setNombreCategoria(string &nombreCategoria) {
    nodoDLCategoria::nombreCategoria = nombreCategoria;
}

void nodoDLCategoria::setSgte(nodoDLCategoria *sgte) {
    nodoDLCategoria::sgte = sgte;
}

void nodoDLCategoria::setAnte(nodoDLCategoria *ante) {
    nodoDLCategoria::ante = ante;
}


