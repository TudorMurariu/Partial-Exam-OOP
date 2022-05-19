#include "UI.h"


void gui::buid_ui()
{
	QHBoxLayout* mainly = new QHBoxLayout;

	QWidget* left = new QWidget;
	QVBoxLayout* vl_left = new QVBoxLayout;
	left->setLayout(vl_left);

	editline = new QLineEdit;
	vl_left->addWidget(editline);

	firltrare_model = new QPushButton("dupa model");
	firltrare_an = new QPushButton("dupa an");
	refresh_btn = new QPushButton("refresh");

	vl_left->addWidget(firltrare_model);
	vl_left->addWidget(firltrare_an);
	vl_left->addWidget(refresh_btn);

	QWidget* right = new QWidget;
	QVBoxLayout* vl_right = new QVBoxLayout;
	right->setLayout(vl_right);

	lista = new QListWidget;
	vl_right->addWidget(lista);


	mainly->addWidget(left);
	mainly->addWidget(right);
	this->setLayout(mainly);
}

void gui::conect_signals()
{
	refresh(srv.getList());

	QObject::connect(lista, &QListWidget::itemClicked, [&]() {
		QListWidgetItem* item = lista->currentItem();
		editline->setText(QString::fromStdString(srv.cauta(item->text().toStdString())));
		});

	QObject::connect(firltrare_model, &QPushButton::clicked, [&]() {
		refresh(srv.filtrare_model(editline->text().toStdString()));
		});

	QObject::connect(firltrare_an, &QPushButton::clicked, [&]() {
		try {
			int an = stoi(editline->text().toStdString());
			refresh(srv.filtrare_an(an));
		}
		catch (exception e)
		{
			QMessageBox::warning(this, "eroare", "In edit line trebuie sa fie un an");
		}
		});

	QObject::connect(refresh_btn, &QPushButton::clicked, [&]() {
		refresh(srv.getList());
		});
}


void gui::refresh(vector<device> l)
{
	lista->clear();
	lista->addItem("model   culoare   pret");
	for (int i = 0; i < l.size(); i++)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(l[i].model + " " + l[i].culoare + " " + to_string(l[i].pret)));
		if (2022 - 3 < l[i].an)
		{
			if (l[i].culoare == "rosu")
			{
				QBrush brush(Qt::red);
				item->setBackground(brush);
			}
			else if (l[i].culoare == "albastru")
			{
				QBrush brush(Qt::blue);
				item->setBackground(brush);
			}
			else if (l[i].culoare == "negru")
			{
				QBrush brush(Qt::black);
				item->setBackground(brush);
			}
			else if (l[i].culoare == "galben")
			{
				QBrush brush(Qt::yellow);
				item->setBackground(brush);
			}
		}

		lista->addItem(item);
	}
}