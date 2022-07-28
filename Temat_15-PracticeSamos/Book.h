#pragma once
#include "Commodity.h"

/*
������� 2

�	�����  (��������,  �����,  ����,  ������������,  �������,  ��  �������  ����������), ����� ������������

    �	�����  (,  ,  �����, ������������,  ,

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
    virtual ~Book()override; // �������������� ������� �����, ����� ����� ��������� ���� ������ ����, ��� ��������

    void setAuthor(string author);
    void setEdition(string edition);

    string getAuthor()const&;
    string getEdition()const&;

    virtual void show()const override;
    virtual string type()const override;

    virtual void save(ofstream& file)override;
    virtual void load(ifstream& file)override;
};

