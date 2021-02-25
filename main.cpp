#include "classes.h"
int main(int argc, char* argv[]) {

    cout << "The number of arguments is: " << argc << endl;
    if (argc == 1)
    {
        Start s1;
    }
    else
        for (int i = 1; i < argc; i++) {
            string name = argv[i];
            Start s(name);
        }


    return 0;
}
