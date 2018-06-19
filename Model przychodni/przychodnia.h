#pragma once
#include "Adres.h"
#include <forward_list>
 
class przychodnia
{
	std::string _nazwa;
	Adres _adres;
	std::forward_list<std::string> _obslugiwane_specjalizacje;

public:
	przychodnia();
	~przychodnia();

	void WczytajInformacjePrzychodni(const std::string& informacje);
	void ZapytanieInformacje();
	void DodajSpecjalizacje();

	void ZapiszSpecjalizacjeDoPliku(std::ofstream& plik) const;
	void ZapiszPrzychodnieDoPliku(std::ofstream& plik) const;
	void WypiszSzczegoloweInformacjePrzychodnia() const;

	bool PrzychodniaDanejSpecjalnosci(const std::string specjalnosc);

	std::string PobierzNazwePrzychodni() const { return _nazwa; }
};

