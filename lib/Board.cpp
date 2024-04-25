#include "../include/Board.h"

Board::Board() {
    this->current_turn = Pieces::Black;
    this->squares = QVector<uint8_t>(BOARD_SIZE * BOARD_SIZE, 0);
    this->white_komadai = QVector<uint8_t>(0, 0);
    this->black_komadai = QVector<uint8_t>(0, 0);
}

void Board::print() {
    QVector<QString> output(BOARD_SIZE * BOARD_SIZE, "0");
    for (uint8_t color = 0; color < 2; ++color) {
        uint8_t piece_color = (color == 0) ? Pieces::Black : Pieces::White;
        for (uint8_t square : this->pawns[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::Pawn);
        }
        for (uint8_t square : this->lances[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::Lance);
        }
        for (uint8_t square : this->knights[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::Knight);
        }
        for (uint8_t square : this->silvers[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::Silver);
        }
        for (uint8_t square : this->golds[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::Gold);
        }
        for (uint8_t square : this->bishops[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::Bishop);
        }
        for (uint8_t square : this->rooks[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::Rook);
        }
        for (uint8_t square : this->turned_pawns[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::TurnedPawn);
        }
        for (uint8_t square : this->turned_lances[color]) {
            output[square] =
                PieceLiterals.at(piece_color | Pieces::TurnedLance);
        }
        for (uint8_t square : this->turned_knights[color]) {
            output[square] =
                PieceLiterals.at(piece_color | Pieces::TurnedKnight);
        }
        for (uint8_t square : this->turned_silvers[color]) {
            output[square] =
                PieceLiterals.at(piece_color | Pieces::TurnedSilver);
        }
        for (uint8_t square : this->turned_bishops[color]) {
            output[square] =
                PieceLiterals.at(piece_color | Pieces::TurnedBishop);
        }
        for (uint8_t square : this->turned_rooks[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::TurnedRook);
        }
        for (uint8_t square : this->kings[color]) {
            output[square] = PieceLiterals.at(piece_color | Pieces::King);
        }
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        QDebug deb = qDebug();
        for (int j = BOARD_SIZE - 1; j >= 0; --j) {
            deb << output[i * BOARD_SIZE + j];
        }
    }
    qDebug() << ((this->current_turn == Pieces::Black) ? "Black" : "White");
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
            color = Pieces::Black;
        } else {
            color = Pieces::White;
        }
        uint8_t color_index = (color == Pieces::Black) ? 0 : 1;
        switch (tolower(character)) {
            case '+':
                turned = true;
                continue;
            case 'k':
                this->squares[BOARD_SIZE * i + j] = color | Pieces::King;
                this->kings[color_index].push_back(BOARD_SIZE * i + j);
                break;
            case 'p':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedPawn;
                    turned = false;
                    this->turned_pawns[color_index].push_back(BOARD_SIZE * i +
                                                              j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Pawn;
                    this->pawns[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'l':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedLance;
                    turned = false;
                    this->turned_lances[color_index].push_back(BOARD_SIZE * i +
                                                               j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Lance;
                    this->lances[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'n':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedKnight;
                    turned = false;
                    this->turned_knights[color_index].push_back(BOARD_SIZE * i +
                                                                j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Knight;
                    this->knights[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 's':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedSilver;
                    turned = false;
                    this->turned_silvers[color_index].push_back(BOARD_SIZE * i +
                                                                j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Silver;
                    this->silvers[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'g':
                this->squares[BOARD_SIZE * i + j] = color | Pieces::Gold;
                this->golds[color_index].push_back(BOARD_SIZE * i + j);
                break;
            case 'b':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedBishop;
                    turned = false;
                    this->turned_bishops[color_index].push_back(BOARD_SIZE * i +
                                                                j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Bishop;
                    this->bishops[color_index].push_back(BOARD_SIZE * i + j);
                }
                break;
            case 'r':
                if (turned) {
                    this->squares[BOARD_SIZE * i + j] =
                        color | Pieces::TurnedRook;
                    turned = false;
                    this->turned_rooks[color_index].push_back(BOARD_SIZE * i +
                                                              j);
                } else {
                    this->squares[BOARD_SIZE * i + j] = color | Pieces::Rook;
                    this->rooks[color_index].push_back(BOARD_SIZE * i + j);
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
        this->current_turn = Pieces::Black;
    } else {
        this->current_turn = Pieces::White;
    }
    for (size_t k = 0; k < list[2].length(); ++k) {
        size_t count = 1;
        if (std::isdigit(list[2].at(k).unicode()) != 0) {
            count = list[2].at(k).unicode() - '0';
            k++;
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
    this->generatePawnAttackMap();
    this->possible_moves = generateMoves();
}

void Board::precalcDistanceToEdges() {
    this->distance_to_edgs = QVector<QVector<uint8_t>>(BOARD_SIZE * BOARD_SIZE);

    for (int rank = 0; rank < BOARD_SIZE; ++rank) {
        for (int file = BOARD_SIZE - 1; file >= 0; --file) {
            uint8_t north = rank;
            uint8_t south = BOARD_SIZE - 1 - rank;
            uint8_t west = BOARD_SIZE - 1 - file;
            uint8_t east = file;
            uint8_t square = rank * BOARD_SIZE + file;
            this->distance_to_edgs[square] =
                QVector<uint8_t>{ north,
                                  south,
                                  east,
                                  west,
                                  std::min(north, west),
                                  std::min(north, east),
                                  std::min(south, west),
                                  std::min(south, east) };
        }
    }
}

void Board::generatePawnAttackMap() {
    for (uint8_t square : this->pawns[0]) {
        this->pawn_attack_map[0].push_back(square +
                                           DIRECTION_OFFSET[Directions::North]);
    }
    for (uint8_t square : this->pawns[1]) {
        this->pawn_attack_map[1].push_back(square +
                                           DIRECTION_OFFSET[Directions::South]);
    }
}

QVector<Move> Board::generateSlidingMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    int start_direction;
    int end_direction;
    bool turned_rook = false;
    bool turned_bishop = false;
    switch (piece & TYPE_MASK) {
        case Pieces::Rook:
            start_direction = 0;
            end_direction = 4;
            break;
        case Pieces::Bishop:
            start_direction = 4;
            end_direction = 8;
            break;
        case Pieces::TurnedRook:
            turned_rook = true;
            start_direction = 0;
            end_direction = 8;
            break;
        case Pieces::TurnedBishop:
            turned_bishop = true;
            start_direction = 0;
            end_direction = 8;
            break;
        default:
            throw "Not sliding piece";
    }
    uint8_t color = piece & COLOR_MASK;
    uint8_t opposite_color = (~color) & COLOR_MASK;
    for (int direction = start_direction; direction < end_direction;
         direction++) {
        int limiter = this->distance_to_edgs[square][direction];
        if (turned_bishop && direction < 4) {
            limiter = std::min(limiter, 1);
        } else if (turned_rook && direction >= 4) {
            limiter = std::min(limiter, 1);
        }
        for (int n = 0; n < limiter; ++n) {
            uint8_t destination =
                square + DIRECTION_OFFSET[direction] * (n + 1);
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) == color) {
                break;
            }
            uint8_t type = (this->squares[destination] == 0)
                               ? MoveType::Regular
                               : MoveType::Capture;
            if (color == Pieces::Black && destination < 3 * BOARD_SIZE &&
                !turned_rook && !turned_bishop) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            } else if (color == Pieces::White &&
                       destination >= 6 * BOARD_SIZE && !turned_bishop &&
                       !turned_rook) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            }
            res.push_back(
                Move(square, destination, this->squares[square], type));
            if ((piece_on_dest & COLOR_MASK) == opposite_color) {
                break;
            }
        }
    }
    return res;
}

QVector<Move> Board::generatePawnLanceMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    uint8_t type = piece & TYPE_MASK;
    uint8_t color = piece & COLOR_MASK;
    uint8_t opposite_color = (~color) & COLOR_MASK;
    uint8_t direction =
        (color == Pieces::White) ? Directions::South : Directions::North;
    uint8_t limiter = this->distance_to_edgs[square][direction];
    if (type == Pieces::Pawn) {
        limiter = std::min(limiter, (uint8_t)1);
    } else {
        limiter = limiter;
    }
    for (int n = 0; n < limiter; ++n) {
        uint8_t destination = square + DIRECTION_OFFSET[direction] * (n + 1);
        uint8_t piece_on_dest = this->squares[destination];
        if ((piece_on_dest & COLOR_MASK) == color) {
            break;
        }
        uint8_t move_type = (this->squares[destination] == 0)
                                ? MoveType::Regular
                                : MoveType::Capture;

        if (color == Pieces::Black && destination < 3 * BOARD_SIZE) {
            res.push_back(Move(square, destination, this->squares[square],
                               MoveType::Promotion));
        } else if (color == Pieces::White && destination >= 6 * BOARD_SIZE) {
            res.push_back(Move(square, destination, this->squares[square],
                               MoveType::Promotion));
        }
        if (color == Pieces::Black && destination >= BOARD_SIZE) {
            res.push_back(
                Move(square, destination, this->squares[square], move_type));
        } else if (color == Pieces::White && destination < 8 * BOARD_SIZE) {
            res.push_back(
                Move(square, destination, this->squares[square], move_type));
        }
        if ((piece_on_dest & COLOR_MASK) == opposite_color) {
            break;
        }
    }
    if (type == Pieces::Pawn) {
        this->generatePawnAttackMap();
    }
    return res;
}

QVector<Move> Board::generateKnightMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    uint8_t color = piece & COLOR_MASK;
    uint8_t direction =
        (color == Pieces::White) ? Directions::South : Directions::North;
    if (this->distance_to_edgs[square][Directions::West] > 0) {
        if (this->distance_to_edgs[square][direction] >= 2) {
            uint8_t destination = square + 2 * DIRECTION_OFFSET[direction] +
                                  DIRECTION_OFFSET[Directions::West];
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) != color) {
                uint8_t type = (this->squares[destination] == 0)
                                   ? MoveType::Regular
                                   : MoveType::Capture;
                if (color == Pieces::Black && destination < 3 * BOARD_SIZE) {
                    res.push_back(Move(square, destination,
                                       this->squares[square],
                                       MoveType::Promotion));
                } else if (color == Pieces::White &&
                           destination >= 6 * BOARD_SIZE) {
                    res.push_back(Move(square, destination,
                                       this->squares[square],
                                       MoveType::Promotion));
                }
                if (color == Pieces::White && (destination < 7 * BOARD_SIZE)) {
                    res.push_back(
                        Move(square, destination, this->squares[square], type));
                } else if (color == Pieces::Black &&
                           destination >= 2 * BOARD_SIZE) {
                    res.push_back(
                        Move(square, destination, this->squares[square], type));
                }
            }
        }
    }
    if (this->distance_to_edgs[square][Directions::East] > 0) {
        if (this->distance_to_edgs[square][direction] >= 2) {
            uint8_t destination = square + 2 * DIRECTION_OFFSET[direction] +
                                  DIRECTION_OFFSET[Directions::East];
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) != color) {
                uint8_t type = (this->squares[destination] == 0)
                                   ? MoveType::Regular
                                   : MoveType::Capture;
                res.push_back(
                    Move(square, destination, this->squares[square], type));
            }
        }
    }
    return res;
}

QVector<Move> Board::generateGeneralsKingMoves(uint8_t square, uint8_t piece) {
    QVector<Move> res;
    int start_direction = 0;
    int end_direction = 8;
    uint8_t color = piece & COLOR_MASK;
    uint8_t opposite_color = (~color) & COLOR_MASK;
    QVector<uint8_t> forbidden_directions;
    switch (piece & TYPE_MASK) {
        case Pieces::Silver:
            forbidden_directions = { Directions::West, Directions::East };
            (color == Pieces::White)
                ? forbidden_directions.push_back(Directions::North)
                : forbidden_directions.push_back(Directions::South);
            break;
        case Pieces::King:
            break;
        default:
            if (color == Pieces::White) {
                forbidden_directions = { Directions::NE, Directions::NW };
            } else {
                forbidden_directions = { Directions::SE, Directions::SW };
            }
            break;
    }
    bool forb_dir = false;
    for (int direction = start_direction; direction < end_direction;
         direction++) {
        for (uint8_t dir : forbidden_directions) {
            if (dir == direction) {
                forb_dir = true;
            }
        }
        if (forb_dir) {
            forb_dir = false;
            continue;
        }
        int limiter =
            std::min(this->distance_to_edgs[square][direction], (uint8_t)1);
        for (int n = 0; n < limiter; ++n) {
            uint8_t destination =
                square + DIRECTION_OFFSET[direction] * (n + 1);
            uint8_t piece_on_dest = this->squares[destination];
            if ((piece_on_dest & COLOR_MASK) == color) {
                break;
            }
            uint8_t type = (this->squares[destination] == 0)
                               ? MoveType::Regular
                               : MoveType::Capture;
            if (piece == (Pieces::Black | Pieces::Silver) &&
                destination < 3 * BOARD_SIZE) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            } else if (piece == (Pieces::White | Pieces::Silver) &&
                       destination >= 6 * BOARD_SIZE) {
                res.push_back(Move(square, destination, this->squares[square],
                                   MoveType::Promotion));
            }
            res.push_back(
                Move(square, destination, this->squares[square], type));
            if ((piece_on_dest & COLOR_MASK) == opposite_color) {
                break;
            }
        }
    }
    return res;
}

QVector<Move> Board::generatePlacements() {
    QVector<Move> res;
    QVector<uint8_t>* komadai;
    (this->current_turn == Pieces::Black) ? komadai = &this->black_komadai
                                          : komadai = &this->white_komadai;
    uint8_t color = this->current_turn;
    uint8_t starting = 0;
    uint8_t ending = BOARD_SIZE * BOARD_SIZE;
    QVector<bool> seen(9);
    for (uint8_t piece : *komadai) {
        uint8_t piece_type = piece & TYPE_MASK;
        if (seen[piece_type]) {
            continue;
        }
        if (piece_type == Pieces::Pawn || piece_type == Pieces::Knight ||
            piece_type == Pieces::Lance) {
            if (piece_type == Pieces::Pawn || piece_type == Pieces::Lance) {
                if (color == Pieces::Black) {
                    starting = 9;
                } else {
                    ending = 72;
                }
            } else {
                if (color == Pieces::Black) {
                    starting = 18;
                } else {
                    ending = 63;
                }
            }
        }
        for (uint8_t square = starting; square < ending; ++square) {
            bool legal = true;
            if (this->squares[square] == 0) {
                if (piece_type == Pieces::Pawn) {
                    uint8_t file = square % BOARD_SIZE;
                    for (uint8_t sq = file; sq < BOARD_SIZE * BOARD_SIZE;
                         sq += 9) {
                        if ((this->squares[sq]) ==
                            (this->current_turn | Pieces::Pawn)) {
                            legal = false;
                            break;
                        }
                    }
                }
                if (legal) {
                    res.push_back(Move(81, square, piece, MoveType::Placement));
                }
            }
        }
        seen[piece_type] = true;
    }
    return res;
}

QVector<Move> Board::generateMoves() {
    QVector<Move> res;

    uint8_t color_index = (this->current_turn == Pieces::Black) ? 0 : 1;
    for (uint8_t square : this->bishops[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->rooks[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_rooks[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_bishops[color_index]) {
        res.append(generateSlidingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->pawns[color_index]) {
        res.append(generatePawnLanceMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->lances[color_index]) {
        res.append(generatePawnLanceMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->knights[color_index]) {
        res.append(generateKnightMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->silvers[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->golds[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_pawns[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_lances[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_knights[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->turned_silvers[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    for (uint8_t square : this->kings[color_index]) {
        res.append(generateGeneralsKingMoves(square, this->squares[square]));
    }
    res.append(generatePlacements());
    return res;
}

std::array<std::array<QVector<uint8_t>, 2>, 16> Board::snapshot() {
    std::array<std::array<QVector<uint8_t>, 2>, 16> snapshot;
    snapshot[0] = this->kings;
    snapshot[1] = this->pawns;
    snapshot[2] = this->lances;
    snapshot[3] = this->knights;
    snapshot[4] = this->silvers;
    snapshot[5] = this->golds;
    snapshot[6] = this->bishops;
    snapshot[7] = this->rooks;
    snapshot[8] = this->turned_pawns;
    snapshot[9] = this->turned_lances;
    snapshot[10] = this->turned_knights;
    snapshot[11] = this->turned_silvers;
    snapshot[12] = this->turned_bishops;
    snapshot[13] = this->turned_rooks;
    snapshot[14][0] = this->black_komadai;
    snapshot[14][1] = this->white_komadai;
    snapshot[15][0] = this->squares;
    return snapshot;
}

void Board::setSnapshot(
    std::array<std::array<QVector<uint8_t>, 2>, 16> snapshot) {
    this->kings = snapshot[0];
    this->pawns = snapshot[1];
    this->lances = snapshot[2];
    this->knights = snapshot[3];
    this->silvers = snapshot[4];
    this->golds = snapshot[5];
    this->bishops = snapshot[6];
    this->rooks = snapshot[7];
    this->turned_pawns = snapshot[8];
    this->turned_lances = snapshot[9];
    this->turned_knights = snapshot[10];
    this->turned_silvers = snapshot[11];
    this->turned_bishops = snapshot[12];
    this->turned_rooks = snapshot[13];
    this->black_komadai = snapshot[14][0];
    this->white_komadai = snapshot[14][1];
    this->squares = snapshot[15][0];
}

void Board::makeMove(Move move) {
    if (this->possible_moves.contains(move)) {
        if (this->squares[move.destSq()] != 0) {
            uint8_t color_index = (this->current_turn == Pieces::Black) ? 0 : 1;
            uint8_t opposite_color = (color_index == 0) ? 1 : 0;
            uint8_t captured_piece = this->squares[move.destSq()];
            captured_piece &= TYPE_MASK;
            switch (captured_piece) {
                case Pieces::Pawn:
                    this->pawns[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Lance:
                    this->lances[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Knight:
                    this->knights[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Silver:
                    this->silvers[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Gold:
                    this->golds[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Bishop:
                    this->bishops[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::Rook:
                    this->rooks[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::TurnedPawn:
                    this->turned_pawns[opposite_color].removeOne(move.destSq());
                    break;
                case Pieces::TurnedLance:
                    this->turned_lances[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedKnight:
                    this->turned_knights[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedSilver:
                    this->turned_silvers[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedBishop:
                    this->turned_bishops[opposite_color].removeOne(
                        move.destSq());
                    break;
                case Pieces::TurnedRook:
                    this->turned_rooks[opposite_color].removeOne(move.destSq());
                    break;
            }
            if (this->current_turn == Pieces::Black) {
                switch (captured_piece) {
                    case Pieces::TurnedPawn:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Pawn);
                        break;
                    case Pieces::TurnedLance:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Lance);
                        break;
                    case Pieces::TurnedKnight:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Knight);
                        break;
                    case Pieces::TurnedSilver:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Silver);
                        break;
                    case Pieces::TurnedBishop:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Bishop);
                        break;
                    case Pieces::TurnedRook:
                        this->black_komadai.push_back(Pieces::Black |
                                                      Pieces::Rook);
                        break;
                    default:
                        this->black_komadai.push_back(Pieces::Black |
                                                      captured_piece);
                        break;
                }
            } else {
                switch (captured_piece) {
                    case Pieces::TurnedPawn:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Pawn);
                        break;
                    case Pieces::TurnedLance:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Lance);
                        break;
                    case Pieces::TurnedKnight:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Knight);
                        break;
                    case Pieces::TurnedSilver:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Silver);
                        break;
                    case Pieces::TurnedBishop:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Bishop);
                        break;
                    case Pieces::TurnedRook:
                        this->white_komadai.push_back(Pieces::White |
                                                      Pieces::Rook);
                        break;
                    default:
                        this->white_komadai.push_back(Pieces::White |
                                                      captured_piece);
                        break;
                }
            }
        }
        if (move.startSq() != 81) {
            uint8_t color_index = (this->current_turn == Pieces::Black) ? 0 : 1;
            switch (this->squares[move.startSq()] & TYPE_MASK) {
                case Pieces::Pawn:
                    if (move.moveType() == MoveType::Promotion) {
                        this->pawns[color_index].removeOne(move.startSq());
                        this->turned_pawns[color_index].push_back(
                            move.destSq());
                        this->squares[move.destSq()] = Pieces::TurnedPawn;
                    } else {
                        this->pawns[color_index][this->pawns[color_index]
                                                     .indexOf(move.startSq())] =
                            move.destSq();
                        this->squares[move.destSq()] = Pieces::Pawn;
                        this->generatePawnAttackMap();
                    }
                    break;
                case Pieces::Lance:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] = Pieces::TurnedLance;
                        this->lances[color_index].removeOne(move.startSq());
                        this->turned_lances[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = Pieces::Lance;
                        this->lances[color_index]
                                    [this->lances[color_index].indexOf(
                                        move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Knight:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] = Pieces::TurnedKnight;
                        this->knights[color_index].removeOne(move.startSq());
                        this->turned_knights[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = Pieces::Knight;
                        this->knights[color_index]
                                     [this->knights[color_index].indexOf(
                                         move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Silver:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] = Pieces::TurnedSilver;
                        this->silvers[color_index].removeOne(move.startSq());
                        this->turned_silvers[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = Pieces::Silver;
                        this->silvers[color_index]
                                     [this->silvers[color_index].indexOf(
                                         move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Gold:
                    this->golds[color_index][this->golds[color_index].indexOf(
                        move.startSq())] = (move.destSq());
                    break;
                case Pieces::Bishop:
                    this->squares[move.destSq()] = Pieces::TurnedBishop;
                    if (move.moveType() == MoveType::Promotion) {
                        this->bishops[color_index].removeOne(move.startSq());
                        this->turned_bishops[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = Pieces::Bishop;
                        this->bishops[color_index]
                                     [this->bishops[color_index].indexOf(
                                         move.startSq())] = (move.destSq());
                    }
                    break;
                case Pieces::Rook:
                    if (move.moveType() == MoveType::Promotion) {
                        this->squares[move.destSq()] = Pieces::TurnedRook;
                        this->rooks[color_index].removeOne(move.startSq());
                        this->turned_rooks[color_index].push_back(
                            move.destSq());
                    } else {
                        this->squares[move.destSq()] = Pieces::Rook;
                        this->rooks[color_index][this->rooks[color_index]
                                                     .indexOf(move.startSq())] =
                            (move.destSq());
                    }
                    break;
                case Pieces::TurnedPawn:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_pawns[color_index]
                                      [this->turned_pawns[color_index].indexOf(
                                          move.startSq())] = (move.destSq());
                    break;
                case Pieces::TurnedLance:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_lances[color_index]
                                       [this->turned_lances[color_index]
                                            .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedKnight:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_knights[color_index]
                                        [this->turned_knights[color_index]
                                             .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedSilver:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_silvers[color_index]
                                        [this->turned_silvers[color_index]
                                             .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedBishop:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_bishops[color_index]
                                        [this->turned_bishops[color_index]
                                             .indexOf(move.startSq())] =
                        (move.destSq());
                    break;
                case Pieces::TurnedRook:
                    this->squares[move.destSq()] = move.pieceType();
                    this->turned_rooks[color_index]
                                      [this->turned_rooks[color_index].indexOf(
                                          move.startSq())] = (move.destSq());
                    break;
            }
            this->squares[move.startSq()] = 0;
        }
        if (move.startSq() == 81) {
            uint8_t color_index = (this->current_turn == Pieces::Black) ? 0 : 1;
            switch (move.pieceType() & TYPE_MASK) {
                case Pieces::Pawn:
                    this->pawns[color_index].append(move.destSq());
                    this->generatePawnAttackMap();
                    break;
                case Pieces::Lance:
                    this->lances[color_index].append(move.destSq());
                    break;
                case Pieces::Knight:
                    this->knights[color_index].append(move.destSq());
                    break;
                case Pieces::Silver:
                    this->silvers[color_index].append(move.destSq());
                    break;
                case Pieces::Gold:
                    this->golds[color_index].append(move.destSq());
                    break;
                case Pieces::Bishop:
                    this->bishops[color_index].append(move.destSq());
                    break;
                case Pieces::Rook:
                    this->rooks[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedPawn:
                    this->turned_pawns[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedLance:
                    this->turned_lances[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedKnight:
                    this->turned_knights[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedSilver:
                    this->turned_silvers[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedBishop:
                    this->turned_bishops[color_index].append(move.destSq());
                    break;
                case Pieces::TurnedRook:
                    this->turned_rooks[color_index].append(move.destSq());
                    break;
            }
            if (this->current_turn == Pieces::Black) {
                this->black_komadai.removeOne(move.pieceType());
            } else {
                this->white_komadai.removeOne(move.pieceType());
            }
        }

        if (this->current_turn == Pieces::Black) {
            this->current_turn = Pieces::White;
        } else {
            this->current_turn = Pieces::Black;
        }
        this->number_of_turns += 1;
        this->possible_moves = generateMoves();
    }
}

int Board::evalBoard() {
    int black_eval = countMaterial(0);
    int white_eval = countMaterial(1);

    int eval = black_eval - white_eval;

    int perspective = (this->current_turn == Pieces::Black) ? 1 : -1;
    return eval * perspective;
}

void Board::reorderMoves(QVector<Move>& moves) {
    for (size_t i = 0; i < moves.size(); ++i) {
        int move_score = 0;
        uint8_t opponent = (this->current_turn == Pieces::Black) ? 1 : 0;
        uint8_t color = COLOR_MASK & moves[i].pieceType();
        uint8_t move_piece = TYPE_MASK & moves[i].pieceType();
        uint8_t capture_piece = TYPE_MASK & this->squares[moves[i].destSq()];
        if (capture_piece != Pieces::None) {
            move_score =
                10 * PieceValue.at(capture_piece) - PieceValue.at(move_piece);
        }
        if (moves[i].moveType() == MoveType::Promotion) {
            switch (moves[i].pieceType() & TYPE_MASK) {
                case Pieces::Pawn:
                    move_score += PieceValue.at(Pieces::TurnedPawn);
                    break;
                case Pieces::Lance:
                    move_score += PieceValue.at(Pieces::TurnedLance);
                    break;
                case Pieces::Knight:
                    move_score += PieceValue.at(Pieces::TurnedKnight);
                    break;
                case Pieces::Silver:
                    move_score += PieceValue.at(Pieces::TurnedSilver);
                    break;
                case Pieces::Bishop:
                    move_score += PieceValue.at(Pieces::TurnedBishop);
                    break;
                case Pieces::Rook:
                    move_score += PieceValue.at(Pieces::TurnedRook);
                    break;
            }
        }
        if (std::count(this->pawn_attack_map[opponent].begin(),
                       this->pawn_attack_map[opponent].end(),
                       moves[i].destSq()) != 0) {
            move_score -= PieceValue.at(moves[i].pieceType() & TYPE_MASK);
        }
        if (move_piece == Pieces::Pawn && this->number_of_turns <= 12) {
            if (color == Pieces::White) {
                move_score += WHITE_PAWN_VALUES_MAP[moves[i].destSq()];
            } else {
                move_score += BLACK_PAWN_VALUES_MAP[moves[i].destSq()];
            }
        } else if (move_piece == Pieces::King && this->number_of_turns >= 6 &&
                   this->number_of_turns <= 20) {
            if (color == Pieces::White &&
                WHITE_SAFETY_TABLE[moves[i].startSq()] != 50) {
                move_score += WHITE_SAFETY_TABLE[moves[i].destSq()];
            } else if (color == Pieces::Black &&
                       BLACK_SAFETY_TABLE[moves[i].startSq()] != 50) {
                move_score += BLACK_SAFETY_TABLE[moves[i].destSq()];
            }
        }
        moves[i].setScore(move_score);
    }
    std::sort(moves.begin(), moves.end());
}

int Board::negaMax(int depth, int alpha, int beta) {
    if (depth == 0) {
        return evalBoard();
    }
    QVector<Move> moves = generateMoves();
    if (moves.isEmpty()) {
        return std::numeric_limits<int>::min();
    }
    this->reorderMoves(moves);
    for (Move move : moves) {
        auto snap = this->snapshot();
        this->makeMove(move);
        int eval = -this->negaMax(depth - 1, -beta, -alpha);
        this->setSnapshot(snap);
        if (eval >= beta) {
            return beta;
        }
        alpha = std::max(alpha, eval);
    }
    return alpha;
}

Move Board::search(int depth = 0) {
    QVector<Move> moves = this->generateMoves();
    this->reorderMoves(moves);
    Move best_move(0, 0, 0, 0);
    int best_eval = std::numeric_limits<int>::min();
    for (Move move : moves) {
        auto snap = this->snapshot();
        this->makeMove(move);
        int eval = this->negaMax(depth, std::numeric_limits<int>::min() + 1,
                                 std::numeric_limits<int>::max() - 1);

        this->setSnapshot(snap);
        if (eval > best_eval) {
            best_eval = eval;
            best_move = move;
        }
    }
    return best_move;
}

int Board::countMaterial(uint8_t color) {
    int material = 0;
    material += this->pawns[color].length() * PieceValue.at(Pieces::Pawn);
    material += this->lances[color].length() * PieceValue.at(Pieces::Lance);
    material += this->knights[color].length() * PieceValue.at(Pieces::Knight);
    material += this->silvers[color].length() * PieceValue.at(Pieces::Silver);
    material += this->golds[color].length() * PieceValue.at(Pieces::Gold);
    material += this->bishops[color].length() * PieceValue.at(Pieces::Bishop);
    material += this->rooks[color].length() * PieceValue.at(Pieces::Rook);
    material +=
        this->turned_pawns[color].length() * PieceValue.at(Pieces::TurnedPawn);
    material += this->turned_lances[color].length() *
                PieceValue.at(Pieces::TurnedLance);
    material += this->turned_knights[color].length() *
                PieceValue.at(Pieces::TurnedKnight);
    material += this->turned_silvers[color].length() *
                PieceValue.at(Pieces::TurnedSilver);
    material += this->turned_bishops[color].length() *
                PieceValue.at(Pieces::TurnedBishop);
    material +=
        this->turned_rooks[color].length() * PieceValue.at(Pieces::TurnedRook);
    material += PieceValue.at(Pieces::King);
    return material;
}

void Board::printMoves() {
    auto moves = this->generateMoves();
    this->reorderMoves(moves);
    for (Move move : moves) {
        move.print();
    }
}
