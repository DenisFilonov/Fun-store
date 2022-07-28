#include "Sport_inventory.h"

Sport_inventory::Sport_inventory()
{
    name = "Some name";
    price = 12.1;
    age = 6;
    manufacturer = "Some manufacturer";
}

Sport_inventory::Sport_inventory(string name, float price, int age, string manufacturer) : Commodity(name, price, age)
{
	this->manufacturer = manufacturer;
}

Sport_inventory::~Sport_inventory()
{
}

void Sport_inventory::setManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

string Sport_inventory::getManufacturer() const&
{
    return manufacturer;
}

void Sport_inventory::show() const
{
    cout << "\nType of commodity: " << type();
    cout << "\nName: " << name;
    cout << "\nPrice: " << price;
    cout << "\nAllowed age for buy: " << age;

    cout << "\nManufacturer: " << manufacturer << endl;
}

string Sport_inventory::type() const
{
    return "Sport inventory";
}

void Sport_inventory::save(ofstream& file)
{
    file << type() << endl << name << endl << price << endl << age << endl << manufacturer << endl;
}

void Sport_inventory::load(ifstream& file)
{
    getline(file, name);
    file >> price >> age;

    char a = file.get();

    getline(file, manufacturer);
}
