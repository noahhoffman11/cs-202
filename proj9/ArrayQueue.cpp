//noah hoffman cs 202
#include "ArrayQueue.h"

using std::cout;
using std::endl;
/*
  operator<<:

*/
std::ostream& operator<<(std::ostream& os,			//(i)
               const ArrayQueue& ArrayQueue)
{
  ArrayQueue.serialize(os);
  return os;
}

/*
  ArrayQueue():

*/
ArrayQueue::ArrayQueue()				    		//(1)
{
  m_size = 0;
  m_front = m_back = -1;
}

/*
  Parameterized C-tor:

*/
ArrayQueue::ArrayQueue(size_t count, const DataType& value)			//(2)
{
  if (count <= 0 || count > ARRAY_MAX)
  {
    if(count > ARRAY_MAX)
      std::cout << "Value outside ARRAY_MAX" << std::endl;
    m_size = 0;
    m_front = m_back = -1;
  }
  else
  {
    size_t i = 0;
    m_size = count;
    m_front = i;
    while (i < m_size)
    {
      m_back = i;
      m_array[i++] = value;
    }
  }
}

/*
  Copy c-tor:


*/
ArrayQueue::ArrayQueue(const ArrayQueue& other)				    	//(3)
{
  if(other.m_size <= 0 || other.m_size > ARRAY_MAX)
  {
    if(other.m_size > ARRAY_MAX)
      std::cout << "Value outside ARRAY_MAX" << std::endl;
    m_size = 0;
    m_front = m_back = -1;
    return;
  }
  else
  {
    m_size = other.m_size;
    m_front = other.m_front;
    m_back = other.m_back;

    size_t i = m_front;
    while(i < m_size)
    {
      m_array[i] = other.m_array[i];
      ++i;
    }
  }
}

/*
  destructor:
   
*/
ArrayQueue::~ArrayQueue()							    			//(4)
{
  cout << "-------------------------------------------" << endl;
  cout << endl << "ArrayQueue D-tor Called!" << endl;
  clear();
}

/*
  operator =:

*/
ArrayQueue& ArrayQueue::operator= (const ArrayQueue& rhs)			//(5)
{
  if(this != &rhs)
  {
    clear();
    m_size = rhs.m_size;
    m_front = rhs.m_front;
    m_back = rhs.m_back;
    size_t i = m_front;
    while (i < m_size)
    {
        m_array[i] = rhs.m_array[i];
        ++i;
    }
  }
  return *this;
}

/*
  front:
  
*/
DataType& ArrayQueue::front()
{
  std::cout << "non-const front() called" << std::endl;
  return m_array[m_front];
}
 
const DataType& ArrayQueue::front() const
{
  std::cout << "const-front() called" << std::endl;
  return m_array[m_front];
 }
DataType& ArrayQueue::back()
{
  std::cout << "non-const back() called" << std::endl;
  return m_array[m_back];

}

/*
  back:
    
*/
const DataType& ArrayQueue::back() const
{
  std::cout << "const-back() called" << std::endl;
  return m_array[m_back];

}

/*
  push:
  
*/
void ArrayQueue::push(const DataType& value)
{
  if(full())
  {
    std::cout << "The list is full, can't add!" << std::endl;
    return;
  }
  else if(empty())
  {
    m_back = m_front = 0;
    m_size = 1;
  }
  else
  {
    //++m_back;
    m_back = (m_back+1) % ARRAY_MAX;
    ++m_size;
  }
  m_array[m_back] = value;
}

/*
  pop:
   
*/
void ArrayQueue::pop()
{
  if(empty())
    return;
  else if(m_back == m_front)
  {
    m_size = 0;
    m_front = m_back = -1;
  }
  else
  {
    cout << "----------" << endl;
    std::cout << m_array[m_front] << " is being removed" << endl;
    //++m_front;
    m_front=(m_front+1)% ARRAY_MAX;
    --m_size;
  }
}
/*
  size():
   
*/
size_t ArrayQueue::size() const									//(13)
{
  return m_size;
}

/*
  empty():
  
*/
bool ArrayQueue::empty() const										//(14)
{
  return (m_front == -1 && m_back == -1);
}

/*
  full:
   
*/
bool ArrayQueue::full() const
{
  return (m_size == ARRAY_MAX);
}

/*
  clear():
    
*/
void ArrayQueue::clear()											//(15)
{
  if(empty())
    return;
  else
  {
    DataType dummy;
    //may seg fault, might need to do m_size-1
    while(m_size--)
      m_array[m_size] = dummy;
  }
}

/*
  serialize:
   
*/
void ArrayQueue::serialize(std::ostream& os) const
{
  if(m_size > 0)
  {
    os << endl;
    size_t i = m_front;
    while (i <= m_back)
    {
      os << m_array[i] << endl;
      ++i;
    }
  }
  else
    std::cout << "Array Empty!" << std::endl;
}
