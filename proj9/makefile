TARGET = proj9
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall -std=c++11 #compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o DataType.o NodeQueue.o ArrayQueue.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o DataType.o NodeQueue.o ArrayQueue.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp DataType.h NodeQueue.h ArrayQueue.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

NodeList.o:NodeQueue.cpp NodeQueue.h
	$(CXX) $(CXX_FLAGS) -c NodeQueue.cpp

DataType.o:DataType.cpp DataType.h
	$(CXX) $(CXX_FLAGS) -c DataType.cpp

ArrayList.o:ArrayQueue.cpp ArrayQueue.h
	$(CXX) $(CXX_FLAGS) -c ArrayQueue.cpp


clean:
	-rm -f *.o
	-rm -f $(TARGET)
