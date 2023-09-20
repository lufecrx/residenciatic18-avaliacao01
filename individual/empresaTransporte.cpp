#include <iostream>
#include <vector>
#include <string>

// Definição da estrutura de passageiro
struct Passageiro {
    std::string cpf;
    std::string nome;
    std::string dataNascimento;
    std::string numAutorizacao;
};

// Definição da estrutura de roteiro
struct Roteiro {
    std::string codigo;
    std::string dataPrevista;
    std::string horaPrevista;
    std::string duracaoPrevista;
    std::string origem;
    std::string destino;
};

// Função para exibir o menu principal e obter a escolha do usuário
int exibirMenuPrincipal() {
    int escolha;
    std::cout << "\nMenu Principal:" << std::endl;
    std::cout << "1. Gestão de Passageiros" << std::endl;
    std::cout << "2. Gestão de Roteiros" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::cin >> escolha;
    return escolha;
}

// Função para exibir o menu de gestão de passageiros e obter a escolha do usuário
int exibirMenuPassageiros() {
    int escolha;
    std::cout << "\nMenu de Opções (Passageiros):" << std::endl;
    std::cout << "1. Incluir" << std::endl;
    std::cout << "2. Excluir" << std::endl;
    std::cout << "3. Alterar (por CPF)" << std::endl;
    std::cout << "4. Listar" << std::endl;
    std::cout << "5. Localizar (por CPF)" << std::endl;
    std::cout << "0. Voltar ao Menu Principal" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::cin >> escolha;
    return escolha;
}

// Função para exibir o menu de gestão de roteiros e obter a escolha do usuário
int exibirMenuRoteiros() {
    int escolha;
    std::cout << "\nMenu de Opções (Roteiros):" << std::endl;
    std::cout << "1. Incluir" << std::endl;
    std::cout << "2. Excluir" << std::endl;
    std::cout << "3. Alterar (por Código)" << std::endl;
    std::cout << "4. Listar" << std::endl;
    std::cout << "5. Localizar (por Código)" << std::endl;
    std::cout << "0. Voltar ao Menu Principal" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::cin >> escolha;
    return escolha;
}

// Função para incluir um passageiro na coleção
void incluirPassageiro(std::vector<Passageiro>& passageiros) {
    Passageiro novoPassageiro;
    std::cout << "CPF: ";
    std::cin >> novoPassageiro.cpf;
    std::cout << "Nome: ";
    std::cin.ignore();
    std::getline(std::cin, novoPassageiro.nome);
    std::cout << "Data de Nascimento: ";
    std::cin >> novoPassageiro.dataNascimento;
    std::cout << "Número de Autorização: ";
    std::cin >> novoPassageiro.numAutorizacao;
    passageiros.push_back(novoPassageiro);
    std::cout << "Passageiro incluído com sucesso!" << std::endl;
}

// Função para excluir um passageiro da coleção por CPF
void excluirPassageiro(std::vector<Passageiro>& passageiros, const std::string& cpf) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->cpf == cpf) {
            passageiros.erase(it);
            std::cout << "Passageiro excluído com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "Passageiro não encontrado." << std::endl;
}

// Função para listar todos os passageiros
void listarPassageiros(const std::vector<Passageiro>& passageiros) {
    std::cout << "\nLista de Passageiros:" << std::endl;
    for (const Passageiro& passageiro : passageiros) {
        std::cout << "CPF: " << passageiro.cpf << std::endl;
        std::cout << "Nome: " << passageiro.nome << std::endl;
        std::cout << "Data de Nascimento: " << passageiro.dataNascimento << std::endl;
        std::cout << "Número de Autorização: " << passageiro.numAutorizacao << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

// Função para localizar um passageiro por CPF
void localizarPassageiro(const std::vector<Passageiro>& passageiros, const std::string& cpf) {
    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            std::cout << "\nPassageiro Encontrado:" << std::endl;
            std::cout << "CPF: " << passageiro.cpf << std::endl;
            std::cout << "Nome: " << passageiro.nome << std::endl;
            std::cout << "Data de Nascimento: " << passageiro.dataNascimento << std::endl;
            std::cout << "Número de Autorização: " << passageiro.numAutorizacao << std::endl;
            return;
        }
    }
    std::cout << "Passageiro não encontrado." << std::endl;
}

// Função para alterar os dados de um passageiro por CPF
void alterarPassageiro(std::vector<Passageiro>& passageiros, const std::string& cpf) {
    for (auto& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            std::cout << "\nDados do Passageiro:" << std::endl;
            std::cout << "CPF: " << passageiro.cpf << std::endl;
            std::cout << "Nome atual: " << passageiro.nome << std::endl;
            std::cout << "Nova Nome (deixe em branco para manter o mesmo): ";
            std::cin.ignore();
            std::getline(std::cin, passageiro.nome);
            if (passageiro.nome.empty()) {
                std::cout << "Nome mantido como estava." << std::endl;
            } else {
                std::cout << "Nome alterado com sucesso!" << std::endl;
            }
            std::cout << "Data de Nascimento atual: " << passageiro.dataNascimento << std::endl;
            std::cout << "Nova Data de Nascimento (deixe em branco para manter a mesma): ";
            std::getline(std::cin, passageiro.dataNascimento);
            if (passageiro.dataNascimento.empty()) {
                std::cout << "Data de Nascimento mantida como estava." << std::endl;
            } else {
                std::cout << "Data de Nascimento alterada com sucesso!" << std::endl;
            }
            std::cout << "Número de Autorização atual: " << passageiro.numAutorizacao << std::endl;
            std::cout << "Novo Número de Autorização (deixe em branco para manter o mesmo): ";
            std::cin >> passageiro.numAutorizacao;
            if (passageiro.numAutorizacao.empty()) {
                std::cout << "Número de Autorização mantido como estava." << std::endl;
            } else {
                std::cout << "Número de Autorização alterado com sucesso!" << std::endl;
            }
            return;
        }
    }
    std::cout << "Passageiro não encontrado." << std::endl;
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
            std::cout << "\nDados do Roteiro:" << std::endl;
            std::cout << "Código: " << roteiro.codigo << std::endl;
            std::cout << "Data Prevista atual: " << roteiro.dataPrevista << std::endl;
            std::cout << "Nova Data Prevista (deixe em branco para manter a mesma): ";
            std::cin.ignore();
            std::getline(std::cin, roteiro.dataPrevista);
            if (roteiro.dataPrevista.empty()) {
                std::cout << "Data Prevista mantida como estava." << std::endl;
            } else {
                std::cout << "Data Prevista alterada com sucesso!" << std::endl;
            }
            std::cout << "Hora Prevista atual: " << roteiro.horaPrevista << std::endl;
            std::cout << "Nova Hora Prevista (deixe em branco para manter a mesma): ";
            std::getline(std::cin, roteiro.horaPrevista);
            if (roteiro.horaPrevista.empty()) {
                std::cout << "Hora Prevista mantida como estava." << std::endl;
            } else {
                std::cout << "Hora Prevista alterada com sucesso!" << std::endl;
            }
            std::cout << "Duração Prevista atual: " << roteiro.duracaoPrevista << std::endl;
            std::cout << "Nova Duração Prevista (deixe em branco para manter a mesma): ";
            std::getline(std::cin, roteiro.duracaoPrevista);
            if (roteiro.duracaoPrevista.empty()) {
                std::cout << "Duração Prevista mantida como estava." << std::endl;
            } else {
                std::cout << "Duração Prevista alterada com sucesso!" << std::endl;
            }
            std::cout << "Origem atual: " << roteiro.origem << std::endl;
            std::cout << "Nova Origem (deixe em branco para manter a mesma): ";
            std::getline(std::cin, roteiro.origem);
            if (roteiro.origem.empty()) {
                std::cout << "Origem mantida como estava." << std::endl;
            } else {
                std::cout << "Origem alterada com sucesso!" << std::endl;
            }
            std::cout << "Destino atual: " << roteiro.destino << std::endl;
            std::cout << "Novo Destino (deixe em branco para manter o mesmo): ";
            std::getline(std::cin, roteiro.destino);
            if (roteiro.destino.empty()) {
                std::cout << "Destino mantido como estava." << std::endl;
            } else {
                std::cout << "Destino alterado com sucesso!" << std::endl;
            }
            return;
        }
    }
    std::cout << "Roteiro não encontrado." << std::endl;
}

int main() {
    // Declaração de variáveis e estruturas de dados
    std::vector<Passageiro> passageiros;
    std::vector<Roteiro> roteiros;

    // Loop principal
    while (true) {
        int escolhaPrincipal = exibirMenuPrincipal();

        switch (escolhaPrincipal) {
            case 1:
                while (true) {
                    int escolhaPassageiros = exibirMenuPassageiros();

                    switch (escolhaPassageiros) {
                        case 1:
                            incluirPassageiro(passageiros);
                            break;
                        case 2:
                            {
                                std::string cpf;
                                std::cout << "Digite o CPF do passageiro a ser excluído: ";
                                std::cin >> cpf;
                                excluirPassageiro(passageiros, cpf);
                            }
                            break;
                        case 3:
                            {
                                std::string cpf;
                                std::cout << "Digite o CPF do passageiro a ser alterado: ";
                                std::cin >> cpf;
                                alterarPassageiro(passageiros, cpf);
                            }
                            break;
                        case 4:
                            listarPassageiros(passageiros);
                            break;
                        case 5:
                            {
                                std::string cpf;
                                std::cout << "Digite o CPF do passageiro a ser localizado: ";
                                std::cin >> cpf;
                                localizarPassageiro(passageiros, cpf);
                            }
                            break;
                        case 0:
                            break;
                        default:
                            std::cout << "Opção inválida. Tente novamente." << std::endl;
                            break;
                    }

                    if (escolhaPassageiros == 0) {
                        break;
                    }
                }
                break;
            case 2:
                while (true) {
                    int escolhaRoteiros = exibirMenuRoteiros();

                    switch (escolhaRoteiros) {
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
                            break;
                        default:
                            std::cout << "Opção inválida. Tente novamente." << std::endl;
                            break;
                    }

                    if (escolhaRoteiros == 0) {
                        break;
                    }
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
