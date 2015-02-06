#include <cstddef>
using namespace std;
void insertionsort(int array[], size_t size) {
    for(size_t i = 0 ; i < size -1; i++) {
        size_t j = 0; 
        int item = array[j];
        while (j > 0 && item < array[j-1]) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = item;
    }
}
void swap(int array[], size_t l, size_t r) {
    int item = array[r]; 
    array[r] = array[l];
    array[l] = item;         
}


void quicksort(int array[], size_t l, size_t r) {
    if(l < r) { 
        size_t bound = l;
        for (size_t i = l + 1; i < r; i++) { 
            if (array[i] < array[l]) {
                swap(array, i, ++bound);
            }
        }
        swap(array, l, bound);
        quicksort(array, l, bound);
        quicksort(array, bound + 1, r);
    }     
}






