/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

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

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[]){
	ProducerConsumer pc;
	int choice = 0;
	string input = "";
	int count = 0;
	int enq = 0;
	int deq = 0;
	while(choice != 3){
		menu();
		cin >> choice;
		if(choice == 1){
			count = 0;
			cout << ​"Enter the number of items to be produced:"​ << endl;
			cin >> enq;
			while(count<enq){
				cout << ​"Item"​ << count + 1 << ​":"​ << endl;
				cin >>input;
				pc.enqueue(input);
				count++;
			}
		}
		else if(choice == 2){
			count = 0;
			cout << ​"Enter the number of items to be consumed:"​ << endl;
			cin >> deq;
			while(count < deq){
				cout << "Consumed: " << pc.peek() << endl;
				pc.dequeue();
				count++;
				if(pc.isEmpty()){
					cout << "No more items to consume from queue" << endl;
					count = 10000;
				}
			}
		}
		else if(choice == 3){
			cout << "Number of items in the queue:" << pc.queueSize() << endl;
		}





	}
}
