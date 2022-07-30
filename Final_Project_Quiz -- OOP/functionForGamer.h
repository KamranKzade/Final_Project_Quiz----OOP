#pragma once





Gamer* createGamer() {
	Gamer* gamer = new Gamer{};
	ushort id = gamer->getId();
	gamer->setId(id++);
	gamer->setGamerSize(gamer->getId());

	string name, surname;
	ushort birtday;
	mySetColor(15, 0);
	cout << "Adinizi daxil edin: ";
	mySetColor(2, 0);

	getline(cin, name);
	gamer->setName(name);
	mySetColor(15, 0);
	cout << "Soyadinizi daxil edin: ";
	mySetColor(2, 0);
	getline(cin, surname);
	gamer->setSurname(surname);
	mySetColor(15, 0);
	cout << "Yasinizi daxil edin: ";
	mySetColor(2, 0);
	cin >> birtday;
	gamer->setAge(birtday);

	return gamer;
}


void showGamer(Gamer* gamer)
{
	for (size_t i = 0; i < gamer->getGamerSize(); i++)
	{
		system("cls");
		mySetColor(15, 0);
		cout << "ID: ";
		mySetColor(9, 0);
		cout << gamer[i].getId() << endl;
		mySetColor(15, 0);
		cout << "Name: ";
		mySetColor(9, 0);
		cout << gamer[i].getName() << endl;
		mySetColor(15, 0);
		cout << "Surname: ";
		mySetColor(9, 0);
		cout << gamer[i].getSurname() << endl;
		mySetColor(15, 0);
		cout << "Birthday: ";
		mySetColor(9, 0);
		gamer[i].getAge();
		cout << endl;
		mySetColor(15, 0);
		cout << "Duzlerin Sayi: ";
		mySetColor(9, 0);
		cout << gamer[i].getDuzlerinSayi() << endl;
		mySetColor(15, 0);
		cout << "Netice: ";
		mySetColor(9, 0);
		cout << gamer[i].getNetice() << '%' << endl;
	}
}


void writeGamerToFile(Gamer* gamer)
{
	if (!gamerFile)
		throw "File could not be created";

	gamerFile << gamer->getId() << endl << gamer->getName() << endl << gamer->getSurname() << endl << gamer->getAge() << endl << gamer->getDuzlerinSayi() << endl << gamer->getNetice() << endl << gamer->getGamerSize() << endl;
	gamerFile.close();
}


Gamer* readGamerFromFile()
{
	ifstream fread("Gamer.txt");

	while (!fread.eof())
	{
		Gamer* temp = new Gamer{};

		string name, surname;
		ushort id, gamerSize, age;
		size_t duzlerinSayi;
		float netice;

		fread >> id >> name >> surname >> age >> duzlerinSayi >> netice >> gamerSize;

		temp->setId(id);
		temp->setName(name);
		temp->setSurname(surname);
		temp->setAge(age);
		temp->setDuzlerinSayi(duzlerinSayi);
		temp->setNetice(netice);
		temp->setGamerSize(gamerSize);

		if (fread.peek() != 10)
			break;

		return temp;
	}

	fread.close();
}


//////////////////////////////////////////////////////////////////
//// start quiz


void PrintQuizForGaming(Quiz* quiz, Gamer*& gamer) {

	mySetColor(2, 0);
	cout << endl << endl << R"(
	C++ PROGRAM QUIZ GAME
     _______________________________________
    | ~              WELCOME               ~|
    | ~                 to                 ~|
    | ~           THE IQ GAME              ~|
    |---------------------------------------|
    |~              Maker:                 ~|
    |~                     Kamran  Kzade   ~|
    |~_____________________________________~|)";

	Sleep(1500);


	int	select = 0;
	for (size_t i = 0; i < quiz->getQuestionSize();)
	{
		select = 0;
		int click = 0;
		while (true) {
			system("cls");
			mySetColor(8, 0);
			cout << quiz->getQuestion()[i]->body << endl;


			int variant = 65;
			if (select == 0)
				mySetColor(2, 0);
			cout << char(variant) << ")" << quiz->getQuestion()[i]->answer[0]->answer;
			cout << endl;
			mySetColor(8, 0);
			if (select == 1)
				mySetColor(2, 0);
			cout << char(variant + 1) << ")" << quiz->getQuestion()[i]->answer[1]->answer;
			cout << endl;
			mySetColor(8, 0);
			if (select == 2)
				mySetColor(2, 0);
			cout << char(variant + 2) << ")" << quiz->getQuestion()[i]->answer[2]->answer;
			cout << endl;
			mySetColor(8, 0);
			if (select == 3)
				mySetColor(2, 0);
			cout << char(variant + 3) << ")" << quiz->getQuestion()[i]->answer[3]->answer;
			cout << endl;
			mySetColor(8, 0);
			if (select == 4)
				mySetColor(2, 0);
			cout << char(variant + 4) << ")" << quiz->getQuestion()[i]->answer[4]->answer;
			cout << endl;

			mySetColor(8, 0);
			if (select == 5)
				mySetColor(2, 0);
			cout << "<-Previous" << endl;
			mySetColor(8, 0);
			if (select == 6)
				mySetColor(2, 0);
			cout << "Submit" << endl;
			mySetColor(8, 0);
			if (select == 7)
				mySetColor(2, 0);
			cout << "Next->" << endl;
			mySetColor(8, 0);

			int click = _getch();
			if (click == 224) {
				click = _getch();
				if (click == 72 && select > 0) {
					select--;
				}
				else if (click == 80 && select < 7) {
					select++;
				}
			}

			else if (select == 5) {
				if (i > 0) {
					i--;
					break;
				}
			}
			else if (select == 6) {
				i = globalAnswerId - 1;
				break;
			}
			else if (select == 7) {
				i++;
				break;
			}
			else if (click == 13) {
				ushort duzlerinsayi = 0;
				if (select == 0) {
					if (quiz->getQuestion()[i]->answer[0]->duzgun == true) {
						ushort duzlerinsayi = gamer->getDuzlerinSayi();
						duzlerinsayi++;
						gamer->setDuzlerinSayi(duzlerinsayi);
						// cout << quiz->getQuestion()[i]->answer[0]->answer << endl;
						// cout << duzlerinsayi << endl;
						// Sleep(2000);
					}
				}

				else if (select == 1) {
					if (quiz->getQuestion()[i]->answer[1]->duzgun == true)
					{
						ushort duzlerinsayi = gamer->getDuzlerinSayi();
						duzlerinsayi++;
						gamer->setDuzlerinSayi(duzlerinsayi);
					}

				}


				else if (select == 2) {
					if (quiz->getQuestion()[i]->answer[2]->duzgun == true)
					{
						ushort duzlerinsayi = gamer->getDuzlerinSayi();
						duzlerinsayi++;
						gamer->setDuzlerinSayi(duzlerinsayi);
					}
				}

				else if (select == 3) {
					if (quiz->getQuestion()[i]->answer[3]->duzgun == true)
					{
						ushort duzlerinsayi = gamer->getDuzlerinSayi();
						duzlerinsayi++;
						gamer->setDuzlerinSayi(duzlerinsayi);
					}
				}

				else if (select == 4) {
					if (quiz->getQuestion()[i]->answer[4]->duzgun == true)
					{
						ushort duzlerinsayi = gamer->getDuzlerinSayi();
						duzlerinsayi++;
						gamer->setDuzlerinSayi(duzlerinsayi);
					}
				}
				else if (select == 5) {
					continue;
				}

				i++;
				break;
			}
		}
	}
	system("cls");
	mySetColor(2, 0);
	cout << "Imtahani ugurla verdiz!!!" << endl << endl;
	cout << "Sizin neticeniz: \n";
	int random = 0;
	if ((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 93)
	{
		random = 140 + (rand() % 20);
		cout << "IQ -> " << random << endl;
		cout << "Cox Ustun seviyyeli Zeka" << endl;
	}
	else if (((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 73) && ((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 93))
	{
		random = 131 + (rand() % 10);
		cout << "IQ -> " << random << endl;
		cout << "Ustun seviyyeli Zeka" << endl;
	}
	else if (((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 53) && ((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 73))
	{
		random = 116 + (rand() % 15);
		cout << "IQ -> " << random << endl;
		cout << "Ireli seviyyeli Zeka" << endl;
	}
	else if (((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 33) && ((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 53))
	{
		random = 85 + (rand() % 21);
		cout << "IQ -> " << random << endl;
		cout << "Normal seviyyeli zeka" << endl;
	}
	else if (((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 13) && ((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) > 33))
	{
		random = 70 + (rand() % 15);
		cout << "IQ -> " << random << endl;
		cout << "Serhed!!!! " << endl;
	}
	else if ((gamer->getDuzlerinSayi() * 100 / quiz->getQuestionSize()) < 13) {
		random = 0 + (rand() % 70);
		cout << "IQ -> " << random << endl;
		cout << "Pisdi vezyet " << endl;
	}


	mySetColor(2, 0);
	float netice = (gamer->getDuzlerinSayi() * 100.0f / quiz->getQuestionSize());
	cout << "Duz cavablarin faizi: " << netice << '%' << endl;
	gamer->setNetice(netice);

	ushort Gamersize = gamer->getGamerSize();
	Gamersize += 1;
	gamer->setGamerSize(Gamersize);

	ushort id = gamer->getId();
	id += 1;
	gamer->setId(id);

	Sleep(3000);
}