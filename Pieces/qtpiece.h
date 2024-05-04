//
// Created by acryoz on 5/1/24.
//

#ifndef COURSEWORK_SRC_QTPIECE_H_
#define COURSEWORK_SRC_QTPIECE_H_

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
class QtPiece;
}

QT_END_NAMESPACE

class QtPiece : public QWidget {
    Q_OBJECT

   public:
    explicit QtPiece(QWidget* parent = nullptr);
    ~QtPiece() override;

   private:
    Ui::QtPiece* ui;
};


#endif  //COURSEWORK_SRC_QTPIECE_H_
