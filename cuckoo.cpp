#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>
#include <chrono>
#include <ratio>
#include "cuckoo.hpp"
using namespace std;

int cuckoo::split (string str, char c, int words[])
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

cuckoo::cuckoo(){
    data1 = "dataSetA.csv";
    data2 = "dataSetC.csv";
    for(int j = 0; j < 10009; j++){
        for(int i =0; i < 2; i++){
            table[i][j] = -1;
        }
    }
}


float cuckoo::getloadfactor(float x){
    return (x/tablesize);
}

int cuckoo::getkey1(int x){
    return data1arr[x];
}

int cuckoo::getkey2(int x){
    return data2arr[x];
}

int cuckoo::getsize(){
    return tablesize;
}

void cuckoo::setsize(int num){
    tablesize = num;
}

void cuckoo::load1(){
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

void cuckoo::load2(){
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

int cuckoo::hash(int func,int num){
    switch(func){
        case 1: return (num%tablesize);
        case 2: return ((num/tablesize)%tablesize);
    }
}

bool cuckoo::search(int num){
    for(int i = 0; i < 2; i++){
        idx[i] = hash(i+1, num);//calc both hash indexes
        if(table[i][idx[i]] == num){//check if weither equals num
            return true;
        }
    }
    
}

bool cuckoo::deletenum(int num){//same as search excpet sey num to -1
    for(int i = 0; i < 2; i++){
        idx[i] = hash(i+1, num);
        if(table[i][idx[i]] == num){
            table[i][idx[i]] == -1;
            return true;
        }
    }
}

void cuckoo::insert(int num, int hashnum, int run, int limit){
    if(run == limit){//times run = max amt 
        cout<< "Cycle Present. Rehash" << endl;
        return;
    }
    if(search(num) == true){//if duplicate
        return;
    }
    if(table[hashnum][idx[hashnum]] != -1){//check num occupies hash index
        int oldnum = table[hashnum][idx[hashnum]];//move old num
        table[hashnum][idx[hashnum]] = num;//replace new num
        run++;
        insert(oldnum, (hashnum+1)%2, run, limit);//insert old num else where
    }
    else{//if empty, insert
        table[hashnum][idx[hashnum]] = num;
    }
    
}

void cuckoo::cuckoo1(int arr, int n){//essentially a main function for this class,
    using namespace std::chrono;//.    same functionality as other mains
    int randnums[100];
    srand(time(0));
    for(int i = 0; i < 100; i++){
         randnums[i] = rand();
    }
    int count = 0;
    int run = 0;
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    bool flag4 = false;
    bool flag5 = false;
    bool flag6 = false;
    if(arr == 1){
      for(int i = 0; i < 40000; i++){
        insert(data2arr[i], 0, run, 40000);
        count++;
        if(getloadfactor(count) >= 0.1 && flag1 == false){
            flag1 = true;
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for(int j = 0; j < 100; j++){
                insert(randnums[j],0, run, 40000);
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "execution time: " << time_span.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t3 = high_resolution_clock::now();
            for(int l = 0; l < 100; l++){
                search(randnums[l]);
            }
            high_resolution_clock::time_point t4 = high_resolution_clock::now();
            duration<double> time_span1 = duration_cast<duration<double>>(t4 - t3);
            cout << "execution time: " << time_span1.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t5 = high_resolution_clock::now();
            for(int k = 0;k < 100; k++){
                deletenum(randnums[k]);
            }
            high_resolution_clock::time_point t6 = high_resolution_clock::now();
            duration<double> time_span2 = duration_cast<duration<double>>(t6 - t5);
            cout << "execution time: " << time_span2.count()/100.0 << endl;
            cout << endl;
        }
        
        if(getloadfactor(count) >= 0.2 && flag2 == false){
            flag2 = true;
            high_resolution_clock::time_point t7 = high_resolution_clock::now();
            for(int m = 0; m < 100; m++){
                insert(randnums[m],0, run, 40000);
            }
            high_resolution_clock::time_point t8 = high_resolution_clock::now();
            duration<double> time_span3 = duration_cast<duration<double>>(t8 - t7);
            cout << "execution time: " << time_span3.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t9 = high_resolution_clock::now();
            for(int n = 0; n < 100; n++){
                search(randnums[n]);
            }
            high_resolution_clock::time_point t10 = high_resolution_clock::now();
            duration<double> time_span4 = duration_cast<duration<double>>(t10 - t9);
            cout << "execution time: " << time_span4.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t11 = high_resolution_clock::now();
            for(int o = 0;o < 100; o++){
                deletenum(randnums[o]);
            }
            high_resolution_clock::time_point t12 = high_resolution_clock::now();
            duration<double> time_span5 = duration_cast<duration<double>>(t12 - t11);
            cout << "execution time: " << time_span5.count()/100.0 << endl;
            cout << endl;
        }
        
        if(getloadfactor(count) >= 0.5 && flag3 == false){
            flag3 = true;
            high_resolution_clock::time_point t13 = high_resolution_clock::now();
            for(int p = 0; p < 100; p++){
                insert(randnums[p],0, run, 40000);
            }
            high_resolution_clock::time_point t14 = high_resolution_clock::now();
            duration<double> time_span6 = duration_cast<duration<double>>(t14 - t13);
            cout << "execution time: " << time_span6.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t15 = high_resolution_clock::now();
            for(int q = 0; q < 100; q++){
                search(randnums[q]);
            }
            high_resolution_clock::time_point t16 = high_resolution_clock::now();
            duration<double> time_span7 = duration_cast<duration<double>>(t16 - t15);
            cout << "execution time: " << time_span7.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t17 = high_resolution_clock::now();
            for(int r = 0;r < 100; r++){
                deletenum(randnums[r]);
            }
            high_resolution_clock::time_point t18 = high_resolution_clock::now();
            duration<double> time_span8 = duration_cast<duration<double>>(t18 - t17);
            cout << "execution time: " << time_span8.count()/100.0 << endl;
            cout << endl;
        }
        
        if(getloadfactor(count) >= 0.7 && flag4 == false){
            flag4 = true;
            high_resolution_clock::time_point t19 = high_resolution_clock::now();
            for(int s = 0; s < 100; s++){
                insert(randnums[s],0, run, 40000);
            }
            high_resolution_clock::time_point t20 = high_resolution_clock::now();
            duration<double> time_span9 = duration_cast<duration<double>>(t20 - t19);
            cout << "execution time: " << time_span9.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t21 = high_resolution_clock::now();
            for(int t = 0; t < 100; t++){
                search(randnums[t]);
            }
            high_resolution_clock::time_point t22 = high_resolution_clock::now();
            duration<double> time_span10 = duration_cast<duration<double>>(t22 - t21);
            cout << "execution time: " << time_span10.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t23 = high_resolution_clock::now();
            for(int u = 0;u < 100; u++){
                deletenum(randnums[u]);
            }
            high_resolution_clock::time_point t24 = high_resolution_clock::now();
            duration<double> time_span11 = duration_cast<duration<double>>(t24 - t23);
            cout << "execution time: " << time_span11.count()/100.0 << endl;
            cout << endl;
        }
        
        if(getloadfactor(count) >= 0.9 && flag5 == false){
            flag5 = true;
            high_resolution_clock::time_point t25 = high_resolution_clock::now();
            for(int v = 0; v < 100; v++){
                insert(randnums[v],0, run, 40000);
            }
            high_resolution_clock::time_point t26 = high_resolution_clock::now();
            duration<double> time_span17 = duration_cast<duration<double>>(t26 - t25);
            cout << "execution time: " << time_span17.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t27 = high_resolution_clock::now();
            for(int w = 0; w < 100; w++){
                search(randnums[w]);
            }
            high_resolution_clock::time_point t28 = high_resolution_clock::now();
            duration<double> time_span12 = duration_cast<duration<double>>(t28 - t27);
            cout << "execution time: " << time_span12.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t29 = high_resolution_clock::now();
            for(int x = 0;x < 100; x++){
                deletenum(randnums[x]);
            }
            high_resolution_clock::time_point t30 = high_resolution_clock::now();
            duration<double> time_span13 = duration_cast<duration<double>>(t30 - t29);
            cout << "execution time: " << time_span13.count()/100.0 << endl;
            cout << endl;
            
        }
        
        if(getloadfactor(count) >= 1.0 && flag6 == false){
            flag6 = true;
            high_resolution_clock::time_point t31 = high_resolution_clock::now();
            for(int y = 0; y < 100; y++){
                insert(randnums[y],0, run, 40000);
            }
            high_resolution_clock::time_point t32 = high_resolution_clock::now();
            duration<double> time_span14 = duration_cast<duration<double>>(t32 - t31);
            cout << "execution time: " << time_span14.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t33 = high_resolution_clock::now();
            for(int z = 0; z < 100; z++){
                search(randnums[z]);
            }
            high_resolution_clock::time_point t34 = high_resolution_clock::now();
            duration<double> time_span15 = duration_cast<duration<double>>(t34 - t33);
            cout << "execution time: " << time_span15.count()/100.0 << endl;
            //------------------------------------------------------------------
            high_resolution_clock::time_point t35 = high_resolution_clock::now();
            for(int a = 0;a < 100; a++){
                deletenum(randnums[a]);
            }
            high_resolution_clock::time_point t36 = high_resolution_clock::now();
            duration<double> time_span16 = duration_cast<duration<double>>(t36 - t35);
            cout << "execution time: " << time_span16.count()/100.0 << endl;
            cout << "load factor reached" << endl;
            
            
        }
        }
    }
    else{
        for(int i = 0, run = 0; i > n; i++, run = 0){
            insert(data2arr[i], 0, run, n);
        }
    }
}
