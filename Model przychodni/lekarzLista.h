#pragma once
#include "lekarz.h"
#include "pacjent.h"
#include <memory>
#include <queue>
 
class lekarzLista
{
	lekarz _lekarz;
	std::queue<int> _numery_obslugiwanych_pacjentow;

	int _maksymalna_ilosc_pacjentow = 5;

public:
	lekarzLista();
	~lekarzLista();

	void WczytajDoLekarzaZLista(const std::string& informacja);
	void ZapytanieInforamcje();
	void ZapiszObslugiwancyhPacjentowDoPliku(std::ofstream& plik);
	void ZapiszLekarzListaDoPliku(std::ofstream& plik);

	void WypiszSzczegoloweInformacjeLekarza () const;

	void UsunOstatniegoPacjentaZListy() { _numery_obslugiwanych_pacjentow.pop(); }

	std::string WpiszPacjenta(const std::shared_ptr<pacjent>& wybrany_pacjent);

	std::string PobierzSpecjalizacje() const { return _lekarz.PobierzSpecjalizacje(); }
	std::string WypiszPodstawoweDaneLekarza() const { return _lekarz.WypiszPodstawoweDane(); }
	int OstatniPacjent() const { return _numery_obslugiwanych_pacjentow.front(); }
	int QueueSize() const { return _numery_obslugiwanych_pacjentow.size(); }
	int MaksymalnaIloscPacjentow() const { return _maksymalna_ilosc_pacjentow; }
	std::string PobierzNazwiskoLekarza() const { return _lekarz.PobierzNazwiskoLekarza(); }
};

