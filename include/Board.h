#pragma once
#ifndef COURSEWORK_LIB_BOARD_H_
#define COURSEWORK_LIB_BOARD_H_

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QVector>
#include <iomanip>
#include <iostream>

static const uint8_t BOARD_SIZE = 9;

static const QString DEFAULT_BOARD =
    "lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL b ";

// clang-format off
enum Squares {
    a1, a2, a3, a4, a5, a6, a7, a8, a9,
    b1, b2, b3, b4, b5, b6, b7, b8, b9,
    c1, c2, c3, c4, c5, c6, c7, c8, c9,
    d1, d2, d3, d4, d5, d6, d7, d8, d9,
    e1, e2, e3, e4, e5, e6, e7, e8, e9,
    f1, f2, f3, f4, f5, f6, f7, f8, f9,
    g1, g2, g3, g4, g5, g6, g7, g8, g9,
    h1, h2, h3, h4, h5, h6, h7, h8, h9,
    i1, i2, i3, i4, i5, i6, i7, i8, i9
};

// clang-format on

class Board {
   public:
    Board();
    void print();
    void setBoardSFEN(QString);
    void setPiece(uint8_t, uint8_t);

    //private:
    QVector<uint8_t> squares;
    //0 - black
    //1 - white
    uchar current_turn;
    QVector<uint8_t> white_komadai;
    QVector<uint8_t> black_komadai;
};

#endif  // !COURSEWORK_LIB_BOARD_H_