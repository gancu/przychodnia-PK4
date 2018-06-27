#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include<iomanip>
#include <regex>

 
class Adres
{
	std::string _ulica;
	std::string _numer_domu;
	std::string _miasto;
	std::string _kod_pocztowy;

public:
	Adres();
	~Adres();
	
	bool SprawdzPoprawnosc(std::regex& wyrazenie, std::string& dane);
	void WczytajAdres(const std::string& adres);
	void ZapytajInformacje();

	void ZapiszDoPliku(std::ofstream& plik) const;
	void WypiszAdres() const;
	
};
