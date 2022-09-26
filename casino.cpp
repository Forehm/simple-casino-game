#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;







int balance = 100;
HANDLE hConsole;






void ShowMenu(int balance)
{
	system("cls");
	SetConsoleTextAttribute(hConsole, 8);
	cout << "Balance: ";
	SetConsoleTextAttribute(hConsole, 7);
	cout << balance;
	SetConsoleTextAttribute(hConsole, 10);
	cout << '$' << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Enter the bet count..." << endl;

}

int RandNumber()
{
	srand(time(NULL));
	int temp;
	temp = rand() % 3 + 1;
	return temp;
}

int SetBet()
{
	portal1:
	int bet;
	cin >> bet;
	if (bet > balance)
	{
		cout << "You cannnot bet this summ" << endl;
		goto portal1;
	}
	else
	{
		return bet;
	}
}







int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	

	portal:



	ShowMenu(balance);


	int bet = SetBet();
	balance -= bet;

	int number = RandNumber();
	SetConsoleTextAttribute(hConsole, 3);
	cout << "Enter your number from 1 to 4" << endl;
	int personNumber;
	cin >> personNumber;


	


	
	
		if (personNumber == number)
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << "You win!!!" << endl;
			bet *= 2;
			balance += bet;
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 13);
			cout << "You lose :(" << " The number was " << number << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
	


		if (balance == 0)
		{
			cout << "You don't have any money" << endl;
			return 0;
		}





	goto portal;




	
}
