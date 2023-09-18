#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

// Compara dois passageiros pelo CPF
bool compararPorCPF(const PASSAGEIRO &a, const PASSAGEIRO &b)
{
    return a.cpf < b.cpf;
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

    // Encontrando a posição correta para inserir o passageiro com base no CPF
    auto it = lower_bound(passageiros.begin(), passageiros.end(), passageiro, compararPorCPF);

    // Inserindo o passageiro na posição encontrada
    passageiros.insert(it, passageiro);

    return true; // O passageiro foi adicionado sem problemas
}

int encontrarPassageiro(vector<PASSAGEIRO> passageiros)
{
    string referencia;

    cout << "CPF do passageiro procurado: ";
    cin >> referencia;

    for (int i = 0; i < passageiros.size(); i++)
    {
        if (passageiros[i].cpf == referencia)
        {
            // Encontrou o passageiro com o CPF especificado
            passageiros.erase(passageiros.begin() + i);
            cout << "Passageiro com CPF " << referencia << " encontrado." << endl;
            return i; // Retorna o índice dele na lista
        }
        else if (passageiros[i].cpf > referencia)
        {
            // Chegou a um passageiro com CPF maior, o passageiro não está na lista
            cout << "Passageiro com CPF " << referencia << " não encontrado." << endl;
            return -1; // Passageiro não encontrado
        }
    }

    // Se o loop terminar sem encontrar o passageiro, significa que ele não está na lista
    cout << "Passageiro com CPF " << referencia << " não encontrado." << endl;
    return -1; // Passageiro não encontrado
}

bool localizarPassageiro(vector<PASSAGEIRO> passageiros)
{
    int pos = encontrarPassageiro(passageiros);

    if (pos == -1) // CPF informado não está na lista
    {
        return false;
    }
    else
    {
        cout << passageiros[pos].nome << endl;
        cout << passageiros[pos].cpf << endl;
        cout << passageiros[pos].nascimento << endl;
        cout << passageiros[pos].numAutorizacao << endl;
        
        return true; // Passageiro encontrado e informações impressas na tela
    }
}

bool alterarDado(vector<PASSAGEIRO> &passageiros)
{
    
}

int main()
{
}