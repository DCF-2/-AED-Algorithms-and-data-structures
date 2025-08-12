#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:

void rotate(vector<int> &arr, int n) {
    int tam = arr.size(); //funcao arr.size() ler o tamanho da string
    if(tam == 0) return; // se estiver vazio retorna e nao faz nada
    
    n = n % tam; // Garante que não rotaciona mais do que precisa
    
    int temp[tam];
    
    int j = 0;
    for(int i= tam -n; i < tam; i++){
        temp[j] = arr[i];
        j++;
    }
    for(int i= 0; i< tam - n; i++){
        temp[j] = arr[i];
        j++;
    }
    for(int i= 0; i< tam; i++){
        arr[i] = temp[i];
    }

}
int main() {
    vector<int> arr = {3, 5, 8, 10, 1, 7, 9, 4};
    rotate(arr, 3);
    for (auto & v : arr) {
     cout << v << " ";   
    }
return 0;
}

//};