#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

class CarLot
{
public:
	CarLot();
	~CarLot();
	CarLot(string Model, int RepairSize, int* Repairs);
	int getNumofCars();

	void setModel(string Model);
	void setRepairSize( int RepairSize);
	void setRepairs(int* Repairs);

	int getArray(int num);
	int exception();


	string getModel();
	int getRepairSize();
	int getRepairs();


private:
	string model;
	int repairSize;
	int* repairs;
	static int numOfCars;
};

