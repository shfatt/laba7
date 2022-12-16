#include <vector>
#include <algorithm>
#include "7.h"

using namespace std;

bool myCompare(pair<vector<int>, long int> a, pair<vector<int>, long int> b) {
	return a.second < b.second;
}

vector<vector<int>> mySort(vector<vector<int>> matrix) {
	// calculate row sums

	vector<pair<vector<int>, long int>> pairs;
	for (int i = 0; i < matrix.size(); i++) {
		int rowSum = 0;
		for (int j = 0; j < matrix[i].size(); j++)
			rowSum += abs(matrix[i][j]);

		pairs.push_back({ matrix[i], rowSum });
	}

	sort(pairs.begin(), pairs.end(), myCompare);

	vector<vector<int>> newMatrix;
	for (auto pair : pairs) newMatrix.push_back(pair.first);

	return newMatrix;
}

bool checkConditions(vector<vector<int>> matrix) {
	// check for having 2 equal columns
	bool hasEqualColumns = false;

	for (int j1 = 0; j1 < matrix[0].size() - 1; j1++) {
		for (int j2 = j1 + 1; j2 < matrix[0].size(); j2++) {
			bool equal = true;
			for (int i = 0; i < matrix.size(); i++)
				if (matrix[i][j1] != matrix[i][j2]) {
					equal = false;
					break;
				}

			if (equal) {
				hasEqualColumns = true;
				break;
			}
		}
	}

	if (!hasEqualColumns) return false;

	bool hasAnyPrimeElement = false;
	// check for prime elements

	for (auto row : matrix)
		for (auto el : row)
			if (prime::isPrime(abs(el))) {
				hasAnyPrimeElement = true;
				break;
			}

	return hasAnyPrimeElement;
}



int main()
{
	auto matrix = fileIO::fileInput("input.txt");
	if (checkConditions(matrix)) matrix = mySort(matrix);
	fileIO::fileOutput("output.txt", matrix);
}
