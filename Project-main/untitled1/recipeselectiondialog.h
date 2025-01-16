#ifndef RECIPESELECTIONDIALOG_H
#define RECIPESELECTIONDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class RecipeSelectionDialog;
}

class RecipeSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeSelectionDialog(QWidget *parent = nullptr);
    ~RecipeSelectionDialog();
    void setRecipeList(const QStringList &recipeNames);
signals:
    void recipeSelected(const QString &selectedRecipe);

private slots:
    void on_listWidget_itemSelectionChanged();

private:
    Ui::RecipeSelectionDialog *ui;
};

#endif // RECIPESELECTIONDIALOG_H
