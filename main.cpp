#include <iostream>
#include "header.h"

// variables importantes
const int max_instrucciones = 100;
const int max_datos = 1000;
const int num_registros = 8;
const int pc_registro = 7;

// estructuras importantes
int datos_memoria[max_datos] = { 0 };  
int registros[num_registros] = { 0 };   
std::string filePath = "";      

int main() {
    bool programm_running_flag = true;

    while (programm_running_flag) {
        printMenu();    
        int opcion = 0;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Seleccione un archivo para ejecutar\n" << std::endl;
            std::cin >> filePath;
            readInstructionCSV(filePath);   
            break;
        case 2: {
            int id, p1, p2, p3;
            std::string code;
            std::cout << "Introduzca una instrucción en el formato: ID CODE P1 P2 P3\n" << std::endl;
            std::cin >> id >> code >> p1 >> p2 >> p3;
            Instruction instr(id, code, p1, p2, p3);    
            ejecutarInstruccion(instr, registros, datos_memoria);   
            break;
        }
        case 3:
            programm_running_flag = false;
            std::cout << "Saliendo del programa...\n" << std::endl;
            break;
        default:
            std::cout << "Opción no válida, intente de nuevo.\n" << std::endl;
            break;
        }
    }

    return 0;
}
