#include <iostream>

#include "lista.h"

using namespace std;

struct tarefa {
    string nome;
    bool feita = false;

    bool operator < (const tarefa &t) const {
        return this->nome < t.nome;
    }

    bool operator > (const tarefa &t) const {
        return this->nome > t.nome;
    }

    bool operator ==(const tarefa &t) const {
        return this->nome == t.nome;
    }
};

//problema 2 e 3
struct compras {
    string nome;
    int quantidade = 0;
    float preco = 0.0;

    bool operator == (const compras &c) const {
        return this->nome == c.nome;
    }

    bool operator < (const compras &c) const {
        return this->nome < c.nome;
    }

    bool operator > (const compras &c) const {
        return this->nome > c.nome;
    }
};


int main() {
    cout << ">> Adicionando valores iniciais..." << endl;
    int valores[] = {11, 4, 7, 9, 10,15,21, 8};

    cout << "Lista Simples: " << endl;

    Lista<int> lista(10);


    
    for (auto &v : valores) {
         lista.adicionar(v);
    }

    cout << "Lista antes de adicionar: " << endl;
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << i << ": " << lista.pega(i) << "; ";
    }
    cout << endl;
    cout << endl;

    //problema 1
    lista[5] = 55;

    cout << ">> Inserindo [22] na posicao [2]" << endl;
    lista.inserir(2, 22);
    for (int i = 1; i <= lista.tamanho(); i++) {cout << lista.pega(i) << " ";}cout << endl;
    cout << endl;

    cout << ">> Removendo elemento da posicao [3]" << endl;
    lista.remover(3);
    cout << "Lista apos remover (posicao 3): ";
for (int i = 1; i <= lista.tamanho(); i++) {cout << lista.pega(i) << " ";}cout << endl;
cout << endl;

    cout << ">> Adicionando elemento da posicao [77]" << endl;
    lista.adicionar(77);
    cout << "Lista apos Adicionar (posicao 77): ";
for (int i = 1; i <= lista.tamanho(); i++) {cout << lista.pega(i) << " ";}cout << endl;
cout << endl;

    cout << ">> Removendo elemento da posicao [4]" << endl;
    lista.remover(4);
    cout << "Lista apos remover (posicao 4): ";
    for (int i = 1; i <= lista.tamanho(); i++) {cout << lista.pega(i) << " ";}cout << endl;
    cout << endl;

    cout << "Lista apos adicionar: ";
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << i << ": " << lista.pega(i) << "; ";
    }
    cout << endl;

    int b[] = {10, 22, 11, 5, 7};
    cout << "Buscas: " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << lista.buscar(v) << endl;
    }

    cout << endl << "Lista Ordenada: " << endl;

    ListaOrdenada<int> listaOrd(10);

    for (auto &v : valores) {
        listaOrd.adicionar(v);
    }

    for (int i = 1; i <= listaOrd.tamanho(); i++) {
        cout << i << ": " << listaOrd.pega(i) << "; ";
    }
    cout << endl;

    cout << "Buscas: " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << listaOrd.buscar(v) << endl;
    }

    cout << endl << "Lista Ordenada de Tarefas: " << endl;

    // tarefa é o tipo do item; string é o tipo da chave usada para buscar o item
    ListaOrdenada<tarefa> todo(10);

    tarefa arr[] = { {"Feira", false},
                     {"Aluguel", false},
                     {"Lixo", false},
                     {"Estudar", false},
                     {"Cinema", false}};

    for (auto &v : arr) {
        todo.adicionar(v);
    }

    todo[1].feita = true;
    todo[3].feita = true;

    for (int i = 1; i <= todo.tamanho(); i++) {
        cout << i << ": " << todo[i].nome << " [" << (todo[i].feita?"feita":"nao feita") << "]" << endl;
    }

    string str[] = {"Feira", "Tarefa de casa", "Cinema", "Padaria"};
    for (string &s : str) {
        // Sintaxe { s, false } cria uma tarefa temporária com nome s, que é usada na busca
        cout << "- Buscando " << s << ": " << todo.buscar({s, false }) << endl;
    }
cout << endl;
   



//problema 2 e 3: Lista de compras ordenadas e simples

compras itensCompras[] = {
    {"Arroz", 2, 5.99},
    {"Feijao", 1, 7.50},
    {"Macarrao", 3, 4.00},
    {"Acucar", 2, 3.50},
    {"Leite", 6, 4.80},
    {"Oleo", 12, 6.92}
};

string nomesBusca[] = {"Leite", "Macarrao", "Oleo"};

cout << "Lista de compras Simples." << endl;
cout << "Lista de Compras: " << endl;
Lista<compras> listaCompras(10);

// Adicionando itens
for (auto &c : itensCompras) {
    listaCompras.adicionar(c);
}

// Inserindo um item no meio
cout << ">> Inserindo [Cafe] na posicao [2]" << endl;
listaCompras.inserir(2, {"Cafe", 1, 10.99});

// Varredura da lista
for (int i = 1; i <= listaCompras.tamanho(); i++) {
    compras c = listaCompras.pega(i);
    cout << i << ": " << c.nome << " - Qtde: " << c.quantidade << ", Preco: R$ " << c.preco << endl;
}

// Buscar alguns itens
for (string nomeBusca : nomesBusca) {
    int pos = listaCompras.buscar({nomeBusca, 0, 0});
    cout << "- Buscando [" << nomeBusca << "]: " << pos << endl;
}

cout <<endl;
cout << "Lista de compras Ordenada."<<endl;
ListaOrdenada<compras> listaComprasOrd(10);

for (auto &c : itensCompras) {
    listaComprasOrd.adicionar(c);
}

cout << "Lista Ordenada de Compras: " << endl;
for (int i = 1; i <= listaComprasOrd.tamanho(); i++) {
    compras c = listaComprasOrd.pega(i);
    cout << i << ": " << c.nome << " - Qtde: " << c.quantidade << ", Preco: R$ " << c.preco << endl;
}

for (string nomeBusca : nomesBusca) {
    int pos = listaComprasOrd.buscar({nomeBusca, 0, 0});
 cout << "- Buscando [" << nomeBusca << "]: " << pos << endl;
}

    return 0;
}
