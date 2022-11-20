#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include "tache.h"
#include "gestionnaire.h"
#include <list>

class GestionTache : public Gestionnaire<Tache>
{
public:
    /**
     * @brief Constructeur par défaut,
     */
    GestionTache();

    /**
     * @brief Permet de récupérer toutes les tâches contenant le mot 'mot'
     * @param mot à tester
     * @return Un nouveau Gestionnaire de tache
     */
    GestionTache& getTacheContenant(const std::string& mot) const;


};

#endif // GESTIONTACHE_H
