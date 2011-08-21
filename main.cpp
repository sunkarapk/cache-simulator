#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "access.h"
#include "cache.h"
#include "memory.h"

using namespace std;

// Global variable declaration
Access* accessor;

int main(int argc, char** argv) {
	if(argc!=5) {
		printf("Usage: %s <cache_size_inKB> <block_size_inB> <associativity> <memory_size_inKB>\n", argv[0]);
		return 1;
	}

	// Declaring variables
	int i, j, buf;
	int matrix_n, matrix_m, matrix_p;
	ifstream inFile;
	
	// Opening files
	inFile.open("INPUT");
	
	// Checking for situation of files
	if(!inFile.is_open()) {
		cout << "Error while opening the input file" << endl;
		return 1;
	}

	// Initalize accessor
	accessor = new Access(atoi(argv[4]));

	// Reading matrix lengths
	inFile >> matrix_n >> matrix_m >> matrix_p;

	// Reading matrices A & B
	for(i=0; i<matrix_n; i++)
		for(j=0; j<matrix_m; j++) {
			inFile >> buf;
			accessor->write(buf);
		}
	for(i=0; i<matrix_m; i++)
		for(j=0; j<matrix_p; j++) {
			inFile >> buf;
			accessor->write(buf);
		}

	// Closing files
	inFile.close();

	return 0;
}
