#ifndef JSONEXPORTEUR_H
#define JSONEXPORTEUR_H

#include <QJsonObject>

#include "primitives/gestioncontact.h"

class JsonExporteur
{

private:

    QJsonObject creerTacheDepuis(const Tache* p_tache);
    QJsonObject creerInteractionDepuis(const Interaction* p_inte);
    QJsonObject creerContactDepuis(const Contact* p_contact);

    const GestionContact* m_p_gt;


public:
    JsonExporteur(const GestionContact* p_gt);

    bool exporterJSONVers(const QString& path);

};

#endif // JSONEXPORTEUR_H
