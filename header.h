#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "utilities.h"
using namespace std;

class Instruction{
    private: 
        int instruction_id;
        string instruction_code;
        int parameter_1;
        int parameter_2;
        int parameter_3;
    public:
        Instruction();
        Instruction(int instruction_id, string instruction_code,
        int parameter_1, int parameter_2, int parameter_3);
        void setInstructionId(int instruction_id);
        void setinstructionCode(string instruction_code);
        void setParameter1(int parameter_1);
        void setParameter2(int parameter_2);
        void setParameter3(int parameter_3);
        int getInstructionId();
        string getInstructionCode();
        int getParameter1();
        int getParameter2();
        int getParameter3();
};

void printMenu();
