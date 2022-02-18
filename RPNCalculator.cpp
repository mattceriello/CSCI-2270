#include "RPNCalculator.hpp"
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

RPNCalculator::RPNCalculator(){
  stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){
    while(!isEmpty()){
        pop();
    }
    stackHead = NULL;
}

bool RPNCalculator::isEmpty(){
  return (stackHead == NULL);
}

void RPNCalculator::push(float num){
  Operand* nn = new Operand;
  nn->number = num;
  nn->next = NULL;
  nn->next = stackHead;
  stackHead = nn;

}

void RPNCalculator::pop(){
  if(!isEmpty())
  {
      Operand* temp = stackHead;
      stackHead = stackHead->next;
      delete temp;
  }
  else{
    cout << "Stack empty, cannot pop an item." << endl;
  }

}


Operand* RPNCalculator::peek(){
  if(isEmpty()==false){
    return stackHead;
  }
  else if(isEmpty() == true){
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }

}



bool RPNCalculator::compute(string symbol){
  float num1 = 0.0;
  float num2 = 0.0;
  float total = 0.0;
  Operand* number1;
  Operand* number2;
  if(isEmpty() == true){
    cout << "err: not enough operands" << endl;
    return false;
  }
  number1 = peek();
  num1 = number1->number;
  if(symbol == "+" || symbol == "*"){
    pop();
  }
  if(isEmpty() == true){
    cout << "err: not enough operands" << endl;
    push(num1);
    return false;
  }
  number2 = peek();
  num2 = number2->number;
  if(symbol  == "+" || symbol == "*"){
    pop();
  }
  cout << "Num1 for operation: " << num1 << endl;
  cout << "Num2 for operation: " << num2 << endl;
  if(symbol == "+"){
    total = num1  + num2;
    push(total);
    return true;
  }
  else if(symbol == "*"){
    total = num1 * num2;
    push(total);
    return true;
  }
  else{
    cout << "err: invalid operation" << endl;
    return false;
  }












}
