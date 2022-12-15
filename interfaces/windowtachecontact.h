#ifndef WINDOWTACHECONTACT_H
#define WINDOWTACHECONTACT_H

#include <QDialog>
#include <QWidget>
#include <QDate>

#include "primitives/tache.h"
#include "primitives/contact.h"


QT_BEGIN_NAMESPACE
namespace Ui {
    class WindowTacheContact;
}
QT_END_NAMESPACE

/**
 * @brief Classe gérant une fenêre d'affichage de toutes les Tache d'une liste de pointeurs de Tache
 */
class WindowTacheContact : public QDialog
{
    Q_OBJECT
private:
    ///Pointeur vers une instance de WindowTacheContact
    Ui::WindowTacheContact* ui;

public:
    /**
     * @brief Constructeur standard
     * @param parent Pointeur vers le QWidget parent
     * @param p_list Pointeur vers une liste de pointeur de Tache
     * @param who Pointeur vers le Contact associé
     * @param apres Pointeur vers une QDate
     * @param avant Pointeur vers une autre QDate
     * @param filtre info si des filtres ont été utilisé pour générer la list, ou non
     */
    explicit WindowTacheContact(QWidget *parent = nullptr, std::list<Tache*>* p_list = nullptr, const Contact* who = nullptr
            , const QDate* apres = nullptr, const QDate* avant = nullptr, const bool filtre = false);

signals:

private slots:
    /**
     * @brief Slot récépteur du clique sur le bouton Fermer
     */
    void on_pb_fermer_clicked();
};

#endif // WINDOWTACHECONTACT_H
