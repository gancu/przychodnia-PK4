#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include "pacjent.h"
#include "lekarzLista.h"
#include "przychodnia.h"
 
class interfejs
{
	bool koniec = false;

	std::string _plik_lekarze;
	std::string _plik_pacjenci;
	std::string _plik_przychodnie;

	std::multimap<std::string, std::shared_ptr<pacjent>> _pacjenci;
	std::multimap<std::string, std::shared_ptr<lekarzLista>> _lekarze;
	std::forward_list<std::shared_ptr<przychodnia>> _lista_przychodni;

	int _ilosc_przychodni = 0;

public:
	interfejs();
	~interfejs();

	void Program(int argc, char** argv);

private:
	//dodawanie do bazy
	void DodajPacjenta();
	void DodajLekarza();
	void DodajPrzychodnie();
	void DodajSpecDoPrzychodni();

	//zarzadzanie pacjentami
	void ZapiszPacjenta();
	void WizytaPacjenta();

	//usuwanie z bazy
	void UsunLekarza();
	void UsunPacjenta();
	void UsunPrzychodnie();
	
	//wypisywanie szczegolowe
	void WypiszSzczegolowoPacjentow() const;
	void WypiszSzczegolowoLekarzy() const;
	void WypiszSzczegolowoPrzychodnie() const;

	//wczytywanie danych z pliku
	void WczytajPacjentow();
	void WczytajListeLekarzy();
	void WczytajPrzychodnie();

	//glowna metoda wczytywania
	void WczytajZPlikow();

	//glowna metoda zapisywania
	void ZapiszPliki();

	//zapisywanie danych
	void ZapiszPacjentow();
	void ZapiszListeLekarzy();
	void ZapiszPrzychodnie();

	//metoda do pobierania parametrow
	bool PobierzParametry(int argc, char ** argv);

	//statyczne metody to wyswietlania informacji
	static void Pomoc();
	static void WyswietlMenu();
	static void WyswietlDodawanie();
	static void WyswietlZarzadzanie();
	static void WyswietlUsuwanie();
	static void WyswietlSzczegolowe();

	static int PobierzWybor(int kres_dolny, int kres_gorny);

	//metody do wyspietlania informacji
	void WypiszPrzychodnie() const;
	void WypiszLekrzy() const;
	void WypiszPacjentow() const;

	//metody glowne menu
	void DodawanieDoBazy();
	void ZarzadzaniePacjentami();
	void UsuwanieZBazy();
	void SzczegoloweInformacje();

	void ZnajdzPrzychodnieOSpecjalnosci(const std::string& specjalnosc);

	std::shared_ptr<pacjent> PobierzDanePacjenta(int id_pacjenta);
	std::shared_ptr<pacjent> ZnajdzOdpowiadajaceNazwiskaPacjent(const std::string& nazwisko);

	std::multimap<std::string, std::shared_ptr<lekarzLista>>::iterator ZnajdzInnegoLekarza(const std::string& specjalizacja);

};
