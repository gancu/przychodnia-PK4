#include "osoba.h"
#include <fstream>
using namespace std;

osoba::osoba() : _id(-1), _imie(""), _nazwisko(""), _plec('0'), _numer_telefonu(-1) {}

osoba::~osoba() {}

bool osoba::SprawdzPoprawnosc(std::regex & wyrazenie, std::string & dane)
{
		if (regex_match(dane, wyrazenie)) {
			return true;
		}
		return false;
	}

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
	string tmp;
	regex regex;
	_id = id;

	regex = "([A-Z]+\\w{1,10})";
	cout << "Podaj Imie: ";
	cin >> tmp;
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawnie imie : ";
		cin >> tmp;
	}
	_imie = tmp;

	cout << "Podaj Nazwisko: ";
	cin >> tmp;
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawnie nazwisko : ";
		cin >> tmp;
	}
	_nazwisko = tmp;

	cout << "Podaj plec: (K/M) ";
	cin >> tmp;
	while(!(tmp[0]=='K' || tmp[0]=='M')) {
		cout << "Wprowadz poprawnie plec (K/M) " <<endl;
		cin >> tmp;
	} _plec = tmp[0];
		
	regex = "(\\d{9})";
	cout << "Podaj numer kontaktowy: ";
	cin >> tmp;
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawny numer kontaktowy (9 znakow 0-9): ";
		cin >> tmp;
	}
	_numer_telefonu = stoi(tmp);

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


