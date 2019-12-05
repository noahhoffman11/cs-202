TARGET = proj7
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall -std=c++11 #compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o MyString.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o MyString.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp MyString.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

MyString.o: MyString.cpp MyString.h
	$(CXX) $(CXX_FLAGS) -c MyString.cpp


clean:
	-rm -f *.o
	-rm -f $(TARGET)
