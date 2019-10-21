#ifndef HFUNC_H
#define HFUNC_H

#include <iostream>
#include <string>
using namespace std;

void printResults(int vals[])
{
    cout << "Printing Results:" << "\n";
    cout << "a: " << vals[0] << "\n";
    cout << "b: " << vals[1] << "\n";
    cout << "c: " << vals[2] << "\n";
    cout << "d: " << vals[3] << "\n";
    cout << "e: " << vals[4] << "\n";
    cout << "f: " << vals[5] << "\n";
    cout << "g: " << vals[6] << "\n";
    cout << "h: " << vals[7] << "\n";
    cout << "i: " << vals[8] << "\n";
    cout << "j: " << vals[9] << "\n";
    cout << "k: " << vals[10] << "\n";
    cout << "l: " << vals[11] << "\n";
    cout << "m: " << vals[12] << "\n";
    cout << "n: " << vals[13] << "\n";
    cout << "o: " << vals[14] << "\n";
    cout << "p: " << vals[15] << "\n";
    cout << "q: " << vals[16] << "\n";
    cout << "r: " << vals[17] << "\n";
    cout << "s: " << vals[18] << "\n";
    cout << "t: " << vals[19] << "\n";
    cout << "u: " << vals[20] << "\n";
    cout << "v: " << vals[21] << "\n";
    cout << "w: " << vals[22] << "\n";
    cout << "x: " << vals[23] << "\n";
    cout << "y: " << vals[24] << "\n";
    cout << "z: " << vals[25] << "\n";
}
int analyzeCharacter(char aChar)
{
    if(aChar == 'a')
        return 0;
    else if(aChar == 'b')
        return 1;
    else if(aChar == 'c')
        return 2;
    else if(aChar == 'd')
        return 3;
    else if(aChar == 'e')
       return 4;
    else if(aChar == 'f')
        return 5;
    else if(aChar == 'g')
        return 6;
    else if(aChar == 'h')
        return 7;
    else if(aChar == 'i')
        return 8;
    else if(aChar == 'j')
        return 9;
    else if(aChar == 'k')
        return 10;
    else if(aChar == 'l')
        return 11;
    else if(aChar == 'm')
        return 12;
    else if(aChar == 'n')
        return 13;
    else if(aChar == 'o')
        return 14;
    else if(aChar == 'p')
        return 15;
    else if(aChar == 'q')
        return 16;
    else if(aChar == 'r')
        return 17;
    else if(aChar == 's')
        return 18;
    else if(aChar == 't')
        return 19;
    else if(aChar == 'u')
        return 20;
    else if(aChar == 'v')
        return 21;
    else if(aChar == 'w')
        return 22;
    else if(aChar == 'x')
        return 23;
    else if(aChar == 'y')
        return 24;
    else if(aChar == 'z')
        return 25;
    else
    {
        return -1;
    }
}
#endif
