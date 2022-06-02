#include<stddef.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<iostream>

int main(){

    pid_t child_p;
    int status;

    std::cout << "Processo pai, PID: " << getpid() << std::endl;
    std::cout << "Meu parent PID: " << getppid() << std::endl;
    std::cout << "Criando novo processo..." << std::endl;
    
    child_p = fork();
    if (child_p == -1){

        /* caso fork() retorne -1 */ 
        std::cout << "Erro: fork() " << std::endl;
        return (-1);

    }else if (child_p == 0){
    
        std::cout << "Processo filho, PID:  " << std::endl;
        std::cout << "PID do processo pai: " << getppid() << std::endl;
    
    }else{

        wait(&status); /* espera o processo filho terminar */
        std::cout << "Processo pai, meu PID é: " << getpid() << std::endl;
    }
            

    return (0);


}