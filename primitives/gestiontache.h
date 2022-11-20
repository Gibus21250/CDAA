#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include "tache.h"
#include <list>

class GestionTache
{
private:
    std::list<Tache> m_lTache;

public:
    /**
     * @brief Constructeur par défaut,
     */
    GestionTache();

    /**
     * @brief Ajouter une tache à la liste des taches
     * @param in
     */
    void ajoutTache(const Tache& in);

    /**
     * @brief Supprimer la première tache correspondant à la tache mit en argument
     * @param in
     */
    bool supprimerTache(const Tache& in);

    bool supprimerTache(const unsigned indice);

    /**
     * @brief Renvoie le nombre de taches contenu dans le gestionnaire
     */
    unsigned getNombreTache() const;

    /**
     * @brief Supprime toute les tâche du gestionnaire
     */
    void effacerTouteTache();

    /**
     * @brief Permet de récupérer la tache à l'indice 'indice' du gestionnaire
     * @param indice
     * @return La tache correspondant à l'indice 'indice'
     */
    std::pair<Tache, bool> getTache(const unsigned indice) const;

    /**
     * @brief Remplace l'instance de la tache à l'indice précisé, par celle mit en argument
     * @param La nouvelle instance
     * @param Indice de l'instance à remplacer
     * @return true ou false, si le remplacement a abouti
     */
    bool remplacer(const Tache& tache, const unsigned indice);

    /**
     * @brief Permet de récupérer toutes les tâches contenant le mot 'mot'
     * @param mot à tester
     * @return Un nouveau Gestionnaire de tache
     */
    GestionTache& getTacheContenant(const std::string& mot) const;

    friend std::ostream& operator<<(std::ostream& out, const GestionTache& c);
};

#endif // GESTIONTACHE_H
