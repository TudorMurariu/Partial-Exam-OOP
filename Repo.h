#pragma once
#include <vector>
#include "entitati.h"
#include <fstream>
using namespace std;

class Repo {

	vector<device> lista_device;
	string fisier;

public:
	Repo(string fisier1);
	vector<device> getList();
	string cauta(string text);
	vector<device> filtrare_model(string model);
	vector<device> filtrare_an(int an);
};