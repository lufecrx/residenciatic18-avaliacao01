#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estrutura de dados para representar uma data
struct Data
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
};

// Estrutura de dados para passageiro
struct Passageiro
{
    string cpf;
    string nome;
    Data dataNascimento;
    string numAutorizacao;
};

// Estrutura de dados para roteiro
struct Roteiro
{
    int id;
    Data dataHoraPrevista;
    string duracaoPrevista;
    string origem;
    string destino;
};

// Função para incluir um passageiro no vector
void IncluirPassageiro(vector<Passageiro> &passageiros)
{
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

// Função para excluir um passageiro do vetor por CPF
void ExcluirPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    cout << "Informe o CPF do passageiro a ser excluído: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if (it->cpf == cpf)
        {
            passageiros.erase(it);
            cout << "Passageiro removido com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro com CPF " << cpf << " não encontrado." << endl;
}

void AlterarPassageiro(vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Informe o CPF do passageiro a ser alterado: ";
    cin >> cpf;

    for (auto& passageiro : passageiros) {
        if (passageiro.cpf == cpf) { //CPF DO PASSAGEIRO
            cout << "Passageiro encontrado. Deseja alterar os dados? (S/N): ";
            char resposta;
            cin >> resposta;

            if (toupper(resposta) == 'S') { //TOUPPER CONVERTE O CARACTER PARA MAIÚSCULO
                cout << "Novo nome (atual: " << passageiro.nome << "): ";
                cin.ignore(); // Limpar o buffer do teclado
                getline(cin, passageiro.nome);
                cout << "Nova data de nascimento (atual: " << passageiro.dataNascimento.dia << "/"
                     << passageiro.dataNascimento.mes << "/" << passageiro.dataNascimento.ano << "): ";
                cin >> passageiro.dataNascimento.dia >> passageiro.dataNascimento.mes >> passageiro.dataNascimento.ano;
                cout << "Novo número de autorização (atual: " << passageiro.numAutorizacao << "): ";
                cin >> passageiro.numAutorizacao;
                cout << "Passageiro alterado com sucesso!" << endl;
                return;
            } else {
                cout << "Alteração cancelada." << endl;
                return;
            }
        }
    }

    cout << "Passageiro com CPF " << cpf << " não encontrado." << endl;
}

// Função para listar todos os passageiros
void ListarPassageiros(const vector<Passageiro> &passageiros)
{
    cout << "Lista de Passageiros:" << endl;
    for (const Passageiro &passageiro : passageiros)
    {
        cout << "CPF: " << passageiro.cpf << " | Nome: " << passageiro.nome << " | Data de Nascimento: "
             << passageiro.dataNascimento.dia << "/" << passageiro.dataNascimento.mes << "/" << passageiro.dataNascimento.ano
             << " | Número de Autorização: " << passageiro.numAutorizacao << endl;
    }
}

// Funções para gerenciar roteiros

void IncluirRoteiro(vector<Roteiro> &roteiros)
{
    Roteiro novoRoteiro;
    cout << "Informe o código do roteiro: ";
    cin >> novoRoteiro.id;
    cout << "Informe a data e hora prevista do roteiro (DD MM AAAA HH:MM): ";
    cin >> novoRoteiro.dataHoraPrevista.dia >> novoRoteiro.dataHoraPrevista.mes >> novoRoteiro.dataHoraPrevista.ano;
    cin >> novoRoteiro.dataHoraPrevista.hora >> novoRoteiro.dataHoraPrevista.minutos;
    cout << "Informe a duração prevista do roteiro: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, novoRoteiro.duracaoPrevista);
    cout << "Informe a origem do roteiro: ";
    getline(cin, novoRoteiro.origem);
    cout << "Informe o destino do roteiro: ";
    getline(cin, novoRoteiro.destino);

    roteiros.push_back(novoRoteiro);
    cout << "Roteiro adicionado com sucesso!" << endl;
}

// Função para excluir um roteiro da coleção por código
void ExcluirRoteiro(vector<Roteiro> &roteiros)
{
    int codigo;
    cout << "Informe o código do roteiro a ser excluído: ";
    cin >> codigo;

    for (auto it = roteiros.begin(); it != roteiros.end(); ++it)
    {
        if (it->id == codigo)
        {
            roteiros.erase(it);
            cout << "Roteiro removido com sucesso!" << endl;
            return;
        }
    }

    cout << "Roteiro com código " << codigo << " não encontrado." << endl;
}

// Função para listar todos os roteiros
void ListarRoteiros(const vector<Roteiro> &roteiros)
{
    cout << "Lista de Roteiros:" << endl;
    for (const Roteiro &roteiro : roteiros)
    {
        cout << "Código: " << roteiro.id << " | Data e Hora Prevista: "
             << roteiro.dataHoraPrevista.dia << "/" << roteiro.dataHoraPrevista.mes << "/" << roteiro.dataHoraPrevista.ano
             << " " << roteiro.dataHoraPrevista.hora << ":" << roteiro.dataHoraPrevista.minutos
             << " | Duração Prevista: " << roteiro.duracaoPrevista
             << " | Origem: " << roteiro.origem
             << " | Destino: " << roteiro.destino << endl;
    }
}

void AlterarRoteiro(vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Informe o código do roteiro a ser alterado: ";
    cin >> codigo;

    for (auto& roteiro : roteiros) {
        if (roteiro.id == codigo) { //CODIGO DO ROTEIRO
            cout << "Roteiro encontrado. Deseja alterar os dados? (S/N): ";
            char resposta;
            cin >> resposta;

            if (toupper(resposta) == 'S') { //TOUPPER CONVERTE O CARACTER PARA MAIÚSCULO
                cout << "Nova data e hora prevista (atual: " << roteiro.dataHoraPrevista.dia << "/"
                     << roteiro.dataHoraPrevista.mes << "/" << roteiro.dataHoraPrevista.ano << " "
                     << roteiro.dataHoraPrevista.hora << ":" << roteiro.dataHoraPrevista.minutos << "): ";
                cin >> roteiro.dataHoraPrevista.dia >> roteiro.dataHoraPrevista.mes >> roteiro.dataHoraPrevista.ano;
                cin >> roteiro.dataHoraPrevista.hora >> roteiro.dataHoraPrevista.minutos;
                cout << "Nova duração prevista (atual: " << roteiro.duracaoPrevista << "): ";
                cin.ignore(); // Limpar o buffer do teclado
                getline(cin, roteiro.duracaoPrevista);
                cout << "Nova origem (atual: " << roteiro.origem << "): ";
                getline(cin, roteiro.origem);
                cout << "Novo destino (atual: " << roteiro.destino << "): ";
                getline(cin, roteiro.destino);
                cout << "Roteiro alterado com sucesso!" << endl;
                return;
            } else {
                cout << "Alteração cancelada." << endl;
                return;
            }
        }
    }

    cout << "Roteiro com código " << codigo << " não encontrado." << endl;
}

// Função para localizar um roteiro por código
void LocalizarRoteiro(const vector<Roteiro> &roteiros)
{
    int codigo;
    cout << "Informe o código do roteiro a ser localizado: ";
    cin >> codigo;

    for (const Roteiro &roteiro : roteiros)
    {
        if (roteiro.id == codigo)
        {
            cout << "Roteiro encontrado:" << endl;
            cout << "Código: " << roteiro.id << " | Data e Hora Prevista: "
                 << roteiro.dataHoraPrevista.dia << "/" << roteiro.dataHoraPrevista.mes << "/" << roteiro.dataHoraPrevista.ano
                 << " " << roteiro.dataHoraPrevista.hora << ":" << roteiro.dataHoraPrevista.minutos
                 << " | Duração Prevista: " << roteiro.duracaoPrevista
                 << " | Origem: " << roteiro.origem
                 << " | Destino: " << roteiro.destino << endl;
            return;
        }
    }

    cout << "Roteiro com código " << codigo << " não encontrado." << endl;
}

int main()
{
    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros;
    int escolha;

    do
    {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Gerenciar Passageiros" << endl;
        cout << "2. Gerenciar Roteiros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha um módulo: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            // Módulo de gerenciamento de passageiros
            int escolhaPassageiros;
            do
            {
                cout << "\nMenu de Opções (Passageiros):" << endl;
                cout << "1. Incluir Passageiro" << endl;
                cout << "2. Excluir Passageiro" << endl;
                cout << "3. Listar Passageiros" << endl;
                cout << "4. Alterar Passageiros" << endl;
                cout << "0. Voltar ao Menu Principal" << endl;
                cout << "Escolha uma opção: ";
                cin >> escolhaPassageiros;

                switch (escolhaPassageiros)
                {
                case 1:
                    IncluirPassageiro(passageiros);
                    break;
                case 2:
                    ExcluirPassageiro(passageiros);
                    break;
                case 3:
                    ListarPassageiros(passageiros);
                    break;
                case 4:
                    AlterarPassageiro(passageiros);
                    break;
                case 0:
                    cout << "Voltando ao Menu Principal." << endl;
                    break;
                default:
                    cout << "Opção inválida." << endl;
                }
            } while (escolhaPassageiros != 0);
            break;

        case 2:
            // Módulo de gerenciamento de roteiros
            int escolhaRoteiros;
            do
            {
                cout << "\nMenu de Opções (Roteiros):" << endl;
                cout << "1. Incluir Roteiro" << endl;
                cout << "2. Excluir Roteiro" << endl;
                cout << "3. Listar Roteiros" << endl;
                cout << "4. Localizar Roteiro por Código" << endl;
                cout << "5. Alterar Roteiro" << endl;
                cout << "0. Voltar ao Menu Principal" << endl;
                cout << "Escolha uma opção: ";
                cin >> escolhaRoteiros;

                switch (escolhaRoteiros)
                {
                case 1:
                    IncluirRoteiro(roteiros);
                    break;
                case 2:
                    ExcluirRoteiro(roteiros);
                    break;
                case 3:
                    ListarRoteiros(roteiros);
                    break;
                case 4:
                    LocalizarRoteiro(roteiros);
                    break;
                case 5:
                    AlterarRoteiro(roteiros);
                    break;
                case 0:
                    cout << "Voltando ao Menu Principal." << endl;
                    break;
                default:
                    cout << "Opção inválida." << endl;
                }
            } while (escolhaRoteiros != 0);
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
