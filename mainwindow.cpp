#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SaveButton_clicked(){

    QString contact_name = ui->NamelineEdit->text();
    QString contact_phone = ui->PhonelineEdit->text();
    QString contact_gender;
    int contact_age = ui->AgespinBox->value();

    if(!(ui->GMaleButton->isChecked()) && !(ui->GFemaleButton->isChecked())){
        contact_gender = "Not especified";
    }

    if(ui->GMaleButton->isChecked()){
        contact_gender = "Male";
    }


    if(ui->GFemaleButton->isChecked()){
        contact_gender = "Female";
    }




    ui->PrinterLabel->setText(contact_name);

    qInfo() << "------------------------------";
    qInfo() << "Hello" << contact_name;
    qInfo() << "Gender: " << contact_gender;
    qInfo() << "Age: " << contact_age;
    qInfo() << "Phone number: " << contact_phone;
    qInfo() << "------------------------------" << "\n";

}

void MainWindow::on_actionExit_Alt_F4_triggered()
{
    QApplication::quit();
}

