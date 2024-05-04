/********************************************************************************
** Form generated from reading UI file 'endmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDMENU_H
#define UI_ENDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndMenu
{
public:

    void setupUi(QWidget *EndMenu)
    {
        if (EndMenu->objectName().isEmpty())
            EndMenu->setObjectName(QString::fromUtf8("EndMenu"));
        EndMenu->resize(400, 300);

        retranslateUi(EndMenu);

        QMetaObject::connectSlotsByName(EndMenu);
    } // setupUi

    void retranslateUi(QWidget *EndMenu)
    {
        EndMenu->setWindowTitle(QCoreApplication::translate("EndMenu", "EndMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndMenu: public Ui_EndMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDMENU_H
