//Cameron Cobb
//CS202
//Proj4.cpp
//Note: I really hate this project. This was the biggest headache ever

#include <iostream>
#include <fstream>
#include "Car.h"
#include "Agency.h"
#include "Sensors.h"
using namespace std;

size_t myStringLength(const char*str);

int myStringCompare(const char*str1, const char*str2);

char *myStringCopy(char* destination, const char* source);

char *myStringCat(char*destination, const char* source);


void themostexspensivecar(Agency * agency); //hope i make it this far

void readFromFile(Agency *agency); // reads from file... duh

void totalSensors(Agency *agency);

int main(){

    int Input;
    Agency agency;
    int positions[5] = {0,1,2,3,4};
    int selection; // not neccessary
     

    do{
        cout << "\n1) Input File Name\n2) Print \n3) Number of Sensors\n4) Most Expensive Car\n5) Exit" << endl;

        cout << "Please choose an option from above: ";

        cin >> Input;
        cout << endl;
        switch(Input){
            case 1: readFromFile(&agency);//reads data
                    break; 
            case 2: agency.printData(); //prints all the date to the screen
                    break;
            case 3:  totalSensors(&agency); //gives total sensors
                    break;
            case 4: //themostexspensivecar(&agency);
                    break;
            case 5: exit(1);
        }
    }while(Input != 5);
    return 0;
}
void readFromFile(Agency *agency)
{
    char sourceFilename[100];
    cout << "Please enter source file name with extension: ";
    cin >> sourceFilename;
    cout << '\n';
    ifstream source_file;
    source_file.open(sourceFilename);
    if(!source_file)
    {
        cout << "Error opening file\n";
    }
    else
    {
        agency->readData(source_file);
    }

    return;
}

//void themostexspensivecar(Agency * agency){ //find the most expensive car
 //   int expensiveCar = 0;
  //  float price = 0;
//	int answer;


 //       for(int j = 0; j < 5; j++)
   //     {
    //        float newvar = m_inventory[i].getBaseprice();
    //        if (newvar > price){
    //            price = newvar;
     //           expensiveCar = j;
      //      }
      //  }
    
    
   // cout << "The " << m_inventory[expensiveCar].getMake() << ' '
  //  << m_inventory[expensiveCar].getModel()<< " is the most expensive car. \n Would you like to rent it? (Answer 1 for yes and 0 for no)\n";
//cin >> answer;
//if (answer=1){
//m_inventory[expensiveCar].setAvailability(false);
//}

// return;
   
//}

void totalSensors(Agency *agency){
Sensor* ptr=agency->getInventory()->getSensors();
ptr->printCount();
}

size_t myStringLength(const char* str){ 
    int length = 0;
    for(; str[length] != '\0'; length++) continue;

    length = length * sizeof(char);
    return length;

}

int myStringCompare(const char*str1, const char*str2){ 
    for (int i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++){
		int val1 = str1[i], val2 = str2[i];
		(val1 >= 97)? val1 -= 32 : val1 -= 0;
		(val2 >= 97)? val2 -= 32 : val1 -= 0;
		if (val1 > val2){
			return 1;
		}else if (val1 < val2){
			return -1;
		}
	}
    return 0;
}

char *myStringCopy(char* destination, const char* source){ 
    char *start = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // add '\0' at the end
    return start;
}

char *myStringCat(char*destination, const char* source){ 
    char *start = destination;

    while(*destination != '\0'){
        destination++;
    }

    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return start; 
}


//car.cpp

// Default Constructor
Car::Car()
{
    setYear(0000);
    setMake("BLANK");
    setModel("BLANK");
    setBaseprice(0.00);
    setAvailability(0);
}

// Paramatized Constructor
Car::Car(int year, char *make, char *model, float price, bool available)
{
    setYear(year);
    setMake(make);
    setModel(model);
    setBaseprice(price);
    setAvailability(available);
}

// Copy Constructor
Car::Car(const Car & other) :
    m_year(other.m_year) ,
    m_baseprice(other.m_baseprice) ,
    m_available(other.m_available)
{
    setMake(other.m_make);
    setModel(other.m_model);
}

// Setters
void Car::setYear(const int year)
{
    m_year = year;
}

void Car::setMake(const char *make)
{
    myStringCopy(m_make, make);
}

void Car::setModel(const char *model)
{
    myStringCopy(m_model, model);
}

void Car::setBaseprice(float baseprice)
{
    m_baseprice = baseprice;
}

void Car::setAvailability(bool available)
{
    m_available = available;
}

void Car::setOwner(char* owner)
{
    myStringCopy(m_owner, owner);
}

void Car::setSensors(Sensor *sensors)
{
    for(int i = 0; i < 3; i++)
    {
        m_sensors[i].setType(sensors->getType());
        m_sensors[i].setExtracost();
        sensors++;
    }
    
}

// Getter
int     Car::getYear()
{
    return m_year;
}

char*   Car::getMake()
{
    return m_make;
}

char*   Car::getModel()
{
    return m_model;
}

Sensor* Car::getSensors()
{
    return m_sensors;
}

float   Car::getBaseprice()
{
    return m_baseprice;
}

float   Car::getFinalprice()
{
    return m_finalprice;
}

bool    Car::getAvailability()
{
    return m_available;
}

char*   Car::getOwner()
{
    return m_owner;
}


// Other method
void Car::addLessee()
{

}

void Car::operator+ (char *type)
{
    m_sensors->setType(type);
}

float Car::estimateCost(const int num_of_days)
{

}

void Car::print()
{
    cout << getYear() << ' '
            << getMake() << ' '
            << getModel() << ' '
            << "  Base: $"
            << getBaseprice() << ' '
            << "  With: { ";
            Sensor * ptr = this->getSensors();
            bool hasSensors = 0;
            for(int i = 0; i < 3; i++)
            {
                if (myStringCompare( ptr->getType(), "none") != 0)
                {
                    cout << ptr->getType() << ' ';
                    hasSensors = 1;
                }
                ptr++;
            }
            if (!hasSensors)
            {
                cout << "none ";
            }
            cout << "}:  $"<< getFinalprice() << "    Available:" << boolalpha
            << getAvailability() << "    "<< getOwner() << "\n";
}

void Car::updatePrice()
{
float temp_price=m_baseprice;
Sensor* ptr=m_sensors;
for(int i=0;i<3;i++,ptr++){ 
temp_price+=ptr->getExtracost();
}
m_finalprice=temp_price;
}

//sensor.cpp

// Default Constructor
Sensor::Sensor()
{
    setType("none");
    setExtracost();
}

// Parametized Constructor
Sensor::Sensor(char* type)
{
    setType(type);
    setExtracost();
	
}

// Setter
void Sensor::setType(char* type)
{
    myStringCopy(m_type, type);
    if (myStringCompare(m_type, "gps") == 0)
    {
        gps_cnt++;
    }
    else if (myStringCompare(m_type, "camera") == 0)
    {
        camera_cnt++;
    }
    else if (myStringCompare(m_type, "lidar") == 0)
    {
        lidar_cnt++;
    }
    else if (myStringCompare(m_type, "radar") == 0)
    {
        radar_cnt++;
    }
}

void Sensor::setExtracost()
{
    if (myStringCompare(m_type, "gps") == 0)
    {
        m_extracost = 5.0;
    }
    else if (myStringCompare(m_type, "camera") == 0)
    {
        m_extracost = 10.0;
    }
    else if (myStringCompare(m_type, "lidar") == 0)
    {
        m_extracost = 15.0;
    }
    else if (myStringCompare(m_type, "radar") == 0)
    {
        m_extracost = 20.0;
    }
    else if (myStringCompare(m_type, "none") == 0)
    {
        m_extracost = 0.0;
    }
}

// Getter
void Sensor::printCount()
{
 cout << "Number of GPS=" <<  gps_cnt; 
cout << "\n Number of Cameras="<< camera_cnt;
cout << "\n Number of Lidar=" << lidar_cnt;
cout <<"\n Number of Radar="<<radar_cnt;

}
char* Sensor::getType()
{
    return m_type;
}

float Sensor::getExtracost()
{
    return m_extracost;
}

// Overload
bool Sensor::operator== (Sensor *sensorRef)
{
    bool result = 1;
    char *sensor_one_type = this->getType();
    char *sensor_two_type = sensorRef->getType();

    while((*sensor_one_type != '\0') && (*sensor_two_type != '\0'))
    {
        if (*sensor_one_type != *sensor_two_type)
        {
            result = 0;
            break;
        }

        sensor_one_type++, sensor_two_type++;
    }
    
    return result;
}

//agency.cpp

// Default Constructor
Agency::Agency()
{
    m_zipcode = 00000;
    myStringCopy(m_name, "Blank");
}

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

// Paramatized Constructor
Agency::Agency(char* name, int zipcode, Car* inventory) :
    m_zipcode(zipcode)
{
    myStringCopy(m_name, name);
}

// Setter
void Agency::setName(char* name)
{
    myStringCopy(m_name, name);
}

void Agency::setZip(int zipcode)
{
    m_zipcode = zipcode;
}

void Agency::setInventory(Car* inventory)
{
    for(int i = 0; i < 5; i++, inventory++)
    {
        this->m_inventory[i].setYear(inventory->getYear());
        this->m_inventory[i].setMake(inventory->getMake());
        this->m_inventory[i].setModel(inventory->getModel());
        this->m_inventory[i].setBaseprice(inventory->getBaseprice());
        this->m_inventory[i].setAvailability(inventory->getAvailability());
    }
}

// Getter
char* Agency::getName()
{
    return m_name;
}

int Agency::getZip()
{
    return m_zipcode;
}

Car* Agency::getInventory()
{
    return m_inventory;
}


// Overload Operator
Car& Agency::operator[](const int index)
{
    return m_inventory[index];
}

// Other Method
void Agency::printData()
{
    cout << this->getName() << ' '
    << this->getZip() << '\n';

    Car *carsRef = getInventory();

    for(int j = 0; j < 5; j++)
    {
        carsRef->print();
        carsRef++;
    }
    cout << '\n';
}

void Agency::readData(ifstream & infile)
{
    char temp_name[256], bracket;
    int temp_zip;

    infile >> temp_name;
    infile >> temp_zip;

    this->setName(temp_name);
    this->setZip(temp_zip);

    for(int j = 0; j < 5; j++)
    {
        int temp_year;
        char temp_make[256], temp_model[256], bracket, string[256];
        float temp_price;
        bool temp_available;
        char temp_type[256];
        char* temp_typeRef;
	Sensor arr[3];
        Sensor* sensor_ptr=arr;


        infile >> temp_year;

        infile >> temp_make;

        infile >> temp_model;

        infile >> temp_price;

	
char* string_ptr=string;
do{

infile>>string;
if(*string_ptr=='{'){
string_ptr++;
}
if(*string_ptr=='g'){
sensor_ptr-> setType("gps");
sensor_ptr++;
}
else if(*string_ptr=='c'){
sensor_ptr-> setType("camera");
sensor_ptr++;
}
else if(*string_ptr=='l'){
sensor_ptr-> setType("lidar");
sensor_ptr++;
}
else if(*string_ptr=='r'){
sensor_ptr-> setType("radar");
sensor_ptr++;
}
string_ptr=string;
}while(*(string_ptr+myStringLength(string)-1)!='}');

        
char noOwner[256]="no owner.";
char* no_ptr=noOwner;
char owner[256];
        infile >> temp_available;
	if(temp_available!=1){
	infile>>owner;
	(*this)[j].setOwner(owner);
}
else{
(*this)[j].setOwner(no_ptr);
}
	

        (*this)[j].setYear(temp_year);
        (*this)[j].setMake(temp_make);
        (*this)[j].setModel(temp_model);
        (*this)[j].setBaseprice(temp_price);
        (*this)[j].setSensors(arr);
        (*this)[j].setAvailability(temp_available);
		(*this)[j].updatePrice();
}
    }


