#ifndef CURSUS_H
#define CURSUS_H

#include <iostream>
#include "UTProfiler.h"
#include "menu.h"
#include <QString>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QDebug>


class menuFormation;

class formation
{
    friend class cursusManager;

    QString nom;
    unsigned int nbCredits; //Le nombre de credits à obtenir pour valider la formation
    unsigned int nbSemestres; //Le nombre de semestres (théoriques) de la formation
    UV** uvs; //la liste des uvs appartenant à la formation mais à aucune de ses filières
    unsigned int nbUV;
    unsigned int nbMaxUV;

    formation(const QString& n, unsigned int c, unsigned int s): nom(n), nbCredits(c), nbSemestres(s), uvs(0), nbUV(0), nbMaxUV(0) {}

public:
    void ajouter_UV(UV*);//template method ??
    void supprimer_UV(const QString &code);
    ~formation();
    QString getNom() const {return nom;}
    unsigned int getNbCred() const {return nbCredits;}
    unsigned int getNbSem() const {return nbSemestres;}
    void modif(const QString& n, unsigned int c, unsigned int s);
    const UV* trouverUV(const QString& code);

    class iterateur<UV>;
    iterateur<UV>& getIterateurUV();
};

class filiere
{
    QString nom;
    formation* form; //formation à laquelle appartieint la filière
    UV** uvs; //la liste des uvs appartenant à la filière et donc à la formation à laquelle appartient la filière
    unsigned int nbUV;
    unsigned int nbMaxUV;

public:
    filiere(const QString& n="", formation* f=0): nom(n), form(f), uvs(0), nbUV(0), nbMaxUV(0) {}
    void ajouter_UV(const UV&);
    ~filiere();
};

class cursusManager // gestionnaire des cursus
{
    formation** formations;
    unsigned int nbFor;
    unsigned int nbMaxFor;
    filiere** filieres;
    unsigned int nbFil;
    unsigned int nbMaxFil;

    friend class menuFormation; //Achtung !!! à supprimer !!!
    friend class modifFormation;//idem ! (faire un itérateur !);

public:
    cursusManager(): formations(0), nbFor(0), nbMaxFor(0), filieres(0), nbFil(0), nbMaxFil(0) {}
    ~cursusManager() {delete[] formations; delete[] filieres; qDebug()<<"Destruction cursusManager";}
    int getnbFor() const {return nbFor;}
    int getnbFil() const {return nbFil;}
    formation* trouverForm(const QString &n);
    formation* getFormation(int index){return formations[index];}
    void ajouterFiliere(const QString& nom, formation* fo);
    void chargerCursus();
    void ajouterFormation(const QString& nom, unsigned int c, unsigned int s);
    void supprimerFormation(const QString& nom);
    void supprimerFormation(unsigned int index);
    void sauverCursus(QWidget* parent);

    class iterateur<formation>;
    iterateur<formation>& getIterateurForm();

};


class ajoutFormation : public QWidget {
    Q_OBJECT
    cursusManager* man;
    menuFormation* parent;
    QVBoxLayout* mainbox;
    QHBoxLayout* hbox1;
    QHBoxLayout* hbox2;
    QHBoxLayout* hbox3;
    QLabel* lbl1;
    QLabel* lbl2;
    QLabel* lbl3;
    QLineEdit* nom;
    QSpinBox* credits;
    QSpinBox* semstr;
    QPushButton* valider;


public :
    ajoutFormation(cursusManager *m, menuFormation* p);

public slots:
    void ajout();
};

class modifFormation : public QWidget {
    Q_OBJECT
    cursusManager* man;
    formation* form;
    QVBoxLayout* mainbox;
    QHBoxLayout* hbox1;
    QHBoxLayout* hbox2;
    QHBoxLayout* hbox3;
    QLabel* lbl1;
    QLabel* lbl2;
    QLabel* lbl3;
    QLineEdit* nom;
    QSpinBox* credits;
    QSpinBox* semstr;
    QPushButton* valider;


public :
    modifFormation(cursusManager *m, formation* f);

public slots:
    void modif();
};

class visualiserFormation : public QWidget
{
    Q_OBJECT
    cursusManager* cman;
    UVManager* uman;
    formation* objet;
    QHBoxLayout* mainbox;
    QVBoxLayout* vbox1;
    QVBoxLayout* vbox2;
    QHBoxLayout* hbox1;
    QHBoxLayout* hbox2;
    QHBoxLayout* hbox3;
    QLabel* form;
    QLabel* cred;
    QLabel* semstr;
    QLabel* lbluvs;
    QLabel* uvs;
    QComboBox* supprUV;
    QPushButton* retour;
    QPushButton* modif;
    QPushButton* suppr;

public:
    visualiserFormation(cursusManager* cmanager, UVManager* umanager, formation* f);
public slots:
    void moduvs();
    void update();
    void supprimer();

};

class selectUVsFormation : public QWidget
{
    Q_OBJECT
    cursusManager* cman;
    UVManager* uman;
    formation* objet;
    visualiserFormation* parent;
    QVBoxLayout* mainbox;
    QLabel* label1;
    QComboBox* choix;
    QPushButton* retour;
    QPushButton* ajouter;

public:
    selectUVsFormation(cursusManager* cm, UVManager* um, formation* f, visualiserFormation* p);
public slots:
    void ajouterUV();
    void update();

};

#endif // CURSUS_H
