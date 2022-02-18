#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  //write your code
  root = nullptr;
}



int printMovieInventoryHelper(TreeNode* currNode, LLMovieNode* head, LLMovieNode* crawler){
  if(currNode){
     printMovieInventoryHelper( currNode->leftChild, head, crawler);
     crawler = currNode->head;
     cout << "Movies starting with letter: "<< currNode->titleChar << endl;
     cout << " >> " <<crawler->title << " "<<crawler->rating << endl;

     while(crawler->next != nullptr){
         crawler= crawler->next;
         cout << " >> " <<crawler->title << " "<<crawler->rating << endl;
     }
     printMovieInventoryHelper( currNode->rightChild, head, crawler);
  }
}




void MovieTree::printMovieInventory() {
   //write your code
   if(root == nullptr){
     //cout <<"Tree is Empty. Cannot print" << endl;
     return;
   }
   LLMovieNode* head;
   LLMovieNode* crawler;
   printMovieInventoryHelper(root, head, crawler);
   //cout << endl;
}

TreeNode* addMovieNodeHelper(TreeNode* currNode, LLMovieNode* movie, LLMovieNode* head, LLMovieNode* crawler,LLMovieNode* prev, int ranking, string title, int year, float rating, char letter){
  if(currNode == NULL){
    TreeNode* newNode = new TreeNode;
    newNode->head = movie;
    newNode->titleChar = letter;
    newNode->parent = NULL;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
  }
  else if(currNode->titleChar == letter){
    crawler = currNode->head;
    prev  == nullptr;
    while(crawler != nullptr){
        if(crawler -> title > title && prev == nullptr){
            movie->next = currNode->head;
            currNode->head = movie;
            break;
        }
        else if(crawler->next != nullptr && (crawler->title < title && crawler->next->title > title)){
            movie->next = crawler->next;
            crawler->next = movie;
            break;
        }
        else if(crawler->next == nullptr){

            crawler -> next = movie;
            break;
        }
        prev = crawler;
        crawler = crawler->next;

    }
  }
  else if(currNode->titleChar < letter){
    currNode->rightChild = addMovieNodeHelper(currNode->rightChild, movie, head, crawler,prev, ranking, title, year, rating, letter);
  }
  else if(currNode->titleChar > letter){
    currNode->leftChild = addMovieNodeHelper(currNode->leftChild, movie, head, crawler, prev, ranking, title, year, rating, letter);
  }
  return currNode;
}

void MovieTree::addMovie(int ranking, string title, int year, float rating) {
  //write your code
  char letter = title.at(0);
  LLMovieNode* prev = nullptr;
  LLMovieNode* head;
  LLMovieNode* crawler = nullptr;
  LLMovieNode* movie = new LLMovieNode(ranking, title, year, rating);
  root = addMovieNodeHelper(root, movie, head, crawler, prev, ranking, title, year, rating, letter);

}

TreeNode* maximumKey(TreeNode* currNode){

  while(currNode->rightChild !=NULL){
    currNode = currNode->leftChild;
  }
  return currNode;
}

TreeNode* deleteMovieHelper(TreeNode* currNode, TreeNode* tempT, TreeNode* prnt,LLMovieNode* head, LLMovieNode* crawler, LLMovieNode* temp, LLMovieNode* prev, char letter, string title){
  crawler = currNode->head;
  prev = nullptr;
  if(currNode->titleChar == letter){
    while(crawler != nullptr){
      if(crawler->title == title && prev == nullptr && crawler->next != nullptr){//head of LL
          temp = currNode->head;
          currNode->head = currNode->head->next;
          delete temp;
          break;
      }
      else if(crawler->title == title && prev == nullptr && crawler->next == nullptr){//delete BST Node
        //delete currNode->head;

        //TODO Case : No child
        if(currNode->leftChild == NULL && currNode->rightChild == NULL){
          delete currNode;
          currNode = NULL;
        }
        //TODO Case : Only right child
        else if(currNode->leftChild == NULL){
          tempT = currNode->rightChild;
          delete currNode;
          return tempT;
        }
        //TODO Case : Only left child
        else if(currNode->rightChild == NULL){
          tempT = currNode->leftChild;
          delete currNode;
          return tempT;
        }
        //TODO Case: Both left and right child
        else{

          prnt = currNode->rightChild;

          tempT= currNode->rightChild;
          while(tempT->leftChild != NULL){
            prnt = tempT;
            tempT = tempT->leftChild;
          }

          prnt->leftChild = tempT->rightChild;
          currNode->head->title = tempT->head->title;
          currNode->titleChar = tempT->titleChar;
          delete tempT;
          return currNode;


        }
        break;
      }
      else if(crawler->next != nullptr && crawler->next->title == title){//middle of LL
          temp = crawler->next;
          crawler->next = crawler->next->next;
          delete temp;
          break;
      }
      else if(crawler->next == nullptr){//end of LL
          delete crawler;
          break;
      }
      prev = crawler;
      crawler = crawler->next;
    }
  }
  else if(currNode->titleChar < letter){
    currNode->rightChild = deleteMovieHelper(currNode->rightChild, tempT, prnt,head, crawler, temp, prev,letter,title);
  }
  else if(currNode->titleChar > letter){
    currNode->leftChild = deleteMovieHelper(currNode->leftChild, tempT , prnt,head, crawler, temp, prev,letter,title);
  }
  //cout << "Movie: " << title << " not found, cannot delete."  << endl;
  return currNode;
}


void MovieTree::deleteMovie(string title){
  if(root == NULL){
      cout << "Movie: " << title << " not found, cannot delete."  << endl;
      return;
  }
  char letter = title.at(0);
  LLMovieNode* prev = nullptr;
  LLMovieNode* head;
  LLMovieNode* temp;
  LLMovieNode* crawler = nullptr;
  TreeNode* tempT;
  TreeNode* prnt;
  root = deleteMovieHelper(root,tempT, prnt ,head, crawler, temp, prev, letter, title);

}

void destroyNode(TreeNode* currNode, LLMovieNode* crawler, LLMovieNode* temp){

  if(currNode == NULL){
    return;
  }

   destroyNode(currNode->leftChild , crawler, temp);

   destroyNode(currNode->rightChild, crawler, temp);

   crawler = currNode->head;
   //cout << currNode->head->title << endl;
   while(crawler != nullptr){
       temp = crawler;

       crawler = crawler->next;
       delete temp;
   }

   delete currNode;



}


MovieTree::~MovieTree() {
  //write your code
  if(root == NULL){

      return;
  }
  LLMovieNode* prev = nullptr;
  LLMovieNode* head;
  LLMovieNode* temp;
  LLMovieNode* crawler = nullptr;
  destroyNode(root, crawler, temp);
  root = NULL;
}
