#include <iostream>

#include <locale>
#include "funcoes.cpp"


int main(void){
    setlocale(LC_ALL, "portuguese");

    do{
        menu();
    }while(opcaoEscolhida != 5);

    system("pause");
    
    return 0;
}

