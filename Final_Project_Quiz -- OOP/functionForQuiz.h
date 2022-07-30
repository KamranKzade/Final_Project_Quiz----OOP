#pragma once


ushort globalAnswerId = 0;
ushort gloabalQuestionSize = 0;
ushort gloabalQuestionId = 0;



Answer** createAnswer() {

	system("cls");
	Answer** cavablar = new Answer * [globalAnswerId];

	for (size_t i = 0; i < globalAnswerId; i++)
		cavablar[i] = new Answer[1];


	for (size_t i = 0; i < globalAnswerId; i++)
	{
		mySetColor(15, 0);
		cout << "Varianti daxil edin: ";
		mySetColor(2, 0);
		string data;
		getline(cin, data);
		cavablar[i]->answer = data;

		mySetColor(15, 0);
		cout << "Cavab dogrudur? ";
		mySetColor(2, 0);

		cin >> cavablar[i]->duzgun;
		cin.ignore();
	}

	return cavablar;
}


void showAnswer(Answer* cavab) {

	mySetColor(15, 0);
	cout << "Variant: ";
	mySetColor(9, 0);
	cout << cavab->answer << endl;
	mySetColor(15, 0);
	cout << "Duzgundur: ";
	mySetColor(9, 0);
	cout << bool(cavab->duzgun) << endl;
}


Question** createQuestion2(Quiz* quiz) {
	cin.ignore();
	Question** suallar = new Question * [gloabalQuestionSize];

	for (size_t i = 0; i < gloabalQuestionSize; i++)
		suallar[i] = new Question();


	for (size_t i = 0; i < gloabalQuestionSize; i++)
	{
		suallar[i]->id = i;

		mySetColor(15, 0);
		cout << "Suali  daxil edin: ";
		mySetColor(2, 0);
		string body;
		getline(cin, body);
		suallar[i]->body = body;

		mySetColor(15, 0);
		cout << "Cavablarin sayini daxil edin: ";
		mySetColor(2, 0);
		cin >> suallar[i]->answerSize;
		globalAnswerId = suallar[i]->answerSize;
		cin.ignore();

		suallar[i]->answer = createAnswer();

	}
	return suallar;
}


void ShowQuestion(Question* sual) {

	mySetColor(15, 0);
	cout << "Id: ";
	mySetColor(9, 0);
	cout << sual->id << endl;
	mySetColor(15, 0);
	cout << "Beden: ";
	mySetColor(9, 0);
	cout << sual->body;
	mySetColor(15, 0);
	cout << "\nCavablar: \n";

	for (size_t i = 0; i < sual->answerSize; i++)
	{
		showAnswer(sual->answer[i]);
	}
}


Quiz* createQuiz() {
	Quiz* quiz = new Quiz{};
	ushort id = quiz->getId();
	quiz->setId(id++);

	mySetColor(15, 0);
	cout << "Quizin adini daxil edin: ";
	mySetColor(9, 0);
	string name;
	getline(cin, name);
	quiz->setNameQuiz(name);

	mySetColor(15, 0);
	cout << "Quizdeki suallarin sayini daxil edin: ";
	mySetColor(9, 0);
	ushort quesSize;
	cin >> quesSize;
	quiz->setQuestionSize(quesSize);


	gloabalQuestionSize = quiz->getQuestionSize();

	auto create = createQuestion2(quiz);
	quiz->setQuestion(create);

	return quiz;
}


void ShowQuiz(Quiz* quiz) {
	mySetColor(15, 0);
	cout << "ID: ";
	mySetColor(9, 0);
	cout << quiz->getId() << endl;
	mySetColor(15, 0);
	cout << "Quiz Name: ";
	mySetColor(9, 0);
	cout << quiz->getName() << endl;
	mySetColor(15, 0);
	cout << "Suallarin sayi: ";
	mySetColor(9, 0);
	cout << quiz->getQuestionSize() << endl;
	mySetColor(15, 0);

	mySetColor(15, 0);
	cout << "\Suallar: \n";
	for (size_t i = 0; i < quiz->getQuestionSize(); i++)
	{
		ShowQuestion(quiz->getQuestion()[i]);
	}
}


/////////////////////////////////////////////////////////////////////
//// Quiz File yazmaq ve oxumaq


void writeQuizToFile(Quiz* quiz)
{

	if (!quizFile)
		throw "File could not be created";


	quizFile << quiz->getId() << endl << quiz->getName() << endl << quiz->getQuestionSize() << endl;

	for (size_t i = 0; i < quiz->getQuestionSize(); i++)
	{
		quizFile << quiz->getQuestion()[i]->id << endl;
		quizFile << quiz->getQuestion()[i]->body << endl;
		quizFile << quiz->getQuestion()[i]->answerSize << endl;

		for (size_t j = 0; j < quiz->getQuestion()[i]->answerSize; j++)
		{
			quizFile << quiz->getQuestion()[i]->answer[j]->answer << endl;
			quizFile << quiz->getQuestion()[i]->answer[j]->duzgun << endl;
		}
	}
	// quizFile.flush();

	quizFile.close();
}


Quiz* readQuizFromFile()
{


	ifstream fread("Quiz.txt");


	while (!fread.eof())
	{
		Quiz* temp = new Quiz{};


		string name;
		ushort id, questionSize;
		fread >> id;
		fread >> name;

		fread >> questionSize;
		temp->setId(id);
		temp->setNameQuiz(name);
		temp->setQuestionSize(questionSize);

		temp->_Question = new Question * [questionSize];

		for (size_t i = 0; i < questionSize; i++)
		{
			temp->getQuestion()[i] = new Question();

			ushort id, answerSize;
			string  body;

			fread >> id;
			fread >> body;
			fread >> answerSize;

			temp->getQuestion()[i]->id = id;
			temp->getQuestion()[i]->body = body;
			temp->getQuestion()[i]->answerSize = answerSize;

			temp->getQuestion()[i]->answer = new Answer * [answerSize];

			for (size_t j = 0; j < answerSize; j++)
			{
				temp->getQuestion()[i]->answer[j] = new Answer();
				string answer;
				bool duzgun;

				fread >> answer >> duzgun;
				temp->getQuestion()[i]->answer[j]->answer = answer;
				temp->getQuestion()[i]->answer[j]->duzgun = duzgun;
			}
		}
		if (fread.peek() != 10)
			break;

		return temp;

	}

	fread.close();

}