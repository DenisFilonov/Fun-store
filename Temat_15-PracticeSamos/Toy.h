#pragma once
#include "Commodity.h"


/*Х	»грушка(название, цена, производитель, материал, возраст, на который рассчитана),

Х	»грушка(, , производитель, материал, ,*/

class Toy :
    public Commodity
{
protected:
    string manufacturer;
    string material;

public:
    Toy();
    Toy(string name, float price, int age, string manufacturer, string material);
    ~Toy();

    void setManufacturer(string manufacturer);
    void setMaterial(string material);

    string getManufacturer()const&;
    string getMaterial()const&;

    virtual void show()const override;
    virtual string type()const override;

    virtual void save(ofstream& file);
    virtual void load(ifstream& file);
};

