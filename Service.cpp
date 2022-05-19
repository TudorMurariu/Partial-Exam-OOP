#include "Service.h"


vector<device> Service::getList()
{
	// returnam lista
	return repo.getList();
}

string Service::cauta(string text)
{
	/// cautam un text dat
	return repo.cauta(text);
}

vector<device> Service::filtrare_model(string model)
{
	// filtram dupa un model dat
	return repo.filtrare_model(model);
}

vector<device> Service::filtrare_an(int an)
{
	// filtram dupa un an dat
	return repo.filtrare_an(an);
}