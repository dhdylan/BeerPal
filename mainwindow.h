#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateResult();
    void setWaterValue(double value);
    void setStarSanValue(double value);

private:
    Ui::MainWindow *ui;

    double waterML;
    double starsanML;
};
#endif // MAINWINDOW_H
