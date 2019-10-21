# CSCE 311 Project 3

##How to Compile and Use
	once in the directory /master, you can enter the command 'make' to compile the code and the output will be two executables: normalIO and mmapIO.
	typing ./normalIO or ./mmapIO will run those executables with "temp.txt" as the text file used. If you follow the executable ./normalIO or
	./mmapIO with any .txt file, it will instead use that .txt file. The executables count each character in the .txt file, and print to the console
	the result, the amount of each character in the text file.

##Subproject 1:
	Colby Hill wrote the code for all of the helper functions in hfunc.h that counted the chars and returned them into the correct location in an array
	of ints, and wrote the function that printed the amount of chars in the file for the array of ints. Colby also wrote the code for the normal file IO
	part of the subproject.
	Nathanael Ellsworth wrote the code for the memory mapped IO part of the subproject, and used the helper functions in hfunc.h to correclty count and
	print the chars in the text file given. Nathanael also wrote the Makefile for compiling and the README.
