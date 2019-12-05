// Noah Hoffman Project1 CS202
#include <iostream>
#include <fstream>
using namespace std;

void myStringCopy(char destination[], const char source[]);

int myStringLength(const char str []);

int myStringCompare(const char str1[], const char str2[]);

void swap(char input[10][9],int index, int index2);

void sort(char input[10][9],int input2[], int arraySize );

void length(char input[10][9],int input2[],int arraySize);

void intswap(int input[10],int index, int index2);

int main()
{
char Cstring[10][9];
char input[100];
char file2[100];
char file3[100];
char temp[100];
int order[10] = {0, 1, 2, 3,4,5,6,7,8,9};

//gets input file
cout << "Please enter your input file name.\n";
ifstream inputFile;
cin.getline(input,100);
inputFile.open(input);

//creates output file for sorted by length
cout << "Please enter your output file name for sorted by length.\n";
ofstream outputFile;
cin.getline(file2,100);
outputFile.open(file2);


//creates output file for sorted alphebtically
cout << "Please enter your output file name for sorted alphebtically.\n";
ofstream outputFile2;
cin.getline(file3,100);
outputFile2.open(file3);

cout << "Unsorted Data (Original Input Order and Name)\n";
cout << "=============================================\n";

//stores names in 2 dimensional array and prints them to terminal
for (int i=0;i<10;i++){
	inputFile >> Cstring[i];
}

for (int i=0;i<10;i++){
	cout << order[i] << " " << Cstring[i] << "\n";


}




//sorts list of names by length 

length(Cstring,order,10);



//Prints the list of sorted-by-length names to the terminal
cout << "Sorted-by-Length Data (Original Input Order and Name)\n";
cout << "=============================================\n";
outputFile << "Sorted-by-Length Data (Original Input Order and Name)\n";
outputFile << "=============================================\n";

for (int i=0;i<10;i++){
	cout << order[i] << " " << Cstring[i] << "\n";
	outputFile << order[i] << " " << Cstring[i] << "\n";
}


//Writes the list of sorted-by-length names to an output file

//Re-sorts the list of names alphabetically this time.
sort(Cstring,order,10);

//Prints the list of alphabetically-sorted names to the terminal and Writes the list of alphabetically-sorted names to a different output file
cout << "Alphabetcially Sorted Data (Original Input Order and Name)\n";
cout << "=============================================\n";
outputFile2 << "Alphabetcially Sorted Data (Original Input Order and Name)\n";
outputFile2 << "=============================================\n";

for (int i=0;i<10;i++){
	cout << order[i] << " " << Cstring[i] << "\n";
	outputFile2 << order[i] << " " << Cstring[i] << "\n";
}











inputFile.close();
outputFile.close();
outputFile2.close();




return 0;
}

//copy function
void myStringCopy(char destination[], const char source[]){
int i=0;
	while(source[i]!='\0'){
	destination[i]=source[i];
		i++;
				}
	destination[i]='\0';

}
//length function
int myStringLength(const char str []){
	int i=0;
		while(str[i] !='\0'){
		i++;
}
return i;

}
//string compare function
int myStringCompare(const char str1[], const char str2[]){
	int i=0;
		while(str1[i]!='\0'||str2[i]!='\0'){
				if (str1[i]>str2[i]){
				return 1;}
					if (str1[i]<str2[i]){
					return -1;}
		i++;

}


}


//swap function
void swap(char input[10][9],int index, int index2){
char temp[9];
	myStringCopy(temp,input[index]);
		myStringCopy(input[index], input[index2]);
			myStringCopy(input[index2], temp);
}
//integer swap function
void intswap(int input[10],int index, int index2){
int temp = 0;
	temp = input[index];
	input[index] = input[index2];
	input[index2]=temp;
}
// Alphebetical sort function
void sort(char input[10][9],int input2[], int arraySize ){
bool swapper=true;
int pos=0;
int last=0;

	while(swapper){
	swapper=false;
		for(int i=0;i<arraySize-1;i++){
			last=myStringCompare(input[i],input[i+1]);
			if (last==1){
			swap(input,pos,pos+1);
			intswap(input2,pos,pos+1);
			swapper=true;
}
	pos++;
}

pos=0;
}

}
//length function
void length(char input[10][9],int input2[],int arraySize){
bool swapper=true;
int pos=0;
int last=0;

	while(swapper){
	swapper=false;
		for(int i=0;i<arraySize-1;i++){
			last=(myStringLength(input[i])>myStringLength(input[i+1]));
			if (last==1){
			swap(input,pos,pos+1);
			intswap(input2,pos,pos+1);
			swapper=true;
}
	pos++;
}

pos=0;
}

}






