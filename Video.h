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
    int anno;
    string director;
    int cantidad;

public:
    Video();
    Video(int, string, string, int, int);

    int getCodigoVideo();
    string getNombreVideo();
    int getAnno();
    string getDirector();
    int getCantidad();

    void setCodigoVideo(int codigoVideo);
    void setNombreVideo(string nombreVideo);
    void setAnno(int anno);
    void setDirector(string director);
    void setCantidad(int cantidad);

};


#endif //ESTRUCTURAS_PROYECTO_VIDEO_H
