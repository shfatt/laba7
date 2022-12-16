#include "fileIO.h"
#include <fstream>
#include <string>
#include <vector>

namespace fileIO {

	vector<vector<int>> fileInput(string filePath) {
		ifstream fin;
		fin.open(filePath);

		string line;
		getline(fin, line);

		int n = stoi(line);

		vector<vector<int>> matrix;

		for (int i = 0; i < n; i++) {
			vector<int> row;
			for (int j = 0; j < n; j++) {
				int el;
				fin >> el;
				row.push_back(el);
			}
			matrix.push_back(row);
		}
		fin.close();
		return matrix;
	}

	void fileOutput(string filePath, vector<vector<int>> matrix) {
		ofstream fout;
		fout.open(filePath);

		for (vector<int> row : matrix) {
			for (int el : row) {
				fout << el << " ";
			}
			fout << "\n";
		}

		fout.close();
	}
}