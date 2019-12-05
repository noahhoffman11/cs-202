//Noah Hoffman CS 202 proj3
#include <iostream>
#include <fstream>
using namespace std;

class RentalCar{
public:
    //Default Constructor
    RentalCar();

    //Paramatized Constructor
    RentalCar(int year, char *make, char *model, float price, bool available);

    //Setter
    void setYear(int year);
    void setMake(char *make);
    void setModel(char *model);
    void setPrice(float price);
    void setAvailability(bool available);

    //Getter
    int   getYear();
    char* getMake();
    char* getModel();
    float getPrice();
    bool  getAvailability();

    //methods
    float estimateCost(const int num_of_days);

private:
    int   m_year;
    char  m_make[256];
    char  m_model[256];
    float m_price;
    bool  m_available;
};

struct RentalAgency{
    char name[256];
    int zipcode[5];
    RentalCar inventory[5];
};

void readfile(RentalAgency * agencies);

int neededfunction(char a);

void printdata(RentalAgency * agencies);

void carRentalCost(RentalAgency * agencies);

void themostexspensivecar(RentalAgency * agencies);

void printAvailable(RentalAgency * agencies);

int main (void){
    RentalAgency arraysforagencies[3];
    int position[5] = {0, 1, 2, 3, 4};
    const int SIZE = 5;
    char filename1[100];
    char filename2[100];
    int choice;
    int days;
    int car;
    

    ifstream inputFile;
    ofstream outputFile;

    while (choice != 6){
        cout << "What would you like to do?\n";
        cout << "1) to read a desired file.\n";
        cout << "2) to print out the information from read file to terminal.\n";
        cout << "3) Estimate car rental cost.\n";
        cout << "4)  Find the most expensive Car.\n";
        cout << "5)Print out only the availableCars-from all Agencies, to a separate output file\n";
        cout << "6) Exit.\n";
	    cout << "Enter a number: ";
        cin >> choice;
        cout << "\n";

        if (choice > 6 || choice <=0){
        cout << "Invalid option.\n";
        }
        else{
            switch (choice){
                case 1:
                    readfile(arraysforagencies);
                    break;
                case 2:
                    printdata(arraysforagencies);
                    break;
                case 3:
                    carRentalCost(arraysforagencies);
                    break;
                case 4:
                    themostexspensivecar(arraysforagencies);
                    break;
                case 5:
                    printAvailable(arraysforagencies);
                    break;
                case 6:
                   
                    break;
            
		    }
        }
    }

	inputFile.close();
	outputFile.close();

    return 0;
}

void readfile(RentalAgency * agencies){
    char inFileName[20];  // size of only 20 characters
    RentalAgency *refagencies = agencies;
    cout << "Full input file name with extension: ";
    cin >> inFileName;
    ifstream infile;
    infile.open(inFileName);

    if(!infile){
        cout<<"Error finding file" << endl;
        system("pause");
        exit(-1);
    }

   for(int i = 0; i < 3; i++){

            char t_zipcode[6];

            infile >> refagencies->name; 
            infile >> t_zipcode;

            int * Refzipcode = refagencies->zipcode;

        for(char * temporaryRefzip = t_zipcode; * temporaryRefzip != '\0'; temporaryRefzip++){
            *Refzipcode = neededfunction(*temporaryRefzip);
            Refzipcode++;
        }

        RentalCar * Refcars = refagencies->inventory;
//stores data
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

            Refcars++; 

        }
        refagencies++; 
        
   }
    infile.close();
    cout << "Data has been successfully read from file and stored." << endl;

}

int neededfunction(char a){ 
    return a - '0';
}

void printdata(RentalAgency * agencies){
    for(int i = 0; i < 3; i++){

        cout << agencies[i].name << ' ';

        for(int j = 0; j < 5; j++){
            cout << agencies[i].zipcode[j];
        }

        cout << "\n";

        for(int k = 0; k < 5; k++){
            cout << agencies[i].inventory[k].getYear() << ' ';
            cout << agencies[i].inventory[k].getMake() << ' ';
            cout << agencies[i].inventory[k].getModel() << ", ";
            cout << "$" << agencies[i].inventory[k].getPrice() << " per day, ";
            cout << "Available: " << boolalpha << agencies[i].inventory[k].getAvailability() << endl;

        }
        cout << "\n";
    }
    cout << "\n";
}

void carRentalCost(RentalAgency * agencies){       //print the contents to a newvar filw

    int selectedAgency, selectedCar, days;

    cout << "Select the agency you want to rent from (pick index): ";
    cin >> selectedAgency;
    cout << "Pick the car you want to rent (pick index): ";
    cin >> selectedCar;
    cout << "How many days would you like to rent that car for: ";
    cin >> days;

    cout << "The "
    << agencies[selectedAgency].inventory[selectedCar].getYear() << ' '
    << agencies[selectedAgency].inventory[selectedCar].getMake() << ' '
    << agencies[selectedAgency].inventory[selectedCar].getModel() << ' '
    << "will cost: $"
    << agencies[selectedAgency].inventory[selectedCar].estimateCost(days)
    << " for " << days << " days." << endl;
}

void themostexspensivecar(RentalAgency * agencies){ //find the most expensive car
    int expensiveAgency = 0, expensiveCar = 0;
    float price = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            float newvar = agencies[i].inventory[j].getPrice();
            if (newvar > price){
                price = newvar;
                expensiveAgency = i;
                expensiveCar = j;
            }
        }
    }
    
    cout << "The " << agencies[expensiveAgency].inventory[expensiveCar].getYear() << ' '
    << agencies[expensiveAgency].inventory[expensiveCar].getMake() << ' '
    << agencies[expensiveAgency].inventory[expensiveCar].getModel() << ' '
    << "is the most expensive car at " << agencies[expensiveAgency].name << endl;
 
   
}

void printAvailable(RentalAgency * agencies){
    char outFilename[100];

    ofstream outfile;
    cout << "What would you like to call the output file: ";
    cin >> outFilename;
    outfile.open(outFilename);

    for(int i = 0; i < 3; i++){

           
          
           

            for(int k = 0; k < 5; k++){
                if(agencies[i].inventory[k].getAvailability() == 1){
                outfile << agencies[i].inventory[k].getYear() << ' ';
                outfile << agencies[i].inventory[k].getMake() << ' ';
                outfile << agencies[i].inventory[k].getModel() << ", ";
                outfile << "$" << agencies[i].inventory[k].getPrice() << " per day, ";
                outfile << "Available: " << boolalpha << agencies[i].inventory[k].getAvailability() << endl;
                }

            }
            cout << "\n";
        }
        cout << "\n";
        outfile.close();
}


void myStringCopy(char* destination, char* source){ 
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
