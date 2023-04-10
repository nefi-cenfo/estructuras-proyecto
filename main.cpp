#include <iostream>

using namespace std;

void menu() {

    int opc = -1;
    int dato = 0;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar Pelicula" << endl;
        cout << "(2) Retirar Pelicula " << endl;
        cout << "(3) Consultar Pelicula  " << endl;
        cout << "(4) Modificar Pelicula  " << endl;
        cout << "(5) Listar catalogo completo ascendente por nombre" << endl;
        cout << "(6) Listar Peliculas por hilera" << endl;
        cout << "(7) Listar Peliculas de un rango de annos" << endl;
        cout << "(8) Listar Peliculas menos solicitadas que..." << endl;
        cout << "(9) Eliminar Peliculas menos solicitadas que..." << endl;
        cout << "(10) Agregar Categoria" << endl;
        cout << "(11) Remover Categoria" << endl;
        cout << "(12) Consultar Categoria" << endl;
        cout << "(13) Listar todos los datos" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
            case 1: {
                // Agregar (Sin repetidos y en forma ascendente)
                break;
            }
            case 2: {
                // Retirar (Se solicita el nombre y si es necesario el año)
                break;
            }
            case 3: {
                // Consultar (Se solicita el nombre y si es necesario el año)
                break;
            }
            case 4: {
                // Modificar (Se solicita el nombre y si es necesario el año)
                break;
            }
            case 5: {
                // Listado catálogo completo en forma ascendente (descendente) por nombre (año)
                break;
            }
            case 6: {
                // Listar películas cuyo nombre contenga una hilera específica (Por ejemplo, si se busca Potter deben
                //aparecer todas las películas que tengan Potter como parte de su nombre)
                break;
            }
            case 7: {
                // Listado de catálogo de películas de un rango de año específico (Ejemplo puedo solicitar las películas
                //entre 2010 y 2015)
                break;
            }
            case 8: {
                // Listar películas cuya solicitud sean inferior a un límite dado (Ejemplo listar las películas cuyas solicitudes
                //sean mejor a 3 ocasiones)
                break;
            }
            case 9:
                // Eliminar de la lista las películas cuya solicitud sea inferior a un límite dado (Ejemplo eliminar todas las
                //películas cuyo número de solicitudes sea menor a 2 veces, es decir, las que fueron solicitadas 0 o 1 vez)
                break;
            case 10:
                // Categorias: agregar ordenado
                break;
            case 11:
                // Categorias: remover
                break;
            case 12:
                // Categorias: consultar
                break;
            case 13:
                // Categorias: listar todos los datos
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
