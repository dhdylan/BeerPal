#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->WaterVol, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateResult);
}

void MainWindow::updateResult()
{
    double starsanToWaterRatio = (double)1/(double)640;
    double starsanAmt = ui->WaterVol->value() * starsanToWaterRatio;
    ui->StarSanVol->setText(QString::number(starsanAmt, 'g', 6));
}

void MainWindow::setWaterValue(double value)
{

}

void MainWindow::setStarSanValue(double value)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

