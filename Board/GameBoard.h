#pragma once
#include "Board.h"
#include "Cell.h"
#include <vector>

class Player; 

class GameBoard : public Board {
private:
    std::vector<std::vector<Cell*>> cells; 

public:
    GameBoard() {
        for (int r = 0; r < rows; r++) {
            std::vector<Cell*> rowCells;
            for (int c = 0; c < cols; c++) {
                rowCells.push_back(new Cell(r, c));
            }
            cells.push_back(rowCells);
        }
    }

    ~GameBoard() {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                delete cells[r][c];
            }
        }
    }

    Cell* getCell(int row, int col) {
        if (!isInside(row, col)) return nullptr;
        return cells[row][col];
    }

    bool isFull() { return false; } 
    bool hasLegalMove(Player* player) { return true; } 
    bool placePiece(Piece* piece, int row, int col) { return true; } 
    Piece* removePiece(int row, int col) { return nullptr; } 
    std::vector<Cell*> getOrthogonalNeighbors(int row, int col) { return std::vector<Cell*>(); } 
    bool hasThreeInARow(Player* player) { return false; } 
};