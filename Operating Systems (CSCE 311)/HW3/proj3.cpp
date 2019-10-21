#include "hfunc.h"
#include <fstream>
#include <time.h>
using namespace std;

int main(int argc, char **argv)
{
    clock_t time, timeP;
    time = clock();
    timeP = clock();
    string filename = "temp.txt";
    if(argc > 1)
    {
        filename = argv[1];
    }
  	int SIZE = 26;
  	int values[SIZE];
  	for(int i = 0; i < SIZE; i++)
  	{
  		values[i] = 0;
  	}
  	ifstream file(filename.c_str());
  	string st;
  	while(getline(file,st))
  	{
    		for(int i = 0; i < st.size(); i++)
    		{
            int temp = analyzeCharacter(st[i]);
            if(temp != -1)
            {
                values[temp] += 1;
            }
    		}
  	}
	timeP = clock() - timeP;
    printResults(values);
	time = clock() - time;
	cout << "The time t w/o printing finish was: " << (float)timeP/CLOCKS_PER_SEC << 
	" and with printing: " << (float)time/CLOCKS_PER_SEC << 
	" and the difference was : " << (float)(time - timeP)/CLOCKS_PER_SEC << endl;
  	return 0;
}
