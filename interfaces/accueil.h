#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include<QListWidget>
#include <QLabel>

#include "primitives/gestioncontact.h"
#include "bdd/mainsqlmanager.h"
#include "bdd/jsonexporteur.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Accueil;
}
QT_END_NAMESPACE

/**
 * @brief Classe gérant la fenêtre principale de l'application
 */
class Accueil : public QMainWindow
{
    Q_OBJECT

private:
    ///UI de l'accueil
    Ui::Accueil* ui;
    ///Instance de Gestionnaire de Contact
    GestionContact gt;

    ///Label de la bar status et sa varible
    QLabel *l_nbContact, *l_nbContactActuel;
    int nbVisible;

    ///Chemin du fichier BDD
    QString BDDLocation;

    /**
     * @brief Manager de base de donnée, qui s'occupe de mettre à jour, de charger des donner et de charger une nouvelle
     * Base de donnée tout en vérifiant les schémas
     */
    MainSQLManager manager;

    /**
     * @brief Instance de l'exporteur de donnée en format JSON alègé (sans ID, les liens entre eux sont dans les objets)
     */
    JsonExporteur je;

    /**
     * @brief Rénitialise la list de widget de contact, et la reremplie
     */
    void resetList();

    /**
     * @brief Réaffiche tous les items de la liste qui ont été caché (dû aux filtres)
     */
    void reafficherListe();
    /**
     * @brief Déclanche une procédure de filtre par rapport au nom, prénom ou entreprise
     */
    void filtrerListe();
    /**
     * @brief Déclanche une procédure de filtre par date
     */
    void filtrerListeParDate();

    /**
     * @brief Actualise les infos dans la status bar
     */
    void actualiserStatusBar();

public:

    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

private slots:
    /**
     * @brief Déclanche une suppression de contact du gestionnaire de Contact (en O(1) pour trouver la cible)
     */
    void supprimerContact();

    /**
     * @brief Déclanche l'ouverture de la fenêtre de création d'un contact
     */
    void ouvrirCreationContact();
    /**
     * @brief Ajoute une copie (dû au push_back de la list) du contact en argument
     * @param c Contact fraichemment créé
     */
    void ajouterContact(Contact& c);
    /**
     * @brief Ouvre la fenêtre d'information du contact (double clique sur item de la liste)
     */
    void ouvrirInfoContact(QListWidgetItem*);
    /**
     * Fermeture de l'application lors du clique sur le bouton Quitter de la barre d'action
     */
    void on_actionQuitter_triggered();
    /**
     * Ouverture d'un FileDialog de l'application lors du clique sur le bouton Ouvrir -> BDD de la barre d'action
     * pour aller chercher (ou non) un nouveau fichier BDD
     */
    void on_actionOuvrirBDD_triggered();

    /**
     * @brief Slot permettant d'ensuite déclancher les filtres par nom, prenom, entreprise
     * @param checked si le bouton est coché ou pas
     */
    void onFiltreActive(bool checked);

    /**
     * @brief Permet de récéptionner le signal lors de la modification dans un TextEdit:
     * cela permet une annimation fluide de recherche en temps réel
     */
    void onValueTEChanged();

    /**
     * @brief Slot permettant d'ensuite déclancher les filtres par date
     * @param checked si le bouton est coché ou pas
     */
    void onFiltreDateActive(bool checked);
    /**
     * @brief Lors du changement de valeur des DateEdit
     * Pour permettre une actualisation en temps réel
     */
    void onDateEditChange();


    /**
     * @brief Slot recepteur du clique sur l'action Général dans la barre d'action
     */
    void on_actionGenerale_triggered();

    /**
     * @brief Slot recepteur du clique sur l'action expoter > JSON
     */
    void on_actionJSON_triggered();

    /**
     * @brief Slot recepteur du clique sur l'action Actualiser (peu utile)
     */
    void on_action_actualiser_triggered();
};

#endif // ACCUEIL_H
