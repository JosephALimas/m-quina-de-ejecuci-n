#include "header.h"

// Función para imprimir el menú
void printMenu() {
    cout << "--------Maquina de ejecucion--------\n" << endl;
    cout << "1.- Instrucciones de ejecución\n" << endl;
    cout << "2.- Ejecutar un archivo\n" << endl;
    cout << "3.- Ejecutar instrucción por instrucción\n" << endl;
    cout << "4.- Reiniciar los registros\n" << endl;
    cout << "5.- Finalizar la ejecución\n" << endl;
    cout << "Seleccione una opcion: \n" << endl;
}
void printRegistros(int* registros, int max_registros) {
    cout << "---------------" << endl;
    for (int i = 0; i < max_registros; i++) {
        cout << "#" << i << ": " << registros[i] << endl;
    }
    cout << "---------------" << endl;
}
void printAyuda() {
    cout << "Instrucciones tipo Operación (formato instrucción r,s,t)\n"<<endl;
    cout << "-------------------------------------------------------\n" << endl;
    cout << "HALT\tDetiene la ejecución de la máquina. Los parámetros son ignorados.\n" << endl;
    cout << "IN\treg[r] se lee de la entrada y se almacena en reg[r] (s y t son ignorados).\n" << endl;
    cout << "OUT\treg[r] se escribe en la salida con el valor de reg[r] (s y t son ignorados).\n" << endl;
    cout << "ADD\treg[r] = reg[s] + reg[t]\n" << endl;
    cout << "SUB\treg[r] = reg[s] - reg[t]\n" << endl;
    cout << "MUL\treg[r] = reg[s] * reg[t]\n" << endl;
    cout << "DIV\treg[r] = reg[s] / reg[t] (debe generar error si se divide por cero).\n\n" << endl;
    cout << "Instrucciones tipo Memoria (formato instrucción r,d(s))\n" << endl;
    cout << "-------------------------------------------------------\n" << endl;
    cout << "LD\treg[r] = datos_Memoria[a]\n" << endl;
    cout << "LDA\treg[r] = a\n" << endl;
    cout << "LDC\treg[r] = d (s es ignorado)\n" << endl;
    cout << "ST\tdatos_Memoria[a] = reg[r]\n" << endl;
    cout << "JLT\tIf reg[r] < 0 reg[REG_EJEC] = a\n" << endl;
    cout << "JLE\tIf reg[r] <= 0 reg[REG_EJEC] = a\n" << endl;
    cout << "JGE\tIf reg[r] >= 0 reg[REG_EJEC] = a\n" << endl;
    cout << "JGT\tIf reg[r] > 0 reg[REG_EJEC] = a\n" << endl;
    cout << "JEQ\tIf reg[r] == 0 reg[REG_EJEC] = a\n" << endl;
    cout << "JNE\tIf reg[r] != 0 reg[REG_EJEC] = a\n" << endl;

}

void reiniciarRegistros(int* registros, int num_registros) {
    for (int i = 0; i < num_registros; i++) {
        registros[i] = 0;
    }
    printRegistros(registros, num_registros);

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

void readInstructionCSV(string filepath, vector<Instruction>& instrucciones) {
    ifstream instructions(filepath, ios::in); // se lee el archivo
    if (!instructions) { //validación en caso de que no se haya leído de manera correcta el archivo
        cerr << "El archivo de instrucciones no se pudo leer correctamente, por favor intente de nuevo\n" << endl;
        exit(EXIT_FAILURE);
    }
    string temp_linea; // declaramos el string en donde vamos a almacenar cada línea del archivo
    while (getline(instructions, temp_linea)) {
        int temp_id = 0;
        string temp_instruction = "";
        int r = 0;
        int s = 0;
        int t = 0;

        // Usamos stringstream para analizar la línea
        stringstream ss(temp_linea);
        string component;

        // Leer el id (número antes del ':')
        getline(ss, component, ':');
        temp_id = stoi(component); // Convertimos el ID a entero

        // Leer el código de instrucción (como "LD", "ST", etc.)
        ss >> temp_instruction; // Lee el código de la instrucción

        // Leer los parámetros r, s, t que están después del código
        ss >> component;

        // Procesar el formato de los parámetros dependiendo de si tiene paréntesis o comas
        if (component.find('(') != string::npos) {
            // Si contiene paréntesis, como 6,0(0)
            string beforeParen = component.substr(0, component.find('('));
            string insideParen = component.substr(component.find('(') + 1, component.find(')') - component.find('(') - 1);

            // Dividimos los valores antes del paréntesis por comas
            stringstream beforeStream(beforeParen);
            string r_str, s_str;
            getline(beforeStream, r_str, ','); // Leer el valor de r
            getline(beforeStream, s_str, ','); // Leer el valor de s

            // Convertir r, s, y t a enteros
            r = stoi(r_str);
            s = stoi(s_str);
            t = stoi(insideParen); // Leer el valor de t desde dentro del paréntesis
        }
        else {
            // Si el formato es con comas, como 0,0,0
            stringstream paramStream(component);
            string r_str, s_str, t_str;
            getline(paramStream, r_str, ','); // Leer el valor de r
            getline(paramStream, s_str, ','); // Leer el valor de s
            getline(paramStream, t_str, ','); // Leer el valor de t

            // Convertir r, s, y t a enteros
            r = stoi(r_str);
            s = stoi(s_str);
            t = stoi(t_str);
        }

        // Crear una nueva instrucción y agregarla al vector
        Instruction temp_instruccion(temp_id, temp_instruction, r, s, t);
        instrucciones.push_back(temp_instruccion);
    }
}

void ejecutarInstruccion(Instruction& instr, int* registros, int* datos_memoria, const int& max_datos, const int& pc_registro, bool& programm_running_flag) {
    string instr_code = instr.getInstructionCode();

    if (instr_code == "ADD" || instr_code == "SUB" || instr_code == "MUL" || instr_code == "DIV" || instr_code == "IN" || instr_code == "OUT" || instr_code == "HALT") {
        ejecutarOperacion(instr, registros, programm_running_flag);
    }
    else if (instr_code == "LD" || instr_code == "LDA" || instr_code == "ST" || instr_code == "LDC" || instr_code == "JLT" || instr_code == "JLE" || instr_code == "JGE" || instr_code == "JEQ" || instr_code == "JNE") {
        ejecutarMemoria(instr, registros, datos_memoria, max_datos, pc_registro);
    }
    else {
        cout << "Error: instrucción no válida" << endl;
        exit(EXIT_FAILURE);
    }
}


void ejecutarOperacion(Instruction& instr, int* registros, bool& programm_running_flag) {
    string instr_code = instr.getInstructionCode();
    int r = instr.getParameter1();
    int s = instr.getParameter2();
    int t = instr.getParameter3();

    if (instr_code == "HALT") {
        cout << "¡¡¡¡Máquina detenida!!!!" << endl;
        programm_running_flag = false;  // Detiene la ejecución
    }
    else if (instr_code == "IN") {
        int temp_int = 0;
        cout << "Introduce un valor para reg[" << r << "]: ";
        cin >> temp_int;  // Almacena el valor en reg[r]
        registros[r - 1] += temp_int;
    }
    else if (instr_code == "OUT") {
        cout << "Valor de reg[" << r << "]: " << registros[r] << endl;  // Imprime el valor de reg[r]
    }
    else if (instr_code == "ADD") {
        registros[r] = registros[s] + registros[t]; // Suma: reg[r] = reg[s] + reg[t]
    }
    else if (instr_code == "SUB") {
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


void ejecutarMemoria(Instruction& instr, int* registros, int* datos_memoria, const int& max_datos, const  int& pc_registro) {
    string instr_code = instr.getInstructionCode();
    int r = instr.getParameter1();
    int d = instr.getParameter2();
    int s = instr.getParameter3();
    int a = d + registros[s]; // si está fuera de los límites del arreglo ERROR

    if (instr_code == "LD") {
        if (a < 0 || a >= max_datos) {
            cout << "Error: dirección fuera de los límites del arreglo" << endl;
            exit(EXIT_FAILURE);
        }
        else {
            registros[r] = datos_memoria[a]; // carga el valor de la memoria en el registro
        }
    }
    else if (instr_code == "ST") {
        if (a < 0 || a >= max_datos) {
            cout << "Error: dirección fuera de los límites del arreglo" << endl;
            exit(EXIT_FAILURE);
        }
        else {
            datos_memoria[a] = registros[r];// guarda el valor del registro en la memoria
        }
    }
    else if (instr_code == "LDA") {
        registros[r] = a;//carga dirección

    }
    else if (instr_code == "LDC") {
        registros[r] = d;//carga constante
    }
    else if (instr_code == "JLT") {
        if (registros[r] < 0) {
            registros[pc_registro] = a;//salto si <0
        }
    }
    else if (instr_code == "JLE") {
        if (registros[r] <= 0) {
            registros[pc_registro] = a;//salto si menor o igual a 0
        }
    }
    else if (instr_code == "JGE") {
        if (registros[r] >= 0) {
            registros[pc_registro] = a;//salto si mayor o igual a 0
        }
    }
    else if (instr_code == "JGT") {
        if (registros[r] > 0) {
            registros[pc_registro] = a;//salto si mayor a 0
        }
    }
    else if (instr_code == "JEQ") {
        if (registros[r] == 0) {
            registros[pc_registro] = a;//salto si igual a 0
        }
    }
    else if (instr_code == "JNE") {
        if (registros[r] != 0) {
            registros[pc_registro] = a;//salto si diferente de 0
        }
    }
    else {
        cout << "Error: instrucción no válida" << endl;
        exit(EXIT_FAILURE);
    }
}

void printOperacion(Instruction& instruccion) {
    cout << instruccion.getInstructionId() << ": " << instruccion.getInstructionCode() << " " << instruccion.getParameter1() << " " << instruccion.getParameter2() << " " << instruccion.getParameter3() << " " << endl;
}
