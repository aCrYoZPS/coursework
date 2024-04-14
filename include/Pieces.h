#pragma once
#include <QString>
#include <unordered_map>

enum Pieces : uint8_t {
    None = 0,
    King = 1,
    Pawn = 2,
    Lance = 3,
    Knight = 4,
    Silver = 5,
    Gold = 6,
    Bishop = 7,
    Rook = 8,
    TurnedPawn = 9,
    TurnedLance = 10,
    TurnedKnight = 11,
    TurnedSilver = 12,
    TurnedBishop = 13,
    TurnedRook = 14,

    White = 16,
    Black = 32,
};

static const std::unordered_map<uint8_t, QString> PieceLiterals = {
    { None, "0" },
    { Black | King, "k" },
    { Black | Pawn, "p" },
    { Black | Lance, "l" },
    { Black | Knight, "n" },
    { Black | Silver, "s" },
    { Black | Gold, "g" },
    { Black | Bishop, "b" },
    { Black | Rook, "r" },
    { Black | TurnedPawn, "+p" },
    { Black | TurnedLance, "+l" },
    { Black | TurnedSilver, "+s" },
    { Black | TurnedBishop, "+b" },
    { Black | TurnedRook, "+r" },
    { White | King, "K" },
    { White | Pawn, "P" },
    { White | Lance, "L" },
    { White | Knight, "N" },
    { White | Silver, "S" },
    { White | Gold, "G" },
    { White | Bishop, "B" },
    { White | Rook, "R" },
    { White | TurnedPawn, "+P" },
    { White | TurnedLance, "+L" },
    { White | TurnedSilver, "+S" },
    { White | TurnedBishop, "+B" },
    { White | TurnedRook, "+R" },
};
