#pragma once

#include <string>
#include <iostream>
using namespace std;


class device {
public:
	string tip;
	string model;
	int an;
	string culoare;
	double pret;
	device(string tip1,string model1,int an1,string culoare1,double pret1)
	{
		tip = tip1;
		model = model1;
		an = an1;
		culoare = culoare1;
		pret = pret1;
	}
};