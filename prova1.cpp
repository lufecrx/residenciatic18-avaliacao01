#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct passageiro{
    string cpf;
    string nome;
    string dataNascimento;
    string numeroAutorizacao;
};
struct roteiro{
    int codigo;
    int data;
    int hora;
    string origem;
    string destino;
};


int localizar_cpf(vector<passageiro> listaPassageiros);
void incluir(vector<passageiro> &listaPassageiros);
void excluir(vector<passageiro> &listaPassageiros);
int localizar(vector<passageiro> listaPassageiros);
void alterar(vector<passageiro> &listaPassageiros);
void listar(vector<passageiro> listaPassageiros);


int main(void){
    vector<passageiro> listaPassageiros;
    int menu;

    do{
    cout << "MENU" << endl;
    cout << "1 - incluir" << endl;
    cout << "2 - excluir" << endl;
    cout << "3 - alterar" << endl;
    cout << "4 - listar" << endl;
    cout << "5 - localizar" << endl;
    cout << "0 - sair" << endl;
    cin >> menu;
    switch (menu){
        case 1:
            incluir(listaPassageiros);
            break;
        case 2:
            excluir(listaPassageiros);
            break;
        case 3:
            alterar(listaPassageiros);
            break;
        case 4:
            listar(listaPassageiros);
            break;
        case 5:
            localizar(listaPassageiros);
            break;
        case 0:
            break;
    }//switch
    }while(menu!=0);
    return 0;
}//main


void incluir(vector<passageiro> &listaPassageiros){
    passageiro novoPassageiro;
    cout << "Digite o nome do passageiro" << endl;
    cin >> novoPassageiro.nome;
    cout << "Digite o CPF" << endl;
    cin >> novoPassageiro.cpf;
    cout << "Digite a data de nascimento no formato DD/MM/AAAA" << endl;
    cin >> novoPassageiro.dataNascimento;
    //(adicionar funcao para verificar se a data digitada é valida)
    char resposta = 'n';
    novoPassageiro.numeroAutorizacao = "";
    cout << "Deseja adicionar um numero de autorizacao? (s/n)" << endl;
    cin >> resposta;
    if ((resposta == 's')||(resposta == 'S')){
        cout << "Digite o numero de autorizacao" << endl;
        cin >> novoPassageiro.numeroAutorizacao;
    }
    //fazer função para verificar respostas incorretas
    listaPassageiros.push_back(novoPassageiro);
}

void excluir(vector<passageiro> &listaPassageiros){
    vector<passageiro>::iterator it = listaPassageiros.begin();
    int i = localizar_cpf(listaPassageiros);
    if (i>=0){
    advance(it,i);
    listaPassageiros.erase(it);
    }
    else
        excluir(listaPassageiros);
}

void alterar(vector<passageiro> &listaPassageiros){
    int i = localizar(listaPassageiros);
    char resposta;
    if (i>=0){
        cout << "Deseja alterar o nome? (s/n)";
        cin >> resposta;
        if(resposta=='s')
            cin >> listaPassageiros[i].nome;

        cout << "Deseja alterar o CPF? (s/n)";
        cin >> resposta;
        if(resposta=='s')
            cin >> listaPassageiros[i].cpf;

        cout << "Deseja alterar a data de nascimento? (s/n)";
        cin >> resposta;
        if(resposta=='s')
            cin >> listaPassageiros[i].dataNascimento;

        cout << "Deseja alterar o numero de autentificação? (s/n)";
        cin >> resposta;
        if(resposta=='s')
            cin >> listaPassageiros[i].numeroAutorizacao;
    }  
}

int localizar(vector<passageiro> listaPassageiros){
    int i = localizar_cpf(listaPassageiros);
    if (i>=0){
        cout << "DADOS DO PASSAGEIRO:" << endl;
        cout << "Nome: " << listaPassageiros[i].nome << endl;
        cout << "CPF: " << listaPassageiros[i].cpf << endl;
        cout << "Data de Nascimento: " << listaPassageiros[i].dataNascimento << endl;
        cout << "Nuemro de Autorizacao: " << listaPassageiros[i].numeroAutorizacao << endl;

    }
    else
        localizar(listaPassageiros);
    return i;
}

void listar(vector<passageiro> listaPassageiros){
    for(int i=0;i<int(listaPassageiros.size());i++){
        cout << "DADOS DO PASSAGEIRO" << i << endl;
        cout << "Nome: " << listaPassageiros[i].nome << endl;
        cout << "CPF: " << listaPassageiros[i].cpf << endl;
        cout << "Data de Nascimento: " << listaPassageiros[i].dataNascimento << endl;
        cout << "Nuemro de Autorizacao: " << listaPassageiros[i].numeroAutorizacao << endl;
    }
}

int localizar_cpf(vector<passageiro> listaPassageiros){
    string cpf;
    cout << "Digite o CPF do passageiro:" << endl;
    cin >> cpf;
    for(int i=0;i<listaPassageiros.size();i++){
        if (listaPassageiros[i].cpf == cpf)
        cout << "Passageiro com CPF " << cpf << " encontrado" << endl;
        return i;
    }
    cout << "Passageiro com CPF " << cpf << " NAO encontrado" << endl;
    return -1;
}
/*
string adicionar_numero(){
    string numeroAutorizacao = "";
    char resposta;
    while((resposta != 's')||(resposta != 'S')||(resposta != 'n')||(resposta != 'N')){
    cout << "Deseja adicionar um numero de autorizacao? (s/n)" << endl:
    cin >> resposta;
    if ((resposta == 's')||(resposta == 'S')){
        cout << "Digite o numero de autorizacao" << endl;
        cin >> numeroAutorizacao;
    }
    else if((resposta != 'n')||(resposta != 'N')){

    }else
        cout << "Resposta invalida!";
    }
    return numeroAutorizacao;
}
*/