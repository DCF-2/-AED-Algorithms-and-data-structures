/*
 * subseqmax.cpp
 *
 *  Created on: 15 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <vector>

unsigned long long count_ssm = 0;

using namespace std;

/* Pr�tica 10 - For�a Bruta -----------------*/

// start e finish: in�cio e final sendo testado agora;
// ini e end: onde s�o retornados o in�cio e final da melhor sequ�ncia
// retorno � a soma da maior sequ�ncia
int subseqMaxBF(const vector<int> &array, int & ini, int & end) {
	int maior_soma = INT_MIN;
	int tamanho = array.size();

	for(size_t i = 0; i < tamanho; i++){
		for (size_t j = i; j < tamanho; j++){
			int soma_atual = 0;
				for (size_t k = i; k < j; k++){
					soma_atual += array[k];
				}
			if(soma_atual > maior_soma){
				maior_soma = soma_atual;
				ini = i;
				end = j;
			}
		}
	}
	return maior_soma;
}

/* Pr�tica 11 - Dividir e Conquistar ----------------- */

int subseqMaxMiddle(const vector<int> &array, int start, int middle, int finish, int & ini, int & end) {
	// GIVEN
	int maxL = 0, maxR = 0;
	int sumL = 0, sumR = 0;

	ini = end = middle;

	for (int i = middle - 1; i >= start; i--) {
		count_ssm ++;
		sumL += array[i];
		if (sumL > maxL) {
			maxL = sumL;
			ini = i;
		}
	}

	for (int i = middle + 1; i <= finish; i++) {
		count_ssm ++;
		sumR += array[i];
		if (sumR > maxR) {
			maxR = sumR;
			end = i;
		}
	}

	return maxL + maxR + array[middle];
}

int subseqMaxDC_Rec(const vector<int> &array, int start, int finish, int & ini, int & end) {
	if(start == finish){
		ini = start;
		end = finish;
		return array[start];
	}
	int mid = (start + finish) /2;

	int ini_esq, fim_esq;
	int soma_esq = subseqMaxDC_Rec(array, start, mid, ini_esq, fim_esq);

	int ini_dir, fim_dir;
	int soma_dir = subseqMaxDC_Rec(array, mid +1, finish, ini_dir, fim_dir);

	int ini_mid, fim_mid;
	int soma_mid = subseqMaxMiddle(array, start, mid, finish, ini_mid, fim_mid);

	if( (soma_esq >= soma_dir) && (soma_esq >= soma_mid)){
		ini = ini_esq;
		end = fim_esq;
		return soma_esq;
	} else if((soma_dir >= soma_esq) && (soma_dir >= soma_mid)){
		ini = ini_dir;
		end = fim_dir;
		return soma_dir;
	} else{
		ini = ini_mid;
		end = fim_mid;
		return soma_mid;
	}
}

int subseqMaxDC(const vector<int> &array, int & ini, int & end) {
	// GIVEN
	int len = (int)array.size();
	return subseqMaxDC_Rec(array, 0, len - 1, ini, end);
}

/* Pr�tica 12 - Rercusiva ----------------- */

int subseqMaxRec(const vector<int> &array, int & ini, int & end) {
	// ???
	return -1;
}

/* Pr�tica 12 - Memoization ----------------- */

int subseqMaxMemo(const vector<int> &array, int & ini, int & end) {
	// ???

	return -1;
}

/* Pr�tica 12 - Programa��o Din�mica ----------------- */

int subseqMaxPD(const vector<int> &array, int & ini, int & end) {
	// ???

	return -1;
}

/* -------------------------------------- */

void runSubseqMax(const char * name, int subseqmax(const vector<int> &, int&, int&), const vector<int> & array, bool printSeq) {
	using namespace std::chrono;

	count_ssm = 0;

	int ini = 0, end = 0;

	auto start = high_resolution_clock::now();

	int max = subseqmax(array, ini, end);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << max << " ";


	cout << "[time: "<< setw(6) << setfill(' ') << elapsed << "us] ";
	cout << "[count: " << setw(6) << setfill(' ') << count_ssm << "] ";

	if (printSeq) {
		cout << "[ ";
		for (int i = ini; i <= end; i++) cout << array[i] << " ";
		cout << "] ";
	}

	cout << endl;
}

int main() {
	bool printSeq = true;
	int size = 20;

	srand(12345);

	vector<int> array(size);

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < size; j++) {
			array[j] = (rand() % (3 * size)) - (rand() % (4 * size));
		}

		cout <<"Test " << i << ": ";

		for (auto v : array) cout << v << " ";
		cout << endl;

		runSubseqMax("Bruteforce     ", subseqMaxBF, array, printSeq);
		runSubseqMax("Divide&Conquer ", subseqMaxDC, array, printSeq);
		runSubseqMax("Recursive      ", subseqMaxRec, array, printSeq);
		runSubseqMax("Memoization    ", subseqMaxMemo, array, printSeq);
		runSubseqMax("Dynamic Prog.  ", subseqMaxPD, array, printSeq);
	}

	return 0;
}






