#pragma once
#include <string>
#include <iostream>
#include "Adres.h"
 
class osoba
{
protected:
	int _id;
	std::string _imie;
	std::string _nazwisko;
	Adres _adres;
	char _plec;
	unsigned int _numer_telefonu;

public:

	void WczytajInformacje(const std::string& informacje);
	void ZapytajPodstawoweInformacje(int id);

	void ZapiszOsobeDoPliku(std::ofstream& plik) const;
	void WypiszSzczegoloweInformacjeOsoba() const;

	osoba();
	virtual ~osoba();
};

