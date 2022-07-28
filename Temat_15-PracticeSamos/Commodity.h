#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*
������� 2
�������  �����������  ����� ������ �  ��������,  ������������  �������  ��  ����� ����������  �  ������,  �  �����  ����������,  �������������  ��  ���  ��������  ����.
������� ����������� ������:

�	������� (��������, ����, �������������, ��������, �������, �� ������� ����������), 
�	�����  (��������,  ����,  �����, ������������,  �������,  ��  �������  ����������),  
�	�����-��������� (��������, ����, �������������, �������, �� ������� ����������),
	�� ������ �������� ������ ���������� �� �����, � ����������� ������������ �������� ����.

	�	������� (, , �������������, ��������, ,
	�	�����  (,  ,  �����, ������������,  ,
	�	�����-��������� (, , �������������, ,
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
	virtual ~Commodity(); // ���� �� virtual ? ������, ��� ������� ���� ����������

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