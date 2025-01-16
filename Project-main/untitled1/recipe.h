#ifndef RECIPE_H
#define RECIPE_H

#include <QString>

class Recipe {
public:
    Recipe();

    QString toString() const;

    void readFile(const QString& file_name);

private:
    QString firstLine;
    QString name;
    QString instructions;
    QString ingredients;
};

#endif // RECIPE_H
