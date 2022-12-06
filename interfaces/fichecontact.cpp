#include "fichecontact.h"

#include "ui_ficheContact.h"

FicheContact::FicheContact(QWidget *parent)
    : QDialog{parent}, ui(new Ui::FicheContact())
{
    ui->setupUi(this);
}
FicheContact::~FicheContact()
{
    delete ui;
}
