#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*
¬ј–»јЌ“ 2
—оздать  абстрактный  класс Ђ“оварї с  методами,  позвол€ющими  вывести  на  экран информацию  о  товаре,  а  также  определить,  соответствует  ли  она  искомому  типу.
—оздать производные классы:

Х	»грушка (название, цена, производитель, материал, возраст, на который рассчитана), 
Х	 нига  (название,  цена,  автор, издательство,  возраст,  на  который  рассчитана),  
Х	—порт-инвентарь (название, цена, производитель, возраст, на который рассчитана),
	со своими методами вывода информации на экран, и определени€ соответстви€ искомому типу.

	Х	»грушка (, , производитель, материал, ,
	Х	 нига  (,  ,  автор, издательство,  ,
	Х	—порт-инвентарь (, , производитель, ,
	*/

class Commodity
{
protected:
	string name;
	float price;
	int age;

public:
	//=================================CONSTRUCTORS===================
	Commodity();
	Commodity(string name, float price,	int age);
	virtual ~Commodity(); // надо ли virtual ? ѕотому, что потомки сюда обращаютс€

	//=================================SETTERS========================
	void setName(string name);
	void setPrice(float price);
	void setAge(int age);

	//=================================GETTERS========================
	string getName()const&;
	float getPrice()const&;
	int getAge()const&;

	//=================================VIRTUAL========================
	virtual void show()const = 0;
	virtual string type()const = 0;

	virtual void save(ofstream& file);
	virtual void load(ifstream& file);
};

//=================================LOGIC==============================
bool upPrice(const Commodity* a, const Commodity* b);
bool dwPrice(const Commodity* a, const Commodity* b);

bool upAge(const Commodity* a, const Commodity* b);
bool dwAge(const Commodity* a, const Commodity* b);

bool upType(const Commodity* a, const Commodity* b);
bool dwType(const Commodity* a, const Commodity* b);