#include<iostream>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>



int main(){

    pid_t child_p;
    int status;

    std::cout << "Processo pai, PID: " << getpid() << std::endl;
    std::cout << "Meu parent PID: " << getppid() << std::endl;
    std::cout << "Criando novo processo..." << std::endl;
    
    child_p = fork();
    if (child_p == -1){

        /* caso fork() retorne -1 */ 
        std::cout << "Erro no fork() " << std::endl;
        return (-1);

    }else if (child_p == 0){

        std::cout << "listando arquivos do diretório..." << std::endl;
        
        if (execl("/usr/bin/ls", "ls", "-l", NULL) < 0){
            
            std::cout << "execl failed!" << std::endl;
            return 2;
        }

        std::cout << "Processo filho, PID:  " << std::endl;
        std::cout << "PID do processo pai: " << getppid() << std::endl;
    
    }else{

        wait(&status); /* espera o processo filho terminar */
        std::cout << "Processo pai, meu PID é: " << getpid() << std::endl;
    }
            

    return (0);


}