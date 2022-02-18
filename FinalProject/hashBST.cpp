#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include "hashBST.hpp"
using namespace std;


node* hashBST::createNode(int key, node* left, node* right, node* parent){
    node* nw = new node;
    nw->key = key;
    nw->left = left;
    nw->right = right;
    nw->parent = parent;
    return nw;
}

int hashBST::split (string str, char c, node* words[])
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
            words[k] = createNode(stoi(word),nullptr, nullptr, nullptr);
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
}

hashBST::hashBST(){
    data1 = "dataSetA.csv";
    data2 = "dataSetC.csv";
    table = new node*[10009];
    for(int i=0;i<10009;i++){
        table[i] = nullptr;
    }
}

float hashBST::getloadfactor(float x){
    return (x/10009);
}

int hashBST::getkey1(int x){
    return data1arr[x]->key;
}

int hashBST::getkey2(int x){
    return data2arr[x]->key;
}

void hashBST::load1(){
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

void hashBST::load2(){
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


int hashBST::hash1(int num){
    return (num % 10009);
}

int hashBST::hash2(int num){
   return  ((num/10009) % 10009);
}

bool hashBST::searchhelp(node* crawler, int num){
    if(crawler == nullptr){
        return false;
    }
    if(crawler->key == num){
        return true;
    }
    else if(crawler->key < num){
        return searchhelp(crawler->right, num);
    }
    else if(crawler->key > num){
        return searchhelp(crawler->left, num);
    }
}

bool hashBST::search(int num){
    int index = hash1(num);
    if(table[index] == nullptr){// if hash index is empty
        return false;
    }
    return searchhelp(table[index], num);//othewise recursively traverse until node is found
}

node* hashBST::inserthelp(node* crawler,int num){
    if(crawler == nullptr){
        node* new1 = createNode(num, nullptr,nullptr, nullptr);
        return new1;
    }
    else if(crawler->key < num){
        crawler->right = inserthelp(crawler->right, num);
    }
    else if(crawler->key > num){
        crawler->left = inserthelp(crawler->left, num);
    }
    return crawler;
}

int hashBST::insert(int num){
    int index = hash2(num);
    node* nn = createNode(num, nullptr, nullptr, nullptr);
    if(table[index] == nullptr){//if hash index is empty, insert new node there
        table[index] = nn;
        return 1;
    }
    if(search(num) == false){//if num is not in table
        table[index] = inserthelp(table[index], num);//recursivekly traverse until proper insertion spot
        return 2;
    }
    else{
        cout << "duplicate entry." << endl;
        return 0;
    }
}

node* minval(node* n){
    node* c = n;
    while(c && c->left != NULL){
        c = c->left;
    }
    return c;
}

node* hashBST::deletehelper(node* curr, node* temp, node* prnt, int num){
    if(curr == NULL){
        return curr;
    }
    if(num < curr->key){//if num is less than node val
        curr->left = deletehelper(curr->left, nullptr, nullptr, num);
    }
    else if(num> curr->key){//if num is greater than node val
        curr->right = deletehelper(curr->right, nullptr, nullptr, num);
    }
    else{
        if(curr->left ==NULL) {//no left child
            temp = curr->right;//assign temp
            delete curr;//delete target
            return temp;
        }
        else if(curr->right == NULL){//no left child
            temp = curr->left;//assign temp
            delete curr;//delete target
            return temp;
        }
        temp = minval(curr->right);//if has both children, find left move value
        curr->key = temp->key;
        curr->right = deletehelper(curr->right, nullptr, nullptr, num);
    }
    return curr;
}

bool hashBST::deletenum(int num){
    node* prnt;
    node* temp;
    node* curr;
    int index = hash2(num);
    if(table[index] == nullptr){//if hash index is empty
        return false;
    }
    if(search(num) == true){//otherwise recursively traverse until target node is found.
        table[index] = deletehelper(table[index], temp, prnt, num);
        return true;
    }
    else{
        return false;
    }
    
}

