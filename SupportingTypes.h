#pragma once

enum class GameState {
    READY,
    RUNNING,
    FINISHED
};

enum class PieceType {
    SMALL,
    MEDIUM,
    LARGE,
    BOMB,
    SPY
};

enum class PlayerColor {
    RED,
    BLUE
};