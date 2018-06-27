#include "przychodnia.h"

using namespace std;
 
przychodnia::przychodnia():_nazwa("") {}

przychodnia::~przychodnia() {}
bool przychodnia::SprawdzPoprawnosc(std::regex & wyrazenie, std::string & dane)
{

	if (regex_match(dane, wyrazenie)) {
		return true;
	}
	return false;
}

void przychodnia::WczytajInformacjePrzychodni(const std::string& informacje)
{
	int koniec_nazwy = informacje.find("\"", 1);
	int koniec_adresu = informacje.find(":", koniec_nazwy);

	_nazwa = informacje.substr(1, koniec_nazwy - 1);
	_adres.WczytajAdres(informacje.substr(koniec_nazwy + 2, koniec_adresu - koniec_nazwy - 2));

	if (koniec_adresu == string::npos)
	{
		//przychodnia nie obsluguje zadnych specjalizacji 
		return;
	}

	string obslugiwane_zawody = informacje.substr(koniec_adresu + 2);

	int prev = 0;
	int pos = obslugiwane_zawody.find(" ");

	while(pos != string::npos)
	{
		_obslugiwane_specjalizacje.push_front(obslugiwane_zawody.substr(prev, pos - prev));
		prev = ++pos;
		pos = obslugiwane_zawody.find(" ", prev);
	}

	_obslugiwane_specjalizacje.push_front(obslugiwane_zawody.substr(prev));
}

void przychodnia::ZapytanieInformacje()
{

	cout << "Podaj nazwe przychodni: ";
	getline(cin, _nazwa);
	while (_nazwa == "" || _nazwa == " ")
	{
		getline(cin, _nazwa);
	}
	_adres.ZapytajInformacje();

	DodajSpecjalizacje();
}

void przychodnia::DodajSpecjalizacje()
{
	string temp;
	cout << "Podaj nowa specjalizacje, k aby zakonczyc: ";
	cin >> temp;

	while (temp != "k")
	{
		_obslugiwane_specjalizacje.push_front(temp);
		cout << "Podaj nowa specjalizacje, k aby zakonczyc: ";
		cin >> temp;
	}
}



void przychodnia::ZapiszSpecjalizacjeDoPliku(std::ofstream& plik) const
{
	if(_obslugiwane_specjalizacje.empty())
	{	
		//przychodnia nie obsluguje zadnych specjalizacji
		return;
	}

	plik << ":";
	for (auto it = _obslugiwane_specjalizacje.begin(); it != _obslugiwane_specjalizacje.end(); ++it)
	{
		plik << " " << (*it);
	}
}

void przychodnia::ZapiszPrzychodnieDoPliku(std::ofstream& plik) const
{
	plik << "\"" << _nazwa << "\"" << " ";
	_adres.ZapiszDoPliku(plik);
	ZapiszSpecjalizacjeDoPliku(plik);
	plik << endl;
}

void przychodnia::WypiszSzczegoloweInformacjePrzychodnia() const
{
	cout << _nazwa << " ";
	_adres.WypiszAdres();
	cout << endl << "  Obslugiwane specjalizacje: ";
	for (auto it = _obslugiwane_specjalizacje.begin(); it != _obslugiwane_specjalizacje.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}

bool przychodnia::PrzychodniaDanejSpecjalnosci(const std::string specjalnosc)
{
	for (auto it = _obslugiwane_specjalizacje.begin(); it != _obslugiwane_specjalizacje.end(); ++it)
	{
		if ((*it) == specjalnosc)
		{
			return true;
		}
	}
	return false;
}
