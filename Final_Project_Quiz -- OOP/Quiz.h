#pragma once




struct Answer {
	string answer = "";
	bool duzgun = 0;

	Answer() = default;

	Answer(string answer, bool duzgun)
	{
		this->answer = answer;
		this->duzgun = duzgun;
	}

};



struct Question
{
	ushort id = 0;
	string body = "";
	ushort answerSize = 0;
	Answer** answer = NULL;

	Question() = default;

	Question(ushort id, string body, ushort answerSize, Answer** answer)
	{
		this->id = id;
		this->body = body;
		this->answerSize = answerSize;
		this->answer = answer;
	}

};



class Quiz
{
	ushort _id = 0;
	string _Name = "";
	ushort _questionSize = 0;

public:

	Question** _Question;
	
	Quiz() = default;
	
	Quiz(ushort id, string name, ushort questionSize, Question** question)
	{
		_id = id;
		_Name = name;
		_questionSize = questionSize;
		_Question = question;
	}

	ushort getId()const { return _id; }
	string getName() const { return _Name; }
	ushort getQuestionSize() const { return _questionSize; }
	Question** getQuestion() const { return _Question; }


	void setId(ushort id)
	{
		if (id < 0)
			throw "Id cannot be negative";

		_id = id;
	}

	void setNameQuiz(string name)
	{
		if (name.empty())
			throw "Enter name repeat, please";
		if (name.size() <= 3)
			throw "the length of the name must be more than 3 letters";

		_Name = name;
	}

	void setQuestionSize(ushort questionSize)
	{
		if (questionSize < 0)
			throw "Question size can not be negative";
		_questionSize = questionSize;
	}

	void setQuestion(Question** question)
	{
		_Question = question;
	}

};