#ifndef FICHECONTACT_H
#define FICHECONTACT_H

#include <QDialog>

#include "primitives/contact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class FicheContact;
}
QT_END_NAMESPACE

class FicheContact : public QDialog
{
    Q_OBJECT

private:
    Ui::FicheContact* ui;
    Contact* m_p_contact;

public:
    explicit FicheContact(QWidget *parent = nullptr, Contact* p_contact = nullptr);
    ~FicheContact();

signals:

};

#endif // FICHECONTACT_H
