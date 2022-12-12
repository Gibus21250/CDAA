#include "mainsqlmanager.h"
#include "qvariant.h"
#include <QDebug>

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

bool MainSQLManager::connectTo(const std::string &pathFichier)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(pathFichier));

    isConnected = db.open();

    //On active ce paramètre pour que les delete on cascade se déclanche
    QSqlQuery query("PRAGMA foreign_keys = ON;");

    return isConnected;

}

bool MainSQLManager::getIsConnected() const
{
    return isConnected;
}

bool MainSQLManager::ajouterContact(Contact *contact) const
{
    int IdC = -1;
    QSqlQuery query2("SELECT max(IdC) FROM Contact;");

    if(query2.next())
    {
        IdC = query2.value(0).toInt();
    }

    if(IdC != -1)
    {
        contact->setIdC(IdC+1);


        QSqlQuery query(db);
        query.prepare("INSERT INTO Contact VALUES (NULL, :n, :p, :e, :m, :t, DATE('now'), DATE('now'), :u)");
        query.bindValue(":n", QString::fromStdString(contact->getNom()));
        query.bindValue(":p", QString::fromStdString(contact->getPrenom()));
        query.bindValue(":e", QString::fromStdString(contact->getEntreprise()));
        query.bindValue(":m", QString::fromStdString(contact->getMail()));
        query.bindValue(":t", QString::fromStdString(contact->getTelephone()));
        query.bindValue(":u", QString::fromStdString(contact->getPhoto()));

        return query.exec();
    }

    return false;

}

bool MainSQLManager::supprimerContact(const int IdC) const
{
    QSqlQuery query;
    query.prepare("DELETE FROM Contact WHERE IdC = :id");
    query.bindValue(":id", IdC);

    return query.exec();

}

bool MainSQLManager::modifierContact(const Contact* contact) const
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET nom = :n, prenom = :p, entreprise = :e, email = :m, tel = :t, dateModification = DATE('now'), photo = :u WHERE IdC = :id");
    query.bindValue(":id", contact->getIdC());

    query.bindValue(":n", QString::fromStdString(contact->getNom()));
    query.bindValue(":p", QString::fromStdString(contact->getPrenom()));
    query.bindValue(":e", QString::fromStdString(contact->getEntreprise()));
    query.bindValue(":m", QString::fromStdString(contact->getMail()));
    query.bindValue(":t", QString::fromStdString(contact->getTelephone()));
    query.bindValue(":u", QString::fromStdString(contact->getPhoto()));

    query.exec();

    return query.numRowsAffected() == 1;

}

bool MainSQLManager::ajouterInteraction(const int IdC, Interaction *inter) const
{

    int IdI = -1;
    QSqlQuery query2("SELECT max(IdC) FROM Contact;");

    if(query2.next())
    {
        IdI = query2.value(0).toInt();
    }

    if(IdI != -1)
    {

        inter->setIdI(IdI);

        QSqlQuery query;
        query.prepare("INSERT INTO Interaction VALUES (NULL, :c, DATE('now'), :idc)");

        query.bindValue(":c", QString::fromStdString(inter->getContenu()));
        query.bindValue(":idc", IdC);

        return query.exec();
    }

  return false;
}

bool MainSQLManager::supprimerInteraction(const int IdC) const
{
    QSqlQuery query;
    query.prepare("DELETE FROM Interaction WHERE IdI = :id");
    query.bindValue(":id", IdC);

    return query.exec();
}

bool MainSQLManager::modifierInteraction(const Interaction *inter) const
{
    QSqlQuery query;
    query.prepare("UPDATE Interaction SET "
                  "Contenu = :c,"
                  "WHERE IdI = :id");
    query.bindValue(":id", inter->IdI());

    query.bindValue(":c", QString::fromStdString(inter->getContenu()));
    query.bindValue(":id", inter->IdI());

    return query.exec();
}

bool MainSQLManager::verifierSchema() const
{
    return true;
}

