﻿#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date;
class Product;
class Customer;
Date get_date();
string get_name();
int get_id();

class Date
{
public:
	Date(int _day,int _month , int _year) : day(_day) , month(_month) , year(_year) {}
	int Get_day() { return day; }
	int Get_month() { return month; }
	int Get_year() { return year; }
	void Show_date() { cout << year << " / " << month << " / " << day << endl; }
private:
	int day;
	int month;
	int year;
};

class Product
{
public:
	Product(int _id, string _name , Date _exp_date): id(_id) , name(_name) , exp_date(_exp_date){}
	void Set_name(string _name) { name = _name; }
	void Set_id(int _id) { id = _id; }
	void Set_price(int _price) { price = _price; }
	void Set_count(int _count) { count = _count; }
	void Set_off(float _off) { off = _off; }
	void Effect_off() { if (off > 0 && off < 1) price *= off; }
	int Get_id() { return id; }
	string Get_name() { return name; }
	float Get_price() { return price; }
	int Get_count() { return count; }
	float Get_off() { return off; }
	Date Get_expire_day() { return exp_date; }
	static void Add(vector <Product*> &products, int _id, string _name, Date _exp_date);
	static int Search_by_name(const vector <Product*> products, string _name);
	static int Search_by_id(const vector <Product*> products, int _id);
	static int Total_search(const vector <Product*> products);
	static void Edit(vector <Product*> &products);
	static void Delete(vector <Product*>& products);
	static void Show_list(const vector <Product*> products);
	static void Show_list_for_saling(const vector <Product*> products);
private:
	int id;
	string name;
	int count = 0;
	float price;
	Date exp_date;
	float off;
};


class Customer
{
public:
	Customer(int _id, string _name, Date _register_date) : id(_id), name(_name), register_date(_register_date) {}
	void Set_phone_num(string _phone_num) { phone_num = _phone_num; }
	void Add_money_to_wallet(float addition) { wallet += addition; }
	void Add_to_basket(Product* product , int _count);
	int Get_id() { return id; }
	string Get_name() { return name; }
	string Get_phone_num() { return phone_num; }
	float Get_wallet() { return wallet; }
	vector<Product*> Get_basket() { return basket; }
	Date Get_register_date() { return register_date; }
	float Get_sum_of_buying() { return sum_buying; }
	void Set_sum_of_buying(float _sum_buying) { sum_buying = _sum_buying; }
	static void Add(vector <Customer*> &customers, int _id, string _name, Date _register_date);
	static int Search_by_name(const vector <Customer*> customers, string _name);
	static int Search_by_id(const vector <Customer*> customers, int _id);
	static int Total_search(const vector <Customer*> customers);
	static void Edit(vector <Customer*> &customers);
	static void Delete(vector <Customer*> &customers);
	static void Show_list(const vector <Customer*> customers);
	static void Total_show_basket(const vector <Customer*> customers);
	void Show_basket();
private:
	int id;
	string name;
	Date register_date;
	string phone_num = "";
	float wallet = 0;
	vector<Product*> basket;
	vector<int> count_basket;
	float sum_buying = 0;
};


class Shop
{
public:
	int product_menu_of_shop();
	int customer_menu_of_shop();
	int total_menu_of_shop();
	void Add_product();
	void Add_customer();
	void Edit_product() { Product::Edit(products); }
	void Edit_costumer() { Customer::Edit(customers); }
	void Delete_product() { Product::Delete(products); }
	void Delete_customer() { Customer::Delete(customers); }
	void Show_products(){ Product::Show_list(products); }
	void Show_customers() { Customer::Show_list(customers); }
	void Buying_product();
	void Start_working();
private:
	vector<Product*> products;
	vector <Customer*> customers;
	//Customer* sundries;
};


int main()
{
	Shop Shahre_ma;
	Shahre_ma.Start_working();




	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Product::Add(vector <Product*> &products, int _id, string _name, Date _exp_date)
{
	char choice;
	float price, off;
	int index = products.size() - 1, count;
	//products.push_back(&Product(get_id(),get_name(),get_date()));
	cout << "Your product had registered but without any price, count and off." << endl
		<< "Do you want to enter price of product ?";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter price : ";
		cin >> price;
		products[index]->Set_price(price);
		cout << "Succesfuly registered. " << endl;
	}
	cout << "Do you want to enter count of product ? (yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter count : ";
		cin >> count;
		products[index]->Set_count(count);
		cout << "Succesfuly registered. " << endl;
	}
	cout << "Do you want to enter off of this product ? (yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter off (between 0 to 1 ) : ";
		cin >> off;
		products[index]->Set_off(off);
		cout << "Succesfuly registered. " << endl;
	}
}
int Product::Search_by_name(const vector <Product*> products, string _name)
{
	int result = -1;
	for (int i = 0; i < products.size(); i++)
		if (products[i]->name == _name)
		{
			result = i;
			break;
		}
	return result;
}
int Product::Search_by_id(const vector <Product*> products, int _id)
{
	int result = -1;
	for (int i = 0; i < products.size(); i++)
		if (products[i]->id == _id)
		{
			result = i;
			break;
		}
	return result;
}
int Product::Total_search(const vector <Product*> products)
{
	char choice;
	string _name;
	int index = -1, _id;
	cout << "You have two choices (search by ID or Name) " << endl
		<< "Do you want to search by ID or Name ?(ID = i , Name = n) ";
	cin >> choice;
	if (toupper(choice) == 'N')
	{
		cout << "Please enter name : ";
		cin >> _name;
		index = Search_by_name(products, _name);
	}
	else
	{
		cout << "Ok, you should search by ID " << endl
			<< "Please enter ID : ";
		cin >> _id;
		index = Search_by_id(products, _id);
	}
	return index;
}
void Product::Edit(vector <Product*>& products)
{
	int index;
	char choice;
	index = Total_search(products);
	if (index == -1)
	{
		cout << "The ID/Name isn\'t exist please try again later." << endl;
		return;
	}
	else
	{
		cout << "Do you want to edit name ?(yes = y , no = n) ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			cout << "Please enter new name :";
			cin >> products[index]->name;
		}
		cout << "Do you want to edit ID ?(yes = y , no = n) ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			cout << "Please enter new ID :";
			cin >> products[index]->id;
		}
	}
}
void Product::Delete(vector <Product*> &products)
{
	int index;
	char choice;
	index = Total_search(products);
	if (index == -1)
		cout << "The ID/Name isn\'t exist please try again later." << endl;
	else
	{
		cout << "Are you sure you want to delete this product ? (yes = y , no = n) ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			delete products[index];
			products.erase(products.begin() + index);
			cout << "Succesfuly deleted. " << endl;
		}
		if (toupper(choice) == 'N' || index == -1)
			cout << "We didn\'t delete any thing if you want please try again ! " << endl;
		return;
	}
}
void Product::Show_list(const vector <Product*> products)
{
	cout << "We have " << products.size() << " products : " << endl;
	for (int i = 0; i < products.size(); i++)
	{
		cout << products[i]->name << " the price with off is : " << products[i]->count << endl;
	}
}
void Product::Show_list_for_saling(const vector <Product*> products)
{
	int cnt = 1;
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i]->count > 0)
		{
			cout << cnt << ". " <<products[i]->name << " the price with off is : " << products[i]->price << " and we have " << products[i]->count << " of them." << endl;
			cnt++;
		}
	}
}
void Customer::Add_to_basket(Product* product , int _count)
{
	int i;
	bool found = false;
	for (i = 0; i < basket.size(); i++)
		if (basket[i] == product)
		{
			found = true;
			break;
		}
	if (found)
		count_basket[i] += _count;
	else
	{
		basket.push_back(product);
		count_basket.push_back(_count);
	}
}
void Customer::Add(vector <Customer*> &customers, int _id, string _name, Date _register_date)
{
	Customer* c = new Customer(_id, _name, _register_date);
	customers.push_back(c);
}
int Customer::Search_by_name(const vector <Customer*> customers, string _name)
{
	int result = -1;
	for (int i = 0; i < customers.size(); i++)
		if (customers[i]->name == _name)
		{
			result = i;
			break;
		}
	return result;
}
int Customer::Search_by_id(const vector <Customer*> customers, int _id)
{
	int result = -1;
	for (int i = 0; i < customers.size(); i++)
		if (customers[i]->id == _id)
		{
			result = i;
			break;
		}
	return result;
}
int Customer::Total_search(const vector <Customer*> customers)
{
	char choice;
	string _name;
	int index = -1, _id;
	cout << "You have two choices (search by ID or Name) " << endl
		<< "Do you want to search by ID or Name ?(Name = n , ID = i) ";
	cin >> choice;
	if (toupper(choice) == 'N')
	{
		cout << "Please enter name : ";
		cin >> _name;
		index = Search_by_name(customers, _name);
	}
	else
	{
		cout << "Ok, you should search by ID " << endl
			<< "Please enter ID : ";
		cin >> _id;
		index = Search_by_id(customers, _id);
	}
	return index;
}
void Customer::Edit(vector <Customer*>& customers)
{
	int index;
	char choice;
	index = Total_search(customers);
	if (index == -1)
	{
		cout << "The ID/Name isn\'t exist please try again later." << endl;
		return;
	}
	else
	{
		cout << "Do you want to edit name ?(yes = y , no = n) ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			cout << "Please enter new name :";
			cin >> customers[index]->name;
		}
		cout << "Do you want to edit ID ?(yes = y , no = n) ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			cout << "Please enter new ID :";
			cin >> customers[index]->id;
		}
	}
}
void Customer::Delete(vector <Customer*> &customers)
{
	int index;
	char choice;
	index = Total_search(customers);
	if (index == -1)
		cout << "The ID/Name isn\'t exist please try again later." << endl;
	else
	{
		cout << "Are you sure you want to delete this customer? (yes = y , no = n) ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			delete customers[index];
			customers.erase(customers.begin() + index);
			cout << "Succesfuly deleted. " << endl;
		}
		if (toupper(choice) == 'N' || index == -1)
			cout << "We didn\'t delete any thing if you want please try again ! " << endl;
		system("pause");
		return;
	}
}
void Customer::Show_list(const vector <Customer*> customers)
{
	cout << "We have " << customers.size() << " customers : " << endl;
	for (int i = 0; i < customers.size(); i++)
	{
		cout << customers[i]->name << " the wallet of sir is : " << customers[i]->wallet << '$' << endl;
	}
	system("pause");
}
void Customer::Total_show_basket(const vector <Customer*> customers)
{
	int index;
	char choice;
	index = Total_search(customers);
	if (index == -1)
		cout << "The ID/Name isn\'t exist please try again later." << endl;
	else
		for (int i = 0; i < customers[index]->basket.size(); i++)
			cout << "The name product is " << customers[index]->basket[i] << " and the sir want " << customers[index]->count_basket[i] << endl;
}

void Customer::Show_basket()
{
	int i;
	float sum , sum_products = 0;
	for (i = 0; i < basket.size(); i++)
	{
		sum = basket[i]->Get_price() * count_basket[i];
		cout << i << ". " << basket[i]->Get_name() << " : you want " << count_basket[i] << " so the price you shoud pay is : " << sum << " ." << endl;
		sum_products += sum;
	}
	cout << "The sum of all produucts that you want is : " << sum_products << endl;
	sum_buying = sum_products;
	system("pause");
}

int Shop::product_menu_of_shop()
{
	int choice;
	do
	{
		cout << "Please choose one of the choices :" << endl
			<< "1.Add product" << endl
			<< "2.Edit product" << endl
			<< "3.Delete product" << endl
			<< "4.Show list of products" << endl
			<< "5.Back" << endl;
		cin >> choice;
	} while (choice < 0 || choice > 6);
	if (choice == 5)
		return 0;
	else
	{
		choice += 4;
		return choice;
	}
}
int Shop::customer_menu_of_shop()
{
	int choice ;
	do
	{
		cout << "Please choose one of the choices :" << endl
			<< "1.Add customer" << endl
			<< "2.Edit a customer" << endl
			<< "3.Delete customer" << endl
			<< "4.Show list of customers" << endl
			<< "5.Back" << endl;
		cin >> choice;
	} while (choice < 0 || choice > 6);
	if (choice == 5)
		return 0;
	else return choice;
}
int Shop::total_menu_of_shop()
{
	int choice, finally_choice;
	while (true)
	{
		do
		{
			system("cls");
			cout << "Please choose one of the choices :" << endl
				<< "1.Products" << endl
				<< "2.Customers" << endl
				<< "3.Buying" << endl
				<< "4.Exit" << endl;
			cin >> choice;
		} while (choice < 0 || choice > 4);/////////////////////////////////////////////////////////
		system("pause");
		system("cls");
		switch (choice)
		{
		case(1):
		{
			finally_choice = product_menu_of_shop();
			break;
		}
		case(2):
		{
			finally_choice = customer_menu_of_shop();
			break;
		}
		case(3):
		{
			Buying_product();
			system("pause");
			finally_choice = 0;
			break;
		}
		case(4):
			return 0;
		default:
		{
			return -1;
		}
		}
		system("cls");
		switch (finally_choice)
		{
		case(0):
		{
			continue;
		}
		case(1):
		{
			//Customer::Add(customers,get_id(),get_name(),get_date());
			Add_customer();
			break;
		}
		case(2):
		{
			Customer::Edit(customers);
			system("pause");
			break;
		}
		case(3):
		{
			Customer::Delete(customers);
			system("pause");
			break;
		}
		case(4):
		{
			Customer::Show_list(customers);
			system("pause");
			break;
		}
		case(5):
		{
			//Product::Add(products, get_id(), get_name(), get_date());
			Add_product();
			break;
		}
		case(6):
		{
			Product::Edit(products);
			system("pause");
			break;
		}
		case(7):
		{
			Product::Delete(products);
			system("pause");
			break;
		}
		case(8):
		{
			Product::Show_list(products);
			system("pause");
			break;
		}
		default:
			return -1;
		}
	}
}
void Shop::Add_product()
{
	float price, off;
	char choice;
	Date expire = get_date();
	string name = get_name();
	int index = products.size(), id = get_id(), count;
	Product* p = new Product(id, name, expire);
	products.push_back(p);
	cout << "Your product had registered but without any price, count and off." << endl
		<< "Do you want to enter price of product ?";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter price : ";
		cin >> price;
		products[index]->Set_price(price);
		cout << "Succesfuly registered. " << endl;
	}
	cout << "Do you want to enter count of product ? (yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter count : ";
		cin >> count;
		products[index]->Set_count(count);
		cout << "Succesfuly registered. " << endl;
	}
	cout << "Do you want to enter off of this product ? (yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter off (between 0 to 1 ) : ";
		cin >> off;
		products[index]->Set_off(off);
		cout << "Succesfuly registered. " << endl;
	}
}
void Shop::Add_customer()
{
	char choice;
	Date _regsiter = get_date();
	string phone_number , _name = get_name();
	int _id = get_id() , index = customers.size();
	float money_wallet;
	Customer* c = new Customer(_id, _name, _regsiter);
	customers.push_back(c);
	cout << "The new customer had registered but without any phone number and wallet." << endl
		<< "Do you want to enter phone number of customer ? (yes = y , no = n)";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter phone number : ";
		cin >> phone_number;
		customers[index]->Set_phone_num(phone_number);
		cout << "Succesfuly registered. " << endl;
	}
	cout << "Do you want to add money to wallet of customer ? (yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter money of wallet : ";
		cin >> money_wallet;
		customers[index]->Add_money_to_wallet(money_wallet);
		cout << "Succesfuly registered. " << endl;
	}
}

void Shop::Buying_product()
{
	//sundries;
	char choice;
	bool continuing , registered = false;
	int index , index2 , counter , i;
	while (registered == false)
	{
		cout << "Do you join in the our customer club ? (yes = y , no = n) ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			index = Customer::Total_search(customers);
			if (index == -1)
				cout << "We didn\'t find you please try again or regiter." << endl;
			else
			{
				registered = true;
				cout << "Mr/Ms " << customers[index]->Get_name() << " you have " << customers[index]->Get_wallet() << " $ in your wallet." << endl;
				i = 0;
				while (true)
				{
					system("cls");
					Product::Show_list_for_saling(products);
					cout << "Now please enter name or ID of one of the products and then count that you want." << endl;
					index2 = Product::Total_search(products);
					if (index2 != -1)
					{
						cout << "You chose a " << products[index2]->Get_name() << ". So now please enter counter that you want (we have just "
							<< products[index2]->Get_count() << " of them.)" << endl;
						cin >> counter;
						if (counter <= products[index2]->Get_count())
						{
							products[index2]->Set_count(products[index2]->Get_count() - counter);
							customers[index]->Add_to_basket(products[index2], counter);
							cout << "It has add to your basket." << endl;
							i++;
						}
						else cout << "Sorry we don\'t have enough " << products[index2]->Get_name() << " ." << endl;
					}
					else
					{
						cout << "Sorry we didn't find this, please try again." << endl;
					}
					cout << "Do you want to continue buying ? (yes = 1 , no = 0)" << endl;
					cin >> continuing;
					if (continuing == 0)
						break;
				}
			}
		}
		else
		{
			cout << "For the first please registered and try it again." << endl;
			Add_customer();
		}
	}
	cout << "Do you want to print reciept ? (yes = y , no = n) " << endl;
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		customers[index]->Show_basket();
	}
	system("pause");
}

void Shop::Start_working()
{
	int performance;
	performance = total_menu_of_shop();
	system("cls");
	cout << "This program stop." << endl
		<< "Have good time ;D " << endl;
}



Date get_date()
{
	int day, month, year;
	cout << "Please enter day : ";
	cin >> day;
	cout << "Please enter month : ";
	cin >> month;
	cout << "Please enter year : ";
	cin >> year;
	return Date(day, month, year);
}

string get_name()
{
	string name;
	cout << "Please enter name : ";
	cin >> name;
	return name;
}

int get_id()
{
	int id;
	cout << "please enter ID : ";
	cin >> id;
	return id;
}