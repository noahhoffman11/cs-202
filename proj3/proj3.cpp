//Cameron Cobb
//CS202
//Proj3.cpp

#include <iostream>
#include <fstream>
#include "RentalCar.h"

// My struct

struct RentalAgency{
    char name[256];
    int zipcode[5];
    RentalCar inventory[5];
};


// Function def
void readFromFile(RentalAgency * arrayforagencies);

void carRentalCost(RentalAgency * arrayforagencies);

void printdata(RentalAgency * arrayforagencies);

void themostexspensivecar(RentalAgency * arrayforagencies);



int somefuncthatineed(char a); //This is a function that I borrowed from a friends code... he explained to me what it was and its purpose and I do not understand why but for some reaosn it works

int main(){

    int Input;
    RentalAgency arrayforagencies[3]; //array of structs
    //RentalAgency * passedstruct;
    int positions[5] = {0,1,2,3,4};
     

    do{
        std::cout << "\n1) Input File Name\n2) Print \n3) Estimate Car Rental Cost\n4) Most Expensive Car\n5) Available cars\n6) Exit" << std::endl;
        std::cout << "Please choose an option from above: ";
        std::cin >> Input;
        std::cout << std::endl;
        switch(Input){
            case 1: readFromFile(arrayforagencies);
                    break; 
            case 2: printdata(arrayforagencies);
                    break;
            case 3: printdata(arrayforagencies);
                    carRentalCost(arrayforagencies);
                    break;
            case 4: themostexspensivecar(arrayforagencies);
                    break;
            case 5: break;
            case 6: exit(1);
        }
    }while(Input != 6);
    return 0;
}
void readFromFile(RentalAgency * arrayforagencies){
    char inFileName[20];  // size of only 20 characters
    RentalAgency *refarrayforagencies = arrayforagencies;
    std::cout << "Full input file name with extension: ";
    std::cin >> inFileName;
    std::ifstream infile;
    infile.open(inFileName);

    if(!infile){
        std::cout<<"Error finding file" << std::endl;
        system("pause");
        exit(-1);
    }

   for(int i = 0; i < 3; i++){

            char t_zipcode[6];

            infile >> refarrayforagencies->name; //reads the name and puts it into the constructor
            infile >> t_zipcode;

            int * Refzipcode = refarrayforagencies->zipcode;

        for(char * temporaryRefzip = t_zipcode; * temporaryRefzip != '\0'; temporaryRefzip++){
            *Refzipcode = somefuncthatineed(*temporaryRefzip);
            Refzipcode++;
        }

        RentalCar * Refcars = refarrayforagencies->inventory;

        for(int j = 0; j < 5; j++){
            int tempyear;
            char tempmake[256], tempmodel[256];
            float tempprice;
            bool tempavailable;

            infile >> tempyear;
            infile >> tempmake;
            infile >> tempmodel;
            infile >> tempprice;
            infile >> tempavailable;

            Refcars->setYear(tempyear);
            Refcars->setMake(tempmake);
            Refcars->setModel(tempmodel);
            Refcars->setPrice(tempprice);
            Refcars->setAvailability(tempavailable);

            Refcars++; //incremeting

        }
        refarrayforagencies++; // incrementing again
        
   }
    infile.close(); //closes file
    std::cout << "Data has been successfully read from file and stored." << std::endl;

}

void printdata(RentalAgency * arrayforagencies){
    for(int i = 0; i < 3; i++){

        std::cout << arrayforagencies[i].name << ' ';

        for(int j = 0; j < 5; j++){
            std::cout << arrayforagencies[i].zipcode[j];
        }

        std::cout << "\n";

        for(int k = 0; k < 5; k++){
            std::cout << arrayforagencies[i].inventory[k].getYear() << ' ';
            std::cout << arrayforagencies[i].inventory[k].getMake() << ' ';
            std::cout << arrayforagencies[i].inventory[k].getModel() << ", ";
            std::cout << "$" << arrayforagencies[i].inventory[k].getPrice() << " per day, ";
            std::cout << "Available: " << std::boolalpha << arrayforagencies[i].inventory[k].getAvailability() << std::endl;

        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void carRentalCost(RentalAgency * arrayforagencies){       //print the contents to a newvar filw

    int selectedAgency, selectedCar, days;

    std::cout << "Select the agency you want to rent from (pick index): ";
    std::cin >> selectedAgency;
    std::cout << "Pick the car you want to rent (pick index): ";
    std::cin >> selectedCar;
    std::cout << "How many days would you like to rent that car for: ";
    std::cin >> days;

    std::cout << "The "
    << arrayforagencies[selectedAgency].inventory[selectedCar].getYear() << ' '
    << arrayforagencies[selectedAgency].inventory[selectedCar].getMake() << ' '
    << arrayforagencies[selectedAgency].inventory[selectedCar].getModel() << ' '
    << "will cost: $"
    << arrayforagencies[selectedAgency].inventory[selectedCar].estimateCost(days)
    << " for " << days << " days." << std::endl;
}

void themostexspensivecar(RentalAgency * arrayforagencies){ //find the most expensive car... duh...
    int expensiveAgency = 0, expensiveCar = 0;
    float price = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            float newvar = arrayforagencies[i].inventory[j].getPrice();
            if (newvar > price){
                price = newvar;
                expensiveAgency = i;
                expensiveCar = j;
            }
        }
    }
    
    std::cout << "The " << arrayforagencies[expensiveAgency].inventory[expensiveCar].getYear() << ' '
    << arrayforagencies[expensiveAgency].inventory[expensiveCar].getMake() << ' '
    << arrayforagencies[expensiveAgency].inventory[expensiveCar].getModel() << ' '
    << "is the most expensive car at " << arrayforagencies[expensiveAgency].name << std::endl;
    std::cout << "Save up buddy ;)" << std::endl;
   
}

int somefuncthatineed(char a){ //still dont know exactly what this does. My friend helped me out with this 
    return a - '0';
}


void myStringCopy(char* destination, char* source){ //why would I use this function also???!!!
    int i = 0;

    while(source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0'; // add '\0' at the end
}

RentalCar::RentalCar(){
    RentalCar::setYear(0000);
    RentalCar::setMake("EMPTY");
    RentalCar::setModel("EMPTY");
    RentalCar::setPrice(0.00);
    RentalCar::setAvailability(0);
}

RentalCar::RentalCar(int year, char *make, char *model, float price, bool available){
    RentalCar::setYear(year);
    RentalCar::setMake(make);
    RentalCar::setModel(model);
    RentalCar::setPrice(price);
    RentalCar::setAvailability(available);
}

//Trend setters... ;)
void RentalCar::setYear(int year){
    m_year = year;
}

void RentalCar::setMake(char *make){
    myStringCopy(m_make, make);
}


void RentalCar::setModel(char *model){
    myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price){
    m_price = price;
}

void RentalCar::setAvailability(bool available){
    m_available = available;
}

// Go Getters... See what I did there ;)
int RentalCar::getYear(){
    return m_year;
}

char* RentalCar::getMake(){
    return m_make;
}

char* RentalCar::getModel(){
    return m_model;
}

float RentalCar::getPrice(){
    return m_price;
}

bool RentalCar::getAvailability(){
    return m_available;
}

float RentalCar::estimateCost(const int num_of_days){
    return m_price * num_of_days;
}
