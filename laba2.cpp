#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int* arr, int size) { 
    while(size !=0){  
        int max_index = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i-1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                max_index = i;
            }
        }
        size = max_index;
    }
}

void InsertionSort(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        int sorted = i - 1;
        while (sorted > -1 && arr[sorted] > arr[sorted + 1]) {
            swap(arr[sorted], arr[sorted + 1]);
            sorted--;
        }
    }
}

int randomPivot(int* arr, int left, int right) { 
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void QuickSort(int* arr, int left, int right) {
    if (left < right) {
        int pivotIndex = randomPivot(arr, left, right);
        QuickSort(arr, left, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, right);
    }
}

void Vivod(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice;
    std::cout << "Варианты сортировок:\n";
    std::cout << "1. Quick Sort\n";
    std::cout << "2. Bubble Sort\n";
    std::cout << "3. Insertion Sort\n";
    std::cout << "Выберите тип сортировки: ";
    std::cin >> choice;

    int sizeArr;
    std::cout << "Введите размер массива: ";
    std::cin >> sizeArr;

    int* arr = new int[sizeArr];
    srand(time(nullptr)); 
    for (int i = 0; i < sizeArr; ++i) {
        *(arr + i) = rand() % 1000;
    }

    std::cout << "Изначальный массив - ";
    Vivod(arr, sizeArr);

    clock_t start = clock();


    switch (choice) {
    case 1:
        QuickSort(arr, 0, sizeArr - 1);
        break;
    case 2:
        BubbleSort(arr, sizeArr);
        break;
    case 3:
        InsertionSort(arr, sizeArr);
        break;
    default:
        std::cout << "Неправильный выбор" << std::endl;
        delete[] arr;
        return 1;
    }

    clock_t end = clock();
    double duration1 = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Отсортированный массив - ";
    Vivod(arr, sizeArr);
    std::cout << std::endl;
    std::cout << "Время выполнения: " << duration1 * 1000 << " мс" << std::endl;
    delete[] arr;
}
