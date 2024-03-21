int main(){
    coust int SAMPLE_SIZE = 10;
    int array_int[SAMPLE_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    string array_str[SAMPLE_SIZE] = {"This","is","a","sentence.",
    "This","is","another","sentence","The","end"
    };

    char array_char[SAMPLE_SIZE] ={'a','b','c','d','e','0','1','2'
    ,'3','4'};

    string int_file = "array_int.csv";

    writeToFile(int_file, array_int, SAMPLE_SIZE);

    
}