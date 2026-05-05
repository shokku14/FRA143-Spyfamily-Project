#pragma once
#include "../Pieces/Piece.h"

class Cell {
private:
    int row;
    int col;
    Piece* occupant; 

public:
    Cell(int r, int c) : row(r), col(c), occupant(nullptr) {}

    bool isEmpty() { return occupant == nullptr; }

    bool canAccept(Piece* piece) {
        if (isEmpty()) return true; 
        return piece->canCover(occupant); 
    }

    void setOccupant(Piece* piece) { occupant = piece; }
    
    Piece* getOccupant() { return occupant; }

    Piece* removeOccupant() {
        Piece* temp = occupant;
        occupant = nullptr;
        return temp;
    }
};