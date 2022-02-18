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

struct wordItem{
  string word;
  int count;

};

cout << "Enter name of the country to receive the message: " << endl;
string countryin = "";
cin >> countryin;
cout << "Enter the message to send: " <<endl;
cout << endl;
string messagein = "";
cin >> messagein;
CountryNet.transmitMsg(countryin, messagein);










void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){
  ifstream file;
  string line= "";
  //file.open(argv[3]);
  file.open(ignoreWordFileName);
  if(file.is_open()){
    int count = 0;
    while(getline(file,line)){
      ignoreWords[count] = line;
      count++;
    }
  }
}

bool isStopWord(string word, string ignoreWords[]){
  bool flag = false;
  for(int i = 0; i < 50; i++){
    if(ignoreWords[i] == word){
      flag = true;
    }
  }
  return flag;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
  int total = 0;
  for(int i = 0; i < length; i++){
    total += uniqueWords[i].count;
  }
  return total;
}
void arraySort(wordItem uniqueWords[], int length){
  string tempword = "";
  int tempcount = 0;
  int tempidx = 0;
  int counter = 0;
  bool flag = false;
  while(counter < length){
    for(int i = counter; i < length; i++){
      if(uniqueWords[i].count > uniqueWords[tempidx].count){
        tempidx = i;
        tempword = uniqueWords[tempidx].word;
        tempcount = uniqueWords[tempidx].count;
        flag = true;
      }
    }
    if(flag == true){
      uniqueWords[tempidx].word = uniqueWords[counter].word;
      uniqueWords[tempidx].count = uniqueWords[counter].count;
      uniqueWords[counter].word = tempword;
      uniqueWords[counter].count = tempcount;
    }
    counter++;
    tempidx = counter;
    flag = false;
  }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
  float prob = 0.0;
  float amt = 0.0;
  float total = 0.0;
  for(int i = N; i < N + 10; i++){
    amt = (float)uniqueWords[i].count;
    total = (float)totalNumWords;
    prob = (amt / total);
    cout<< fixed<<setprecision(4);
    cout << prob << " - " << uniqueWords[i].word << endl;
  }
}

void arrayDouble(wordItem*& inArr, int& n){
  //allocate new array
  wordItem* temp = new wordItem[2*n];

  for (int i = 0; i < n; i++){
    temp[i] = inArr[i];
  }

  delete [] inArr;

  inArr = temp;

  n = 2*n;
}


bool inWordArr(string word, wordItem*& inArr, int length){
  bool flag = false;
  for(int i = 0; i < length; i++){
    if(inArr[i].word == word){
      return true;
    }
  }
  return flag;
}

int getWordIdx(string word, wordItem*& inArr, int length){
  for(int i = 0; i < length; i++){
    if(inArr[i].word == word){
      return i;
    }
  }
}

void addWord(string word, wordItem*& inArr, int length){
  inArr[length].word = word;
  inArr[length].count++;
}

int main(int argc, char* argv[]){
  string ignoreWords[50];
  getStopWords(argv[3], ignoreWords);

  int n = 100;
  int added = 0;
  int doubled = 0;
  wordItem* arr = new wordItem[n]; //allocate

  //fill array of structs
  string word = "";
  int idx = 0;
  ifstream file;
  file.open(argv[2]);
  if(file.is_open()){
    while(getline(file,word,' ')){
      if(added = n){
        arrayDouble(arr, n);
        doubled++;
      }

      if(isStopWord(word, ignoreWords) == true){

      }
      else if(isStopWord(word, ignoreWords) == false){
        if(inWordArr(word, arr, n) == true){
          idx = getWordIdx(word, arr, n);
          arr[idx].count++;
        }
        else if(inWordArr(word, arr, n) == false){
            addWord(word, arr, added);
            added++;
        }
      }
    }
  }
  cout << doubled << endl;
  cout << added << endl;
  cout << getTotalNumberNonStopWords(arr, added) << endl;
  cout << printNext10(arr, argv[1], getTotalNumberNonStopWords(arr, added)) << endl;




}
