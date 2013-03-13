#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void dndroll(bool doBasic);
void multiroll(bool doBasic);
void coinflip(bool doBasic);
void ropasc(bool doBasic);
void avghp();
void kobroll(bool doBasic);
int random_roll(bool doBasic, int num);

int main()
{
	bool cont = true, doBasic = true;
	int choice = 0;
	srand(time(NULL));

	while(cont)
	{		
		system("cls");
		cout << "|}-----{ Dice Roller ver. 3.0  }-----{|" << endl;
		cout << "| 0: Quit                             |" << endl;
		cout << "| 1: Composite roll [Ex.: 1d20+5 = ??]|" << endl;
		cout << "| 2: Multi-dice roll [Ex.: 5d4 = ??]  |" << endl;
		cout << "| 3: Flip a coin                      |" << endl;
		cout << "| 4: Rock-Paper-Scissors              |" << endl;
		cout << "| 5: Avg HP [Ex.: 2d10+6 = ?? HP]     |" << endl;
		cout << "| 6: KoB Roll (0-25 result)           |" << endl;
		cout << "|}----------------{^}----------------{|" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		doBasic = rand()%2;

		switch (choice)
		{
			case 0:	cont = false;
				    break;

			case 1: dndroll(doBasic);
				    break;

			case 2: multiroll(doBasic);
				    break;

			case 3: coinflip(doBasic);
				    break;

			case 4: ropasc(doBasic);
					break;

			case 5: avghp();
					break;

			case 6: kobroll(doBasic);
				    break;
		}
		system ("Pause");
	}

	cout << "Ending program. ";
	system ("Pause");
	return 0;
}

void dndroll(bool doBasic)
{
	int numdice, numsides, addmod, tmp, sum;
	char chard, charsign;
	bool repeat = true;

	while(repeat)
	{
		cout << "Enter a roll command: ";
		cin >> numdice >> chard >> numsides >> charsign >> addmod;

		sum = addmod;

		if (charsign != '+' && charsign != '-')
		{
			cout << "Incorrect command" << endl;
			numdice = numsides = addmod = 0;
			chard = charsign = ' ';
			repeat = true;
		}

		else
		{
			cout << endl;
			if(charsign == '-')
				sum *= -1;
			
			for(int i = 0; i < numdice; i++)
			{
				tmp = random_roll(doBasic, numsides) +1;
				cout << "Roll " << i+1 << ": " << tmp << endl;
				sum += tmp;
			}			
			repeat = false;
		}	
	}
	cout << endl << numdice << "d" << numsides << charsign << addmod << " = " << sum << endl;
}


void multiroll(bool doBasic)
{
	int numdice, numsides, sum = 0, tmp;
	char chard;
	
	cout << "Enter a roll command: ";
	cin >> numdice >> chard >> numsides;
	cout << endl;

	for (int i = 0; i <numdice; i++)
	{
		tmp = random_roll(doBasic, numsides) +1;
		cout << "Roll " << i+1 << ": " << tmp << endl;
		sum += tmp;
	}

	cout << endl << numdice << "d" << numsides << " = " << sum << endl;
}



void coinflip(bool doBasic)
{
	int tmp = random_roll(doBasic, 2);
//	cout << tmp << endl;
	if(tmp)
		cout << "Tails!" << endl;
	else
	 cout << "Heads!" << endl;
}

void ropasc(bool doBasic)
{
	int tmp = random_roll(doBasic, 3);
//	cout << tmp << endl;
	if(tmp == 0)
		cout << "Rock!" << endl;

	else
		if (tmp == 1)
			cout << "Paper!" << endl;

	else
	 cout << "Scissors!" << endl;
}

void avghp()
{
	int numdice =1, numsides, conmod, sum;
	char chard;

	cout << "Enter the HD [Ex.: 5d6]: ";
	cin >> numdice >> chard >> numsides;

	cout << "Enter HP modifiers [Ex.: CON mod, Imp. Toughness]: ";
	cin >> conmod;
	
	sum = (numsides/2) +1;
	sum += conmod;
	sum *= numdice;

	cout << numdice << "d" << numsides;
	if(conmod >=0)
		cout << "+";
	cout << conmod * numdice <<" = " << sum << endl;
}

void kobroll(bool doBasic)
{
	int num = 0;

	for (int i = 0; i < 5; i++)
	{
		num += random_roll(doBasic, 6);
	}

	cout << "Your roll is " << num << "." << endl;
}

int random_roll(bool doBasic, int num = 0)
{
	double num1, num2;
	int result1, result2;
	
	for(int i = 0; i<RAND_MAX; i++)
	{
	num1 = rand();
	num2 = num1 / (RAND_MAX +1);
	
	result1 = static_cast<int>(num1) % num;
	result2 = static_cast<int>(num2 * num);
		
	if (doBasic)
	{
		doBasic = false;
		return result1;		
	}

	doBasic = true;
	return result2;	
	}
}

/*void random_type_two()
{
	double num1, num2, num3;
	int result1, result2, testnum, chk;
	
	cout << "Enter test number: ";
	cin >> testnum;
	for(int i = 0; i<RAND_MAX; i++)
	{
	num1 = rand();
	num2 = RAND_MAX +1;
	num3 = (num1/num2);

	result1 = static_cast<int>(num3 * testnum);
	result2 = static_cast<int>(num1) % testnum;
	
	result1++;
	result2++;

	chk = result1 - result2;
	
	cout << "Old Rand: " << result2 << ". New Rand: " << result1 << ". Chk: " << chk << endl;
	num1 = num2 = num3 = result1 = result2 = chk = 0;
	}
}*/




/*	int num = -1; 
	srand(time(NULL));

	do
	{
		cout << "Number of sides: ";
		cin >> num;

		if (num == 0)
			break;

		cout << "1d" << num << " = " << rand() %num +1 << endl;

	} while(true);


void dndroll()
{
	int numdice, numsides, addmod, tmp, sum;
	char chard, charsign;
	bool repeat = true;

	while(repeat)
	{
		cout << "Enter a roll command: ";
		cin >> numdice >> chard >> numsides >> charsign >> addmod;

		sum = addmod;

		if (charsign != '+' && charsign != '-')
		{
			cout << "Incorrect command" << endl;
			numdice = numsides = addmod = 0;
			chard = charsign = ' ';
			repeat = true;
		}

		else
		{
			cout << endl;
			if(charsign == '-')
				sum *= -1;
			
			for(int i = 0; i < numdice; i++)
			{
				tmp = rand() % numsides +1;
				cout << "Roll " << i+1 << ": " << tmp << endl;
				sum += tmp;
			}			
			repeat = false;
		}	
	}
	cout << endl << numdice << "d" << numsides << charsign << addmod << " = " << sum << endl;
}


void multiroll()
{
	int numdice, numsides, sum = 0, tmp;
	char chard;
	
	cout << "Enter a roll command: ";
	cin >> numdice >> chard >> numsides;
	cout << endl;

	for (int i = 0; i <numdice; i++)
	{
		tmp = rand() % numsides +1;
		cout << "Roll " << i+1 << ": " << tmp << endl;
		sum += tmp;
	}

	cout << endl << numdice << "d" << numsides << " = " << sum << endl;
}



void coinflip()
{
	int tmp = rand() % 2;
//	cout << tmp << endl;
	if(tmp)
		cout << "Tails!" << endl;
	else
	 cout << "Heads!" << endl;
}

void ropasc()
{
	int tmp = rand() % 3;
//	cout << tmp << endl;
	if(tmp == 0)
		cout << "Rock!" << endl;

	else
		if (tmp == 1)
			cout << "Paper!" << endl;

	else
	 cout << "Scissors!" << endl;
}

void avghp()
{
	int numdice =1, numsides, conmod, sum;
	char chard;

	cout << "Enter the HD [Ex.: 5d6]: ";
	cin >> numdice >> chard >> numsides;

	cout << "Enter HP modifiers [Ex.: CON mod, Imp. Toughness]: ";
	cin >> conmod;
	
	sum = (numsides/2) +1;
	sum += conmod;
	sum *= numdice;

	cout << numdice << "d" << numsides;
	if(conmod >=0)
		cout << "+";
	cout << conmod * numdice <<" = " << sum << endl;
	/*
	int numdice, numsides, addmod, multmod, tmp, sum;
	char chard, charsign, charx;
	bool repeat = true;

	while(repeat)
	{
		cout << "Enter the HP specs: ";
		cin >> numdice >> chard >> numsides >> charsign >> addmod;

		sum = addmod;

		if (charsign != '+' && charsign != '-')
		{
			cout << "Incorrect command" << endl;
			numdice = numsides = addmod = 0;
			chard = charsign = ' ';
			repeat = true;
		}

		else
		{
			cout << endl;
			if(charsign == '-')
				sum *= -1;

			sum *= multmod;

			tmp = multmod * ((numsides/2)+1); 
			cout << "Average HP: " << tmp << endl;

			for(int i = 0; i < numdice; i++)
			{
				tmp = rand() % numsides +1;
				cout << "Roll " << i+1 << ": " << tmp << endl;
				sum += tmp;
			}			
			repeat = false;
		}	
	}
	cout << endl << numdice << "d" << numsides << charsign << addmod << " = " << sum << endl;
}

void kobroll()
{
	int num = -4;

	for (int i = 0; i < 4; i++)
	{
		num += rand() % 6;
	}

	cout << "Your roll is " << num << "." << endl;
}*/