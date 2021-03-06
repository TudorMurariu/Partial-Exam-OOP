#include "Repo.h"


Repo::Repo(string fisier1)
{
	// constructor
	fisier = fisier1;

	ifstream f(fisier);

	string a, b, c, d, e;

	while (f >> a >> b >> c >> d >> e)
	{
		int an = stoi(c);
		double pret = stod(e);
		device x(a, b, an, d, pret);
		lista_device.push_back(x);
	}
}

vector<device> Repo::getList()
{
	// returnam lista de device-uri
	return this->lista_device;
}

string Repo::cauta(string text)
{
	// cautam un text dat
	for (int i = 0; i < lista_device.size(); i++)
	{
		string aux = lista_device[i].model + " " + lista_device[i].culoare + " " + to_string(lista_device[i].pret);
		if (text == aux)
		{
			return lista_device[i].model + " " + to_string(lista_device[i].an);
		}
	}
	return "error";
}

vector<device> Repo::filtrare_model(string model)
{
	// filtram dupa un model dat
	vector<device> v;
	for (int i = 0; i < lista_device.size(); i++)
	{
		if (lista_device[i].model == model)
			v.push_back(lista_device[i]);
	}
	return v;
}

vector<device> Repo::filtrare_an(int an)
{
	// filtram dupa un an dat
	vector<device> v;
	for (int i = 0; i < lista_device.size(); i++)
	{
		if (lista_device[i].an == an)
			v.push_back(lista_device[i]);
	}
	return v;
}