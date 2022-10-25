#include <iostream>
#include <string>

#include "primitives/contact.h"
#include "primitives/interaction.h"
#include "primitives/dateSimple.h"

int main()
{
    Contact c1("Nathan", "Jacquinet", "none", "n.j@gmail.com", "0614024807", "null");
    Interaction i1("Faire le ménage");
    std::cout << c1 << std::endl;
    std::cout << i1 << std::endl;

    DateSimple d1, d2("28/10/2022");

    std::cout << d1.getDateStrFormat() << std::endl;

    std::cout << DateSimple::getDifferenceDays(d1, d2);

    return 0;
}
