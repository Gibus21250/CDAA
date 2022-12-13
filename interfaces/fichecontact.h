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

class FicheContact : public QDialog
{
    Q_OBJECT

private:
    Ui::FicheContact* ui;
    Contact* m_p_contact;
    const MainSQLManager* manager;

    DoubleClickQLabel* m_dcl[6];
    QLineEdit* m_le[5];

    DoubleClickTextEditor* dcte;

    bool modeEdition;
    char quiEstEdite;

    void changerEtatPourEdition(bool mode);
    void keyPressEvent(QKeyEvent *event);

    void actualiserContenuTextEdit();


public:
    explicit FicheContact(QWidget *parent = nullptr, Contact* p_contact = nullptr, const MainSQLManager* manager = nullptr);
    ~FicheContact();

signals:

private slots:
    void interactionChange();
    void modEditionInformation(char);
    void ajouterInteraction();
    void supprimerInteraction();

    void doubleCliqueTextEditor();


};

#endif // FICHECONTACT_H
