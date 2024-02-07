// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel - Oct 2023


// This file - variable.cpp - contains the body of the function contained in The Variable class. The evaluate function 
// looks up the value of a variable in the symbol table and returns that value.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"

extern SymbolTable symbolTable;
string message = "\tA variable not initialized or properly set cannot be used.  \n\tCurrent entry will be skipped and the next line retrieved.\n"; 	

double Variable::evaluate() {
	cout << "  variable.cpp -> symbolTable.lookUp(name) -> " << symbolTable.lookUp(name) << endl;  //nv
	
	if ( symbolTable.lookUp(name) == -1 )
		throw message;			
			
    return symbolTable.lookUp(name);
}