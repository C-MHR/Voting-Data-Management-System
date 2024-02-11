#pragma once
using namespace std;
struct assembly {
	int number;	 
	string name, party, cnic;
};

void add(assembly p[], int index ,bool signal) {

	cout << "Enter HALQA NUMBER\t: ";
	cin >> p[index].number;
	cout << "Enter Candidate's CNIC\t: ";
	cin >> p[index].cnic;
	cout << "Enter Candidate's Name\t: ";
	cin >> p[index].name;
	cout << "Enter Candidate's Party\t: ";
	cin >> p[index].party;
	ofstream fout;
	if (signal)
	{
		fout.open("NA.txt");
	}
	else
	{
		fout.open("PA.txt");
	}
	for (int i = 0; i < index+1; i++)
	{
		fout << p[i].number << "\t" << p[i].name << "\t"<< p[i].cnic  << "\t" << p[i].party << "\n";
	}
	fout.close();
}
void view(const assembly p[], int index) {
	cout << "HALQA\tCNIC\t\tName\tParty\n";
	for (int i = 0; i < index; i++)
	{
			cout << p[i].number << "\t" << p[i].cnic << "\t" << p[i].name << "\t" << p[i].party<<"\n";
	}

}