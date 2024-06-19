#include <iostream>
#define SIZE 10

void displayArray(int array[]) {
    for (int i = 0; i < SIZE; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

int findMaximum(int array[]) {
    int max = array[0];
    for (int i = 0; i < SIZE; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int findMinimum(int array[]) {
    int min = array[0];
    for (int i = 0; i < SIZE; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

float calculateAverage(int array[]) {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += array[i];
    }
    float average = (float) sum / SIZE;
    return average;
}

void enterDataIntoArray(int array[]) {
    printf("Enter data into array:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
}

void displayResults(int min, int max, float average) {
    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);
    printf("Average value = %f\n", average);
}

int main() {
    int array[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};
    printf("Simple array\n");

    enterDataIntoArray(array);
    displayArray(array);
    int max = findMaximum(array);
    int min = findMinimum(array);
    float average = calculateAverage(array);
    displayResults(min, max, average);

    return 0;
}
