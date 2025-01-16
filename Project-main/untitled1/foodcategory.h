#ifndef FOODCATEGORY_H
#define FOODCATEGORY_H

#include <QObject>
#include <QString>
#include <QVector>

class FoodCategory : public QObject {
    Q_OBJECT

public:
    explicit FoodCategory(QObject *parent = nullptr);
    QVector<QString> loadRecipesFromFile(const QString &dosya_yolu);
    void initializeRecipes(const QString &categoryPath);
    void addRecipeName(const QString &recipeName);
    QVector<QPair<QString, QVector<QString>>> recipes;

protected:
    QVector<QString> recipeNames;
};

class Soup : public FoodCategory {
    Q_OBJECT

public:
    Soup(QObject *parent = nullptr);
};

class Salad : public FoodCategory {
    Q_OBJECT

public:
    Salad(QObject *parent = nullptr);
};

class Dessert : public FoodCategory {
    Q_OBJECT

public:
    Dessert(QObject *parent = nullptr);
};

class Snack : public FoodCategory {
    Q_OBJECT

public:
    Snack(QObject *parent = nullptr);
};

class MainCourse : public FoodCategory {
    Q_OBJECT

public:
    MainCourse(QObject *parent = nullptr);
};

#endif // FOODCATEGORY_H
