#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#ifndef finalLP_HPP
#define finalLP_HPP



class hashLP{
    
    private:
        string data1;//filenames
        string data2;
        int tablesize = 10009;
        int table[10009];//hashtable
        int data1arr[40000];//arrays to read files
        int data2arr[40000];
        
    
    public:
        int key;
        hashLP();
        float getloadfactor(float x);//calc load factor
        int getkey1(int x);
        int getkey2(int x);
        void load1();//load files
        void load2();
        int hash1(int num);//hash functions
        int hash2(int num);
        bool insert(int num);//
        bool search(int num);
        bool deletenum(int num);
        void del100();
        void searchrand();
        
        
};
#endif
