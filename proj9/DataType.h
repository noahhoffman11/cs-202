//noah hoffman cs 202
#ifndef DATATYPE_H_
#define DATATYPE_H_

#include <iostream>

struct Exception
{
  const char* error;
  Exception(const char* message):error(message){};

};

class DataType{

friend std::ostream& operator<<(std::ostream& os, const DataType& dataType);
friend std::istream& operator>>(std::istream& is, DataType& dataType);

  public:
    DataType();
    DataType(int intVal, double doubleVal);

    DataType(const DataType& srcData);

    bool operator==(const DataType& other_dataType) const;
    DataType& operator= (const DataType& other_dataType);
    DataType& operator* (int multiplier);

    int GetIntVal() const;
    void SetIntVal(int i);
    double GetDoubleVal() const;
    void SetDoubleVal(double d);

  private:
    int m_intVal;
    double m_doubleVal;
};

#endif //DATATYPE_H_
