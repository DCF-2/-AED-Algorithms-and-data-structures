#include <iostream>
#include <vector>   

using namespace std;
void validStrings(vector<string> &seqs, int n, string tmp) {
    if (tmp.size() == n) {
        seqs.push_back(tmp);
        return;
    }

    validStrings(seqs, n, tmp + "0");
    validStrings(seqs, n, tmp + "1");
}
// Função que inicia o processo recursivo e retorna o vetor de strings
vector<string> validStrings(int n) {
    vector<string> seqs;            // Vetor que guarda as sequências válidas
    validStrings(seqs, n, "");
    return seqs;
}

int main() {
    int n = 2;
    for (auto &s : validStrings(n)) {
        cout << s << endl;  
    }
    return 0;
}

// Função p/ letcode
/*// Função recursiva que gera todas as strings binárias válidas
void validStrings(vector<string> &seqs, int n, string tmp) {
    //condição de parada:
    // Se o tamanho da string temporária 'tmp' já for igual a 'n'
    if (tmp.size() == n) {
        seqs.push_back(tmp);  // Adiciona a string completa no vetor 'seqs'
        return;           
    }

    //Sempre pode adicionar o dígito '1'
    validStrings(seqs, n, tmp + "1");

    //Só podemos adicionar '0' se:
    // - A string estiver vazia (primeiro caractere) OU
    // - O último caractere NÃO for '0' (para evitar dois zeros seguidos)
    if (tmp.empty() || tmp.back() != '0') {
        validStrings(seqs, n, tmp + "0");
    }
}
*/