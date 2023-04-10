//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "Video.h"

Video::Video() {

}

int Video::getCodigoVideo() {
    return codigoVideo;
}

void Video::setCodigoVideo(int codigoVideo) {
    Video::codigoVideo = codigoVideo;
}

string &Video::getNombreVideo() {
    return nombreVideo;
}

void Video::setNombreVideo(string &nombreVideo) {
    Video::nombreVideo = nombreVideo;
}

string &Video::getAnno() {
    return anno;
}

void Video::setAnno(string &anno) {
    Video::anno = anno;
}

string &Video::getDirector() {
    return director;
}

void Video::setDirector(string &director) {
    Video::director = director;
}

int Video::getCantidad() {
    return cantidad;
}

void Video::setCantidad(int cantidad) {
    Video::cantidad = cantidad;
}

