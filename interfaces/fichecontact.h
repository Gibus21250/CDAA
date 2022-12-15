#ifndef FICHECONTACT_H
#define FICHECONTACT_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

#include "doubleclickqlabel.h"
#include "doubleclicktexteditor.h"

#include "primitives/contact.h"

#include "bdd/mainsqlmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class FicheContact;
}
QT_END_NAMESPACE

/**
 * @brief Classe gérant l'affichage d'un Contact, et de la modification des données associées à lui
 */
class FicheContact : public QDialog
{
    Q_OBJECT

private:
    ///Pointeur vers l'ui FicheContact
    Ui::FicheContact* ui;
    ///Pointeur du contact
    Contact* m_p_contact;
    ///Manager de la base de donnée
    const MainSQLManager* manager;

    ///Tableau des qlabel custom qui prennent en charge le double clique
    DoubleClickQLabel* m_dcl[6];
    ///Tableau des qline edit, qui serviront à remplacer les QLabl custom lors de la phase de modification
    QLineEdit* m_le[5];

    ///pointeur d'une instance d'un textEditor integrant l'emmission lors du oduble clique
    DoubleClickTextEditor* dcte;



    ///bool mode edition activé?
    bool modeEdition;
    ///char contenant le numero de qui est edité (cf tableau double clique qlabel)
    char quiEstEdite;

    /**
     * @brief Permet de desactiver tout les widgets pour entrer en mode edition (et l'inverse)
     * @param mode true, ou false
     */
    void changerEtatPourEdition(bool mode);

    /**
     * @brief Evenement d'appuie sur les boutons: echap, ctrl+s, entrer
     * @param event touche évènement
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief Actualiser le contenu du textedit lors du changement de selection d'une interaction
     */
    void actualiserContenuTextEdit();

    /**
     * @brief reactualiser le contenu des widget de la liste d'interaction
     */
    void reafficherListe();

    /**
     * @brief Déclanche une procédure de filtre par date
     */
    void filtrerListeParDate();

public:
    explicit FicheContact(QWidget *parent = nullptr, Contact* p_contact = nullptr, const MainSQLManager* manager = nullptr);
    ~FicheContact();

signals:

private slots:

    /**
     * @brief Slot permettant d'ensuite déclancher les filtres par date
     * @param checked si la checkbox est cochée ou non
     */
    void onFiltreDateActive(bool checked);
    /**
     * @brief Lors du changement de valeur des DateEdit
     * Pour permettre une actualisation en temps réel
     */
    void onDateEditChange();

    /**
     * @brief Slot recepteur lors d'un changement de selection d'un item dans la liste de widget
     */
    void interactionChange();

    /**
     * @brief Slot récpeteur des signaux des custom QLabel
     */
    void modEditionInformation(char);

    /**
     * @brief Slot recepteur du clique de bouton ajouter interaction
     */
    void ajouterInteraction();
    /**
     * @brief Slot recepteur du clque de bouton supprimer interaction
     */
    void supprimerInteraction();

    /**
     * @brief Slot recepteur du double clique sur le custom text edit
     */
    void doubleCliqueTextEditor();

    /**
     * @brief Slot recepteur du clique sur le bouton afficher toute les tâches
     * Cela ouvre une fenetre qui affiche toute les tâches des interactions selectionnée
     */
    void on_pb_toutTache_clicked();

    /**
     * @brief Slot recepteur du clique de bouton fermer
     */
    void on_pushButton_clicked();
};

#endif // FICHECONTACT_H
