//
// Created by Nefi Ureña Salas on 9/4/23.
//

#ifndef ESTRUCTURAS_PROYECTO_NODODCVIDEO_H
#define ESTRUCTURAS_PROYECTO_NODODCVIDEO_H


#include "Video.h"

class nodoDCVideo {

private:
    Video* video;
    nodoDCVideo* antVideo;
    nodoDCVideo* sgteVideo;

public:
    nodoDCVideo();
    nodoDCVideo(Video*);

    void setAntVideo(nodoDCVideo *antVideo);
    void setSgteVideo(nodoDCVideo *sgteVideo);
    void setVideo(Video *video);

    nodoDCVideo *getAntVideo();
    nodoDCVideo *getSgteVideo();
    Video *getVideo();

};


#endif //ESTRUCTURAS_PROYECTO_NODODCVIDEO_H
