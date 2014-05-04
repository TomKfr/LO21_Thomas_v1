#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "UTProfiler.h"
#include "cursus.h"
#include <QString>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>

class cursusManager;

class menuFormation : public QWidget
{
    Q_OBJECT
    cursusManager* m;
    UVManager* uvman;
    QVBoxLayout* mainbox;
    QHBoxLayout* hbox1;
    QHBoxLayout* hbox2;
    QLabel* titre;
    QComboBox* select;
    QPushButton* visualiser;
    QPushButton* ajouter;
    QPushButton* modifier;
    QPushButton* supprimer;
    QPushButton* quit;
    QPushButton* sauver;

public:
    menuFormation(cursusManager* m, UVManager *u);

public slots:
    void voir();
    void ajout();
    void modif();
    void suppr();
    void update();
    void save();
};



#endif // MENU_H
