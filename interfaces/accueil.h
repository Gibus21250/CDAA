#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include<QListWidget>

#include "primitives/gestioncontact.h"
#include "bdd/mainsqlmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Accueil;
}
QT_END_NAMESPACE

class Accueil : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Accueil* ui;
    GestionContact gt;

    std::string BDDLocation;

    void actualiseList();
    MainSQLManager manager;

public:

    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

private slots:
    void supprimerContact();

    void ouvrirCreationContact();
    void ajouterContact(Contact& c);
    void ouvrirInfoContact(QListWidgetItem*);
    void on_actionQuitter_triggered();
};

#endif // ACCUEIL_H
