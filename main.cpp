#include <iostream>
#include <string>
#include <list>

#include <QApplication>

#include "primitives/contact.h"
#include "primitives/gestioncontact.h"

#include "interfaces/accueil.h"

int main(int argc, char *argv[])
{

    Contact marie("Mortier", "Marie", "Etudiante", "marie.mortier@gmail.com", "0615874920", "");
    Interaction iM("Continuer SR", "07/12/2022"), i2M("Faire dodo");
    Tache tm1("Charger PC"), tm2("Compiler avec makefile", "08/12/2022");

    iM.ajouterTache(tm1);
    iM.ajouterTache(tm2);

    marie.ajoutInteraction(iM);
    marie.ajoutInteraction(i2M);

    GestionContact gt;
    gt.ajouterElement(marie);
    gt.ajouterElement(Contact("Jacquinet", "Nathan", "none", "j.n@gmail.com", "76543210", ""));


    QApplication app(argc, argv);


    Accueil acc;
    acc.setGt(&gt);
    acc.show();


    /*
    std::list<Tache> lt;
    Tache t1("Dormir");

    int cmp = 0;
    while(cmp < 100)
    {

        for(int i = 0; i < 2; i++)
        {
            lt.push_back(t1);
        }

        int whoDelete = rand()%lt.size();

        auto it = lt.begin();
        std::advance(it, whoDelete);

        lt.erase(it);


    }
    */




    return app.exec();
}
