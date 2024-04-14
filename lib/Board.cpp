#include "../include/Board.h"
#include "../include/Pieces.h"

Board::Board() {
    this->squares = QVector<uint8_t>(BOARD_SIZE * BOARD_SIZE, 0);
    this->white_komadai = QVector<uint8_t>(0, 0);
    this->black_komadai = QVector<uint8_t>(0, 0);
}

void Board::print() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        QDebug deb = qDebug();
        for (int j = BOARD_SIZE - 1; j >= 0; --j) {
            deb << PieceLiterals.at(this->squares[i * BOARD_SIZE + j]);
        }
        deb << "";
    }
    qDebug() << ((this->current_turn == 0) ? "Black" : "White");
    qDebug() << "Black has: ";
    QDebug deb = qDebug();
    for (uint8_t piece : this->black_komadai) {
        deb << PieceLiterals.at(piece);
    }
    deb = qDebug();
    qDebug() << "White has:";
    for (uint8_t piece : this->white_komadai) {
        deb << PieceLiterals.at(piece);
    }
    deb << "";
}

void Board::setPiece(uint8_t square, uint8_t piece) {
    this->squares[square] = piece;
}

void Board::setBoardSFEN(QString SFEN) {
    uint8_t color;
    bool turned = false;
    QStringList list = SFEN.split(' ');
    size_t i = 0;
    size_t j = BOARD_SIZE - 1;
    for (size_t k = 0; k < list[0].length(); ++k) {
        char character = list[0].at(k).unicode();
        if (std::isdigit(character) != 0) {
            j -= character - '0';
            continue;
        }
        if (std::isupper(character) != 0) {
            color = Pieces::White;
        } else {
            color = Pieces::Black;
        }
        switch (tolower(character)) {
            case '+':
                turned = true;
                continue;
            case 'k':
                this->squares[BOARD_SIZE * i + j] = color | Pieces::King;
                break;
            case 'p':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedPawn;
                    turned = false;
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Pawn;
                }
                break;
            case 'l':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedLance;
                    turned = false;
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Lance;
                }
                break;
            case 'n':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedKnight;
                    turned = false;
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Knight;
                }
                break;
            case 's':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedSilver;
                    turned = false;
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Silver;
                }
                break;
            case 'g':
                this->squares[BOARD_SIZE * i + j] = color | Pieces::Gold;
                break;
            case 'b':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedBishop;
                    turned = false;
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Bishop;
                }
                break;
            case 'r':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedRook;
                    turned = false;
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Rook;
                }
                break;
            case '/':
                i += 1;
                j = BOARD_SIZE - 1;
                continue;
            default:
                throw "Logic error";
        }
        j--;
    }
    if (list[1] == "b") {
        this->current_turn = 0;
    } else {
        this->current_turn = 1;
    }
    for (size_t k = 0; k < list[2].length(); ++k) {
        size_t count = 1;
        if (std::isdigit(list[2].at(k).unicode()) != 0) {
            count = list[2].at(k).unicode() - '0';
        }
        QVector<uint8_t>* komadai;
        char character = list[2].at(k).unicode();
        if (std::isupper(character) != 0) {
            komadai = &this->black_komadai;
            color = Pieces::Black;
        } else {
            komadai = &this->white_komadai;
            color = Pieces::White;
        }
        switch (tolower(character)) {
            case 'p':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Pawn);
                }
                break;
            case 'l':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Lance);
                }
                break;
            case 'n':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Knight);
                }
                break;
            case 's':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Silver);
                }
                break;
            case 'g':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Gold);
                }
                break;
            case 'b':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Bishop);
                }
                break;
            case 'r':
                for (int piece_count = 0; piece_count < count; ++piece_count) {
                    komadai->push_back(color | Pieces::Rook);
                }
                break;
            default:
                throw "Logic error";
        }
    }
}