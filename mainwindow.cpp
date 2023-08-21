#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBoxMenu->setHidden(true);
    ui->tableWidget->setHidden(true);
    ui->ContactsCounterLabel->setText(QString::number(0));
    SetUpContactsTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SaveButton_clicked(){

    static int member_counter = 0;
    QString contact_name = ui->NamelineEdit->text();
    QString contact_phone = ui->PhonelineEdit->text();
    QString contact_gender;
    int contact_age = ui->AgespinBox->value();

    NullNameChecker(&contact_name);

    if(!(ui->GMaleButton->isChecked()) && !(ui->GFemaleButton->isChecked())){
        contact_gender = "Not especified";
    }

    if(ui->GMaleButton->isChecked()){
        contact_gender = "Male";
    }


    if(ui->GFemaleButton->isChecked()){
        contact_gender = "Female";
    }

    member_counter += 1;
    AdjustTableSize(&member_counter);
    PopulateContactsTable(
        &member_counter,
        &contact_name,
        &contact_gender,
        &contact_age,
        &contact_phone
    );

    ui->AgespinBox->setValue(0);
    ui->ContactsCounterLabel->setText(QString::number(member_counter));
    ui->tableWidget->setHidden(false);
}

void MainWindow::SetUpContactsTable(){

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Age"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Phone"));
}

void MainWindow::AdjustTableSize(int *counter){

    ui->tableWidget->setRowCount(*counter);
}

void MainWindow::PopulateContactsTable(int *counter, QString *name, QString *gender, int *age, QString *phone){

    ui->tableWidget->setItem(*counter - 1, 0, new QTableWidgetItem(*name));
    ui->tableWidget->setItem(*counter - 1, 1, new QTableWidgetItem(*gender));
    ui->tableWidget->setItem(*counter - 1, 2, new QTableWidgetItem(QString::number(*age)));
    ui->tableWidget->setItem(*counter - 1, 3, new QTableWidgetItem(*phone));
}

void MainWindow::NullNameChecker(QString *name){

    QString *string_checker = new QString((*name).trimmed());
    if(string_checker->isEmpty()){
        *name = "Unnamed";
    }
    delete string_checker;
}

void MainWindow::on_CancelButton_clicked()
{
    ui->groupBoxMenu->setHidden(true);
}

void MainWindow::on_AddButton_clicked()
{
    ui->tableWidget->setHidden(true);
}

void MainWindow::on_actionExit_Alt_F4_triggered()
{
    QApplication::quit();
}

