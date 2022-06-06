#include<iostream>
#include<algorithm>
#include<vector>


int main(){

    std::string prefixo {"+"};

    std::vector<int> v_int {1,45,65,24,98,67};

    std::for_each(std::begin(v_int), std::end(v_int), [](int a) { std::cout << a << std::endl; });

    std::for_each(std::begin(v_int), std::end(v_int), [&prefixo](int a) { std::cout << prefixo << a << std::endl; });
}


/*
   clausule cap: [] 
   parameter list: ()
   mutable specification: mutable
   exception specification: noexcept
   trailing return typ: -> type
   body: {}

   mutable permite que um parametro passado por valor seja alterado no corpo da lamvda,
   ou seja, as variaveis passadas na lista de parametros são const-by-value e o mutable
   remove essa restrição.

*/