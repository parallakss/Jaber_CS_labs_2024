#include <iostream>

namespace SortsArrays{
void SelectArray();

void ExecutionApp();

void RunSelectionSort(int& , int& , size_t, int*, bool);
void RunBubbleSort(int& , int& , int*, size_t, bool);

void RunStaticArraySort();
void RunDynamicArraySort(size_t);

}

enum class ArrayType {
    Static = 1,
    Dynamic
};
