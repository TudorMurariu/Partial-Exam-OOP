#include "Service.h"


vector<device> Service::getList()
{
	return repo.getList();
}

string Service::cauta(string text)
{
	return repo.cauta(text);
}

vector<device> Service::filtrare_model(string model)
{
	return repo.filtrare_model(model);
}

vector<device> Service::filtrare_an(int an)
{
	return repo.filtrare_an(an);
}