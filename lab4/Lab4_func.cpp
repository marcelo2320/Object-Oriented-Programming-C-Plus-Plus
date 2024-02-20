#include <iostream>
using namespace std;

// SumOfThree function
int sumOfThree(int x, int y, int z){

    return x+y+z;
}
// Division function
 double division(double x, double y){
    return x/y;
 }
 // IsGreaterThan function    
 bool isGreaterThan(double x, int y){
    if (x>y){
        return true;
    }
    else{
        return false;
    }  
}
 // Select function   
 string select(string func_type){
    string out="";
    if(func_type == "sum"){
        out = "The sum is\n";     
    }
    else if (func_type == "division"){
        out = "The quotient is\n";
    }
    else if (func_type == "comparison"){
        out = "The first value being greater than the second value is\n";
    }
    else{
        out ="Invalid function type\n";
    }   
    return out;
 }
// MyPrint function
template <typename T>
void myPrint(string func_type, T output){
    cout << select(func_type) << output << endl;
}

int main()
{

    // initialize 3 int parameters 
    int x1 = 2;
    int x2 = 3;
    int x3 = 5;

    // call sumOfThree
    int sum_out = sumOfThree(x1, x2, x3);
    // call myPrint
    myPrint("sum", sum_out);

    // initialize 2 double parameters 
    double dividend = 12345.1;
    double divisor = 2345.6;

    // call division
    double div_out = division(dividend, divisor);
    myPrint("division", div_out);

    // compare div_out and sum_out
    bool is_greater_out = isGreaterThan(div_out, sum_out);
    myPrint("comparison", is_greater_out);
    return 0;
}


