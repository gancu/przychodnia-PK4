#pragma once
#include "osoba.h"
 
class lekarz :
	public osoba
{
	static int _aktualny_id;
protected:
	std::string _specjalizacja;

public:
	lekarz();
	~lekarz();

	void WczytajDaneLekarzy(const std::string& _dane_lekarza);
	void ZapytanieInformacje();

	void WypiszSzczegoloweDane() const;
	std::string WypiszPodstawoweDane() const;
	void ZapiszLekarzaDoPliku(std::ofstream& plik) const;

	std::string PobierzSpecjalizacje() const { return _specjalizacja; }
	std::string PobierzNazwiskoLekarza() const { return _nazwisko; }
	static int PobierzAkutalneId() { return _aktualny_id; }
};

