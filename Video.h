//
// Created by Nefi Ureña Salas on 9/4/23.
//

#ifndef ESTRUCTURAS_PROYECTO_VIDEO_H
#define ESTRUCTURAS_PROYECTO_VIDEO_H

#include <string>
using namespace std;

class Video {

private:
    int codigoVideo;
    string nombreVideo;
    string anno;
    string director;
    int cantidad;

public:
    Video();

    int getCodigoVideo();
    string &getNombreVideo();
    string &getAnno();
    string &getDirector();
    int getCantidad();

    void setCodigoVideo(int codigoVideo);
    void setNombreVideo(string &nombreVideo);
    void setAnno(string &anno);
    void setDirector(string &director);
    void setCantidad(int cantidad);

};


#endif //ESTRUCTURAS_PROYECTO_VIDEO_H
