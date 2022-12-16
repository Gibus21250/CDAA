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
 * @brief Classe gérant l'affichage d'une liste de toutes les Tache d'un Contact suivant des filtres
 */
class WindowTacheContact : public QDialog
{
    Q_OBJECT
private:
    ///Pointeur vers l'UI
    Ui::WindowTacheContact* ui;

public:
    /**
     * @brief Constructeur standard
     * @param parent Pointeur vers l'instance QWidget parent
     * @param p_list Pointer vers une liste de poineur de Tache
     * @param who Pointeur vers un contact
     * @param apres Pointeur vers la date d'apres
     * @param avant Pointeur vers la date d'avant
     * @param filtre boolean si oui ou non il y a eu des filtres d'activé
     */
    explicit WindowTacheContact(QWidget *parent = nullptr, std::list<Tache*>* p_list = nullptr, const Contact* who = nullptr
            , const QDate* apres = nullptr, const QDate* avant = nullptr, const bool filtre = false);

signals:

private slots:
    /**
     * @brief Slot récépteur du clique sur e bouton fermer
     */
    void on_pb_fermer_clicked();
};

#endif // WINDOWTACHECONTACT_H
