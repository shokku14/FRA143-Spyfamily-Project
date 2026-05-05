#pragma once
#include "../Types/SupportingTypes.h"

class PieceInventory {
private:
    int mediumCount = 2;
    int mediumMax = 2;
    int mediumRegenInterval = 3;

    int largeCount = 1;
    int largeMax = 1;
    int largeRegenInterval = 5;

    int bombCount = 2;
    int bombMax = 2;
    int bombRegenInterval = 5;

    int spyCount = 2;
    int spyMax = 2;
    int spyRegenInterval = 7;

public:
    PieceInventory() = default;

    bool hasAvailable(PieceType type) {
        switch (type) {
            case PieceType::SMALL: return true;
            case PieceType::MEDIUM: return mediumCount > 0;
            case PieceType::LARGE: return largeCount > 0;
            case PieceType::BOMB: return bombCount > 0;
            case PieceType::SPY: return spyCount > 0;
            default: return false;
        }
    }

    void consume(PieceType type) {
        if (type == PieceType::MEDIUM) mediumCount--;
        else if (type == PieceType::LARGE) largeCount--;
        else if (type == PieceType::BOMB) bombCount--;
        else if (type == PieceType::SPY) spyCount--;
    }

    void regenerate(int ownerTurns, bool allowRegen) {
        if (!allowRegen) return; 

        int rounds = ownerTurns; 
        
        if (rounds > 0 && rounds % mediumRegenInterval == 0 && mediumCount < mediumMax) mediumCount++;
        if (rounds > 0 && rounds % largeRegenInterval == 0 && largeCount < largeMax) largeCount++;
        if (rounds > 0 && rounds % bombRegenInterval == 0 && bombCount < bombMax) bombCount++;
        if (rounds > 0 && rounds % spyRegenInterval == 0 && spyCount < spyMax) spyCount++;
    }
};