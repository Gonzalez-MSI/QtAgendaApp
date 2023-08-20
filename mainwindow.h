#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtCore>
#include <QString>

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

    void on_SaveButton_clicked();

    void on_actionExit_Alt_F4_triggered();

    void on_CancelButton_clicked();

    void on_AddButton_clicked();

    void NullNameChecker(QString*);

    void AdjustTableSize(int*);

    void PopulateContactsTable(int*, QString*, QString*, int*, QString*);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
