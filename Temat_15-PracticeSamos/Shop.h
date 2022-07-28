#pragma once
#include "Commodity.h"
#include "Book.h"
#include "Toy.h"
#include "Sport_inventory.h"

class Shop // Класс контейнер
{
private:
	Commodity** arr;
	int size;

public:
	Shop();
	~Shop();

	int getSize()const&;
	void addCommodity(Commodity& obj);
	void deleteCommodity(string name);
	void editCommodity(string name)const&;
	void editCommodityByID(int id)const&; //id


	void showShop()const&;
	int findCommodityByName(string name)const&;
	void showCurrentType(string type)const&;
	void showCommodityByName(string name)const&;

	void sort(bool(*cmp)(const Commodity*, const Commodity*))const&;

	void save();
	void load();
};