#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>

#include "dateSimple.h"
#include "tache.h"
#include "gestiontache.h"

/**
 * @brief Classe gérant une Interaction
 */
class Interaction
{
private:

    ///ID de l'Interaction
    unsigned m_IdI;
    ///Contenu de l'Interaction
    std::string m_contenu;
    ///Instance de DateSimple associée à l'Interaction
    DateSimple m_date;
    ///Instance d'un GestionTache
    GestionTache m_taches;

public:

    ///Constructeur par défaut
    Interaction();
    /**
     * @brief Constructeur partiel initialisant la date de l'interaction à la date du jour
     * @param ID de l'Interaction
     * @param Description de l'Interaction
     */
    Interaction(const unsigned id, const std::string& desc);

    /**
     * @brief Constructeur standard de l'instance Interaction
     * @param ID de l'Interaction
     * @param Description de l'Interaction
     * @param Instance DateSimple de la date à associer à l'instance Interaction
     */
    Interaction(const unsigned id, const std::string& desc, const DateSimple& date);

    /**
     * @brief Constructeur standard de l'instance Interaction
     * @param ID de l'Interaction
     * @param Description de l'Interaction
     * @param Date sous forme de string, de syntax jj/MM/aaaa ou aaaa-MM-jj
     */
    Interaction(const unsigned id, const std::string& desc, const std::string& date);

    ///Surcharge de l'opérateur << transformant l'Interaction et l'envoyant au flux out
    friend std::ostream& operator<<(std::ostream& out, const Interaction& i);

    /**
     * @brief Renvoie la date associé à l'Interaction
     * @return DateSimple correspondant à cette date
     */
    const DateSimple& getDate() const;

    /**
     * @brief Change l'instance de la date
     * @param Nouvelle DateSimple
     */
    void setDate(const DateSimple &value);

    /**
     * @brief Renvoie le contenu
     * @return String du contenu
     */
    const std::string& getContenu() const;

    /**
     * @brief Change la valeur du contenu
     * @param valeur du contenu à modifier
     */
    void setContenu(const std::string &value);

    ///Renvoie le nombre de Tache associé à l'Interaction
    unsigned getNombreTache() const;

    /**
     * @brief Ajoute une Tache à la liste de tache
     * @param Instance de Tache
     */
    void ajouterTache(const Tache& tache);

    /**
     * @brief Retire la Tache du gestionnaire de tache associé à l'Interaction
     * @param Instance de Tache à supprimer
     */
    void retirerTache(const Tache& tache);

    /**
     * @brief Retire la Tache correspondant à l'ID
     * @param ID de la Tache
     */
    void retirerTache(const unsigned id);

    ///Compare tous les membres de l'Interaction
    bool operator==(const Interaction& in) const;

    /**
     * @brief Renvoie le gestionnaire de Tache associé à l'Interaction
     * @return GestionTache associé
     */
    const GestionTache &taches() const;

    /**
     * @brief Change le gestionnaire de Tache
     * @param Le nouveau GestionTache
     */
    void setTaches(const GestionTache &newTaches);

    /**
     * @brief Renvoie l'ID de l'Interaction
     * @return L'ID
     */
    const unsigned &IdI() const;

    /**
     * @brief Change l'ID de l'Interaction
     * @param Nouvel ID
     */
    void setIdI(const unsigned &newIdI);
};

#endif // INTERACTION_H
