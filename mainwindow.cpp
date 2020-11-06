#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

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


void MainWindow::on_pushButton_ThucHien_clicked()
{
    if(ui->lineEdit_A->text() < "0" || ui->lineEdit_A->text() > "9" ||
            ui->lineEdit_B->text() < "0" || ui->lineEdit_B->text() > "9" ||
            ui->lineEdit_C->text() < "0" || ui->lineEdit_C->text() > "9")
             {
                ui->lineEdit_4->setText("Hay nhap vao A, B, C la so nguyen!!!");
                return;
             }
    double a = ui->lineEdit_A->text().toDouble();
    double b = ui->lineEdit_B->text().toDouble();
    double c = ui->lineEdit_C->text().toDouble();
    double max = a;

    if(max < b)
    {
        max = b;
    }

    if(max < c)
    {
        max = c;
    }

    ui->lineEdit_4->setText(QString::number(max));

}

void MainWindow::on_pushButton_TiepTuc_clicked()
{
    ui->lineEdit_A->setText("");
    ui->lineEdit_B->setText("");
    ui->lineEdit_C->setText("");
    ui->lineEdit_4->setText("");
}

void MainWindow::on_pushButton_Thoat_clicked()
{
    QMessageBox a;
    a.setWindowTitle("Close");
    a.setText("Ban co muon close khong?");
    a.setInformativeText("Nhan Yes de close");
    a.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    a.setDefaultButton(QMessageBox::No);
    a.setIcon(QMessageBox::Warning);
    int ketQua = a.exec();
    switch (ketQua) {
        case QMessageBox::Yes:
        close();
        break;
    case QMessageBox::No:
        break;
    }
}
