#pragma once

#include<iostream>
#include<string>
using namespace std;
namespace labrary
{
	int  read_number_from_into(string info, int from, int into)
	{
		int number;
		do {
			cout << info;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << info;
				cin >> number;

			}


		} while (number<from || number >into);
		cout << endl;
		return number;
	}

	int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	void color_red()
	{
		system("color 4F");
	}

	void color_green()
	{
		system("color 2F");
	}

	void color_yalue()
	{
		system("color 6F");
	}

	void color_plack()
	{
		system("color 0F");
	}

	void new_scrren()
	{
		system("CLS");
		system("color 0F");
	}


	void Multiplication_table_from_to_into(int from, int into)
	{

		for (int i = from; i <= into; i++)
		{
			cout << "*************************\n";
			cout << "      " << i << ":       \n";
			cout << "*************************\n";
			for (int x = 1; x <= 10; x++)
			{
				cout << i << "*" << x << "=" << i * x << endl;
			}
		}
	}


	bool odd_number(int number)
	{
		return(number % 2 == 0);
	}
	bool even_number(int number)
	{
		return(number % 2 == 0);
	}

	int  Check_the_largest_number_among_three_numbers(int number1, int number2, int number3)
	{

		if (number1 > number2)
			if (number1 > number3)
				return number1;
			else
				return number3;
		else
			if (number2 > number3)
				return number2;
			else
				return number3;



	}

	void temp(int& number1, int& number2)
	{
		int temp = number1;
		number1 = number2;
		number2 = temp;


	}
	



}