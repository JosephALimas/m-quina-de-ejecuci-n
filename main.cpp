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
