#include <iostream>
#include <string>

#include "primitives/contact.h"
#include "primitives/interaction.h"
#include "primitives/dateSimple.h"
#include "primitives/tache.h"

int main()
{
    Contact c1("Nathan", "Jacquinet", "none", "n.j@gmail.com", "0614024807", "null");
    Interaction i1("Faire le ménage");
    std::cout << c1 << std::endl;
    std::cout << i1 << std::endl;

    DateSimple d1, d2("28/10/2022");

    std::cout << d1.getDateStrFormat() << std::endl;

    std::cout << DateSimple::getDifferenceDays(d1, d2) << std::endl;

    Tache t1("Donner à manger aux poissons", d1);

    //std::cout << t1 << std::endl;

    i1.getLTache().push_back(t1);

    std::cout << i1 << std::endl;

    return 0;
    //TODO voir pk les list ne se remplissent pas!
}
