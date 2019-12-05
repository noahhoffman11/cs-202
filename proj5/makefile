TARGET = proj5
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall -std=c++11 #compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o Vehicle.o Car.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o Vehicle.o Car.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp Vehicle.h Car.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

Vehicle.o: Vehicle.cpp Vehicle.h
	$(CXX) $(CXX_FLAGS) -c Vehicle.cpp

Car.o:Car.cpp Car.h
	$(CXX) $(CXX_FLAGS) -c Car.cpp

clean:
	-rm -f *.o
	-rm -f $(TARGET)
