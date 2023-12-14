#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
	Student(string _name , string _family , int _id) : name (_name) , family(_family) , id(_id) {}
	void set_score()
	{
		float  sum = 0;
		int n;
		cout << "Please enter the number of the students score : ";
		cin >> n;
		scores.resize(n);
		for (int i = 0; i < n; i++)
		{
			cout << "Please enter number " << i + 1 << " th of student : ";
			cin >> scores[i];
			sum += scores[i];
		}
		avg = (float)sum / n;
	}
	string Get_name() { return name; }
	string Get_family() { return family; }
	int Get_id() { return id; }
	vector<float> Get_score() { return scores; }
	float Get_average() { return avg; }
	static void Add_std();
	static void Show_list();
	static void Edit_std(int);
	static int Search_id();
	static int Search_name();
	static int Search_family();
	static void Delete_std(int);
private:
	string name;
	string family;
	int id;
	vector <float> scores;
	float avg;
};

vector <Student> students;

void Student :: Add_std()
{
	string name;
	string family;
	int id;
	cout << "For add new student we need to get some information of him/her. " << endl;
	cout << "Please enter the name of his/her : ";
	cin >> name;
	cout << "Please enter his/her family name : ";
	cin >> family;
	cout << "Please enter his/her ID : ";
	cin >> id;
	students.push_back(Student(name, family, id));
}

void Student :: Show_list() 
{
	cout << "You had entered " << students.size() << " student information : " << endl;
	for (int i=0; i < students.size();i++)
	{
		cout << "Mr/Mss " << students[i].name << " " << students[i].family << " with ID : " << students[i].id <<endl;
	}
}

int Student::Search_name()
{
	int result = -1;
	string _name;
	cout << "Please enter the name of your student : ";
	cin >> _name;
	for (int i = 0; i < students.size(); i++)
		if (students[i].name == _name)
		{
			result = i;
			break;
		}
	return result;
}

int Student::Search_family()
{
	int result = -1;
	string _family;
	cout << "Please enter the family of your student : ";
	cin >> _family;
	for (int i = 0; i < students.size(); i++)
		if (students[i].family == _family)
		{
			result = i;
			break;
		}
	return result;
}

int Student :: Search_id()
{
	int result = -1 , _id;
	cout << "Please enter the ID of your student : ";
	cin >> _id;
	for (int i = 0; i < students.size(); i++)
		if (students[i].id == _id)
		{
			result = i;
			break;
		}
	return result;
}

void Student :: Delete_std(int index) { students.erase(students.begin() + index); }

void Student :: Edit_std(int index) 
{
	char choice;
	cout << "Do you want to edit name ?(yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter new name :";
		cin >> students[index].name;
	}
	cout << "Do you want to edit family ?(yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter new family :";
		cin >> students[index].family;
	}
	cout << "Do you want to edit ID ?(yes = y , no = n) ";
	cin >> choice;
	if (toupper(choice) == 'Y')
	{
		cout << "Please enter new ID :";
		cin >> students[index].id;
	}
}

int Search_determine()
{
	int ch , index ;
	cout << "Do you want to enter : 1.ID num  2.Name  3.Family  for editing ? ";
	cin >> ch;
	switch (ch)
	{
	case(1):
	{
		index = Student::Search_id();
		break;
	}
	case(2):
	{
		index = Student::Search_name();
		break;
	}
	case(3):
	{
		index = Student::Search_family();
		break;
	}
	default:
		index = -1;
	}
	return index;
}

void Show_menu()
{
	cout << "Please choose one of the choices : " << endl
		<< "1.Add new student " << endl
		<< "2.Show list of student " << endl
		<< "3.Edit student information " << endl
		<< "4.Delete student information " << endl
		<< "5.Serach student by information " << endl
		<< "6.Add scores to student " << endl
		<< "7.Exit " << endl;
}



int main()
{
	int choice = 0 , index;
	Show_menu();
	cin >> choice;
	while (choice < 7 && choice >=0)
	{
		switch (choice)
		{
		case(1): 
		{
			Student::Add_std();
			system("pause");
			break;
		}
		case(2):
		{
			Student::Show_list();
			system("pause");
			break;
		}
		case(3):
		{
			index = Search_determine();
				if (index != -1)
				Student::Edit_std(index);
			else
				cout << "Sorry we can\'t find that, please try again later." << endl;
				system("pause");
			break;
		}
		case(4):
		{
			index = Search_determine();
			if (index != -1) 
			{
				Student::Delete_std(index);
				cout << "Succefuly the student deleted" << endl;
			}
			else
				cout << "Sorry we can\'t find that, please try again later." << endl;
			system("pause");
			break;
		}
		case(5):
		{
			index = Search_determine();
			cout << "The student name is : " << students[index].Get_name() << endl
				<< "The student family is : " << students[index].Get_family() << endl
				<< "The student ID is : " << students[index].Get_id() << endl;
			if ((students[index].Get_score()).size() != 0)
			{
				cout << "And his/her scores are : ";
				for (int i = 0; i < (students[index].Get_score()).size(); i++)
				{
					cout << (students[index].Get_score())[i] << "  ";
				}
				cout << endl << "And the average of his/her numbers is : " << students[index].Get_average() << endl;
			}
			else cout << "The scores of this student didn\'t registered." << endl;
			system("pause");
			break;
		}
		case(6):
		{
			index = Search_determine();
			if (index != -1)
				students[index].set_score();
			else
				cout << "Sorry we can\'t find that, please try again later." << endl;
			system("pause");
			break;
		}
		case(7):
		{
			break;
		}
		}
		system("cls");
		Show_menu();
		cin >> choice;
	}
	
	return 0;
}
