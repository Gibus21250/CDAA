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
    Contact* contact;
    Ui::ContactWidget* ui;

public:
    /**
     * @brief Prend en argument un pointeur du contact
     * @param parent
     */
    explicit ContactWidget(QWidget *parent = nullptr, Contact* = nullptr);
    ~ContactWidget();


    Contact* getContact() const;

signals:

};

#endif // CONTACTWIDGET_H
