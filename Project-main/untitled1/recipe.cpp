#include "recipe.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>

Recipe::Recipe() {}

QString Recipe::toString() const {
    return "Name: " + name + "\nIngredients:\n" + ingredients + "\n\nInstructions:\n " + instructions;
}

//Reading a recipe file.
void Recipe::readFile(const QString& file_name) {
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString file_path = desktop_path + "/food/"+ file_name;

    //Create a QFile object to handle the recipe file.
    QFile file(file_path);

    //Check if the file can be opened.
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        if(stream.readLineInto(&firstLine)){
            if (stream.readLineInto(&name)) { //Reading the recipe name from the file.

                if (stream.readLineInto(&ingredients)) { //Reading the list of ingredients

                    while (!stream.atEnd()) { //Reading the instructions line by line and append them to the instructions string.
                    QString line = stream.readLine();
                    instructions += line + '\n';
                    }
                }
            }
        }
        file.close();
    } else {
        qDebug() << file_name << "file cannot be found."; //Error message if the file cannot be opened.
    }
}
