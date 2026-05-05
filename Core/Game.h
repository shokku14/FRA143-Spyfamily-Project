#pragma once
#include "../Types/SupportingTypes.h"
#include "../Board/GameBoard.h"
#include "Player.h"
#include <vector>

class Game {
private:
    Player* currentPlayer;
    int turnNumber = 1;
    int roundNumber = 1;
    bool specialExtraTurn = false;
    bool skipRegenerationThisTurn = false;
    GameState state = GameState::READY;

    GameBoard* board;
    std::vector<Player*> players;

public:
    Game() {
        board = new GameBoard();
    }
    ~Game() {
        delete board;
        for (Player* p : players) delete p;
    }

    void start() {
        state = GameState::RUNNING;
    }

    void switchTurn() {
    }

    bool playTurn(PieceType pieceType, int row, int col) {
        return true; 
    }

    bool checkWinFor(Player* player) {
        return board->hasThreeInARow(player);
    }

    Player* getOpponentOf(Player* player) {
        if (players.size() < 2) return nullptr;
        return (players[0] == player) ? players[1] : players[0];
    }

private:
    void handleFullBoardRule(Player* blockedPlayer) {
        specialExtraTurn = true;
        skipRegenerationThisTurn = true;
    }

    void triggerAllActiveBombs() {
    }
};
