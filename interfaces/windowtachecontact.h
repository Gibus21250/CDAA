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

class WindowTacheContact : public QDialog
{
    Q_OBJECT
private:
    Ui::WindowTacheContact* ui;

public:
    explicit WindowTacheContact(QWidget *parent = nullptr, std::list<Tache*>* p_list = nullptr, const Contact* who = nullptr
            , const QDate* apres = nullptr, const QDate* avant = nullptr, const bool filtre = false);

signals:

private slots:
    void on_pb_fermer_clicked();
};

#endif // WINDOWTACHECONTACT_H
