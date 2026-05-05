#pragma once

class Board {
protected:
    int rows = 3; 
    int cols = 3;

public:
    virtual ~Board() = default;

    bool isInside(int row, int col) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }
};