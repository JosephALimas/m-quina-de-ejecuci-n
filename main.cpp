#include <iostream>
#include "header.h"


// variables importantes
const int max_instrucciones = 100;
const int max_datos = 1000;
const int num_registros = 8;
const int pc_registro = 7;

// estructuras importantes
int datos_memoria[] = {0,0,0,0,0,0,0,0};
int registros[] = {0,0,0,0,0,0,0,0};
string filePath = "";

int main(){
    bool programm_running_flag = true;
    while(programm_running_flag){
        printMenu();
        int opcion = 0;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            cout<<"Seleccione un archivo para ejecutar"<<endl;
            cin>>filePath;
            break;
        case 2: {
                int id, p1, p2, p3;
                string code;
                cout << "Introduzca una instrucción en el formato: ID CODE P1 P2 P3" << endl;
                cin >> id >> code >> p1 >> p2 >> p3;
                Instruction instr(id, code, p1, p2, p3);
                ejecutarInstruccion(instr, registros, datos_memoria);
            case 3:
                programm_running_flag = false;
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción no válida, intente de nuevo." << endl;
                break;
        }
    }

    return 0;
}
