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
    /**
     * @brief Renvoie un pair<Interaction, bool> resultant de la recherche d'interaction par correspondance du contenu dans les paramètre
     * @param contenu à trouver
     * @return l'interaction, avec un boolean, correspondant au resultat de la recherche: si le bool est false, c'est que l'interaction n'a pas été trouvée
     */
    std::pair<Interaction, bool> getInteraction(const std::string contenu);
    /**
     * @brief Renvoie un pair<Interaction, bool> resultant de la recherche d'interaction par correspondance du contenu dans les paramètre
     * @param nb
     * @return l'interaction, avec un boolean, correspondant au resultat de la recherche: si le bool est false, c'est que l'interaction n'a pas été trouvée
     */
    std::pair<Interaction, bool> getInteraction(const int nb);
    /**
     * @brief Renvoie la liste des interactions
     * @return
     */
    std::list<Interaction> getListInteraction() const;

    friend std::ostream& operator<<(std::ostream& out, const GestionInteraction& c);
};

#endif // GESTIONINTERACTION_H
