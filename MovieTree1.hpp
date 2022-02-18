#include <string>

using namespace std;

struct MovieNode{
    int ranking;
    string title;
    int year;
    float rating;

    MovieNode* left = NULL;
    MovieNode* right = NULL;

    MovieNode(int rank, string t, int y, float r) {
        title = t;
        ranking = rank;
        year = y;
        rating = r;
    }

};


class MovieTree{
    private:
        MovieNode* root;


    public:

        MovieTree();

        ~MovieTree();

        void printMovieInventory();

        void addMovieNode(int ranking, std::string title, int year, float rating);

        void findMovie(std::string title);

        void queryMovies(float rating, int year);

        void averageRating();
};

TreeNode* findMax(TreeNode* currNode){
  if(currNode == NULL){
    return NULL;
  }
  while(currNode->rightChild != NULL){
    currNode = currNode->rightChild;
  }
  return currNode;

}

TreeNode* deleteMovieHelper(TreeNode* currNode, TreeNode* tempT ,LLMovieNode* head, LLMovieNode* crawler, LLMovieNode* temp, LLMovieNode* prev, char letter, string title){
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
        delete currNode->head;
        //TODO Case : No child
        if(currNode->leftChild == NULL && currNode->rightChild == NULL){
          delete currNode;
          currNode = NULL;
        }
        //TODO Case : Only right child
        else if(currNode->leftChild == NULL){
          tempT = currNode;
          currNode = currNode->rightChild;
          delete tempT;
        }
        //TODO Case : Only left child
        else if(currNode->rightChild == NULL){
          tempT = currNode;
          currNode = currNode->leftChild;
          delete tempT;
        }
        //TODO Case: Both left and right child
        else{
          ///Replace with Minimum from right subtree
          tempT = findMax(currNode->leftChild);
          currNode->titleChar = tempT->titleChar;
          currNode->leftChild = deleteMovieHelper(currNode->leftChild, tempT,head, crawler, temp, prev, tempT->titleChar, title);
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
    currNode->rightChild = deleteMovieHelper(currNode->rightChild, tempT,head, crawler, temp, prev,letter,title);
  }
  else if(currNode->titleChar > letter){
    currNode->leftChild = deleteMovieHelper(currNode->leftChild, tempT ,head, crawler, temp, prev,letter,title);
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
  root = deleteMovieHelper(root,tempT ,head, crawler, temp, prev, letter, title);

}
