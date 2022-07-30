#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>


using namespace std;


#include "Design.h"
#include "Base.h"
#include "Gamer.h"
#include "Quiz.h"
#include "User.h"

ofstream userFile("User.txt ", ios::app);

#include "functionForUser.h"

ofstream quizFile("Quiz.txt", ios::app);
ofstream gamerFile("Gamer.txt", ios::app);

#include "functionForQuiz.h"
#include "functionForGamer.h"





ushort GamerSize = 0;

int main()
{
	srand(time(NULL));
	baslangic();

	loadUsers();


	while (true)
	{
		int secim = 0;
		secim = secimlerBaslangic(secim);
		
		///// Admin - in icerisi

		if (secim == 0)
		{
			secim = 0;

			while (true)
			{
				secim = adminChoice(secim);
				mySetColor(0, 0);

				// Sign Up
				if (secim == 0)
				{
					system("cls");
					User* user = signUp();
					mySetColor(4, 0);

					if (user == nullptr)
					{
						cout << "\n\tThis username used, pls try again\n";
						Sleep(3000);
						break;
					}

					mySetColor(2, 0);
					append(user);
					saveUsers();
					cout << "\n\n========== Successfully ==========\n\n";
					Sleep(3000);
					break;
				}


				// Sign In
				else if (secim == 1)
				{
					User* user = signIn();

					bool isExist = isExistUser(user);

					if (isExist)
					{
						mySetColor(2, 0);
						Quiz* quiz = createQuiz();

						writeQuizToFile(quiz);

						quizFile.close();
						cout << "\n\n========== Successfully ==========\n\n" << endl;
						Sleep(3000);
						break;
					}
					else
					{
						mySetColor(4, 0);
						cout << "\n\tSign in failed, username or password is wrong\n";
						Sleep(3000);
						continue;
					}
				}

				// Back
				else if (secim == 2) {
					break;
				}
				userFile.close();
			}
		}

		///// User - in icerisi

		else if (secim == 1)
		{
			secim = 0;
			secim = UserChoice(secim);
			while (true)
			{
				// Start Game
				if (secim == 0) {
					system("cls");
					mySetColor(2, 0);

					Gamer* gamer = createGamer();
					Quiz* temp = readQuizFromFile();

					PrintQuizForGaming(temp, gamer);
					writeGamerToFile(gamer);

					Sleep(3000);
					break;
				}

				// Board
				else if (secim == 1)
				{
					cout << "Neticeler\n";
					Gamer* temp = readGamerFromFile();

					showGamer(temp);
					Sleep(3000);
					break;
				}

				// Back
				else if (secim == 2)
				{
					break;
				}
			}
		}

		///// Guest

		else if (secim == 2)
		{
			secim = 0;
			secim = guestChoice(secim);
			while (true)
			{
				// Start game 
				if (secim == 0)
				{
					Quiz* temp = readQuizFromFile();
					Gamer* gamer = new Gamer();
					PrintQuizForGaming(temp, gamer);

					Sleep(3000);
					break;
				}

				// Back
				else if (secim == 1)
				{
					break;
				}
			}
		}
	}
}