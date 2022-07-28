#pragma once
#include "Commodity.h"

/*
¬ј–»јЌ“ 2

Х	 нига  (название,  автор,  цена,  издательство,  возраст,  на  который  рассчитана), ј¬“ќ– »«ƒј“≈Ћ№—“¬ќ

    Х	 нига  (,  ,  автор, издательство,  ,

*/

class Book :
    public Commodity
{
protected:
    string author;
    string edition;

public:
    Book();
    Book(string name, float price, int age, string author, string edition);
    virtual ~Book()override; // переопредел€ем базовый класс, иначе будет чиститьс€ одно только €дро, без потомков

    void setAuthor(string author);
    void setEdition(string edition);

    string getAuthor()const&;
    string getEdition()const&;

    virtual void show()const override;
    virtual string type()const override;

    virtual void save(ofstream& file)override;
    virtual void load(ifstream& file)override;
};

