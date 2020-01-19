#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString pathRepo("C:/Git/test");
    QString pathAuthroLog("../author_fix/authorsLog.txt");

    // Parse and prepare author information
    QFile file(pathAuthroLog);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    QStringList allAuthors;
    QMap<QString,QStringList> results;
    QString currentPath;

    while(!in.atEnd()) {
        QString line = in.readLine();
        line.replace("\t", QString(""));

        if(line.at(0) == ".") {
            currentPath = pathRepo + line.replace("./", "/");
        } else {
            results[currentPath].append(line);
            allAuthors.append(line);
        }
    }

    file.close();

    allAuthors.removeDuplicates();

    //qDebug() << results;
    qDebug() << "\n \n" << allAuthors;

    QMap<QString,QPair<QString,QString>> authorInfos;

    authorInfos["Christoph Dinh"] = qMakePair(QString("Christoph Dinh"), QString("christoph.dinh@live.de"));
    authorInfos["chdinh"] = qMakePair(QString("Christoph Dinh"), QString("christoph.dinh@live.de"));
    authorInfos["lorenz_e"] = qMakePair(QString("Lorenz Esch"), QString("lesch@mgh.harvard.edu"));
    authorInfos["Lorenz_e"] = qMakePair(QString("Lorenz Esch"), QString("lesch@mgh.harvard.edu"));
    authorInfos["LorenzE"] = qMakePair(QString("Lorenz Esch"), QString("lesch@mgh.harvard.edu"));
    authorInfos["Lorenz Esch"] = qMakePair(QString("Lorenz Esch"), QString("lesch@mgh.harvard.edu"));
    authorInfos["lorenze"] = qMakePair(QString("Lorenz Esch"), QString("lesch@mgh.harvard.edu"));
    authorInfos["buildqa"] = qMakePair(QString("Robert Dicamillo"), QString("rd521@nmr.mgh.harvard.edu"));
    authorInfos["Gabriel B Motta"] = qMakePair(QString("Gabriel B Motta"), QString("gabrielbenmotta@gmail.com"));
    authorInfos["GBeret"] = qMakePair(QString("Daniel Knobl"), QString("Daniel.Knobl@tu-ilmenau.de"));
    authorInfos["LostSign"] = qMakePair(QString("Martin Henfling"), QString("Martin.Henfling@tu-ilmenau.de"));
    authorInfos["Felix Arndt"] = qMakePair(QString("Felix Arndt"), QString("Felix.Arndt@tu-ilmenau.de"));
    authorInfos["farndt"] = qMakePair(QString("Felix Arndt"), QString("Felix.Arndt@tu-ilmenau.de"));
    authorInfos["Limin Sun"] = qMakePair(QString("Limin Sun"), QString("limin.sun@childrens.harvard.edu"));
    authorInfos["liminsun"] = qMakePair(QString("Limin Sun"), QString("limin.sun@childrens.harvard.edu"));
    authorInfos["sheinke"] = qMakePair(QString("Simon Heinke"), QString("Simon.Heinke@tu-ilmenau.de"));
    authorInfos["Viktor"] = qMakePair(QString("Viktor Klueber"), QString("Viktor.Klueber@tu-ilmenau.de"));
    authorInfos["ViktorKL"] = qMakePair(QString("Viktor Klueber"), QString("Viktor.Klueber@tu-ilmenau.de"));
    authorInfos["louis"] = qMakePair(QString("Louis Eichhorst"), QString("Louis.Eichhorst@tu-ilmenau.de"));
    authorInfos["louiseichhorst"] = qMakePair(QString("Louis Eichhorst"), QString("Louis.Eichhorst@tu-ilmenau.de"));
    authorInfos["Louis Eichhorst"] = qMakePair(QString("Louis Eichhorst"), QString("Louis.Eichhorst@tu-ilmenau.de"));
    authorInfos["Erik Hornberger"] = qMakePair(QString("Erik Hornberger"), QString("erik.hornberger@shi-g.com"));
    authorInfos["juangpc"] = qMakePair(QString("Juan Garcia-Prieto"), QString("juangpc@gmail.com"));
    authorInfos["cdoshi"] = qMakePair(QString("Chiran Doschi"), QString("Chiran.Doschi@childrens.harvard.edu"));
    authorInfos["Chiran"] = qMakePair(QString("Chiran Doschi"), QString("Chiran.Doschi@childrens.harvard.edu"));
    authorInfos["Florian Schlembach"] = qMakePair(QString("Florian Schlembach"), QString("Florian.Schlembach@tu-ilmenau.de"));
    authorInfos["Seok Lew"] = qMakePair(QString("Seok Lew"), QString("Seok.Lew@childrens.harvard.edu"));
    authorInfos["Tim Kunze"] = qMakePair(QString("Tim Kunze"), QString("Tim.Kunze@tu-ilmenau.de"));
    authorInfos["doerfelruben@aol.com"] = qMakePair(QString("Ruben Doerfel"), QString("Ruben.Doerfel@tu-ilmenau.de"));
    authorInfos["Ruben Doerfel"] = qMakePair(QString("Ruben Doerfel"), QString("Ruben.Doerfel@tu-ilmenau.de"));
    authorInfos["joewalter"] = qMakePair(QString("Daniel Strohmeier"), QString("Daniel.Strohmeier@tu-ilmenau.de"));
    authorInfos["rickytjen"] = qMakePair(QString("Ricky Tjen"), QString("ricky270@student.sgu.ac.id"));
    authorInfos["Ricky"] = qMakePair(QString("Ricky Tjen"), QString("ricky270@student.sgu.ac.id"));
    authorInfos["SugandhaSachdeva"] = qMakePair(QString("Sugandha Sachdeva"), QString("sugandha.sachdeva@tu-ilmenau.de"));
    authorInfos["MKlamke"] = qMakePair(QString("Marco Klamke"), QString("marco.klamke@tu-ilmenau.de"));
    authorInfos["PetrosSimidyan"] = qMakePair(QString("Petros Simidyan"), QString("petros.simidyan@tu-ilmenau.de"));
    authorInfos["Petros Simidyan"] = qMakePair(QString("Petros Simidyan"), QString("petros.simidyan@tu-ilmenau.de"));
    authorInfos["Blerta Hamzallari"] = qMakePair(QString("Blerta Hamzallari"), QString("blerta.hamzallari@tu-ilmenau.de"));
    authorInfos["1Dice"] = qMakePair(QString("Lars Debor"), QString("Lars.Debor@tu-ilmenau.de"));
    authorInfos["1DIce"] = qMakePair(QString("Lars Debor"), QString("Lars.Debor@tu-ilmenau.de"));
    authorInfos["mfarisyahya"] = qMakePair(QString("Faris Yahya"), QString("mfarisyahya@gmail.com"));
    authorInfos["Felix Griesau"] = qMakePair(QString("Felix Griesau"), QString("Felix.Griesau@tu-ilmenau.de"));
    authorInfos["Jana Kiesel"] = qMakePair(QString("Jana Kiesel"), QString("Jana.Kiesel@tu-ilmenau.de"));
    authorInfos["Matti Hamalainen"] = qMakePair(QString("Matti Hamalainen"), QString("msh@nmr.mgh.harvard.edu"));

    authorInfos["Christof Pieloth"] = qMakePair(QString("Christof Pieloth"), QString(""));
    authorInfos["cpieloth"] = qMakePair(QString("Christof Pieloth"), QString(""));
    authorInfos["Benjamin Kay"] = qMakePair(QString("Benjamin Kay"), QString(""));
    authorInfos["Eric Larson"] = qMakePair(QString("Eric Larson"), QString(""));
    authorInfos["fjpolo"] = qMakePair(QString("Franco Polo"), QString(""));
    authorInfos["Martin Luessi"] = qMakePair(QString("Martin Luessi"), QString(""));
    authorInfos["Mainak Jas"] = qMakePair(QString("Mainak Jas"), QString(""));

    // Process cpp h and pro files > Update author information only if license is present > do not delete present authors
    QMapIterator<QString,QStringList> i(results);
    while (i.hasNext()) {
        i.next();
        QString pathFile = i.key();
        QStringList authorList = i.value();

        qDebug() << "Fixing" << pathFile << "with authors" << authorList;

        // Open file
        QFile fileFix(pathFile);
        if(fileFix.open(QIODevice::ReadWrite)) {
            // Check if @authors exists
            QTextStream inFix(&fileFix);
            QString all = inFix.readAll();

            //qDebug() << all;

            int indexAuthor = all.indexOf("* @author");
            int indexVersion = all.indexOf("* @version");
            if(indexAuthor != -1) {
//                qDebug() << "Found author keyword in" << pathFile;
//                qDebug() << "indexAuthor" << indexAuthor;
//                qDebug() << "indexVersion" << indexVersion;

                // Check if Matti as author exisits
                if(all.contains("Hamalainen")) {
                    authorList << "Matti Hamalainen";
                }

                // Replace authors with correct ones from authorLog file
                QString placeholder("*           ");
                QString replaceString;

                for(int i = 0; i < authorList.size(); ++i) {
                    QString newAuthor = QString("%1 <%2>\r\n").arg(authorInfos[authorList.at(i)].first).arg(authorInfos[authorList.at(i)].second);

                    if(i == 0) {
                        replaceString.append("* @author   ");
                        replaceString.append(newAuthor);
                    } else if (!replaceString.contains(newAuthor)) {
                        replaceString.append(placeholder);
                        replaceString.append(newAuthor);
                    }
                }

                // Fix licencing
                all.replace(indexAuthor, indexVersion-indexAuthor, replaceString);
                fileFix.seek(0); // go to the beginning of the file
                fileFix.write(all.toUtf8()); // write the new text back to the file

                fileFix.close(); // close the file handle.
            } else {
                qDebug() << "Did not find author keyword in" << pathFile;
            }
        } else {
            qDebug() << "Could not open file" << pathFile;
        }
    }

    return a.exec();
}
