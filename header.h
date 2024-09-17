#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <set>
#include <limits>
using namespace std;

// Clase para manejar las instrucciones
class Instruction {
private:
    int instruction_id;
    string instruction_code;
    int parameter_1;
    int parameter_2;
    int parameter_3;

public:
    Instruction(); // Constructor por defecto
    Instruction(int instruction_id, string instruction_code, int parameter_1, int parameter_2, int parameter_3);


    // Métodos para acceder y modificar los atributos de la instrucción
    void setInstructionId(int instruction_id);
    void setInstructionCode(string instruction_code);
    void setParameter1(int parameter_1);
    void setParameter2(int parameter_2);
    void setParameter3(int parameter_3);
    int getInstructionId();
    string getInstructionCode();
    int getParameter1();
    int getParameter2();
    int getParameter3();
};

// Funciones para manejar la máquina de ejecución
//void ejecutarArchivo(string filePath);
void ejecutarInstruccion( Instruction& instr, int* registros, int* datos_memoria, const int& max_datos, const  int& pc_registro);
void ejecutarOperacion( Instruction& instr, int* registros);
void ejecutarMemoria( Instruction& instr, int* registros, int* datos_memoria, const  int& max_datos, const int& pc_registro);
void printMenu();
int getFileLength(string filetpath);
void readInstructionCSV(string filepath, vector<Instruction>& instrucciones);