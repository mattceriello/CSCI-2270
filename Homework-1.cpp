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

int split (string str, char c, string words[], int length)
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
            words[k] = word;
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
}

struct Park {
  string parkname;
  string state;
  int area;

};

void printList(const Park parks[100], int length){
  for(int i = 0; i < length; i++){
    cout << parks[i].parkname <<  " [" << parks[i].state << "] area: " << to_string(parks[i].area) << endl;
  }
}



void addPark(Park parks[100], string parkname1, string state1, int area1, int length){
  parks[length].parkname =  parkname1;
  parks[length].state = state1;
  parks[length].area = area1;
}

int main(int argc, char* argv[]){
  Park parks[100];
  string parkname = "";
  string state = "";
  string area = "";
  int length = 0;
  int count = 0;
  string line = "";
  string linearr[3];

  //string filename;
  ifstream file;
  file.open(argv[1]);
  ofstream ofile;
  ofile.open(argv[2]);
  if (file.is_open()){
    while(getline(file,line)){
      split(line, ',' , linearr, 3);
      addPark(parks, linearr[0], linearr[1], stoi(linearr[2]), length);
      length++;
    }

    printList(parks, length);
  }
  if(ofile.is_open()){
    for(int j = 0; j < length; j++){
      if(parks[j].area >= atoi(argv[3])){
        ofile << parks[j].parkname << "," << parks[j].state << "," << parks[j].area << "\n";
      }
    }


  }





}
