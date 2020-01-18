#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("C:/Git/author_fix/authorsLog.txt");
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

    authorInfos["Christoph Dinh"] = qMakePair("Christoph Dinh", "");
    authorInfos["chdinh"] = qMakePair("Christoph Dinh", "");
    authorInfos["LorenzE"] = qMakePair("Lorenz Esch", "");
    authorInfos["Lorenz Esch"] = qMakePair("Lorenz Esch", "");
    authorInfos["lorenze"] = qMakePair("Lorenz Esch", "");
    authorInfos["buildqa"] = qMakePair("Rob ", "");
    authorInfos["Gabriel B Motta"] = qMakePair("Gabriel B Motta", "");
    authorInfos["GBeret"] = qMakePair("", "");
    authorInfos["LostSign"] = qMakePair("", "");
    authorInfos["Felix Arndt"] = qMakePair("Felix Arndt", "");
    authorInfos["Felix"] = qMakePair("Felix Arndt", "");
    authorInfos["Limin Sun"] = qMakePair("Limin Sun", "");
    authorInfos["liminsun"] = qMakePair("", "");
    authorInfos["sheinke"] = qMakePair("Simon Heinke", "");
    authorInfos["Viktor"] = qMakePair("Viktor Klueber", "");
    authorInfos["ViktorKL"] = qMakePair("Viktor Klueber", "");
    authorInfos["louis"] = qMakePair("Louis Eichhorst", "");
    authorInfos["louiseichhorst"] = qMakePair("Louis Eichhorst", "");
    authorInfos["Louis Eichhorst"] = qMakePair("Louis Eichhorst", "");
    authorInfos["Erik Hornberger"] = qMakePair("Erik Hornberger", "");
    authorInfos["juangpc"] = qMakePair("", "");
    authorInfos["Chiran"] = qMakePair("", "");
    authorInfos["Florian Schlembach"] = qMakePair("Florian Schlembach", "");
    authorInfos["Seok Lew"] = qMakePair("Seok Lew", "");
    authorInfos["Tim Kunze"] = qMakePair("Tim Kunze", "");
    authorInfos["doerfelruben@aol.com"] = qMakePair("Ruben Doerfel", "");
    authorInfos["Ruben Doerfel"] = qMakePair("Ruben Doerfel", "");
    authorInfos["joewalter"] = qMakePair("Daniel Strohmeier", "");
    authorInfos["rickytjen"] = qMakePair("Ricky Tjen", "");
    authorInfos["SugandhaSachdeva"] = qMakePair("", "");
    authorInfos["MKlamke"] = qMakePair("", "");
    authorInfos["PetrosSimidyan"] = qMakePair("Petros Simidyan", "");
    authorInfos["Petros Simidyan"] = qMakePair("Petros Simidyan", "");
    authorInfos["Blerta Hamzallari"] = qMakePair("Blerta Hamzallari", "");
    authorInfos["1Dice"] = qMakePair("Lars Debor", "");
    authorInfos["1DIce"] = qMakePair("Lars Debor", "");
    authorInfos["mfarisyahya"] = qMakePair("Faris Yahya", "");
    authorInfos["Jana Kiesel"] = qMakePair("Jana Kiesel", "");

    return a.exec();
}
