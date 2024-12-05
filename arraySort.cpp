#include "arraySort.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <span>

namespace {
const int kStaticArraySize = 5;
const int kMinimumElementValue = 0;
const int kMaximumElementValue = 99;

void PrintMenu() {
    std::cout << "1 - Статический массив" << '\n';
    std::cout << "2 - Динамический массив" << '\n';
    std::cout << "Введите номер задачи: " << '\n';
}

void PrintArray(size_t arrayLength, int* array) {
    if (arrayLength <= kStaticArraySize) {
        std::cout << "----------------------------------------------------------------------------------------------------------" << '\n';
        std::cout << "--  массив до сортировки:    ";
        for (int i : std::span(array, arrayLength)) {
            std::cout << i << "\t";
        }
        std::cout << '\n';
    }
}

void PrintSortedArray(int comparisons, int permutations, int* resultArray, size_t arrayLength, bool SortMethod) {
    if (SortMethod) {
        std::cout << "--  после сортировки выбором:";
        if (arrayLength <= kStaticArraySize) {
            for (int i : std::span(resultArray, arrayLength)) {
                std::cout << i << "  ";
            }
            std::cout << '\n' << "--" << '\n';
        }
    } else {
        std::cout << "--  после сортировки пузырьком:";
        if (arrayLength <= kStaticArraySize) {
            for (int i : std::span(resultArray, arrayLength)) {
                std::cout << i << "  ";
            }
            std::cout << '\n' << "--" << '\n';
        }
    }

    std::cout << "--  количество сравнений = " << comparisons << '\n'
              << "--  количество перестановок = " << permutations << '\n'
              << "----------------------------------------------------------------------------------------------------------" << '\n';
}

void ArrayGenerator(int* array, size_t arrayLength) {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(kMinimumElementValue, kMaximumElementValue);
    for (size_t i = 0; i < arrayLength; ++i) {
        array[i] = distribution(randomEngine);
    }
}
}  // namespace

namespace SortsArrays {

void RunSelectionSort(int& permutations, int& comparisons, size_t arrayLength, int* source, bool SortType) {
    permutations = 0;
    comparisons = 0;
    for (size_t i{}; i < arrayLength - 1; ++i) {
        int position = i;
        for (size_t j = i + 1; j < arrayLength; ++j) {
            if ((source[j] < source[position] && SortType) || (source[j] > source[position] && !SortType)) {
                position = j;
            }
        }
        if (source[i] != source[position]) {
            permutations += 1;
        }
        comparisons += 1;
        std::swap(source[i], source[position]);
    }
}

void RunBubbleSort(int& permutations, int& comparisons, int* source, size_t arrayLength, bool SortType) {
    permutations = 0;
    comparisons = 0;

    for (size_t i{}; i < arrayLength - 1; i++) {
        for (size_t j{}; j < arrayLength - i - 1; j++) {
            comparisons += 1;
            if ((source[j] > source[j + 1] && SortType) || (source[j] < source[j + 1] && !SortType)) {
                std::swap(source[j], source[j + 1]);
                permutations += 1;
            }
        }
        if (permutations == 0) {
            break;
        }
    }
}

void RunStaticArraySort() {
    int SourceStaticArray[kStaticArraySize]{};
    ArrayGenerator(SourceStaticArray, kStaticArraySize);

    int CopySourceStaticArray[kStaticArraySize]{};
    std::copy(SourceStaticArray, SourceStaticArray + kStaticArraySize, CopySourceStaticArray);

    int permutations{};
    int comparisons{};

    PrintArray(kStaticArraySize, SourceStaticArray);

    RunSelectionSort(permutations, comparisons, kStaticArraySize, SourceStaticArray, true);
    PrintSortedArray(comparisons, permutations, SourceStaticArray, kStaticArraySize, true);
    RunSelectionSort(permutations, comparisons, kStaticArraySize, SourceStaticArray, true);
    PrintSortedArray(comparisons, permutations, SourceStaticArray, kStaticArraySize, true);
    RunSelectionSort(permutations, comparisons, kStaticArraySize, SourceStaticArray, false);
    PrintSortedArray(comparisons, permutations, SourceStaticArray, kStaticArraySize, true);

    PrintArray(kStaticArraySize, CopySourceStaticArray);

    RunBubbleSort(permutations, comparisons, CopySourceStaticArray, kStaticArraySize, true);
    PrintSortedArray(comparisons, permutations, SourceStaticArray, kStaticArraySize, false);
    RunBubbleSort(permutations, comparisons, CopySourceStaticArray, kStaticArraySize, true);
    PrintSortedArray(comparisons, permutations, SourceStaticArray, kStaticArraySize, false);
    RunBubbleSort(permutations, comparisons, CopySourceStaticArray, kStaticArraySize, false);
    PrintSortedArray(comparisons, permutations, SourceStaticArray, kStaticArraySize, false);
}

void RunDynamicArraySort(size_t arrayLength) {
    int* SourceDynamicArray = new int[arrayLength]{};
    ArrayGenerator(SourceDynamicArray, arrayLength);
    int* CopySourceDynamicArray = new int[arrayLength]{};
    std::copy(SourceDynamicArray, SourceDynamicArray + kStaticArraySize, CopySourceDynamicArray);

    int permutations{};
    int comparisons{};

    PrintArray(arrayLength, SourceDynamicArray);

    RunSelectionSort(permutations, comparisons, arrayLength, SourceDynamicArray, true);
    PrintSortedArray(comparisons, permutations, SourceDynamicArray, arrayLength, true);

    PrintArray(arrayLength, CopySourceDynamicArray);

    RunBubbleSort(permutations, comparisons, CopySourceDynamicArray, arrayLength, true);
    PrintSortedArray(comparisons, permutations, SourceDynamicArray, arrayLength, false);

    delete[] CopySourceDynamicArray;
    delete[] SourceDynamicArray;
}

void SelectArray() {
    PrintMenu();

    int option{};
    std::cin >> option;

    size_t dynamicArraySize{};
    switch (static_cast<ArrayType>(option)) {
        case ArrayType::Static:
            RunStaticArraySort();
            break;
        case ArrayType::Dynamic:
            std::cout << "Введите длину массива" << '\n';
            std::cin >> dynamicArraySize;
            RunDynamicArraySort(dynamicArraySize);
            break;
        default:
            std::cout << "Введён несуществующий номер задачи" << '\n';
            break;
    }
}

void ExecutionApp() {
    char continueExecution = 'y';

    while (continueExecution == 'y') {
        SelectArray();

        std::cout << "Хотите продолжить работу (y - продолжить, n - закончить): " << '\n';
        std::cin >> continueExecution;
    }  // `
}
}  // namespace SortsArrays
