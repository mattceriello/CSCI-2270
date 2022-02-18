#include "ProducerConsumer.hpp"
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



ProducerConsumer::ProducerConsumer(){
  queueFront = 0;
  queueEnd = 0;

}

bool ProducerConsumer::isEmpty(){
  return(queueSize() == 0);
}

bool ProducerConsumer::isFull(){
  return(queueSize() ==  SIZE);
}

void ProducerConsumer::enqueue(string item){
  if(!isFull()){
    counter++;
    queue[queueEnd] = item;
    queueEnd = (queueEnd+1)% SIZE;
  }
  else{
    cout << "Queue full, cannot add new item" <<endl;
  }

}

void ProducerConsumer::dequeue(){
  if(!isEmpty()){
    queueFront = (queueFront+1)% SIZE;
    counter--;
  }
  else{
    cout << "Queue empty, cannot dequeue an item" <<endl;
  }

}

string ProducerConsumer::peek(){
  if(isEmpty() == true){
    cout << "Queue empty, cannot peek" <<endl;
  }
  return queue[queueFront];

}

int ProducerConsumer::queueSize(){
  return counter;
}
