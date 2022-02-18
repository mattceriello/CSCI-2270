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

int insertIntoSortedArray(int myArray[100], int numEntries, int newValue){

  bool shift = false;
  if(numEntries == 0){
    myArray[0] = newValue;
    numEntries++;

    cout << to_string(myArray[0]) << endl;


    return numEntries;
  }
  int newidx = 0;
  for(int i = 0; i < 100; i++){
    if(newValue < myArray[i]){
      newidx = i;
      shift = true;
      break;
    }
    else if(newValue > myArray[i] && myArray[i + 1] == 0 && myArray[i + 2] == 0 && myArray[i + 3] == 0 && myArray[i + 4] == 0 ){
        myArray[i + 1] = newValue;
        numEntries++;
        break;
    }
    else if(i == numEntries - 1){
        myArray[i + 1] = newValue;
        numEntries++;
        break;
    }


  }
  if(shift == true){
    for(int j = 99; j > newidx; j--){
      myArray[j] = myArray[j-1];
    }
    myArray[newidx] = newValue;
    numEntries++;
  }

  for(int k = 0; k < numEntries; k++){
    cout << to_string(myArray[k]);
    if(k != numEntries - 1){
      cout << ",";
    }
  }
  cout << endl;

  return numEntries;
}

int main(int argc, char *argv[]){

  int arr[100];
  int idx = 0;
  int entries = 0;
  int added = 0;
  int val = 0;

  string filename;
  ifstream file;
  //cout << "FileContents:" << endl;
  //cin>> filename;
  file.open(argv[1]);
  if(file.is_open()){
    string line = "";

    int current;


    while(getline(file,line)){
      current = stoi(line);
      added = insertIntoSortedArray(arr, entries, current);
      entries = added;

    }



  }
  else{
    cout << "Failed to open the file." << endl;

  }

}
