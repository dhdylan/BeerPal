#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include "unitconversion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void onWaterUnitMilliliter();
    void onWaterUnitOunce();
    void onWaterUnitLiter();
    void onWaterUnitGallon();
    void onStarSanUnitMilliliter();
    void onStarSanUnitOunce();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateResult();
    void onWaterValueChanged(double newValue);

private:
    Ui::MainWindow *ui;

    Unit waterUnit;
    Unit starSanUnit;

    double waterML;
    double starsanML;

    void updateWaterUnit(Unit newUnit);
    void updateStarSanUnit(Unit newUnit);
    void setStarSanValue(double value);
    void setWaterValue(double);
};
#endif // MAINWINDOW_H
