#include "interfejs.h"

using namespace std;
 
interfejs::interfejs() {}

interfejs::~interfejs() {}

void interfejs::WyswietlMenu()
{
	cout << stoi("0");
	cout << endl;
	cout << "MENU:" << endl;
	cout << "1\tDodaj do bazdy danych." << endl;
	cout << "2\tUsun z bazy danych." << endl;
	cout << "3\tZarzadzaj pacjentami." << endl;
	cout << "4\tSzczegolowe informacje." << endl;
	cout << "0\tZakoncz program." << endl;
	cout << endl;
}

void interfejs::WyswietlDodawanie()
{
	cout << endl;
	cout << "1\tDodaj pacjenta." << endl;
	cout << "2\tDodaj lekarza." << endl;
	cout << "3\tDodaj przychodnie." << endl;
	cout << "4\tDodaj specjalizacje do wybranej przychodni." << endl;
	cout << "9\tPowrot do Menu." << endl;
	cout << "0\tWyjscie z programu." << endl;
	cout << endl;
}

void interfejs::WyswietlZarzadzanie()
{
	cout << endl;
	cout << "1\tZapisz pacjenta do lekarza." << endl;
	cout << "2\tWizyta pacjenta." << endl;
	cout << "9\tPowrot do Menu." << endl;
	cout << "0\tWyjscie z programu." << endl;
	cout << endl;
}

void interfejs::WyswietlUsuwanie()
{
	cout << endl;
	cout << "1\tUsun pacjenta." << endl;
	cout << "2\tUsun lekarza." << endl;
	cout << "3\tUsun przychodnie." << endl;
	cout << "9\tPowrot do Menu." << endl;
	cout << "0\tWyjscie z programu." << endl;
	cout << endl;
}

void interfejs::WyswietlSzczegolowe()
{
	cout << endl;
	cout << "1\tSzczegolowe informacje dotyczace pacjentow." << endl;
	cout << "2\tSzczegolowe informacje dotyczace lekarzy." << endl;
	cout << "3\tSzczegolowe informacje dotyczace przychodni." << endl;
	cout << "9\tPowrot do Menu." << endl;
	cout << "0\tWyjscie z programu." << endl;
	cout << endl;

}

bool interfejs::CzyWpisanoCyfre(string& a)
{
	try
	{
		stoi(a);
		return true;
	}
	catch (exception)
	{
		cout << "Prosze podac cyfre: " << endl;
		return false;
	}
}

int interfejs::PobierzWybor(int kres_dolny, int kres_gorny)
{
	string tmp;
	int wybor;
	cin >> tmp;
	while (!CzyWpisanoCyfre(tmp)) {
		cin >> tmp;
	}

	wybor = stoi(tmp);
	while (wybor < kres_dolny || wybor >= kres_gorny)
	{
		cout << "Podales numer spoza zakresu. Wprowadz numer ponownie: ";
		cin >> wybor;
	}

	return wybor;
}

void interfejs::WypiszPrzychodnie() const
{
	int i = 0;

	for (auto it = _lista_przychodni.begin(); it != _lista_przychodni.end(); ++it, ++i)
	{
		cout << i << ". " << (*it)->PobierzNazwePrzychodni() << endl;
	}
}

void interfejs::WypiszLekrzy() const
{
	int i = 0;
	cout << "Nr \tNazwisko\tspec\tliczba pacjentow" << endl;

	for (auto it = _lekarze.begin(); it != _lekarze.end(); ++it, ++i)
	{
		cout << std::setiosflags(std::ios::left);
		cout << std::setw(3);
		cout << i; 
		cout << std::setw(30) << it->second->WypiszPodstawoweDaneLekarza() << "  " << it->second->QueueSize() << endl;
	}
}

void interfejs::WypiszPacjentow() const
{
	int i = 0;
	cout << std::setiosflags(std::ios::left);
	cout << std::setw(3);
	cout << "Nr";
	cout << std::setw(15);
	cout << "Nazwisko";
	cout << std::setw(15);
	cout << "Pesel" << endl;

	for (auto it = _pacjenci.begin(); it != _pacjenci.end(); ++it, ++i)
	{
		cout << std::setw(3);
		cout << i;
		cout << std::setw(45) << it->second->PobierzPodstawoweDanePacjenta() << endl;
	}
}

void interfejs::DodawanieDoBazy()
{
	WyswietlDodawanie();

	char z;
	cin >> z;

	switch (z)
	{
		case'1':
			DodajPacjenta();
			break;
		case'2':
			DodajLekarza();
			break;
		case'3':
			DodajPrzychodnie();
			break;
		case'4':
			DodajSpecDoPrzychodni();
			break;
		case'0':
			koniec = true;
		case'9':
			break;
		default:
			cout << "Podano zly indeks powrot do Menu." << endl;
			break;
	}
}

void interfejs::ZarzadzaniePacjentami() 
{
	WyswietlZarzadzanie();
	
	char z;
	cin >> z;

	switch(z)
	{
		case'1':
			ZapiszPacjenta();
			break;
		case'2':
			WizytaPacjenta();
			break;
		case'0':
			koniec = true;
		case'9':
			break;
		default:
			cout << "Podano zly indeks powrot do Menu." << endl;
			break;
	}
}

void interfejs::UsuwanieZBazy()
{
	WyswietlUsuwanie();

	char z;
	cin >> z;

	switch (z) {
		case'1':
			UsunPacjenta();
			break;
		case'2':
			UsunLekarza();
			break;
		case'3':
			UsunPrzychodnie();
			break;
		case'0':
			koniec = true;
		case'9':
			break;
		default:
			cout << "Podano zly indeks powrot do Menu." << endl;
			break;
	}
}

void interfejs::SzczegoloweInformacje()
{
	WyswietlSzczegolowe();

	char z;
	cin >> z;

	switch(z)
	{
		case '1':
			WypiszSzczegolowoPacjentow();
			break;
		case '2':
			WypiszSzczegolowoLekarzy();
			break;
		case '3':
			WypiszSzczegolowoPrzychodnie();
			break;
		case '0':
			koniec = true;
		case '9':
			break;
		default:
			cout << "Podano zly indeks powrot do Menu." << endl;
			break;
	}
}

void interfejs::ZnajdzPrzychodnieOSpecjalnosci(const std::string& specjalnosc)
{
	vector<std::shared_ptr<przychodnia>> temp;

	//przeszukaj liste przychodni w celu znalezienia danej specjalnosci
	for (auto it = _lista_przychodni.begin(); it != _lista_przychodni.end(); ++it)
	{
		//jezeli dana specjalnosc jest obslugiwana przez przychodnie dodaj przychodnie do vectora
		if((*it)->PrzychodniaDanejSpecjalnosci(specjalnosc))
		{
			temp.push_back(*it);
		}
	}

	//nie ma przychodni obslugujacych podana specjalnosc
	if (temp.size() == 0)
	{
		cout << "Niestety nie ma przychodni o specjalnosci: " << specjalnosc << endl;
		cout << "Zalecamy poczekac na zwolnienie sie miejsca." << endl;
		return;
	}

	//sa przychodnie obslugujace podana specjalnosc

	cout << "Przychodnie w ktorych mozna znalezc lekarzy o specjalnosci " << specjalnosc << ":" << endl;

	for (int i = 0; i < temp.size(); ++i)
	{
		cout << temp[i]->PobierzNazwePrzychodni() << endl;
	}

}

shared_ptr<pacjent> interfejs::PobierzDanePacjenta(int id_pacjenta)
{
	//przeszukaj multimape pacjentow w celu znalezienia go
	for (auto it = _pacjenci.begin(); it != _pacjenci.end(); ++it)
	{
		//jezeli go znajdziemy wracamy go
		if((*it).second->PobierzId() == id_pacjenta)
		{
			return it->second;
		}
	}

	cout << "Nie ma takiego w bazie." << endl;
	shared_ptr<pacjent>temp(new pacjent);
	return temp;
}

std::shared_ptr<pacjent> interfejs::ZnajdzOdpowiadajaceNazwiskaPacjent(const std::string& nazwisko)
{
	//jezeli w multimapie znajduje sie tylko 1 takie nazwisko to zwracamy tego pacjenta
	if (_pacjenci.count(nazwisko) == 1)
	{
		return _pacjenci.find(nazwisko)->second;
	}

	vector<shared_ptr<pacjent>> temp;
	
	//w multimapie szukamy rekordow ktore maja takie samo nazwisko i wpisujemy do vectora
	auto ret = _pacjenci.equal_range(nazwisko);

	for( auto it = ret.first ; it !=ret.second;++it)
	{
		temp.push_back(it->second);
	}
	
	//jezeli nie bylo osob o takim nazwisku to zwracamy pustego pacjenta
	if(temp.size() == 0)
	{
		cout << "Brak takiego pacjenta" << endl;
		shared_ptr<pacjent> brak(new pacjent());
		return brak;
	}

	//wypisujemy osoby ktore maja podane nazwisko i wybieramy
	for(int i =0 ; i<temp.size();++i)
	{
		cout << i << ".\t" << temp[i]->PobierzPodstawoweDanePacjenta() << endl;
	}

	cout << "Wybierz odpowiedniego pacjenta: ";

	int wybor = PobierzWybor(0, temp.size());

	return temp[wybor];

}

std::multimap<std::string, std::shared_ptr<lekarzLista>>::iterator interfejs::ZnajdzInnegoLekarza(const std::string& specjalizacja)
{
	vector<std::multimap<std::string, std::shared_ptr<lekarzLista>>::iterator> temp;

	//szukamy lekarza ktory ma ta sama specjalizacje i posiada miejsce do przyjecia osob
	for (auto it = _lekarze.begin(); it != _lekarze.end(); ++it)
	{
		if (it->second->PobierzSpecjalizacje() == specjalizacja && it->second->QueueSize() != it->second->MaksymalnaIloscPacjentow())
		{
			temp.push_back(it);
		}
	}

	//nie ma lekarzy o podanej specjalnosci
	if (temp.size() == 0)
	{
		return _lekarze.end();
	}

	//jest jeden lekarz o podanej specjalnosci
	if (temp.size()== 1)
	{
		return temp[0];
	}

	//przy wiekszej ilosci wypisujemy ich i wybieramy
	for(int i =0;i<temp.size();++i)
	{
		cout << i << ".\t" << temp[i]->second->WypiszPodstawoweDaneLekarza() << endl;
	}

	cout << "Wybierz lekarza: ";
	int wybor = PobierzWybor(0, temp.size());

	return temp[wybor];
}

void interfejs::Program(int argc, char** argv)
{
	if(!PobierzParametry(argc,argv))
	{
		cout << "Blad na etapie wczytywania parametrow" << endl;
		return;
	}

	WczytajZPlikow();

	while(!koniec)
	{
		WyswietlMenu();
		char z;
		cin >> z;
		switch (z)
		{
			case '1':
				DodawanieDoBazy();
				break;
			case '2':
				UsuwanieZBazy();
				break;
			case '3':
				ZarzadzaniePacjentami();
				break;
			case '4':
				SzczegoloweInformacje();
				break;
			case '0':
				koniec = true;
				break;
			default:
				cout << "Zle sprobuj jeszcze raz" << endl;
				break;
		}
	}
	ZapiszPliki();
}

void interfejs::DodajPacjenta()
{
	shared_ptr<pacjent> temp(new pacjent);

	temp->ZapytanieInformacje();

	pair<string, shared_ptr<pacjent>> para(temp->PobierzNazwisko(), temp);

	_pacjenci.insert(para);
}

void interfejs::DodajLekarza()
{
	shared_ptr<lekarzLista> temp(new lekarzLista);

	temp->ZapytanieInforamcje();

	pair<string, shared_ptr<lekarzLista>> para(temp->PobierzNazwiskoLekarza(), temp);

	_lekarze.insert(para);
}

void interfejs::DodajPrzychodnie()
{
	shared_ptr<przychodnia> temp(new przychodnia);

	temp->ZapytanieInformacje();

	_lista_przychodni.push_front(temp);

	++_ilosc_przychodni;
}

void interfejs::DodajSpecDoPrzychodni()
{
	WypiszPrzychodnie();

	cout << "Wybierz do ktorej przychodni chcesz dodac specjalizacje: ";

	int wybor = PobierzWybor(0, _ilosc_przychodni);
	
	auto it = _lista_przychodni.begin();

	for (int i = 0; i < wybor; ++i, ++it) {}

	(*it)->DodajSpecjalizacje();
}

void interfejs::ZapiszPacjenta()
{
	cout << "Podaj nazwisko pacjenta: ";
	string nazwisko_pacjenta;
	cin >> nazwisko_pacjenta;

	//szukamy pacjenta o podanym nazwisku
	shared_ptr<pacjent> wybrany_pacjent = ZnajdzOdpowiadajaceNazwiskaPacjent(nazwisko_pacjenta);

	//jezeli takiego nie ma to wyjdz z metody
	if (wybrany_pacjent->PobierzId() == -1)
	{
		return;
	}

	//wypisujemy i wybieramy lekarza
	cout << "Do jakiego lekarza: " << endl;
	WypiszLekrzy();

	int wybor = PobierzWybor(0, _lekarze.size());

	auto it = _lekarze.begin();
	for (int i = 0; i < wybor; ++i, ++it) {}

	//jezei wybrany lekarz ma za duzo osob to szukamy innego w przeciwnym wypadku wpisujemy do tego lekarza
	if (it->second->QueueSize() == it->second->MaksymalnaIloscPacjentow())
	{
		cout << "Niestety ten lekarz ma za duzo osob." << endl;

		auto znaleziony_lekarz = ZnajdzInnegoLekarza(it->second->PobierzSpecjalizacje());

		//jezeli jest lekarz o podanej specjalizacji to pytamy sie czy chcemy do niego zapisac 
		//jesli tak to zapisujemy i wychodzimy z funkcji w przeciwnym wypadku wypisujemy przychodnie obslugujace podobne specjalizacje
		if (znaleziony_lekarz != _lekarze.end())
		{
			cout << "Czy mozemy zapisac do: " << znaleziony_lekarz->second->WypiszPodstawoweDaneLekarza() << " t/n: ";
			char z;
			cin >> z;
			if (z == 't')
			{
				cout << znaleziony_lekarz->second->WpiszPacjenta(wybrany_pacjent) << endl;
				return;
			}
		}

		ZnajdzPrzychodnieOSpecjalnosci(it->second->PobierzSpecjalizacje());
		
	}
	else
	{
		cout << it->second->WpiszPacjenta(wybrany_pacjent) << endl;
	}

}

void interfejs::WizytaPacjenta()
{
	//wypisujemy liste lekarzy i pytamy u ktorego byla wizyta
	WypiszLekrzy();

	cout << "Wybierz ktorego lekarza u ktorego odbyla sie wizyta: ";

	int wybor = PobierzWybor(0, _lekarze.size());

	auto it = _lekarze.begin();

	for (int i = 0; i < wybor; ++i, ++it) {}

	if (it->second->QueueSize() != 0)
	{
		//upewniamy sie czy to byla ta osoba jesli tak to usuwamy ja z kolejki jestli nie to jej nie przetwarzamy;
		int id_pacjenta = (*it).second->OstatniPacjent();

		shared_ptr<pacjent> temp = PobierzDanePacjenta(id_pacjenta);

		cout << "Czy to byla osoba: " << temp->PobierzPodstawoweDanePacjenta() << " t/n: ";

		char z;
		cin >> z;

		if (z == 't')
		{
			(*it).second->UsunOstatniegoPacjentaZListy();
			cout << "Przetworzono." << endl;
		}
		else
		{
			cout << "Nie przetworzono." << endl;
		}
	}
	else
	{
		cout << "Ten lekarz nie mial zapisanych pacjentow!" << endl;
	}

	cout << "Powrot do Menu." << endl;
}

void interfejs::UsunLekarza()
{
	cout << "Usuwanie lekarza." << endl;

	WypiszLekrzy();
	
	cout << "Wybierz ktorego lekarza chcesz usunac z bazy: ";
	int wybor = PobierzWybor(0, _lekarze.size());

	auto it = _lekarze.begin();

	for (int i = 0; i < wybor; ++i, ++it) {}

	_lekarze.erase(it);

}

void interfejs::UsunPacjenta()
{
	cout << "Usuwanie pacjenta." << endl;

	WypiszPacjentow();

	cout << "Wybierz pacjenta ktorego chcesz usunac z bazy: ";
	int wybor = PobierzWybor(0, _pacjenci.size());

	auto it = _pacjenci.begin();

	for (int i = 0; i < wybor; ++i, ++it) {}

	_pacjenci.erase(it);

}

void interfejs::UsunPrzychodnie()
{
	cout << "Usuwanie przychodni." << endl;

	WypiszPrzychodnie();

	cout << "Wybierz przychodnie ktora chcesz usunac z bazy: ";
	int wybor = PobierzWybor(0, _ilosc_przychodni);

	auto it = _lista_przychodni.begin();

	for (int i = 0; i < wybor; ++i, ++it) {}

	_lista_przychodni.remove(*it);

	--_ilosc_przychodni;
}

void interfejs::WypiszSzczegolowoPacjentow() const
{
	cout << endl;
	for(auto it=_pacjenci.begin();it!= _pacjenci.end();++it)
	{
		(*it).second->WypiszSzczegoloweInformacjePacjenta();
	}
	cout << endl;
}

void interfejs::WypiszSzczegolowoLekarzy() const
{
	cout << endl;
	for (auto it = _lekarze.begin(); it != _lekarze.end(); ++it)
	{
		(*it).second->WypiszSzczegoloweInformacjeLekarza();
	}
	cout << endl;
}

void interfejs::WypiszSzczegolowoPrzychodnie() const
{
	cout << endl;
	for (auto it = _lista_przychodni.begin(); it != _lista_przychodni.end(); ++it)
	{
		(*it)->WypiszSzczegoloweInformacjePrzychodnia();
		cout << endl;
	}
	cout << endl;
}

void interfejs::WczytajPacjentow()
{
	ifstream plik;
	plik.open(_plik_pacjenci);

	while (plik.good())
	{
		string informacje;
		getline(plik, informacje);

		if(informacje == "")
		{
			continue;
		}

		shared_ptr<pacjent> temp(new pacjent);

		temp->WczytajDanePacjenta(informacje);

		pair<string, shared_ptr<pacjent>> para_do_dodania(temp->PobierzNazwisko(), temp);

		_pacjenci.insert(para_do_dodania);
	}
	plik.close();
}

void interfejs::WczytajListeLekarzy()
{
	ifstream plik;
	plik.open(_plik_lekarze);

	while(plik.good())
	{
		string informacje;
		getline(plik, informacje);

		if (informacje == "")
		{
			continue;
		}

		shared_ptr<lekarzLista> temp(new lekarzLista);

		temp->WczytajDoLekarzaZLista(informacje);

		pair<string, shared_ptr<lekarzLista>> para_do_dodania(temp->PobierzNazwiskoLekarza(), temp);

		_lekarze.insert(para_do_dodania);
	}
	plik.close();
}

void interfejs::WczytajPrzychodnie()
{
	ifstream plik;
	plik.open(_plik_przychodnie);

	while (plik.good())
	{
		string informacje;
		getline(plik, informacje);

		if (informacje == "")
		{
			continue;
		}

		shared_ptr<przychodnia> temp(new przychodnia);

		temp->WczytajInformacjePrzychodni(informacje);

		_lista_przychodni.push_front(temp);

		++_ilosc_przychodni;
	}
	plik.close();
}

void interfejs::WczytajZPlikow()
{
	WczytajPacjentow();
	WczytajListeLekarzy();
	WczytajPrzychodnie();
}

void interfejs::ZapiszPliki()
{
	ZapiszPacjentow();
	ZapiszListeLekarzy();
	ZapiszPrzychodnie();
}

void interfejs::ZapiszPacjentow()
{
	ofstream plik;
	plik.open(_plik_pacjenci, ios_base::trunc);

	for (auto it = _pacjenci.begin(); it != _pacjenci.end(); ++it)
	{
		(*it).second->ZapiszPacjentaDoPliku(plik);
	}

	plik.close();
}

void interfejs::ZapiszListeLekarzy()
{
	ofstream plik;
	plik.open(_plik_lekarze, ios_base::trunc);

	for (auto it = _lekarze.begin(); it != _lekarze.end(); ++it)
	{
		(*it).second->ZapiszLekarzListaDoPliku(plik);
	}
	plik.close();
}

void interfejs::ZapiszPrzychodnie()
{
	ofstream plik;
	plik.open(_plik_przychodnie, ios_base::trunc);

	for (auto it = _lista_przychodni.begin(); it != _lista_przychodni.end(); ++it)
	{
		(*it)->ZapiszPrzychodnieDoPliku(plik);
	}
	plik.close();
}

bool interfejs::PobierzParametry(int argc, char** argv)
{
	if (argc < 7 && static_cast<string>(argv[1]) != "-h")
	{
		cout << "Podano za malo parametrow" << endl;
		Pomoc();
		return false;
	}
	if (static_cast<string>(argv[1]) == "-h")
	{
		Pomoc();
		return false;
	}
	for (int i = 1; i < argc; ++i)
	{
		if(static_cast<string>(argv[i])=="-l")
		{
			_plik_lekarze = argv[++i];
			continue;
		}
		if (static_cast<string>(argv[i]) == "-o")
		{
			_plik_pacjenci = argv[++i];
			continue;
		}
		if (static_cast<string>(argv[i]) == "-p")
		{
			_plik_przychodnie = argv[++i];
			continue;
		}
		else
		{
			cout << "Nie ma takiego przelacznika" << endl;
			Pomoc();
			return false;
		}
	}

	return true;
}

void interfejs::Pomoc()
{
	cout << "Program implementujacy baze danych wykorzystywana w przychodni." << endl;
	cout << "Program uruchamiany z linii polecen z wykorzystaniem nastepujacych przelacznikow:" << endl;
	cout << " -o\tplik z danymi osobowymi pacjentow" << endl;
	cout << "-l\tplik z danymi dotyczacymi lekarzy" << endl;
	cout << "-p\tplik z danymi dotyczacymi przychodni" << endl;
	cout << "-h\twyswietlana pomoc" << endl;
}
