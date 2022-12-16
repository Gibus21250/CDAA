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
 * @brief Classe permettant l'affichage d'une fenêtre de recherche
 */
class WindowRecherche : public QDialog
{
    Q_OBJECT

private:
    ///Pointeur vers l'UI
    Ui::WindowRecherche* ui;

    ///Pointeur vers une instance de GestionContact
    const GestionContact* m_p_gt;

    /**
     * @brief Permet d'actualiser les colonnes du tableau en fonction de la donnée à afficher
     */
    void setupColonne();

    /**
     * @brief Permet de remplir les données choisis dans le tableau
     */
    void setupDonnee();

    /**
     * @brief Permet de déclancher une procédure de filtrage de donnée
     */
    void filtrerParDate();

public:
    explicit WindowRecherche(QWidget *parent = nullptr, const GestionContact* = nullptr);

signals:

private slots:
    /**
     * @brief Réceptionne le clique de la checkbox trier, et active ou non le tri par colonne du tableau
     * @param checked
     */
    void on_check_trier_toggled(bool checked);

    /**
     * @brief Permet de réactualiser le contenu du tableau
     */
    void reactualiserTable();

    /**
     * @brief Receptionne le click du bouton fermer, et ferme la fenêtre
     */
    void on_pb_fermer_clicked();
};

#endif // WINDOWRECHERCHE_H
