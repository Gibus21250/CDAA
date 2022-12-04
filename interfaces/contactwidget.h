#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QWidget>

#include "primitives/contact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class ContactWidget;
}
QT_END_NAMESPACE


class ContactWidget : public QWidget
{
    Q_OBJECT

private:
    Contact contact;
    Ui::ContactWidget* ui;

public:
    explicit ContactWidget(QWidget *parent = nullptr, const Contact& cont = Contact());
    ~ContactWidget();


    const Contact &getContact() const;

signals:

};

#endif // CONTACTWIDGET_H
