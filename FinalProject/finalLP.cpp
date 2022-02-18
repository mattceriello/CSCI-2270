#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include "finalLP.hpp"
#include <vector>
using namespace std;

int split (string str, char c, int words[])//helper function to help read file
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    int k = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[k] = stoi(word);
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
}


hashLP::hashLP(){//constructor
    data1 = "dataSetA.csv";
    data2 = "dataSetC.csv";
    for(int i = 0; i < 10009; i++){
        table[i] = -1;
    }
}

float hashLP::getloadfactor(float x){
    return (x/10009);
}

int hashLP::getkey1(int x){
    return data1arr[x];
}

int hashLP::getkey2(int x){
    return data2arr[x];
}

void hashLP::load1(){//load files
    string line;
    ifstream file;
    file.open(data1);
    if(file.is_open()){
        getline(file,line);
        split(line,',',data1arr);
    }
    else{
        cout << "error" << endl;
    }
}

void hashLP::load2(){
    string line;
    ifstream file;
    file.open(data2);
    if(file.is_open()){
        getline(file,line);
        split(line,',',data2arr);
    }
    else{
        cout << "error" << endl;
    }
}

int hashLP::hash1(int num){//H(x)
    return (num % 10009);
}

int hashLP::hash2(int num){//H'(X)
   return  ((num/tablesize) % tablesize);
}

bool hashLP::search(int num){
    int index1 = hash1(num);//calc hash index
    if(table[index1] == num){//if num in table
        return true;
    }
    if(table[index1] != num){//if not at hash index
        for(int i =0; i< 10009; i++){//check for linear probing
            if(table[i] == num){//if found
                return true;
            }
        }
    }
    return false;
}

bool hashLP::insert(int num){
    if(search(num) == false){ //check if number doesnt already exist
        int index = hash1(num);  //calc index
        while(table[index] != -1){//apply linear probing
            if(index == 10008){
                index = 0;
            }
            else{
                index++;
            }
        }
        table[index] = num;
        return true;
    }
    else{
        cout << "Error. Duplicate input" << endl;
        return false;
    }
}

bool hashLP::deletenum(int num){
    if(search(num) == true){//check if num exists
        int index = hash1(num);//calc index
        while(table[index] != num){//traverse array until target num 
            if(index == 10008){//loop index back to 0 at end of table
                index = 0;
            }
            else{
                index++;
            }
        }
        table[index] = -1;//set target number to -1
        return true;
    }
    else{
        //cout << "not in table" << endl;
    }
    
}

void hashLP::del100(){
    for(int i = 0; i < 100; i++){
        table[i] = -1;
    }
}


 






