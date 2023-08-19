#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <clocale>

using namespace std;
vector <int> repeatedLinesFound;

struct paciente{
    string nome, interpretacaoIMC;
    float peso, altura, IMC;
    char sexo;
};

struct paciente newPatient;

void getDados(){
    cout << "Nome: ";
    cin.ignore();
    getline(cin, newPatient.nome);
    cin.clear();
    cout << "Peso: ";
    cin >> newPatient.peso;
    cin.clear();
    cout << "Altura(cm): ";
    cin >> newPatient.altura;
    cin.clear();
    cout << "sexo\n (M -> Masculino\n F -> Feminino\n->)";
    cin >> newPatient.sexo;
}

int calculaIMC(){
    newPatient.IMC = newPatient.peso/pow(newPatient.altura/100, 2);
    if (newPatient.IMC < 18.5 ){
        newPatient.interpretacaoIMC = "Magreza";
    } else if(newPatient.IMC >= 18.5 && newPatient.IMC < 25){
        newPatient.interpretacaoIMC = "Normal";
    } else if (newPatient.IMC >= 25 && newPatient.IMC < 30){
        newPatient.interpretacaoIMC = "Sobrepeso";
    } else if (newPatient.IMC >= 30 && newPatient.IMC <= 40){
        newPatient.interpretacaoIMC = "Obesidade";
    } else {
        newPatient.interpretacaoIMC = "Obesidade Grave";
    }
    
    return EXIT_SUCCESS;
}

int incluirPaciente(const string& nome, float peso, float altura){

    ofstream myfile("registroPacientes.txt", ios::app);

    if(myfile.is_open()){
        myfile << "\nNome   -> " << newPatient.nome << endl; 
        if(newPatient.sexo == 'M' || newPatient.sexo == 'm'){
            myfile << "Sexo   -> " << "Masculino" << endl; 
        } else {
            myfile << "Sexo   -> " << "Feminino" << endl; 
        }
        myfile << "Peso   -> " << newPatient.peso << endl;
        myfile << "Altura -> " << newPatient.altura << endl;
        myfile << "IMC    -> " << newPatient.IMC << " --- Condição: " << newPatient.interpretacaoIMC << endl;
        
        myfile << "____________________________________________________" << endl;
        myfile.close();
    } else {
        cerr << "Não foi possível abrir o arquivo." << endl;
    }

    return EXIT_SUCCESS;
}

int exibirPacientes(){

    ifstream myfile("registroPacientes.txt", ios::app);

    if(myfile.is_open()){

        string linha;

        while (getline(myfile, linha)) {
            cout << linha << std::endl;
        }
        myfile.close();

    } else {
        cerr << "Não foi possível abrir o arquivo." << endl;
    }

    return EXIT_SUCCESS;

}

int buscarPaciente(){
    string substring, atualLine;
    int line = 1;
    bool findedLine = false;

    cout << "Digite o nome: "<<endl;
    cin.ignore();
    getline(cin, substring);

    ifstream myfile("registroPacientes.txt", ios::app);
    
    if(myfile.is_open()){
        while (getline (myfile, atualLine)){
            if (atualLine.find(substring, 0) != string::npos) {
                repeatedLinesFound.push_back(line);
                findedLine = true;  
            }
            line++;
        }
    } else {
        cerr << "Não foi possível abrir o arquivo." << endl;
    } 

    if(!findedLine) {
        cout << "Paciente não encontrado(a)" << endl;
    }  

    myfile.close();

    cout << "Linhas quem contem a busca: " << endl;
    for (int index = 0; index < repeatedLinesFound.size(); index++ ){
        cout << repeatedLinesFound[index] << endl;
    }

    repeatedLinesFound.erase(repeatedLinesFound.begin(), repeatedLinesFound.end());

    return EXIT_SUCCESS;
}

int excluirPaciente(){

    buscarPaciente();
    string line;
    ofstream myfile("registroPacientes.txt", ios::app);

    if(myfile.is_open()){
        

        myfile.close();
    } else {
        cerr << "Não foi possível abrir o arquivo." << endl;
    }

    return EXIT_SUCCESS;
}

void menu(){

    int opcaoEscolhida;

    do{
        cout << "\nEscolha uma das opções" << endl;
        cout << "1.....Inserir Paciente" << endl;
        cout << "2.....Editar Paciente" << endl;
        cout << "3.....Excluir Paciente" << endl;
        cout << "4.....Buscar Paciente" << endl;
        cout << "5.....Exibir Pacientes" << endl;
        cout << "0.....Sair do programa\n" << endl;
        cout << "------> " ;

        cin >> opcaoEscolhida;

        switch (opcaoEscolhida){
            case 1:
                getDados();
                calculaIMC();
                incluirPaciente(newPatient.nome, newPatient.peso, newPatient.altura);
                break;
            case 2:
                buscarPaciente();
                break;
            case 3:
                excluirPaciente();
                break;
            case 4:
                buscarPaciente();
                break;
            case 5:
                exibirPacientes();
                break;       
            case 0:
                cout << "Saindo...\n";
                break;       
            default:
                cout <<"Opcao invalida";
                menu();
                break;
        }
    }while(opcaoEscolhida != 0);
}
