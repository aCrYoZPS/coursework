#pragma once
#ifndef COURSEWORK_LIB_BOARD_H_
#define COURSEWORK_LIB_BOARD_H_

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QVector>
#include <iomanip>
#include <iostream>

#include "Move.h"
#include "Pieces.h"
#include "Squares.h"

static constexpr uint8_t BOARD_SIZE = 9;

static const QString DEFAULT_BOARD =
    "lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL b ";

static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_SAFETY_TABLE = {
    // clang-format off
    0,  0,  0,   0,   0,   0,   0,   0,  0,
    1, 1, 2,  2,  3,  3,  3,  4, 5,
    5, 6, 6,  7,  8,  8,  8,  9, 10,
    11, 12, 13, 14, 15, 16, 18, 19, 20,
    21, 22, 23, 24, 26, 27, 28, 29, 30,
    31, 33, 34, 35, 36, 37, 38, 40, 41,
    42, 43, 44, 45, 47, 48, 49, 50, 50,
    50, 50, 50, 45, 40, 45, 50, 50, 50,
    50, 50, 50, 45, 40, 45, 50, 50, 50
};
// clang-format on
static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_SAFETY_TABLE = {
    // clang-format off
    50, 50, 50, 45, 40, 45, 50, 50, 50,
    50, 50, 50, 45, 40, 45, 50, 50, 50,
    42, 43, 44, 45, 47, 48, 49, 50, 50,
    31, 33, 34, 35, 36, 37, 38, 40, 41,
    21, 22, 23, 24, 26, 27, 28, 29, 30,
    11, 12, 13, 14, 15, 16, 18, 19, 20,
    5, 6, 6,  7,  8,  8,  8,  9, 10,
    1, 1, 2,  2,  3,  3,  3,  4, 5,
    0,  0,  0,   0,   0,   0,   0,   0,  0,
};
// clang-format on
static const std::array<int, BOARD_SIZE * BOARD_SIZE> BLACK_PAWN_VALUES_MAP{
    // clang-format off
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    50, 50, 50, 50, 50, 50, 50, 50, 50,
    20, 20, 20, 20, 20, 20, 20, 20, 20,
    30, 30, 30, 30, 30, 30, 30, 30, 30,
    40, 40, 40, 40, 40, 40, 40, 40, 40,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};
// clang-format on
static const std::array<int, BOARD_SIZE * BOARD_SIZE> WHITE_PAWN_VALUES_MAP{
    // clang-format off
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    40, 40, 40, 40, 40, 40, 40, 40, 40,
    30, 30, 30, 30, 30, 30, 30, 30, 30,
    20, 20, 20, 20, 20, 20, 20, 20, 20,
    50, 50, 50, 50, 50, 50, 50, 50, 50,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};
// clang-format on

class Board {
   public:
    Board();
    void print();
    void printMoves();
    void setBoardSFEN(QString);
    void precalcDistanceToEdges();
    void setPiece(uint8_t, uint8_t);
    void makeMove(Move);
    QVector<Move> generateMoves();
    QVector<Move> generateGeneralsKingMoves(uint8_t, uint8_t);
    QVector<Move> generateSlidingMoves(uint8_t, uint8_t);
    QVector<Move> generatePawnLanceMoves(uint8_t, uint8_t);
    QVector<Move> generateKnightMoves(uint8_t, uint8_t);
    QVector<Move> generatePlacements();
    void generatePawnAttackMap();
    void reorderMoves(QVector<Move>&);
    Move search(int);
    int negaMax(int, int, int);
    std::array<std::array<QVector<uint8_t>, 2>, 16> snapshot();
    void setSnapshot(std::array<std::array<QVector<uint8_t>, 2>, 16>);
    int evalBoard();
    int countMaterial(uint8_t);

   private:
    QVector<uint8_t> squares;
    //32 - black
    //16 - white
    uint8_t current_turn = 32;
    uint32_t number_of_turns = 0;
    QVector<uint8_t> white_komadai;
    QVector<uint8_t> black_komadai;
    QVector<Move> possible_moves;
    QVector<QVector<uint8_t>> distance_to_edgs;

    std::array<QVector<uint8_t>, 2> kings;
    std::array<QVector<uint8_t>, 2> pawns;
    std::array<QVector<uint8_t>, 2> lances;
    std::array<QVector<uint8_t>, 2> knights;
    std::array<QVector<uint8_t>, 2> silvers;
    std::array<QVector<uint8_t>, 2> golds;
    std::array<QVector<uint8_t>, 2> turned_pawns;
    std::array<QVector<uint8_t>, 2> turned_lances;
    std::array<QVector<uint8_t>, 2> turned_knights;
    std::array<QVector<uint8_t>, 2> turned_silvers;
    std::array<QVector<uint8_t>, 2> bishops;
    std::array<QVector<uint8_t>, 2> rooks;
    std::array<QVector<uint8_t>, 2> turned_rooks;
    std::array<QVector<uint8_t>, 2> turned_bishops;

    std::array<QVector<uint8_t>, 2> pawn_attack_map;
};

#endif  // COURSEWORK_LIB_BOARD_H_
