#ifndef UVEDITEUR_H
#define UVEDITEUR_H

#include<iostream>
#include<QWidget>
#include<QObject>
#include<QPushButton>
#include<QApplication>
#include<QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QVBoxLayout>
#include<QString>
#include<QFileDialog>
#include<QLabel>
#include<QCheckBox>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QComboBox>
#include<QSpinBox>
#include<QMessageBox>
#include"UTProfiler.h"

class Debut : public QWidget {
    Q_OBJECT
    QPushButton* modifier;
    QPushButton* sup;
    QPushButton* ajouter;
    QHBoxLayout* coucheH;
    QVBoxLayout* coucheV;


public :
    Debut();

public slots:
    void ajout();
    void suppression();
    void modif();
};

class UVSuppression : public QWidget {
    Q_OBJECT
    UVManager& M;
    QLabel* codeLabel;
    QLineEdit* code2;
    QPushButton* submit;
    QHBoxLayout* coucheH;
    QVBoxLayout* coucheV;

public : UVSuppression(UVManager & uvm);

public slots :
    void supprUV();
};


class UVModif : public QWidget {
    Q_OBJECT
    UVManager& M;
    QLabel* codeLabel;
    QLineEdit* code;
    QPushButton* submit;
    QHBoxLayout* coucheH;
    QVBoxLayout* coucheV;

public : UVModif(UVManager & uvm);

public slots :
    void modifUV();
};

class UVAjout : public QWidget{
    Q_OBJECT


    UVManager& M;

    QLineEdit* code;
    QLabel* codeLabel;
    QTextEdit* titre;
    QLabel* titreLabel;
    QSpinBox* credits;
    QLabel* creditsLabel;
    QComboBox* categorie;
    QLabel* categorieLabel;
    QLabel* ouvertureLabel;
    QCheckBox* automne;
    QCheckBox* printemps;
    QPushButton* sauver;
    QPushButton* annuler;

    QVBoxLayout * couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;

public:
 UVAjout(UVManager & uvm);
public slots:
 void slot_ajoutUV();
 //void activerSauver(QString str="");

};

class UVEditeur : public QWidget {
    Q_OBJECT //macro qui déploie toutes les instructions pour gérer signaux et slots
    UV& uv;
    UVManager& M;

       QLineEdit* code;
       QLabel* codeLabel;
       QTextEdit* titre;
       QLabel* titreLabel;
       QSpinBox* credits;
       QLabel* creditsLabel;
       QComboBox* categorie;
       QLabel* categorieLabel;
       QLabel* ouvertureLabel;
       QCheckBox* automne;
       QCheckBox* printemps;
       QPushButton* sauver;
       QPushButton* annuler;

       QVBoxLayout * couche;
       QHBoxLayout* coucheH1;
       QHBoxLayout* coucheH2;
       QHBoxLayout* coucheH3;
       QHBoxLayout* coucheH4;

public:
    UVEditeur(UV& u, UVManager & uvm, QWidget* parent=0);
public slots:
    void sauverUV();
    //void activerSauver(QString str="");

};

#endif // UVEDITEUR_H
