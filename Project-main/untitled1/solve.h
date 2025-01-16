#ifndef SOLVE_H
#define SOLVE_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <vector>
#include <unordered_set>
#include "foodcategory.h"

class Solve : public QObject {
    Q_OBJECT

public:
    Solve(QObject *parent = nullptr);
    Solve(QVector<QString> &ingredients, int categoryChoice);

    QVector<QString> getResults() const;

private:
    QVector<QString> results;

    void chooseCategory(const QVector<QString> &ingredients, int categoryChoice);
    void findMatchingRecipes(const QVector<QString> &ingredients, const QVector<QPair<QString, QVector<QString>>> &categoryRecipes);
};

#endif // SOLVE_H
