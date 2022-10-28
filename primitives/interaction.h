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

    /**
     * @brief getDate
     * @return la date à laquelle se passe l'interaction
     */
    DateSimple getDate() const;

    /**
     * @brief setDate
     * @param la valeur de la date à modifier
     */
    void setDate(const DateSimple &value);

    /**
     * @brief getContenu
     * @return Le contenu de l'interaction
     */
    std::string getContenu() const;

    /**
     * @brief setContenu
     * @param valeur du contenu à modifier
     */
    void setContenu(const std::string &value);

    GestionTache getTaches() const;
    void setTaches(const GestionTache &value);

    unsigned getNombreTache() const;

    /**
     * @brief Ajoute une tache à la liste de tache
     * @param tache
     */
    void ajouterTache(const Tache& tache);
    /**
     * @brief Ajoute une tache à la liste de tache
     * @param tache
     */
    void ajouterTache(const std::string contenu, std::string dateStr);
    /**
     * @brief Ajoute une tache à la liste de tache
     * @param tache
     */
    void ajouterTache(const std::string contenu, DateSimple dateStr);

    /**
     * @brief Retire toute les taches à la liste de tache
     * @param tache
     */
    void retirerTache(const Tache& tache);

    bool operator==(const Interaction& in);


};

#endif // INTERACTION_H
