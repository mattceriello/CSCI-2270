#include "MovieTree.hpp"
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
void displayMenu(){
   cout << "======Main Menu======" << endl;
   cout << "1. Print the inventory" << endl;
   cout << "2. Delete a movie" << endl;
   cout << "3. Quit" <<  endl;
}

int main(int argc, char* argv[]){
  MovieTree m;
  ifstream file;
  file.open(argv[1]);
  if(file.is_open()){
    string line = "";
    string linearr[4];
    while(getline(file,line)){
      split(line, ',' , linearr, 4);
      m.addMovie(stoi(linearr[0]), linearr[1], stoi(linearr[2]), stof(linearr[3]));
    }
  }
  string answer = "";
  while(answer != "3"){
    displayMenu();
    cin >> answer;
    if(answer == "1"){
      m.printMovieInventory();
    }
    else if(answer == "2"){
      string intitle = "";
      cout << "Enter a movie title:" << endl;
      cin.ignore();
      getline(cin,intitle);
      m.deleteMovie(intitle);
    }
    else if(answer == "3"){
      cout << "Goodbye!" << endl;
      return 0;
    }
  }




}
