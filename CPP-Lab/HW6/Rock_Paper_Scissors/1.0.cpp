#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int Rand(int min, int max) { return (rand() % (max - min)) + min; }

class Object
{
public:
	virtual string Get_loser_for_it() = 0;
	virtual string Get_winner_for_it() = 0;
	virtual string Get_name() = 0;
protected:
	string loser;
	string winner;
	string name;
};

class Rock : public Object
{
public:
	Rock() { name = "Rock"; loser = "Paper"; winner = "Scissors"; }
	string Get_loser_for_it() { return loser; }
	string Get_winner_for_it() { return winner; }
	string Get_name() { return name; }
};

class Paper : public Object
{
public:
	Paper() { name = "Paper"; loser = "Scissors"; winner = "Rock"; }
	string Get_loser_for_it() { return loser; }
	string Get_winner_for_it() { return winner; }
	string Get_name() { return name; }
};

class Scissors : public Object
{
public:
	Scissors() { name = "Scissors"; loser = "Rock"; winner = "Paper"; }
	string Get_loser_for_it() { return loser; }
	string Get_winner_for_it() { return winner; }
	string Get_name() { return name; }
};


class Rock_Paper_Scissors 
{
public:
	Rock_Paper_Scissors(int _max_scores) { max_scores = _max_scores; }
	void start()
	{
		string answer[] = { "Rock" , "Paper" , "Scissors" };
		int i, j , rand_num , comp_num , user_choice;
		while(true)
		{
			rand_num = Rand(0, 3);
			cout << "-------------------------------------------------------" << endl;
			Show_result();
			while (true)
			{
				cout << "Please enter your choice between 1-3 ( 1.Rock 2.Paper 3.Scissors ) : ";
				cin >> user_choice;
				if (user_choice > 0 && user_choice < 4)
					break;
				else cout << "Your entery is incorrect, please try again." << endl;
			}
			user_choice--;
			cout << "Computer choose " << answer[rand_num] << endl
				<< "You choose " << answer[user_choice] << endl;
			comp_num = Compare(answer[user_choice], answer[rand_num]);
			
			switch (comp_num)
			{
			case(0):
			{
				computer_score++;
				cout << "Computer win this secsion" << endl;
				break;
			}
			case(2):
			{
				user_score++;
				cout << "You win this secsion" << endl;
				break;
			}
			case(1):
				cout << "Draw" << endl;
			default:
				break;
			}
			if (computer_score == user_score && user_score == max_scores - 1)
				max_scores++;
			Show_result();
			system("pause");
			if (max_scores == user_score )
			{
				cout << "___________________________________________THE_END_________" << endl
					<< "You win the game, congragoation !" << endl;
				break;
			}
			else if (max_scores == computer_score)
			{
				cout << "___________________________________________THE_END_________" << endl
					<< "Unfortunity, the computer win the game." << endl;
				break;
			}
			cout << "Next seccion :" << endl;
		}
		

	}
	void Show_result()
	{
		cout << "Your score : " << user_score << "\t"
			<< "Computer score : " << computer_score << "\t"
			<< "Max score is : " << max_scores << endl;
	}
	int Compare(string a, string b)
	{
		if (a == b)
			return 1;
		for (int i = 0; i < 3; i++)
			if (a == choices[i]->Get_name())
			{
				if (b == choices[i]->Get_loser_for_it())
					return 0;
				else return 2;
			}
		return -1;
	}
private:
	int user_score = 0;
	int computer_score = 0;
	int max_scores;
	vector <Object*>choices{ new Rock , new Paper , new Scissors };
};


int main()
{
	int choice;
	srand(time(0));
	cout << "Please enter max of the game : ";
	cin >> choice;
	Rock_Paper_Scissors s(choice);
	s.start();


	return 0;
}