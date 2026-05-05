# Final Project Proposal: Spyfamily ^v^
**This project is part of the FRA143 course.**

## 👥 Group Members
* **Kanrawee Kojaroen** (Student ID: 68340500004)
* **Jiranat Worachaiyut** (Student ID: 68340500011)
* **Chonthara Jittiphanphornee** (Student ID: 68340500014)
* **Arus Sangcharoenwanakul** (Student ID: 68340500055)

---

## 📖 Game-Specific Terminology
* **Turn:** A single action taken by one side.
* **Round:** A period in which both sides have each taken one turn.

---

## 룰 Basic Rules

1. **Board Size:** Played on a 3×3 grid.
2. **Overlapping:** A piece with a higher Weight may be placed on top of a piece with a lower Weight in the same cell. The piece being covered is immediately removed from the board.
3. **Win Conditions:**
   * The side that lines up 3 of their own pieces in a row — vertically, horizontally, or diagonally — wins.
   * **Special Rule (Full Board):** If the board is full and the opposing side cannot make a move, their turn is skipped and the current side receives a bonus turn. *(Note: no piece recovery occurs during this bonus turn.)* If the current side can line up 3 pieces in a row, they win. If they cannot move either, they immediately lose.
4. **Information Visibility:**
   * The game displays the **"number of standard pieces"** for both sides at all times.
   * The game **hides** each player's **"number of special pieces"** from the opposing side.

---

## ♟️ Pieces & Resources

### 1. Standard Pieces
* **Small (Anya / Damian) | Weight = 1:** Unlimited supply.
* **Medium (Yor / Melinda) | Weight = 3:** Starts with 2 (Max 2); recovers 1 every 3 rounds.
* **Large (Loid / Donovan) | Weight = 5:** Starts with 1 (Max 1); recovers 1 every 5 rounds.

### 2. Special Pieces
* **💣 Bomb | Weight = 2:** Starts with 2 (Max 2); recovers 1 every 5 rounds.
  * **Effect:** Destroys pieces in the 4 adjacent cells (up, down, left, right).
  * **Trigger Conditions:**
    1. Activates automatically after the opponent has taken 2 turns (the bomb goes off before the opponent's 3rd turn since placement).
    2. If an opponent places a piece on top of it, the bomb activates immediately and also destroys the piece that triggered it.

* **🕵️ Spy | Weight = 1:** Starts with 2 (Max 2); recovers 1 every 7 rounds.
  * **Passive Skill — Disguise:** The opposing side sees this piece as an ordinary "Small" piece. Only the owner knows its true identity.
  * **Effect When Covered:**
    1. *Covered by a standard piece:* Sends a signal that triggers another bomb on the board immediately. (If covered by an opponent, the bomb activates immediately.)
    2. *Covered by a bomb piece:* The bomb placed on top of it becomes a dud (does not detonate), with no notification given to the opposing side.

---

## 🎮 Game Modes

1. **Normal Mode:** Players take turns indefinitely until one side lines up 3 pieces in a row (win), or the board is completely full with no further overlaps possible (draw).
2. **Round-Limited Mode:** Play is limited to a total of 15 rounds. If no side has lined up 3 pieces by the end of round 15, the side with the **most pieces on the board** wins.

---

## 💻 System Architecture Overview

The system is designed using **Object-Oriented Programming (OOP)** principles, divided into 4 main components:

1. **Core:** Central controller for game logic (e.g., `Game`, `Player`, `PieceInventory`).
2. **Board Model:** Manages board state (e.g., `GameBoard`, `Cell`).
3. **Piece Hierarchy:** Inheritance-based piece structure (Base class `Piece` → `StandardPiece` / `SpecialPiece` → individual piece types).
4. **Supporting Types:** Foundational types that support the system (e.g., `GameState`, `PieceType`, `PlayerColor`).

### OOP Principles Applied:
* **Encapsulation:** Sensitive data (e.g., piece counts inside `PieceInventory`) is declared `private` and accessed only through methods, preventing illegal data modification.
* **Inheritance:** `Piece` serves as the base class holding shared attributes (e.g., weight, owner), with subclasses branching out into specific piece types.
* **Polymorphism:** Different behaviors are produced when the same method is called — for example, `onCoveredBy()` causes a standard piece to simply disappear when covered, while a `Bomb` piece triggers an explosion.
* **Separation of Concerns:** Class responsibilities are clearly separated with no cross-contamination of logic — `Game` manages turn flow, `GameBoard` handles the grid cells, and `Piece` governs piece behavior.