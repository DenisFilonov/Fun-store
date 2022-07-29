#include"Book.h"
#include"Toy.h"
#include"Sport_inventory.h"
#include"Shop.h"

void main()
{
	setlocale(NULL, "");

	/*
	Shop sh;
	Book b("Чёрный день", 2500, 18, "Алексей Доронин", "Золотое");
	Toy t("Плюшевый мишка", 1500, 6, "Укр.Игрушки", "Пух");
	Sport_inventory si("Ролики", 5500, 12, "Укр.Спорт.Товары");

	Book b1;
	Toy t1;
	Sport_inventory si1;
	*/

	/*
	b.show();
	cout << "\n==============================================\n";
	t.show();
	cout << "\n==============================================\n";
	si.show();
	cout << "\n==============================================\n";
	*/

	/*
	sh.addCommodity(t);
	id = sh.getSize() - 1;
	sh.editCommodityByID(id);
	*/

	int menu = 0, menu1 = 0;
	int id = 0, value = 0;
	string str;

	Book b;
	Toy t;
	Sport_inventory sp;

	Shop sh;
	
	cout << "\n\t=== Starting and loading the application ===\n";
	sh.load();
	
	do
	{
		cout << "\n\tSHOP MENU:";
		cout << "\n1. Show store content.";
		cout << "\n2. Sort store content.";
		cout << "\n3. Add commodity to store.";
		cout << "\n4. Delete commodity from store.";
		cout << "\n5. Show current type of commodity.";
		cout << "\n6. Find commodity by name.";
		cout << "\n0. Exit the application and save.\nChoice: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			sh.showShop();
			break;

		case 2:
			//=================================================================================================================
			do
			{
				cout << "\n\tHow to sort?";
				cout << "\n1) By price up.";
				cout << "\n2) By price down.";
				cout << "\n3) By age up.";
				cout << "\n4) By age down.";
				cout << "\n5) By type up.";
				cout << "\n6) By type down.";
				cout << "\n0) Turn back to main menu.\nChoice: ";
				cin >> menu1;
				switch (menu1)
				{
				case 1:
					sh.sort(upPrice);
					break;

				case 2:
					sh.sort(dwPrice);
					break;

				case 3:
					sh.sort(upAge);
					break;

				case 4:
					sh.sort(dwAge);
					break;

				case 5:
					sh.sort(upType);
					break;

				case 6:
					sh.sort(dwType);
					break;

				default: if (menu1 > 6 && menu1 != 0 || menu1 < 0) cout << "\nWrong menu item selected.\n\n"; break;
				}
			} while (menu1 != 0);
			//=================================================================================================================
			break;

		case 3:
			//=================================================================================================================
			do
			{
				cout << "\n\tCOMMODITY ADD MENU:";
				cout << "\n1) Book.";
				cout << "\n2) Toy.";
				cout << "\n3) Sport inventory.";
				cout << "\n0) Turn back to main menu.\nChoice: ";
				cin >> menu1;

				switch (menu1)
				{
				case 1:
					sh.addCommodity(b);
					cout << "\nThe book has been added. Would you like to change information right now?\n1) Yes\n2) No\nChoice: ";
					cin >> value;

					if (value == 1)
					{
						id = sh.getSize() - 1;
						sh.editCommodityByID(id);
					}
					else
					{
						break;
					}
					break;

				case 2:
					sh.addCommodity(t);
					cout << "\nThe toy has been added. Would you like to change information right now?\n1) Yes\n2) No\nChoice: ";
					cin >> value;

					if (value == 1)
					{
						id = sh.getSize() - 1;
						sh.editCommodityByID(id);
					}
					else
					{
						break;
					}
					break;

				case 3:
					sh.addCommodity(sp);
					cout << "\nThe toy has been added. Would you like to change information right now?\n1) Yes\n2) No\nChoice: ";
					cin >> value;

					if (value == 1)
					{
						id = sh.getSize() - 1;
						sh.editCommodityByID(id);
					}
					else
					{
						break;
					}
					break;

				default: if (menu1 > 3 && menu1 != 0 || menu1 < 0) cout << "\nWrong menu item selected.\n\n"; break;
				}
			} while (menu1 != 0);
			//=================================================================================================================
			break;

		case 4:
			cout << "\nInput name of commodity: ";
			cin.ignore();
			getline(cin, str);
			sh.deleteCommodity(str);
			break;

		case 5:
			cout << "\nInput type of commodity: ";
			cin.ignore();
			getline(cin, str);
			sh.showCurrentType(str);
			break;

		case 6:
			cout << "\nInput name of commodity: ";
			cin.ignore();
			getline(cin, str);
			sh.findCommodityByName(str);
			break;

		default: if (menu > 6 && menu != 0 || menu < 0) cout << "\nWrong menu item selected.\n\n"; break;
		}
	} while (menu != 0);

	sh.save();
	cout << "\n\t=== Saving and closing the application ===\n\n";
}