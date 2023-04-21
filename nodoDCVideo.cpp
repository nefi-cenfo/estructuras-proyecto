//
// Created by Nefi Ureña Salas on 9/4/23.
//

#include "nodoDCVideo.h"

nodoDCVideo::nodoDCVideo() {

}

nodoDCVideo::nodoDCVideo(Video *video) {
    this->video = video;
}

void nodoDCVideo::setAntVideo(nodoDCVideo *antVideo) {
    nodoDCVideo::antVideo = antVideo;
}

void nodoDCVideo::setSgteVideo(nodoDCVideo *sgteVideo) {
    nodoDCVideo::sgteVideo = sgteVideo;
}

void nodoDCVideo::setVideo(Video *video) {
    nodoDCVideo::video = video;
}

nodoDCVideo *nodoDCVideo::getAntVideo() {
    return antVideo;
}

nodoDCVideo *nodoDCVideo::getSgteVideo() {
    return sgteVideo;
}

Video *nodoDCVideo::getVideo() {
    return video;
}


