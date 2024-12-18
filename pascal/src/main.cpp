#include "../inc/pascal.h"
#include <bits/basic_string.h>
#include <iostream>


int main(int argc, char* argv[])
{
    int n = MAX_SIZE;

    if (argc > 1){
        n = std::stoi(argv[1]);
        if (n > MAX_SIZE){
            std::cerr << "Invalid number given." << std::endl;
        }
    }

    auto triangle = createTriangle(n);
    printTriangle(triangle);

    return 0;
}

