//noah hoffman
//Array list implemetation

#include <iostream>
#include "ArrayList.h"
#include <cstring>
using namespace std;


//Default Ctor
ArrayList::ArrayList()
{
	m_array = NULL;
	m_size = 0;
	m_maxsize = 0;
	cout << "ArrayList default ctor test. VALUES: \n " << this << endl; 
}								    		

//parameterized Ctor
ArrayList::ArrayList(size_t count, const DataType & value): m_size(count), m_maxsize(count)
{
	size_t i = 0;
	m_array = NULL;
	m_array = new DataType[m_maxsize];
	
	while (i != m_maxsize){
		m_array[i] = value;
		i++;
	}
	
	cout << "ArrayList parameterized ctor test. VALUES: \n " << this << endl; 

}										

//Copy Ctor
ArrayList::ArrayList(const ArrayList & other): m_size(other.m_size), m_maxsize(other.m_maxsize)
{
	size_t i = 0;
	m_array = NULL;
	m_array = new DataType[m_size];
	while (i != m_maxsize){
		m_array[i] = other.m_array[i];
		i++;
	}
	
	cout << "ArrayList copy ctor test. VALUES: \n " << this << endl; 
}	


//Destructor				    
ArrayList::~ArrayList()
{
	clear();
	
	cout << "Array dtor test, he's dead Jim" << endl; 
	
}							    		


// Other methods
DataType * ArrayList::front()
{
	cout << "ArrayList front function test." << endl; 
	
	if(m_array != NULL){
		return &m_array[0];
	}else{
		cout << "List is empty" << endl;
		return NULL;
	}
	
}								     	

DataType * ArrayList::back()
{
	cout << "ArrayList back function test." << endl; 
	if(m_array != NULL){
		return &m_array[m_size];
	}else{
		cout << "List is empty" << endl;
		return NULL;
	}
}							            
	
DataType * ArrayList::find(const DataType & target, DataType * & previous)
{
	cout << "Finding values" << endl;
	DataType* arrayPtr = m_array;
    if (arrayPtr != NULL)
    {
		size_t i = 0;
        while (i < m_size)
        {
            if (*arrayPtr == target)
            {
                arrayPtr--;
                if (arrayPtr != NULL)
                {
                    previous = arrayPtr;
                }
                else
                {
                    previous = NULL;
                }
                arrayPtr++;
                return arrayPtr;
            }
            i++;
            arrayPtr++;
        }
    }
    previous = NULL;
    return NULL;
}										
	
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value)
{
	cout << "inserting after" << endl;
	size_t i = 0;
	DataType *curr = m_array;
	while(curr != NULL){
		if (target == *curr){
			for (size_t k = m_size - 1; k > i; k--){
					m_array[k] = m_array[k - 1];
				}
				m_array[i + 1] = value;
				*curr = m_array[i + 1];
				return curr; 
			}
			i++;
			curr++;
	}
	if (empty()){
		m_array[0] = value;
        *curr = m_array[0];
        m_size++;
        return curr;
	}
	return NULL;
	
	
}
	 
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value)
{
	cout << "inserting before" << endl;
	size_t i = 0;
	DataType *curr = m_array;
	while(curr != NULL){
		if (target == *curr){
			for (size_t k = m_size - 1; k > i; k--){
					m_array[k] = m_array[k - 1];
				}
				m_array[i] = value;
				return curr; 
			}
			i++;
			curr++;
	}
	if (empty()){
		m_array[0] = value;
        *curr = m_array[0];
        m_size++;
        return curr;
	}
	return NULL;
	
	
}

DataType * ArrayList::erase(const DataType & target)
{
	cout << "erasing value target" << endl;
	size_t counter = 0;
	DataType *curr = m_array;
	while(curr != NULL){
		if (target == *curr){
			for(size_t i = counter; i < m_size; i++){
				m_array[i-1] = m_array[i];
			}
			if(counter == 0){
				return m_array;
			}
			else{
				return curr--;
			}
		}
		curr++;
		counter++;
	}
	return NULL;
	
}		


//Operators
ArrayList & ArrayList::operator= (const ArrayList & rhs)
{
	if (this != &rhs) {
        m_maxsize = rhs.m_maxsize;
		m_size = rhs.m_size;
        size_t i = 0;
		while (i != m_maxsize){
			m_array[i] = rhs.m_array[i];
			i++;
		}
    } else {
       return *this;
    }

    return *this;
    cout << "ArrayList assignment operator test. VALUES: \n " << this << endl; 
}											


ostream & operator<<(ostream & os, const ArrayList & arrayList)
{
	size_t i = 0;
	while (i < arrayList.m_size){
		os << '{' << i << ',' << arrayList.m_array[i] << "} " << endl;
		i++;
	}
	return os;
}
	
DataType & ArrayList::operator[] (size_t position)
{
	
	return m_array[position];
}													

// More methods
size_t ArrayList::size() const
{
	return (m_size);
}													
bool ArrayList::empty() const
{
	bool truth = 0;
	if (m_array == NULL){
		truth = 1;
	}
	return truth;
	
}														
void ArrayList::clear()
{
	if (m_array != NULL){
        delete [] m_array;
        m_array = NULL;
    }
    m_size = 0;
    m_maxsize = 0;
}														

void ArrayList::resize(size_t count)
{
	size_t i = 0;
	DataType *placeHolder = new DataType[m_size];
	if(m_array != NULL){
		while (i < m_size){
			placeHolder[i] = m_array[i];
			i++;	
		}
	}else{
		while (i < m_size){
			placeHolder = NULL;
			placeHolder++;
			i++;
		}
	}
	delete [] m_array;
	m_array = NULL;
	

	m_maxsize = m_maxsize + count;
    m_array = new DataType[m_maxsize];
    
	i = 0;
	while (i < m_maxsize){
		if (m_size < m_maxsize && i > m_size){
			m_array = 0;
		}
		
		m_array = placeHolder;
		placeHolder++;
		m_array++;
		i++;
	}
}		               					

