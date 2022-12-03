#include <iostream>
#include <string>
#include <list>

#include <QApplication>

#include "primitives/contact.h"
#include "primitives/gestioncontact.h"

#include "interfaces/accueil.h"
#include "interfaces/contactwidget.h"

int main(int argc, char *argv[])
{

    GestionContact gt;
    gt.ajouterElement(Contact("Mortier", "Marie", "none", "m.m@gmail.com", "01234567", "none"));
    gt.ajouterElement(Contact("Jacquinet", "Nathan", "none", "j.n@gmail.com", "76543210", "none"));

    QApplication app(argc, argv);

    Accueil acc;
    acc.setGt(gt);
    acc.show();

    return app.exec();
}
