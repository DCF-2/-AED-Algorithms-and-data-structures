#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool solve_recursive(vector<string> &M, int linha, int coluna);

// Função principal que inicia o processo.
void solve(vector<string> &M) {
    int linha_inicio = -1, coluna_inicio = -1;

    // 1. Encontra as coordenadas da origem 'o'.
    // CORREÇÃO: Loops corretos para percorrer a matriz.
    for (size_t l = 0; l < M.size(); l++) {
        for (size_t c = 0; c < M[l].size(); c++) {
            if (M[l][c] == 'o') {
                linha_inicio = l;
                coluna_inicio = c;
                break;
            }
        }
        if (linha_inicio != -1) break; // Sai do loop externo também
    }

    // 2. Chama a função recursiva para começar a busca.
    if (linha_inicio != -1) {
        solve_recursive(M, linha_inicio, coluna_inicio);
    }
}

// Função auxiliar que faz o backtracking.
bool solve_recursive(vector<string> &M, int linha, int coluna) {
    // Pega as dimensões do labirinto.
    int altura = M.size();
    int largura = M[0].size();

    // --- CASOS BASE (CONDIÇÕES DE PARAGEM) ---

    // 1. Fora dos limites do labirinto? Caminho inválido.
    if (linha < 0 || linha >= altura || coluna < 0 || coluna >= largura) {
        return false;
    }

    // 2. Posição atual é uma parede ('#') ou já faz parte do caminho ('x')? Inválido.
    if (M[linha][coluna] == '#' || M[linha][coluna] == 'x') {
        return false;
    }

    // 3. Chegámos ao destino ('d')? SUCESSO!
    if (M[linha][coluna] == 'd') {
        return true;
    }

    // --- PASSO RECURSIVO ---

    // 1. Marca o caminho (não marca a origem 'o').
    if (M[linha][coluna] != 'o') {
        M[linha][coluna] = 'x';
    }

    // 2. Tenta explorar os vizinhos (Cima, Baixo, Direita, Esquerda).
    if (solve_recursive(M, linha - 1, coluna)) return true; // Cima
    if (solve_recursive(M, linha + 1, coluna)) return true; // Baixo
    if (solve_recursive(M, linha, coluna + 1)) return true; // Direita
    if (solve_recursive(M, linha, coluna - 1)) return true; // Esquerda

    // 3. BACKTRACK: Se nenhum vizinho levou a uma solução, este caminho é um beco sem saída.
    //    Desfaz a marcação (não apaga a origem 'o').
    if (M[linha][coluna] != 'o') {
        M[linha][coluna] = '.';
    }

    
    return false;
}

void print(const vector<string> &M) {
    for (auto &s : M) {
        cout << s << endl;
    }
    cout << endl;
}

int main() {
    vector<string> M1 = {
            ".#...",
            "...##",
            ".#..#",
            "o##.d",
            "#####"
    };

    vector<string> M2 = {
            "#...o",
            "..###",
            ".#...",
            "...#.",
            "###d."
    };

    solve(M1);
    print(M1);

    /* sa�da valida
    .#...
    xxx##
    x#xx#
    o##xd
    #####
    */

    solve(M2);
    print(M2);

    /*
    #xxxo
    xx###
    x#xxx
    xxx#x
    ###dx
     */


    return 0;
}


