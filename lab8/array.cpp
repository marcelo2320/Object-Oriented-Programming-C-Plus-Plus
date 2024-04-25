#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief print the elements in the array and their memory location
 * 
 * @param arr - array of integerrs
 * @param size - the number of elemnts in the array
*/

void printMemarr(const int * arr, int size){
    printf("Array - each int is worth %lu bytes\n", sizeof(arr[0]));
    for(int i =0; i < size; i++){
        printf("Value : %i at Memory Lcation: %p\n", arr[i], arr +i);
    }
}

void incArrBy10(int * arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] += 10;
    }
}

int main(){
    const int SIZE = 5;
    int arr[SIZE];
    for(int i = 0; i < SIZE; i ++){
        arr[i] = 100 +i;
    }

    printf("Before--------------\n");
    printMemarr(arr, SIZE);
    incArrBy10(arr, SIZE);
    printf("After--------------\n");
    printMemarr(arr, SIZE);
    return 0;
}
