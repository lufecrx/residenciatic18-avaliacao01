#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estrutura de dados para representar uma data
struct Data {
    int dia;
    int mes;
    int ano;
};

// Estrutura de dados para passageiro
struct Passageiro {
    string cpf;
    string nome;
    Data dataNascimento;
    string numAutorizacao;
};

// Estrutura de dados para roteiro
struct Roteiro {
    int id;
    Data dataHoraPrevista;
    string duracaoPrevista;
    string origem;
    string destino;
};

// Função para incluir um passageiro na coleção
void IncluirPassageiro(vector<Passageiro>& passageiros) {
    Passageiro novoPassageiro;
    cout << "Informe o CPF do passageiro: ";
    cin >> novoPassageiro.cpf;
    cout << "Informe o nome do passageiro: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, novoPassageiro.nome);
    cout << "Informe a data de nascimento do passageiro (DD MM AAAA): ";
    cin >> novoPassageiro.dataNascimento.dia >> novoPassageiro.dataNascimento.mes >> novoPassageiro.dataNascimento.ano;
    cout << "Informe o número de autorização do responsável (se necessário): ";
    cin >> novoPassageiro.numAutorizacao;

    passageiros.push_back(novoPassageiro);
    cout << "Passageiro adicionado com sucesso!" << endl;
}

// Função para excluir um passageiro da coleção por CPF
void ExcluirPassageiro(vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Informe o CPF do passageiro a ser excluído: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->cpf == cpf) {
            passageiros.erase(it);
            cout << "Passageiro removido com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro com CPF " << cpf << " não encontrado." << endl;
}

// Função para listar todos os passageiros
void ListarPassageiros(const vector<Passageiro>& passageiros) {
    cout << "Lista de Passageiros:" << endl;
    for (const Passageiro& passageiro : passageiros) {
        cout << "CPF: " << passageiro.cpf << " | Nome: " << passageiro.nome << " | Data de Nascimento: "
             << passageiro.dataNascimento.dia << "/" << passageiro.dataNascimento.mes << "/" << passageiro.dataNascimento.ano
             << " | Número de Autorização: " << passageiro.numAutorizacao << endl;
    }
}

int main() {
    vector<Passageiro> passageiros;
    int escolha;

    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Incluir Passageiro" << endl;
        cout << "2. Excluir Passageiro" << endl;
        cout << "3. Listar Passageiros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                IncluirPassageiro(passageiros);
                break;
            case 2:
                ExcluirPassageiro(passageiros);
                break;
            case 3:
                ListarPassageiros(passageiros);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (escolha != 0);

    return 0;
}
