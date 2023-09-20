#include <iostream>
#include <vector>
#include <string>

// Estrutura para representar um passageiro
struct Passageiro {
    std::string cpf;
    std::string nome;
    std::string dataNascimento;
    std::string numeroAutorizacao;
};

// Função para incluir um novo passageiro na coleção
void IncluirPassageiro(std::vector<Passageiro>& passageiros) {
    Passageiro novoPassageiro;
    std::cout << "CPF: ";
    std::cin >> novoPassageiro.cpf;
    std::cout << "Nome: ";
    std::cin.ignore(); // Limpar o buffer de entrada
    std::getline(std::cin, novoPassageiro.nome);
    std::cout << "Data de Nascimento: ";
    std::cin >> novoPassageiro.dataNascimento;
    std::cout << "Número de Autorização: ";
    std::cin >> novoPassageiro.numeroAutorizacao;

    passageiros.push_back(novoPassageiro);
    std::cout << "Passageiro incluído com sucesso!" << std::endl;
}

// Função para excluir um passageiro da coleção por CPF
void ExcluirPassageiro(std::vector<Passageiro>& passageiros, const std::string& cpf) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->cpf == cpf) {
            passageiros.erase(it);
            std::cout << "Passageiro excluído com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "Passageiro com CPF " << cpf << " não encontrado." << std::endl;
}

// Função para listar todos os passageiros
void ListarPassageiros(const std::vector<Passageiro>& passageiros) {
    std::cout << "Lista de Passageiros:" << std::endl;
    for (const Passageiro& passageiro : passageiros) {
        std::cout << "CPF: " << passageiro.cpf << std::endl;
        std::cout << "Nome: " << passageiro.nome << std::endl;
        std::cout << "Data de Nascimento: " << passageiro.dataNascimento << std::endl;
        std::cout << "Número de Autorização: " << passageiro.numeroAutorizacao << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

// Função para localizar um passageiro por CPF
void LocalizarPassageiro(const std::vector<Passageiro>& passageiros, const std::string& cpf) {
    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            std::cout << "CPF: " << passageiro.cpf << std::endl;
            std::cout << "Nome: " << passageiro.nome << std::endl;
            std::cout << "Data de Nascimento: " << passageiro.dataNascimento << std::endl;
            std::cout << "Número de Autorização: " << passageiro.numeroAutorizacao << std::endl;
            return;
        }
    }
    std::cout << "Passageiro com CPF " << cpf << " não encontrado." << std::endl;
}

// Função para alterar os dados de um passageiro por CPF
void AlterarPassageiro(std::vector<Passageiro>& passageiros, const std::string& cpf) {
    for (Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            std::cout << "Dados do passageiro com CPF " << cpf << ":" << std::endl;
            std::cout << "CPF: " << passageiro.cpf << std::endl;
            std::cout << "Nome: " << passageiro.nome << std::endl;
            std::cout << "Data de Nascimento: " << passageiro.dataNascimento << std::endl;
            std::cout << "Número de Autorização: " << passageiro.numeroAutorizacao << std::endl;

            std::cout << "Deseja alterar o Nome (S/N)? ";
            char escolha;
            std::cin >> escolha;
            if (escolha == 'S' || escolha == 's') {
                std::cout << "Novo Nome: ";
                std::cin.ignore();
                std::getline(std::cin, passageiro.nome);
            }

            std::cout << "Deseja alterar a Data de Nascimento (S/N)? ";
            std::cin >> escolha;
            if (escolha == 'S' || escolha == 's') {
                std::cout << "Nova Data de Nascimento: ";
                std::cin >> passageiro.dataNascimento;
            }

            std::cout << "Deseja alterar o Número de Autorização (S/N)? ";
            std::cin >> escolha;
            if (escolha == 'S' || escolha == 's') {
                std::cout << "Novo Número de Autorização: ";
                std::cin >> passageiro.numeroAutorizacao;
            }

            std::cout << "Dados do passageiro alterados com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "Passageiro com CPF " << cpf << " não encontrado." << std::endl;
}

int main() {
    std::vector<Passageiro> passageiros;
    int escolha;

    do {
        std::cout << "Menu de Opções:" << std::endl;
        std::cout << "1. Incluir" << std::endl;
        std::cout << "2. Excluir" << std::endl;
        std::cout << "3. Alterar (apenas por CPF)" << std::endl;
        std::cout << "4. Listar" << std::endl;
        std::cout << "5. Localizar (por CPF)" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                IncluirPassageiro(passageiros);
                break;
            case 2:
                {
                    std::string cpf;
                    std::cout << "CPF do passageiro a ser excluído: ";
                    std::cin >> cpf;
                    ExcluirPassageiro(passageiros, cpf);
                }
                break;
            case 3:
                {
                    std::string cpf;
                    std::cout << "CPF do passageiro a ser alterado: ";
                    std::cin >> cpf;
                    AlterarPassageiro(passageiros, cpf);
                }
                break;
            case 4:
                ListarPassageiros(passageiros);
                break;
            case 5:
                {
                    std::string cpf;
                    std::cout << "CPF do passageiro a ser localizado: ";
                    std::cin >> cpf;
                    LocalizarPassageiro(passageiros, cpf);
                }
                break;
            case 0:
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (escolha != 0);

    return 0;
}
