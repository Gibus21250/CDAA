#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include "interaction.h"
#include <list>

/**
 * @brief Classe gérant une liste d'Interaction
 */
class GestionInteraction : public Gestionnaire<Interaction>
{

public:
    ///Constructeur par défaut
    GestionInteraction();

    ///Supprime l'instance Interaction associé à l'ID en paramètre
    bool supprimerParId(const unsigned IdI);

    /**
     * @brief Permet de récupérer une instance de GestionInteraction avec dedans toutes les Interactions contenant le mot 'mot'
     * @param mot à tester
     * @return Un nouveau GestionInteraction contenant des Interactions satisfaisant la condition
     */
    GestionInteraction& getInteractionsContenant(const std::string& mot);

    /**
     * @brief Permet de récupérer une instance de GestionInteraction avec dedans toutes les Interactions se passant avant la date en agument
     * @param La date
     * @return Un nouveau GestionInteraction contenant des Interactions satisfaisant la condition
     */
    GestionInteraction& getInteractionsAvant(const DateSimple& date);

    /**
     * @brief Permet de récupérer une instance de GestionTache avec dedans toutes les Interactions se passant après la date en agument
     * @param La date
     * @return Un nouveau GestionInteraction contenant des Interactions satisfaisant la condition
     */
    GestionInteraction& getInteractionsApres(const DateSimple& date);

};

#endif // GESTIONINTERACTION_H
