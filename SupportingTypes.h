#pragma once

// กำหนดสถานะของเกม[cite: 2]
enum class GameState {
    READY,
    RUNNING,
    FINISHED
};

// กำหนดประเภทของหมากทั้งหมดในเกม[cite: 2]
enum class PieceType {
    SMALL,
    MEDIUM,
    LARGE,
    BOMB,
    SPY
};

// กำหนดสีหรือฝ่ายของผู้เล่น[cite: 2]
enum class PlayerColor {
    RED,
    BLUE
};