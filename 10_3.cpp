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


int f(int a, int* b, int &c){
  a = a+2;
  *b = *b + 2;
  c = c+2;
}

int func(int * a){
  a[0] = 2;
}


int main(int argc, char argv[]){
  int a = 1;
  int b = 2;
  int c = 3;
  f(a, &b, c);

  int arr[3] = {1,1,2};

  func(arr);
  cout << a << " " << b << " " << c << endl;
  cout << arr[0] << endl;






}
