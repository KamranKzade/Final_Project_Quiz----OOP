#pragma once




////////////////////////////////////////////////////////////////////////////////////
// renglendirmek funksiya

void mySetColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}



////////////////////////////////////////////////////////////////////////////////////
// Animation

void baslangic() {
	int tiMe = 25, percent = 4;
	mySetColor(2, 0);
	cout << endl << endl << R"(
	C++ PROGRAM QUIZ GAME
	 _______________________________________
	|               WELCOME                 |
	|                  to                   |
	|            THE Quiz GAME              |
	|_______________________________________|)";
	Sleep(4000);
	while (tiMe != 0) {
		system("cls");
		mySetColor(15, 0);
		cout << endl << endl << setw(20) << percent << "%" << endl;
		percent += 4;
		for (size_t i = 0; i < 25 - tiMe; i++)
			cout << char(219) << " ";
		tiMe--;
		Sleep(250);
	}
	cout << endl;
	Sleep(2000);
	system("cls");
}



////////////////////////////////////////////////////////////////////////////////////
// Start window

int secimlerBaslangic(int& mouse) {
	system("cls");

	if (mouse == 0)
		mySetColor(2, 0);
	cout << "\nAdmin\n";
	cout << endl;
	mySetColor(8, 0);
	if (mouse == 1)
		mySetColor(2, 0);
	cout << "Start Quiz\n" << endl;
	mySetColor(8, 0);
	if (mouse == 2)
		mySetColor(2, 0);
	cout << "Guest\n" << endl;
	mySetColor(8, 0);

	int x = _getch();
	if (x == 224) {
		int y = _getch();
		if (y == 72 && mouse > 0) {
			mouse--;
		}
		else if (y == 80 && mouse < 2) {
			mouse++;
		}
	}
	if (x == 13) {
		return mouse;
	}
	secimlerBaslangic(mouse);
}



////////////////////////////////////////////////////////////////////////////////////
// Admin in  secimleri

int adminChoice(int& make)
{
	system("cls");
	if (make == 0)
		mySetColor(2, 0);
	cout << "Sign UP\n";
	cout << endl;
	mySetColor(8, 0);
	if (make == 1)
		mySetColor(2, 0);
	cout << "Sign In\n";
	cout << endl;
	mySetColor(8, 0);
	if (make == 2)
		mySetColor(2, 0);
	cout << "Back\n";
	mySetColor(8, 0);


	int x = _getch();
	if (x == 224) {
		int y = _getch();
		if (y == 72 && make > 0) {
			make--;
		}
		else if (y == 80 && make < 2) {
			make++;
		}
	}
	if (x == 13) {
		return make;
	}
	adminChoice(make);
}



////////////////////////////////////////////////////////////////////////////////////
// User in secimleri

int UserChoice(int& gamer)
{
	system("cls");
	if (gamer == 0)
		mySetColor(2, 0);
	cout << "Start Game\n";
	cout << endl;
	mySetColor(8, 0);
	if (gamer == 1)
		mySetColor(2, 0);
	cout << "Look Result Gamer\n";
	cout << endl;
	mySetColor(8, 0);
	if (gamer == 2)
		mySetColor(2, 0);
	cout << "Back\n";
	mySetColor(8, 0);

	int x = _getch();
	if (x == 224) {
		int y = _getch();
		if (y == 72 && gamer > 0) {
			gamer--;
		}
		else if (y == 80 && gamer < 2) {
			gamer++;
		}
	}
	if (x == 13) {
		return gamer;
	}
	UserChoice(gamer);
}




////////////////////////////////////////////////////////////////////////////////////
// Guest in secimleri

int guestChoice(int& gamer)
{
	system("cls");
	if (gamer == 0)
		mySetColor(2, 0);
	cout << "Play Quiz\n";
	cout << endl;
	mySetColor(8, 0);
	if (gamer == 1)
		mySetColor(2, 0);
	cout << "Back\n";
	mySetColor(8, 0);

	int x = _getch();
	if (x == 224) {
		int y = _getch();
		if (y == 72 && gamer > 0) {
			gamer--;
		}
		else if (y == 80 && gamer < 1) {
			gamer++;
		}
	}
	if (x == 13) {
		return gamer;
	}
	guestChoice(gamer);
}