#include <iostream>
#include <string>
#include <vector>

// Gestão de passageiros de uma empresa de transporte.

using namespace std;

struct PASSAGEIRO
{
    string cpf;
    string nome;
    string nascimento;
    int numAutorizacao;
};

string dataFormat(int dia, int mes, int ano)
{
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
}

bool incluirPassageiro(vector<PASSAGEIRO> &passageiros)
{
    PASSAGEIRO passageiro;
    int dia, mes, ano;

    cout << "Nome do passageiro: ";
    cin >> passageiro.nome;

    cout << "CPF do passageiro: ";
    cin >> passageiro.cpf;

    cout << "Dia de nascimento: ";
    cin >> dia;
    if (dia < 1 || dia > 31)
    {
        cout << "Dia inválido. O dia deve estar entre 1 e 31." << endl;
        return false;
    }

    cout << "Mes de nascimento: ";
    cin >> mes;
    if (mes < 1 || mes > 12)
    {
        cout << "Mês inválido. O mês deve estar entre 1 e 12." << endl;
        return false;
    }

    cout << "Ano de nascimento: ";
    cin >> ano;
    if (ano < 1900 || ano > 2023) // Ano atual: 2023
    {
        cout << "Ano inválido. O ano deve estar entre 1900 e 2023." << endl;
        return false;
    }

    passageiro.nascimento = dataFormat(dia, mes, ano);

    passageiros.push_back(passageiro);
    return true; // O passageiro foi adicionado sem problemas
}

// bool excluirPassageiro()
// {

// }

int main()
{
}