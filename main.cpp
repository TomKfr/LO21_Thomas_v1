#include"projet.h"
#include<QApplication>
#include<QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QString>
#include<QFileDialog>
#include"UTProfiler.h"
#include "cursus.h"
#include <QDebug>
#include "menu.h"


int main(int argc,char*argv[]) {
QApplication app(argc, argv);

/*Debut fenetre;
fenetre.show();*/

cursusManager* m=new cursusManager();
UVManager& u=UVManager::getInstance();
m->chargerCursus();
QString chemin=QFileDialog::getOpenFileName(0,"Ouvrir un fichier d'Uvs");
u.load(chemin);

menuFormation* fenetre =new menuFormation(m,&u);
fenetre->show();


return app.exec();

}
