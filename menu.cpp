#include "cursus.h"
#include "menu.h"
#include "UTProfiler.h"
#include <QMessageBox>

menuFormation::menuFormation(cursusManager *man, UVManager* u)
{
    m=man;
    uvman=u;

    mainbox=new QVBoxLayout(this);
    hbox1=new QHBoxLayout(this);
    hbox2=new QHBoxLayout(this);
    titre=new QLabel("Choisissez une formation et sélectionnez l'opération:",this);
    select=new QComboBox(this);
    visualiser=new QPushButton("Voir les détails",this);
    ajouter=new QPushButton("Ajouter une formation",this);
    modifier=new QPushButton("Modifier",this);
    supprimer=new QPushButton("Supprimer",this);
    quit=new QPushButton("Quitter",this);
    sauver=new QPushButton("Sauver",this);

    select->setFixedWidth(300);
    mainbox->addLayout(hbox1);
    mainbox->addLayout(hbox2);
    hbox1->addWidget(titre);
    hbox1->addWidget(select);
    hbox2->addWidget(visualiser);
    hbox2->addWidget(ajouter);
    hbox2->addWidget(modifier);
    hbox2->addWidget(supprimer);
    hbox2->addWidget(sauver);
    hbox2->addWidget(quit);

    QObject::connect(visualiser,SIGNAL(clicked()),this,SLOT(voir()));
    QObject::connect(ajouter,SIGNAL(clicked()),this, SLOT(ajout()));
    QObject::connect(modifier,SIGNAL(clicked()),this, SLOT(modif()));
    QObject::connect(supprimer,SIGNAL(clicked()),this, SLOT(suppr()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(sauver, SIGNAL(clicked()),this,SLOT(save()));

    update();
}

void menuFormation::voir()
{
    try{
    if(m->getnbFor()==0) {throw UTProfilerException("Aucune formation à afficher !");}
    visualiserFormation* fenetre=new visualiserFormation(m,uvman,m->trouverForm(select->currentText()));
    fenetre->show();
    }
    catch(UTProfilerException& e) {QMessageBox::information(0,"Erreur",e.getInfo(),QMessageBox::Ok);}
}

void menuFormation::update()
{
    select->clear();
    for(iterateur<formation>& it=m->getIterateurForm();!it.isDone();it.next())
    {
        select->addItem(it.courant()->getNom());
    }
}

void menuFormation::ajout()
{
    ajoutFormation* fenetre=new ajoutFormation(m, this);
    fenetre->show();
}

void menuFormation::modif()
{
    try{
    if(m->getnbFor()==0) {throw UTProfilerException("Aucune formation à modifier !");}
    modifFormation* fenetre=new modifFormation(m,m->trouverForm(select->currentText()));
    fenetre->show();
    }
    catch(UTProfilerException& e) {QMessageBox::information(0,"Erreur",e.getInfo(),QMessageBox::Ok);}
}

void menuFormation::suppr()
{
    try{
    if(m->getnbFor()==0) {throw UTProfilerException("Aucune formation à supprimer !");}
    if(QMessageBox::information(this,"Suppression","Voulez-vous supprimer la formation "+select->currentText()+" ?",QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Ok)
    {
        int index=select->currentIndex();
        m->supprimerFormation(index);
        QMessageBox::information(this,"Suppression","Formation supprimée !",QMessageBox::Ok);
        this->update();
    }
    }
    catch(UTProfilerException& e) {QMessageBox::information(0,"Erreur",e.getInfo(),QMessageBox::Ok);}
}
void menuFormation::save()
{
    m->sauverCursus(this);
}
