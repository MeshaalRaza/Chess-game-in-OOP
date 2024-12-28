#include <iostream>
#include <vector>
#include <string>
#include <cctype>

// Enum to represent the chess pieces
enum class PieceType { EMPTY, KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

// Enum to represent the colors of pieces
enum class PieceColor { NONE, WHITE, BLACK };

// Class to represent a chess piece
class ChessPiece {
public:
    ChessPiece() : type(PieceType::EMPTY), color(PieceColor::NONE) {}
    ChessPiece(PieceType type, PieceColor color) : type(type), color(color) {}

    // Display the piece on the console
    void display() const {
        char pieceChar;
        switch (type) {
            case PieceType::KING:    pieceChar = 'K'; break;
            case PieceType::QUEEN:   pieceChar = 'Q'; break;
            case PieceType::ROOK:    pieceChar = 'R'; break;
            case PieceType::BISHOP:  pieceChar = 'B'; break;
            case PieceType::KNIGHT:  pieceChar = 'N'; break;
            case PieceType::PAWN:    pieceChar = 'P'; break;
            case PieceType::EMPTY:   pieceChar = '.'; break;
        }

        char colorChar = (color == PieceColor::WHITE) ? 'W' : 
                         (color == PieceColor::BLACK) ? 'B' : ' ';
        if (type == PieceType::EMPTY) 
            std::cout << " . ";
        else
            std::cout << colorChar << pieceChar << " ";
    }

    PieceType getType() const { return type; }
    PieceColor getColor() const { return color; }

    void setPiece(PieceType t, PieceColor c) {
        type = t;
        color = c;
    }

private:
    PieceType type;
    PieceColor color;
};

// Class to represent a chessboard
class ChessBoard {
public:
    ChessBoard() {
        // Initialize the chessboard with pieces
        initializeBoard();
    }

    // Display the current state of the chessboard
    void display() const {
        std::cout << "\n  a b c d e f g h\n";
        std::cout << " +----------------\n";
        for (int i = 0; i < 8; ++i) {
            std::cout << 8 - i << "|";
            for (int j = 0; j < 8; ++j) {
                pieces[i][j].display();
            }
            std::cout << " " << 8 - i << "\n";
        }
        std::cout << " +----------------\n";
        std::cout << "  a b c d e f g h\n";
    }

    // Function to handle a player's move
    bool movePiece(const std::string& from, const std::string& to, PieceColor playerColor) {
        int fromRow = 8 - (from[1] - '0');
        int fromCol = from[0] - 'a';
        int toRow = 8 - (to[1] - '0');
        int toCol = to[0] - 'a';

        ChessPiece& fromPiece = pieces[fromRow][fromCol];
        ChessPiece& toPiece = pieces[toRow][toCol];

        // Check if the move is valid (only move if there is a piece and it matches player's color)
        if (fromPiece.getColor() == playerColor && fromPiece.getType() != PieceType::EMPTY) {
            // Simulate a move by removing the piece from the "from" position and placing it at the "to" position
            toPiece.setPiece(fromPiece.getType(), fromPiece.getColor());
            fromPiece.setPiece(PieceType::EMPTY, PieceColor::NONE);
            return true;
        }

        return false;
    }

private:
    // 2D array to represent the chessboard
    ChessPiece pieces[8][8];

    // Initialize the chessboard with pieces in their initial positions
    void initializeBoard() {
        // Initialize empty squares
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                pieces[i][j] = ChessPiece();
            }
        }

        // Initialize pawns
        for (int i = 0; i < 8; ++i) {
            pieces[1][i] = ChessPiece(PieceType::PAWN, PieceColor::WHITE);
            pieces[6][i] = ChessPiece(PieceType::PAWN, PieceColor::BLACK);
        }

        // Initialize other pieces
        pieces[0][0] = ChessPiece(PieceType::ROOK, PieceColor::WHITE);
        pieces[0][7] = ChessPiece(PieceType::ROOK, PieceColor::WHITE);
        pieces[7][0] = ChessPiece(PieceType::ROOK, PieceColor::BLACK);
        pieces[7][7] = ChessPiece(PieceType::ROOK, PieceColor::BLACK);

        pieces[0][1] = ChessPiece(PieceType::KNIGHT, PieceColor::WHITE);
        pieces[0][6] = ChessPiece(PieceType::KNIGHT, PieceColor::WHITE);
        pieces[7][1] = ChessPiece(PieceType::KNIGHT, PieceColor::BLACK);
        pieces[7][6] = ChessPiece(PieceType::KNIGHT, PieceColor::BLACK);

        pieces[0][2] = ChessPiece(PieceType::BISHOP, PieceColor::WHITE);
        pieces[0][5] = ChessPiece(PieceType::BISHOP, PieceColor::WHITE);
        pieces[7][2] = ChessPiece(PieceType::BISHOP, PieceColor::BLACK);
        pieces[7][5] = ChessPiece(PieceType::BISHOP, PieceColor::BLACK);

        pieces[0][3] = ChessPiece(PieceType::QUEEN, PieceColor::WHITE);
        pieces[0][4] = ChessPiece(PieceType::KING, PieceColor::WHITE);
        pieces[7][3] = ChessPiece(PieceType::QUEEN, PieceColor::BLACK);
        pieces[7][4] = ChessPiece(PieceType::KING, PieceColor::BLACK);
    }
};

int main() {
    ChessBoard chessBoard;
    chessBoard.display();

    std::string from, to;
    PieceColor currentPlayer = PieceColor::WHITE;
    while (true) {
        std::cout << (currentPlayer == PieceColor::WHITE ? "White's turn" : "Black's turn") << std::endl;
        std::cout << "Enter move (e.g., e2 e4): ";
        std::cin >> from >> to;

        if (chessBoard.movePiece(from, to, currentPlayer)) {
            chessBoard.display();
            currentPlayer = (currentPlayer == PieceColor::WHITE) ? PieceColor::BLACK : PieceColor::WHITE;
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}

