#pragma once
#include <string>
#include <iostream>
#include <fstream>
 
class Adres
{
	std::string _ulica;
	std::string _numer_domu;
	std::string _miasto;
	std::string _kod_pocztowy;

public:
	Adres();
	~Adres();
	
	void WczytajAdres(const std::string& adres);
	void ZapytajInformacje();

	void ZapiszDoPliku(std::ofstream& plik) const;
	void WypiszAdres() const;
	
};
