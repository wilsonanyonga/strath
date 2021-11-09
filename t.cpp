#include <iostream>
#include<fstream>
#include<string>

using namespace std;


string maleADMN[72], femaleADMN[42];	
string namesMale[72], namesFemale[42];


string admICSA[57], admICSB[57];		
string ICSAnames[57], ICSBnames[57];				
string ICSAgender[57], ICSBgender[57];			
void perfectshuffle(string* males, string* females, string* maleADMN, string* femaleADMN);
void conclusion();
int main()
{

    fstream inputICSA("inputICSA.csv");
    string adm;
    string firstname;
    string secondname;
    string gender;

    int maleCounter = 0;
    int femaleCounter = 0;

    while (getline(inputICSA, adm, ','))
    {

        inputICSA.ignore(2, '"');
        getline(inputICSA, firstname, ',');
        getline(inputICSA, secondname, '"');
        inputICSA.ignore(0, ',');
        getline(inputICSA, gender, '\n');
        

        if (gender == "M")
        {
            maleADMN[maleCounter] = adm;
            namesMale[maleCounter] = firstname + " , " + secondname;
            
            maleCounter++;
        }
        else
        {
            femaleADMN[femaleCounter] = adm;
            namesFemale[femaleCounter] = firstname + " , " + secondname;
         
            femaleCounter++;
        }
        

  
    }

    cout << "End of ICSA. " << endl;
    cout << "\n" << endl;
    inputICSA.close();

    fstream inputICSB("inputICSB.csv");

    while (getline(inputICSB, adm, ','))
    {

        inputICSB.ignore(2, '"');
        getline(inputICSB, firstname, ',');
        getline(inputICSB, secondname, '"');
        inputICSA.ignore(0, ',');
        getline(inputICSB, gender, '\n');


        if (gender == "M")
        {
            maleADMN[maleCounter] = adm;
            namesMale[maleCounter] = firstname + " , " + secondname;

            maleCounter++;
        }
        else
        {
            femaleADMN[femaleCounter] = adm;
            namesFemale[femaleCounter] = firstname + " , " + secondname;

            femaleCounter++;
        }
        


    }
    cout << "End of ICSB. " << endl;
    cout << endl;
    inputICSB.close();

    fstream inputICSC("inputICSC.csv");

    while (getline(inputICSC, adm, ','))
    {

        inputICSC.ignore(2, '"');
        getline(inputICSC, firstname, ',');
        getline(inputICSC, secondname, '"');
        inputICSC.ignore(0, ',');
        getline(inputICSC, gender, '\n');


        if (gender == "M")
        {
            maleADMN[maleCounter] = adm;
            namesMale[maleCounter] = firstname + " , " + secondname;
            maleCounter++;
        }
        else
        {
            femaleADMN[femaleCounter] = adm;
            namesFemale[femaleCounter] = firstname + " , " + secondname;
            femaleCounter++;
        }
        


    }
    cout << "End of ICSC. " << endl;
    inputICSC.close();

	perfectshuffle(namesMale, namesFemale, maleADMN, femaleADMN);

	conclusion();
    return 0;
}
void perfectshuffle(string* males, string* females, string* maleADMN, string* femaleADMN)
{


	string maleA[36], maleB[36], femalesA[21], femalesB[21];
	string admMA[36], admMB[36], admFA[21], admFB[21];



	for (int x = 0; x < 36; x++)
	{
		maleA[x] = males[x];
		maleB[x] = males[x + 36];
		admMA[x] = maleADMN[x];
		admMB[x] = maleADMN[x + 36];
	}
	for (int x = 0; x < 21; x++)
	{
		femalesA[x] = females[x];
		femalesB[x] = females[x + 21];
		admFA[x] = femaleADMN[x];
		admFB[x] = femaleADMN[x + 21];
	}


	int indexICSA = 0;
	int posMaleA = 0;
	int posFemaleA = 0;

	int indexICSB = 0;
	int posMaleB = 0;
	int posFemaleB = 0;

	for (int x = 0; x < 36; x++)
	{

		if (x % 2 == 0)
		{
			admICSA[x] = admMA[posMaleA];
			ICSAnames[x] = maleA[posMaleA];
			ICSAgender[x] = "M";
			posMaleA++;
		}
		else
		{
			admICSA[x] = admMB[posMaleB];
			ICSAnames[x] = maleB[posMaleB];
			ICSAgender[x] = "M";
			posMaleB++;
		}
		indexICSA++;
	}


	for (int x = 0; x < 36; x++)
	{

		if (x % 2 == 0)
		{
			admICSB[x] = admMA[posMaleA];
			ICSBnames[x] = maleA[posMaleA];
			ICSBgender[x] = "M";
			posMaleA++;
		}
		else
		{
			admICSB[x] = admMB[posMaleB];
			ICSBnames[x] = maleB[posMaleB];
			ICSBgender[x] = "M";
			posMaleB++;
		}
		indexICSB++;
	}


	for (int x = 0; x < 21; x++)
	{
		int femaleIndex = x + indexICSA;
		if (x % 2 == 0)
		{
			admICSA[femaleIndex] = admFA[posFemaleA];
			ICSAnames[femaleIndex] = femalesA[posFemaleA];
			ICSAgender[femaleIndex] = "F";
			posFemaleA;
		}
		else
		{
			admICSA[femaleIndex] = admFB[posFemaleB];
			ICSAnames[femaleIndex] = femalesB[posFemaleB];
			ICSAgender[femaleIndex] = "F";
			posFemaleB;
		}
	}


	for (int x = 0; x < 21; x++)
	{

		int femaleIndex = x + indexICSB - 1;
		posFemaleA--;
		if (x % 2 == 0)
		{
			admICSB[femaleIndex] = admFA[posFemaleA];
			ICSBnames[femaleIndex] = femalesA[posFemaleA];
			ICSBgender[femaleIndex] = "F";
			posFemaleA;
		}
		else
		{
			admICSB[femaleIndex] = admFB[posFemaleB];
			ICSBnames[femaleIndex] = femalesB[posFemaleB];
			ICSBgender[femaleIndex] = "F";
			posFemaleB;
		}

	}

}

void conclusion()
{

	ofstream SHuffleICSA("ICSA Shuffled.csv");
	for (int i = 0; i < 57; i++)
	{
		SHuffleICSA << admICSA[i] << "," << "\t";
		SHuffleICSA << ICSAnames[i] << "\t" << ",";
		SHuffleICSA << ICSAgender[i] << endl;
	}

	ofstream SHuffleICSB("ICSB Shuffled.csv");
	for (int i = 0; i < 57; i++)
	{
		SHuffleICSB << admICSB[i] << "," << "\t";
		SHuffleICSB << ICSBnames[i] << "\t" << ",";
		SHuffleICSB << ICSBgender[i] << endl;
	}


	//	Close files
	SHuffleICSA.close();
	SHuffleICSB.close();
}