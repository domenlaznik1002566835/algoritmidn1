#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

int main() {
    std::ifstream file("vhod.txt");
    std::vector<int> numbers;

    if (!file) {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::copy(std::istream_iterator<int>(file),
              std::istream_iterator<int>(),
              std::back_inserter(numbers));

    return 0;
}
