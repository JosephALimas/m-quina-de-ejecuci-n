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


void printMenu(){
    cout<<"--------Maquina de ejecución--------";
    cout<<"Seleccione una opción";
    cout<<"1.- Ejecutar un archivo";
    cout<<"2.- Ejecutar instrucciónes";
    cout<<"3.- Salir";
}

void ejecutarArchivo(string filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    vector<Instruction> instrucciones;

    // Leer archivo línea por línea
    while (getline(file, linea)) {
        if (linea.empty() || linea[0] == '*') {
            continue;  // Ignorar comentarios y líneas vacías
        }

        stringstream ss(linea);
        int id, p1, p2, p3;
        string code;

        ss >> id >> code >> p1 >> p2 >> p3;
        Instruction instr(id, code, p1, p2, p3);
        instrucciones.push_back(instr);
    }

    // Ejecutar las instrucciones
    for (const auto& instr : instrucciones) {
        ejecutarInstruccion(instr, registros, datos_memoria);
    }

    file.close();
}

// Función para ejecutar instrucciones manualmente
void ejecutarInstruccionManual() {
    int id, p1, p2, p3;
    string code;
    
    cout << "Introduzca una instrucción en el formato: ID CODE P1 P2 P3" << endl;
    cin >> id >> code >> p1 >> p2 >> p3;
    
    Instruction instr(id, code, p1, p2, p3);
    ejecutarInstruccion(instr, registros, datos_memoria);
}

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
        case 2:
            cout<<"Introduzca una instruccion"<<endl;
            
            break;
        
        default:
            break;
        }
    } 


    return 0;
}
