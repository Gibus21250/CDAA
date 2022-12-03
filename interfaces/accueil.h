#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>

#include "primitives/gestioncontact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Accueil;
}
QT_END_NAMESPACE

class Accueil : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Accueil* ui;
    GestionContact gt;

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();



    void setGt(const GestionContact &newGt);
};

#endif // ACCUEIL_H
