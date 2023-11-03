#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , waterUnit(Unit::Milliliter)
    , starSanUnit(Unit::Milliliter)
{
    ui->setupUi(this);

    connect(ui->WaterVol, &QDoubleSpinBox::valueChanged, this, &MainWindow::onWaterValueChanged);
    connect(ui->WaterUnitMilliliter, &QAbstractButton::pressed, this, &MainWindow::onWaterUnitMilliliter);
    connect(ui->WaterUnitOz, &QAbstractButton::pressed, this, &MainWindow::onWaterUnitOunce);
    connect(ui->WaterUnitLiter, &QAbstractButton::pressed, this, &MainWindow::onWaterUnitLiter);
    connect(ui->WaterUnitGallons, &QAbstractButton::pressed, this, &MainWindow::onWaterUnitGallon);
    connect(ui->StarSanUnitMilliliter, &QAbstractButton::pressed, this, &MainWindow::onStarSanUnitMilliliter);
    connect(ui->StarSanUnitOz, &QAbstractButton::pressed, this, &MainWindow::onStarSanUnitOunce);
    ui->WaterUnitMilliliter->setChecked(true);
    ui->StarSanUnitMilliliter->setChecked(true);
}

void MainWindow::updateResult()
{
    double starsanToWaterRatio = (double)1/(double)640;
    starsanML = waterML * starsanToWaterRatio;

    if(starSanUnit == Unit::Milliliter)
    {
        setStarSanValue(starsanML);
    }
    else if(starSanUnit == Unit::Ounce)
    {
        setStarSanValue(UnitConversion::MilliliterToOunce(starsanML));
    }

    std::cout<<starsanML<<std::endl;
}

void MainWindow::onWaterValueChanged(double newValue)
{
    switch (waterUnit)
    {
        case Unit::Milliliter:
            waterML = newValue;
            break;
        case Unit::Liter:
            waterML = UnitConversion::LiterToMilliliter(newValue);
            break;
        case Unit::Ounce:
            waterML = UnitConversion::OunceToMilliliter(newValue);
            break;
        case Unit::Gallon:
            waterML = UnitConversion::GallonToMilliliter(newValue);
            break;
    };
    updateResult();
}

void MainWindow::onWaterUnitMilliliter()
{
    waterUnit = Unit::Milliliter;
    updateWaterUnit(Unit::Milliliter);
}

void MainWindow::onWaterUnitOunce()
{
    waterUnit = Unit::Ounce;
    updateWaterUnit(Unit::Ounce);
}

void MainWindow::onWaterUnitLiter()
{
    waterUnit = Unit::Liter;
    updateWaterUnit(Unit::Liter);
}

void MainWindow::onWaterUnitGallon()
{
    waterUnit = Unit::Gallon;
    updateWaterUnit(Unit::Gallon);
}

void MainWindow::onStarSanUnitMilliliter()
{
    starSanUnit = Unit::Milliliter;
    updateResult();
}

void MainWindow::onStarSanUnitOunce()
{
    starSanUnit = Unit::Ounce;
    updateResult();
}

void MainWindow::updateWaterUnit(Unit newUnit)
{
    switch(newUnit)
    {
        case Unit::Milliliter:  ui->WaterVol->setValue(waterML); break;
        case Unit::Liter:       ui->WaterVol->setValue(UnitConversion::MilliliterToLiter(waterML)); break;
        case Unit::Ounce:       ui->WaterVol->setValue(UnitConversion::MilliliterToOunce(waterML)); break;
        case Unit::Gallon:      ui->WaterVol->setValue(UnitConversion::MilliliterToGallon(waterML)); break;
    }
}

void MainWindow::updateStarSanUnit(Unit newUnit)
{
    if(newUnit == Unit::Milliliter)
    {
        ui->StarSanVol->setText(QString::number(starsanML));
    }
    else if(newUnit == Unit::Ounce)
    {
        ui->StarSanVol->setText(QString::number(UnitConversion::MilliliterToOunce(starsanML)));
    }
    else
    {
        throw std::runtime_error("StarSan unit is being set to something unsupported.");
    }
}

void MainWindow::setStarSanValue(double value)
{
    ui->StarSanVol->setText(QString::number(value));
}

void MainWindow::setWaterValue(double value)
{
    ui->WaterVol->setValue(value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

