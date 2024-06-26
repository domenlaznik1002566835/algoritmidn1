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

void radixsort(std::vector<unsigned char> &arr){
    for(int place = 0; place < 8; place++)
        countingSort(arr, place);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: dn1 <input file>";
        return 1;
    }

    std::string filePath = argv[1];

    std::ifstream inputFile(filePath);
    std::vector<unsigned char> numbers;

    if (!inputFile) {
        std::cerr << "Unable to open file";
        return 1;
    }

    unsigned char number;
    while(inputFile >> number)
        numbers.push_back(number);

    radixsort(numbers);

    std::ofstream outputFile("izhod.txt");
    for(const auto& n : numbers){
        outputFile << static_cast<int>(n) << ' ';
    }

    return 0;
}