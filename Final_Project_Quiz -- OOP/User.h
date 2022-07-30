#pragma once





class User : public Base
{
	string _password ;
	
public:

	User() = default;
	
	User(ushort id, string name, ushort birthday, string password)
		:Base(id, name, birthday)
	{
		_password = password;
	}

	const string getPassword() const { return _password; }
	void setPassword(string password)
	{
		if (password.empty())
			throw "Re-enter your surname";
		if (!_password.empty())
			_password.clear();

		_password = password;
	}

};