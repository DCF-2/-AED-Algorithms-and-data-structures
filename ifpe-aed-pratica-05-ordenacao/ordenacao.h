/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//A STL oferece uma sunção swap() que troca elementos; ela pode ser usada abaixo

template<class T>
void bubblesort(vector<T> &array) {
	size_t n = array.size();

	if(n < 2){return;}

	for(int i  = 0; i < n -1; i++){
		for (int j = 0; j < n-i-1; j++){
			if (array[j] > array[j+1]){
				swap(array[j], array[j+1]);
			}
		}
	}
}

template<class T>
void selectionsort(vector<T> &array) {
	size_t n = array.size();

	if( n < 2){return;}

	for (int i = 0; i < n-1; i++){
		int indice_menor = i;
			for (int j = i+1; j < n; j++){
				if (array[j] < array[indice_menor]){
					indice_menor = j;
				}
		}
		if (indice_menor != i){
					swap(array[i], array[indice_menor]);
				}
	}
	
}

template<class T>
void insertionsort(vector<T> &array) {
	size_t n = array.size();

	if(n < 2){return;}

	for(int i = 1; i < n; i++){
		int chave = array[i];
		int j = i -1;
		while((j >= 0) && (array[j] > chave)){
				array[j+1] = array[j];
				j--;
		}
		array[j+1] = chave;
	}
}

// Faz o merge dos subarrays em aux para array, isto é, array[...] = aux[...]
template<class T>
void merge(vector<T> &array, vector<T> &aux, int start, int mid, int finish) {

	vector<T> temp(aux.begin() + start, aux.begin() + finish + 1);
	
	int i = 0;
    int j = mid - start;
	int k = start;          // índice atual no array original

	int midLocal = mid - start;
    int finishLocal = finish - start;

    while (i < midLocal && j <= finishLocal) {
        if (temp[i] <= temp[j]) {
            array[k++] = temp[i++];
        } else {
            array[k++] = temp[j++];
        }
    }

    while (i < midLocal) {
        array[k++] = temp[i++];
    }

    while (j <= finishLocal) {
        array[k++] = temp[j++];
    }
}
// Array: array que vai conter o resultado ordenado
// Aux: array auxiliar usado para ordenar as duas metades, esquerda e direita
// Repare que na chamada recursiva de mergesorte, array e aux se alternam
// Isto é, uma hora um é o principal e o outro é o auxiliar, depois invertem
template<class T>
void mergesort(vector<T> &array, vector<T> &aux, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(aux, array, start, mid);
	mergesort(aux, array, mid + 1, finish);

	merge(array, aux, start, mid + 1, finish);
}

// Função chamada inicialmente;
// Chama a função mergesorte() acima com os limites start e finish, e o clone do array (aux).
template<class T>
void mergesort(vector<T> &array) {
    vector<T> &aux = array; // ⚠️ aux é uma REFERÊNCIA para o MESMO vetor
	mergesort(aux, array, 0, array.size() - 1);
}

// Partição do QuickSort
template<class T>
int partition(vector<T> &array, int start, int finish) {
	int pivo = array[finish];
	int i = start -1;

	for(int j = start; j < finish; j++){
		if(array[j] <= pivo){
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[finish]);
	return i + 1;
}

template<class T>
void quicksort(vector<T> &array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

// Semelhante ao que ocorre com o MergeSort.
template<class T>
void quicksort(vector<T> &array) {
	quicksort(array, 0, array.size() - 1);
}

// Funções Utilitárias

// Valida um array (isto é, se está ordenado ou não)
template<class T>
int validate(vector<T> &array) {
	for (int i = 0; i < array.size() - 1; i++) {
		if (array[i] > array[i + 1]) return 0;
	}
	return 1;
}

// Exibe um array na tela
template<class T>
void print(vector<T> &array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

// Testa um algoritmo passado como parâmetro.
template<class T>
void test(vector<T> &array, const char * name, void function(vector<T> &array), bool printFlag) {
    vector<T> copy = array;
	auto start = std::chrono::high_resolution_clock::now();

	function(copy);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	int valid = validate(copy);
	cout << name << ": " << (valid?"ok":"erro") << " (tempo[us] = " << elapsed << ") ";

	if (printFlag) print(copy); else cout << endl;
}








