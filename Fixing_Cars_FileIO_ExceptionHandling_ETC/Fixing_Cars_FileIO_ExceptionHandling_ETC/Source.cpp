//Angela Pham PS#1363875

#include<iostream>
#include <string>
#include "CarLot.h"
#include<fstream>
using namespace std;

struct RepairList 
{
	int repairCode;
	string repairPart;
};
vector<RepairList> repairs; //vector of RepairsList varibles
void setrList(istream& txtfile);

vector <CarLot> carsLot; //vector of CarLot varibles
void setCarList(istream & txtfile);

void needRepairs(CarLot arr);

int main() {
	ifstream cars;
	cars.open("Cars.txt");
	if (cars.fail())
	{
		cout << "File \"Cars.txt\" cannot be opened." << endl;
		system("pause");
		return 1;
	}
	setCarList(cars);

	ifstream repairList("RepairsKey.txt");
	if (repairList.fail())
	{
		cout << "File \"RepairsKey.txt\" cannot be opened." << endl;
		system("pause");
		return 1;
	}
	setrList(repairList);
	
	for (int i = 0; i < carsLot.size(); i++) {
		cout << "Car Model: " << carsLot[i].getModel() << endl;
		try {
			carsLot[i].exception(); //check exception
			needRepairs(carsLot[i]); // compare each arrray element to the repair codes 
		}
		catch (int x) {
				cout << "Pass: Car is done" << endl;
		}
		cout << endl;

	}
	cars.close();
	repairList.close();
	system("pause");
	return 0;
}

void setrList(istream& txtfile) {
	repairs.clear();
	RepairList temp = RepairList();
	while (txtfile >> temp.repairCode)
	{
		getline(txtfile, temp.repairPart);
		repairs.emplace_back(temp);
	}
}

void setCarList(istream & txtfile) 
{
	string mod;
	while (txtfile >> mod) {
		string tempr;
		getline(txtfile, tempr);
		stringstream stream(tempr);

		while (stream) {
			int n;
			int counter = 1;
			int *reps = new int[counter];
			while (stream >> n) {
				if (counter > 1) {
					int *temparr = new int[counter];
					for (int i = 0; i < counter - 1; i++) {
						temparr[i] = reps[i];
					}
					delete[] reps;
					reps = temparr;
				}
				reps[counter - 1] = n;
				counter++;				
			}

			CarLot temp = CarLot(mod, counter - 1, reps); 
			carsLot.emplace_back(temp);
		}

	}

}

void needRepairs(CarLot arr)
{
	for (int i = 0; i < arr.getRepairSize(); i++)
	{

		if (arr.getArray(i) == repairs[1].repairCode)
			cout << "Repair #" << i + 1 << ": " << repairs[1].repairPart << endl;

		else if (arr.getArray(i) == repairs[2].repairCode)
			cout << "Repair #" << i + 1 << ": " << repairs[2].repairPart  << endl;

		else if (arr.getArray(i) == repairs[3].repairCode)
			cout << "Repair #" << i + 1 << ": " << repairs[3].repairPart << endl;

		else if (arr.getArray(i) == repairs[4].repairCode)
			cout << "Repair #" << i + 1 << ": " << repairs[4].repairPart << endl;

		else if (arr.getArray(i) == repairs[5].repairCode)
			cout << "Repair #" << i + 1 << ": " << repairs[5].repairPart << endl;

		else if (arr.getArray(i) == repairs[6].repairCode)
			cout << "Repair #" << i + 1 << ": " << repairs[6].repairPart << endl;
	}
	cout << endl;
}