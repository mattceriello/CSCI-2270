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


void Swap(int& x, int y){
  int temp = x;
  x = y;
  y = temp;

}





int main(void){
  int m = 1, n = 2;
  int *pm = &m, *pn = &n, *r;
  r = pn;
  pn = pm;
  *pm = *pn + 2;
  cout << m << "," << n << "," << *r << "," <<*pm << endl; 



}
