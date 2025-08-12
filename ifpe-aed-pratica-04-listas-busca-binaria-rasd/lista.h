//
// Created by IFPE on 10/06/2025.
//

#ifndef FILAS_LISTA_H
#define FILAS_LISTA_H

#include <vector>

using namespace std;

template <class T>
class Lista {
protected:
    int capacidade;
    int num_itens = 0;
    vector<T> itens;

    T & pega_ref(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        return itens[idx - 1];
    }

public:
    explicit Lista(int capacidade)  : itens(capacidade), capacidade(capacidade), num_itens(0) {
        if (capacidade <= 0) throw runtime_error("Capacidade invalida");
    }

    virtual void adicionar(T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");

        itens[num_itens] = v;
        num_itens++;
    }

    virtual void inserir(int idx, T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        for (int i = num_itens - 1; i >= idx - 1; i--) {
            itens[i + 1] = itens[i];
        }

        itens[idx - 1] = v;

        num_itens++;
    }
    //problema 1
    void remover(int index){
        if(num_itens == 0){cout << "lista vazia." << endl; return;}
        if( (index < 1) || (index > num_itens)){cout << "index invalido."<< endl; return;}
        for(int i= index - 1; i < num_itens -1; i++){
            itens[i] = itens[i +1];
        }
        num_itens--;
}

    int tamanho() const {
        return num_itens;
    }

    T pega(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        return itens[idx - 1];
    }

    T & operator [] (int idx) {
        return pega_ref(idx);
    }

    virtual int buscar(T valor) {
        for (int i = 0; i < num_itens; i++) {
            if (itens[i] == valor) {
                return i + 1;
            }
        }
        return -1;
    }
};

// T é o tipo do dado, ex., tarefa
template <class T>
class ListaOrdenada : public Lista<T> {


public:
    explicit ListaOrdenada(int cap) : Lista<T>(cap) {  }

    void inserir(int idx, T v) override {
        throw runtime_error("Operacao nao suportada!");
    }

    void adicionar(T v) override {
        if (this->num_itens >= this->capacidade) throw runtime_error("Fila cheia!");

        int i = 0;
        for (i = this->num_itens - 1; i >= 0 && this->itens[i] > v; i--) {
            this->itens[i + 1] = this->itens[i];
        }
        this->itens[i + 1] = v;
        this->num_itens++;
    }

    int buscar_binario_recursivo(int inicio, int fim, T valor) {
    if (inicio > fim) {
        return -1;  // Não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (this->itens[meio] == valor) {
        return meio + 1;  // Índice baseado em 1
    }
    else if (this->itens[meio] < valor) {
        return buscar_binario_recursivo(meio + 1, fim, valor);
    }
    else {
        return buscar_binario_recursivo(inicio, meio - 1, valor);
    }
}
    int buscar(T v) override {
        //Busca Recursiva
    //return buscar_binario_recursivo(0, this->num_itens - 1, valor);
    int inicio = 0;
    int fim = this->num_itens - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (this->itens[meio] == v) {
            return meio + 1;  // índice 1-based
        }
        else if (this->itens[meio] < v) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
        return -1;
    }
};


#endif //FILAS_LISTA_H
