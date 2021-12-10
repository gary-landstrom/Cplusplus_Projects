#include <Python.h>

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

/* The second function provided in the starter code worked for this assignment with minor changes.
 * The only change made to the starter code is a new name for the int value. "userNum" It is worth
 * noting that the program would be fine without this change, the switch was made to help me understand
 * the provided code better.
 */

 // In order to call the following function the name of the Python function must be called followed by an int val to send.
int callIntFunc(string proc, int userNum) {

	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", userNum);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

/* I wanted a single function to print the user menu and drive the program. So below the needed
 * variables are declared before the menu is printed, after that the loop begins printing the menu
 * and prompting the user for input in the terminal. If the user types 1 or 2 they are prompted again
 * for an additional integer. The userNum int is passed to Python for calculations and the sum is returned
 * here to be printed in the terminal. The only way the loop is terminated is if the user types 3.
 */

void menu() {
	int userIn, userNum;
	userIn = 0;
	bool run = true;

	// I opted for a bool variable to run the loop, if userIn is 3 the bool val switches to false killing the loop.
	while (run == true) {

		cout << "\n1: Display a multiplication Table \n2: Double a Value \n3: Exit \nEnter your selection as a number 1, 2, or 3.\n";

		// Checks the user input for non int vals
		while (!(cin >> userIn)) {
			cout << "Invalid input.\n";
			cout << "\n1: Display a multiplication Table \n2: Double a Value \n3: Exit \nEnter your selection as a number 1, 2, or 3.\n";
			cin.clear();
			cin.ignore(123, '\n');
		}

		if (userIn == 1) {
			cout << "Please enter an integer.";
			// Checks the user input for non int vals
			while (!(cin >> userNum)) {
				cout << "Invalid input please enter a number.\n";
				cin.clear();
				cin.ignore(123, '\n');
			}
			// The user input is taken and passed into the Python function, then returned and printed.
			cout << callIntFunc("MultiplicationTable", userNum) << "\n\n";
		}

		if (userIn == 2) {
			cout << "Please enter an integer.";
			// Checks the user input for non int vals
			while (!(cin >> userNum)) {
				cout << "Invalid input please enter a number\n";
				cin.clear();
				cin.ignore(123, '\n');
			}
			// The same C++ function is called but the DoubleValue Python function is called instead of MultiplicationTable.
			cout << callIntFunc("DoubleValue", userNum) << "\n\n";
		}

		if (userIn == 3) {
			cout << "\nThanks for using the program.\n";
			// The bool val 'run' is only false when the user inputs 3 killing the loop.
			run = false;
		}

		// Basic catch for invalid input
		if (userIn <= 0 || userIn >= 4) {
			cout << "\nInvalid input please use 1, 2, or 3.\n";
		}
	}
}


int main()
{

	// A single call to menu() is all that is required to run
	menu();

	return 0;
}
