#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Passageiro {
    string cpf;
    string nome;
    string dataNascimento;
    int numeroAutorizacao;
};

int menuPassageiros() {
    int opcao;
    cout << "\nMenu de Passageiros:" << endl;
    cout << "1. Incluir" << endl;
    cout << "2. Excluir" << endl;
    cout << "3. Alterar" << endl;
    cout << "4. Listar" << endl;
    cout << "5. Localizar por CPF" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    return opcao;
}

void incluirPassageiro(vector<Passageiro>& passageiros) {
    Passageiro novoPassageiro;
    cout << "CPF: ";
    cin >> novoPassageiro.cpf;
    cout << "Nome: ";
    cin >> novoPassageiro.nome;
    cout << "Data de Nascimento: ";
    cin >> novoPassageiro.dataNascimento;
    cout << "Número de autorização: ";
    cin >> novoPassageiro.numeroAutorizacao;
    passageiros.push_back(novoPassageiro);
    cout << "Passageiro incluído com sucesso!" << endl;
}

void excluirPassageiro(vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Digite o CPF do passageiro a ser excluído: ";
    cin >> cpf;
    
    for (auto i = passageiros.begin(); i != passageiros.end(); i++) {
        if (i->cpf == cpf) {
            passageiros.erase(i);
            cout << "Passageiro excluído com sucesso!" << endl;
            return;
        }
    }
    
    cout << "Passageiro não encontrado." << endl;
}

void alterarPassageiro(vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Digite o CPF do passageiro a ser alterado: ";
    cin >> cpf;
    
    for (auto& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            cout << "Novos dados do passageiro:" << endl;
            cout << "Nome: ";
            cin >> passageiro.nome;
            cout << "Data de Nascimento: ";
            cin >> passageiro.dataNascimento;
            cout << "Número de autorização: ";
            cin >> passageiro.numeroAutorizacao;
            cout << "Dados do passageiro alterados com sucesso!" << endl;
            return;
        }
    }
    
    cout << "Passageiro não encontrado." << endl;
}

void listarPassageiros(const vector<Passageiro>& passageiros) {
    cout << "\nLista de Passageiros:" << endl;
    for (const auto& passageiro : passageiros) {
        cout << "CPF: " << passageiro.cpf << endl;
        cout << "Nome: " << passageiro.nome << endl;
        cout << "Data de Nascimento: " << passageiro.dataNascimento << endl;
        cout << "Número de autorização: " << passageiro.numeroAutorizacao << endl;
        cout << "--------------------------" << endl;
    }
}

void localizarPassageiro(const vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Digite o CPF do passageiro a ser localizado: ";
    cin >> cpf;
    
    for (const auto& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            cout << "CPF: " << passageiro.cpf << endl;
            cout << "Nome: " << passageiro.nome << endl;
            cout << "Data de Nascimento: " << passageiro.dataNascimento << endl;
            cout << "Número de autorização: " << passageiro.numeroAutorizacao << endl;
            return;
        }
    }
    
    cout << "Passageiro não encontrado." << endl;
}

int main(void) {
    vector<Passageiro> passageiros;
    //vector<Roteiro> roteiros;

    int opcao;

    while (opcao >= 0) {
            opcao = menuPassageiros();
            switch (opcao) {
                case 1:
                    incluirPassageiro(passageiros);
                    break;
                case 2:
                    excluirPassageiro(passageiros);
                    break;
                case 3:
                    alterarPassageiro(passageiros);
                    break;
                case 4:
                    listarPassageiros(passageiros);
                    break;
                case 5:
                    localizarPassageiro(passageiros);
                    break;
                case 0:
                    cout << "Programa encerrado." << endl;
                    return 0;
                default:
                    cout << "Opção inválida!" << endl;
            }
    }
    
}