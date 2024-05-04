/********************************************************************************
** Form generated from reading UI file 'textboard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTBOARD_H
#define UI_TEXTBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextBoard
{
public:

    void setupUi(QWidget *TextBoard)
    {
        if (TextBoard->objectName().isEmpty())
            TextBoard->setObjectName(QString::fromUtf8("TextBoard"));
        TextBoard->resize(400, 300);

        retranslateUi(TextBoard);

        QMetaObject::connectSlotsByName(TextBoard);
    } // setupUi

    void retranslateUi(QWidget *TextBoard)
    {
        TextBoard->setWindowTitle(QCoreApplication::translate("TextBoard", "TextBoard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextBoard: public Ui_TextBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTBOARD_H
