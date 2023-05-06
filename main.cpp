#include <iostream>
#include <filesystem>
#include <windows.h>
#include <fstream>

namespace fs = std::filesystem;

int main() {
    int numArchivos;
    std::cout << "Ingrese la cantidad de archivos a crear: ";
    std::cin >> numArchivos;

    std::string directorio;
    if (numArchivos % 2 == 0) {
        directorio = "C://Users//HP Core i7//Documents//par";
    } else {
        directorio = "C://Users//HP Core i7//Desktop//Impar";
    }

    if (!fs::exists(directorio)) {
        if (!fs::create_directories(directorio)) {
            std::cout << "No se pudo crear el directorio.\n";
            return 1;
        }
    }

    for (int i = 1; i <= numArchivos; i++) {
        std::string nombreArchivo = directorio + "documento" + std::to_string(i) + ".txt";
        std::ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            archivo << "Contenido del documento " << i << std::endl;
            archivo.close();
            std::cout << "Archivo creado: " << nombreArchivo << std::endl;
        } else {
            std::cout << "No se pudo crear el archivo: " << nombreArchivo << std::endl;
        }
    }

    return 0;
}




