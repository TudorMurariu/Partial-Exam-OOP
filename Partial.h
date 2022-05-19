#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Partial.h"

class Partial : public QMainWindow
{
    Q_OBJECT

public:
    Partial(QWidget *parent = Q_NULLPTR);

private:
    Ui::PartialClass ui;
};
