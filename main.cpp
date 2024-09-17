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
int file_length = 0;
std::string filePath = "C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\_quinto_\\teorias_lenguajes\\ejemplo_instruccion.txt";
vector <Instruction> instrucciones;

int main() {
    bool programm_running_flag = true;

    while (programm_running_flag) {
        printMenu();
        int opcion = 0;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Seleccione un archivo para ejecutar\n" << std::endl;
            //std::cin >> filePath;
            file_length = getFileLength(filePath);

            // Validar que el archivo no esté vacío

            readInstructionCSV(filePath, instrucciones);
            for (int i = 0; i <= file_length; i++) {
                ejecutarInstruccion(instrucciones[i], registros, datos_memoria, max_datos, pc_registro);
            }

            break;

        case 2: {
            int id, p1, p2, p3;
            std::string code;
            std::cout << "Introduzca una instrucción en el formato: ID CODE P1 P2 P3\n" << std::endl;
            std::cin >> id >> code >> p1 >> p2 >> p3;

            // Verificar si la entrada es válida
            if (std::cin.fail()) {
                std::cerr << "Entrada inválida, por favor intente de nuevo." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            // Válidas instrucciones de operación y memoria
            std::set<std::string> instrucciones_validas = {
                "ADD", "SUB", "MUL", "DIV",   // Operaciones
                "IN", "OUT", "HALT",          // Entrada/Salida
                "LD", "LDA", "ST",            // Instrucciones de memoria
                "JLT", "JLE", "JGE", "JEQ", "JNE"  // Saltos condicionales
            };

            // Verificar si el código de instrucción es válido
            if (instrucciones_validas.find(code) == instrucciones_validas.end()) {
                std::cerr << "Error: Instrucción desconocida: " << code << std::endl;
                break;  // Salir si la instrucción no es válida
            }

            Instruction instr(id, code, p1, p2, p3);
            ejecutarInstruccion(instr, registros, datos_memoria, max_datos, pc_registro);
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
