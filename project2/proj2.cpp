// Noah Hoffman Project2 proj2.h CS202
#include <iostream>
#include <fstream>
using namespace std;

struct RentalCar {
  int year;
char make[11];
char model[11];
float price;
bool avalable;
};

int main()
{

int car;
int choice;
int days;
char inputfile1[100];
char outputfile1[100];
RentalCar rentalCar[5];
ifstream inputFile;
ofstream outputFile;
do
{


cout << endl
<< " 1 - Input file.\n"
<< " 2 - Print all data.\n"
<< " 3 - Print out ALL data for all of the cars to a separate output file.\n"
<< " 4 - Sort the cars by ascending price.\n"
<< " 5 -  how many days of rental do you want ?  .\n"
<< " 6 - Rent a car.\n"
<< " 7 - Exit.\n"
<< " Enter your choice and press return: ";
cin >> choice;

switch (choice)
{
case 1:
//gets input file
cout << "Please enter your input file name.\n";
cin >> inputfile1;
inputFile.open(inputfile1);

if(!inputFile){
cout << "File cannot be opened";
system("EXIT");
exit(1);
}



//stores data into array structs
for (int i=0;i<5;i++){
	inputFile >> rentalCar[i].year >> rentalCar[i].make >> rentalCar[i].model >> rentalCar[i].price >> rentalCar[i].avalable;
}
break;

case 2:
//Print out ALLdata for each of the cars to the terminal
for (int i=0;i<5;i++){
cout <<"["<< i <<"]: "<< rentalCar[i].year << "  ";
cout << rentalCar[i].make << "  ";
cout << rentalCar[i].model << "  ,$";
cout << rentalCar[i].price << " per day, Available:   ";
if(rentalCar[i].avalable==0){
cout << " false  \n";}
if(rentalCar[i].avalable==1){
cout << " true  \n";}
}
break;
case 3:
//Print out ALLdata for all of the carsto a separate output file

//creates outputfile
cout << "Please enter your output file name.\n";
cin >> outputfile1;
outputFile.open(outputfile1);

//stores in outputfile
for (int i=0;i<5;i++){
outputFile << rentalCar[i].year << " " << rentalCar[i].make << " " << rentalCar[i].model << " " << rentalCar[i].price << " " << rentalCar[i].avalable << "\n";

}
break;
case 4:
//Sort the cars by ascending price.

for(int j=0;j<4;j++){
for(int i=0;i<4;i++){
if(rentalCar[i].price > rentalCar[i+1].price){
RentalCar temp=rentalCar[i];
rentalCar[i] = rentalCar[i+1];
rentalCar[i+1]=temp;
}
}
}

for (int i=0;i<5;i++){
cout <<"["<< i <<"]: "<< rentalCar[i].year << "  ";
cout << rentalCar[i].make << "  ";
cout << rentalCar[i].model << "  ,$";
cout << rentalCar[i].price << " per day, Available:   ";
if(rentalCar[i].avalable==0){
cout << " false  \n";}
if(rentalCar[i].avalable==1){
cout << " true  \n";}
}

break;
case 5:
cout << "How many days would you like to rent a car?\n";
cin >> days;
//Sort the cars by ascending price.

for(int j=0;j<4;j++){
for(int i=0;i<4;i++){
if(rentalCar[i].price > rentalCar[i+1].price){
RentalCar temp=rentalCar[i];
rentalCar[i] = rentalCar[i+1];
rentalCar[i+1]=temp;
}
}
}

//print out avaliable cars

for (int i=0;i<5;i++){
if(rentalCar[i].avalable==1){
cout <<"["<< i <<"]: "<< rentalCar[i].year << "  ";
cout << rentalCar[i].make << "  ";
cout << rentalCar[i].model << "  ,Total Cost$ ";
cout << rentalCar[i].price * days << " \n";
}
}

break;
case 6:





//asks user what car
cout << "\n What car do you want to rent?\n";
cin >> car;
if(rentalCar[car].avalable==0){
cout << "This car is not avalable. Please try again . \n ";
break;
}

cout << "How many days would you like to rent a car?\n";
cin >> days;

if(rentalCar[car].avalable==1){
rentalCar[car].avalable=0;
cout << "Congrats your car has been rented out, your total price is : $"<< rentalCar[car].price * days << " \n";
}




break;
case 7:
cout << "End of Program.\n";
break;
default:
cout << "Not a Valid Choice. \n"
<< "Choose again.\n";
break;
}

}while (choice !=7);
return 0;




}
