#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


#include "SLL.hpp"

SLL::SLL(){
  head = nullptr;
}

SLL::~SLL(){

}

Node* SLL::search(string sKey){
  Node* crawler = head;

  While(crawler != nullptr && crawler -> key != sKey){
    crawler = crawler -> next;
  }
  return crawler;

}

void SLL::displayList(){
  Node* crawler = head;
  while(crawler != nullptr){
    cout << crawler-> key << "->";
    crawler = crawler -> next;
  }
  cout << "END" << endl;
}

void SLL::insert(Node* afterMe, string newValue){
  if(head == nullptr){
    //fist case: empty list
    head = new Node;
    head -> key = newValue;
    head -> next = nullptr;
  }
  else if(afterMe == nullptr){
    //insert before head
    //if afterme is nullptr, means user wants to insert new node before
    //the head (beginning of list)
    Node* newNode = new Node;
    newNode -> key = newValue;
    newNode-> next = head;
  }
  else{
    Node* newNode = new Node;
    newNode -> key = newValue;
    newNode -> next = afterMe -> next;
    afterMe->next = newNode;
  }

}

void SLL::deleteNode(){


}


int main(int argc, char* argv[]){


}
