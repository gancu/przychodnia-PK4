#include "lekarz.h"

using namespace std;
 
int lekarz::_aktualny_id = 0;

lekarz::lekarz() :osoba(), _specjalizacja("") {}

lekarz::~lekarz() {}

void lekarz::WczytajDaneLekarzy(const std::string& dane_lekarza)
{
	int zawod = dane_lekarza.find_last_of(" ");
	string podstawowe_inf = dane_lekarza.substr(0, zawod);

	WczytajInformacje(podstawowe_inf);

	_specjalizacja = dane_lekarza.substr(zawod+1);

	_aktualny_id++;
}

void lekarz::ZapytanieInformacje()
{
	ZapytajPodstawoweInformacje(_aktualny_id);

	cout << "Podaj specjalizacje lekarza: ";
	cin >> _specjalizacja;
}

std::string lekarz::WypiszPodstawoweDane() const
{
	return _imie + " " + _nazwisko + "\t" + _specjalizacja;
}

void lekarz::WypiszSzczegoloweDane() const
{
	WypiszSzczegoloweInformacjeOsoba();
	cout << _specjalizacja << "\t";
}

void lekarz::ZapiszLekarzaDoPliku(std::ofstream& plik) const
{
	ZapiszOsobeDoPliku(plik);
	plik << _specjalizacja;
}
