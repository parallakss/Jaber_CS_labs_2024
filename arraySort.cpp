#include "arraySort.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <span>

namespace {
const int kStaticArraySize = 10;
const int kMinimumElementValue = 0;
const int kMaximumElementValue = 99;
const int kMinElementDefoltValue = 100;

void ArrayGenerator(int* array, int arrayLength) {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(kMinimumElementValue, kMaximumElementValue);
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = distribution(randomEngine);
    }
}
}  // namespace
void PrintArray(int comparisons, int permutations, int* resultArray, int arrayLength) {
    if (arrayLength <= kStaticArraySize) {
        std::cout << "--  после сортировки:    ";
        for (int i : std::span(resultArray, arrayLength)) {
            std::cout << i << "\t";
        }
        std::cout << '\n' << "--" << '\n';
    }

    std::cout << "--  количество сравнений = " << comparisons << '\n'
              << "--  количество перестановок = " << permutations << '\n'
              << "----------------------------------------------------------------------------------------------------------" << '\n';
}

void SelectionSort(int* permutations, int* comparisons, int arrayLength, int* source) {
    int minElem = kMinElementDefoltValue;
    int position{};
    for (int i{}; i < arrayLength; ++i) {
        for (int j = i; j < arrayLength; ++j) {
            if (source[j] < minElem) {
                minElem = source[j];
                position = j;
            }
        }
        if (source[i] != source[position]) {
            *permutations += 1;
        }
        *comparisons += 1;
        std::swap(source[i], source[position]);
        minElem = kMinElementDefoltValue;
    }
    PrintArray(*comparisons, *permutations, source, arrayLength);

    minElem = kMinElementDefoltValue;
    *comparisons = 0;
    *permutations = 0;
    for (int i{}; i < arrayLength; ++i) {
        for (int j = i; j < arrayLength; ++j) {
            if (source[j] < minElem) {
                minElem = source[j];
                position = j;
            }
        }
        if (source[i] != source[position]) {
            *permutations += 1;
        }
        *comparisons += 1;
        std::swap(source[i], source[position]);
        minElem = kMinElementDefoltValue;
    }
    PrintArray(*comparisons, *permutations, source, arrayLength);

    int maxElem = -1;
    *comparisons = 0;
    *permutations = 0;
    for (int i{}; i < arrayLength; ++i) {
        for (int j = i; j < arrayLength; ++j) {
            if (source[j] > maxElem) {
                maxElem = source[j];
                position = j;
            }
        }
        if (source[i] != source[position]) {
            *permutations += 1;
        }
        *comparisons += 1;
        std::swap(source[i], source[position]);
        maxElem = -1;
    }
    PrintArray(*comparisons, *permutations, source, arrayLength);
}

void BubbleSort(int* permutations1, int* comparisons1, int* source, int arrayLength) {
    for (int i{}; i < arrayLength - 1; i++) {
        for (int j{}; j < arrayLength - i - 1; j++) {
            *comparisons1 += 1;
            if (source[j] > source[j + 1]) {
                std::swap(source[j], source[j + 1]);
                *permutations1 += 1;
            }
        }
    }
    PrintArray(*comparisons1, *permutations1, source, arrayLength);

    *comparisons1 = 0;
    *permutations1 = 0;
    for (int i{}; i < arrayLength - 1; i++) {
        for (int j{}; j < arrayLength - i - 1; j++) {
            *comparisons1 += 1;
            if (source[j] > source[j + 1]) {
                std::swap(source[j], source[j + 1]);
                *permutations1 += 1;
            }
        }
    }
    PrintArray(*comparisons1, *permutations1, source, arrayLength);

    *comparisons1 = 0;
    *permutations1 = 0;
    for (int i{}; i < arrayLength - 1; i++) {
        for (int j{}; j < arrayLength - i - 1; j++) {
            *comparisons1 += 1;
            if (source[j] < source[j + 1]) {
                std::swap(source[j], source[j + 1]);
                *permutations1 += 1;
            }
        }
    }
    PrintArray(*comparisons1, *permutations1, source, arrayLength);
}

void RunStaticArraySort() {
    int SourceStaticArray[kStaticArraySize]{};
    ArrayGenerator(SourceStaticArray, kStaticArraySize);
    std::cout << "----------------------------------------------------------------------------------------------------------" << '\n';
    std::cout << "--  массив до сортировки:    ";
    for (int i : SourceStaticArray) {
        std::cout << i << "\t";
    }
    std::cout << '\n';
    int CopySourceStaticArray[kStaticArraySize]{};
    std::copy(SourceStaticArray, SourceStaticArray + kStaticArraySize, CopySourceStaticArray);
    int permutations{};
    int comparisons{};
    SelectionSort(&permutations, &comparisons, kStaticArraySize, SourceStaticArray);
    std::cout << "----------------------------------------------------------------------------------------------------------" << '\n';
    std::cout << "--  массив до сортировки:    ";
    for (int i : CopySourceStaticArray) {
        std::cout << i << "\t";
    }
    std::cout << '\n';
    int permutations1{};
    int comparisons1{};
    BubbleSort(&permutations1, &comparisons1, CopySourceStaticArray, kStaticArraySize);
}

void RunDynamicArraySort(int arrayLength) {
    int* SourceDynamicArray = new int[arrayLength]{};
    ArrayGenerator(SourceDynamicArray, arrayLength);
    int* CopySourceDynamicArray = new int[arrayLength]{};
    std::copy(SourceDynamicArray, SourceDynamicArray + kStaticArraySize, CopySourceDynamicArray);
    if (arrayLength < kStaticArraySize) {
        std::cout << "----------------------------------------------------------------------------------------------------------" << '\n';
        std::cout << "--  массив до сортировки:    ";
        for (int i : std::span(SourceDynamicArray, arrayLength)) {
            std::cout << i << "\t";
        }
        std::cout << '\n';
    }
    int permutations{};
    int comparisons{};
    SelectionSort(&permutations, &comparisons, arrayLength, SourceDynamicArray);
    delete[] SourceDynamicArray;
    if (arrayLength < kStaticArraySize) {
        std::cout << "----------------------------------------------------------------------------------------------------------" << '\n';
        std::cout << "--  массив до сортировки:    ";
        for (int i : std::span(CopySourceDynamicArray, arrayLength)) {
            std::cout << i << "\t";
        }
        std::cout << '\n';
    }
    int permutations1{};
    int comparisons1{};
    BubbleSort(&permutations1, &comparisons1, CopySourceDynamicArray, arrayLength);
    delete[] CopySourceDynamicArray;
}

void PrintMenu() {
    std::cout << "1 - Статический массив" << '\n';
    std::cout << "2 - Динамический массив" << '\n';
    std::cout << "Введите номер задачи: " << '\n';
}

void selectArraySort() {
    char continueExecution = 'y';

    while (continueExecution == 'y') {
        PrintMenu();
        int option{};
        std::cin >> option;
        int dynamicArraySize{};
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
        std::cout << "Хотите продолжить работу (y - продолжить, n - закончить): " << '\n';
        std::cin >> continueExecution;
    }
}
