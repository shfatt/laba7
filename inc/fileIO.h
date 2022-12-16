#pragma once

namespace fileIO {
	vector<vector<int>> fileInput(std::string filePath);
	void fileOutput(std::string filePath, std::vector<vector<int>> matrix);
}