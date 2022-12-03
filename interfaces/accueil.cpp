#include "accueil.h"

#include "ui_Accueil.h"

Accueil::Accueil(QWidget *parent) : QMainWindow(parent), ui(new Ui::Accueil())
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
