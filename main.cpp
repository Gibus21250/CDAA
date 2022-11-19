#include <iostream>
#include <string>
#include <list>

#include "primitives/contact.h"
#include "primitives/interaction.h"
#include "primitives/dateSimple.h"
#include "primitives/tache.h"
#include "primitives/gestioncontact.h"

void testCreationContact();
void testCreationTache();
void testCreationInteractionSansTache();
void testCreationInteractionAvecTache();
void testContactAvecInteraction();
void testGestionContact();


int main()
{

     Tache t;
     std::cout << t << std::endl;

   /*
    testCreationContact();
    testCreationTache();
    testCreationInteractionSansTache();
    testCreationInteractionAvecTache();
    testContactAvecInteraction();
    testGestionContact();
    */

    return 0;
}

void testCreationContact()
{
    std::cout << "/--------------------------DEBUT--------------------------\\" << std::endl;
    std::cout << "Test de la creation d'un contact, et de son affichage:" << std::endl;
    std::cout << "Contact simple sans interactions:" << std::endl << std::endl;
    Contact c1("Nathan", "Jacquinet", "none", "n.j@gmail.com", "0614024807", "none");
    std::cout << c1 << std::endl;
    std::cout << "\\---------------------------Fin---------------------------/" << std::endl;
}

void testCreationTache()
{
    std::cout << "/--------------------------DEBUT--------------------------\\" << std::endl;
    std::cout << "Test de creation d'une Tâche, avec et sans date, et de leurs affichage" << std::endl;
    std::cout << "Tache sans date predefinie:" << std::endl << std::endl;
    Tache t("Menage du garage");
    std::cout << t << std::endl;
    std::cout << "Tache avec date predefinie:" << std::endl << std::endl;
    Tache t2("Envoyer rapport", "28/10/2022");
    std::cout << t2 << std::endl;
    std::cout << "\\---------------------------Fin---------------------------/" << std::endl;
}

void testCreationInteractionSansTache()
{
    std::cout << "/--------------------------DEBUT--------------------------\\" << std::endl;
    std::cout << "Test de création d'une interaction, sans taches" << std::endl;

    std::cout << "Interaction simple sans taches ni date prédéfinie:" << std::endl << std::endl;
    Interaction i("Rendre Jalon numero 1");
    std::cout << i << std::endl << std::endl;
    std::cout << "Interaction simple pour le 24/07/2022 sans taches:" << std::endl << std::endl;
    Interaction i1("Anniversaire Marie", "24/07/2022");
    std::cout << i1 << std::endl << std::endl;
    std::cout << "\\---------------------------Fin---------------------------/" << std::endl;
}

void testCreationInteractionAvecTache()
{
    std::cout << "/--------------------------DEBUT--------------------------\\" << std::endl;
    std::cout << "Test de création d'une interaction, avec taches" << std::endl;
    std::cout << "Interaction simple pour le 24/07/2022 avec taches: (Cadeau, et emballer cadeau avec date)" << std::endl << std::endl;
    Interaction i2("Anniversaire Marie", "24/07/2022");
    Tache cadeau("Ne pas oublier le cadeau");
    Tache preparer("Emballer cadeau", "23/07/2022");
    i2.ajouterTache(cadeau);
    i2.ajouterTache(preparer);
    std::cout << i2;
    std::cout << "\\---------------------------Fin---------------------------/" << std::endl;
}

void testContactAvecInteraction()
{
    std::cout << "/--------------------------DEBUT--------------------------\\" << std::endl;
    std::cout << "Test de création d'un contact, avec interactions (des tests d'avant)" << std::endl << std::endl;
    Contact c("Nathan", "Jacquinet", "none", "n.j@gmail.com", "0614024807", "none");

    Interaction i("Anniversaire Marie", "24/07/2022"), i2("Faire les courses", "30/10/2022");

    Tache cadeau("Ne pas oublier le cadeau");
    Tache preparer("Emballer cadeau", "23/07/2022");
    i.ajouterTache(cadeau);
    i.ajouterTache(preparer);

    c.ajoutInteraction(i);
    c.ajoutInteraction(i2);

    std::cout << c << std::endl;
    std::cout << "\\---------------------------Fin---------------------------/" << std::endl << std::endl;
}
void testGestionContact()
{
    std::cout << "/--------------------------DEBUT--------------------------\\" << std::endl;
    std::cout << "Test de création d'un gestionnaire de contacts, avec \"garniture\" des classe, puis affichage" << std::endl;
    GestionContact gc;

    Contact n("Nathan", "Jacquinet", "none", "n.j@gmail.com", "0614024807", "none");
    Contact m("Marie", "Mortier", "none", "m.m@gmail.com", "0748021406", "none");

    n.ajoutInteraction(Interaction("Finir rapport", "28/10/2022"));
    n.ajoutInteraction(Interaction("Prendre le train", "29/10/2022"));

    Interaction iM("Preparer voyage", "31/10/2022");

    iM.ajouterTache(Tache("Descendre la valise du grenier"));
    iM.ajouterTache(Tache("Sortir la voiture du garage le soir", "30/10/2022"));

    m.ajoutInteraction(iM);

    gc.ajoutContact(n);
    gc.ajoutContact(m);

    std::cout << gc;
    std::cout << "\\---------------------------Fin---------------------------/" << std::endl;
}
