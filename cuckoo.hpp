#ifndef CUCKOO_HPP
#define CUCKOO_HPP
#include <string>
using namespace std;

class cuckoo{
    private:
        string data1;
        string data2;
        int tablesize = 10009;
        int table[2][10009];//2d hash table
        int idx[2];//array to hold hashing indexes
        int data1arr[40000];
        int data2arr[40000];
    
    public:
        cuckoo();
        float getloadfactor(float x);
        int split (string str, char c, int words[40000]);
        void load1();
        void load2();
        int getkey1(int x);
        int getkey2(int x);
        int hash(int func, int num);
        void insert(int num, int hashnum, int run, int limit);
        bool deletenum(int num);
        bool search(int num);
        void cuckoo1(int arr, int n);
        int getsize();
        void setsize(int num);
       
};
#endif