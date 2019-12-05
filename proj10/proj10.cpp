// Noah Hoffman
//CS202


#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"

class DataType{

friend std::ostream & operator<<(std::ostream & os, const DataType & dataType);
friend std::istream & operator>>(std::istream & is, DataType & dataType);

  public:
    DataType();
    DataType(int intVal, double doubleVal);
	DataType(const DataType & other);
	
    bool operator==(const DataType & rhs) const;
    DataType & operator= (const DataType & rhs);
    
    int getIntVal() const;
    void setIntVal(int i);  
    double getDoubleVal() const;
    void setDoubleVal(double d);

  private:
    int m_intVal;
    double m_doubleVal;
};



int main()
{
  //DEFAULT CTOR															
	ArrayStack<int> aempty;
	NodeStack<int> nempty;
	
	std::cout << "Default ctors\nArrayStack: " << aempty
			  << "NodeStack: " << nempty << std::endl;
			  
  //PARAMETERIZED CTOR 														
	DataType garbage(8, 8.0);
	DataType alsogarbage(12, 12.0);
	ArrayStack<int> gettingsomewhere(5, 1);
	NodeStack<int> alsogettingsomewhere(20, 3);
	
	std::cout << "Parameterized ctors\nArrayStack: " 
			  << gettingsomewhere << "NodeStack: " << alsogettingsomewhere	
			  << std::endl;
	
  //COPY CTOR 															
	ArrayStack<int> cat(gettingsomewhere);
	NodeStack<int> kitty(alsogettingsomewhere);
	
	std::cout << "Copy ctors\nArrayStack: " << cat << "NodeStack: "
			  << kitty << std::endl;

  //ASSIGNMENT OPERATOR 													
	std::cout << "Assignemnt operator: Changing default to copy.\nOld "
			  << "ArrayStack: " << aempty;
	aempty = cat;
	std::cout << "New ArrayStack: " << aempty;
	
	std::cout << "\nOld NodeStack: " << nempty;
	nempty = kitty;
	std::cout << "New NodeStack: " << nempty;

  //TOP FUNCTION															
	DataType value(13, 13.0);
	DataType nodeValue(26, 26.0);
	ArrayStack<int> aTop(4, 8);
	NodeStack<int>  nTop(1, 5);
	
	std::cout << "\nTop value of stack:\nArrayStack: " << aTop.top()
			  << "\nNodeStack: " << nTop.top() << std::endl;
	
  //PUSH FUNCTION 															
	DataType aPush(10,10.0);
	DataType nPush(11, 11.0);
	aTop.push(3);
	nTop.push(44);
	
	std::cout << "\nPush function:\nArrayStack: " << aTop << "NodeStack: "
			  << nTop << std::endl;
			 
  //POP FUNCTION															
	std::cout << "Pop function:\nOld ArrayStack: " << aTop  
			  << "Old NodeStack: " << nTop;
	aTop.pop();
	nTop.pop();
	std::cout << "New ArrayStack: " << aTop << "New NodeStack: " << nTop;
	
  //SIZE FUNCTION															
	std::cout << "\nSize function:\nArrayStack: " << aTop.size() 
			  << "\nNodeStack: " << nTop.size() << std::endl;

  //EMPTY FUNCTION															
	ArrayStack<int> empty;
	NodeStack<int>  notfull;
	
	std::cout << "\nTesting empty function:\nEmpty ArrayStack: " << std::boolalpha
			  << empty.empty() << "\nRegular Array Stack: " << std::boolalpha
			  << aTop.empty() << "\nEmpty NodeStack: " << std::boolalpha 
			  << notfull.empty() << "\nRegular NodeStack: " << std::boolalpha
			  << nTop.empty() << std::endl;
		  
  //FULL FUNCTION															
	ArrayStack<int> full(999, 1);
	NodeStack<int> neverfull(1001, 2);
	std::cout << "\nTesting full function:\nFull ArrayStack: " 
			  << std::boolalpha << full.full() << "\nRegular ArrayStack: " 
			  << std::boolalpha << aTop.full() << "\nNodeStacks have no limit, "
			  << "NodeStack of size 1001: " << std::boolalpha 
			  << neverfull.full() << std::endl;
			  		  
  //CLEAR FUNCTION															
	std::cout << "\nClear function:\nFull ArrayStack: ";
	full.clear();
	std::cout << full << "\nNodeStack: ";
	neverfull.clear();
	std::cout << neverfull << std::endl;
	
	

	std::cout << "Tests Done!" << std::endl;
	

	return 0;
}




DataType::DataType()
 : m_intVal(0),
   m_doubleVal(0)
{
}

DataType::DataType(int intVal, double doubleVal)
 : m_intVal(intVal),
   m_doubleVal(doubleVal)
{
}

DataType::DataType(const DataType & other)
 : m_intVal(other.m_intVal),
   m_doubleVal(other.m_doubleVal)
{
}
	
bool DataType::operator==(const DataType& rhs) const{
  return m_intVal==rhs.m_intVal && m_doubleVal==rhs.m_doubleVal;
}

DataType& DataType::operator=(const DataType& rhs){
  if (this != &rhs){
    m_intVal = rhs.m_intVal;
    m_doubleVal = rhs.m_doubleVal;
  }
  return *this;
}

int DataType::getIntVal() const{
  return m_intVal;
}

void DataType::setIntVal(int i){
  m_intVal = i;
}

double DataType::getDoubleVal() const{
  return m_doubleVal;
}



void DataType::setDoubleVal(double d){
  m_doubleVal = d;
}


std::ostream & operator<<(std::ostream& os, const DataType & dt){
  os << "{" << dt.m_intVal << "," << dt.m_doubleVal << "}";
  return os;
}



std::istream & operator>>(std::istream & is, DataType & dt){
  char in_buf[255];
  is >> in_buf;
  dt.m_doubleVal = atof(in_buf);
  dt.m_intVal = (int)dt.m_doubleVal;
  dt.m_doubleVal -= dt.m_intVal;
  return is;
}

