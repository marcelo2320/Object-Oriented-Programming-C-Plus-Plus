#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;


/**
 * @brief return the first index of elem if it exists otherwise return -1
 * iterativeSearch starts at the frist index and iterates sequentially to the next until it either
 * finds the element or until it reaches th end
 * 
 * @param v : vector of elements
 * @param elem : integer to look for
 * @return int 
*/
int iterativeSearch(vector<int>v, int elem){
   
    for( int i = 0; i < v.size(); i++){
        if (v[i] == elem){
            return i;
        }
    }
    return -1;
    }

/**
 * @brief returms the index of elem, if it exists in v. otherwise it
 * returns -1
 * binarySearch is recursive (i.e. function calls itself).
 * it utilizes the fact that v is increasing order 
 * (e.g. values go up and duplicates are not allowed)
 * 
 * @param v : vector of elements
 * @param start : leftmost index( start value is 0)
 * @param end : rightmost index (starting value is v.size())
 * @param elem : integer to look for
 * @return int
*/
int binarySearch(vector<int> & v, int start, int end, int elem){
    if ( start > end){
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (v[mid] == elem){
        return mid;
    }
    else if (elem < v[mid]){
        return binarySearch(v, start, mid - 1, elem);
    } 
    else {return binarySearch(v,  mid + 1, end, elem);}
}
/**
 * @brief update v to contain the values from filename ( leave as is)
 * 
 * it is expected that the file contain values ranging from one to
 * one hundred million in ascending order (no duplicates).
 * 
 * @param filename : string
 * @param v : vector
*/
void vecGen(string filename, vector<int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while(file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

int main(){
    // populate v with 10000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // test through all 10 of the test_elem values and calls iterative search
    // and records how long each search took ( leave as is )
    for(int i = 0; i < v[i]; i++){
        // gets the elem to search for
        int elem = v[i];

        //stopwatches the time
        clock_t start = clock();                     // start time
        int index_if_found = iterativeSearch(v, elem); // call search
        clock_t end = clock();                        // end time

        // calculates the total time it took in seconds
        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

        //prints the index and how long it took to find it
        cout << index_if_found << ":" <<elapsed_time_in_sec << endl;
    }
    for(int i = 0; i < 10; i++) {
        int elem_to_find = v[i];

        clock_t start = clock ();
        int index_if_found = binarySearch(v, 0, v.size() - 1, elem_to_find);
        clock_t end = clock();

        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

        cout << index_if_found << ":" << elapsed_time_in_sec << endl;

    }
}