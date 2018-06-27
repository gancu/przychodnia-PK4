#pragma once
#include "osoba.h"
 
class pacjent :
	public osoba
{
	static int _aktualny_id;
protected:
	unsigned long long _pesel;
	std::string _numer_ubezpieczenia;

public:
	pacjent();
	~pacjent();

	bool SprawdzPoprawnosc(std::regex& wyrazenie, std::string& dane);
	void WczytajDanePacjenta(const std::string& _dane_pacjenta);
	void ZapytanieInformacje();

	void ZapiszPacjentaDoPliku(std::ofstream& plik) const;
	void WypiszSzczegoloweInformacjePacjenta() const;

	std::string	PobierzNazwisko() const { return _nazwisko; }
	int PobierzId() const { return _id; }
	std::string PobierzPodstawoweDanePacjenta() const { return _imie + " " + _nazwisko + " " + std::to_string(_pesel); }
	static int PobierzAkutalneId() { return _aktualny_id; }
};

