#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iomanip>

using namespace std;


unordered_map<string, string> opcodes = {
    {"MVI", "3E"}, 
    {"LDA", "3A"}, 
    {"STA", "32"}, 
    {"JMP", "C3"}   
};

unordered_map<string, int> symbolTable;

void pass1(const vector<string>& sourceCode) {
    int lc = 0;  
    
    for (const string& line : sourceCode) {
        stringstream ss(line);
        string label, instruction, operand;
        
       
        if (line.find(':') != string::npos) {
            ss >> label;
            label.pop_back(); 
            symbolTable[label] = lc;
            ss >> instruction;
        } else {
            ss >> instruction;
        }
        
       
        if (instruction == "ORG") {
            ss >> operand;
            lc = stoi(operand, nullptr, 16); 
        } else if (instruction == "DS") {
            ss >> operand;
            lc += stoi(operand);
        } else {
           
            if (opcodes.find(instruction) != opcodes.end()) {
                lc += 1;
            }
        }
    }
}

vector<string> pass2(const vector<string>& sourceCode, const unordered_map<string, int>& symbolTable) {
    int lc = 0;  
    vector<string> machineCode;
    
    for (const string& line : sourceCode) {
        stringstream ss(line);
        string label, instruction, operand;
        
       
        if (line.find(':') != string::npos) {
            ss >> label;
            ss >> instruction;
        } else {
            ss >> instruction;
        }
        
        if (instruction == "ORG") {
            ss >> operand;
            lc = stoi(operand, nullptr, 16); 
        } else if (instruction == "DS") {
            ss >> operand;
            lc += stoi(operand);
        } else {
            if (opcodes.find(instruction) != opcodes.end()) {
                string opcode = opcodes[instruction];
                if (ss >> operand) {
                    if (symbolTable.find(operand) != symbolTable.end()) {
                        operand = to_string(symbolTable.at(operand));
                    }
                }
                
                stringstream hexLC;
                hexLC << setw(4) << setfill('0') << hex << uppercase << lc;
                string codeLine = hexLC.str() + ": " + opcode + " " + operand;
                machineCode.push_back(codeLine);
                
                lc += 1;
            }
        }
    }
    
    return machineCode;
}

int main() {
    
    vector<string> sourceCode = {
        "START: MVI A, 23H",
        "      LDA 2500H",
        "LOOP: STA 2400H",
        "      JMP LOOP",
        "      END"
    };
    

    pass1(sourceCode);
    cout << "Symbol Table:" << endl;
    for (const auto& entry : symbolTable) {
        cout << entry.first << ": " << entry.second << endl;
    }
    
    
    vector<string> machineCode = pass2(sourceCode, symbolTable);
    cout << "Machine Code:" << endl;
    for (const string& line : machineCode) {
        cout << line << endl;
    }
    
    return 0;
}

