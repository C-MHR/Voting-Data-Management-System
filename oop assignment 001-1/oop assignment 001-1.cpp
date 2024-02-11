#include <iostream>
#include <fstream>
#include "Assembly.h"
#include "Voter.h"

using namespace std;

void mainMenu();
void NAmenu();
void PAmenu();
void votingMenu();


int main()
{
	mainMenu();
}


void mainMenu()
{
	while (true) {
		cout << "Voting Management System\n";
		cout << "1.NA Candidate Management \n2.PA Candidate Management \n3.Voting List Management \n4.Exit\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "NA Candidate Management\n";
			NAmenu();
			break;
		case 2:
			cout << "PA Candidate Management\n";
			PAmenu();
			break;
		case 3:
			cout << "Voting List Management\n";
			votingMenu();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Choose valid option from menu\n";
		}
	}
}


void NAmenu()
{
	const int size = 50;
	assembly NA[size] = { 0 };
	
	while (true) {
		ifstream fin;
		fin.open("NA.txt");
		try {
			if (fin.fail())
			{
				throw runtime_error("File Not Found.Enter record to create file\n");
			}
		}
		catch (runtime_error & e)
		{
			cout << "Error!!" << e.what();
		}
		int recordsStored = 0;
		if (!fin.fail())
		{
			while (!fin.eof())
			{
				fin >> NA[recordsStored].number >> NA[recordsStored].name >> NA[recordsStored].cnic >> NA[recordsStored].party;
				recordsStored++;
			}
			recordsStored -= 1;
		}

		cout << "1.Add \n2.View \n3.Back\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Calling Add function\n";
			add(NA, recordsStored, 1);
			break;
		case 2:
			cout << "Calling View function\n";
			view(NA, recordsStored);
			break;
		case 3:
			mainMenu();
			break;
		default:
			cout << "Choose valid option from menu\n";
		}
	}
}


void PAmenu()
{
	const int size = 50;
	assembly PA[size] = { 0 };
	
	while (true) {
		ifstream fin;
		fin.open("PA.txt");
		try {
			if (fin.fail())
			{
				throw runtime_error("File Not Found.Enter record to create file\n");
			}
		}
		catch (runtime_error & e)
		{
			cout << "Error!!" << e.what();
		}
		int recordsStored = 0;
		if (!fin.fail())
		{
			while (!fin.eof())
			{
				fin >> PA[recordsStored].number >> PA[recordsStored].name >> PA[recordsStored].cnic >> PA[recordsStored].party;
				recordsStored++;
			}
			recordsStored -= 1;
		}

		cout << "1.Add \n2.View \n3.Back\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Calling Add function\n";
			add(PA, recordsStored, 0);
			break;
		case 2:
			cout << "Calling View function\n";
			view(PA, recordsStored);
			break;
		case 3:
			mainMenu();
			break;
		default:
			cout << "Choose valid option from menu\n";
		}
	}
}


void votingMenu() 
{
	const int size = 50;
	voter Voters[size] = { 0 };
	
	while (true) {

		ifstream fin;
		fin.open("Voters_Detail.txt");
		try {
			if (fin.fail())
			{
				throw runtime_error("File Not Found.Enter record to create file\n");
			}
		}
		catch (runtime_error & e)
		{
			cout << "Error!!" << e.what();
		}
		int recordsStored = 0;
		if (!fin.fail())
		{
			while (!fin.eof())
			{
				fin >> Voters[recordsStored].cnic >> Voters[recordsStored].area >> Voters[recordsStored].NAnumber >> Voters[recordsStored].PAnumber >> Voters[recordsStored].blockCode;
				recordsStored++;
			}
			recordsStored -= 1;
		}


		cout << "1.Add \n2.View \n3.Search \n4.Back\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Calling Add function\n";
			add(Voters, recordsStored);
			break;
		case 2:
			cout << "Calling View function\n";
			view(Voters, recordsStored);
			break;
		case 3:
			cout << "Calling Search function\n";
			uint64_t required;
			cout << "Enter CNIC to search ";
			cin >> required;
			bool flag;
			flag= search(Voters, recordsStored, required);
			if (flag)
				cout << "voter exists\n";
			else
				cout << "Record not found\n";
			break;
		case 4:
			mainMenu();
			break;
		default:
			cout << "Choose valid option from menu\n";
		}
	}
}
