/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
 CountryNetwork::CountryNetwork()
 {
   head = nullptr;

 }


 /*
  * Purpose: Add a new Country to the network
  *   between the Country *previous and the Country that follows it in the network.
  * @param previous name of the Country that comes before the new Country
  * @param countryName name of the new Country
  * @return none
  */
 void CountryNetwork::insertCountry(Country* previous, string countryName)
 {
   if(head == nullptr){
     //fist case: empty list
     head = new Country;
     head -> name = countryName;
     head -> next = nullptr;
     cout << "adding: " << countryName << " (HEAD)" << endl;
   }
   else if(previous == nullptr){
     //insert at beginning
     Country* newCountry = new Country;
     newCountry -> name = countryName;
     newCountry -> next = head;
     head = newCountry;
     cout << "adding: " << countryName << " (HEAD)" << endl;
   }
   else{
     Country* newCountry = new Country;
     newCountry-> name = countryName;
     newCountry-> next = previous-> next;
     previous->next = newCountry;
     cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
   }
 }

 /*
  * Purpose: populates the network with the predetermined countries
  * @param none
  * @return none
  */
 void CountryNetwork::loadDefaultSetup()
 {
   Country* previous;
   insertCountry(NULL, "United States");
   //cout << head->name << endl;
   previous = searchNetwork("United States");
   insertCountry(previous, "Canada");

   previous = searchNetwork("Canada");
   insertCountry(previous, "Brazil");

   previous = searchNetwork("Brazil");
   insertCountry(previous, "India");

   previous = searchNetwork("India");
   insertCountry(previous, "China");

   previous = searchNetwork("China");
   insertCountry(previous, "Australia");

 }

 /*
  * Purpose: Search the network for the specified country and return a pointer to that node
  * @param countryName name of the country to look for in network
  * @return pointer to node of countryName, or NULL if not found
  */
 Country* CountryNetwork::searchNetwork(string countryName)
 {
   Country* crawler = head;
   while(crawler != nullptr && crawler -> name != countryName){
     crawler = crawler -> next;
   }
   return crawler;
 }


 /*
  * Purpose: prints the current list nicely
  * @param ptr head of list
  */
 void CountryNetwork::printPath()
 {
   cout << "== CURRENT PATH ==" << endl;
   Country* crawler = head;
   if(head == nullptr){
     cout << "nothing in path" << endl;
     cout <<"==="<<endl;
     return;
   }
   while(crawler != nullptr){
     cout << crawler-> name << " -> ";
     crawler = crawler -> next;
   }
   cout << "NULL" << endl;
   cout <<"==="<<endl;
 }

void CountryNetwork::deleteCountry(string countryName){
  Country* loc;
  Country* crawler;
  loc = searchNetwork(countryName);
  if(loc == NULL){
    cout << "Country does not exist." << endl;
  }
  else if(loc == head){
    head = head-> next;
    delete loc;
  }
  else{
    crawler = head;
    while(crawler->next!= loc){
      crawler = crawler->next;
    }
    crawler->next = crawler->next->next;
    delete loc;
  }
 }

 void CountryNetwork::deleteEntireNetwork(){
   Country* crawler;
   if(head == nullptr){
     return;
   }
   while(head!=nullptr){
     crawler= head-> next;
     cout << "deleting: " << head->name << endl;
     delete head;
     head = crawler;
   }
   //cout << "hello" << endl;
   head = nullptr;
   cout << "Deleted network" << endl;
 }

void CountryNetwork::reverseEntireNetwork(){
  Country* crawler = head;
  Country *prev = NULL, *next = NULL;
  while(crawler != NULL){
    next = crawler-> next;
    crawler-> next = prev;
    prev = crawler;
    crawler = next;
  }
  head = prev;
}

bool CountryNetwork::isEmpty(){
  if(head == nullptr){
    return true;
  }
  return false;
}


void CountryNetwork::rotateNetwork(int n){
  Country* move = head;

  int count = 0;
  while(move != nullptr){
    move = move -> next;
    count++;
  }
  //cout << count << endl;

  if(head == nullptr){
    cout << "Linked List is Empty" << endl;
    return;
  }
  else if(n > count || n < 1){
    cout << "Rotate not possible" << endl;
  }
  else{
    Country* first = head;
    Country* last = head;

    for(int i = 0; i < n; i++){
        while(last->next != nullptr){
            last = last-> next;
        }
        head= first->next;
        first->next = nullptr;
        last->next = first;
        last = head;
        first = head;
    }
    cout << "Rotate Complete" << endl;
  }


}
