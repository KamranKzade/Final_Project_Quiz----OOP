#pragma once




class Gamer : public Base
{
	string _surname = "";
	size_t _duzlerinSayi = 0;
	float _netice = 0;
	ushort _gamerSize = 0;

public:
	Gamer() = default;

	Gamer(ushort id, string name, ushort birthday, string surname, size_t duzlerinSayi, float netice)
		:Base(id, name, birthday)
	{
		_surname = surname;
		_duzlerinSayi = duzlerinSayi;
		_netice = netice;
	}

	const string getSurname() const { return _surname; }
	const size_t getDuzlerinSayi() const { return _duzlerinSayi; }
	const float getNetice() const { return _netice; }
	const ushort getGamerSize() const { return _gamerSize; }

	void setDuzlerinSayi(size_t duzlerinSayi)
	{
		if (duzlerinSayi < 0)
			throw "DuzlerinSayi is not negative";

		_duzlerinSayi = duzlerinSayi;
	}
	void setSurname(string surname)
	{
		if (surname.empty())
			throw "Re-enter your surname";
		if (!_surname.empty())
			_surname.clear();

		_surname = surname;
	}
	void setNetice(float netice)
	{
		if (netice < 0)
			throw "netice is not negative";

		_netice = netice;
	}
	void setGamerSize(ushort gamerSize)
	{
		if (gamerSize < 0)
			throw "gamerSize is not negative";

		_gamerSize = gamerSize;
	}

};