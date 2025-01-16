#include "solve.h"
#include <QVector>
#include <QString>
#include <fstream>
#include <string>
#include <sstream>

Solve::Solve(QObject *parent) : QObject(parent) {
}

Solve::Solve(QVector<QString> &ingredients, int categoryChoice) {
    chooseCategory(ingredients, categoryChoice); //Select a category.
}

QVector<QString> Solve::getResults() const {
    return results;
}

void Solve::chooseCategory(const QVector<QString> &ingredients, int categoryChoice) {
    switch (categoryChoice) {
    case 0: {
        MainCourse mainCourse;
        findMatchingRecipes(ingredients, mainCourse.recipes);
        break;
    }
    case 1: {
        Soup soup;
        findMatchingRecipes(ingredients, soup.recipes);
        break;
    }
    case 2: {
        Salad salad;
        findMatchingRecipes(ingredients, salad.recipes);
        break;
    }
    case 3: {
        Dessert dessert;
        findMatchingRecipes(ingredients, dessert.recipes);
        break;
    }
    case 4: {
        Snack snack;
        findMatchingRecipes(ingredients, snack.recipes);
        break;
    }
    default:
        qDebug() << "Invalid category choice.\n"; //If the selected category does not match.
    }
}

void Solve::findMatchingRecipes(const QVector<QString> &ingredients, const QVector<QPair<QString, QVector<QString>>> &categoryRecipes) {
    //Function to find matching recipes.
    for (const auto& categoryRecipe : categoryRecipes) {
        const auto& recipeName = categoryRecipe.first;
        const auto& recipeIngredients = categoryRecipe.second;

        //Performs the content comparison during the search process.
        QSet<QString> recipeIngredientsSet(recipeIngredients.begin(), recipeIngredients.end());
        int matchCount = recipeIngredients.size() * 0.5;

        int count = 0; //Counter to keep track of matching ingredients.

        for (const QString& ingredient : ingredients) {
            if (recipeIngredientsSet.contains(ingredient)) {
                //Increase count if ingredient exists.
                count++;
            }
        }
        if (count >= matchCount) {
            //Push results to vector.
            results.push_back(recipeName);
        }
    }
}

