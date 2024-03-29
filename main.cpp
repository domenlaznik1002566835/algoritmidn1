#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

void countingSort(std::vector<unsigned char>& arr, int place){
    const int maxVal = 256;
    std::vector<int> count(maxVal, 0);
    std::vector<unsigned char> output(arr.size());

    for (unsigned char i : arr)
        count[(i >> place) & 1]++;

    for(int i = 1; i < maxVal; i++)
        count[i] += count[i - 1];

    for(int i = arr.size() - 1; i >= 0; i--){
        output[count[(arr[i] >> place) & 1] - 1] = arr[i];
        count[(arr[i] >> place) & 1]--;
    }

    for(int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
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
