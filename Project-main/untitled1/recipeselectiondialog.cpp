#include "recipeselectiondialog.h"
#include "ui_recipeselectiondialog.h"
#include <recipe.h>
#include <ingredients.h>
#include <QStandardPaths>
#include <QListWidgetItem>
#include <QScreen>


RecipeSelectionDialog::RecipeSelectionDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::RecipeSelectionDialog)
{
    ui->setupUi(this);
    move(screen()->geometry().center() - frameGeometry().center());// Center the window on the screen

    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QPixmap pix(desktop_path+"/görsel.jpg");
    ui->label_2->setPixmap(pix.scaled(819,700,Qt::KeepAspectRatio));   //Placing the photo in interface.
}

RecipeSelectionDialog::~RecipeSelectionDialog()
{
    delete ui;
}


//Set the list of recipes in the RecipeSelectionDialog's list widget.
void RecipeSelectionDialog::setRecipeList(const QStringList &recipeNames)
{
    ui->listWidget->addItems(recipeNames);
}

void RecipeSelectionDialog::on_listWidget_itemSelectionChanged()
{
    QListWidgetItem *selectedItem = ui->listWidget->currentItem(); //Taking the selected item on listWidget object.

    qDebug()<<selectedItem->text();

    QString selectedRecipeName = selectedItem->text(); //Taking the text of the selectedItem which is the recipe name.
    emit recipeSelected(selectedRecipeName);

    //Read the content of the selected recipe file and display it.
    Recipe recipe;
    recipe.readFile(selectedRecipeName + ".txt");
    ui->textEdit->setText(recipe.toString()); //Showing the recipe.txt file on textEdit object.
}
