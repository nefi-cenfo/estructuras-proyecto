//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "VideoListaDobleCircular.h"
#include <iostream>
#include <string>

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

nodoDCVideo *VideoListaDobleCircular::dirNodo(int pCodigoVideo) {
    //Devuelve la direcci�n del nodo cuyo valor sea x
    nodoDCVideo* aux = NULL;
    bool encontrado = false;

    if (!esVacia()) {
        aux = getCabeza();
        do {
            if (aux->getVideo()->getCodigoVideo() == pCodigoVideo) encontrado = true;
            else aux = aux->getSgteVideo();
        } while (aux != getCabeza() && !encontrado);

    }
    if (encontrado) return aux;
    else return NULL;
}

nodoDCVideo *VideoListaDobleCircular::dirAnterior(int pCodigoVideo) {
    //Devuelve la direcci�n del nodo anterior al nodo cuyo valor sea x

    nodoDCVideo* anterior = NULL;

    if (!esVacia()) {
        nodoDCVideo* aux = dirNodo(pCodigoVideo);
        if (aux != NULL)
            anterior = aux->getAntVideo();
    }
    return anterior;
}

nodoDCVideo *VideoListaDobleCircular::dirUltimo() {
    if (!esVacia()) return getCabeza()->getAntVideo();
    else return NULL;
}

bool VideoListaDobleCircular::esVacia() {
    return getCabeza() == NULL;
}

void VideoListaDobleCircular::agregarInicio(Video* pVideo) {
    agregarFinal(pVideo);
    //Paso 3. Reacomodar la lista con el nuevo nodo
    if (getLargo() > 1) setCabeza(getCabeza()->getAntVideo());

}

void VideoListaDobleCircular::agregarFinal(Video* pVideo) {   //Agrega al final de la lista un nodo con el valor de _dato
    //Si la lista est� vac�a siempre se agrega

    nodoDCVideo* nuevo = new nodoDCVideo(pVideo); //Paso #1 crear el nodo

    if (esVacia()) {
        nuevo->setSgteVideo(nuevo);
        nuevo->setAntVideo(nuevo);
        setCabeza(nuevo);
    }
    else {
        nodoDCVideo* ult = getCabeza()->getAntVideo();

        //Paso 2. Enlazar el nuevo nodo a la lista
        nuevo->setSgteVideo(getCabeza());
        nuevo->setAntVideo(ult);

        //Paso 3. Reacomodar la lista con el nuevo nodo
        ult->setSgteVideo(nuevo);
        getCabeza()->setAntVideo(nuevo);
    }

    setLargo(getLargo() + 1);
}

bool VideoListaDobleCircular::verificarUnico(Video *) {
    return false;
}

bool VideoListaDobleCircular::agregarAscendenteVideo(Video *pVideo) {
    //Agregar videos en forma ascendente y sin repetir codigo

    bool agregado = false;
    bool repetido = false;
    nodoDCVideo* nuevo = new nodoDCVideo(pVideo);//Paso #1, crear el nodo que revise el puntero del video
    if (esVacia()) {

        //Paso #2, enlazar el nuevo a la lista
        nuevo->setSgteVideo(nuevo);
        nuevo->setAntVideo(nuevo);
        //Paso #3, Reacomodar la lista con el nuevo nodo
        setCabeza(nuevo);
        setLargo(1);
        agregado = true;
    }
    else {

        if (pVideo->getCodigoVideo() < getCabeza()->getVideo()->getCodigoVideo()) {
            agregarInicio(pVideo);
            agregado = true;
        }
        else {
            if (pVideo->getCodigoVideo() > getCabeza()->getAntVideo()->getVideo()->getCodigoVideo()) {
                agregarFinal(pVideo);
                agregado = true;
                repetido = false;
            }
            else {
                nodoDCVideo* aux = getCabeza();
                do {
                    if (pVideo->getCodigoVideo() == aux->getVideo()->getCodigoVideo())
                        repetido = true;
                    else if (pVideo->getCodigoVideo() > aux->getSgteVideo()->getVideo()->getCodigoVideo()) {
                        //Paso #2: Enlazar el nuevo a la lista
                        nuevo->setSgteVideo(aux->getSgteVideo());
                        nuevo->setAntVideo(aux);
                        //Paso #3: Reacomodar la lista con el nuevo nodo
                        aux->getSgteVideo()->setAntVideo(nuevo);
                        aux->setSgteVideo(nuevo);
                        setLargo(getLargo() + 1);
                        agregado = true;
                        repetido = false;
                    }
                    else {
                        aux = aux->getSgteVideo();
                    }
                } while (aux != getCabeza() && !repetido && !agregado);
            }

        }
    }

    return agregado;
}

void VideoListaDobleCircular::modificarVideo(int codigo, string director, int anno, int cantidad) {
    nodoDCVideo* aux = dirNodo(codigo);
    if (!director.empty()) {
        aux->getVideo()->setDirector(director);
    }
    if (anno > 1900 && anno < 2030) {
        aux->getVideo()->setAnno(anno);
    }
    if (cantidad > 0) {
        aux->getVideo()->setCantidad(cantidad);
    }
}

void VideoListaDobleCircular::mostrarListaOrdCod() {
    if (esVacia()) {
        std::cout << "La lista está vacia...";
    } else {
        nodoDCVideo* aux = getCabeza();
        do {
            cout << "----------------------------------" << endl;
            std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
            std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
            std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
            std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
            std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
            cout << "----------------------------------" << endl;
            aux = aux->getSgteVideo();
        } while (aux != getCabeza());
        std::cout << "Fin de la lista \n";
    }
}

void VideoListaDobleCircular::mostrarListaOrdCodDes() {
    mostrarListaOrdCodDes(getCabeza());
}

void VideoListaDobleCircular::mostrarListaOrdCodDes(nodoDCVideo *aux) {
    if (aux->getSgteVideo() != getCabeza()) { //condicion de parada
        mostrarListaOrdCodDes(aux->getSgteVideo()); //Invocacion recursiva
        cout << "----------------------------------" << endl;
        std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
        std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
        std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
        std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
        std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
        cout << "----------------------------------" << endl;
    }
    if (aux == getCabeza()->getAntVideo()) {
        cout << "----------------------------------" << endl;
        std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
        std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
        std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
        std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
        std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
        cout << "----------------------------------" << endl;
    }
}

void VideoListaDobleCircular::mostrarListaOrdXNombre() {
}

void VideoListaDobleCircular::mostrarListaHilera(string hilera) {
    std::size_t encontrado;
    bool hayAlgunValor = false;
    if (esVacia()) {
        std::cout << "La lista está vacia...";
    } else {
        nodoDCVideo* aux = getCabeza();
        do {
            encontrado = aux->getVideo()->getNombreVideo().find(hilera);
            if (encontrado != std::string::npos) {
                cout << "----------------------------------" << endl;
                std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
                std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
                std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
                std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
                std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
                cout << "----------------------------------" << endl;
                hayAlgunValor = true;
            }
            aux = aux->getSgteVideo();
        } while (aux != getCabeza());
        if (hayAlgunValor) {
            std::cout << "Fin de la lista \n";
        } else {
            std::cout << "No se encuentran Peliculas con ese nombre \n";
        }
    }
}

void VideoListaDobleCircular::mostrarListaAnno(int dato1,int dato2) {
    if (esVacia()) {
        std::cout << "No hay lista de peliculas...";
    }
    else {
        nodoDCVideo* aux = getCabeza();
        do {
            if (dato1 <= aux->getVideo()->getAnno() and dato2 >= aux->getVideo()->getAnno()) {
                cout << "----------------------------------" << endl;
                std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
                std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
                std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
                std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
                std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
                cout << "----------------------------------" << endl;

            }

            aux = aux->getSgteVideo();
        } while (aux != getCabeza());
        std::cout << "Fin de la consulta \n";
    }
}

void VideoListaDobleCircular::mostrarListaItem(int cantidad) {
    if (esVacia()) {
        std::cout << "No hay lista de peliculas...";
    }
    else {
        nodoDCVideo* aux = getCabeza();
        do {
            if (cantidad >= aux->getVideo()->getCantidad()) {
                cout << "----------------------------------" << endl;
                std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
                std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
                std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
                std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
                std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
                cout << "----------------------------------" << endl;

            }
            aux = aux->getSgteVideo();
        } while (aux != getCabeza());
    }
}

string VideoListaDobleCircular::mostrarListaSinCategoria() {
    return std::string();
}

bool VideoListaDobleCircular::eliminarVideo(int codigoVideo) {
    bool removido = false;
    nodoDCVideo* aux = dirNodo(codigoVideo); //Localizar el nodo de _dato
    if (aux != NULL) {
        if (getLargo() == 1) {
            setCabeza(NULL);
        }
        else {
            if (aux == getCabeza()) setCabeza(getCabeza()->getSgteVideo());
            aux->getAntVideo()->setSgteVideo(aux->getSgteVideo());
            aux->getSgteVideo()->setAntVideo(aux->getAntVideo());
        }
        delete aux;
        setLargo(getLargo() - 1);
        removido = true;
    }
    return removido;
}

void VideoListaDobleCircular::eliminarVideoItem(int cantidad) {
    nodoDCVideo* aux1;
    nodoDCVideo* aux2;
    int i, len;


    if (!esVacia()) {

        if (getLargo() == 1) {
            delete cabeza;
            cabeza = NULL;
            setLargo(0);
        } else {

            i = 0;
            aux1 = getCabeza();
            aux2 = getCabeza()->getSgteVideo();;
            len = getLargo();
            do {
                int dato = aux1->getVideo()->getCantidad();
                if (cantidad > dato) {
                    cout << "----------------------------------" << endl;
                    cout << "Nombre de Pelicula: " << aux1->getVideo()->getNombreVideo() << endl;
                    cout << "Codigo: " << aux1->getVideo()->getCodigoVideo() << endl;
                    cout << "Anno: " << aux1->getVideo()->getAnno() << endl;
                    cout << "Director: " << aux1->getVideo()->getDirector() << endl;
                    cout << "Numero de veces solicitado: " << aux1->getVideo()->getCantidad() << endl;
                    cout << "----------------------------------" << endl;
                    eliminarVideo(aux1->getVideo()->getCodigoVideo());
                    cout << "... se ha borrado pelicula" << endl;
                }
                aux1 = aux2;
                aux2 = aux2->getSgteVideo();
                i++;
            } while (i < len);
        }
    }
}

int VideoListaDobleCircular::consultar(string nombreVideo) {
    int dato = 0;
    if (esVacia()) {
        std::cout << "No hay lista de peliculas...";
    }
    else {
        nodoDCVideo* aux = getCabeza();
        do {
            if (nombreVideo == aux->getVideo()->getNombreVideo()) {
                cout << "----------------------------------" << endl;
                std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
                std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
                std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
                std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
                std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
                cout << "----------------------------------" << endl;
                dato = aux->getVideo()->getCodigoVideo();
            }
            aux = aux->getSgteVideo();
        } while (aux != getCabeza());

    }
    return dato;
}

int VideoListaDobleCircular::consultarCantidad(string nombreVideo) {
    int dato = 0;
    if (esVacia()) {
        std::cout << "No hay lista de peliculas...";
    }
    else {
        nodoDCVideo* aux = getCabeza();
        do {
            if (nombreVideo == aux->getVideo()->getNombreVideo()) {
                dato = dato + 1;
            }
            aux = aux->getSgteVideo();
        } while (aux != getCabeza());
    }
    return dato;
}

int VideoListaDobleCircular::consultarNombreAnno(string nombreVideo, int anno) {
    int dato = 0;
    bool cantidad = false;
    if (esVacia()) {
        std::cout << "No hay lista de peliculas...";
    }
    else {
        nodoDCVideo* aux = getCabeza();
        do {
            if (nombreVideo == aux->getVideo()->getNombreVideo() and anno == aux->getVideo()->getAnno()) {
                cout << "----------------------------------" << endl;
                std::cout << "Nombre de Pelicula: " << aux->getVideo()->getNombreVideo() << endl;
                std::cout << "Codigo: " << aux->getVideo()->getCodigoVideo() << endl;
                std::cout << "Anno: " << aux->getVideo()->getAnno() << endl;
                std::cout << "Director: " << aux->getVideo()->getDirector() << endl;
                std::cout << "Numero de veces solicitado: " << aux->getVideo()->getCantidad() << endl;
                cout << "----------------------------------" << endl;
                dato = aux->getVideo()->getCodigoVideo();

            }
            aux = aux->getSgteVideo();
        } while (aux != getCabeza());
    }
    return dato;

}


