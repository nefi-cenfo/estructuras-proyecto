//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "Video.h"

Video::Video() {
    this->codigoVideo = 0;
    this->nombreVideo = "";
    this->director = "";
    this->anno = 0;
    this->cantidad = 0;
}

Video::Video(int pCodigoVideo, string pNombreVideo, string pDirector, int pAnno, int pCantidad) {
    this->codigoVideo = pCodigoVideo;
    this->nombreVideo = pNombreVideo;
    this->director = pDirector;
    this->anno = pAnno;
    this->cantidad = pCantidad;
}

int Video::getCodigoVideo() {
    return codigoVideo;
}

void Video::setCodigoVideo(int codigoVideo) {
    Video::codigoVideo = codigoVideo;
}

string Video::getNombreVideo() {
    return nombreVideo;
}

void Video::setNombreVideo(string nombreVideo) {
    Video::nombreVideo = nombreVideo;
}

int Video::getAnno() {
    return anno;
}

void Video::setAnno(int anno) {
    Video::anno = anno;
}

string Video::getDirector() {
    return director;
}

void Video::setDirector(string director) {
    Video::director = director;
}

int Video::getCantidad() {
    return cantidad;
}

void Video::setCantidad(int cantidad) {
    Video::cantidad = cantidad;
}

