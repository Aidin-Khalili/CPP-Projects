#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<ctime>
#define Rate_of_ill 1.7 //It's the rate of illness to pass to person.
#define Max_day 10   //By deafult it's the max of days but we aske for use deafult or no.
#define Adress_Input "h:\\matrix.txt"
#define Adress_Output "h:\\Log.txt"
#define Range_of_rec -6,3    // This is the range of recovery that we choose for each petient.


using namespace std;

class society;
class Entey_Exception {};
class Read_File_Exception {};
class Write_File_Execption {};
class Console_In_Exeption {};

class file_entery //This class for file entery (getting proximity matrix).
{
public:
	file_entery() {}
	~file_entery() { M.clear(); }
	file_entery(const file_entery& a) : M(a.M) {}
	file_entery& operator=(const file_entery& f)
	{
		if (&f == this)
			return *this;
		M.clear();
		M = f.M;
		return *this;
	}
	void read_file()
	{
		int i, j;
		fstream In_file(Adress_Input, ios::in);
		string LINE;
		if (!In_file) //Coudn't read file entery.
			throw Read_File_Exception();
		getline(In_file, LINE);
		N = LINE.length();
		M.resize(N, vector<char>(N));
		for (i = 0; i < N; i++)
			M[0][i] = LINE[i];
		i = 1;
		while (i < N)
		{
			getline(In_file, LINE);
			for (j = 0; j < N; j++)
				M[i][j] = LINE[j];
			i++;
		}
		for (i = 0; i < N; i++) ///cheking invalid proximity matrix.
		{
			if (M[i][i] != '0')
				throw Entey_Exception();
			for (j = i + 1; j < N; j++)
				if (M[i][j] != M[j][i] || (M[i][j] != '1' && M[i][j] != '0'))
					throw Entey_Exception();
		}
	}

	vector<vector<char>> get_matrix() { return M; }
private:
	int N;
	vector<vector<char>> M;
};


class Person
{
public:
	Person(char _id) { id = _id; }
	~Person() { link.clear(); }
	Person(const Person& p) : id(p.id), patiener(p.patiener), link(p.link), polution_num(p.polution_num), dead(p.dead), patient(p.patient) {}
	Person& operator=(const Person& p)
	{
		if (&p == this)
			return *this;
		link.clear();
		link = p.link;
		id = p.id;
		patiener = p.patiener;
		polution_num = p.polution_num;
		dead = p.dead;
		patient = p.patient;
		return *this;
	}
	char get_id() { return id; }
	int get_pol_num() { return polution_num; }
	char get_patiner() { return patiener; }
	void be_patient() { patient = true; }
	void set_painter(char p) { patiener = p; }
	bool is_patient() { return patient; }
	void get_health() { patient = false; patiener = '0'; }
	void make_link(Person* a) { link.push_back(a); }
	void change_pol_num(int a) { polution_num = a; }
	void die() { dead = true; }
	bool is_die() { return dead; }
	void print_link_preson()
	{
		ofstream Out_file(Adress_Output, ios::app);
		cout << id << " is near by : ";
		Out_file << id << " is near by : ";
		for (int i = 0; i < link.size(); i++)
		{
			Out_file << link[i]->id << ' ';
			cout << link[i]->id << ' ';
		}
		cout << endl;
		Out_file << endl;
		Out_file.close();
	}
private:
	char id;
	char patiener = '0';
	vector<Person*> link;
	int polution_num = 0;
	bool dead = false;
	bool patient = false;
};

class Society
{
public:
	Society(vector<vector<char>> M)
	{
		Set_guys(M);
		Make_link();
		int i, j;
		ofstream Out_file(Adress_Output, ios::out);
		if (!Out_file.is_open())
			throw Write_File_Execption();
		else {
			Out_file << "     ";
			for (i = 0; i < N; i++) {
				Out_file << ' ' << (char)('A' + i) << ' ';
			}
			Out_file << endl;
			for (i = 0; i < N; i++)
			{
				Out_file << ' ' << (char)('A' + i) << " |";
				for (j = 0; j < N; j++)
					Out_file << ' ' << matrix[i][j] << ' ';
				Out_file << '|' << endl;
			}
			Out_file.close();
		}
		for (i = 0; i < N; i++)
			guys[i]->print_link_preson();
	}
	~Society()
	{
		for (int i = 0; i < guys.size(); i++)
			delete guys[i];
		matrix.clear();
		paitiens.clear();
	}
	Society(const Society& s)
	{
		int i;
		N = s.N;
		matrix = s.matrix;
		guys.clear();
		for (i = 0; i < N; i++)
			guys[i] = new Person('A' + i);
		this->Make_link();
		paitiens.clear();
		for (i = 0; i < N; i++)
			if (s.guys[i]->is_patient())
			{
				guys[i]->be_patient();
				guys[i]->change_pol_num(s.guys[i]->get_pol_num());
				guys[i]->set_painter(s.guys[i]->get_patiner());
				paitiens.push_back(guys[i]);
			}
	}
	Society& operator=(const Society& s)
	{
		if (&s == this)
			return *this;
		int i;
		N = s.N;
		matrix = s.matrix;
		guys.clear();
		for (i = 0; i < N; i++)
			guys[i] = new Person('A' + i);
		this->Make_link();
		paitiens.clear();
		for (i = 0; i < N; i++)
			if (s.guys[i]->is_patient())
			{
				guys[i]->be_patient();
				guys[i]->change_pol_num(s.guys[i]->get_pol_num());
				guys[i]->set_painter(s.guys[i]->get_patiner());
				paitiens.push_back(guys[i]);
			}
		return *this;
	}
	void Set_guys(vector<vector<char>> M)
	{
		matrix = M;
		N = M.size();
		int i;
		guys.resize(N);
		for (i = 0; i < N; i++)
			guys[i] = new Person('A' + i);

	}
	void Make_link()
	{
		int i, j;
		for (i = 0; i < N; i++)
			for (j = i + 1; j < N; j++)
				if (matrix[i][j] == '1')
				{
					guys[i]->make_link(guys[j]);
					guys[j]->make_link(guys[i]);
				}
	}
	void start(int first_pul, int Max_Day)
	{
		if ((N <= first_pul) || (-1 >= first_pul))
			throw Console_In_Exeption();
		guys[first_pul]->be_patient();
		guys[first_pul]->set_painter('u');
		guys[first_pul]->change_pol_num(10);
		paitiens.push_back(guys[first_pul]);
		wend_days(Max_Day);
	}
	void remove_paitent(int i)
	{
		for (int j = 0; j < paitiens.size(); j++)
			if (guys[i] == paitiens[j])
				paitiens.erase(paitiens.begin() + j);
	}

	void print_condition()
	{
		for (int i = 0; i < paitiens.size(); i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Yellow);
			cout << "The person " << paitiens[i]->get_id() << " is paitent by " << paitiens[i]->get_patiner() << " (" << paitiens[i]->get_pol_num() << ")" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
		}
	}

	static int Rand(int min, int max) { return (rand() % (max - min)) + min; }

	void wend_days(int max_days)
	{
		int day = 0, i, j, rand_num, chance_pol, pol_num, background, foreground;
		char pol_id;
		ofstream Out_file;
		Out_file.open(Adress_Output, ios::app);
		Out_file << "\nIn Day " << day << " :" << endl;
		cout << endl << "\nIn Day " << day << " :" << endl << endl;
		for (i = 0; i < 12; i++)
		{
			foreground = COLOR[i][0];
			background = COLOR[i][1];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background << 4 | foreground);
			cout << "[" << i << "]";
		}
		cout << endl << endl;
		for (i = 0; i < N; i++)
		{
			pol_num = guys[i]->get_pol_num();
			pol_id = guys[i]->get_id();
			foreground = COLOR[pol_num][0];
			background = COLOR[pol_num][1];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background << 4 | foreground);
			Out_file << "[ " << pol_id << " ] ";
			cout << "[ " << pol_id << " ]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
			cout << ' ';
		}
		Out_file << endl;
		cout << endl;
		for (i = 0; i < N; i++)
		{
			pol_num = guys[i]->get_pol_num();
			foreground = COLOR[guys[i]->get_pol_num()][0];
			background = COLOR[guys[i]->get_pol_num()][1];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background << 4 | foreground);
			Out_file << "  " << pol_num << "  ";
			if (pol_num < 10)
				printf("| %.1d |", pol_num);
			else
				printf("|%.2d |", pol_num);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
			cout << ' ';
		}
		Out_file << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
		cout << endl;
		for (int j = 0; j < paitiens.size(); j++)
			Out_file << "The person " << paitiens[j]->get_id() << " is paitent by " << paitiens[j]->get_patiner() << " (" << paitiens[j]->get_pol_num() << ")" << endl;
		print_condition();
		for (i = 0; i < N; i++)
			Out_file << '[' << guys[i]->get_id() << "] ";
		Out_file << endl;
		for (i = 0; i < N; i++)
			Out_file << "  " << guys[i]->get_pol_num() << "  ";
		Out_file << endl;
		for (day = 1; day <= max_days; day++)
		{
			Out_file << "-----------------------------------------------------------------------------------------" << endl;
			Out_file << "\nIn Day " << day << " :" << endl;
			cout << "-----------------------------------------------------------------------------------------" << endl;
			cout << "\nIn Day " << day << " :" << endl << endl;
			for (i = 0; i < N; i++)
			{
				if (guys[i]->is_patient() && !guys[i]->is_die())
				{
					for (j = 0; j < N; j++)
					{
						if ((matrix[i][j] == '1') && !guys[j]->is_patient() && !guys[i]->is_die())
						{
							chance_pol = (Rate_of_ill - 1) * 10 * guys[i]->get_pol_num();
							rand_num = Rand(0, 100);
							Out_file << "(For " << guys[j]->get_id() << " : rand number is " << rand_num << " (between 0-100) and paitener pul num is " << guys[i]->get_pol_num()
								<< " and rate of ill infection is " << Rate_of_ill << " so his chance of pullotion is : " << chance_pol << " )" << endl;
							if ((rand_num <= chance_pol))
							{
								pol_id = (guys[i]->get_id());
								guys[j]->set_painter(pol_id);
								rand_num = Rand(0, 4);
								if (guys[i]->get_pol_num() <= rand_num)
									rand_num = 0;
								guys[j]->change_pol_num(guys[i]->get_pol_num() - rand_num);

								Out_file << "<< " << guys[j]->get_id() << " : " << guys[i]->get_pol_num()
									<< " - " << rand_num << " = " << guys[j]->get_pol_num() << " >>" << endl;
							}
						}
					}
					rand_num = Rand(Range_of_rec);
					Out_file << "{ " << guys[i]->get_id() << " : " << guys[i]->get_pol_num() << " + ( " << rand_num << " ) = ";
					guys[i]->change_pol_num(rand_num + guys[i]->get_pol_num());
					if (guys[i]->get_pol_num() > 10)
					{
						guys[i]->die();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Bright_Red);
						cout << "Unfortiunity we undrestand " << guys[i]->get_id() << " was die!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
						guys[i]->change_pol_num(11);
						remove_paitent(i);
					}
					if (guys[i]->get_pol_num() <= 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Green);
						cout << "Hopefully we heared that " << guys[i]->get_id() << " get better and now he goes home ." << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
						guys[i]->change_pol_num(0);
						remove_paitent(i);
					}
					Out_file << guys[i]->get_pol_num() << " }" << endl;
				}

			}
			cout << endl;
			for (i = 0; i < N; i++)
				if (guys[i]->get_pol_num() == 0)
					guys[i]->get_health();
			for (i = 0; i < N; i++)
				if (guys[i]->get_patiner() != '0' && guys[i]->get_patiner() != 'u')
				{
					for (j = 0; j < paitiens.size(); j++)
						if (guys[i] == paitiens[j])
							break;
					if (j == paitiens.size())
					{
						paitiens.push_back(guys[i]);
						guys[i]->be_patient();
					}

				}
			for (i = 0; i < 12; i++)
			{
				foreground = COLOR[i][0];
				background = COLOR[i][1];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background << 4 | foreground);
				cout << "[" << i << "]";
			}
			cout << endl << endl;
			for (i = 0; i < N; i++)
			{
				pol_num = guys[i]->get_pol_num();
				pol_id = guys[i]->get_id();
				foreground = COLOR[pol_num][0];
				background = COLOR[pol_num][1];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background << 4 | foreground);
				Out_file << "[ " << pol_id << " ] ";
				cout << "[ " << pol_id << " ]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
				cout << ' ';
			}
			Out_file << endl;
			cout << endl;
			for (i = 0; i < N; i++)
			{
				pol_num = guys[i]->get_pol_num();
				foreground = COLOR[guys[i]->get_pol_num()][0];
				background = COLOR[guys[i]->get_pol_num()][1];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background << 4 | foreground);
				Out_file << "  " << pol_num << "  ";
				if (pol_num < 10)
					printf("| %.1d |", pol_num);
				else
					printf("|%.2d |", pol_num);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
				cout << ' ';
			}
			Out_file << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
			cout << endl;
			print_condition();
			for (int j = 0; j < paitiens.size(); j++)
				Out_file << "The person " << paitiens[j]->get_id() << " is paitent by " << paitiens[j]->get_patiner() << " (" << paitiens[j]->get_pol_num() << ")" << endl;
		}
		Out_file.close();
	}

private:
	int N;
	vector <Person*> guys;
	vector<vector<char>> matrix;
	vector <Person*> paitiens;
	enum COLORS { Black, Blue, Green, Cyan, Red, Magenta, Brown, White, Gray, Bright_Blue, Bright_Green, Bright_Cyan, Bright_Red, Bright_Magenta, Yellow, Bright_White };
	int COLOR[12][2] = { Bright_White,Green, Black,Bright_White, Black,White, Blue,Brown, Black,Yellow, Yellow,Bright_Red, Black,Bright_Magenta, Yellow,Magenta, Black,Red, Yellow,Gray, Bright_Red,Blue, Gray,Black };
	//This is each two binary numbers for 'foregraund' and 'backgraumd'
};

int main()
{
	file_entery f;
	char choice = ' ';
	int max_days = 1, first_paitent = -1 , count;
	srand(time(0));
	while ((toupper(choice) != 'Y' && toupper(choice) != 'N') || max_days <= 0)
	{
		system("cls");
		cout << "Do you want to enter number of days( Y = Yes and N = No )? ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			cout << "Please enter max of days: ";
			cin >> max_days;
		}
		else
		{
			cout << "By deafult we consider the number of day is: " << Max_day << endl;
			max_days = Max_day;
		}
	}
	while (first_paitent < 0)
	{
		cout << "Do you want to enter number of first paitent( Y = Yes and N = No)? ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			cout << "Please enter index of first paitent : ";
			cin >> first_paitent;
		}
		else {
			first_paitent = 0;
			cout << "As a deafult we choose " << first_paitent + 1 << " for the first paitent." << endl;
		}
	}
	cout << endl;
	count = 3;
	while (count >= 0)
	{
		try {
			f.read_file();
			break;
		}
		catch (Entey_Exception x)
		{
			
			cerr << "Your file entery is invalid please try again." << endl
				<< "(if you solve problem please enter any key) you have just " << count << " chances" <<endl;
			count--;
			system("pause");
		}
		catch (Read_File_Exception y)
		{
			cerr << "File can not open ! \n please try again." << endl
				<< "(if you solve problem please enter any key) you have just " << count << " chances" << endl;
			count--;
			system("pause");
		}
	}
	if (count == -1)
	{
		cout << "We can not open please try again later." << endl;
		return 1;
	}
	count = 3;
	while (count >= 0)
	{
		try
		{
			Society Iran(f.get_matrix());
			Iran.start(first_paitent, max_days);
			break;
		}
		catch (Write_File_Execption z)
		{
			cerr << "We can not write any log on file " << endl
				<< "(if you solve problem please enter any key) you have just " << count << " chances" << endl;
			count--;
			system("pause");
		}
		catch (Console_In_Exeption c)
		{
		
			cerr << "Your number for first paitent is invalid " << endl
				<< "(Please enter first paitent again) you have just " << count << " chances" << endl;
			count--;
			cout << "Please enter index of first paitent : ";
			cin >> first_paitent;

		}
	}
	if (count == -1)
	{
		cout << "We can not do proccess please try again later." << endl;
		return 1;
	}
	return 0;
}