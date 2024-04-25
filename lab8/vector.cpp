#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief print the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
*/
void printMemVec(vector<int>  &v){
    printf("Vector - each int is worth %lu bytes\n", sizeof(v[0]));
    for(int i =0; i < v.size(); i++){
        printf("Value : %i at Memory Lcation: %p\n", v[i], &v +i);
    }
}

/**
 * @brief increments all of the elemnents in v by 10
 * 
 * @param v - address to a vector of integers
*/
void incVecBy10(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        v[i] += 10;
    }
}

int main(){
    const int SIZE = 5;
    vector<int> vec(SIZE);
    for(int i = 0; i < SIZE; i ++){
        vec[i] = 100 +i;
    }

    printf("Before Increment-----------------\n");
    printMemVec(vec);
    incVecBy10(vec);

    printf("after Increment--------------\n");
    printMemVec(vec);

    vec.pop_back();
     printMemVec(vec);
    printf("After Pop----------------\n");
    
    vec.push_back(101);
    vec.push_back(102);
    printf("After Push----------\n");
    printMemVec(vec);

}
