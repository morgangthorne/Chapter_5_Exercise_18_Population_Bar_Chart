// Chapter_5_Exercise_18_Population_Bar_Chart.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Function Prototypes
int Text_File_Read_Convert(int population[], int size, int &count);
void Prairie_Population(int population[], int count);
bool GetRepeatInfo();

int main()
{
    const int size = 6;
    int population[size];
    int count = 0;
    
    bool User_Repeat;

    do {
        Text_File_Read_Convert(population, size, count);
    
        Prairie_Population(population, count);
    
        User_Repeat = GetRepeatInfo();
    } 
    
    while (User_Repeat); {
        cout << "Thank you for using the program";
        return 0;
    }
}




//Opens and closes file, Uses a fail-state check, While loop increases years by 20 until its reach 2000. 
int Text_File_Read_Convert(int population[], int size, int &count) {

    ifstream inputFile;

    inputFile.open("People.txt");

    if (!inputFile) { //Fail-state check
        cout << "Unable to open file\n";

        return 1;
    }
    
    count = 0;

    cout << "Year:\tPopulation:\n";
    cout << "-------------------\n";

    //Population[count] reads from file and stores each number in a positition within count. count < size makes sure it stops correctly and doesn't read more than whats in the array
    while (count < size && inputFile >> population[count]) { 
        cout << 1900 + (count * 20) << "  \t" << population[count] << endl;

        count++;

    }

    cout << "-------------------\n";

    inputFile.close();
}
    
//Displays year 1900 to 2000 in 20 year intervals, before each year increments by 20 the for loop uses an array to determine how many * are needed for each year.
void Prairie_Population(int population[], int count) {
    int year = 1900;

    cout << "Prairieville Population Growth Chart\n";
    cout << "Each * represents 1,000 people\n";
    cout << "-------------------\n";

    for (int i = 0; i < count; i++) {
        cout << year << ": ";

        int asterisk = population[i] / 1000; //Population already has its values from function above, those values are divided by 1000 and that result is assigned to int asterisk

        for (int a = 0; a < asterisk; a++) {
            cout << "*";
        }

    cout << endl;

    year += 20;
    }
    
}

//Allows user to choose whether they want to repeat program or end it
bool GetRepeatInfo() {
    char choice;
    cout << "Would you like to repeat Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
