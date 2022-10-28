#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include "interaction.h"

#include <list>

class GestionInteraction
{
private:
    /**
     * @brief Les interactions sont stockées dans une liste
     */
    std::list<Interaction> listInteraction;
public:
    GestionInteraction();

    /**
     * @brief Permet d'ajouter une interaction
     * @param L'interaction à ajouter
     */
    void ajoutInteraction(const Interaction in);

    /**
     * @brief Permet de supprimer une interaction
     * @param L'interaction à supprimer
     * @return un boolean
     */
    bool supprimerInteraction(const Interaction& in);

    /**
     * @brief renvoie le nombre d'interaction d'un contact
     */
    unsigned getNombreInteraction() const;
    std::pair<Interaction, bool> getInteraction(const std::string contenu);
    std::pair<Interaction, bool> getInteraction(const int nb);
    std::list<Interaction> getListInteraction() const;

    friend std::ostream& operator<<(std::ostream& out, const GestionInteraction& c);
};

#endif // GESTIONINTERACTION_H
