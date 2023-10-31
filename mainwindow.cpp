#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->WaterVol, &QSpinBox::valueChanged, this, &MainWindow::updateResult);

    waterVolumeButtonGroup.setExclusive(true);
    starsanVolumeButtonGroup.setExclusive(true);
    //group radio buttons
    for(int i=0; i < ui->WaterUnitSelect->children().count(); i++)
    {
        waterVolumeButtonGroup.addButton(qobject_cast<QAbstractButton*>(ui->WaterUnitSelect->children()[i]), i);
    }

    for(int i=0; i < ui->StarSanUnitSelect->children().count(); i++)
    {
        QAbstractButton* button = qobject_cast<QAbstractButton*>(ui->StarSanUnitSelect->children()[i]);
        starsanVolumeButtonGroup.addButton(button, i);

    }
}

void MainWindow::updateResult()
{
    double starsanToWaterRatio = 1/640;
    double starsanAmt = ui->WaterVol->value() * starsanToWaterRatio;
    ui->StarSanVol->setText(QString::number(starsanAmt, 'g'));
}

MainWindow::~MainWindow()
{
    delete ui;
}

