

  
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int Column1, Column2;

/*

cout << argc << endl;

for(int i = 0; i < argc; i++)
	cout << argv[i] << endl; 
argc is the number of inputs and argv is the inputs themselves

*/ 
if(argc != 3) {
        cout << "Usage: " << argv[0] << " <Input file> <outfile>" << endl;
        exit(0);
}

inputFile.open(argv[1]);
outputFile.open(argv[2]);
    
if(!inputFile){
	cout << "error opening input file" << endl;
	exit(0);

}

if(!outputFile) {
	cout << "error opening output file" << endl;
	exit(0);


}

while(!inputFile.eof()) {//end-of-file
	inputFile >> Column1 >> Column2;
	outputFile << Column1 << Column2;
}
    
    

    inputFile.close();
    outputFile.close();



    return (0);
}
