#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
using namespace std;
int maintain[3];
int total = 0;
struct inventory
{
	int code;
	string name;
	int stockavailable;
	double price;
};
struct supplier
{
	int codeofproduct;
	string nameofsupplier;
	int stockrecieved;
	string paymenttobedone;
};
struct sale
{
	string nameofproduct;
	double rate;
	double amount;
	int quantity;
	int code;
};
inventory add(inventory[], int);
inventory display(inventory[], int);
inventory displayprice(inventory[], int);
supplier supplierinfo(supplier[], inventory[], int);
inventory maintainstock(inventory[], int);
inventory alertofstock(inventory[], int);
inventory stockofitem(inventory[], int);
inventory sell(inventory[], sale[], int,int);
sale bill(sale[],int);
inventory returnitem(inventory[],int);

void writeInventoryToFile(inventory items[], int size) {
    ofstream fout("inventory_data.txt");

    for (int i = 0; i < size; i++) {
        fout << "Product " << i+1 << ":\n"
			 << "\t\tCode: " << items[i].code 
             << "\tName: " << items[i].name 
             << "\tStock: " << items[i].stockavailable
             << "\tPrice: " << items[i].price << "$\n";
    }

    fout.close();
}

void readInventoryFromFile(inventory items[], int size) {
    ifstream fin("inventory_data.txt");

    for (int i = 0; i < size; i++) {
        fin >> items[i].code
            >> items[i].name
            >> items[i].stockavailable
            >> items[i].price;
    }

    fin.close();
	}



int main()
{
	int choice, ans;
	const int size = 3;
	inventory a, b, c, e, f,g,h;
	inventory items[size];
	supplier info[size];
	sale products[size];
	supplier d;
	cout << " \t\t WELCOME TO INVENTORY CONTROL SYSTEM" << endl;
	cout << " Please enter products in the inventory to continue." << endl;
	a = add(items, size);
	cout << endl;
	cout << "The maintainance of the stock is automatic." << endl;
	maintainstock(items, size);




    readInventoryFromFile(items, size);
	do
	{
		cout << " What action you want to perform?" << endl << endl;
		cout << "  1. Display price of an item." << endl;
		cout << "  2. Display list of items in the inventory." << endl;
		cout << "  3. Sale an item." << endl;
		cout << "  4. Manage supplier." << endl;
		cout << "  5. See the stock available for a particular item." << endl;
		cout << "  6. Return an item." << endl;
		cout << "\n Choose an option:";
		cin >> choice;
		switch (choice)
		{
		case 1:a = displayprice(items, size);
		writeInventoryToFile(items, size);
			break;
		case 2: e = display(items, size);
		writeInventoryToFile(items, size);
			break;
		case 3: g = sell(items, products, size,total);
		writeInventoryToFile(items, size);
			break;
		case 4:d = supplierinfo(info, items, size);
		writeInventoryToFile(items, size);
			break;
		case 5:f = stockofitem(items, size);
		writeInventoryToFile(items, size);
			break;
		case 6:h = returnitem(items,size);
		writeInventoryToFile(items, size);
			break;
		}
		cout << "\n Do you want to perform any other action?Press 1 for yes and 0 for no.";
		cin >> ans;
	} while (ans == 1);

	return 0;
}


inventory add(inventory items[], int size)
{
	inventory t;
	for (int i = 0; i < size; i++)
	{
		cout << "\n Enter the code for the product : ";
		cin >> items[i].code;
		cout << "Enter the name of the product : ";
		cin >> items[i].name;
		cout << "Enter the amount of items in the inventory:";
		cin >> items[i].stockavailable;
		cout << "Enter the price of the product:$";
		cin >> items[i].price;
		cout << endl;

	}
	return t;
}
inventory display(inventory items[], int size)
{
	inventory k;
	cout << "code" << "\t\t product" << "\t amount " << "\t price" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << items[i].code << "\t\t" << items[i].name << "\t\t" << items[i].stockavailable << "\t\t" << items[i].price;
		cout << endl;
	}
	return k;
}
inventory displayprice(inventory items[], int size)
{
	inventory a;
	int code;
	cout << " enter the code of the product to know its price:";
	cin >> code;
	for (int i = 0; i < size; i++)
	{
		if (code == items[i].code)
		{
			cout << "The price of the item is: $" << items[i].price << endl;
		}
	}
	return a;
}
supplier supplierinfo(supplier info[], inventory items[], int size)
{
	supplier a;
	inventory z;
	cout << " Please enter the following data before continuing:" << endl;
	cout << "please enter the number of products been recieved:";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "\n Enter the code for the product : ";
		cin >> info[i].codeofproduct;
		cout << "Enter the name of the supplier : ";
		cin.ignore();
		getline(cin, info[i].nameofsupplier);
		cout << "Enter the amount of item recieved by supplier:";
		cin >> info[i].stockrecieved;
		if (items[i].code == info[i].codeofproduct)
		{
			items[i].stockavailable = items[i].stockavailable + info[i].stockrecieved;
		}
		cout << "Enter the payment to be done:$";
		cin >> info[i].paymenttobedone;
		cout << endl;
	}
	int ans;
	cout << "Do you want to view the updated amount of stock now?Press 1 for yes and 0 for no." << endl;
	cin >> ans;
	if (ans == 1)
	{
		const int size = 3;
		z = display(items, size);
	}

	return a;

}
inventory maintainstock(inventory items[], int size)
{


	inventory a;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the amount of stock you need to maintain for product " << items[i].code << " : ";
		cin >> maintain[i];
		if (items[i].stockavailable < maintain[i])
		{
			cout << " YOU ARE RUNNING OUT OF STOCK FOR THE PRODUCT OF CODE " << items[i].code << endl;
		}
		else
		{
			cout << "THE STOCK FOR PRODUCT " << items[i].code << " IS NOT YET ON THE BORDER LINE." << endl;
		}
	}
	return a;
}
inventory alertofstock(inventory items[], int size)
{
	inventory a;
	for (int i = 0; i < size; i++)
	{

		if (items[i].stockavailable < maintain[i])
		{
			cout << " YOU ARE RUNNING OUT OF STOCK FOR THE PRODUCT OF CODE " << items[i].code << endl;
		}
		else
		{
			cout << "THE STOCK FOR PRODUCT " << items[i].code << " IS NOT YET ON THE BORDER LINE." << endl;
		}
	}
	return a;
}
inventory stockofitem(inventory items[], int size)
{
	int code;
	inventory a;
	cout << "Enter the code of the product you want to view stock of:";
	cin >> code;
	for (int i = 0; i < size; i++)
	{

		if (code == items[i].code)
		{
			cout << "The stock available for the product " << items[i].code << " is " << items[i].stockavailable << endl;
		}
	}
	return a;
}
inventory sell(inventory items[], sale products[], int size,int total)
{
	inventory a, b;

	int count, ans;
	
	cout << "HOW MANY ITEMS TO SELL?";
	cin >> count;


	for (int i = 0; i < count; i++)
	{
		cout << "Enter the code of the product" << i+1 << ": ";
		cin >> products[i].code;
		cout << "Enter the quantity you want to buy:";
		cin >> products[i].quantity;
		for (int j = 0; j < count; j++)
			if (products[i].code == items[j].code)
			{
				products[i].nameofproduct = items[i].name;
				products[i].rate = items[i].price;
				items[i].stockavailable = items[i].stockavailable - products[i].quantity;
				products[i].amount = items[i].price * products[i].quantity;
				total = total + products[i].amount;
			}
	}
	cout << " Do you want to generate a bill? Enter 1 for yes and 0 for no." << endl;
	cin >> ans;
	sale m;
	if (ans == 1)
	{
		m=bill(products,total);
	}
	else
	{
		cout << " Products have been sold." << endl;
	}
	b=alertofstock(items, size);
	return a;
}
sale bill(sale products[],int total)
{
	int count;
	sale a;
	string name;
	double date, time;
	cout << "Enter total number of type of items?";
	cin >> count;
    cout << "Enter Cashier's name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter date and time:";
	cin >> date >> time;
	cout << "       ********SALE RECIEPT********" << endl;
	cout << "Cashier:" << name << endl;
	cout << "Date:" << date;
	cout << "\t\t Time:" << time << endl;
	cout << "PRODUCT NAME|   RATE|   QUANTITY|  AMOUNT "<<endl;
	for (int i = 0; i < count; i++)
	{
		cout << products[i].nameofproduct << "\t\t" << products[i].rate << "\t " << products[i].quantity << " \t\t" << products[i].amount << endl;
	}
	cout << "Total Bill:$ " << total << endl << endl;
	cout << "THANK YOU FOR SHOPPING WITH US.\n We have a 3-day return policy"<<endl<<endl;
	return a;
}
inventory returnitem(inventory items[],int size)
{
	inventory a;
	int code;
	cout << " ENTER CODE FOR THE PRODUCT TO BE RETURNED:"<<endl;
	cin >> code;
	for (int i = 0; i < size; i++)
	{
		if (code==items[i].code)
		{
			items[i].stockavailable = items[i].stockavailable + 1;
			cout << "Please return $" << items[i].price << " to the customer."<<endl;
			
		}
	}
	return a;
	
}

