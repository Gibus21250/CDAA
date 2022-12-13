#include <iostream>
#include <string>
#include <list>

#include <QApplication>

#include "primitives/contact.h"
#include "primitives/gestioncontact.h"

#include "interfaces/accueil.h"

#include "primitives/dateSimple.h"

int main(int argc, char *argv[])
{
    //qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));
    /*
    Contact marie(1, "Mortier", "Marie", "Etudiante", "marie.mortier@gmail.com", "0615874920", "");
    Interaction iM(1, "Continuer SR", "07/12/2022"), i2M(2, "Faire dodo");
    Tache tm1(1, "Charger PC"), tm2(2, "Compiler avec makefile", "08/12/2022");

    iM.ajouterTache(tm1);
    iM.ajouterTache(tm2);

    marie.ajoutInteraction(iM);
    marie.ajoutInteraction(i2M);

    GestionContact gt;
    gt.ajouterElement(marie);
    gt.ajouterElement(Contact(2, "Jacquinet", "Nathan", "none", "j.n@gmail.com", "76543210", ""));

    */

    QApplication app(argc, argv);

    Accueil acc;
    acc.show();

    return app.exec();
}
