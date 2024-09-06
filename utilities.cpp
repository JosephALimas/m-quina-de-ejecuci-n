#include "header.h"
void printMenu(){
    cout<<"--------Maquina de ejecución--------";
    cout<<"Seleccione una opción";
    cout<<"1.- Ejecutar un archivo";
    cout<<"2.- Ejecutar instrucciónes";
}

Instruction::Instruction(int instruction_id, string instruction_code, 
int parameter_1, int parameter_2, int parameter_3){
    this-> instruction_id = instruction_id;
    this->instruction_code = instruction_code;
    this-> parameter_1 = parameter_1;
    this-> parameter_2 = parameter_2;
    this-> parameter_3 = parameter_3;
}
void Instruction::setInstructionId(int instruction_id){
    this->instruction_id = instruction_id;
}
void Instruction::setinstructionCode(string instruction_code){
    this->instruction_code = instruction_code;
}
void Instruction::setParameter1(int parameter_1){
    this->parameter_1 = parameter_1;
}
void Instruction::setParameter2(int parameter_2){
    this->parameter_2 = parameter_2;
}
void Instruction::setParameter3(int parameter_3){
    this->parameter_3 = parameter_3;
}
int Instruction::getInstructionId(){
    return instruction_id;
}
string Instruction::getInstructionCode(){
    return instruction_code;
}
int Instruction::getParameter1(){
    return parameter_1;
}
int Instruction::getParameter2(){
    return parameter_2;
}
int Instruction::getParameter3(){
    return parameter_3;
}
void readInstructionCSV(){

}
