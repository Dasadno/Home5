#include <iostream>
#include <vector>
#include <Windows.h>


void generateRandomArray(std::vector<int>& arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; 
    }
}

void bubbleSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            if (j == 0) break; 
            --j;
        }
        arr[j + 1] = key;
    }
}

void printArray(const std::vector<int>& arr) {
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << '\n';
}

int main() {
    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arraySize = 10;
    std::vector<int> arr(arraySize); 


    generateRandomArray(arr, arraySize);
    std::cout << "Сгенерированный массив:\n";
    printArray(arr);

   
    std::vector<int> arrBubble = arr; 
    bubbleSort(arrBubble);
    std::cout << "Отсортированный массив пузырьком:\n";
    printArray(arrBubble);

  
    std::vector<int> arrSelection = arr; 
    selectionSort(arrSelection);
    std::cout << "Отсортированный массив выбором:\n";
    printArray(arrSelection);

 
    std::vector<int> arrInsertion = arr; 
    insertionSort(arrInsertion);
    std::cout << "Отсортированный массив вставками:\n";
    printArray(arrInsertion);

    return 0;
}