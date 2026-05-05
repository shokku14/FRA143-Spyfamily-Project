#pragma once
#include "Piece.h"

class StandardPiece : public Piece {
public:
    StandardPiece(int w, Player* p) : Piece(w, p) {}
};

class Small : public StandardPiece {
public:
    Small(Player* p) : StandardPiece(1, p) {}

    std::string getVisibleNameFor(Player* viewer) override {
        return "Small"; 
    }

    void onCoveredBy(Piece* coveringPiece, Game* game) override {
    }
};

class Medium : public StandardPiece {
public:
    Medium(Player* p) : StandardPiece(3, p) {}

    std::string getVisibleNameFor(Player* viewer) override {
        return "Medium";
    }

    void onCoveredBy(Piece* coveringPiece, Game* game) override {
    }
};

class Large : public StandardPiece {
public:
    Large(Player* p) : StandardPiece(5, p) {}

    std::string getVisibleNameFor(Player* viewer) override {
        return "Large";
    }

    void onCoveredBy(Piece* coveringPiece, Game* game) override {
    }
};
