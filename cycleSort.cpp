#include <iostream>

void cycleSort(int arr[], int n) {
    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;

        // Find the position where we put the element
        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // If the element is already in the correct position
        if (pos == cycleStart) {
            continue;
        }

        // Otherwise, put the element to the correct position
        while (item == arr[pos]) {
            pos++;
        }

        std::swap(item, arr[pos]);

        // Rotate the rest of the cycle
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            while (item == arr[pos]) {
                pos++;
            }

            std::swap(item, arr[pos]);
        }
    }
}

int main() {
    int arr[] = {5, 2, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    cycleSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
