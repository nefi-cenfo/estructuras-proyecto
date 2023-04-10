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
    bool agregarAscendenteVideo(Video*);
    string modificarVideo(Video*);
    string mostrarListaOrdCod();
    string mostrarListaOrdXNombre();
    string mostrarListaHilera(string);
    string mostrarListaAnno(string);
    string mostrarListaItem(int);
    string mostrarListaSinCategoria();
    bool eliminarVideo(Video*);
    bool eliminarVideoItem(int, Video*);

};


#endif //ESTRUCTURAS_PROYECTO_VIDEOLISTADOBLECIRCULAR_H
