/********************************************************************************
** Form generated from reading UI file 'movelineedit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVELINEEDIT_H
#define UI_MOVELINEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_MoveLineEdit
{
public:

    void setupUi(QLineEdit *MoveLineEdit)
    {
        if (MoveLineEdit->objectName().isEmpty())
            MoveLineEdit->setObjectName(QString::fromUtf8("MoveLineEdit"));
        MoveLineEdit->resize(400, 300);

        retranslateUi(MoveLineEdit);

        QMetaObject::connectSlotsByName(MoveLineEdit);
    } // setupUi

    void retranslateUi(QLineEdit *MoveLineEdit)
    {
        MoveLineEdit->setWindowTitle(QCoreApplication::translate("MoveLineEdit", "MoveLineEdit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoveLineEdit: public Ui_MoveLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVELINEEDIT_H
