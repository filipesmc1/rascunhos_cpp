#include<iostream>

/*
    Da pra fazer também com enum class e unordered_map pra ficar elegante!
*/

enum class Error{
   
    NoCameraConnected = 500,
    NoNetworkConnection = 800
    
};


int main(){

    std::cout << static_cast<int>(Error::NoCameraConnected) << std::endl;

    return 0;
}
