//
// Created by acryoz on 5/1/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QtPiece.h" resolved

#include "qtpiece.h"
#include "ui_QtPiece.h"

QtPiece::QtPiece(QWidget* parent) : QWidget(parent), ui(new Ui::QtPiece) {
    ui->setupUi(this);
}

QtPiece::~QtPiece() {
    delete ui;
}
