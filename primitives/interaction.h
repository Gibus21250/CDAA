#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>

#include "dateSimple.h"
#include "tache.h"
#include "gestiontache.h"


class Interaction
{
private:

    DateSimple date;
    std::string contenu;
    GestionTache taches;

public:

    Interaction();
    Interaction(const std::string& desc);
    Interaction(const std::string& desc, const DateSimple& date);
    Interaction(const std::string& desc, const std::string& date);

    friend std::ostream& operator<<(std::ostream& out, const Interaction& i);

    DateSimple getDate() const;
    void setDate(const DateSimple &value);

    std::string getContenu() const;
    void setContenu(const std::string &value);

    GestionTache getTaches() const;
    void setTaches(const GestionTache &value);

    unsigned getNombreTache() const;

    void ajouterTache(const Tache& tache);
    void ajouterTache(const std::string contenu, std::string dateStr);
    void ajouterTache(const std::string contenu, DateSimple dateStr);

    void retirerTache(const Tache& tache);

    bool operator==(const Interaction& in);


};

#endif // INTERACTION_H
