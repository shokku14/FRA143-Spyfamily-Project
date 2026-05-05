#pragma once
#include "Piece.h"

class SpecialPiece : public Piece {
protected:
    bool isSpecial = true; 
public:
    SpecialPiece(int w, Player* p) : Piece(w, p) {}
};


class Spy : public SpecialPiece {
public:
    Spy(Player* p) : SpecialPiece(1, p) {}

    std::string getVisibleNameFor(Player* viewer) override {
        if (viewer == owner) {
            return "Spy"; 
        }
        return "Small"; 
    }

    // เอฟเฟกต์เมื่อถูกหมากตัวอื่นวางทับ (รอเชื่อมต่อกับระบบ Game ภายหลัง)[cite: 1, 2]
    void onCoveredBy(Piece* coveringPiece, Game* game) override {
        // กติกา 1: ถ้าโดนหมากระเบิดทับ (กินด้วยระเบิด) -> ระเบิดลูกนั้นจะกลายเป็น "ระเบิดด้าน"[cite: 1]
        // กติกา 2: ถ้าโดนหมากปกติทับ -> ส่งสัญญาณจุดชนวนระเบิดทุกลูกบนกระดานให้ทำงานทันที![cite: 1]
        
        // (หมายเหตุ: ตรรกะนี้เดี๋ยวเราจะมาเขียนเพิ่มตอนทำไฟล์ระบบศูนย์กลาง Game ครับ)
    }
};


class Bomb : public SpecialPiece {
private:
    int remainingOpponentTurns = 2; 
    bool active = true; 

public:
    Bomb(Player* p) : SpecialPiece(2, p) {}

    void deactivate() { active = false; } 
    bool isActive() { return active; } 

    // ฟังก์ชันระเบิด (ทำลาย 4 ช่องรอบตัว)[cite: 1, 2]
    void explode(Game* game) {
        if (!active) return;
        // (รอเชื่อมต่อคำสั่งลบหมากบนกระดาน GameBoard ภายหลัง)[cite: 1]
    }

    std::string getVisibleNameFor(Player* viewer) override {
        return "Bomb";
    }

    void onCoveredBy(Piece* coveringPiece, Game* game) override {
        if (active) {
            explode(game);
        }
    }

    void onOpponentTurnPassed(Game* game, Player* opponent) override {
        if (active) {
            remainingOpponentTurns--;
            if (remainingOpponentTurns == 0) {
                explode(game); 
            }
        }
    }
};
