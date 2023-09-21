#include "Paciente.h"


Paciente::Paciente()
{
}


Paciente::Paciente(string nome, unsigned idade, double altura , double peso)
{
	this->nome = nome;
	this->idade = idade;
	this->altura = altura;
	this->peso = peso;
}

void Paciente::setNome(string nome)
{
	this->nome = (nome.length() <= LENGHT_NAME) ? nome : nome.substr(0, LENGHT_NAME);
}

void Paciente::setIdade(unsigned idade)
{
	this->idade = idade;
}

void Paciente::setAltura(double altura)
{
	
	this->altura = (altura > 0) ? altura : -1;
}

void Paciente::setPeso(double peso)
{
	this->peso = (peso > 0) ? peso : -1;
}

string Paciente::getNome()
{

	return nome;
}

unsigned Paciente::getIdade()
{
	return idade;
}

double Paciente::getAltura()
{
	return altura;
}

double Paciente::getPeso()
{
	return peso;
}

string Paciente::exibirInformacoes()
{
	string saida = "\nNome -> " + getNome() + "\n" + "Idade -> " + to_string(getIdade()) + "\n" + "Altura - > " + to_string(getAltura()) + "\n\n";
	return saida;


}
