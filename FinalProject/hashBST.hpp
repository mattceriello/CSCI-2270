#ifndef HASHBST_HPP
#define HASHBST_HPP
#include <string>
using namespace std;

struct node
{
    int key;
    struct node* left;
    struct node* right;
    struct node* parent;
};

class hashBST{
    private:
        string data1;
        string data2;
        node* *table;//pointer to hash table
        node* createNode(int key, node* left, node* right, node* parent);
        node* data1arr[40000];
        node* data2arr[40000];
    
    
    public:
        hashBST();
        float getloadfactor(float x);
        int split (string str, char c, node* words[40000]);
        void load1();
        void load2();
        int hash1(int key);
        int hash2(int key);
        int getkey1(int x);
        int getkey2(int x);
        bool search(int key);
        bool searchhelp(node* crawler, int num);
        int insert(int key);
        node* inserthelp(node* crawler,int num);
        bool deletenum(int num);
        node* deletehelper(node* crawler, node* temp, node* prnt, int num);
       
};
#endif