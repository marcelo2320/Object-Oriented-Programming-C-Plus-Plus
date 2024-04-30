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
void vecGen(string file_name, vector<int> & v){
    ifstream file(file_name);
    int num;
    v.clear();
    while(file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

void writeTime(string filename, const vector<double> time, const vector<int> n){
        ofstream myFile(filename);

        myFile << "Number if Elements (n)\t Time (sec) " << endl;
        for( int i = 0; i < time.size(); i++){

            myFile << n[i] << "\t" << time[i] << "\n";
    }
    myFile.close();
    cout << "wrote to " << filename << endl;
    }

double average(const vector<double> a){
     if (a.empty()){
        return 0.0;
     }
     double sum = 0.0;
     size_t i = 0;
     while (i < a.size()){
        sum = a[i];
        i++;
     }
return sum /static_cast<double>(a.size());
     
}


int main(){
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    vector<int>v;

    vector<double> times;

    vector<double> avg;

    for(int i = 0; i < file_sizes.size(); i++){
        string file_name = to_string(file_sizes[i]) + "_numbers.csv";
        vecGen(file_name, v );
        times.clear();

        for (int j = 0; j < elem_to_find.size(); j++){
            int elem = elem_to_find[j];
            double elapsed_time_in_sec = iterativeSearch(v,elem);
            times.push_back(elapsed_time_in_sec);
        }

        double average_time = average (times);
        avg.push_back(average_time);
    }

        writeTime("iterativeSearch_times.csv", avg, file_sizes);
        
    avg.clear();

    for (int i = 0; i < file_sizes.size(); i++){
         string file_name = to_string(file_sizes[i]) + "_numbers.csv";
        vecGen( file_name, v);
        times.clear();
         for (int j = 0; j < elem_to_find.size(); j ++){

            int elem = elem_to_find[j];
            double elapsed_time_in_sec = binarySearch(v, 0, v.size(), elem);

            times.push_back(elapsed_time_in_sec);
         }
         double avergae_time = average(times);
         avg.push_back(average(times));
         
    writeTime("binarySearch_times.csv", avg, file_sizes);

    }
    return 0;
    } 
   