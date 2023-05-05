#include <iostream>

using namespace std;

int main()
{

#ifdef DEBUG
    printf("Nihao");
#endif
    cout
        << "Hello World!"
        << "\n";

    return 0;
}
