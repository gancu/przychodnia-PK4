#include "Adres.h"

using namespace std;

Adres::Adres() : _ulica(""), _numer_domu(""), _miasto(""), _kod_pocztowy("") {}

Adres::~Adres() {}

void Adres::WczytajAdres(const std::string & adres)
{
	int prev = adres.find_first_of(" ");
	_ulica = adres.substr(0, prev);
	int temp = adres.find(" ", prev + 1);
	_numer_domu = adres.substr(prev + 1, temp - prev - 1);
	prev = temp;
	temp = adres.find(" ", prev + 1);
	_miasto = adres.substr(prev + 1, temp - prev - 1);
	_kod_pocztowy = adres.substr(temp + 1);

}

void Adres::ZapytajInformacje()
{
	cout << "Podaj adres: (ulica, numer domu / mieszkania, miejscowosc, kod pocztowy) " << endl;

	cout << "Ulica: ";
	cin >> _ulica;

	cout << "Numer budynku: ";
	cin >> _numer_domu;

	cout << "Miasto: ";
	cin >> _miasto;

	cout << "Kod pocztowy: ";
	cin >> _kod_pocztowy;
	cout << endl;
}

void Adres::ZapiszDoPliku(std::ofstream& plik) const
{
	plik << _ulica << " " << _numer_domu << " " << _miasto << " " << _kod_pocztowy;
}

void Adres::WypiszAdres() const
{
	cout << _ulica << "\t" << _numer_domu << "\t" << _miasto << "\t" << _kod_pocztowy << "\t";
}
