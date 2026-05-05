#pragma once
#include <string>
#include "../Types/SupportingTypes.h"
#include "PieceInventory.h"
#include "../Pieces/Piece.h"
#include "../Pieces/StandardPieces.h"
#include "../Pieces/SpecialPieces.h"

class Player {
private:
    std::string name;
    PlayerColor color;
    int turnsTaken = 0;
    PieceInventory inventory; 

public:
    Player(std::string n, PlayerColor c) : name(n), color(c) {}

    std::string getName() { return name; }
    int getTurnsTaken() { return turnsTaken; }
    void incrementTurn() { turnsTaken++; }
    PieceInventory& getInventory() { return inventory; }

    Piece* createPiece(PieceType type) {
        if (!inventory.hasAvailable(type)) return nullptr; 
        
        inventory.consume(type); 

        switch (type) {
            case PieceType::SMALL: return new Small(this);
            case PieceType::MEDIUM: return new Medium(this);
            case PieceType::LARGE: return new Large(this);
            case PieceType::BOMB: return new Bomb(this);
            case PieceType::SPY: return new Spy(this);
            default: return nullptr;
        }
    }

    std::string getVisibleStandardInfo() { return "Standard Pieces Info..."; }
    std::string getPrivateSpecialInfo() { return "Special Pieces Info..."; }
};