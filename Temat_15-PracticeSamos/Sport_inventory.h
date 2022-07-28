#pragma once
#include "Commodity.h"

/*
Х	—порт-инвентарь (название, цена, производитель, возраст, на который рассчитана),

	Х	—порт-инвентарь (, , производитель, ,

*/

class Sport_inventory :
    public Commodity
{
protected:
	string manufacturer;

public:
	Sport_inventory();
	Sport_inventory(string name, float price, int age, string manufacturer);
	~Sport_inventory();


	void setManufacturer(string manufacturer);
	string getManufacturer()const&;

	virtual void show()const override;
	virtual string type()const override;

	virtual void save(ofstream& file);
	virtual void load(ifstream& file);
};

