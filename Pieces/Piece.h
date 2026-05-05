#pragma once
#include <string>

class Game;
class Player;

class Piece {
protected:
    int weight;
    int row;
    int col;
    Player* owner; 

public:
    Piece(int w, Player* p) : weight(w), owner(p), row(-1), col(-1) {}

    virtual ~Piece() = default;

    Player* getOwner() { return owner; }
    int getWeight() { return weight; }

    virtual bool canCover(Piece* target) {
        if (target == nullptr) return true; // ถ้าช่องว่าง ทับได้เลย
        return this->weight > target->getWeight();
    }

    virtual std::string getVisibleNameFor(Player* viewer) = 0; 

    virtual void onPlaced(Game* game, int r, int c) {
        row = r;
        col = c;
    }

    virtual void onCoveredBy(Piece* coveringPiece, Game* game) = 0; 

    virtual void onOpponentTurnPassed(Game* game, Player* opponent) {} 
};