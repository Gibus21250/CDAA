#ifndef WINDOWRECHERCHE_H
#define WINDOWRECHERCHE_H

#include <QDialog>

#include "primitives/gestioncontact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class WindowRecherche;
}
QT_END_NAMESPACE

/**
 * @brief Classe gérant la recherche générale dans toutes les données chargée
 */
class WindowRecherche : public QDialog
{
    Q_OBJECT

private:
    ///Pointeur vers l'ui WindowRecherche
    Ui::WindowRecherche* ui;

    ///Pointeur vers une instance de GestionInteraction
    const GestionContact* m_p_gt;

    ///Actualise les colonnes du tableau suivant le type de donnée à afficher
    void setupColonne();

    ///Actualise les données dans le tableau
    void setupDonnee();

    ///Filtre par date les données du tableau
    void filtrerParDate();

public:
    /**
     * @brief Constructeur standard
     * @param parent Pointeur vers la fenêtre parent
     * @param p_gt Pointeur vers une instance de GestionContact
     */
    explicit WindowRecherche(QWidget *parent = nullptr, const GestionContact* p_gt = nullptr);

signals:

private slots:
    /**
     * @brief Slot récepteur du clique sur la checkbox Trier
     * @param checked Si la checkBox est cochée ou non
     */
    void on_check_trier_toggled(bool checked);

    /**
     * @brief Slot récépteur lors du changement de valeurs de la QDateEdit
     */
    void reactualiserTable();

    /**
     * @brief Slot récépteur du clique sur le bouton Fermer
     */
    void on_pb_fermer_clicked();
};

#endif // WINDOWRECHERCHE_H
