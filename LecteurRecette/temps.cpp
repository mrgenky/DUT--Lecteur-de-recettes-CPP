/**
 * \file temps.cpp
 * \author Munoz Matteo - Dufour Mattéo
 *
 * \brief Programme qui s'occupe du traitement du temps
 *
 */
#include "temps.h"
#include "mainwindow.h"


void traitement::traitementTemps(QStringList &contenuTempsPrep, QStringList &contenuTempsCuisson, QStringList &contenuTempsTotal,LecteurJson Json)
{
    QString tempsPreparation = Json.getTemps().at(0);
    QString tempsCuisson = Json.getTemps().at(1);
    QRegExp CalcHeures("([0-9]*)H");
    QRegExp CalcMinutes("([0-9]*)M");
    int tempsTotalHeures;
    int tempsTotalMinutes;

    CalcMinutes.indexIn(tempsPreparation);
    CalcHeures.indexIn(tempsPreparation);
    contenuTempsPrep << CalcHeures.cap(1) + " heures et " + CalcMinutes.cap(1) + " minutes";

    tempsTotalHeures = (CalcHeures.cap(1)).toInt();
    tempsTotalMinutes = (CalcMinutes.cap(1)).toInt();

    CalcMinutes.indexIn(tempsCuisson);
    CalcHeures.indexIn(tempsCuisson);
    contenuTempsCuisson << CalcHeures.cap(1) + " heures et " + CalcMinutes.cap(1) + " minutes";

    tempsTotalHeures += (CalcHeures.cap(1)).toInt();
    tempsTotalMinutes += (CalcMinutes.cap(1)).toInt();
    contenuTempsTotal << QString::number(tempsTotalHeures) + " heures et " + QString::number(tempsTotalMinutes) + " minutes";
}
