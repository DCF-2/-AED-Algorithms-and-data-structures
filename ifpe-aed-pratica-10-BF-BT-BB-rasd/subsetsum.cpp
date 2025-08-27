/*
 * subsetsum.cpp
 *
 *  Created on: 14 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long count_ssk = 0;

/* Prática 10 - Força Bruta ------------------*/

bool subsetSumBF(const vector<int> &array, int K, vector<bool> &subset) {
        // GIVEN
	long total = 1 << array.size(); // 2^N combinações totais

	for (long v = 0; v < total; v++) { // para todas as combinações
		count_ssk ++;

		int cur_sum = 0;
		for (unsigned i = 0; i < array.size(); i++) { // para todas as posições / bits
			subset[i] = v & (1 << i);
			if (subset[i]) cur_sum += array[i];
		}
		if (cur_sum == K) return true;
	}

	return false;
}

/* Prática 10 - Backtracking ------------------- */


bool subsetSumBT(const vector<int> &array, int k, vector<bool> &subset) {
    // TODO

    return false;
}

/* Prática 11 - Greedy ------------------ */

bool subsetSumGreedy(const vector<int> &array, int k, vector<bool> &subset) {
    // ???

    return false;
}

/* Prática 12 - Programação Dinâmica ------------------ */

bool subsetSumMemo(const vector<int> &array, int k, vector<bool> &subset) {
    // ???
    return false;
}

bool subsetSumDP(const vector<int> &array, int k, vector<bool> &subset) {
    // ???

    return false;
}

/* -------------------------------------- */

bool check_sum(const vector<int> &array, int sum, const vector<bool> &subset) {
	int cur_sum = 0;

	for (int i = 0; i < (int)array.size(); i++) {
		if (subset[i]) cur_sum += array[i];
	}

	return (cur_sum == sum);
}

void runSubsetSum(const char *name, bool subsetSum(const vector<int> &, int, vector<bool> &), const vector<int> &array, int sum) {
	using namespace std::chrono;

    count_ssk = 0;

	vector<bool> subset(array.size(), false);

	auto start = high_resolution_clock::now();

	bool found = subsetSum(array, sum, subset);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish - start).count() / 1000;

	bool valid = found && check_sum(array, sum, subset);

	cout << name << ": " << (found ? ( valid ? "YES " : "ERR " ): " NO ");

	cout << "[time: " << elapsed << "us] ";
	cout << "[count: " << count_ssk << "] ";
	if (found) {
		cout << "[ ";
		for (unsigned i = 0; i < array.size(); i++) {
			if (subset[i])
				cout << array[i] << " ";
		}
		cout << "] ";
	}
	cout << endl;

}

int main() {
	int size = 20;

	vector<int> array(size);

//	srand(333);
	srand(12345);

	for (int i = 0; i < size; i++) {
		cout << (array[i] = 1 + rand() % (size * 5)) << " ";
	}
	cout << endl;

	int value = 0;
	for (int i = 0; i < 20; i++) {
		value += (rand() % (size * 6));
		cout << i << ": Trying " << value << " ..." << endl;

		runSubsetSum("Bruteforce   ", subsetSumBF, array, value);
		runSubsetSum("Backtracking ", subsetSumBT, array, value);
		runSubsetSum("Memoization  ", subsetSumMemo, array, value);
		runSubsetSum("Dynamic Prog.", subsetSumDP, array, value);
		runSubsetSum("Greedy       ", subsetSumGreedy, array, value);
	}


	return 0;
}

