#include <iostream>
#include <vector>
using namespace std;

class fila_media{
    private:
    vector<int> itens;
    int capacidade = 0;
    int inicio = 0;
    int tam = 0;
    int soma = 0;
    int final = 0;
    
    public:
    explicit fila_media(int capacidade) : capacidade(capacidade), itens(capacidade){}
    
    bool cheia()const{
        return tam == capacidade;
    }
    
    bool vazia()const{
        return tam == 0;
    }
    
    void desenfileira(){
        if(!vazia()){
            soma -= itens[inicio];
            inicio = (inicio + 1) % capacidade;
            tam--;
        }
    }
    
    void enfileira(int i){
        final = (inicio + tam) % capacidade;
        itens[final] = i;
        soma += i;
        tam++;
    }
    
    int proximo(){
        if(!vazia()){
            return itens[inicio];
            throw runtime_error("Fila vazia");
        }
    }
    
    double media() const{
        if(tam == 0) return 0.0;
        return static_cast<double>(soma) / tam;
    }
    
    int tamanho() const{
        return tam;
    }

};
int main() {
    int arr[] = {10, 2, 3, 5, 6, 10, 7, 9, 2, 6, 3, 13, 6};
    fila_media fila(4);
    
    for(int i : arr){
        if (fila.cheia()) fila.desenfileira();
        fila.enfileira(i);
        cout << fila.media() << " ";
    }
    return 0;
}
