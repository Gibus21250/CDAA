#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include "tache.h"
#include <list>

class GestionTache
{
private:
    std::list<Tache> lTache;

public:
    GestionTache();
    /**
     * @brief Ajouter une tache à la liste des taches
     * @param in
     */
    void ajoutTache(const Tache in);
    /**
     * @brief Supprimer toute les taches correspondant à la tache mit en argument
     * @param in
     */
    bool supprimerTache(const Tache& in);
    /**
     * @brief Renvoie le nombre de taches
     */
    unsigned getNombreTache() const;

    friend std::ostream& operator<<(std::ostream& out, const GestionTache& c);
};

#endif // GESTIONTACHE_H
