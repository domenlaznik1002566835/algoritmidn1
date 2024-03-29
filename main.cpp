#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

void countingSort(std::vector<unsigned char>& arr, int place){
    const int maxVal = 256;
    std::vector<int> count(maxVal, 0);
    std::vector<unsigned char> output(arr.size());
}

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
