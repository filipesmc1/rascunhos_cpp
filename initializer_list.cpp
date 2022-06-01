#include<iostream>
#include<array>
#include<initializer_list>

int soma(std::initializer_list<int> lst){
   
    int total {0};
    
    for(auto i: lst){
        total += i;
    }

    return total;
}

int main(){

    
    std::cout << soma({10, 45,67,87,988,67,43,23,54,12,3,43}) << std::endl;


    

    return 0;
}