//noah hoffman
//proj11.cpp

#include <iostream>
#include <fstream>

#include <vector>

#include "VectorRecursion.h"
using namespace std;

int main(){

  // Vector creation
  vector<int> vecInt;
  
  // Vector population with input values
  ifstream fin("RandomData.txt");
  while(fin){
    int fin_in;
    fin >> fin_in;
    if (!fin)
      break;
    vecInt.push_back( fin_in );
  }

  // Vector indexing and output ( using operator[] or at() )
  for (size_t i=0; i<vecInt.size(); ++i){
    cout << vecInt[i] << " same as " << vecInt.at(i) << endl; 
  }
  
  // Vector indexing and output ( using iterator )
  for (vector<int>::iterator it=vecInt.begin(); it!=vecInt.end(); ++it){
    cout << *it << endl; 
  }

  return 0;
}
