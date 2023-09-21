#pragma once
#include <string>
#include <cstdlib>
#include <clocale>
#include <iostream>

using namespace std;

class Paciente
{
private:
	const unsigned LENGHT_NAME = 50;
	string nome;
	int idade = 0;
	double altura = 0;
	double peso = 0;
	double imc = 0;

	
public:
	Paciente();
	Paciente(string nome, unsigned idade, double altura,double peso); // construtor sobrecarregado

	void setNome(string nome);
	void setIdade(unsigned idade);
	void setAltura(double altura);
	void setPeso(double peso);
	string getNome();
	unsigned getIdade();
	double getAltura();
	double getPeso();
	string exibirInformacoes();
};

