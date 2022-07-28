#include "Toy.h"

Toy::Toy()
{
    name = "Some name";
    price = 12.1;
    age = 6;
    manufacturer = "Some manufacturer";
    material = "Some material";
}

Toy::Toy(string name, float price, int age, string manufacturer, string material) : Commodity(name, price, age)
{
    this->manufacturer = manufacturer;
    this->material = material;
}

Toy::~Toy()
{
}

void Toy::setManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

void Toy::setMaterial(string material)
{
    this->material = material;
}

string Toy::getManufacturer() const&
{
    return manufacturer;
}

string Toy::getMaterial() const&
{
    return material;
}

void Toy::show() const
{
    cout << "\nType of commodity: " << type();
    cout << "\nName: " << name;
    cout << "\nPrice: " << price;
    cout << "\nAllowed age for buy: " << age;

    cout << "\nManufacturer: " << manufacturer;
    cout << "\nMaterial: " << material << endl;
}

string Toy::type() const
{
    return "Toy";
}

void Toy::save(ofstream& file)
{
    file << type() << endl << name << endl << price << endl << age << endl << manufacturer << endl << material << endl;
}

void Toy::load(ifstream& file)
{
    getline(file, name);
    file >> price >> age;

    char a = file.get();

    getline(file, manufacturer);
    getline(file, material);
}
