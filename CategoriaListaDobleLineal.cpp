//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "CategoriaListaDobleLineal.h"

CategoriaListaDobleLineal::CategoriaListaDobleLineal() {}

CategoriaListaDobleLineal::~CategoriaListaDobleLineal() {

}

nodoDLCategoria *CategoriaListaDobleLineal::getCabeza() {
    return cabeza;
}

int CategoriaListaDobleLineal::getLargo() {
    return largo;
}

void CategoriaListaDobleLineal::setCabeza(nodoDLCategoria *cabeza) {
    CategoriaListaDobleLineal::cabeza = cabeza;
}

void CategoriaListaDobleLineal::setLargo(int largo) {
    CategoriaListaDobleLineal::largo = largo;
}

nodoDLCategoria *CategoriaListaDobleLineal::dirNodo(int) {
    return nullptr;
}

nodoDLCategoria *CategoriaListaDobleLineal::dirAnterior(int) {
    return nullptr;
}

nodoDLCategoria *CategoriaListaDobleLineal::dirUltimo() {
    return nullptr;
}

bool CategoriaListaDobleLineal::esVacia() {
    return false;
}

bool CategoriaListaDobleLineal::agregarCategoria(string) {
    return false;
}

string CategoriaListaDobleLineal::consultarCategoria(string) {
    return std::string();
}

bool CategoriaListaDobleLineal::retirarCategoria(string) {
    return false;
}

bool CategoriaListaDobleLineal::modificarCategoria(string, string) {
    return false;
}

VideoListaDobleCircular *CategoriaListaDobleLineal::consultarCategoriaVideo() {
    return nullptr;
}

bool CategoriaListaDobleLineal::agregarVideoCategoria(string, Video *) {
    return false;
}

bool CategoriaListaDobleLineal::retirarVideo(Video *) {
    return false;
}

VideoListaDobleCircular *CategoriaListaDobleLineal::consultarVideosXCategoria() {
    return nullptr;
}

VideoListaDobleCircular *CategoriaListaDobleLineal::consultarVideos() {
    return nullptr;
}

VideoListaDobleCircular *CategoriaListaDobleLineal::consultarVideosDetallado() {
    return nullptr;
}
