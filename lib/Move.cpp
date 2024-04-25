//
// Created by acryoz on 4/16/24.
//

#include "../include/Move.h"

Move::Move(uint8_t square, uint8_t destination, uint8_t piece, uint8_t type) {
    this->start = square;
    this->destination = destination;
    this->piece = piece;
    this->type = type;
}

uint8_t Move::startSq() const {
    return this->start;
}

uint8_t Move::destSq() const {
    return this->destination;
}

uint8_t Move::pieceType() const {
    return this->piece;
}

bool Move::operator==(const Move& lhs) const {
    return (this->start == lhs.startSq()) &&
           (this->destination == lhs.destSq()) &&
           (this->piece == lhs.pieceType());
}

int Move::getScore() {
    return this->score;
}

void Move::setScore(int new_score) {
    this->score = new_score;
}

bool Move::operator<(const Move& other) const {
    return this->score > other.score;
}

uint8_t Move::moveType() const {
    return this->type;
}

void Move::print() {
    qDebug() << PieceLiterals.at(this->piece) << this->start
             << this->destination << this->score;
}