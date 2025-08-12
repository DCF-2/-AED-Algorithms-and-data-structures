#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Função que verifica se a chuva pode atingir uma determinada célula
bool checa_chuva(const vector<vector<char>> &C, int i, int j) {
    return (i > 0 && C[i - 1][j] == 'o') ||                                                      // Se há chuva diretamente acima
    (j > 0 && i < C.size() - 1 && C[i][j - 1] == 'o' && C[i + 1][j - 1] == '#') ||              // Esquerda segura para fluxo de água
    (j < C[i].size() - 1 && i < C.size() - 1 && C[i][j + 1] == 'o' && C[i + 1][j + 1] == '#'); // Direita segura para fluxo de água
}

// Solução iterativa: Simula a propagação da chuva até que nenhuma célula nova seja preenchida.
void solucao_iterativa(vector<vector<char>> &C) {
    bool change;                                        // Variável de controle para verificar mudanças na matriz
    do {
        change = false;                               // Reseta a variável para cada nova verificação
        for (int i = 0; i < C.size(); i++) {         // Percorre todas as linhas
            for (int j = 0; j < C[i].size(); j++) { // Percorre todas as colunas
                if (C[i][j] != '.') continue;      // Apenas células vazias podem ser preenchidas

                // Se houver chuva ao redor, preenche a célula com 'o'
                if (checa_chuva(C, i, j)) {
                    C[i][j] = 'o';
                    change = true;              // Marca que houve uma mudança na matriz
                }
            }
        }
    }
    while (change);
}

// Verifica se uma posição da matriz é válida para ser preenchida
bool valida(const vector<vector<char>> &C, int i, int j) {
    return (i >= 0 && j >= 0 && i < C.size() && j < C[i].size() && C[i][j] == '.');
}

// Algoritmo recursivo: Espalha a chuva para posições válidas
void chuva(vector<vector<char>> &C, int i, int j) {
    if (C[i][j] == 'o' || checa_chuva(C, i, j)) {               // Se já tem chuva ou pode ser preenchido
    
        C[i][j] = 'o';                                       // Marca a célula como molhada

        if (valida(C, i, j - 1)) chuva(C, i, j - 1); // Espalha para a esquerda
        //if (valida(C, i, j + 1)) chuva(C, i, j + 1); // Espalha para a direita
        if (valida(C, i + 1, j)) chuva(C, i + 1, j); // Espalha para baixo
    }
}

// Chama a solução recursiva a partir da posição inicial da chuva
void solucao_recursiva(vector<vector<char>> &C, int x, int y) {
    chuva(C, x, y);
}

// Algoritmo baseado em pilha: Simula uma abordagem semelhante à recursão, mas sem uso explícito da pilha de chamadas
void solucao_pilha(vector<vector<char>> &C, int x, int y) {
    stack<pair<int, int>> pilha;                            // Usa uma pilha para armazenar as posições a serem processadas

    pilha.emplace(x, y);                                    // Adiciona a posição inicial

    while (!pilha.empty()) {                                // Enquanto houver células a processar
        auto [i, j] = pilha.top();
        pilha.pop();                                        // Remove a célula da pilha

        if (C[i][j] == 'o' || checa_chuva(C, i, j)) {               // Se já tem chuva ou pode ser preenchido
            C[i][j] = 'o';                                          // Marca a célula como molhada

            if (valida(C, i + 1, j)) pilha.emplace(i + 1, j); // Chuva escorrendo para baixo
            if (valida(C, i, j - 1)) pilha.emplace(i, j - 1); // Chuva para a esquerda
            //if (valida(C, i, j + 1)) pilha.emplace(i, j + 1); // Chuva para a direita
        }
    }
}

// Algoritmo baseado em fila: Similar ao da pilha, mas espalha a chuva de maneira mais uniforme
void solucao_fila(vector<vector<char>> &C, int x, int y) {
    queue<pair<int, int>> fila;                                 // Usa uma fila para armazenar as posições a serem processadas

    fila.emplace(x, y);                                         // Adiciona a posição inicial

    while (!fila.empty()) {                                     // Enquanto houver células a processar
        auto [i, j] = fila.front();
        fila.pop();                                             // Remove a célula da fila

        if (C[i][j] == 'o' || checa_chuva(C, i, j)) {           // Se já tem chuva ou pode ser preenchido
            C[i][j] = 'o';                                      // Marca a célula como molhada

            if (valida(C, i + 1, j)) fila.emplace(i + 1, j); // Chuva escorrendo para baixo
            //if (valida(C, i, j - 1)) fila.emplace(i, j - 1); // Chuva para a esquerda
            if (valida(C, i, j + 1)) fila.emplace(i, j + 1); // Chuva para a direita
        }
    }
}


int main() {
    int n, m, x, y;

    cin >> n >> m;

    vector<vector<char>> C(n, vector<char>(m)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
            if (C[i][j] == 'o') {                           // Guarda a posição inicial da chuva
                x = i;
                y = j;
            }
        }
    }

    // Escolha da solução desejada:
    // solucao_iterativa(C);
    // solucao_recursiva(C, x, y);
    // solucao_pilha(C, x, y);

    solucao_fila(C, x, y); // Utilizando a solução baseada em fila

    for (const auto &linha : C) {
        for (char c : linha) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
