#pragma once
#include <regex>
#include<iomanip>
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
	bool SprawdzPoprawnosc(std::regex& wyrazenie, std::string& dane);

	void ZapiszSpecjalizacjeDoPliku(std::ofstream& plik) const;
	void ZapiszPrzychodnieDoPliku(std::ofstream& plik) const;
	void WypiszSzczegoloweInformacjePrzychodnia() const;

	bool PrzychodniaDanejSpecjalnosci(const std::string specjalnosc);

	std::string PobierzNazwePrzychodni() const { return _nazwa; }
};

