#include "header.h"

// Función para imprimir el menú
void printMenu() {
    cout << "--------Maquina de ejecucion--------\n";
    cout << "Seleccione una opcion\n";
    cout << "1.- Ejecutar un archivo\n";
    cout << "2.- Ejecutar instrucciónes\n";
}
Instruction::Instruction() {
    this->instruction_id = 0;
    this->instruction_code = "";
    this->parameter_1 = 0;
    this->parameter_2 = 0;
    this->parameter_3 = 0;
}
// Constructor de la clase Instruction
Instruction::Instruction(int instruction_id, string instruction_code,
    int parameter_1, int parameter_2, int parameter_3) {
    this->instruction_id = instruction_id;
    this->instruction_code = instruction_code;
    this->parameter_1 = parameter_1;
    this->parameter_2 = parameter_2;
    this->parameter_3 = parameter_3;
}

// Métodos setter
void Instruction::setInstructionId(int instruction_id) {
    this->instruction_id = instruction_id;
}
void Instruction::setInstructionCode(string instruction_code) {
    this->instruction_code = instruction_code;
}
void Instruction::setParameter1(int parameter_1) {
    this->parameter_1 = parameter_1;
}
void Instruction::setParameter2(int parameter_2) {
    this->parameter_2 = parameter_2;
}
void Instruction::setParameter3(int parameter_3) {
    this->parameter_3 = parameter_3;
}
int Instruction::getInstructionId() {
    return instruction_id;
}
string Instruction::getInstructionCode() {
    return instruction_code;
}
int Instruction::getParameter1() {
    return parameter_1;
}
int Instruction::getParameter2() {
    return parameter_2;
}
int Instruction::getParameter3() {
    return parameter_3;
}
void readInstructionCSV(string filepath) {
    cout << "PRUEBA DE QUE ENTRA EN LA FUNCION READINSTRUCIONS" << endl;
    ifstream instructions(filepath, ios::in); // se lee el archivo
    if (instructions) { //valiación en caso de que no se haya leido de manera correcta el archivo
        cerr << "El archivo de instrucciones no se pudo leer correctamente, por favo intente de nuevo\n" << endl;
        exit(EXIT_FAILURE);
    }
    string temp_linea; // declaramos el string en donde vamos a almacenar el csv
    while (getline(instructions, temp_linea, '\n')) {
        while (getline(instructions, temp_linea, ' ')) {
            int temp_instruction_id = stoi(temp_linea);
            //getline
        }
    }
}
void ejecutarInstruccion(const Instruction& instr, int* registros, int* datos_memoria) {

}