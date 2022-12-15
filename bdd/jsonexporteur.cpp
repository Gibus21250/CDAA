#include "jsonexporteur.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

JsonExporteur::JsonExporteur(const GestionContact* p_gt)
    : m_p_gt(p_gt) {}

bool JsonExporteur::exporterJSONVers(const QString& path)
{
    QJsonDocument document;

    QJsonObject gestionContact;

    for(int i = 0; i < m_p_gt->getNombreElements(); i++)
    {
        gestionContact.insert(QString::number(i), creerContactDepuis(&m_p_gt->getElement(i)));
    }

    document.setObject(gestionContact);

    QByteArray bytes = document.toJson(QJsonDocument::Indented);
    QFile file(path);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        QTextStream tStream(&file);
        tStream.setCodec("utf-8");
        tStream << bytes;
        file.close();
        return true;
    }
    else
    {
        std::cout << "Erreur lors de l'écriture du fichier JSON" << std::endl;
        return false;
    }
}

QJsonObject JsonExporteur::creerTacheDepuis(const Tache *p_tache)
{
    QJsonObject tacheJson;
    tacheJson.insert("contenu", QString::fromStdString(p_tache->getContenu()));
    tacheJson.insert("date", QString::fromStdString(p_tache->getDate().getDateStrFormat()));
    return tacheJson;
}

QJsonObject JsonExporteur::creerInteractionDepuis(const Interaction *p_inte)
{
    QJsonObject interactionJson;
    interactionJson.insert("contenu", QString::fromStdString(p_inte->getContenu()));
    interactionJson.insert("date", QString::fromStdString(p_inte->getContenu()));
    QJsonObject listeTache;

    for(int i = 0; i < p_inte->getNombreTache(); i++)
    {
        listeTache.insert(QString::number(i), creerTacheDepuis(&p_inte->taches().getElement(i)));
    }

    interactionJson.insert("taches", listeTache);

    return interactionJson;
}

QJsonObject JsonExporteur::creerContactDepuis(const Contact *p_contact)
{
    QJsonObject contactJson;
    contactJson.insert("nom", QString::fromStdString(p_contact->getNom()));
    contactJson.insert("prenom", QString::fromStdString(p_contact->getPrenom()));
    contactJson.insert("entreprise", QString::fromStdString(p_contact->getEntreprise()));
    contactJson.insert("mail", QString::fromStdString(p_contact->getMail()));
    contactJson.insert("telephone", QString::fromStdString(p_contact->getTelephone()));
    contactJson.insert("photo", QString::fromStdString(p_contact->getPhoto()));
    contactJson.insert("dateCreation", QString::fromStdString(p_contact->getDateCreation().getDateStrFormat()));
    contactJson.insert("dateModification", QString::fromStdString(p_contact->getDateModification().getDateStrFormat()));

    QJsonObject interactionsJson;

    for(int i = 0; i < p_contact->getNombreInteraction(); i++)
    {
        interactionsJson.insert(QString::number(i), creerInteractionDepuis(&p_contact->interactions().getElement(i)));
    }

    contactJson.insert("interactions", interactionsJson);

    return contactJson;

}
