// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel - Oct 2023


// This file - parse.cpp - contains the body of the function parseName. That function consumes all alphanumeric 
// characters until the next whitespace and returns the name that those characters form.

#include <cctype>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

#include "parse.h"

string parseName(stringstream& in) {
    char alnum;
    string name = "";
	
    in >> ws;
	// read entire var (can be multiple chars) including underscore ...
    while ( isalnum(in.peek()) || in.peek() == '_' ) {     // while next token is an alphanumeric or underscore
        in >> alnum;
        name += alnum;
		cout << "        parse.cpp -> name after 'name += alnum' -> " << name << endl;  //nv
    }
	
    return name;  
}