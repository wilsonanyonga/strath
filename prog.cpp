#include <iostream>
#include<fstream>
#include<string>

using namespace std;

string maleADMN[71],  femaleADMN[42];	
string namesMale[71], namesFemale[42];
//string names2Male[71], names2Female[42];
string genderMale[71], genderFemale[42];

int main()
{

    ifstream inputICSA;
    if (inputICSA.is_open()) cout << "error: file open" << '\n';
    inputICSA.open("inputICSA.csv");
    string adm;
    string name;
    string firstname;
    string secondname;
    string gender;
	
	int maleTotal = 0;
	int femaleTotal = 0;
	
	
    int maleCounter = 0;
    int femaleCounter = 0;

    while (getline(inputICSA, adm, ','))
    {
//        inputICSA.ignore(1, '"');
//		getline(inputICSA, name, ',');
        getline(inputICSA, firstname, ',');
        getline(inputICSA, secondname, ',');
//        inputICSA.ignore(0, '"');
        getline(inputICSA, gender, '\n');
        

        if (gender == "M")
        {
            maleADMN[maleCounter] = adm;
            namesMale[maleCounter] = firstname + ", " + secondname;
            genderMale[maleCounter] = gender;
            
            maleCounter++;
            maleTotal++;
        }
        else
        {
            femaleADMN[femaleCounter] = adm;
            namesFemale[femaleCounter] = firstname + ", " + secondname;
            genderFemale[femaleCounter] = gender;
         
            femaleCounter++;
            femaleTotal++;
        }
//        cout << adm << " " << firstname << ", " << secondname << " " << gender  << endl;

  
    }
    
    ifstream inputICSB;
    if (inputICSB.is_open()) cout << "error: file open" << '\n';
    inputICSB.open("inputICSB.csv");
    string admB;
    string firstnameB;
    string secondnameB;
    string genderB;

    int maleCounterB = 19;
    int femaleCounterB = 11;

    while (getline(inputICSB, admB, ','))
    {
//        inputICSA.ignore(1, '"');
//		getline(inputICSA, name, ',');
        getline(inputICSB, firstnameB, ',');
        getline(inputICSB, secondnameB, ',');
//        inputICSA.ignore(0, '"');
        getline(inputICSB, genderB, '\n');
        

        if (genderB == "M")
        {
            maleADMN[maleCounterB] = admB;
            namesMale[maleCounterB] = firstnameB + ", " + secondnameB;
            genderMale[maleCounterB] = genderB;
            
            maleCounterB++;
            maleTotal++;
        }
        else
        {
            femaleADMN[femaleCounterB] = admB;
            namesFemale[femaleCounterB] = firstnameB + ", " + secondnameB;
            genderFemale[femaleCounterB] = genderB;
         
            femaleCounterB++;
            femaleTotal++;
        }
//        cout << admB << " " << firstnameB << ", " << secondnameB << " " << genderB  << endl;

  
    }
    
    ifstream inputICSC;
    if (inputICSC.is_open()) cout << "error: file open" << '\n';
    inputICSC.open("inputICSC.csv");
    string admC;
    string firstnameC;
    string secondnameC;
    string genderC;

    int maleCounterC = 35;
    int femaleCounterC = 23;

    while (getline(inputICSC, admC, ','))
    {
//        inputICSA.ignore(1, '"');
//		getline(inputICSA, name, ',');
        getline(inputICSC, firstnameC, ',');
        getline(inputICSC, secondnameC, ',');
//        inputICSA.ignore(0, '"');
        getline(inputICSC, genderC, '\n');
        

        if (genderC == "M")
        {
            maleADMN[maleCounterC] = admC;
            namesMale[maleCounterC] = firstnameC + ", " + secondnameC;
            genderMale[maleCounterC] = genderC;
            
            maleCounterC++;
            maleTotal++;
        }
        else
        {
            femaleADMN[femaleCounterC] = admC;
            namesFemale[femaleCounterC] = firstnameC + ", " + secondnameC;
            genderFemale[femaleCounterC] = genderC;
         
            femaleCounterC++;
            femaleTotal++;
        }
//        cout << admC << " " << firstnameC << ", " << secondnameC << " " << genderC  << endl;

  
    }
    
//    int arrSize = sizeof(namesMale)/sizeof(namesMale[0]);
//    cout << "The size of the array is: " << arrSize<< endl;
    
    size_t n = sizeof(namesMale)/sizeof(namesMale[0]);
 	
 	size_t fem = sizeof(namesFemale)/sizeof(namesFemale[0]);
 	
    // loop through the array elements
    for (size_t i = 0; i < 36; i++) {
        std::cout << maleADMN[i] << ' '<< namesMale[i] << ' '<< genderMale[i] << endl;
    }
    cout <<  "\n";
    for (size_t i2 = 0; i2 < 21; i2++) {
        std::cout << femaleADMN[i2] << ' '<< namesFemale[i2] << ' '<< genderFemale[i2] << endl;
    }
    cout <<  "\n";
    for (size_t i = 36; i < n; i++) {
        std::cout << maleADMN[i] << ' '<< namesMale[i] << ' '<< genderMale[i] << endl;
    }
    cout <<  "\n";
    for (size_t i2 = 21; i2 < fem; i2++) {
        std::cout << femaleADMN[i2] << ' '<< namesFemale[i2] << ' '<< genderFemale[i2] << endl;
    }
    cout <<  "\n";
	
	cout << maleTotal << endl;
    cout << femaleTotal << endl;
    
    cout << femaleCounter<< endl;
    cout << maleADMN[70]<< " ";
    cout << namesMale[70]<< " ";
    cout << genderMale[70]<< endl;
    cout << "End of ICSA. " << endl;
    cout << "\n" << endl;
    inputICSA.close();
}
