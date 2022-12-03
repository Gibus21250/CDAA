#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>

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

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();
signals:

};

#endif // ACCUEIL_H
