// CPP program to implement hashing with chaining
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include "hash.hpp"
using namespace std;

node* HashTable::createNode(int key, node* next){
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

int HashTable::split (string str, char c, node* words[])
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
            words[k] = createNode(stoi(word),nullptr);
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
}

HashTable::HashTable(){
    data1 = "dataSetA.csv";
    data2 = "dataSetC.csv";
    for(int i=0;i<10009;i++){
        table[i] = nullptr;
    }
}

float HashTable::getloadfactor(float x){
    return (x/10009);
}

int HashTable::getkey1(int x){
    return data1arr[x]->key;
}

int HashTable::getkey2(int x){
    return data2arr[x]->key;
}

void HashTable::load1(){
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

void HashTable::load2(){
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


int HashTable::hash1(int num){
    return (num % 10009);
}

int HashTable::hash2(int num){
   return  ((num/10009) % 10009);
}

node* HashTable::search(int num){
    int index = hash2(num);//calc hash index
    node* crawler = table[index];//set crawler to LL head
    while(crawler != nullptr){//traverse until node is found
        if(crawler->key == num){
            return crawler;
        }
        else{
            crawler = crawler->next;
        }
    }
    return nullptr;
}


int HashTable::insert(int num){
    node* crawler;
    node* head;
    node* prev = nullptr;
    if(search(num) == nullptr){//if dooesnt. exist in table
       int index = hash2(num);
       head = table[index];
       if(head == nullptr){//if table at index is empty,, add node there
           head = createNode(num, nullptr);
           table[index] = head;
           return 2;
       }
       crawler = head;
       while(crawler != nullptr){//otherwise, traverse down LL until null
           prev = crawler;
           crawler = crawler->next;
       }
       node* nn = createNode(num, nullptr);//insert new 
       prev->next = nn;
       return 1;
     }
    else{
        cout  << "dup:" << num<<endl; 
        return 0;
    }

}

bool HashTable::deletenum(int num){
    node* crawler;
    node* loc;
    node* head;
    node* prev = nullptr;
    if(search(num) != nullptr){//if num is in table
        int index = hash2(num);//calc hash index
        head = table[index];
        loc = search(num);
        if(loc == head){//if target node is LL head
            head = head->next;
            delete loc;//delete
            return true;
        }
        else{//otherwise traverse until matching LL node is found
            crawler = head;
            while(crawler->next != loc){
                crawler = crawler->next;
            }
            crawler->next = crawler->next->next;
            delete loc;
            return true;
        }
        
        
        
    }
    else{
        return false;
    }
    
}




