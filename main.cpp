#include <iostream>
#include "Video.h"
#include "VideoListaDobleCircular.h"
#include "CategoriaListaDobleLineal.h"

using namespace std;

void menu() {

    Video* video1 = new Video();
    video1->setAnno(1990);
    video1->setCantidad(10);
    video1->setCodigoVideo(1);
    video1->setDirector("Director-name");
    video1->setNombreVideo("Exorcista");
    nodoDCVideo* nodoVideo1 = new nodoDCVideo();
    nodoVideo1->setVideo(video1);

    Video* video2 = new Video();
    video2->setAnno(2015);
    video2->setCantidad(10);
    video2->setCodigoVideo(2);
    video2->setDirector("Director-name");
    video2->setNombreVideo("John-Wick");
    nodoDCVideo* nodoVideo2 = new nodoDCVideo();
    nodoVideo2->setVideo(video2);

    Video* video3 = new Video();
    video3->setAnno(1999);
    video3->setCantidad(8);
    video3->setCodigoVideo(3);
    video3->setDirector("Director-name");
    video3->setNombreVideo("Harry-potter-y-la-piedra-filosofal");
    nodoDCVideo* nodoVideo3 = new nodoDCVideo();
    nodoVideo3->setVideo(video3);

    Video* video4 = new Video();
    video4->setAnno(2000);
    video4->setCantidad(7);
    video4->setCodigoVideo(4);
    video4->setDirector("Director-name");
    video4->setNombreVideo("Harry-potter-y-la-camara-secreta");
    nodoDCVideo* nodoVideo4 = new nodoDCVideo();
    nodoVideo4->setVideo(video4);

    Video* video5 = new Video();
    video5->setAnno(2020);
    video5->setCantidad(10);
    video5->setCodigoVideo(5);
    video5->setDirector("Director-name");
    video5->setNombreVideo("Super-mario-bros");
    nodoDCVideo* nodoVideo5 = new nodoDCVideo();
    nodoVideo5->setVideo(video5);

    nodoVideo1->setSgteVideo(nodoVideo2);
    nodoVideo2->setSgteVideo(nodoVideo3);
    nodoVideo3->setSgteVideo(nodoVideo4);
    nodoVideo4->setSgteVideo(nodoVideo5);
    nodoVideo5->setSgteVideo(nodoVideo1);

    nodoVideo1->setAntVideo(nodoVideo5);
    nodoVideo2->setAntVideo(nodoVideo1);
    nodoVideo3->setAntVideo(nodoVideo2);
    nodoVideo4->setAntVideo(nodoVideo3);
    nodoVideo5->setAntVideo(nodoVideo4);

    VideoListaDobleCircular* videoLista = new VideoListaDobleCircular();
    videoLista->setCabeza(nodoVideo1);
    videoLista->setLargo(5);

    CategoriaListaDobleLineal* categoriaLista = new CategoriaListaDobleLineal();

    int opc = -1, opcion = -1;

    int codigoVideo = 0, anno = 0, cantidad = 0, anno1 = 0, anno2 = 0;
    string nombreVideo = "blanco", director = "blanco";

    string nombreCategoria = "";

    while (opc != 0) {
        cout << "========================================" << endl;
        cout << "              MENU" << endl;
        cout << "========================================" << endl;
        cout << "------------ P E L I C U L A S ---------" << endl;
        cout << "(1) Agregar Pelicula" << endl;
        cout << "(2) Retirar Pelicula " << endl;
        cout << "(3) Consultar Pelicula  " << endl;
        cout << "(4) Modificar Pelicula  " << endl;
        cout << "(5) Listar catalogo completo por codigo" << endl;
        cout << "(6) Listar Peliculas por hilera" << endl;
        cout << "(7) Listar Peliculas de un rango de annos" << endl;
        cout << "(8) Listar Peliculas menos solicitadas que..." << endl;
        cout << "(9) Eliminar Peliculas menos solicitadas que..." << endl;
        cout << "------------ C A T E G O R I A S ---------" << endl;
        cout << "(10) Agregar Categoria" << endl;
        cout << "(11) Remover Categoria" << endl;
        cout << "(13) Listar todas las categorias" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "===================================" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;

        switch (opc) {
            case 1: {
                // Agregar (Sin repetidos y en forma ascendente)
                cout << "Ingrese el codigo del video" << endl;
                cin >> codigoVideo;

                cin.ignore();
                cout << "Ingrese el nombre del video (SIN ESPACIOS, UTILIZAR - PARA ESPACIAR)" << endl;
                cin >> nombreVideo;

                cin.ignore();
                cout << "Ingrese el director del video (SIN ESPACIOS, UTILIZAR - PARA ESPACIAR)" << endl;
                cin >> director;

                cin.ignore();
                cout << "Ingrese el a�o" << endl;
                cin>> anno;

                cin.ignore();
                cout << "Ingrese la cantidad" << endl;
                cin >> cantidad;
                Video* video = new Video(codigoVideo, nombreVideo, director, anno, cantidad);
                cout << "=======================================" << endl;
                cout << "Datos ingresados:" << endl;
                cout << "Codigo de Video: " << video->getCodigoVideo()  << endl;
                cout << "Nombre de Video: " << video->getNombreVideo() << endl;
                cout << "Nombre de Director: " << video->getDirector() << endl;
                cout << "A�o de pelicula: " << video->getAnno() << endl;
                cout << "Numero de veces solicitada: " << video->getCantidad() << endl;
                cout << "=======================================" << endl;

                if (videoLista->agregarAscendenteVideo(video)) {
                    cout << "Video ingresado" << endl;
                    cout << "--------------------------" << endl;
                }
                else {
                    cout << "Codigo de pelicula ya existe en la lista" << endl;
                    cout << "-----------------------------------------" << endl;
                }
                break;
            }
            case 2: {
                // Retirar (Se solicita el nombre y si es necesario el año)
                cout << "Ingrese el nombre de pelicula" << endl;
                cin >> nombreVideo;
                if (videoLista->consultarCantidad(nombreVideo) > 1) {
                    cout << "-----------------------------------------" << endl;
                    cout << "Hay varias peliculas con el mismo nombre" << endl;
                    cout << "Indicar anno de pelicula que desea borrar" << endl;
                    cin >> anno;
                    cout << "Datos de pelicula a borrar:" << endl;
                    codigoVideo = videoLista->consultarNombreAnno(nombreVideo, anno);
                    videoLista->eliminarVideo(codigoVideo);
                    cout << "....se ha borrado la pelicula" << endl;

                }
                else if (videoLista->consultarCantidad(nombreVideo) == 0) {
                    cout << "No existe pelicula con ese nombre en la lista" << endl;

                }
                else {
                    cout << "Datos de pelicula a borrar:" << endl;
                    codigoVideo = videoLista->consultar(nombreVideo);
                    videoLista->eliminarVideo(codigoVideo);
                }
                break;
            }
            case 3: {
                // Consultar (Se solicita el nombre y si es necesario el año)
                cout << "Ingrese el nombre de pelicula (SIN ESPACIOS, UTILIZAR - PARA ESPACIAR)" << endl;
                cin >>nombreVideo;
                if (videoLista->consultarCantidad(nombreVideo) > 1) {
                    cout << "-----------------------------------------" << endl;
                    cout << "Hay varias peliculas con el mismo nombre" << endl;
                    cout << "-----------------------------------------" << endl;
                    while (opcion !=0){
                        cout << "(1) Listar todas las peliculas" << endl;
                        cout << "(2) Consultar el ano" << endl;
                        cout << "(0) Salir al menu principal" << endl;
                        cout << "Opcion seleccionada" << endl;
                        cin >> opcion;

                        switch (opcion) {
                            case 1:
                                videoLista->consultar(nombreVideo);
                                break;
                            case 2:
                                cout << "Indique el a�o de la pelicula" << endl;
                                cin >> anno;
                                videoLista->consultarNombreAnno(nombreVideo, anno);
                                break;
                            case 0:
                                cout << "Salir al menu principal ";
                                break;
                            default:
                                cout << "Opcion no v�lida..." << endl;
                        }
                    }
                }
                else if (videoLista->consultarCantidad(nombreVideo) == 0){
                    cout << "No existe pelicula con ese nombre en la lista" << endl;
                }else{
                    videoLista->consultar(nombreVideo);
                }
                break;
            }
            case 4: {
                // Modificar (Se solicita el nombre y si es necesario el año)
                char questionAnswer;
                codigoVideo = 0;
                director = "";
                anno = 0;
                cantidad = 0;
                cout << "Ingrese el nombre de la pelicula" << endl;
                cin >> nombreVideo;
                int cantidadPeliculasNombre = videoLista->consultarCantidad(nombreVideo);

                if (cantidadPeliculasNombre != 0) {
                    codigoVideo = videoLista->consultar(nombreVideo);
                    if (cantidadPeliculasNombre > 1) {
                        cout << "-----------------------------------------" << endl;
                        cout << "Hay varias peliculas con el mismo nombre" << endl;
                        cout << "-----------------------------------------" << endl;
                        cout << "Ingrese el anno: " << endl;
                        cin >> anno;
                        codigoVideo = videoLista->consultarNombreAnno(nombreVideo, anno);
                        while (codigoVideo == 0 && anno != -1) {
                            cout << "Dato incorrecto, ingrese el anno o -1 para cancelar" << endl;
                            cin >> anno;
                            codigoVideo = videoLista->consultarNombreAnno(nombreVideo, anno);
                        }
                    }
                    if (anno != -1) {
                        cout << "Desea modificar el director? (SIN ESPACIOS, UTILIZAR - PARA ESPACIAR) (Y/N)" << endl;
                        cin >> questionAnswer;
                        if (tolower(questionAnswer) == 'y') {
                            cout << "Ingrese el director del video" << endl;
                            cin >> director;
                        }
                        cout << "Desea modificar el anno? (Y/N)" << endl;
                        cin >> questionAnswer;
                        if (tolower(questionAnswer) == 'y') {
                            cout << "Ingrese el anno del video" << endl;
                            cin >> anno;
                        }
                        cout << "Desea modificar la cantidad de veces solicitada? (Y/N)" << endl;
                        cin >> questionAnswer;
                        if (tolower(questionAnswer) == 'y') {
                            cout << "Ingrese la cantidad" << endl;
                            cin >> cantidad;
                        }
                        videoLista->modificarVideo(codigoVideo, director, anno, cantidad);
                    }
                } else {
                    cout << "No hay peliculas con ese nombre" << endl;
                }

                break;
            }
            case 5: {
                // Listado catálogo completo en forma ascendente (descendente) por nombre (año)
                cout << "Seleccione una opcion:" << endl;
                do {
                    cout << "1 - Mostrar lista ascendente" << endl;
                    cout << "2 - Mostrar lista descendente" << endl;
                    cout << "0 - Regresar al menu principal" << endl;
                    cin >> opcion;
                    if (opcion == 1) {
                        videoLista->mostrarListaOrdCod();
                        opcion = 0;
                    }
                    if (opcion == 2) {
                        videoLista->mostrarListaOrdCodDes();
                        opcion = 0;
                    }
                } while (opcion != 0);
                break;
            }
            case 6: {
                // Listar películas cuyo nombre contenga una hilera específica (Por ejemplo, si se busca Potter deben
                //aparecer todas las películas que tengan Potter como parte de su nombre)
                cout << "Indique el termino a buscar:" << endl;
                cin >> nombreVideo;
                videoLista->mostrarListaHilera(nombreVideo);
                break;
            }
            case 7: {
                // Listado de catálogo de películas de un rango de año específico (Ejemplo puedo solicitar las películas
                //entre 2010 y 2015)
                cout << "Ingrese el rango de fecha" << endl;
                cout << "Fecha 1 (la mas antigua): " << endl;
                cin >> anno1;
                cout << "Fecha 2 (la mas reciente)" << endl;
                cin >> anno2;
                cout << "Rango a consultar " << anno1 << " - " << + anno2 << endl;
                videoLista->mostrarListaAnno(anno1,anno2);
                break;
            }
            case 8: {
                // Listar películas cuya solicitud sean inferior a un límite dado (Ejemplo listar las películas cuyas solicitudes
                //sean mejor a 3 ocasiones)
                cout << "Ingrese cantidad de veces pelicula ha sido solicitada:" << endl;
                cin >> cantidad;
                videoLista->mostrarListaItem(cantidad);
                break;
            }
            case 9:
                // Eliminar de la lista las películas cuya solicitud sea inferior a un límite dado (Ejemplo eliminar todas las
                //películas cuyo número de solicitudes sea menor a 2 veces, es decir, las que fueron solicitadas 0 o 1 vez)
                cout << "Ingrese limite de cantidad para borrar de la lista:" << endl;
                cin >> cantidad;
                videoLista->eliminarVideoItem(cantidad);
                break;
            case 10:
                // Categorias: agregar ordenado
                cout << "Ingrese el nombre de la categoria" << endl;
                cin >> nombreCategoria;
                if(categoriaLista->agregarCategoria(nombreCategoria)){
                    cout << "=======================================" << endl;
                    cout << "Dato ingresado" << endl;
                    cout << "Nombre de la Categoria: " << nombreCategoria << endl;
                    cout << "=======================================" << endl;
                }
                break;
            case 11:
                // Categorias: remover
                cout << "Ingrese el nombre de la categoria" << endl;
                cin >> nombreCategoria;

                if (categoriaLista->retirarCategoria(nombreCategoria))
                    cout << "La categoria " << nombreCategoria << " ha sido eliminado exitosamente" << endl;
                else
                    cout << "La categoria " << nombreCategoria << " no se encuentra en la lista" << endl;
                break;
            case 12:
                // TODO: Categorias: consultar
                cout << "Funcionalidad aun no implementada.";
                break;
            case 13:
                // TODO: Categorias: listar todos los datos; , se muestran solo las categorias por el momento
                cout << "Desplegando los valores de la categoria" << endl;
                categoriaLista->consultarCategoria();
                break;
            case 0:
                cout << "Finalizando el programa... ";
                break;
            default:
                cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }


}

int main() {
    menu();
}
