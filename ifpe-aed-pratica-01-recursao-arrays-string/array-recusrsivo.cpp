#include <iostream>
#include <vector>
using namespace std;

int maior(const vector<int> &arr, int local) {
	int maiorvalor = arr[0];

	if(local == arr.size() -1) {
		return arr[local];
	}

	int maiorResult = maior(arr, local +1);

	return max(arr[local], maiorResult);
	//return min(arr[local], maiorResult);  // A funC'C#o std::max() retorna o maior dos dois valores passados como argumentos.
	// funC'C#o mim() retorna o menor valor dos dois valores passados como argumentos.
}

int main() {
	int local;
	vector<int> arr = {10, 1, 5, 3, 12, 7, 4, 6, 20, 100, 30, 50, 20, 15, 35, 24};
	cout << maior(arr, 0) << endl;
	return 0;
}

/*for(int i= 1; i < arr.size(); i++){
     if(arr[i] > maiorvalor){
         maiorvalor = arr[i];
     }
 }
 return maiorvalor;
}*/
