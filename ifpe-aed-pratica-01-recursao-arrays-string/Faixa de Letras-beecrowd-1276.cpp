#include <iostream>
#include <vector>

using namespace std;

string reordenar(const string &s) { 
    //vetor para armazenar a frequência de cada caractere ('a' a 'z')
    vector<int> freq(26, 0);

    //frequência de cada letra na string
    for (char c : s) {
        freq[c - 'a']++;
    }

    //string ordenada
    string resultado = "";
    // do menor pro maior
    for(int i= 0; i <= 25; i++){
        while(freq[i] > 0){
            resultado += (char)('a' + i);
            freq[i]--;
        }
    }
    
    //do maior pro menor
    /*for (int i = 25; i >= 0; i--) {
        while (freq[i] > 0) {
        resultado += (char)('a' + i);
        freq[i]--;
    }*/

    return resultado;
}


int main() {
    cout << reordenar(string("casa")) << endl;
    cout << reordenar(string("escola")) << endl;
    cout << reordenar(string("ifpe")) << endl;
    cout << reordenar(string("banana")) << endl;
    return 0;
}
