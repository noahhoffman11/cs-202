TARGET = proj8
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall -std=c++11 #compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o DataType.o NodeList.o ArrayList.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o DataType.o NodeList.o ArrayList.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp DataType.h NodeList.h ArrayList.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

NodeList.o:NodeList.cpp NodeList.h
	$(CXX) $(CXX_FLAGS) -c NodeList.cpp

DataType.o:DataType.cpp DataType.h
	$(CXX) $(CXX_FLAGS) -c DataType.cpp

ArrayList.o:ArrayList.cpp ArrayList.h
	$(CXX) $(CXX_FLAGS) -c ArrayList.cpp


clean:
	-rm -f *.o
	-rm -f $(TARGET)
