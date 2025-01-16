
#include "ingredients.h"
#include "ui_ingredients.h"
#include "mainwindow.h"
#include "recipe.h"
#include "solve.h"
#include <QCheckBox>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <algorithm>
#include <iterator>
#include <QStandardPaths>
#include <recipeselectiondialog.h>
#include <QPalette>
#include <QScreen>

Ingredients::Ingredients(QWidget *parent)
    : QDialog(parent), ui(new Ui::Ingredients)
{
    ui->setupUi(this);
    // Center the window on the screen
    move(screen()->geometry().center() - frameGeometry().center());
}

Ingredients::~Ingredients()
{
    delete ui;
}

//Retrieve selected ingredients from checkboxes.
QVector<QString> Ingredients::getSelectedIngredients() const
{
    QVector<QString> selectedIngredients;
    //List of checkboxes representing various ingredients.
    QList<QCheckBox*> checkboxes = { ui->checkBox_ALMOND,ui->checkBox_AVOCADO,ui->checkBox_BROCCOLI, ui->checkBox_CARROT, ui->checkBox_CAULIFLOWER,
                                     ui->checkBox_CUCUMBER, ui->checkBox_EGGPLANT,ui->checkBox_GARLIC,ui->checkBox_LEMON, ui->checkBox_LETTUCE,
                                     ui->checkBox_MUSHROOM, ui->checkBox_ONION,ui->checkBox_OLIVE,ui->checkBox_PARSLEY,
                                     ui->checkBox_PEA, ui->checkBox_PEPPER, ui->checkBox_POTATO,ui->checkBox_SPINACH,
                                     ui->checkBox_STRAWBERRY ,ui->checkBox_TOMATO,ui->checkBox_WALNUT ,ui->checkBox_ZUCCHINI,
                                     ui->checkBox_BEEF, ui->checkBox_BUTTER, ui->checkBox_CHICKEN,ui->checkBox_CHEESE,
                                     ui->checkBox_EGG, ui->checkBox_LAMB, ui->checkBox_MILK, ui->checkBox_MINCEDMEAT, ui->checkBox_PASTRAMI, ui->checkBox_YOGURT,
                                     ui->checkBox_BULGUR, ui->checkBox_CHICKPEAS, ui->checkBox_FLOUR, ui->checkBox_LENTIL,
                                     ui->checkBox_QUINOA, ui->checkBox_RICE, ui->checkBox_SEMOLINA, ui->checkBox_TARHANA,
                                     ui->checkBox_BAKINGSODA, ui->checkBox_BAKINGPOWDER,ui->checkBox_BREADCRUMB,ui->checkBox_CHOCOLATE,
                                     ui->checkBox_CINNAMON, ui->checkBox_CORNSTARCH, ui->checkBox_CROUTON, ui->checkBox_OIL,
                                     ui->checkBox_OREGANO, ui->checkBox_PHYLLODOUGH, ui->checkBox_RAISIN, ui->checkBox_SUGAR,
                                     ui->checkBox_TAHINI, ui->checkBox_TOMATOPASTE, ui->checkBox_VANILLA, ui->checkBox_VINEGAR};

    for (QCheckBox* checkbox : checkboxes) {
        if (checkbox->isChecked()) {
            //If checkBoox is checked, taking the text in it which is ingredient name and adds to selected ingredients vector.
            selectedIngredients.push_back(checkbox->text());
        }
    }

    return selectedIngredients;
}


void Ingredients::on_pushButton_clicked()
{
    //Retrieve selected ingredients and close the dialog window.
    QVector<QString> selectedIngredients = getSelectedIngredients();
    this->close();

    int count = selectedIngredients.size();

    if (count <= 3) {  //Warning message if less than 3 ingredients are selected.
        QMessageBox::warning(this, "Not Enough Ingredients", "Please choose more than 3 ingredients.");
    } else {
        for (const QString& ingredient : selectedIngredients) {
            qDebug() << "Selected Ingredient: " << ingredient;
        }
    }
    //Finding the chosen category by getting the lastClikedButton object that has been declared as enum at mainwindow.h and assigning in
    //mainwindow.cpp's pushButtonMethods.
    MainWindow::ButtonType selectedCategory = (static_cast<MainWindow*>(parent()))->getLastClickedButton();
    qDebug() << "Selected Category: " << selectedCategory;

    if(selectedIngredients.size()<=3){
        Ingredients* ingredients = new Ingredients(this);
        ingredients->setModal(true);
        int result = ingredients->exec();
    }else{
            //Solve based on selected ingredients and category.
            Solve solver(selectedIngredients, selectedCategory);
            const auto& result = solver.getResults();

            //When no recipe is found for selected category and ingredients.
            if(result.isEmpty()){
                QMessageBox::warning(this, "RECIPE NOT FOUND", "No recipe found for the selected category and ingredients.");
                this->close();
            }else{                
                for (const auto& result : solver.getResults()) {
                    Recipe recipe;
                    recipe.readFile(result + ".txt");

                    qDebug()<< recipe.toString() << "\n";
                    qDebug() << "------------------------\n";
                }
                //After finding the recipes, ingredients interface has been closed, then recipe selection dialog
                //interface has been created and displayed.
                this->close();
                RecipeSelectionDialog selectionDialog;
                selectionDialog.setRecipeList(solver.getResults());
                selectionDialog.exec();
            }
    }
    this->close();
}

