//Noah Hoffman
//CS202



#ifndef ARRAYSTACK_H_
#define ARRAYSTACk_H_

#include <iostream>


template <typename T> class ArrayStack;
template <typename T> std::ostream & operator<<(std::ostream & os, 
						const ArrayStack<T> & arrayStack);
									
const size_t MAX_STACKSIZE = 1000;

template <typename T>
class ArrayStack{
	
  friend std::ostream & operator<< <> (std::ostream & os, 
								const ArrayStack<T> & arrayStack); 
  public:
  //Default Ctor, initializes m_top to 0 							(1)
	ArrayStack():m_top(0){;}
	
  //Parameterized ctor, initializes ArrayStack with providied values		(2)
	ArrayStack(size_t count, const T & value){
		if(count < (MAX_STACKSIZE) && count >= 1){
			size_t i = 0;
			m_top = count;
			while(i <= m_top){
				m_container[i] = value;
				i++;
			}
		}else{
			std::cout << "INVALID COUNT NUMBER, ARRAY NOT INITIALIZED" 
					  << std::endl;
			m_top = 0;
		}
	}
	
  //Copy ctor, makes a new ArrayStack with values of other ArrayStack object			(3)
	ArrayStack(const ArrayStack<T> & other){
		size_t i = 0;
		m_top = other.m_top;
		while(i <= m_top){
			m_container[i] = other.m_container[i];
			i++;
		}
	}
	
  //Dtor, kills ArrayStack object :(										(4) 
	~ArrayStack(){
	clear();	
	std::cout << "ARRAYSTACK DTOR CALLED." << std::endl;
	}
	
  //Assignment operator, copies one ArrayStack object with rhs ArrayStack
  //																	(5)
	ArrayStack & operator= (const ArrayStack<T> & rhs){
		if(this != &rhs){
			size_t i = 0;
			m_top = rhs.m_top;
			while(i < m_top){
				m_container[i] = rhs.m_container[i];
				i++;
			}
			return *this;
		}else{
			return *this;
		}
	}
	
  //top function (non-const), returns a usable data value for m_top		(6a) 
	T & top(){return m_container[m_top];}
	
  //top function (const), returns a display only data value for m_top 	(6b)
	const T & top() const{return m_container[m_top];}
	
  //push function, inserts provided value to Stack						(7) 
	void push(const T & value){
		if((m_top) < MAX_STACKSIZE){
			++m_top;
			m_container[m_top] = value;
		}else{
			std::cout << "OVERFLOW IMMENINT IF PUSHED, NO GO." << std::endl;
		}
	}
	
 //pop function, delete top value of Stack								(8) 
	void pop(){
		if(!empty()){
			m_container[m_top] = -2000;
			m_top -= 1;
		}else{
			std::cout << "This Stack is empty!" << std::endl;
		}
	}
	
  //size function, transverses through Nodes to find sizeof Stack		(9)	
	size_t size() const{
		return m_top;
	}
	
  //empty function, checks if Stack is empty							(10)
	bool empty() const{
		if(m_top == 0){
			return true;
		}else{
			return false;
		}
	}
	
  //full function, check if the Stack is full							(11)
	bool full() const{
		if(m_top == (MAX_STACKSIZE - 1)){
			return true;
		}else{
			return false;
		}
	}
	
  //clear function, clears Stack of values								(12)
	void clear(){
		if(!empty()){
			while(!empty()){
				pop();
				if(empty()){
					std::cout << "This Stack is now empty." << std::endl;
				}
			}
		}else{
			std::cout << "This Stack is empty!" << std::endl;
		}
	}
	
  //serialize function, initializes a ostream variable for << operator	(13)
	void serialize(std::ostream & os) const{
		if(!empty()){
			os << '[';
			size_t i = 0;
			while(i < m_top){
				if((m_top - 1) == i){
					os << m_container[i] << ']';
				}else{
					os << m_container[i] << ", ";
				}
				i++;
			}
		}else{
			os << "This Stack is empty!!!";
		}
		os << std::endl;
	}
	


  private:
	T m_container[MAX_STACKSIZE];
	size_t m_top;
};

template<typename T>
std::ostream & operator<< (std::ostream & os, 
								const ArrayStack<T> & arrayStack){
	arrayStack.serialize(os);
	return os;
}
#endif //ARRAYSTACK_H_
