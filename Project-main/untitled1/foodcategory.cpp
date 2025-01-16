#include "foodcategory.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>

FoodCategory::FoodCategory(QObject *parent) : QObject(parent) {
}

QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
QString file_path = desktop_path + "/food/";
std::vector<std::pair<std::string, std::vector<std::string>>> recipes;

//Reads recipe files and collects ingredients.
QVector<QString> FoodCategory::loadRecipesFromFile(const QString &file_path) {
    QVector<QString> ingredients;
    QFile file(file_path);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine();

        while (!line.isNull()) {
            QStringList parts = line.split(","); //Splitting the line by commas to separate ingredients.
            ingredients.append(parts); //Add ingredients to the list.
            line = in.readLine();
            break; //Read only the first line.
        }
        file.close();
    } else {
        qDebug() << file_path << "file cannot be found.";
    }

    return ingredients;
}

//Initialize recipes for a specific category by reading recipe files.
void FoodCategory::initializeRecipes(const QString &categoryPath) {
    for (const auto &recipeName : recipeNames) {
        recipes.append({recipeName, loadRecipesFromFile(categoryPath + recipeName + ".txt")});
    }
}

void FoodCategory::addRecipeName(const QString &recipeName) {
    recipeNames.append(recipeName);
}

Soup::Soup(QObject *parent) : FoodCategory(parent) {
    addRecipeName("ChickenSoup");
    addRecipeName("YaylaSoup");
    addRecipeName("BroccoliSoup");
    addRecipeName("TomatoSoup");
    addRecipeName("EzogelinSoup");
    addRecipeName("MushroomSoup");
    addRecipeName("MercimekSoup");
    addRecipeName("TarhanaSoup");
    addRecipeName("VegetableSoup");
    initializeRecipes(file_path);
}

Salad::Salad(QObject *parent) : FoodCategory(parent) {
    addRecipeName("TacoSalad");
    addRecipeName("StrawberrySalad");
    addRecipeName("GreekSalad");
    addRecipeName("GardenSalad");
    addRecipeName("CobbSalad");
    addRecipeName("CaesarSalad");
    addRecipeName("MediterraneanQuinoaSalad");
    addRecipeName("BroccoliSalad");
    initializeRecipes(file_path);
}

MainCourse::MainCourse(QObject *parent) : FoodCategory(parent) {
    addRecipeName("ZucchiniCauliflowerFritters");
    addRecipeName("TarhanaBulgurKofte");
    addRecipeName("PeaStew");
    addRecipeName("EggplantCasseroleWithOliveOil");
    addRecipeName("Casserole");
    addRecipeName("BulgurLentilPilaf");
    addRecipeName("BroccoliAndMushroomPilaf");
    addRecipeName("BakedChickenWithMushroom");
    addRecipeName("BakedCauliflowerAndEggplantDish");
    addRecipeName("Alinazik");
    initializeRecipes(file_path);
}

Snack::Snack(QObject *parent) : FoodCategory(parent) {
    addRecipeName("VegetablePancakes");
    addRecipeName("StuffedPeppers");
    addRecipeName("StuffedMeatballs");
    addRecipeName("RoastedPepperSandal");
    addRecipeName("PotatoCroquettewithCheddar");
    addRecipeName("PacangaPastry");
    addRecipeName("HunterPastry");
    addRecipeName("Falafel");
    addRecipeName("CheddarMushroom");
    initializeRecipes(file_path);
}

Dessert::Dessert(QObject *parent) : FoodCategory(parent) {
    addRecipeName("Sutlac");
    addRecipeName("Souffle");
    addRecipeName("SemolinaCake");
    addRecipeName("Pudding");
    addRecipeName("Cake");
    addRecipeName("Helva");
    addRecipeName("Cookie");
    addRecipeName("CarrotCake");
    addRecipeName("ApplePie");
    initializeRecipes(file_path);
}
