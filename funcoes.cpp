#include <iostream>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;

struct paciente{
    std::string nome, interpretacaoIMC;
    float peso, altura, IMC;
    
};

struct paciente includePaciente;

void getDados(){
    std::cout << "Nome: ";
    cin.ignore();
    std::getline(std::cin, includePaciente.nome);
    cin.clear();
    std::cout << "Peso: ";
    std::cin >> includePaciente.peso;
    cin.clear();
    std::cout << "Altura: ";
    std::cin >> includePaciente.altura;
    cin.clear();
}

float calculaIMC(){
    includePaciente.IMC = includePaciente.peso/pow(includePaciente.altura/100, 2);
    if(includePaciente.IMC >= 18.5 && includePaciente.IMC < 25){
        includePaciente.interpretacaoIMC = "Normal";
    } 

    return includePaciente.IMC;
}


void incluirPaciente(const std::string& nome, float peso, float altura){


    std::ofstream myfile("registroPacientes.txt", std::ios::app);

    if(myfile.is_open()){
        myfile << "\nNome -> " << includePaciente.nome << "\n"; 
        myfile << "Peso -> " << includePaciente.peso << "\n";
        myfile << "Altura -> " << includePaciente.altura << "\n";
        myfile << "IMC -> " << includePaciente.IMC << " --- " << includePaciente.interpretacaoIMC << "\n";
        myfile << "____________________________________________________\n";
        myfile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
    }

}

void editarPaciente(){
    string substring, x;
    int line = 1;
    bool ans=false;


    cout << "Digite o nome: "<<endl;  
    cin >> substring;

    std::ifstream myfile("registroPacientes.txt", std::ios::app);

    if(myfile.is_open()){
        while ( getline (myfile, x) ){
            if (x.find(substring, 0) != string::npos) {
                cout<<"Paciente na linha -> "<<line<<endl;
                ans=true;     
            }
            line++;
        }
    } else {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
    }

    if(!ans)   // if subtring not present.
        cout<<"Paciente não encontrado(a)"<<endl;

    myfile.close();
}

int opcaoEscolhida;
void menu(){

    std::cout << "\nEscolha uma das opcoes";
    std::cout << "\n1.....Inserir Paciente";
    std::cout << "\n2.....Editar Paciente";
    std::cout << "\n3.....Excluir Paciente";
    std::cout << "\n4.....Buscar Paciente";
    std::cout << "\n5.....Sair do programa";
    std::cout << "\n------> ";

    
    std::cin >> opcaoEscolhida;

    switch (opcaoEscolhida){
        case 1:
            getDados();
            calculaIMC();
            incluirPaciente(includePaciente.nome, includePaciente.peso, includePaciente.altura);

            break;
        case 2:
            editarPaciente();
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            cout << "Saindo...\n";
            break;       
        default:
            cout <<"Opção inválida";
            break;
    }
}



