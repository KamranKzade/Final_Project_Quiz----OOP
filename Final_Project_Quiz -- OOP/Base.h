#pragma once


typedef unsigned short ushort;




class Base
{
protected:
	ushort _id ;
	string _name ;
	ushort _age ;

	Base() = default;

	Base(ushort id, string name, ushort age)
	{
		_id = id;
		_name = name;
		_age = age;
	}

public:

	const ushort getId()  const { return _id; }
	const string getName() const { return _name; }
	const ushort getAge() const { return _age; }

	void setName(string name)
	{
		if (name.empty())
			throw "Re-enter your name";
		if (!_name.empty())
			_name.clear();

		_name = name;
	}

	void setId(ushort id)
	{
		if (id < 0)
			throw "Id is not negative";

		_id = id;
	}

	void setAge(ushort age)
	{
		if (age > 0)
			_age = age;
		else
			throw "Birtday is Wrong";
	}

};