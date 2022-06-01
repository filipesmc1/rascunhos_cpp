#include<iostream>

int main(int argv, char** argc){

    float pi = 3.14f;
    int pi_cast = static_cast<int>(pi);
    int pi_cast_float{0};

    pi_cast_float = pi;

    std::cout << pi << std::endl;
    std::cout << pi_cast << std::endl;
    std::cout << pi_cast_float << std::endl;

    bool b = !true;
    bool c = !b;

    std::cout << b << " " << c << std::endl;

    int i = 34 + (8 * 2) + ( (21 / 7) % 2 );
    std::cout << i << std::endl;

    return 0;
}
