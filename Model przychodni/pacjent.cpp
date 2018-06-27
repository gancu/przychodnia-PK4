#include "pacjent.h"
 
using namespace std;

int pacjent::_aktualny_id = 0;

pacjent::pacjent() :osoba(), _pesel(-1), _numer_ubezpieczenia("") {}

pacjent::~pacjent() {}


bool pacjent::SprawdzPoprawnosc(std::regex & wyrazenie, std::string & dane)
{
	if (regex_match(dane, wyrazenie)) {
		return true;
	}
	return false;
}
void pacjent::WczytajDanePacjenta(const std::string& _dane_pacjenta)
{
	int przed_nr_ubezp = _dane_pacjenta.find_last_of(" ");
	int przed_nr_pesel = _dane_pacjenta.find_last_of(" ", przed_nr_ubezp - 1);

	string podstawowe_inf = _dane_pacjenta.substr(0, przed_nr_pesel);
	string numery = _dane_pacjenta.substr(przed_nr_pesel + 1);

	WczytajInformacje(podstawowe_inf);

	int temp = numery.find_first_of(" ");
	_pesel = stoll(numery.substr(0, temp));
	_numer_ubezpieczenia = numery.substr(temp + 1);

	_aktualny_id++;
}

void pacjent::ZapytanieInformacje()
{
	ZapytajPodstawoweInformacje(_aktualny_id);
	string tmp;
	regex regex;

	regex = "(\\d{11})";
	cout << "Podaj pesel: ";
	cin >> tmp;
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawnie numer pesel (11 cyfr): ";
		cin >> tmp;
	}
	_pesel = stoll(tmp);


	regex = "(\\d{1,})";
	cout << "Podaj numer ubzepieczenia: ";
	cin >> tmp;
	while (!SprawdzPoprawnosc(regex, tmp)) {
		cout << "Podaj poprawnie numer ubezpieczenia : ";
		cin >> tmp;
	}
	_numer_ubezpieczenia = stoll(tmp);
}

void pacjent::ZapiszPacjentaDoPliku(std::ofstream& plik) const
{
	ZapiszOsobeDoPliku(plik);
	plik << _pesel << " " << _numer_ubezpieczenia << endl;
}

void pacjent::WypiszSzczegoloweInformacjePacjenta() const
{
	WypiszSzczegoloweInformacjeOsoba();
	cout<< _pesel << " " << _numer_ubezpieczenia << endl;
}
