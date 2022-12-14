#include "mainsqlmanager.h"
#include "qvariant.h"
#include <QDebug>

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

bool MainSQLManager::connectTo(const std::string &pathFichier)
{

    //Améliorer reset connection DB
    db = QSqlDatabase::database();

    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);

    if(db.isOpen()) db.close();
    if(db.isValid()) db.close();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(pathFichier));

    isConnected = db.open();

    //On active ce paramètre pour que les delete on cascade se déclanche
    QSqlQuery query("PRAGMA foreign_keys = ON;");
    query.exec();

    return isConnected;

}

bool MainSQLManager::getIsConnected() const
{
    return isConnected;
}

void MainSQLManager::chargerBaseDeDonnee(GestionContact *gt) const
{
    if(isConnected)
    {

        QSqlQuery qContact("SELECT * FROM Contact");
        qContact.exec();
        int cmp = 0;

        while(qContact.next())
        {
            Contact c(
                        qContact.value(0).toUInt(),                         //IdC
                        qContact.value(1).toString().toStdString(),         //Nom
                        qContact.value(2).toString().toStdString(),         //Prenom
                        qContact.value(3).toString().toStdString(),         //entreprise
                        qContact.value(4).toString().toStdString(),         //email
                        qContact.value(5).toString().toStdString(),         //tel
                        qContact.value(8).toString().toStdString());        //photo
            c.setDateCreation(DateSimple(qContact.value(6).toString().toStdString()));
            c.setDateDerniereModification(DateSimple(qContact.value(7).toString().toStdString()));

            gt->ajouterElement(c);

            Contact* p_c = &gt->getElement(cmp);

            QSqlQuery qInte;
            qInte.prepare("SELECT * FROM Interaction WHERE IdC = :id");
            qInte.bindValue(":id", c.getIdC());

            qInte.exec();

            int cmpI = 0;

            while(qInte.next())
            {
                Interaction I(qInte.value(0).toUInt(),
                              qInte.value(1).toString().toStdString(),
                              DateSimple(qInte.value(2).toString().toStdString())
                            );

                p_c->ajoutInteraction(I);

                Interaction* p_I = &p_c->interactions().getElement(cmpI);

                QSqlQuery qTache;
                qTache.prepare("SELECT * FROM Tache WHERE IdI = :id");
                qTache.bindValue(":id", I.IdI());

                qTache.exec();

                while(qTache.next())
                {
                    Tache tache(qTache.value(0).toUInt(),
                                qTache.value(1).toString().toStdString(),
                                qTache.value(2).toString().toStdString());

                    p_I->ajouterTache(tache);
                }

                ++cmpI;

            }

            ++cmp;
        }

    }
}

bool MainSQLManager::ajouterContact(Contact *contact) const
{
    if(isConnected)
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
    }

    return false;

}

bool MainSQLManager::supprimerContact(const int IdC) const
{
    if(isConnected)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM Contact WHERE IdC = :id");
        query.bindValue(":id", IdC);

        return query.exec();
    }

    return false;
}

bool MainSQLManager::modifierContact(const Contact* contact) const
{
    if(isConnected)
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

    return false;

}

int MainSQLManager::getNombreContact() const
{
    if(isConnected)
    {
        QSqlQuery query("SELECT count(IdC) FROM Contact;");

        return query.value(0).toInt();
    }
    return -1;
}

bool MainSQLManager::ajouterInteraction(const int IdC, Interaction *inter) const
{
    if(isConnected)
    {
        int IdI = -1;
        QSqlQuery query2("SELECT max(IdI) FROM Interaction;");

        if(query2.next())
        {
            IdI = query2.value(0).toInt();
        }

        if(IdI != -1)
        {

            inter->setIdI(IdI+1);

            QSqlQuery query;
            query.prepare("INSERT INTO Interaction VALUES (NULL, :c, :date, :idc)");

            query.bindValue(":c", QString::fromStdString(inter->getContenu()));
            query.bindValue(":date", QString::fromStdString(inter->getDate().getDateStrFormatBDD()));
            query.bindValue(":idc", IdC);

            return query.exec();
        }
    }

    return false;
}

bool MainSQLManager::supprimerInteraction(const int IdI) const
{
    if(isConnected)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM Interaction WHERE IdI = :id");
        query.bindValue(":id", IdI);

        return query.exec();
    }
    return false;

}

bool MainSQLManager::modifierInteraction(const Interaction *inter) const
{
    if(isConnected)
    {
        QSqlQuery query;
        query.prepare("UPDATE Interaction SET Contenu = :c, date = :date WHERE IdI = :id");
        query.bindValue(":id", inter->IdI());

        query.bindValue(":c", QString::fromStdString(inter->getContenu()));
        query.bindValue(":date", QString::fromStdString(inter->getDate().getDateStrFormatBDD()));

        return query.exec();
    }
    return false;

}

int MainSQLManager::getNombreInteraction() const
{
    if(isConnected)
    {
        QSqlQuery query("SELECT count(IdI) FROM Interaction;");

        return query.value(0).toInt();
    }
    return -1;
}

bool MainSQLManager::ajouterTache(const int IdI, Tache *tache) const
{
    if(isConnected)
    {
        int IdT = -1;
        QSqlQuery query2("SELECT max(IdT) FROM Tache;");

        if(query2.next())
        {
            IdT = query2.value(0).toInt();
        }

        if(IdT != -1)
        {

            tache->setIdT(IdT+1);

            QSqlQuery query;
            query.prepare("INSERT INTO Tache VALUES (NULL, :c, :date, :idi)");

            query.bindValue(":c", QString::fromStdString(tache->getContenu()));
            query.bindValue(":date", QString::fromStdString(tache->getDate().getDateStrFormatBDD()));
            query.bindValue(":idi", IdI);

            return query.exec();
        }
    }

    return false;
}

bool MainSQLManager::supprimerTache(const int IdT) const
{
    if(isConnected)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM Tache WHERE IdT = :id");
        query.bindValue(":id", IdT);

        return query.exec();
    }
    return false;
}

bool MainSQLManager::modifierTache(const Tache *tache) const
{
    if(isConnected)
    {
        QSqlQuery query;
        query.prepare("UPDATE Tache SET Contenu = :c, dateAFaire = :date WHERE IdT = :id");
        query.bindValue(":id", tache->IdT());

        query.bindValue(":c", QString::fromStdString(tache->getContenu()));
        query.bindValue(":date", QString::fromStdString(tache->getDate().getDateStrFormatBDD()));

        return query.exec();
    }
    return false;

}

int MainSQLManager::getNombreTache() const
{
    if(isConnected)
    {
        QSqlQuery query("SELECT count(IdT) FROM Tache;");

        return query.value(0).toInt();
    }
    return -1;
}

void MainSQLManager::supprimerToutTache(const int IdI) const
{
    if(isConnected)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM Tache WHERE IdI = :id");
        query.bindValue(":id", IdI);

        query.exec();
    }
}

bool MainSQLManager::verifierSchema() const
{
    return true;
}

