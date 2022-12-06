#ifndef CREATIONCONTACT_H
#define CREATIONCONTACT_H

#include <QDialog>

#include "primitives/contact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class CreationContact;
}
QT_END_NAMESPACE

class CreationContact : public QDialog
{
    Q_OBJECT

private:
    Ui::CreationContact* ui;
    Contact contact;
    QString uri;

public:
    explicit CreationContact(QWidget *parent = nullptr);

signals:
    void creerContact(const Contact& c);

private slots:
    void terminerCreation();
    void ouvrirDialogFichier();
    void annulerCreation();
};

#endif // CREATIONCONTACT_H
