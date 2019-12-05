//noah hoffman
// proj8.cpp


#include <iostream>
#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main() {

    
    //1.Testing Default ctors

    ArrayList arrayList;
    cout << arrayList << endl;
   
    NodeList nodeList;
    cout << nodeList << endl;


    //2.Testing Parameterized ctor's	
  
    DataType testValue1(100, 150.0);
    DataType testValue2(200, 250.0);
    ArrayList paraArrayTest(10, testValue1);
    cout << paraArrayTest << endl;
    
    NodeList paraNodeTest(10, testValue2);
    cout << paraNodeTest << endl;
    
  
    //3.Testing Copy ctors	

    ArrayList copyArrayTest(paraArrayTest);
    cout << copyArrayTest << endl;
    
    NodeList copyNodeTest(paraNodeTest);
    cout << copyNodeTest << endl;
    
    //4.Testing Dtor's  
     
    DataType nullSet(0, 0.0);
    ArrayList* arrayPtr = new ArrayList(10, nullSet);
    NodeList* nodePtr = new NodeList(20, nullSet);
    
    delete arrayPtr;
    arrayPtr = NULL;
    delete nodePtr;
    nodePtr = NULL;
    
	
    //5.Testing Assignemnt operator             

    DataType assigntestValue1(740, 100.0), assigntestValue2(98, 22.0), assigntestValue3(129, 25.6);
    ArrayList array1(8, assigntestValue1);
    array1 = ArrayList(8, assigntestValue2);
    cout << array1 << endl;
    ArrayList array2(8, assigntestValue2);
    cout << array2 << endl;

    NodeList node1(6, assigntestValue3);
    node1 = NodeList(6, assigntestValue1);
    cout << node1 << endl;
    NodeList node2(6, assigntestValue1);
    cout << node2 << endl;
    
    

    //6 and 7. front and back	             
    
    ArrayList AfirstElement(array1), AlastElement(array1);
    DataType* AshowFront = AfirstElement.front();
    cout << *AshowFront << endl;
    DataType* AshowBack = AlastElement.back();
    cout << *AshowBack << endl;

    NodeList nlFront(node1), nlBack(node1);
    Node* showFnode = nlFront.front();

    if (showFnode != NULL)
    {
        cout << "TRUE" << endl;
    }

    else
    {
        cout << "FALSE" << endl;
    }

    Node* showBnode = nlBack.back();

    if (showBnode != NULL)
    {
        cout << "TRUE" << endl;
    }

    else
    {
        cout << "FALSE" << endl;
    }

    //8.Testing Find 

    DataType* prev_data = NULL;
    DataType* find_data = array1.find(assigntestValue1, prev_data);
    cout << *find_data << endl;
    Node* prev_node = NULL;
    Node* find_node = node1.find(assigntestValue1, prev_node);
    if (find_node != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
  
    //10 and 11. Testing Dtor's?   
 
    
    DataType* insertafter = array1.insertAfter(assigntestValue1, assigntestValue3);
    cout << *insertafter << endl;
    DataType* insertbefore = array1.insertBefore(assigntestValue1, assigntestValue3);
    cout << *insertbefore << endl;

    Node* in_after = node1.insertAfter(assigntestValue1, assigntestValue3);

    if (in_after != NULL)
    {
        cout << "TRUE" << endl;
    }

    else
    {
        cout << "FALSE" << endl;
    }
    Node* in_before = node1.insertBefore(assigntestValue1, assigntestValue3);

    if (in_before != NULL)
    {
        cout << "TRUE" << endl;
    }

    else
    {
        cout << "FALSE" << endl;
    }
    

    //12 and 13. Testing Dtor
  
    DataType* eraser = array1.erase(assigntestValue1);
    cout << *eraser << endl;
    
    cout << "Test1" << endl;
    Node* erasernode = node1.erase(assigntestValue1);
    cout << "Test2" << endl;

    if (erasernode != NULL)
    {
        cout << "TRUE" << endl;
    }

    else
    {
        cout << "FALSE" << endl;
    }

    

    //14. Testing Dtor's?   
  
    cout << array1[2] << endl;
    cout << array2[2] << endl;
    cout << node1[2] << endl;
    cout << node2[2] << endl;
    
 
    //15. Testing Dtor's? 
  
    ArrayList arraysize(21, assigntestValue1);
    cout << arraysize.size() << endl;
    NodeList nodesize(20, assigntestValue1);
    cout << nodesize.size() << endl;

    // Testing Dtor's?  
   
    array1.clear();
    cout << boolalpha << array1.empty() << endl;

    node1.clear();
    cout << boolalpha << node1.empty() << endl;

    array1.clear();

    node1.clear();

    paraArrayTest.clear();

    paraNodeTest.clear();

    copyArrayTest.clear();

    copyNodeTest.clear();

    AfirstElement.clear();

    nlFront.clear();

    AlastElement.clear();

    nlBack.clear();

    return 0;
}
