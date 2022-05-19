#pragma once
#include "Repo.h"

class Service {
	Repo& repo;

public:

	Service(Repo& r) : repo(r){}

	vector<device> getList();
	string cauta(string text);
	vector<device> filtrare_model(string model);
	vector<device> filtrare_an(int an);
};