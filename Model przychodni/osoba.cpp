#include "osoba.h"
#include <fstream>
using namespace std;

osoba::osoba() : _id(-1), _imie(""), _nazwisko(""), _plec('0'), _numer_telefonu(-1) {}

osoba::~osoba() {}

void osoba::WczytajInformacje(const std::string& informacje)
{
	int prev = informacje.find_first_of(" ");

	string pom = informacje.substr(0, prev);

	_id = stoi(informacje.substr(0, prev));

	int temp = informacje.find(" ", prev + 1);

	_plec = informacje.substr(prev + 1, temp - prev)[0];

	prev = temp;
	temp = informacje.find(" ", prev + 1);

	_imie = informacje.substr(prev + 1, temp - prev - 1);

	prev = temp;
	temp = informacje.find(" ", prev + 1);

	_nazwisko = informacje.substr(prev + 1, temp - prev - 1);

	prev = temp;
	temp = informacje.find(" ", prev + 1);

	_numer_telefonu = stoul(informacje.substr(prev + 1, temp - prev));

	string ulica = informacje.substr(temp + 1);

	_adres.WczytajAdres(ulica);

}

void osoba::ZapytajPodstawoweInformacje(int id)
{
	_id = id;

	cout << "Podaj imie i nazwisko: ";
	cin >> _imie >> _nazwisko;

	cout << "Podaj plec: (K/M) ";
	cin >> _plec;

	cout << "Podaj numer kontaktowy: ";
	cin >> _numer_telefonu;

	_adres.ZapytajInformacje();
}

void osoba::ZapiszOsobeDoPliku(std::ofstream& plik) const
{
	plik << _id << " " << _plec << " " << _imie << " " << _nazwisko << " " << _numer_telefonu << " ";
	_adres.ZapiszDoPliku(plik);
	plik << " ";
}

void osoba::WypiszSzczegoloweInformacjeOsoba() const
{
	cout << _id << "\t" << _imie << "\t" << _nazwisko << "\t";
	_adres.WypiszAdres();
	cout << _numer_telefonu << "\t";
}


