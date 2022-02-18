#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable{
    
    private:  
        string data1;
        string data2;
        node* table[10009];// Pointer to an array containing buckets
        node* createNode(int key, node* next);//create node
        node* data1arr[40000];
        node* data2arr[40000];
        
    public:
        HashTable();
        float getloadfactor(float x);
        int split (string str, char c, node* words[40000]);
        void load1();
        void load2();
        int hash1(int key);
        int hash2(int key);
        int getkey1(int x);
        int getkey2(int x);
        node* search(int key);
        int insert(int key);
        bool deletenum(int key);
        void del100();
};
#endif
