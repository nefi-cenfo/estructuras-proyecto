//
// Created by Nefi Ureña Salas on 9/4/23.
//

#ifndef ESTRUCTURAS_PROYECTO_CATEGORIALISTADOBLELINEAL_H
#define ESTRUCTURAS_PROYECTO_CATEGORIALISTADOBLELINEAL_H


#include "nodoDLCategoria.h"
#include "VideoListaDobleCircular.h"

class CategoriaListaDobleLineal {

private:
    nodoDLCategoria* cabeza;
    int largo;

public:
    CategoriaListaDobleLineal();
    ~CategoriaListaDobleLineal();

    nodoDLCategoria *getCabeza();
    int getLargo();
    void setCabeza(nodoDLCategoria *cabeza);
    void setLargo(int largo);

    nodoDLCategoria* dirNodo(string);
    nodoDLCategoria* dirAnterior(string);
    nodoDLCategoria* dirUltimo();

    void agregarInicio(string);
    void agregarFinal(string);

    bool esVacia();
    bool agregarCategoria(string);
    void consultarCategoria();
    bool retirarCategoria(string);
    bool modificarCategoria(string, string);
    VideoListaDobleCircular* consultarCategoriaVideo();
    bool agregarVideoCategoria(string, Video*);
    bool retirarVideo(Video*);
    VideoListaDobleCircular* consultarVideosXCategoria();
    VideoListaDobleCircular* consultarVideos();
    VideoListaDobleCircular* consultarVideosDetallado();

};


#endif //ESTRUCTURAS_PROYECTO_CATEGORIALISTADOBLELINEAL_H
