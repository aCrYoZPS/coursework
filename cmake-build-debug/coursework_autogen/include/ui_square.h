/********************************************************************************
** Form generated from reading UI file 'square.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQUARE_H
#define UI_SQUARE_H

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>

QT_BEGIN_NAMESPACE

class Ui_Square
{
public:

    void setupUi(QObject *Square)
    {
        if (Square->objectName().isEmpty())
            Square->setObjectName(QString::fromUtf8("Square"));
        Square->resize(400, 300);

        retranslateUi(Square);

        QMetaObject::connectSlotsByName(Square);
    } // setupUi

    void retranslateUi(QObject *Square)
    {
        Square->setWindowTitle(QCoreApplication::translate("Square", "Square", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Square: public Ui_Square {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQUARE_H
