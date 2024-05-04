#pragma once
#include <QString>
#include <unordered_map>

static const uint8_t COLOR_MASK = 0b00110000;
static const uint8_t TYPE_MASK = 0b00001111;

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

static const std::unordered_map<uint8_t, QString> pieceLiterals = {
    { None, "-" },
    { White | King, "k" },
    { White | Pawn, "p" },
    { White | Lance, "l" },
    { White | Knight, "n" },
    { White | Silver, "s" },
    { White | Gold, "g" },
    { White | Bishop, "b" },
    { White | Rook, "r" },
    { White | TurnedPawn, "+p" },
    { White | TurnedLance, "+l" },
    { White | TurnedKnight, "+n" },
    { White | TurnedSilver, "+s" },
    { White | TurnedBishop, "+b" },
    { White | TurnedRook, "+r" },
    { Black | King, "K" },
    { Black | Pawn, "P" },
    { Black | Lance, "L" },
    { Black | Knight, "N" },
    { Black | Silver, "S" },
    { Black | Gold, "G" },
    { Black | Bishop, "B" },
    { Black | Rook, "R" },
    { Black | TurnedPawn, "+P" },
    { Black | TurnedLance, "+L" },
    { Black | TurnedKnight, "+N" },
    { Black | TurnedSilver, "+S" },
    { Black | TurnedBishop, "+B" },
    { Black | TurnedRook, "+R" },
};

static const std::unordered_map<std::string, uint8_t> pieceByLiteral = {
    { "-", None },
    { "k", White | King },
    { "p", White | Pawn },
    { "l", White | Lance },
    { "n", White | Knight },
    { "s", White | Silver },
    { "g", White | Gold },
    { "b", White | Bishop },
    { "r", White | Rook },
    { "+p", White | TurnedPawn },
    { "+l", White | TurnedLance },
    { "+n", White | TurnedKnight },
    { "+s", White | TurnedSilver },
    { "+b", White | TurnedBishop },
    { "+r", White | TurnedRook },
    { "K", Black | King },
    { "P", Black | Pawn },
    { "L", Black | Lance },
    { "N", Black | Knight },
    { "S", Black | Silver },
    { "G", Black | Gold },
    { "B", Black | Bishop },
    { "R", Black | Rook },
    { "+P", Black | TurnedPawn },
    { "+L", Black | TurnedLance },
    { "+N", Black | TurnedKnight },
    { "+S", Black | TurnedSilver },
    { "+B", Black | TurnedBishop },
    { "+R", Black | TurnedRook },
};

static const std::unordered_map<uint8_t, int16_t> PieceValue{
    { None, 0 },         { King, 500 },        { Pawn, 1 },
    { Lance, 4 },        { Knight, 5 },        { Silver, 7 },
    { Gold, 8 },         { Bishop, 11 },       { Rook, 13 },
    { TurnedPawn, 10 },  { TurnedLance, 9 },   { TurnedKnight, 9 },
    { TurnedSilver, 8 }, { TurnedBishop, 15 }, { TurnedRook, 17 }
};

bool isSliding(uint8_t);
