#include "Shop.h"

Shop::Shop()
{
    arr = nullptr;
    size = 0;
}

Shop::~Shop()
{
    if (arr != nullptr)
    {
        int i = 0;
        while(i < size)
        {
            arr[i++]->~Commodity();
        }
    }
    delete arr;
}

int Shop::getSize() const&
{
    return size;
}

void Shop::addCommodity(Commodity& obj)
{
    Commodity** tmp = new Commodity* [++size];
    if (arr != nullptr) memcpy(tmp, arr, sizeof(arr) * (size - 1)); // Побайтное копирование вместо цикла. Привет Железняку Антону
    if (arr != nullptr) delete[] arr;
    tmp[size - 1] = &obj;
    arr = tmp;
    cout << "\nThe commodity has been successfully placed in shop!\n\n";
}

void Shop::deleteCommodity(string name)
{
    if (size == 0) cout << "\nThe shop neither closed nor empty.\n\n";
    else
    {
        int id = findCommodityByName(name);
        if (id == -1) cout << "\nAccomodation wasn't found. Check input data.\n\n";
        else
        {
            Commodity** tmp = new Commodity * [--size];
            int i = 0;
            while (i < size)
            {
                if (i < id) tmp[i] = arr[i];
                else if (i >= id) tmp[i] = arr[i + 1];
                i++;
            }
            arr[id]->~Commodity();//<<<  !!!! без этого попросту засрём память и п-здарики на воздушном шарике ОЗУ.
            if (arr != nullptr) delete[] arr;
            arr = tmp;
            cout << "\nThe commodity with identification number on system [" << id + 1 << "] has been succesfully deleted from database!\n\n";
        }
    }
}

void Shop::editCommodity(string name) const&
{
    int id = findCommodityByName(name);

    if (id == -1) cout << "\nAccomodation wasn't found. Check input data.\n\n";
    else
    {
        int menu = 0;
        string s1 = "", s2 = "", s3 = "";
        int ivalue = 0;
        float fvalue = 0;

        if (arr[id]->type() == "Book")
        {
            /*	string name;
            float price;
            int age;
            string author;
            string edition;*/
            do
            {
                cout << "\n\tMENU TO CHANGE INFORMATION:";
                cout << "\n1) Name.";
                cout << "\n2) Price.";
                cout << "\n3) Age.";
                cout << "\n4) Author.";
                cout << "\n5) Edition.";
                cout << "\n6) All of this.";
                cout << "\n0) Turn back to main menu.\nChoice: ";

                cin >> menu;
                switch (menu)
                {
                case 1:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);
                    cout << "\nName set succesfully!\n\n";
                    break;

                case 2:
                    cout << "\nInput price: ";
                    cin >> fvalue;
                    arr[id]->setPrice(fvalue);
                    cout << "\nPrice set succesfully!\n\n";
                    break;

                case 3:
                    cout << "\nInput age: ";
                    cin >> ivalue;
                    arr[id]->setPrice(ivalue);
                    cout << "\nAge set succesfully!\n\n";
                    break;

                case 4:
                    cout << "\nInput author: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Book*)arr[id])->setAuthor(s1);
                    cout << "\nAuthor set succesfully!\n\n";
                    break;

                case 5:
                    cout << "\nInput edition: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Book*)arr[id])->setEdition(s1);
                    cout << "\nEdition set succesfully!\n\n";
                    break;

                case 6:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);

                    cout << "\nInput price: ";
                    cin >> fvalue;
                    arr[id]->setPrice(fvalue);

                    cout << "\nInput age: ";
                    cin >> ivalue;
                    arr[id]->setPrice(ivalue);

                    cout << "\nInput author: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Book*)arr[id])->setAuthor(s1);

                    cout << "\nInput edition: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Book*)arr[id])->setEdition(s1);

                    cout << "\nAll information set succesfully!\n\n"; break;
                    break;

                default: if (menu > 6 && menu != 0 || menu < 0) cout << "\nWrong menu item selected.\n\n"; break;
                }

            } while (menu != 0);
        }
        else if (arr[id]->type() == "Toy")
        {
            /*	string name;
            float price;
            int age;
            string manufacturer;
            string material;*/
            do
            {
                cout << "\n\tMENU TO CHANGE INFORMATION:";
                cout << "\n1. Name.";
                cout << "\n2. Price.";
                cout << "\n3. Age.";
                cout << "\n4. Manufacturer.";
                cout << "\n5. Material.";
                cout << "\n6. All of this.";
                cout << "\n0. Turn back to main menu.\nChoice: ";

                cin >> menu;
                switch (menu)
                {
                case 1:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);
                    cout << "\nName set succesfully!\n\n";
                    break;

                case 2:
                    cout << "\nInput price: ";
                    cin >> fvalue;
                    arr[id]->setPrice(fvalue);
                    cout << "\nPrice set succesfully!\n\n";
                    break;

                case 3:
                    cout << "\nInput age: ";
                    cin >> ivalue;
                    arr[id]->setPrice(ivalue);
                    cout << "\nAge set succesfully!\n\n";
                    break;

                case 4:
                    cout << "\nInput manufacturer: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Toy*)arr[id])->setManufacturer(s1);
                    cout << "\nManufacturer set succesfully!\n\n";
                    break;

                case 5:
                    cout << "\nInput material: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Toy*)arr[id])->setMaterial(s1);
                    cout << "\nMaterial set succesfully!\n\n";
                    break;

                case 6:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);

                    cout << "\nInput price: ";
                    cin >> fvalue;
                    arr[id]->setPrice(fvalue);

                    cout << "\nInput age: ";
                    cin >> ivalue;
                    arr[id]->setPrice(ivalue);

                    cout << "\nInput manufacturer: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Book*)arr[id])->setAuthor(s1);

                    cout << "\nInput material: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Book*)arr[id])->setEdition(s1);

                    cout << "\nAll information set succesfully!\n\n";
                    break;

                default: if (menu > 6 && menu != 0 || menu < 0) cout << "\nWrong menu item selected.\n\n"; break;
                }

            } while (menu != 0);
        }
        else if (arr[id]->type() == "Sport inventory")
        {
            /*	string name;
            float price;
            int age;
            string manufacturer;*/
            do
            {
                cout << "\n\tMENU TO CHANGE INFORMATION:";
                cout << "\n1. Name.";
                cout << "\n2. Price.";
                cout << "\n3. Age.";
                cout << "\n4. Manufacturer.";
                cout << "\n5. All of this.\nChoice: ";

                cin >> menu;
                switch (menu)
                {
                case 1:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);
                    cout << "\nName set succesfully!\n\n";
                    break;

                case 2:
                    cout << "\nInput price: ";
                    cin >> fvalue;
                    arr[id]->setPrice(fvalue);
                    cout << "\nPrice set succesfully!\n\n";
                    break;

                case 3:
                    cout << "\nInput age: ";
                    cin >> ivalue;
                    arr[id]->setPrice(ivalue);
                    cout << "\nAge set succesfully!\n\n";
                    break;

                case 4:
                    cout << "\nInput manufacturer: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Book*)arr[id])->setAuthor(s1);
                    cout << "\nManufacturer set succesfully!\n\n";
                    break;

                case 5:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);

                    cout << "\nInput price: ";
                    cin >> fvalue;
                    arr[id]->setPrice(fvalue);

                    cout << "\nInput age: ";
                    cin >> ivalue;
                    arr[id]->setPrice(ivalue);

                    cout << "\nInput manufacturer: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Sport_inventory*)arr[id])->setManufacturer(s1);

                    cout << "\nAll information set succesfully!\n\n";
                    break;

                default: if (menu > 5 && menu != 0 || menu < 0) cout << "\nWrong menu item selected.\n\n"; break;
                }

            } while (menu != 0);
        }
    }
}

void Shop::editCommodityByID(int id) const&
{
    string tmp = "";
    tmp = arr[id]->getName();
    editCommodity(tmp);
}

void Shop::showShop() const&
{
    if (size == 0) cout << "\nThe shop neither closed nor empty.\n\n";
    else
    {
        int i = 0;
        while (i < size)
        {
            cout << "\n\tCommodity #" << i + 1 << endl;
            arr[i++]->show();
        }
    }
}

int Shop::findCommodityByName(string name) const&
{
    int i = 0;
    while (i < size)
    {
        if (arr[i]->getName() == name)
        {
            return i;
            break;
        }
        i++;
    }
    return -1;
}

void Shop::showCurrentType(string type) const&
{
    int i = 0, check = 0;
    while (i < size)
    {
        if (arr[i]->type() == type)
        {
            cout << "\n\tCommodity {" << type << "}:";
            arr[i]->show();
            check++;
        }
        i++;
    }
    if (check == 0) cout << "\nError. The type wasn't found.\n\n";
}

void Shop::showCommodityByName(string name) const&
{
    int id = findCommodityByName(name);

    if (id == -1) cout << "\nAccomodation wasn't found. Check input data.\n\n";
    else arr[id]->show();
}

void Shop::sort(bool(*cmp)(const Commodity*, const Commodity*)) const&
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
    cout << "\nAssortment sorted.\n\n";
}

void Shop::save()
{
    ofstream fw("Shop.txt");
    if (fw.is_open())
    {
        if (size == 0)
        {
            cout << "\nNo data for save.\n\n";
            fw.close();
        }
        else
        {
            int i = 0;
            while (i < size)
            {
                arr[i++]->save(fw);
            }
            fw.close();
            cout << "\nShop data successfully saved!\n\n";
        }
    }
    else
    {
        cout << "\nShop database saving error! Check files.\n\n";
    }
}

void Shop::load()
{
    ifstream fr("Shop.txt");
    Commodity* ptr = nullptr;

    if (fr.is_open())
    {
        string tmp;
        while (!fr.eof())
        {
            getline(fr, tmp);

            if (tmp == "Book")
            {
                ptr = new Book();
                ptr->load(fr);
                addCommodity(*ptr); // Потому, что там & в /h
            }
            else if (tmp == "Toy")
            {
                ptr = new Toy();
                ptr->load(fr);
                addCommodity(*ptr); // Потому, что там & в /h
            }
            else if (tmp == "Sport inventory")
            {
                ptr = new Sport_inventory();
                ptr->load(fr);
                addCommodity(*ptr); // Потому, что там & в /h
            }
        }
        fr.close();
        cout << "\nShop data successfully loaded!\n\n";
    }
    else
    {
        cout << "\nShop database loading error! Check files.\n\n";
        size = 0;
        arr = nullptr;
    }
}