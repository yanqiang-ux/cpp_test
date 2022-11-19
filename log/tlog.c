#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char fileName[] = "data.txt";
	/* ifstream infile(fileName); */
	
	/* if(infile) */
	/*         cout << infile.rdbuf(); */
		
	/* else */
		clog << "Error while opening the file " << fileName << endl; 
      return 0;
}
