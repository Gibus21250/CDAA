#ifndef WINDOWRECHERCHE_H
#define WINDOWRECHERCHE_H

#include <QDialog>

#include "primitives/gestioncontact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class WindowRecherche;
}
QT_END_NAMESPACE

class WindowRecherche : public QDialog
{
    Q_OBJECT

private:

    Ui::WindowRecherche* ui;

    const GestionContact* m_p_gt;

    void setupColonne();

    void setupDonnee();

    void filtrerParDate();

public:
    explicit WindowRecherche(QWidget *parent = nullptr, const GestionContact* = nullptr);

signals:

private slots:
    void on_check_trier_toggled(bool checked);

    void reactualiserTable();
    void on_pb_fermer_clicked();
};

#endif // WINDOWRECHERCHE_H
