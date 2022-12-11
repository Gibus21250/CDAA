#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>

#include "dateSimple.h"
#include "tache.h"
#include "gestiontache.h"


class Interaction
{
private:

    unsigned m_IdI;
    std::string m_contenu;
    DateSimple m_date;
    GestionTache m_taches;

public:

    Interaction();
    Interaction(const unsigned id, const std::string& desc);
    Interaction(const unsigned id, const std::string& desc, const DateSimple& date);
    Interaction(const unsigned id, const std::string& desc, const std::string& date);

    friend std::ostream& operator<<(std::ostream& out, const Interaction& i);

    /**
     * @brief getDate
     * @return la date à laquelle se passe l'interaction
     */
    const DateSimple& getDate() const;

    /**
     * @brief setDate
     * @param la valeur de la date à modifier
     */
    void setDate(const DateSimple &value);

    /**
     * @brief getContenu
     * @return Le contenu de l'interaction
     */
    const std::string& getContenu() const;

    /**
     * @brief setContenu
     * @param valeur du contenu à modifier
     */
    void setContenu(const std::string &value);

    unsigned getNombreTache() const;

    /**
     * @brief Ajoute une tache à la liste de tache
     * @param tache
     */
    void ajouterTache(const Tache& tache);
    /*
     * @brief Retire toute les taches à la liste de tache
     * @param tache
     */
    void retirerTache(const Tache& tache);

    void retirerTache(const unsigned id);

    bool operator==(const Interaction& in) const;

    const GestionTache &taches() const;
    void setTaches(const GestionTache &newTaches);
    const unsigned &IdI() const;
    void setIdI(const unsigned &newIdI);
};

#endif // INTERACTION_H
