#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n){
  int count = 1; // account for null at end
  int target= 0;
  Node* move = head;
  while(move!=nullptr){//loop counts elemts in LL
    move = move->next;
    count++;
  }
  target = count - n;//allows us to stop when we reach target node
  Node* temp1;
  if(n == count - 1){//if trying to delete head;
    temp1 = head;//temp for head
    head = head->next;//shoft head to new head
    delete temp1;//delete old head
    return;
  }
  Node* crawler = head;
  Node* prev;
  Node* temp;
  int idx = 1;
  while(crawler->next != nullptr){
    if(idx == target - 1){//stop 1 before target node
      temp = crawler->next;//temp(target) set to next node
      crawler->next = crawler->next->next;//link current node to node after target
      delete temp;//delete target node
      return;
    }
    crawler = crawler->next;
    idx++;
  }




}
