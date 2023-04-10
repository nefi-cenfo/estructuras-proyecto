//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "VideoListaDobleCircular.h"

VideoListaDobleCircular::VideoListaDobleCircular() {

}

VideoListaDobleCircular::~VideoListaDobleCircular() {

}

nodoDCVideo *VideoListaDobleCircular::getCabeza() {
    return cabeza;
}

void VideoListaDobleCircular::setCabeza(nodoDCVideo *cabeza) {
    VideoListaDobleCircular::cabeza = cabeza;
}

int VideoListaDobleCircular::getLargo() {
    return largo;
}

void VideoListaDobleCircular::setLargo(int largo) {
    VideoListaDobleCircular::largo = largo;
}

nodoDCVideo *VideoListaDobleCircular::dirNodo(int) {
    return nullptr;
}

nodoDCVideo *VideoListaDobleCircular::dirAnterior(int) {
    return nullptr;
}

nodoDCVideo *VideoListaDobleCircular::dirUltimo() {
    return nullptr;
}

bool VideoListaDobleCircular::esVacia() {
    return false;
}

bool VideoListaDobleCircular::verificarUnico(Video *) {
    return false;
}

bool VideoListaDobleCircular::agregarAscendenteVideo(Video *) {
    return false;
}

string VideoListaDobleCircular::modificarVideo(Video *) {
    return std::string();
}

string VideoListaDobleCircular::mostrarListaOrdCod() {
    return std::string();
}

string VideoListaDobleCircular::mostrarListaOrdXNombre() {
    return std::string();
}

string VideoListaDobleCircular::mostrarListaHilera(string) {
    return std::string();
}

string VideoListaDobleCircular::mostrarListaAnno(string) {
    return std::string();
}

string VideoListaDobleCircular::mostrarListaItem(int) {
    return std::string();
}

string VideoListaDobleCircular::mostrarListaSinCategoria() {
    return std::string();
}

bool VideoListaDobleCircular::eliminarVideo(Video *) {
    return false;
}

bool VideoListaDobleCircular::eliminarVideoItem(int, Video *) {
    return false;
}


