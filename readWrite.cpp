#include <fstream>
#include <iostream>

void displayFileContents(std::ifstream& file) {
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

void readAndDisplayFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return;
    }

    displayFileContents(file);
}

int main() {
    readAndDisplayFile("vhod.txt");
    readAndDisplayFile("izhod.txt");

    return 0;
}