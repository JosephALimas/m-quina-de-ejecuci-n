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
 

int main(){
    bool programm_running_flag = true;
    while(programm_running_flag){
        printMenu();
        int opcion = 0;
        cin>>opcion;
    } 


    return 0;
}