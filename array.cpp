#include<iostream>
#include<array>

int main(){

    std::array<int, 3> arr {1,2,3};

    std::cout << "Array and it size " << arr.size() << std::endl;

    for(auto a: arr){
        std::cout << a << "\t";
    }

    std::cout << "\n";

    /* structured binding */
    auto [x, y, z] = arr;
    std::cout << x << "\t" << y << "\t" << z << std::endl;

    while(!arr.empty()){
        std::cout << arr.back() << "\t";
    }

    return 0;
}
