#include "lekarzLista.h"

using namespace std;
 
lekarzLista::lekarzLista() {}

lekarzLista::~lekarzLista() {}

void lekarzLista::WczytajDoLekarzaZLista(const std::string & informacja)
{
	int pozycja_dwukr = informacja.find_last_of(":");

	string podstawowe_inf = informacja.substr(0, pozycja_dwukr);
	_lekarz.WczytajDaneLekarzy(podstawowe_inf);

	if(pozycja_dwukr == string::npos)
	{
		//nie ma ludzi do tego lekarza
		return;
	}

	string numery_pacjentow = informacja.substr(pozycja_dwukr + 2);

	//wczytuj numery do listy
	int pos = -1;
	int prev = 0;
	pos = numery_pacjentow.find(" ");

	while (pos != string::npos)
	{
		_numery_obslugiwanych_pacjentow.push(stoi(numery_pacjentow.substr(prev, pos - prev)));
		prev = ++pos;
		pos = numery_pacjentow.find(" ", prev);
	}

	_numery_obslugiwanych_pacjentow.push(stoi(numery_pacjentow.substr(prev)));
}

void lekarzLista::ZapytanieInforamcje()
{
	_lekarz.ZapytanieInformacje();
}

void lekarzLista::ZapiszObslugiwancyhPacjentowDoPliku(std::ofstream& plik)
{
	if (_numery_obslugiwanych_pacjentow.empty())
	{
		return;
	}

	plik << ":";
	while (!_numery_obslugiwanych_pacjentow.empty())
	{
		plik <<" "<< _numery_obslugiwanych_pacjentow.front();
		_numery_obslugiwanych_pacjentow.pop();
	}
}

void lekarzLista::ZapiszLekarzListaDoPliku(std::ofstream& plik)
{
	_lekarz.ZapiszLekarzaDoPliku(plik);
	ZapiszObslugiwancyhPacjentowDoPliku(plik);
	plik << endl;
}

void lekarzLista::WypiszSzczegoloweInformacjeLekarza() const
{
	_lekarz.WypiszSzczegoloweDane();
	cout << this->QueueSize() << endl;
}

string lekarzLista::WpiszPacjenta(const shared_ptr<pacjent>& wybrany_pacjent)
{
	_numery_obslugiwanych_pacjentow.push(wybrany_pacjent->PobierzId());
	return "Pomyslnie zapisano do: " + _lekarz.WypiszPodstawoweDane();
}
