#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QWidget>

#include "primitives/contact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class ContactWidget;
}
QT_END_NAMESPACE

/**
 * @brief The ContactWidget classe premet de générer un petit widget indicatif sur les infos du contact passé en argument
 *
 */
class ContactWidget : public QWidget
{
    Q_OBJECT

private:
    ///Pointeur vers une instance de contact
    Contact* contact;
    ///Pointeur vers une instance de l'UI
    Ui::ContactWidget* ui;

public:
    /**
     * @brief Constructeur standard
     * @param parent Parent du widget
     * @param cont Pointeur vers une instance de Contact
     */
    explicit ContactWidget(QWidget *parent = nullptr, Contact* cont = nullptr);
    ~ContactWidget();

    /**
     * @brief Actualiser le contenu du widget
     */
    void actualiserAffichage();


    /**
     * @brief Retourne le pointeur du contact associé au widget
     * @return
     */
    Contact* getContact() const;

signals:

};

#endif // CONTACTWIDGET_H
