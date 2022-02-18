#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
using namespace std;


struct Node{
  int key;
  Node* next;
};






int main(){
  int arr [] = {15,12,14};
  int n = 3;
  Node* head, * previous, * temp;
  head = new Node;
  head -> key = arr[0];
  head -> next = nullptr;
  previous = head;

  for(int i = 1; i < n; i++){
    temp = new Node;
    temp -> key = arr[i];
    temp -> next = nullptr;
    previous  -> next = temp;
    previous = temp;

  }




}
