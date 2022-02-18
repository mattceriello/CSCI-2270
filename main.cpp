/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"

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
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network " << endl;
    cout << " 6. Rotate Network " << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)

    CountryNetwork CountryNet;
    string answer = "";

    while(answer != "8"){
      displayMenu();
      cin >> answer;
      if(answer == "1"){
        CountryNet.loadDefaultSetup();
        CountryNet.printPath();
      }
      else if(answer == "2"){
        CountryNet.printPath();
      }
      else if(answer == "3"){
        cout << "Enter a new country name:" << endl;
        string newname = "";
        cin>> newname;
        cout << "Enter the previous country name (or First): " << endl;
        string prevname = "";
        cin >> prevname;

        if(prevname == "First"){
            CountryNet.insertCountry(nullptr, newname);
            CountryNet.printPath();
        }
        else{

            Country* temp;
            temp = CountryNet.searchNetwork(prevname);
            while(temp == NULL){
            cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
            cin >> prevname;
            temp = CountryNet.searchNetwork(prevname);
            }
            CountryNet.insertCountry(temp, newname);
            CountryNet.printPath();
        }
      }
      else if(answer == "4"){

        cout << "Enter a country name:" << endl;
        string name = "";
        cin.ignore();
        getline(cin,name);

        CountryNet.deleteCountry(name);
        CountryNet.printPath();
      }
      else if(answer == "5"){
        CountryNet.reverseEntireNetwork();
        CountryNet.printPath();

      }
      else if(answer == "6"){
        int num = 0;
        cout << "Enter the count of values to be rotated:" << endl;
        cin>> num;
        CountryNet.rotateNetwork(num);
        CountryNet.printPath();
      }
      else if(answer == "7"){
        cout << "Network before deletion" << endl;
        CountryNet.printPath();
        CountryNet.deleteEntireNetwork();
        cout << "Network after deletion" << endl;
        CountryNet.printPath();
      }
      else if(answer =="8"){
        cout << "Quitting... cleaning up path:" << endl;
        CountryNet.printPath();
        CountryNet.deleteEntireNetwork();
        if(CountryNet.isEmpty() == true){
          cout << "Path cleaned" << endl;
        }
        else{
          cout << "Error: Path NOT cleaned" << endl;
        }
        cout << "Goodbye!" << endl;
        return 0;
      }
    }

    return 0;
}


/*
 * Purpose; displays a menu with options
 */
