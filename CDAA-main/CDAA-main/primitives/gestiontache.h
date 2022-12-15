#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include "tache.h"
#include "gestionnaire.h"
#include <list>

/**
 * @brief Classe gérant une liste de Tache
 */
class GestionTache : public Gestionnaire<Tache>
{
public:
    /**
     * @brief Constructeur par défaut,
     */
    GestionTache();

    /**
    * @brief Supprime l'instance de Tache associé à l'ID en argument
    * @param Id id de la Tache
    * @return true si il a été trouvé et supprimé, false sinon
    */
    bool supprimerParId(const unsigned Id);

    /**
     * @brief Permet de récupérer une nouvelle instance de GestionTache avec dedans toutes les tâches contenant le mot 'mot'
     * @param mot mot à tester
     * @return Un nouveau GestionTache contenant des Tache satisfaisant la condition
     */
    GestionTache& getTachesContenant(const std::string& mot);

    /**
     * @brief Permet de récupérer une nouvelle instance de GestionTache avec dedans toutes les tâches se passant avant la date en agument
     * @param date La date
     * @return Un nouveau GestionTache contenant des Tache satisfaisant la condition
     */
    GestionTache& getTachesAvant(const DateSimple& date);

    /**
     * @brief Permet de récupérer une nouvelle instance de GestionTache avec dedans toutes les tâches se passant après la date en agument
     * @param date La date
     * @return Un nouveau GestionTache contenant des Tache satisfaisant la condition
     */
    GestionTache& getTachesApres(const DateSimple& date);


};

#endif // GESTIONTACHE_H
