#include<iostream>
#include<limits>


int main(){

    /* kernel usa lp64 data model p/ x64 */
    std::cout << "char " << int(std::numeric_limits<char>::min()) << " - " << int(std::numeric_limits<char>::max()) << " size (bytes) = " << sizeof(char) << std::endl;

    std::cout << "int " << std::numeric_limits<int>::min() << " - " << std::numeric_limits<int>::max() << " size (bytes) = " << sizeof(int) << std::endl;

    std::cout << "bool " << std::numeric_limits<bool>::min() << " - " << std::numeric_limits<bool>::max() << " size (bytes) = " << sizeof(bool) << std::endl;

    std::cout << "float " << std::numeric_limits<float>::min() << " - " << std::numeric_limits<float>::max() << " size (bytes) = " << sizeof(float) << std::endl;

    std::cout << "double " << std::numeric_limits<double>::min() << " - " << std::numeric_limits<double>::max() << " size (bytes) = " << sizeof(double) << std::endl;
}