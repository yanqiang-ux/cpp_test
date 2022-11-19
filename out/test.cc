#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename("./tmp.txt");
    fstream file;

    file.open(filename, std::ios_base::app | std::ios_base::in);
    if (file.is_open())
        file << "Some random text to append." << endl;
    cout << "Done !" << endl;

    return 0;
}
