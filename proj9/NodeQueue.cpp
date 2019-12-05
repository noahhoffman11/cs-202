//noah hoffman cs202
#include <iostream>
#include "NodeQueue.h"


std::ostream& operator<<(std::ostream& os, const NodeQueue& srcQueue)
{
    srcQueue.serialize(os);
    return os;
}


NodeQueue::NodeQueue()							    		//(1)
{
  m_front = NULL;
  m_back = m_front;
}


NodeQueue::NodeQueue(size_t count, const DataType& value)
{
  if(count <= 0)
  {
    m_front = m_back = NULL;
    std::cout << "Zero or less count detected, value not assigned" << std::endl;
  }
  else
  {
    m_front = new Node(value);
    Node * current = m_front;
    int i = 0;
    while (--count > 0)
    {
      
      current->m_next = new Node(value);
      current = current->m_next;
      m_back = current;
      ++i;
    }
    //deallocate current
    current = NULL;
    delete current;
  }
}

/*
  Copy constructor:
*/
NodeQueue::NodeQueue(const NodeQueue& other)					//(3)
{

  if(!other.m_front)
  {
    m_front = m_back = NULL;
  }
  else if(!other.m_front->m_next)
  {
    m_front = new Node(other.m_front->m_data);
    m_back = m_front;
  }
  else
  {
    Node * otherCurr = other.m_front;
    m_front = new Node (otherCurr->m_data);
    Node * current = m_front;
    otherCurr = otherCurr->m_next;

    while (otherCurr)
    {
      current->m_next = new Node(otherCurr->m_data);
      current = current->m_next;
      m_back = current;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
    delete current;
    delete otherCurr;
  }
}


NodeQueue::~NodeQueue()							   			//(4)
{
  std::cout << std::endl << "------------------------------------" << std::endl;
  std::cout << std::endl << "NodeQueue D-tor called!" << std::endl;
  size_t count = 0;
  //convert into a LLL, then delete it
  if(m_front)
  {
    m_back = NULL;
    Node * del = m_front;
    while(m_front)
    {
      m_front = m_front->m_next;
      del->m_next = NULL;
      delete del;
      del = m_front;
      ++count;
    }
    del = NULL;
    delete del;
  }
    //safety precaution
    std::cout << "Total Number of nodes deleted " << count << std::endl;
    m_front = NULL;
    delete m_front;

}

/*
  operator=
  
*/
NodeQueue& NodeQueue::operator= (const NodeQueue& rhs)			//(5)
{
  if(this == &rhs)
    return *this;
//delete any list that current exists
    if(m_front)
    {
      m_back = NULL;
      Node * del = m_front;
      while(m_front)
      {
        m_front = m_front->m_next;
        del->m_next = NULL;
        delete del;
        del = m_front;
      }
      del = NULL;
      delete del;
    }

  if(!rhs.m_front)
  {
    m_front = m_back = NULL;
    return *this;
  }
  else if(!rhs.m_front->m_next)
  {
    m_front = new Node(rhs.m_front->m_data);
    m_back = m_front;
    return *this;
  }
  else
  {
    Node * otherCurr = rhs.m_front;
    m_front = new Node (otherCurr->m_data);
    Node * current = m_front;

    otherCurr = otherCurr->m_next;
    while (otherCurr)
    {
      current->m_next = new Node(otherCurr->m_data);
      current = current->m_next;
      m_back = current;
      otherCurr = otherCurr->m_next;
    }
    current = NULL;
    otherCurr = NULL;
    delete current;
    delete otherCurr;
    return *this;
  }
}

/*
  front():
*/

DataType& NodeQueue::front()
{
  std::cout << "Non-const front() method called" << std::endl;
  return m_front->m_data;
}

/*
  front():
*/
const DataType& NodeQueue::front() const
{
  std::cout << "Const front() method called" << std::endl;
  return m_front->m_data;
}

/*
  back():
*/
DataType& NodeQueue::back()
{
  std::cout << "Non-const back() method called" << std::endl;
  return m_back->m_data;
}

/*
  back():
*/
const DataType& NodeQueue::back() const
{
  std::cout << "Const back() method being called" << std::endl;
  return m_back->m_data;
}

/*
  push():
*/
void NodeQueue::push(const DataType& value)
{
  if(!m_front)
  {
    m_front = new Node(value);
    m_back = m_front;
  }
  else
  {
    Node * temp = new Node(value);
    m_back->m_next = temp;
    m_back = temp;
    temp = NULL;
  }
}

/*
  pop():
*/
void NodeQueue::pop()
{
  if(!m_front)
    return;
  else if(!m_front->m_next)
  {
    m_back = NULL;
    delete m_front;
    m_front = NULL;
  }
  else
  {
    Node * temp = m_front;
    m_front = m_front->m_next;
    delete temp;
    temp = NULL;
  }
}

/*
  size():
*/
size_t NodeQueue::size() const               //(13)
{
  size_t count = 0;
  if(m_front)
  {
    Node * current = m_front;
    while(current)
    {
      ++count;
      current = current->m_next;
    }
    current = NULL;
    delete current;
  }
  return count;
}

/*
  empty():

*/
bool NodeQueue::empty() const									//(14)
{
  if(!m_front)
    return true;
  return false;
}

/*
  full():
    
*/
bool NodeQueue::full() const
{
  std::cout << "NO size limitations set" << std::endl;
  return false;
}

/*
  Clear():
*/
void NodeQueue::clear()										//(15)
{
  if(m_front)
  {
    Node * del = m_front;
    while(m_front)
    {
      m_front = m_front->m_next;
      del->m_next = NULL;
      delete del;
      del = m_front;
    }
    del = NULL;
    delete del;
  }
}

/*
  serialize:
*/
void NodeQueue::serialize(std::ostream& os) const
{
  using std::endl;

  if(!m_front)
  {
    os << "No list to display" << endl;
  }
  else
  {
    Node * current = m_front;
    //display first node on a new line
    os << endl;

    size_t i = 1;
    while(current)
    {
      os << "Value of Node " << i << ": " << current->GetData()<< endl;
      ++i;
      current = current->GetNext();
    }
  }
}
