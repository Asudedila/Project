#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <QDialog>
#include <QCheckBox>
#include <QVector>
#include <QString>

namespace Ui {
class Ingredients;
}

class Ingredients : public QDialog
{
    Q_OBJECT

public:
    explicit Ingredients(QWidget *parent = nullptr);
    ~Ingredients();
    QVector<QString> getSelectedIngredients() const;


private slots:
    void on_pushButton_clicked();

private:
    Ui::Ingredients *ui;
};

#endif // INGREDIENTS_H
