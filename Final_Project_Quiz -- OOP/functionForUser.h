#pragma once




size_t static usersSize;
User** users = nullptr;


//// Write user to file

void writeUserToFile(User** user)
{
	if (!userFile)
		throw "File could not be created";

	userFile.seekp(0);
	for (size_t i = 0; i < usersSize; i++)
	{
		userFile.seekp(0);
		ushort id, age;
		string name, password;

		id = user[i]->getId();
		age = user[i]->getAge();
		name = user[i]->getName();
		password = user[i]->getPassword();

		userFile << id << endl << name << endl << password << endl << age << endl;
	}
	//userFile.flush();


	userFile.close();
}


//// Read user from file

User* readUserFromFile()
{
	ifstream fread("User.txt");

	fread.seekg(0);


	while (!fread.eof())
	{
		fread.seekg(0);
		User* user = new User();
		string name, password;
		ushort age, id, userSize2;

		fread >> userSize2 >> id >> name >> password >> age;

		user->setId(id);
		user->setName(name);
		user->setPassword(password);
		user->setAge(age);


		// if (fread.peek() != 10)
		// 	break;

		return user;
	}


	fread.close();
}



///////////////////////////////////////////////////////////////////
//// User addition method


void loadUsers()
{
	ifstream fread("User.txt");
	ushort usSize;
	fread >> usSize;

	if (usSize == 52428)
		usSize = 0;

	users = new User * [usSize];

	for (size_t i = 0; i < usSize; i++)
		users[i] = readUserFromFile();
}


void saveUsers()
{
	userFile.seekp(0);
	userFile << usersSize << endl;

	//for (size_t i = 0; i < usersSize; i++)
	writeUserToFile(users);

}


void append(User* user)
{
	User** temp = new User * [usersSize + 1];

	for (size_t i = 0; i < usersSize; i++)
		temp[i] = users[i];

	temp[usersSize++] = user;

	delete[] users;
	users = temp;
}


User* fillUser()
{
	User* user = new User();
	mySetColor(15, 0);
	cout << "Enter username: ";
	mySetColor(2, 0);
	string data;
	getline(cin, data);
	user->setName(data);

	mySetColor(15, 0);
	cout << "Enter password: ";
	mySetColor(2, 0);
	string data2;
	getline(cin, data2);
	user->setPassword(data2);

	return user;
}


User* signUp()
{
	User* user = fillUser();

	ifstream fread("User.txt");
	ushort usSize;
	fread >> usSize;
	if (usSize == 52428)
		usSize = 0;

	if (usSize == 0)
		usersSize = 0;

	usersSize = usSize;


	for (size_t i = 0; i < usersSize; i++)
		if (!(users[i]->getName().compare(user->getName())))
		{
			delete user;
			return nullptr;
		}

	mySetColor(15, 0);
	cout << "Enter Age: ";
	mySetColor(2, 0);
	ushort age;
	cin >> age;
	cin.ignore();
	user->setAge(age);

	if (usersSize != 0)
		user->setId((users[usersSize - 1]->getId()) + 1);

	else
		user->setId(1);

	return user;
}


User* signIn()
{
	system("cls");
	User* user = fillUser();
	return user;
}


bool isExistUser(User* user)
{
	ifstream fread("User.txt");
	ushort usSize;
	fread >> usSize;
	if (usSize == 52428)
		usSize = 0;

	if (usSize == 0)
		usersSize = 0;

	usersSize = usSize;

	for (size_t i = 0; i < usersSize; i++)
		if (!users[i]->getName().compare(user->getName()))
			if (!users[i]->getPassword().compare(user->getPassword()))
				return true;

	return false;
}