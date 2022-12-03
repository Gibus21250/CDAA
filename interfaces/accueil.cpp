#include "accueil.h"

#include "ui_Accueil.h"

#include "contactwidget.h"

void Accueil::setGt(const GestionContact &newGt)
{
    gt = newGt;
    for(int i = 0; i < gt.getNombreElements(); i++)
    {
        ContactWidget* cw = new ContactWidget(this, gt.getElement(i));

        auto item = new QListWidgetItem();

        item->setSizeHint(cw->sizeHint());

        ui->lw_Contact->addItem(item);
        ui->lw_Contact->setItemWidget(item, cw);

    }
}

Accueil::Accueil(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Accueil())
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Gestionnaire de Contact");
    setMinimumWidth(650);
    setMinimumHeight(700);
}

Accueil::~Accueil()
{
    delete ui;
}
