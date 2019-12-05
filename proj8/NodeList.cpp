//noah Hoffman

#include "NodeList.h"
#include <cstring>
using namespace std;

//Default ctor
NodeList::NodeList()
{
	m_head = NULL;
	cout << "Testing NodeList default ctor" << endl;
}								    				 

//Parameterized Ctor
NodeList::NodeList(size_t count, const DataType & value)
{
	if (count <= 0){
		m_head = NULL;
	}else{
		m_head = new Node(value, NULL);
		Node *newNode = m_head;
		size_t i = 0;
		while(i < count){
			newNode->m_next = new Node(value, NULL);
			newNode = newNode->m_next;
			i++;
		} 
		newNode->m_next = NULL;
	}
	cout << "Testing NodeList Parameterized ctor" << endl;
}													  

//Copy Ctor
NodeList::NodeList(const NodeList & other)
{
	if (other.m_head != NULL){
		m_head = new Node (other.m_head->data());
		
		Node *headcopy = m_head;
		Node *othercopy = other.m_head;
		while (othercopy->m_next != NULL){
			othercopy = othercopy->m_next;
			headcopy->m_next = new Node (othercopy->data());
			headcopy = headcopy->m_next;
		}
		headcopy->m_next = NULL;
	}
	cout << "Testing NodeList copy ctor." << endl;
}					  								

//Destructor
NodeList::~NodeList()
{
	clear();
	cout << "Testing NodeList dtor" << endl;
}							   				    
								   

//Other methods
Node * NodeList::front()
{
	return m_head;
}			    						    		

Node * NodeList::back()
{
	Node *headTemp = m_head;
	while (headTemp->m_next != NULL){
		headTemp = headTemp->m_next;
	}
	return headTemp;
}												
	
Node * NodeList::find(const DataType & target, Node * & previous)
{
	Node* nodePtr = m_head;
    while (nodePtr->m_next != NULL && nodePtr != NULL)
    {
        if (nodePtr->m_next->data() == target)
        {
            if (nodePtr != NULL)
            {
                previous = nodePtr;
            }
            else
            {
                previous = NULL;
            }
            return nodePtr->m_next;
        }
        nodePtr = nodePtr->m_next;
    }
    previous = NULL;
    return NULL;

	
}	
	
Node * NodeList::insertAfter(const DataType & target,    	
                       const DataType & value)
{
	Node* headtemp = m_head;
    while (headtemp != NULL)
    {
        if (headtemp->data() == target && headtemp != NULL)
        {
            headtemp->m_next = new Node (value,headtemp->m_next);
            return headtemp->m_next;
        }
        headtemp = headtemp->m_next;
    }
    if (empty())
    {
        m_head = new Node (value, NULL);
        return m_head;
    }
    return NULL;
}
    

Node * NodeList::insertBefore(const DataType & target,    	  
                        const DataType & value)
{
	 if (empty())
    {
        m_head = new Node (value, NULL);
        return m_head;
    }
    else if (m_head->data() == target)
    {
        Node* m_newHead = new Node (value, NULL);
        m_newHead->m_next = m_head;
        return m_newHead;
    }

    Node* h1 = NULL;
    Node* h2 = m_head;

    while (h2 != NULL)
    {
        if (h2->data() == target && h2 != NULL)
        {
            h1->m_next = new Node (value,h2);
            return h1->m_next;
        }
        h1 = h2;
        h2 = h2->m_next;
    }
    return NULL;
}

Node * NodeList::erase(const DataType & target)
{
	if(m_head->data() == target){
		m_head = m_head->m_next;
		return m_head;
	}
	if(empty()){
		return NULL;
	}
	else{
		Node *h1;
		Node *h2;
		h2 = find(target, h1);
		if(h2 != NULL){
			h1->m_next = h2->m_next;
			delete h2;
			return h1;
		}
	}
	return NULL;
	
}									 			  

//Assaignment operator
NodeList & NodeList::operator= (const NodeList & rhs)
{
	cout << "Testing assignment operator NodeList" << endl;
	if (this != &rhs){
		Node *headcpy = m_head;
		Node *rhscpy = rhs.m_head;
		if(this->size() < rhs.size()){
			clear();
			DataType dataC(0,0.0);
			NodeList newL(rhs.size(), dataC);
			headcpy = newL.m_head;
		}
		while (rhscpy->m_next != NULL){
			headcpy->m_data = rhscpy->data();
			headcpy = headcpy->m_next;
			rhscpy = rhscpy->m_next;
		}
	}else{
		return *this;
	}
	return *this;
}				

// insertion operator
ostream & operator<<(ostream & os,	  
					       const NodeList & nodeList)
{
	size_t i = 0;
	while (i < nodeList.size()){
		os << '{' << i << ',' << nodeList[i] << "} " << endl;
	}
	return os;
}


DataType & NodeList::operator[] (size_t position)
{
	size_t i = 0;
	Node *curr = m_head;
	while (i < position){
		curr++;
	}
	return curr->data();
}													

const DataType & NodeList::operator[] (size_t position) const
{
	size_t i = 0;
	Node *curr = m_head;
	while (i < position){
		curr++;
	}
	return curr->data();
}  											
    
size_t NodeList::size() const
{
	size_t i = 0;
	Node *size = m_head;
	while (size != NULL){
		i++;
		size = size->m_next;
	}
	return i;
}												

bool NodeList::empty() const
{
	bool truth = 0;
	if(m_head == NULL){
		truth = 1;
	}
	
	return truth;
	
}											

void NodeList::clear()
{
	Node* curr = m_head;
	Node* pre = m_head;
	while (curr != NULL){
		curr = curr->m_next;
		delete pre;
		pre = curr;
	}
	m_head = NULL;	
}												  
	
