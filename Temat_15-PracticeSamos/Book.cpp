#include "Book.h"

Book::Book()
{
    name = "Some name";
    price = 12.1;
    age = 6;
    author = "Some name";
    edition = "Some edition";
}

Book::Book(string name, float price, int age, string author, string edition) : Commodity(name, price, age)
{
    this->author = author;
    this->edition = edition;
}

Book::~Book()
{
}

void Book::setAuthor(string author)
{
    this->author = author;
    cout << "\nError. Input correctly author's initials!\n\n";
}

void Book::setEdition(string edition)
{
    if (edition.size() <= 4) this->author = author;
    else cout << "\nError. Input correctly edition!\n\n";
}

string Book::getAuthor() const&
{
    return author;
}

string Book::getEdition() const&
{
    return edition;
}

void Book::show() const
{
    cout << "\nType of commodity: " << type();
    cout << "\nName: " << name;
    cout << "\nPrice: " << price;
    cout << "\nAllowed age for buy: " << age;

    cout << "\nAuthor: " << author;
    cout << "\nEdition: " << edition << endl;
}

string Book::type() const
{
    return "Book";
}

void Book::save(ofstream& file)
{
    file << type() << endl << name << endl << price << endl << age << endl << author << endl << edition << endl;
}

void Book::load(ifstream& file)
{
    getline(file, name);
    file >> price >> age;

    char a = file.get();

    getline(file, author);
    getline(file, edition);
}
