#include <iostream>
using namespace std;

int main()
{
	cout << "\033[35;106m Bulls and Cows \033[m \n";

	srand(time(0));
	int number, t, s, d, e, number1, t1, s1, d1, e1, bulls, cows;

	do {
		number1 = 1000 + rand() % 9000;
		t1 = number1 / 1000;
		s1 = number1 / 100 % 10;
		d1 = number1 / 10 % 10;
		e1 = number1 % 10;
	} while (t1 == s1 || t1 == d1 || t1 == e1 || s1 == d1 || s1 == e1 || d1 == e1);

	do {
		bulls = cows = 0;
		do {
			cout << "\n\nInput 4-digit number with different digits: ";
			cin >> number;
			t = number / 1000;
			s = number / 100 % 10;
			d = number / 10 % 10;
			e = number % 10;
		} while (number < 1023 || number > 9876 || t == s || t == d || t == e || s == d || s == e || d == e);
		cout << "\t\t\t";

		// thousands check
		if (t == t1)
		{
			bulls++;
			cout << "\033[92;99m" << t << "\033[m";
		}
		else
		{
			if (t == s1 || t == d1 || t == e1)
			{
				cows++;
				cout << "\033[33;99m" << t << "\033[m";
			}
			else
			{
				cout << "\033[0;99m" << t << "\033[m";
			}
		}

		// hundreds check
		if (s == s1) {
			bulls++;
			cout << "\033[92;99m" << s << "\033[m";
		}
		else
		{
			if (s == t1 || s == d1 || s == e1)
			{
				cows++;
				cout << "\033[33;99m" << s << "\033[m";
			}
			else {
				cout << "\033[0;99m" << s << "\033[m";
			}
		}

		// tens check
		if (d == d1) {
			bulls++;
			cout << "\033[92;99m" << d << "\033[m";
		}
		else
		{
			if (d == t1 || d == s1 || d == e1) {
				cows++;
				cout << "\033[33;99m" << d << "\033[m";
			}
			else
			{
				cout << "\033[0;99m" << d << "\033[m";
			}
		}

		// ones check
		if (e == e1) {
			bulls++;
			cout << "\033[92;99m" << e << "\033[m";
		}
		else
		{
			if (e == t1 || e == s1 || e == d1)
			{
				cows++;
				cout << "\033[33;99m" << e << "\033[m";
			}
			else {
				cout << "\033[0;99m" << e << "\033[m";
			}
		}

		cout << "\n\033[92;99mBulls: " << bulls << "\033[m\t\033[33;99mCows: " << cows<<"\033[m";
	} while (bulls != 4);

	cout << "\n\n\033[41;99mCongratulations! You won!\033[m\n\n";
}