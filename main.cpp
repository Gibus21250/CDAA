#include <iostream>
#include <string>
#include <list>

#include <QApplication>

#include "primitives/contact.h"
#include "primitives/gestioncontact.h"

#include "interfaces/accueil.h"
#include "interfaces/contactwidget.h"

#include "interfaces/creationcontact.h"

int main(int argc, char *argv[])
{

    Contact marie("Mortier", "Marie", "none", "m.m@gmail.com", "01234567", "none");
    GestionContact gt;
    gt.ajouterElement(marie);
    gt.ajouterElement(Contact("Jacquinet", "Nathan", "none", "j.n@gmail.com", "76543210", "none"));


    QApplication app(argc, argv);


    Accueil acc;
    acc.setGt(&gt);
    acc.show();



    return app.exec();
}
