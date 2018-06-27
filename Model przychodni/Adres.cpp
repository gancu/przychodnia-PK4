#include "Adres.h"

using namespace std;

Adres::Adres() : _ulica(""), _numer_domu(""), _miasto(""), _kod_pocztowy("") {}

Adres::~Adres() {}

bool Adres::SprawdzPoprawnosc(std::regex & wyrazenie, std::string & dane)
{
		if (regex_match(dane, wyrazenie)) {
			return true;
		}
		return false;
}


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
	string tmp = "";
	regex regex;

	cout << "Podaj adres: (ulica, numer domu / mieszkania, miejscowosc, kod pocztowy) " << endl;
	regex = "([A-Z]{1}[a-zA-Z]{1,}\\s+\\w{1,}\\s+\\w{1,}|[A-Z]{1}[a-zA-Z]{1,}\\s+\\w{1,}|[A-Z]{1}[a-zA-Z]{1,})";
	cout << "Podaj nazwe ulicy : ";
	cin.ignore();
	getline(cin, tmp);
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj nazwe ulicy : ";
		getline(cin, tmp);
	}
	_ulica = tmp;

	regex = "(\\d{1,}[/]\\d{1,}|\\d{1,})";
	cout << "Numer budynku: ";
	cin >> tmp;
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawnie numer budynku ex(13 lub 123/3) : ";
		cin >> tmp;
	}
	_numer_domu = tmp;


	regex = "([A-Z]{1}[a-zA-Z]{1,}\\s+\\w{1,}\\s+\\w{1,}|[A-Z]{1}[a-zA-Z]{1,}\\s+\\w{1,}|[A-Z]{1}[a-zA-Z]{1,})";
	cout << "Miasto : ";
	cin.ignore();
	getline(cin, tmp);
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawne miasto : ";
		getline(cin, tmp);
	}
	_miasto = tmp;


	regex = "(\\d{2}[-]\\d{3})";
	cout << "Kod pocztowy : ";
	cin >> tmp;
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawny kod pocztowy (xx-xxx) : ";
		getline(cin, tmp);
	}
	_kod_pocztowy = tmp;
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
