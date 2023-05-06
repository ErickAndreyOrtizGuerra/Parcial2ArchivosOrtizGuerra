#include <iostream>
#include <filesystem>
#include <windows.h>
#include <fstream>

namespace fs = std::filesystem;

void agregartextoarchivo(const std::string& nombredearchivo, int numerodelineas) {
    std::ofstream archivo(nombredearchivo, std::ios_base::app);
    if (archivo.is_open()) {
        for (int i = 1; i <= numerodelineas; i++) {
            archivo << "lineas " << i  << std::endl;
        }
        archivo.close();
        std::cout << "texto agregado: " << nombredearchivo << std::endl;
    } else {
        std::cout << "no se pudo abrir: " << nombredearchivo << std::endl;
    }
}

int main() {
    int numArchivos;
    std::cout << "ingrese la cantidad de archivos que desea crear :) : ";
    std::cin >> numArchivos;

    std::string directorio;
    if (numArchivos % 2 == 0) {
        directorio = "C://Users//HP Core i7//Documents//par//";
    } else {
        directorio = "C://Users//HP Core i7//Desktop//impar//";
    }

    if (!fs::exists(directorio)) {
        if (!fs::create_directories(directorio)) {
            std::cout << "No se pudo crear el directorio.\n";
            return 1;
        }
    }

    for (int i = 1; i <= numArchivos; i++) {
        std::string nombredelarchivo2 = directorio + "documento" + std::to_string(i) + ".txt";
        std::ofstream archivo(nombredelarchivo2);
        if (archivo.is_open()) {
            archivo << "numero de lineas del documento: " << i << std::endl;
            archivo.close();
            std::cout << "archivo creado: " << nombredelarchivo2 << std::endl;
            agregartextoarchivo(nombredelarchivo2, i);
        } else {
            std::cout << "no se pudo crear: " << nombredelarchivo2 << std::endl;
        }
    }

    return 0;
}





