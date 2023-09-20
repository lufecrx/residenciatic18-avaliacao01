#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Passageiro {
    string cpf;
    string nome;
    string dataNasc;
    int numeroAutorizacao;
};

struct Roteiro {
    int codigo;
    string origem;
    string destino;
    string data_hora_prev;
    string duracao_prev;
};

int menuPassageiros() {
    int opcao;
    cout << "\nMenu de Passageiros:" << endl;
    cout << "1. Incluir" << endl;
    cout << "2. Excluir" << endl;
    cout << "3. Alterar por CPF" << endl;
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
    cin.ignore();
    getline(cin, novoPassageiro.nome);
    cout << "Data de Nascimento: ";
    getline(cin, novoPassageiro.dataNasc);
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
            cout << "Deseja alterar o Nome? (S/N): ";
            char resposta;
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, passageiro.nome);
            }

            cout << "Deseja alterar a Data de Nascimento? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Nova Data de Nascimento: ";
                cin.ignore();
                getline(cin, passageiro.dataNasc);
            }

            cout << "Deseja alterar o Número de Autorização? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Novo Número de Autorização: ";
                cin >> passageiro.numeroAutorizacao;
            }

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
        cout << "Data de Nascimento: " << passageiro.dataNasc << endl;
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
            cout << "Data de Nascimento: " << passageiro.dataNasc << endl;
            cout << "Número de autorização: " << passageiro.numeroAutorizacao << endl;
            return;
        }
    }
    
    cout << "Passageiro não encontrado." << endl;
}

int menuRoteiros() {
    int opcao;
    cout << "\nMenu de Roteiros:" << endl;
    cout << "1. Incluir" << endl;
    cout << "2. Excluir" << endl;
    cout << "3. Alterar por código" << endl;
    cout << "4. Listar" << endl;
    cout << "5. Localizar por código" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    return opcao;
}

void incluirRoteiro(vector<Roteiro>& roteiros) {
    Roteiro novoRoteiro;
    cout << "Código: ";
    cin >> novoRoteiro.codigo;
    cout << "Origem: ";
    cin.ignore();
    getline(cin, novoRoteiro.origem);
    cout << "Destino: ";
    getline(cin, novoRoteiro.destino);
    cout << "Data e Hora previstas: ";
    getline(cin, novoRoteiro.data_hora_prev);
    cout << "Duração prevista: ";
    getline(cin, novoRoteiro.duracao_prev);
    roteiros.push_back(novoRoteiro);
    cout << "Roteiro incluído com sucesso!" << endl;
}

void excluirRoteiro(vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Digite o Código do roteiro a ser excluído: ";
    cin >> codigo;
    
    for (auto i = roteiros.begin(); i != roteiros.end(); i++) {
        if (i->codigo == codigo) {
            roteiros.erase(i);
            cout << "Roteiro excluído com sucesso!" << endl;
            return;
        }
    }
    
    cout << "Roteiro não encontrado." << endl;
}

void alterarRoteiro(vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Digite o código do roteiro a ser alterado: ";
    cin >> codigo;
    
    for (auto& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Deseja alterar a origem? (S/N): ";
            char resposta;
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Nova origem: ";
                cin.ignore();
                getline(cin, roteiro.origem);
            }

            cout << "Deseja alterar o destino? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Novo destino: ";
                cin.ignore();
                getline(cin, roteiro.destino);
            }

            cout << "Deseja alterar a data e hora previstas? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Nova data e hora previstas: ";
                cin.ignore();
                getline(cin, roteiro.data_hora_prev);
            }

            cout << "Deseja alterar a duração prevista? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Nova duração prevista: ";
                cin.ignore();
                getline(cin, roteiro.duracao_prev);
            }

            cout << "Dados do roteiro alterados com sucesso!" << endl;
            return;
        }
    }
    
    cout << "Roteiro não encontrado." << endl;
}

void listarRoteiros(const vector<Roteiro>& roteiros) {
    cout << "\nLista de Roteiros:" << endl;
    for (const auto& roteiro : roteiros) {
        cout << "Código: " << roteiro.codigo << endl;
        cout << "Origem: " << roteiro.origem << endl;
        cout << "Destino: " << roteiro.destino << endl;
        cout << "Data e hora previstas: " << roteiro.data_hora_prev << endl;
        cout << "Duração prevista: " << roteiro.duracao_prev << endl;
        cout << "--------------------------" << endl;
    }
}

void localizarRoteiro(const vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Digite o Código do roteiro a ser localizado: ";
    cin >> codigo;
    
    for (const auto& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Código: " << roteiro.codigo << endl;
            cout << "Origem: " << roteiro.origem << endl;
            cout << "Destino: " << roteiro.destino << endl;
            cout << "Data e Hora previstas: " << roteiro.data_hora_prev << endl;
            cout << "Duração prevista: " << roteiro.duracao_prev << endl;
            return;
        }
    }
    cout << "Roteiro não encontrado." << endl;
}

int main() {
    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros;

    int modulo = 0;
    int opcao;

    while (modulo >= 0) {
        if (modulo == 0) {
            cout << "\nMenu Principal:" << endl;
            cout << "1. Gerenciar Passageiros" << endl;
            cout << "2. Gerenciar Roteiros" << endl;
            cout << "0. Sair" << endl;
            cout << "Escolha uma opção: ";
            cin >> opcao;
            switch (opcao) {
                case 1:
                    modulo = 1;
                    break;
                case 2:
                    modulo = 2;
                    break;
                case 0:
                    modulo = -1;
                    break;
                default:
                    cout << "Opção inválida!" << endl;
            }
        } else if (modulo == 1) {
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
                    modulo = 0;
                    break;
                default:
                    cout << "Opção inválida!" << endl;
            }
        } else if (modulo == 2) {
            opcao = menuRoteiros();
            switch (opcao) {
                case 1:
                    incluirRoteiro(roteiros);
                    break;
                case 2:
                    excluirRoteiro(roteiros);
                    break;
                case 3:
                    alterarRoteiro(roteiros);
                    break;
                case 4:
                    listarRoteiros(roteiros);
                    break;
                case 5:
                    localizarRoteiro(roteiros);
                    break;
                case 0:
                    modulo = 0;
                    break;
                default:
                    cout << "Opção inválida!" << endl;
            }
        }
    }

    cout << "Programa encerrado." << endl;
    return 0;
}
