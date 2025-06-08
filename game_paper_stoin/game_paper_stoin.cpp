#include<iostream>
#include<iomanip>
#include<string>
#include"my_labrary.h"

using namespace labrary;
using namespace std;
enum enstat { stone = 1, paper = 2, scicor = 3 };

enum enstatwan { Player1 = 1, computer = 2, no_winner = 3 };

struct info_finall
{

	int round_of_all = 0;
	short counter_chose_user = 0;
	short counter_chose_computer = 0;
	short conter_drow_time = 0;
	enstatwan won_fainally = computer;
};

struct info
{
	int round = 0;
	enstat chose_user = stone;
	enstat chose_computer = stone;
	enstatwan wan = computer;
	enstatwan won_fainally = computer;


};


enstatwan round_won(info s1)
{


	switch (s1.chose_user)
	{
	case  enstat::stone:
	{
		if (s1.chose_computer == enstat::paper)
			return enstatwan::computer;

		else if (s1.chose_computer == enstat::scicor)
			return enstatwan::Player1;
		else
			return enstatwan::no_winner;

	}break;


	case  enstat::paper:
	{

		if (s1.chose_computer == enstat::scicor)
			return enstatwan::computer;
		else if (s1.chose_computer == enstat::stone)
			return enstatwan::Player1;
		else
			return enstatwan::no_winner;



	}break;


	case enstat::scicor:
	{
		if (s1.chose_computer == enstat::stone)
			return enstatwan::computer;
		else if (s1.chose_computer == enstat::paper)
			return enstatwan::Player1;
		else
			return enstatwan::no_winner;

	}break;
	}
}

void color_Syst(enstatwan s1)
{
	if (s1 == enstatwan::Player1)
		color_green();
	else if (s1 == enstatwan::computer)
	{
		color_red();
		cout << '\a';
	}
	else
		color_yalue();
}
string store_stat_playre_and_computer_string_data(enstat s1)
{
	if (enstat::paper == s1)
		return"paper";
	else if (enstat::scicor == s1)
		return "scicor";
	else
		return "stone";

}

string print_own_string_data(enstatwan s1)
{
	if (s1 == enstatwan::computer)
		return"computer";
	else if (s1 == enstatwan::Player1)
		return "Player 1";
	else
		return"no_winner";
}

void print_round(info s1, int i)
{
	color_Syst(s1.wan);
	cout << "________________________________________________________"<<endl;
	cout << " Round |    Player 1  |    Computer   |  Round Winner  " << endl;
	cout << "--------------------------------------------------------"<<endl;
	cout << setw(2) <<"(" << setw(3) << i<< setw(2) << ")" << "|" << setw(14) << store_stat_playre_and_computer_string_data(s1.chose_user) << "|" << setw(14) << store_stat_playre_and_computer_string_data(s1.chose_computer) << "|" << setw(17) << print_own_string_data(s1.wan) << endl;
	cout << "--------------------------------------------------------" << endl;
}


enstatwan select_won_fanall(info_finall f1)
{
	if (f1.conter_drow_time == f1.counter_chose_computer && f1.conter_drow_time == f1.counter_chose_user)
		return  enstatwan::no_winner;
	else if (f1.counter_chose_user > f1.counter_chose_computer)
		return enstatwan::Player1;
	else if (f1.counter_chose_computer > f1.counter_chose_user)
		return enstatwan::computer;

	else
		return  enstatwan::no_winner;


}

string lapp(int number) {
	string word = "";
	for (int i = 1; i <= number; i++)
		word += '\t';
	return word;
}

void hedar_screen()
{
	cout << lapp(3)<<"_________________________________________________\n\n";
	cout << lapp (5)<< "+ + + GAME OVER + + +\n\n";
	cout <<lapp(3)<< "-------------------------------------------------\n\n";
}

void print_oll_finel(info_finall f1)
{
	hedar_screen();
	cout << lapp(3)<<"***************[GAMES RESULT]*******************\n";
	cout << lapp(3) << "|\n";
	cout << lapp(3) << "|GAME Rounds : ("<< f1.round_of_all << ")" <<endl;
	cout << lapp(3) << "|plyaer won tiems : ("<< f1.counter_chose_user << ")"<< endl;
	cout << lapp(3) << "|computer won tiems : ("<< f1.counter_chose_computer  <<")"<< endl;
	cout << lapp(3) << "|drow time : ("<< f1.conter_drow_time <<")" <<endl;
	color_Syst(f1.won_fainally);
	cout << lapp(3) << "|woner finally : ("<< print_own_string_data(f1.won_fainally)<<")" << endl;
	cout << lapp(3) << "**********************************************\n\n";

}

info_finall roundd(info s1)
{
	info_finall f1;
	short number1, number2;
	s1.round = read_number_from_into("HOW MANY RAOUND FROM 1 INTO 10 :", 1, 10);

	for (int i = 1; i <= s1.round; i++)
	{
		cout << "Round [" << i << "] Beging :\n\n";

		number1 = read_number_from_into("Your choose :\n[1]stone   [2]paper   [3]scicor :", 1, 3);
		number2 = RandomNumber(1, 3);

		s1.chose_user = (enstat)number1;
		s1.chose_computer = (enstat)number2;

		s1.wan = round_won(s1);



		if (s1.wan == enstatwan::computer)
			f1.counter_chose_computer++;
		else if (s1.wan == enstatwan::Player1)
			f1.counter_chose_user++;
		else
			f1.conter_drow_time++;


		print_round(s1, i);

	}
	f1.won_fainally = select_won_fanall(f1);
	f1.round_of_all = s1.round;
	return f1;

}

void mmain()
{
	char x = 'Y';
	info s1;
	do
	{
		new_scrren();
		print_oll_finel(roundd(s1));
		cout << "\n Do you want play agine ?(Y or N) ?\n ";
		cin >> x;
	} while (x == 'Y' || x == 'y');


}

int main()
{
	mmain();
}

