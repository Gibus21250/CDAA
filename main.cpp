#include <iostream>
#include <string>
#include <list>

#include "primitives/contact.h"
#include "primitives/interaction.h"
#include "primitives/dateSimple.h"
#include "primitives/tache.h"

void testCreationContact();

int main()
{
    testCreationContact();

    return 0;
}

void testCreationContact()
{
    std::cout << "Test de la creation d'un contact, et de son affichage:" << std::endl;
    Contact c1("Nathan", "Jacquinet", "none", "n.j@gmail.com", "0614024807", "null");
    std::cout << c1 << std::endl;
}


