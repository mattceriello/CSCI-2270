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
}




int main(int argc, char* argv[]){
  int arr[] = {15,12,14};
  int N = 3;

  Node* head,* previous,* temp;

  head = new Node;
  head->key = arr[0];
  head->next = nullptr;
  previous = head;

  for(int i = 1; i< N; i++){
    temp = new Node;
    temp->key = arr[i];
    temp->next = nullptr;
    previous->next = temp;
    previous = temp;
  }

}
