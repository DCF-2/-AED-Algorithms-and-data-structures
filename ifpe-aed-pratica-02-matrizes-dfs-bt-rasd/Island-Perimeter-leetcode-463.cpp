#include <iostream>
#include <vector>

using namespace std;

/*class Solution{
public:*/

int islandPerimeter(vector<vector<int>>& grid) {
    int perimeter = 0;
    
    // Obtendo o número de linhas e colunas da matriz.
    int row = grid.size();
    int col = grid[0].size();
    
    // Percorre toda a matriz.
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            // Se a célula representa terra (1), adicionamos 4 ao perímetro inicial.
            if(grid[i][j] == 1){
                perimeter += 4;
                
                // Subtrai 1 para cada vizinho que também seja terra.
                if (i > 0 && grid[i-1][j] == 1) perimeter -= 1;         // Célula acima.
                if (i < row - 1 && grid[i+1][j] == 1) perimeter -= 1;   // Célula abaixo.
                if (j > 0 && grid[i][j-1] == 1) perimeter -= 1;         // Célula à esquerda.
                if (j < col - 1 && grid[i][j+1] == 1) perimeter -= 1;   // Célula à direita.
            }
        }
    }
    return perimeter;
};

int main(){
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    // Chama a função e imprime o perímetro da ilha.
    cout << "Perímetro da ilha: " << islandPerimeter(grid) << endl;
    return 0;
}

/* pseudocodigo:
perimetro = 0

Para i de 0 até row-1:
    Para j de 0 até col-1:
        Se grid[i][j] == 1:
            perimetro += 4
            
            Se i > 0 e grid[i-1][j] == 1:
                perimetro -= 1
            Se i < row-1 e grid[i+1][j] == 1:
                perimetro -= 1
            Se j > 0 e grid[i][j-1] == 1:
                perimetro -= 1
            Se j < col-1 e grid[i][j+1] == 1:
                perimetro -= 1

Retornar perimetro
*/
