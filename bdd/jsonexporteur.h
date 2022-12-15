#ifndef JSONEXPORTEUR_H
#define JSONEXPORTEUR_H

#include <QJsonObject>

#include "primitives/gestioncontact.h"

/**
 * @brief Classe gérant l'exportation de donnée en format JSON
 */
class JsonExporteur
{

private:
    /**
     * @brief Génère un objet QJsonObject correspondant à l'instance de Tache pointée
     * @param Pointeur vers une instance de Tache
     * @pre p_tache non nul
     * @return L'objet QJsonObject généré
     */
    QJsonObject creerTacheDepuis(const Tache* p_tache);

    /**
     * @brief Génère un objet QJsonObject correspondant à l'instance d'Interaction pointée
     * @param Pointeur vers une instance d'Interaction
     * @pre p_inte non nul
     * @return L'objet QJsonObject généré
     */
    QJsonObject creerInteractionDepuis(const Interaction* p_inte);

    /**
     * @brief Génère un objet QJsonObject correspondant à l'instance de Contact pointée
     * @param Pointeur vers une instance de Contact
     * @pre p_contact non nul
     * @return L'objet QJsonObject généré
     */
    QJsonObject creerContactDepuis(const Contact* p_contact);

    /// Pointeur vers l'instance d'un GestionContact
    const GestionContact* m_p_gt;


public:
    /**
     * @brief Constructeur standart d'un JsonExporteur
     * @param Pointeur vers une instance de GestionContact
     * @pre p_gt non nul
     */
    JsonExporteur(const GestionContact* p_gt);

    /**
     * @brief Génère puis exporte les données de l'instance pointée par @ref m_p_gt à l'emplacement path
     * @param Chemin du fichier
     * @return True Si l'exportation a eu lieu, false sinon
     */
    bool exporterJSONVers(const QString& path);

};

#endif // JSONEXPORTEUR_H
