#include "CarLot.h"


int CarLot::numOfCars = 0;
CarLot::CarLot()
{
	numOfCars++;
}


CarLot::~CarLot()
{
	repairSize = NULL;
	repairs = NULL;
	numOfCars--;
}

CarLot::CarLot(string Model, int RepairSize, int * Repairs)
{
	model = Model;
	repairSize = RepairSize;
	repairs = Repairs;
}

int CarLot::getNumofCars()
{
	return numOfCars;
}


void CarLot::setModel(string Model)
{
	model = Model;
}

void CarLot::setRepairSize(int RepairSize)
{
	repairSize = RepairSize;
}

void CarLot::setRepairs(int * Repairs)
{
	repairs = Repairs;
}

int CarLot::exception()
{
	if (repairs[0] == 0) {
		throw 0;
	}
}

int CarLot::getArray(int num)
{
	for (int i = 0; i < repairSize; i++) {
		return *(repairs+num);
	}
}




string CarLot::getModel()
{
	return model;
}

int CarLot::getRepairSize()
{
	return repairSize;
}

int CarLot::getRepairs()
{
	return *repairs;
}


