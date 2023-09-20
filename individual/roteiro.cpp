#include <iostream>
#include <vector>
#include <string>

// Definição da estrutura de roteiro
struct Roteiro {
    std::string codigo;
    std::string dataPrevista;
    std::string horaPrevista;
    std::string duracaoPrevista;
    std::string origem;
    std::string destino;
};

// Função para exibir o menu e obter a escolha do usuário
int exibirMenuRoteiros() {
    int escolha;
    std::cout << "\nMenu de Opções (Roteiros):" << std::endl;
    std::cout << "1. Incluir" << std::endl;
    std::cout << "2. Excluir" << std::endl;
    std::cout << "3. Alterar (por Código)" << std::endl;
    std::cout << "4. Listar" << std::endl;
    std::cout << "5. Localizar (por Código)" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::cin >> escolha;
    return escolha;
}

// Função para incluir um roteiro na coleção
void incluirRoteiro(std::vector<Roteiro>& roteiros) {
    Roteiro novoRoteiro;
    std::cout << "Código: ";
    std::cin >> novoRoteiro.codigo;
    std::cout << "Data Prevista: ";
    std::cin >> novoRoteiro.dataPrevista;
    std::cout << "Hora Prevista: ";
    std::cin >> novoRoteiro.horaPrevista;
    std::cout << "Duração Prevista: ";
    std::cin >> novoRoteiro.duracaoPrevista;
    std::cout << "Origem: ";
    std::cin.ignore();
    std::getline(std::cin, novoRoteiro.origem);
    std::cout << "Destino: ";
    std::getline(std::cin, novoRoteiro.destino);
    roteiros.push_back(novoRoteiro);
    std::cout << "Roteiro incluído com sucesso!" << std::endl;
}

// Função para excluir um roteiro da coleção por Código
void excluirRoteiro(std::vector<Roteiro>& roteiros, const std::string& codigo) {
    for (auto it = roteiros.begin(); it != roteiros.end(); ++it) {
        if (it->codigo == codigo) {
            roteiros.erase(it);
            std::cout << "Roteiro excluído com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "Roteiro não encontrado." << std::endl;
}

// Função para listar todos os roteiros
void listarRoteiros(const std::vector<Roteiro>& roteiros) {
    std::cout << "\nLista de Roteiros:" << std::endl;
    for (const Roteiro& roteiro : roteiros) {
        std::cout << "Código: " << roteiro.codigo << std::endl;
        std::cout << "Data Prevista: " << roteiro.dataPrevista << std::endl;
        std::cout << "Hora Prevista: " << roteiro.horaPrevista << std::endl;
        std::cout << "Duração Prevista: " << roteiro.duracaoPrevista << std::endl;
        std::cout << "Origem: " << roteiro.origem << std::endl;
        std::cout << "Destino: " << roteiro.destino << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

// Função para localizar um roteiro por Código
void localizarRoteiro(const std::vector<Roteiro>& roteiros, const std::string& codigo) {
    for (const Roteiro& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            std::cout << "\nRoteiro Encontrado:" << std::endl;
            std::cout << "Código: " << roteiro.codigo << std::endl;
            std::cout << "Data Prevista: " << roteiro.dataPrevista << std::endl;
            std::cout << "Hora Prevista: " << roteiro.horaPrevista << std::endl;
            std::cout << "Duração Prevista: " << roteiro.duracaoPrevista << std::endl;
            std::cout << "Origem: " << roteiro.origem << std::endl;
            std::cout << "Destino: " << roteiro.destino << std::endl;
            return;
        }
    }
    std::cout << "Roteiro não encontrado." << std::endl;
}

// Função para alterar os dados de um roteiro por Código
void alterarRoteiro(std::vector<Roteiro>& roteiros, const std::string& codigo) {
    for (auto& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            std::cout << "Código: " << roteiro.codigo << std::endl;
            std::cout << "Data Prevista atual: " << roteiro.dataPrevista << std::endl;
            std::cout << "Nova Data Prevista: ";
            std::cin >> roteiro.dataPrevista;
            std::cout << "Hora Prevista atual: " << roteiro.horaPrevista << std::endl;
            std::cout << "Nova Hora Prevista: ";
            std::cin >> roteiro.horaPrevista;
            std::cout << "Duração Prevista atual: " << roteiro.duracaoPrevista << std::endl;
            std::cout << "Nova Duração Prevista: ";
            std::cin >> roteiro.duracaoPrevista;
            std::cout << "Origem atual: " << roteiro.origem << std::endl;
            std::cin.ignore();
            std::cout << "Nova Origem: ";
            std::getline(std::cin, roteiro.origem);
            std::cout << "Destino atual: " << roteiro.destino << std::endl;
            std::cout << "Novo Destino: ";
            std::getline(std::cin, roteiro.destino);
            std::cout << "Dados do roteiro atualizados com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "Roteiro não encontrado." << std::endl;
}

int main() {
    std::vector<Roteiro> roteiros;

    while (true) {
        int escolha = exibirMenuRoteiros();

        switch (escolha) {
            case 1:
                incluirRoteiro(roteiros);
                break;
            case 2:
                {
                    std::string codigo;
                    std::cout << "Digite o Código do roteiro a ser excluído: ";
                    std::cin >> codigo;
                    excluirRoteiro(roteiros, codigo);
                }
                break;
            case 3:
                {
                    std::string codigo;
                    std::cout << "Digite o Código do roteiro a ser alterado: ";
                    std::cin >> codigo;
                    alterarRoteiro(roteiros, codigo);
                }
                break;
            case 4:
                listarRoteiros(roteiros);
                break;
            case 5:
                {
                    std::string codigo;
                    std::cout << "Digite o Código do roteiro a ser localizado: ";
                    std::cin >> codigo;
                    localizarRoteiro(roteiros, codigo);
                }
                break;
            case 0:
                std::cout << "Saindo do programa." << std::endl;
                return 0;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }
    }

    return 0;
}
