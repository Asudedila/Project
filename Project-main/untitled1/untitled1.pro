QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += c++11
QT += core

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    foodcategory.cpp \
    ingredients.cpp \
    main.cpp \
    mainwindow.cpp \
    recipe.cpp \
    recipeselectiondialog.cpp \
    solve.cpp

HEADERS += \
    foodcategory.h \
    ingredients.h \
    mainwindow.h \
    recipe.h \
    recipeselectiondialog.h \
    solve.h

FORMS += \
    ingredients.ui \
    mainwindow.ui \
    recipeselectiondialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
