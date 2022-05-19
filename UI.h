#pragma once
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>

#include "Service.h"
#include <exception>

class gui : public QWidget {
	Service& srv;
protected:

	QListWidget* lista;

	QLineEdit* editline;

	QPushButton* firltrare_model;
	QPushButton* firltrare_an;
	QPushButton* refresh_btn;

public:
	gui(Service& s) : srv(s){}
	void buid_ui();
	void conect_signals();
	void refresh(vector<device> l);
};