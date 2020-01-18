#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("../author_fix/authorsLog.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    QStringList allAuthors;
    QMap<QString,QStringList> results;
    QString currentPath;

    while(!in.atEnd()) {
        QString line = in.readLine();
        line.replace("\t", "");

        if(line.at(0) == ".") {
            currentPath = line;
        } else {
            results[currentPath].append(line);
            allAuthors.append(line);
        }
    }

    file.close();

    allAuthors.removeDuplicates();

    qDebug() << results;
    qDebug() << "\n \n" << allAuthors;

    QMap<QString,QPair<QString,QString>> authorInfos;

    authorInfos["Christoph Dinh"] = qMakePair(QString("Christoph Dinh"), QString("christoph.dinh@live.de"));
    authorInfos["chdinh"] = qMakePair("Christoph Dinh", QString("christoph.dinh@live.de"));
    authorInfos["LorenzE"] = qMakePair("Lorenz Esch", "lesch@mgh.harvard.edu");
    authorInfos["Lorenz Esch"] = qMakePair("Lorenz Esch", "lesch@mgh.harvard.edu");
    authorInfos["lorenze"] = qMakePair("Lorenz Esch", "lesch@mgh.harvard.edu");
    authorInfos["buildqa"] = qMakePair("Robert Dicamillo", "rd521@nmr.mgh.harvard.edu");
    authorInfos["Gabriel B Motta"] = qMakePair("Gabriel B Motta", "gabrielbenmotta@gmail.com");
    authorInfos["GBeret"] = qMakePair("Daniel Knobl", "Daniel.Knobl@tu-ilmenau.de");
    authorInfos["LostSign"] = qMakePair("Martin Henfling", "Martin.Henfling@tu-ilmenau.de");
    authorInfos["Felix Arndt"] = qMakePair("Felix Arndt", "Felix.Arndt@tu-ilmenau.de");
    authorInfos["Limin Sun"] = qMakePair("Limin Sun", "limin.sun@childrens.harvard.edu");
    authorInfos["liminsun"] = qMakePair("Limin Sun", "limin.sun@childrens.harvard.edu");
    authorInfos["sheinke"] = qMakePair("Simon Heinke", "Simon.Heinke@tu-ilmenau.de");
    authorInfos["Viktor"] = qMakePair("Viktor Klueber", "Viktor.Klueber@tu-ilmenau.de");
    authorInfos["ViktorKL"] = qMakePair("Viktor Klueber", "Viktor.Klueber@tu-ilmenau.de");
    authorInfos["louis"] = qMakePair("Louis Eichhorst", "Louis.Eichhorst@tu-ilmenau.de");
    authorInfos["louiseichhorst"] = qMakePair("Louis Eichhorst", "Louis.Eichhorst@tu-ilmenau.de");
    authorInfos["Louis Eichhorst"] = qMakePair("Louis Eichhorst", "Louis.Eichhorst@tu-ilmenau.de");
    authorInfos["Erik Hornberger"] = qMakePair("Erik Hornberger", "erik.hornberger@shi-g.com");
    authorInfos["juangpc"] = qMakePair("Juan Garcia-Prieto", "juangpc@gmail.com");
    authorInfos["Chiran"] = qMakePair("Chiran Doshi", "Chiran.Doshi@childrens.harvard.edu");
    authorInfos["Florian Schlembach"] = qMakePair("Florian Schlembach", "");
    authorInfos["Seok Lew"] = qMakePair("Seok Lew", "Seok.Lew@childrens.harvard.edu");
    authorInfos["Tim Kunze"] = qMakePair("Tim Kunze", "Tim.Kunze@tu-ilmenau.de");
    authorInfos["doerfelruben@aol.com"] = qMakePair("Ruben Doerfel", "Ruben.Doerfel@tu-ilmenau.de");
    authorInfos["Ruben Doerfel"] = qMakePair("Ruben Doerfel", "Ruben.Doerfel@tu-ilmenau.de");
    authorInfos["joewalter"] = qMakePair("Daniel Strohmeier", "Daniel.Strohmeier@tu-ilmenau.de");
    authorInfos["rickytjen"] = qMakePair("Ricky Tjen", "ricky270@student.sgu.ac.id");
    authorInfos["SugandhaSachdeva"] = qMakePair("Sugandha Sachdeva", "sugandha.sachdeva@tu-ilmenau.de");
    authorInfos["MKlamke"] = qMakePair("Marco Klamke", "marco.klamke@tu-ilmenau.de");
    authorInfos["PetrosSimidyan"] = qMakePair("Petros Simidyan", "petros.simidyan@tu-ilmenau.de");
    authorInfos["Petros Simidyan"] = qMakePair("Petros Simidyan", "petros.simidyan@tu-ilmenau.de");
    authorInfos["Blerta Hamzallari"] = qMakePair("Blerta Hamzallari", "blerta.hamzallari@tu-ilmenau.de");
    authorInfos["1Dice"] = qMakePair("Lars Debor", "Lars.Debor@tu-ilmenau.de");
    authorInfos["1DIce"] = qMakePair("Lars Debor", "Lars.Debor@tu-ilmenau.de");
    authorInfos["mfarisyahya"] = qMakePair("Faris Yahya", "mfarisyahya@gmail.com");
    authorInfos["Felix Griesau"] = qMakePair("Felix Griesau", "Felix.Griesau@tu-ilmenau.de");
    authorInfos["Jana Kiesel"] = qMakePair("Jana Kiesel", "Jana.Kiesel@tu-ilmenau.de");

    return a.exec();
}
