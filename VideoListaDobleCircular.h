//
// Created by Nefi Ureña Salas on 9/4/23.
//

#ifndef ESTRUCTURAS_PROYECTO_VIDEOLISTADOBLECIRCULAR_H
#define ESTRUCTURAS_PROYECTO_VIDEOLISTADOBLECIRCULAR_H


#include "nodoDCVideo.h"

class VideoListaDobleCircular {

private:
    nodoDCVideo* cabeza;
    int largo;

public:
    VideoListaDobleCircular();
    ~VideoListaDobleCircular();

    nodoDCVideo *getCabeza();
    int getLargo();

    void setCabeza(nodoDCVideo *cabeza);
    void setLargo(int largo);

    nodoDCVideo* dirNodo(int);
    nodoDCVideo* dirAnterior(int);
    nodoDCVideo* dirUltimo();

    bool esVacia();
    bool verificarUnico(Video*);
    void agregarInicio(Video*);
    void agregarFinal(Video*);
    bool agregarAscendenteVideo(Video*);
    void modificarVideo(int, string, int, int);
    void mostrarListaOrdCod();
    void mostrarListaOrdCodDes();
    void mostrarListaOrdCodDes(nodoDCVideo*);
    void mostrarListaOrdXNombre();
    void mostrarListaHilera(string);
    void mostrarListaAnno(int, int);
    void mostrarListaItem(int);
    string mostrarListaSinCategoria();
    bool eliminarVideo(int);
    void eliminarVideoItem(int);
    int consultar(string);
    int consultarCantidad(string);
    int consultarNombreAnno(string, int);

};


#endif //ESTRUCTURAS_PROYECTO_VIDEOLISTADOBLECIRCULAR_H
