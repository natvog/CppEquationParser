// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel - Oct 2023

// This file - project2.cpp - contains the main function for the project 2 skeleton. It reads an input file named input.txt
// that contains one statement that includes an expression following by a sequence of variable assignments.
// It parses each statement and then evaluates it.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& in);


int main() {
	const int SIZE = 256;
	Expression* expression;
    char paren, comma, line[SIZE];
	string message;
 
	ifstream fin;
	fin = ifstream("/Users/natalievogel/cpp/input.txt");
	if (!(fin.is_open())) {
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}
	
	while (true) {
        fin.getline(line, SIZE);
		if (!fin)
			break;     // break out of loop if end of file
		
		// display input line ...
		cout << endl << endl << "Curr InputFile Line: " << line << " " << endl;
		
		// Read line into stringstream "in" var for ease of parsing - token at a time.
		// Symbol '>>' outputs a token, then moves to next (using internal placeholder) ...
		stringstream in(line, ios_base::in); 
		
		cout << "  project2.cpp -> stringstream in: " << in.str() << endl;    // display entire str stream (does not affect placeholder)
		
		/**** Or display a word at a time moving intenal placeholder after each '>>' ...
		string strmWrd;
        while (in >> strmWrd)
          cout <<  "  Value of string strWrd: " << strmWrd << endl;   
	    ****/
		
		in >> paren;    // 1st token sb a left paren - store in paren var
		try {
			expression = SubExpression::parse(in);    // get entire expression portion of line - assignment part later ...
			cout <<  "  project2.cpp -> expression pointer returned by SubExpression.parse(in) : " << expression << endl;    // mem address for expression
			
            // catch any errors in building expression ...
			if (expression == 0)     // if no mem address, could not parse line
               throw message = "\tUnable to parse expression from current file line.  \n\tEntry will be skipped and the next line retrieved.\n";			
			
			in >> comma;    // at end of expression, should be a comma
			// cout << "  project2.cpp -> value of comma var after stmt 'in >> comma' -> " << comma << endl;  
			
			parseAssignments(in);   // get assignment portion 
			
			double result = expression->evaluate();    
			cout << "Expression Value Is: " << result << endl;
			
		}
		catch (string message) {        // displays certain error msgs for no assign or more than 1 assign
			cout << message << endl;
		}
	}
	
	cout << "\nCompleted processing input file." << endl;
	system("pause");
	return 0;
}




void parseAssignments(stringstream& in) {
	char assignop, delimiter;
    string variable;
    //int value;  
    double value;   	 // must handle floating points
	string message;
	
	symbolTable.clear();   // clear symbol table for new line from file 
    do {
        variable = parseName(in);
		cout << "   parseAssignments -> parseName(in) returned variable: " << variable << endl;  // nv
        in >> ws >> assignop >> value >> delimiter;
		//cout << "   parseAssignments -> assignop: " << assignop << endl;
		//cout << "   parseAssignments -> value: " << value << endl; 
		//cout << "   parseAssignments -> delimiter: " << delimiter << endl; 
		
		// check if var already exists ...
		if ( symbolTable.lookUp(variable) != -1 )
		  throw message = "\tVariable '" +variable+ "' already has a value.  Cannot assign another one. \n\tEntry will be skipped and the next line retrieved.\n";	;
	  
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
   
