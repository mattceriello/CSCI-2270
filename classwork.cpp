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


struct student {
  string name;
  int age
};

struct Node{
  int someData;
  Node* next;
};
//not pointing to itself. Rather, pointing to its own type



int main(void){
  Node* n0 = new Node;
  Node* n1 = new Node;
  n0->someData = 3;
  n1->someData = 5;
  n0 -> next = n1;
  n1 -> next = nullptr;


}
