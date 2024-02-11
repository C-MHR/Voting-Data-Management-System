#pragma once
using namespace std;
struct voter {
	uint64_t cnic;
	string area;
	int NAnumber, PAnumber, blockCode;
};
void add(voter p[], int index)
{	
	cout << "Enter Voter's CNIC\t: ";
	cin >> p[index].cnic;
	cout << "Enter Area\t\t: ";
	cin >> p[index].area;
	cout << "Enter NA Number\t\t: ";
	cin >> p[index].NAnumber;
	cout << "Enter PA Number\t\t: ";
	cin >> p[index].PAnumber;
	cout << "Enter Block Code\t: ";
	cin >> p[index].blockCode;
	ofstream fout;
	fout.open("Voters_Detail.txt");

	for (int i = 0; i < index + 1; i++)
	{
		fout << p[i].cnic << "\t" << p[i].area << "\t" << p[i].NAnumber << "\t" << p[i].PAnumber << "\t" << p[i].blockCode << "\n";
	}
	fout.close();
}
void view(voter p[], int index)
{
	cout << "CNIC\t\tArea\tNA#\tPA#\tBlockCode\n";
	for (int i = 0; i < index; i++)
	{
		cout << p[i].cnic << "\t" << p[i].area << "\t" << p[i].NAnumber << "\t" << p[i].PAnumber << "\t" << p[i].blockCode << "\n";
	}
}
bool search(voter p[], int index, uint64_t required)
{
	for (int i = 0; i < index; i++)
	{
		if (p[i].cnic==required)
		{
			return 1;
		}
	}
	return 0;
}