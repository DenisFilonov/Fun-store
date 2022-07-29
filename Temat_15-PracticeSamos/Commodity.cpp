#include "Commodity.h"

Commodity::Commodity()
{
    name = "Some commodity";
    price = 12.1;
    age = 6;
}

Commodity::Commodity(string name, float price, int age)
{
    this->name = name;
    if(price > 0) this->price = price;
    if (price > 0) this->age = age;
}

Commodity::~Commodity()
{
}

void Commodity::setName(string name)
{
    this->name = name;
}

void Commodity::setPrice(float price)
{
    if (price > 0) this->price = price;
}

void Commodity::setAge(int age)
{
    if (price > 0) this->age = age;
}

string Commodity::getName() const&
{
    return name;
}

float Commodity::getPrice() const&
{
    return price;
}

int Commodity::getAge() const&
{
    return age;
}

void Commodity::save(ofstream& file)
{
    //Писать не нужно, т.к. никогда не будет доступа, не обратится никогда
}

void Commodity::load(ifstream& file)
{
    //Писать не нужно, т.к. никогда не будет доступа, не обратится никогда
}








bool upPrice(const Commodity* a, const Commodity* b)
{
    return a->getPrice() > b->getPrice();
}

bool dwPrice(const Commodity* a, const Commodity* b)
{
    return !upAge(a, b);
}

bool upAge(const Commodity* a, const Commodity* b)
{
    return a->getAge() > b->getAge();
}

bool dwAge(const Commodity* a, const Commodity* b)
{
    return !upAge(a, b);
}

bool upType(const Commodity* a, const Commodity* b)
{
    return a->type() < b->type();
}

bool dwType(const Commodity* a, const Commodity* b)
{
    return !upType(a, b);
}
