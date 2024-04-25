#include <QApplication>
#include <QPushButton>

#include "../include/Board.h"
#include "../include/Pieces.h"

int main(int argc, char* argv[]) {
    Board board;
    board.precalcDistanceToEdges();
    board.setBoardSFEN(DEFAULT_BOARD);
    board.print();
    Move mv(60, 51, Pieces::Black | Pieces::Pawn, MoveType::Regular);
    board.makeMove(mv);
    board.print();
    Move mv2(20, 29, Pieces::White | Pieces::Pawn, MoveType::Regular);
    board.makeMove(mv2);
    board.print();
    qDebug() << "";
    board.makeMove(
        Move(70, 10, Pieces::Black | Pieces::Bishop, MoveType::Promotion));
    board.print();
    board.makeMove(
        Move(2, 10, Pieces::White | Pieces::Silver, MoveType::Capture));
    board.print();
    //QApplication a(argc, argv);
    //QPushButton button("Hello world!", nullptr);
    //button.resize(200, 100);
    //button.show();
    //return QApplication::exec();
    return 0;
}
