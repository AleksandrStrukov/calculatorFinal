using namespace std;
#include <iostream>
#include "calculator.h"
#include <string>
#include <cmath>
using Number = double;


bool ReadNumber(Number& result) {
	if (cin >> result) {
		return true;
	}
	else {
		cerr << "Error: Numeric operand expected" << endl;
		return false;
	}
}

bool RunCalculatorCycle () {
	Number result = 0;   
    Number current = 0;     
    string operation;
    Number saveNum;
    bool memorySaved = false;

if (!ReadNumber(result)) {
	return false;
}
	while (true) {
        cin >> operation;

        if (operation == "=") {
            cout << result << endl;
            continue;
        } else if (operation == "q") {
            break;
        } else if (operation == "c") {
            result = 0; 
            continue;
        }  else if (operation == "s") {
            saveNum = result;     
            memorySaved = true;  
            continue;
        } else if (operation == "l") {
            if (memorySaved) {
                result = saveNum; 

                continue;
            } else {
                cerr << "Error: Memory is empty" << endl;
                break;
            }
        }
        if (!ReadNumber(current)) {
        	break;
		}

        if (operation == "+") {
            result += current;
        } else if (operation == "-") {
            result -= current;
        } else if (operation == "*") {
            result *= current;
        } else if (operation == "/") {
            result /= current;
        } else if (operation == "**") {
            result = pow(result, current);
        }
        else if (operation == ":") {
            result = current;
        } else {
            cerr << "Error: Unknown token " << operation << endl;
            break;

        }
    }
    return true;
}
