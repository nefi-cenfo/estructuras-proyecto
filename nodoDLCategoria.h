//
// Created by Nefi Ureña Salas on 9/4/23.
//

#ifndef ESTRUCTURAS_PROYECTO_NODODLCATEGORIA_H
#define ESTRUCTURAS_PROYECTO_NODODLCATEGORIA_H

#include <string>
using namespace std;

class nodoDLCategoria {

private:
    string nombreCategoria;
    nodoDLCategoria* sgte;
    nodoDLCategoria* ante;

public:
    nodoDLCategoria();
    nodoDLCategoria(string);

    string &getNombreCategoria();
    nodoDLCategoria *getSgte();
    nodoDLCategoria *getAnte();

    void setNombreCategoria(string &nombreCategoria);
    void setSgte(nodoDLCategoria *sgte);
    void setAnte(nodoDLCategoria *ante);

};


#endif //ESTRUCTURAS_PROYECTO_NODODLCATEGORIA_H
