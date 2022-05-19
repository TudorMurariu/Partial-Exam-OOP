#include "Partial.h"
#include <QtWidgets/QApplication>
#include "UI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Repo repo("input.txt");
    Service srv(repo);
    gui ui(srv);

    ui.buid_ui();
    ui.conect_signals();
    ui.show();

    return a.exec();
}
