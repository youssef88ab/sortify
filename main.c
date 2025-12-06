#include <stdlib.h>
#include <stdio.h>

// * Swap Function
void swap (int *x , int *y) {
    int temp = *x ;
    *x = *y;
    *y = temp;
}

// * Partition Function
int partition(int *array, int size) {
    int pivot = array[size - 1];
    int i = -1;

    for (int j = 0; j < size - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[size - 1]);

    return i + 1;   // pivot final index
}

// * Bubble Sort
void bubbleSort (int *array , int size) {
    for (int i = 0 ; i < size - 1 ; i++) {
        for (int j = 0 ; j < size - i - 1 ; j++) {
            // Swap Condition
            if (array[j] > array[j+1]) { swap(&array[j] , &array[j+1]); }
        }
    }
}

// * Selection Sort
void selectionSort(int *array , int size) {
    for (int i = 0 ; i < size - 1 ; i++) {
        int minIndex = i;

        // * Find MinIndex
        for (int j = i + 1 ; j < size ; j++) {
            if (array[j] < array[minIndex]) { minIndex = j; }
        }

        // * Swap
        swap(&array[i] , &array[minIndex]);
    }
}

// * Insertion Sort
void insertionSort(int *array , int size) {

    for (int i = 1 ; i < size ; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j -= 1;
        }

        array[j + 1] = key;
    }
}

// * Quick Sort
void quickSort(int *array, int size) {
    if (size <= 1) return;

    int pivotIndex = partition(array, size);

    quickSort(array, pivotIndex);
    quickSort(array + pivotIndex + 1, size - pivotIndex - 1);
}



// * Print Table
void printTable (int *array , int size) {
    printf("[");
    for (int i = 0 ; i < size ; i++) {
        printf(" %d " , array[i]);
    }
    printf("] \n");
}

int main() {
    int array[] = {2 , 3 , 5 , 1 ,7 ,9 ,4 ,6 ,8 ,10};

    printTable(array , 10);
    quickSort(array , 10);
    printTable(array , 10);

    return 0;
}