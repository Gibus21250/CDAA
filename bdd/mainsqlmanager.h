#ifndef MAINSQLMANAGER_H
#define MAINSQLMANAGER_H

#include <QtSql/QSqlDatabase>

#include "primitives/gestioncontact.h"

///Classe gérant la manipulation de base de donnée SQlite
class MainSQLManager
{

private:

    ///Le gestionnaire est connecté à la base de donnée ?
    bool isConnected;
    ///Instance de QSqlDatabase qui gère la connexion vers une base de donnée
    QSqlDatabase db;

public:

    ///Constructeur par défaut
    MainSQLManager();

    /**
     * @brief Permet d'ouvrir une connexion vers base de donnée
     * @param pathFichier Chemin du fichier .sqlite
     * @return True si succès, false sinon
     * @pre pathFichier non nul et est une chemin vers un fichier .sqlite
     */
    bool connectTo(const std::string& pathFichier);

    /**
     * @brief Vérifie le schéma de la base de donnée chargée
     * @return true si le schéma est compatible, false sinon
     *
     * La base de donnée doit comporter 3 tables:<br>
     * Contact(<u>IdC</u>, nom, prenom, entreprise, email, tel, dateCreation, dateModification, photo)<br>
     * Interaction(<u>IdI</u>, Contenu, date, <em>IdC</em>)<br>
     * Tache(<u>IdT</u>, Contenu, dateAFaire, <em>IdI</em>)
     */
    bool verifierSchema() const;

    ///@brief Renvoie si la base de donnée est opérationnelle
    bool getIsConnected() const;

    /**
     * @brief Charge les données de la base de donnée dans l'instance pointée vers GestionContact
     * @param gt Pointeur vers une instance de GestionContact
     * @pre gt non nul (et de préférence vide)
     */
    void chargerBaseDeDonnee(GestionContact* gt) const;

    /**
     * @brief Inscrit le Contact pointé dans la base de donnée
     * @param contact Pointeur vers une instance de Contact
     * @return True si l'insertion a été faite avec succès, false sinon
     */
    bool ajouterContact(Contact* contact) const;

    /**
     * @brief Supprime l'inscription du Contact de a base de donnée associé à l'ID
     * @param IdC ID du contact
     * @return True si la suppression a été faite avec succès, false sinon
     */
    bool supprimerContact(const int IdC) const;

    /**
     * @brief Met à jour l'insription du Contact dans la base de donnée avec les valeurs de l'instance pointée
     * @param contact Pointeur vers une instance de Contact
     * @return True si la mise a jouer a été faite avec succès, false sinon
     */
    bool modifierContact(const Contact* contact) const;

    ///Renvoie le nombre de contact inscrit dans base de donnée
    int getNombreContact() const;

    ///Renvoie le prochain ID que la base de donnée associera à la prochaine inscription d'un nouveau Contact
    int getProchainIdC() const;

    /**
     * @brief Inscrit l'Interaction pointée dans la base de donnée
     * @param IdC Id du contact
     * @param inter Pointeur vers une instance d'Interaction
     * @return True si l'insertion a été faite avec succès, false sinon
     */
    bool ajouterInteraction(const int IdC, Interaction* inter) const;

    /**
     * @brief Supprime l'inscription de l'Interaction de a base de donnée associé à l'ID
     * @param IdC ID de l'Interaction
     * @return True si la suppression a été faite avec succès, false sinon
     */
    bool supprimerInteraction(const int IdC) const;

    /**
     * @brief Met à jour l'insription de l'Interaction dans la base de donnée avec les valeurs de l'instance pointée
     * @param inter Pointeur vers une instance d'Interaction
     * @return True si la mise a jouer a été faite avec succès, false sinon
     */
    bool modifierInteraction(const Interaction* inter) const;

    ///Renvoie le nombre d'Interaction dans la base de donnée
    int getNombreInteraction() const;

    /**
     * @brief Inscrit la Tache pointée dans la base de donnée
     * @param IdI Id de l'interaction
     * @param tache Pointeur vers une instance de Tache
     * @return True si l'insertion a été faite avec succès, false sinon
     */
    bool ajouterTache(const int IdI, Tache* tache) const;

    /**
     * @brief Supprime l'inscription de la Tache de a base de donnée associé à l'ID
     * @param IdT ID de la Tache
     * @return True si la suppression a été faite avec succès, false sinon
     */
    bool supprimerTache(const int IdT) const;

    /**
     * @brief Supprime toutes les instance de Tache associées à l'Interaction définit par son ID
     * @param IdI ID de l'Interaction
     */
    void supprimerToutTache(const int IdI) const;

    /**
     * @brief Met à jour l'insription de la Tache dans la base de donnée avec les valeurs de l'instance pointée
     * @param tache Pointeur vers une instance de Tache
     * @return True si la mise a jouer a été faite avec succès, false sinon
     */
    bool modifierTache(const Tache* tache) const;

    ///Renvoie le nombre de Tache dans la base de donnée
    int getNombreTache() const;
};

#endif // MAINSQLMANAGER_H
