#include <iostream>
#include <fstream>
#include <string>
#include "debug.h"

using namespace std;

class getInputData
{
  public:
    fstream myInputFile;
    string line;
    int myTestArray[MAX_ARRAY_SIZE];
    int pos1, pos2;
    const char *myInputFileURL;
    void displayLines()
    {
      myInputFile.open(myInputFileURL);
      if (myInputFile.is_open())
      {
        while (getline(myInputFile, line))
        {
          cout << line << '\n';
        }
        myInputFile.close();
      }
      else cout << '\n' << "unable to open" << '\n';
    };
    void buildTestArray()
    {
      pos1 = 0;
      myInputFile.open(myInputFileURL);
      if (myInputFile.is_open())
      {
        getline(myInputFile, line);
        for (int x=0; x<=MAX_ARRAY_SIZE; x++)
    	  {
    	    if (pos1 <= line.length())
    	    {
    	      pos2 = line.find(" ", pos1);
    	      //myTestArray[x]=std::stoi(line.substr(pos1, pos2-pos1).c_str());
    	      cout << myTestArray[x] << '\n';
    	      pos1 = pos2 + 1;
    	    }
    	    else return;
    	  }
        myInputFile.close();
      }
      else cout << '\n' << "unable to open" << '\n';
    }
};
/****************************************************************************/
class heapNode
{
  int nodeValue, leftChild, rightChild, nodeParrent;
  public:
    heapNode(int value)
    {
      nodeValue = value;
    }
};

class heap
{
  int heapSize, heapLength; 
  //int myTestArray[MAX_ARRAY_SIZE];
  public:
    heap()
    {
      heapSize = 0;
      heapLength = 0;
    }
    heap(int myArray[])
    {
      heapSize = 0;
      heapLength = MAX_ARRAY_SIZE;
    }

    int left(int i)
    {
      return 2*i;
    }
    int parrent(int i)
    {
      return i/2;
    }
    int right(int i)
    {
      return 2*i+1;
    }

    void maxHeapify(int A[], int pos)
    {
      int largest;
      if (left(pos) <= heapSize and A[left(pos)] > A[pos])
        largest = left(pos);
      else
        largest = pos;
      if (right(pos) <= heapSize and A[right(pos)] > A[pos])
        largest = right(pos);
      if (largest != pos)
      {
        //exchange myArray[pos] with myArray[largest]
        int buffer = A[pos];
        A[pos] = A[largest];
        A[largest] = buffer;
        maxHeapify(A, largest);
      }
    }
    void buildMaxHeap(int A[])
    {
      heapSize = MAX_ARRAY_SIZE;
      for (int i=(heapSize/2); i>0; i--)
        maxHeapify(A, i);
    }
};

int main()
{
  getInputData myTestData;
  myTestData.myInputFileURL = "input.txt";
  myTestData.displayLines();
  myTestData.buildTestArray();
  heap myFirstHeap(myTestData.myTestArray);
  myFirstHeap.buildMaxHeap(myTestData.myTestArray);
  return 0;
}