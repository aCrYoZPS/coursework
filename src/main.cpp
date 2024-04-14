#include <QApplication>
#include <QPushButton>

#include "../include/Board.h"
#include "../include/Pieces.h"

int main(int argc, char* argv[]) {
    Board board;
    QString position =
        "ln1g5/1r2S1k2/p2pppn2/2ps2p2/1p7/2P6/PPSPPPPLP/2G2K1pr/LN4G1b w "
        "BGSLPnp";
    board.setBoardSFEN(DEFAULT_BOARD);
    board.print();
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
