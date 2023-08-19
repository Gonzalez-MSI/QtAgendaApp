#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBoxMenu->setHidden(true);
    ui->tableWidget->setHidden(true);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Age"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Phone"));
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

    QString *string_checker = new QString(contact_name.trimmed());
    if(string_checker->isEmpty()){
        contact_name = "Unnamed";
    }
    delete string_checker;

    if(!(ui->GMaleButton->isChecked()) && !(ui->GFemaleButton->isChecked())){
        contact_gender = "Not especified";
    }

    if(ui->GMaleButton->isChecked()){
        contact_gender = "Male";
    }


    if(ui->GFemaleButton->isChecked()){
        contact_gender = "Female";
    }

    qInfo() << "------------------------------";
    qInfo() << "Hello" << contact_name;
    qInfo() << "Gender: " << contact_gender;
    qInfo() << "Age: " << contact_age;
    qInfo() << "Phone number: " << contact_phone;
    qInfo() << "------------------------------" << "\n";

    member_counter += 1;
    AdjustTableSize(&member_counter);
    PopulateContactsTable(
        &member_counter,
        &contact_name,
        &contact_gender,
        &contact_age,
        &contact_phone
    );
    ui->tableWidget->setHidden(false);
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

void MainWindow::on_CancelButton_clicked()
{
    ui->groupBoxMenu->setHidden(true);
}


void MainWindow::on_actionExit_Alt_F4_triggered()
{
    QApplication::quit();
}




void MainWindow::on_AddButton_clicked()
{
    ui->tableWidget->setHidden(true);
}

