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


struct Node{
  int key;
  Node* next;
  Node* head;
};

void arrayDouble(int*& a, int& n){
  int* temp = new int[2*n];
  for(int i =0; i < n; i++){
    temp[i] = a[i];
  }
  delete [] a;
  a = temp;
  n= 2*n
}

bool lengthIsEven(Node* head){
  int count = 0;
  Node* crawler = head;
  while(crawler != nullptr){
    count++;
    crawler = crawler->next;
  }
  if(count % 2 == 0){
    return true;
  }
  else{
    return false;
  }
}

void display(Node* head){
  Node* crawler = head;
  while(crawler != nullptr){
    cout << crawler->key << " -> ";
    crawler = crawler->next;
  }
  cout << "NULL" <<endl;
}

Node *deleteNegatives(Node *head){
  Node* crawler;
  Node* temp;
  Node* prev;
  Node* target;
  Node* after;
  if(head->key < 0){
    temp = head;
    head = head-> next;
    delete temp;
  }
  crawler = head;
  while(crawler->next != nullptr){
    if(crawler->next->key < 0){
      prev = crawler;
      target = crawler->next;
      if(crawler->next->next == nullptr){
        prev->next = nullptr;
        crawler->next = nullptr;
      }
      else{
        after = crawler->next->next;
        prev->next = after;
        crawler = after;
      }
      delete target;
    }
    else{
      crawler = crawler->next;
    }
  }
  return head;
}

int main(int argc, char* argv[]){
  Node* temp;
  Node* head;
  Node* prev;
  Node* newHead;
  bool flag = false;
  int arr[] = {-3,9,2,-4};
  int n = 4;
  head = new Node;
  head->key = arr[0];
  head->next = nullptr;
  prev = head;
  for(int i = 1; i < n; i++){
    temp = new Node;
    temp->key = arr[i];
    temp->next = nullptr;
    prev->next = temp;
    prev = temp;
  }

  //display(head);
  //flag = lengthIsEven(head);
  //if(flag == true){
    //cout << "Even" << endl;
  //}
  //else{
    //cout << "Odd" << endl;
  //}
  newHead = deleteNegatives(head);
  //display(newHead);

  int b = 5;
  int *a;
  a = &b;
  cout << b << endl;//5
  cout << *a << endl;//5
  *a = 4 * b;
  cout << b << endl;//20
  cout << *a << endl;//20







}
