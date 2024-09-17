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

void ejecutarOperacion(const Instruction& instr, int* registros){
    string instr_code = instr.getInstructionCode();
    int r =instr.getParameter1();
    int s = instr.getParameter2();
    int t = instr.getParameter3();  

    if (instr_code == "HALT") {
        cout << "Máquina detenida." << endl;
        exit(0);  // Detiene la ejecución
    } 
    else if (instr_code == "IN") {
        cout << "Introduce un valor para reg[" << r << "]: ";
        cin >> registros[r];  // Almacena el valor en reg[r]
    } 
    else if (instr_code == "OUT") {
        cout << "Valor de reg[" << r << "]: " << registros[r] << endl;  // Imprime el valor de reg[r]
    } 
    else if (instr_code=="ADD"){
        registros[r] = registros[s] + registros[t]; // Suma: reg[r] = reg[s] + reg[t]
    } 
    else if(instr_code=="SUB"){
        registros[r] = registros[s] - registros[t]; // Resta: reg[r] = reg[s] - reg[t]
    }
    else if (instr_code == "MUL") {
        registros[r] = registros[s] * registros[t]; // Multiplicación: reg[r] = reg[s] * reg[t]
    }
    else if (instr_code == "DIV") {
        if (registros[t] == 0) {
            cerr << "Error: División por cero." << endl;
            exit(EXIT_FAILURE);  // Finaliza el programa en caso de error
        }
        registros[r] = registros[s] / registros[t]; // División: reg[r] = reg[s] / reg[t]
    }

    else {
        cerr << "Error: Instrucción desconocida: " << instr_code << endl;
        exit(EXIT_FAILURE);  // Finaliza el programa si encuentra una instrucción no válida
    }
}


void ejecutarMemoria(const Instruction& instr, int* registros, int* datos_memoria){
    string instr_code = instr.getInstructionCode();
    int r =instr.getParameter1(); 
    int d = instr.getParameter2();
    int s = instr.getParameter3();
    int a=d+registros[s]; // si está fuera de los límites del arreglo ERROR

    if (instr_code=="LD"){
        if(a<0 ||a>=max_datos){
            cout<<"Error: dirección fuera de los límites del arreglo"<<endl;
             exit(EXIT_FAILURE);
        }else{
            registros[r]=datos_memoria[a]; // carga el valor de la memoria en el registro
        }
    }else if(instr_code=="ST"){
        if(a<0 ||a>=max_datos){
            cout<<"Error: dirección fuera de los límites del arreglo"<<endl;
             exit(EXIT_FAILURE);
        }else{
            datos_memoria[a]=registros[r];// guarda el valor del registro en la memoria
        }
    }else if(instr_code=="LDA"){
        registros[r]=a;//carga dirección
       
    }else if(instr_code=="LDC"){
        registros[r]=d;//carga constante
    }
    else if(instr_code=="JLT"){
        if(registros[r]<0){
            registros[pc_registro]=a;//salto si <0
        }
    }else if(instr_code=="JLE"){
        if(registros[r]<=0){
            registros[pc_registro]=a;//salto si menor o igual a 0 
        }}
    else if(instr_code=="JGE"){
        if(registros[r]>=0){
            registros[pc_registro]=a;//salto si mayor o igual a 0
        }}
    else if(instr_code=="JGT"){
        if(registros[r]>0){
            registros[pc_registro]=a;//salto si mayor a 0
        }}
    else if(instr_code=="JEQ"){
        if(registros[r]==0){
            registros[pc_registro]=a;//salto si igual a 0
        }}
    else if(instr_code=="JNE"){
        if(registros[r]!=0){
            registros[pc_registro]=a;//salto si diferente de 0
        }}
    else{
        cin<<"Error: instrucción no válida"<<endl;
            exit(EXIT_FAILURE);
        }
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

int getFileLength(string filepath) {
    ifstream instructions(filepath, ios::in); // se lee el archivo
    if (!instructions) { //valiación en caso de que no se haya leido de manera correcta el archivo
        cerr << "El archivo de instrucciones no se pudo leer correctamente, por favo intente de nuevo\n" << endl;
        exit(EXIT_FAILURE);
    }
    std::string linea;
    int contadorLineas = 0;

    while (getline(instructions, linea)) {
        contadorLineas++;  // Incrementar contador por cada línea leída
    }

    instructions.close();
    cout << contadorLineas << endl;
    return contadorLineas;
}


void readInstructionCSV(string filepath, int file_length) {
    ifstream instructions(filepath, ios::in); // se lee el archivo
    if (!instructions) { //valiación en caso de que no se haya leido de manera correcta el archivo
        cerr << "El archivo de instrucciones no se pudo leer correctamente, por favo intente de nuevo\n" << endl;
        exit(EXIT_FAILURE);
    }
    string temp_linea; // declaramos el string en donde vamos a almacenar el csv
    while (getline(instructions, temp_linea)) {
        int temp_id = 0;
        string temp_instruction = "";
        int temp_parameter1 = 0;
        int temp_parameter2 = 0;
        int temp_parameter3 = 0;

        stringstream ss(temp_linea);
        string component;
        getline(ss, component, ':');

    }


    for (int i = 0; i < file_length; i++) {
        getline(instructions, temp_linea, ':');
        

    }

    /*
    while (getline(instructions, temp_linea, '\n')) {
        cout << temp_linea << endl;
        while (getline(instructions, temp_linea, ':')) {
            cout << temp_linea << endl;
            int temp_instruction_id = stoi(temp_linea);
            //getline
        }
    }
    */
}
void ejecutarInstruccion(const Instruction& instr, int* registros, int* datos_memoria) {
    string instr_code = instr.getInstructionCode();

    if(instr_code=="ADD"||instr_code=="SUB"||instr_code=="MUL"||instr_code=="DIV"||instr_code=="IN"||instr_code=="OUT"||instr_code=="HALT"){
        ejecutarOperacion(instr, registros);
}else if(instr_code=="LD"||instr_code=="LDA"||instr_code=="ST"||instr_code=="LDC"||instr_code=="JLT"||instr_code=="JLE"||instr_code=="JGE"||instr_code=="JEQ"||instr_code=="JNE"){
    ejecutarMemoria(instr, registros, datos_memoria);
}else{
    cout<<"Error: instrucción no válida"<<endl;
    exit(EXIT_FAILURE);
}
}