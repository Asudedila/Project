#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingredients.h"
#include <QPixmap>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QScreen>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    move(screen()->geometry().center() - frameGeometry().center()); // Center the window on the screen

    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    
    //Placing photos in interface.
    QPixmap pix(desktop_path + "/maincourse.jpg");
    ui->label_pic->setPixmap(pix.scaled(289,289,Qt::KeepAspectRatio));

    QPixmap pix2(desktop_path + "/soup.jpg");
    ui->label_pic_2->setPixmap(pix2.scaled(289,289,Qt::KeepAspectRatio));

    QPixmap pix3(desktop_path + "/salad.jpg");
    ui->label_pic_3->setPixmap(pix3.scaled(289,289,Qt::KeepAspectRatio));

    QPixmap pix4(desktop_path + "/dessert.jpg");
    ui->label_pic_4->setPixmap(pix4.scaled(289,289,Qt::KeepAspectRatio));

    QPixmap pix5(desktop_path + "/aperatifs.jpg");
    ui->label_pic_5->setPixmap(pix5.scaled(289,289,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::ButtonType MainWindow::getLastClickedButton() const {
    return lastClickedButton;
}

void MainWindow::open_ingredients(){
    //Method for opening of ingredients.ui.
    Ingredients* ingredients = new Ingredients(this);
    ingredients->setModal(true);  
    int result = ingredients->exec();
}

//All pushButton methods have the same logic except that lastClickedButton is assigned by which method has been chosen.
void MainWindow::on_pushButton_clicked()
{
    this->close();
    lastClickedButton = Button1;
    open_ingredients(); //Opening of the ingredients.ui.
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    lastClickedButton = Button2;
    open_ingredients();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
    lastClickedButton = Button3;
    open_ingredients();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
    lastClickedButton = Button4;
    open_ingredients();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->close();
    lastClickedButton = Button5;
    open_ingredients();
}

