#include <stdio.h>   // Standard Input/Output header file (needed for printf, scanf, etc.)

// ------------------------- SWAP FUNCTION -------------------------
// Function to swap two numbers (used later in partitioning)
void swap(int *a, int *b) {
    int temp = *a;   // Store value of *a in temporary variable
    *a = *b;         // Copy value of *b into *a
    *b = temp;       // Copy stored value from temp into *b
    // After this, values at *a and *b are exchanged
}

// ------------------------- PARTITION FUNCTION -------------------------
// Partition function: rearranges elements and places pivot in correct position

int partition(int arr[], int low, int high) {
    int pivot = arr[low];   // Assume first element as pivot --> element itself
    int i = low;            // Start pointer i from the beginning (left side) -- Index
    int j = high;           // Start pointer j from the end (right side) -- Index

    // Continue until the two pointers cross
    while (i < j) {
        // Move i to the right until we find an element greater than the pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;   // keep incrementing i until condition breaks
        }
        
        // Move j to the left until we find an element smaller or equal to pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;   // keep decrementing j until condition breaks
        }

        // If i and j have not crossed, swap the elements at i and j
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }


    
    // Finally, swap pivot with element at j → pivot is now in correct place
    swap(&arr[low], &arr[j]);

    return j;   // Return the index where pivot has been placed
}

// ------------------------- QUICKSORT FUNCTION -------------------------
// Recursive function to apply quick sort on sub-arrays
void quickSort(int arr[], int low, int high) {

    if (low < high) {  

        /* m will give us a new pivot which would be partition the array in such a way
        that left side elements will be smaller than pivot and right side elements will be 
        bigger than pivot */

        int m = partition(arr, low, high);  // initially - partition(arr, 0, 5) 

        // Recursively sort the left half (elements before pivot)
        quickSort(arr, low, m - 1);

        // Recursively sort the right half (elements after pivot)
        quickSort(arr, m + 1, high);
    }
}

// ------------------------- MAIN FUNCTION -------------------------
// Entry point of C Program

void main() {
    // Initial unsorted array
    int arr[] = {34, 7, 23, 32, 5, 62};

    // Calculate number of elements in array
    // sizeof(arr) gives total bytes of array → 24 (6 * 4)
    // sizeof(arr[0]) gives bytes of one element → 4
    // n = 24/4 = 6
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    printf("Original array: ");
    for (int i = 0; i <= n-1; i++) {




        printf("%d ", arr[i]);
    }
    printf("\n");

    // Apply Quick Sort on entire array (from index 0 to n-1)
    quickSort(arr, 0, n - 1); // quickSort(arr, 0, 5) -- 6 array elements

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i <= n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

  // End of program
}


/* Time Complexixty 

Best - O(n log n)
Worst - O(n²)

*/
