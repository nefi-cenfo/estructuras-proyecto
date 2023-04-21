//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "CategoriaListaDobleLineal.h"
#include <iostream>
using namespace std;

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

nodoDLCategoria *CategoriaListaDobleLineal::dirNodo(string pNombre) {
    //Devuelve la direcci�n del nodo cuyo valor sea x
    nodoDLCategoria* aux = NULL;

    if (!esVacia()) {
        aux = getCabeza();
        while (aux != NULL && (aux->getNombreCategoria() != pNombre)) {
            aux = aux->getSgte();
        }
    }
    return aux;
}

nodoDLCategoria *CategoriaListaDobleLineal::dirAnterior(string pNombre) {
    //Devuelve la direcci�n del nodo anterior al nodo cuyo valor sea x

    nodoDLCategoria* anterior = NULL;

    if (!esVacia()) {
        anterior = dirNodo(pNombre)->getAnte();

    }
    return anterior;
}

nodoDLCategoria *CategoriaListaDobleLineal::dirUltimo() {
    if (!esVacia()) {
        nodoDLCategoria* aux = getCabeza();
        nodoDLCategoria* aux2 = NULL;
        while (aux->getSgte() != NULL) {
            aux2 = aux->getSgte();
            aux = aux2;
        }
        return aux;
    }
    else {
        return NULL;
    }
}

void CategoriaListaDobleLineal::agregarInicio(string pNombre)
{
    nodoDLCategoria* nuevo = new nodoDLCategoria(pNombre); //Paso #1 crear el nodo

    if (!esVacia()) {
        //Paso #2 Enlazar el nuevo nodo a la lista
        nuevo->setSgte(getCabeza());
        //Paso #3 Reacomodar la lista con el nuevo nodo
        getCabeza()->setAnte(nuevo);
    }

    setCabeza(nuevo);
    setLargo(getLargo() + 1);

}

void CategoriaListaDobleLineal::agregarFinal(string pNombre)
{   //Agrega al final de la lista un nodo con el valor de _dato
    //Si la lista est� vac�a siempre se agrega

    nodoDLCategoria* nuevo = new nodoDLCategoria(pNombre); //Paso #1 crear el nodo

    if (esVacia()) {
        //Paso #3 Reacomodar la lista con el nuevo nodo
        setCabeza(nuevo);
    }
    else {
        //Paso #2 Enlazar el nuevo nodo a la lista
        nodoDLCategoria* ult = dirUltimo();
        nuevo->setAnte(ult);
        //Paso #3 Reacomodar la lista con el nuevo nodo
        ult->setSgte(nuevo);
    }
    setLargo(getLargo() + 1);
}

bool CategoriaListaDobleLineal::esVacia() {
    return cabeza == NULL;
}

bool CategoriaListaDobleLineal::agregarCategoria(string pNombre) {
    bool agregado = false;
    bool repetido = false;
    if (esVacia()) {
        nodoDLCategoria* nuevo = new nodoDLCategoria(pNombre);//Paso #1, crear el nodo que revise el puntero del video

        //Paso #2, enlazar el nuevo a la lista
        nuevo->setSgte(NULL);
        nuevo->setAnte(NULL);
        //Paso #3, Reacomodar la lista con el nuevo nodo
        setCabeza(nuevo);
        setLargo(1);
        agregado = true;

    }
    else {

        if (pNombre.compare(getCabeza()->getNombreCategoria()) < 0) {
            agregarInicio(pNombre);
            agregado = true;

        }
        else {
            if (pNombre.compare(dirUltimo()->getNombreCategoria()) > 0) {
                agregarFinal(pNombre);
                agregado = true;

            }
            else {
                nodoDLCategoria* aux = getCabeza();
                do {
                    if (pNombre.compare(aux->getNombreCategoria()) == 0) {
                        repetido = true;

                    }


                    else if (pNombre.compare  (aux->getNombreCategoria()) > 0 ) {
                        nodoDLCategoria* nuevo = new nodoDLCategoria(pNombre);//Paso #1, crear el nodo que revise el puntero del video
                        //Paso #2: Enlazar el nuevo a la lista
                        nuevo->setSgte(aux->getSgte());
                        nuevo->setAnte(aux);
                        //Paso #3: Reacomodar la lista con el nuevo nodo
                        aux->setSgte(nuevo);
                        setLargo(getLargo() + 1);
                        agregado = true;

                    }
                    else {
                        nodoDLCategoria* nuevo = new nodoDLCategoria(pNombre);//Paso #1, crear el nodo que revise el puntero del video
                        aux->setAnte(nuevo);
                        nuevo->setSgte(aux);
                        nuevo->setAnte(aux->getAnte());
                        agregado = true;

                    }

                    aux = aux->getSgte();

                } while (aux != getCabeza() && !repetido && !agregado);
            }

        }
    }
    if (repetido)
        std::cout << "Ya existe la categoria";
    return agregado;
}

void CategoriaListaDobleLineal::consultarCategoria() {
    if (esVacia())
        std::cout << "La lista est� vac�a...";
    else {
        nodoDLCategoria* aux = getCabeza();
        while (aux != NULL) {
            std::cout << aux->getNombreCategoria() << "-";
            aux = aux->getSgte(); //permite pasar al siguiente nodo
        }
        std::cout << " \nFin de la lista \n";

    }
}

bool CategoriaListaDobleLineal::retirarCategoria(string pNombre) {
    //Eliminar el primer nodo cuyo valor sea igual a _dato
    bool removido = false;

    nodoDLCategoria* aux = dirNodo(pNombre); //Paso #1: Apunte el nodo a eliminar

    if (aux != NULL) {

        //Paso #2: reacomodar la lista sin el nodo
        if (aux->getAnte() != NULL)
            aux->getAnte()->setSgte(aux->getSgte());
        if (aux->getSgte() != NULL)
            aux->getSgte()->setAnte(aux->getAnte());
        if (aux == getCabeza()) {
            if (this->largo == 0) setCabeza(NULL);
            else setCabeza(getCabeza()->getSgte());
        }

        //Paso #3: Eliminar el nodo
        delete aux;
        setLargo(getLargo() - 1);

        removido = true;
    }

    return removido;
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
