#include<iostream>
#include<string>
using namespace std;

/*
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
	//Implement this function
  int evenidx = 0;
  int oddidx = 0;
  for(int i = 0; i < size; i++){//gather amount of evens
    if(arr[i]%2 == 0){
      even_size++;
    }
    else if(arr[i]%2==1){//gather amount of odds
      odd_size++;
    }
  }
  for(int j = 0; j < size; j++){//if element in arr is even, add to even_arr
    if(arr[j]%2 == 0){
      even_arr[evenidx] = arr[j];//place even value in even array
      evenidx++;//increase even array index by 1
    }
    else if(arr[j]%2==1){//if element in arr is odd, add to odd_arr
      odd_arr[oddidx] = arr[j];//place even value in even array
      oddidx++;//increase odd array index by 1
    }
  }
}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
    int evensize = 0;
    int oddsize = 0;
    int *evenarr = new int[evensize];//dynamically allocate even array
    int *oddarr = new int[oddsize];//dynamically allocate odd array

	// Call your function with new arrays:
    split(arr, evenarr, oddarr, size, evensize, oddsize);

	// Output
  cout << "even array: ";
  printArray(evenarr,evensize);
  cout << "odd array: ";
  printArray(oddarr, oddsize);

	// Clean up (delete)
    delete [] arr;
    delete [] evenarr;
    delete [] oddarr;

    return 0;
}
