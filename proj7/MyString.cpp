#include <iostream>
#include "MyString.h"
using namespace std;
// Default Constructor
MyString::MyString()
{ 
    buffer_allocate(0); 
}

// Paramatized C-tor
MyString::MyString(const char* buffer)
{
    size_t size;
    for (int i=0; buffer[i] != 0; i++) size = i;
    size++;

    try
    {
        buffer_allocate(size);
        for(size_t i = 0; i < size; i++)
            (*this)[i] = buffer[i];
    }
    catch(const bad_alloc & e) //if doesnt work
    {
        cerr << e.what() << '\n';
        buffer_deallocate();
    }
}

MyString::MyString(const MyString & other)
{
    try
    {
        buffer_allocate(other.size());
        for(size_t i = 0; i < other.size(); i++)
            (*this)[i] = other[i];
    }
    catch(const bad_alloc & e)
    {
        cerr << e.what() << '\n';
        buffer_deallocate();
    }
}
//Destructor
MyString::~MyString()
{
    this->buffer_deallocate();
}

//Other Methods
size_t MyString::size() const { return m_size; }
size_t MyString::length() const { return m_size-1; }
const char * MyString::c_str() const { return m_buffer; }

bool MyString::operator== (const MyString & other) const
{   
    int i = 0;
    for(;other[i] &&
        (other[i] == (*this)[i]); i++);
    
    if(other[i] - (*this)[i]) return false;
    return true;
}

MyString & MyString::operator= (const MyString & other)
{
    this->buffer_deallocate();

    try
    {
        this->buffer_allocate(other.size());
        for(size_t i = 0; i < other.size(); i++)
            (*this)[i] = other[i];
    }
    catch(const bad_alloc & e)
    {
        cerr << e.what() << '\n';
        this->buffer_deallocate();
    }
    
    return *this;
}

MyString MyString::operator+ (const MyString & other_myStr) const
{

    size_t new_size = other_myStr.size() + size();

    char* concat_buffer;

    try
    {
        concat_buffer = new char[new_size];

        size_t i = 0;
        for (; i < size(); i++)
            concat_buffer[i] = (*this)[i];
        for (; i < new_size; i++)
            concat_buffer[i] = other_myStr[i-size()];
    }
    catch(const bad_alloc & e)
    {
        cerr << e.what() << '\n';
    }

    return MyString(concat_buffer);
}

char & MyString::operator[] (size_t index) { return m_buffer[index]; }
const char & MyString::operator[] (size_t index) const { return m_buffer[index]; }

ostream & operator<<(ostream & os, const MyString & myStr)
{
    os << myStr.m_buffer;
    return os;
}

void MyString::buffer_deallocate()
{
    delete[] m_buffer;
    m_buffer = NULL; 
    m_size = 0;
}

void MyString::buffer_allocate(size_t size)
{
    try
    {
        m_size = size;
        m_buffer = new char[size];
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        this->buffer_deallocate();
    }
}
