#include <iostream>
#include <vector>

using namespace std;
  

int main() {
    int n;
    cin >> n;
    
      // Criando matriz (N+1) x (N+1)
    vector<vector<int>> esquinas(n+1, vector<int>(n+1));

    // Lendo os dados das câmeras
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> esquinas[i][j];
        }
    }

    // Para cada quadra, verificar as 4 esquinas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int soma = esquinas[i][j] + esquinas[i][j+1] + esquinas[i+1][j] + esquinas[i+1][j+1];

            if (soma >= 2) {
                cout << "S"; // Quadra segura
            } else {
                cout << "U"; // Quadra insegura
            }
        }
        cout << endl; // Nova linha após cada linha de quadras
    }


    return 0;
}

