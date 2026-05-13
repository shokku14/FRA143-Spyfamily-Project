#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // สร้างหน้าต่างเกม
    sf::RenderWindow window(sf::VideoMode(800, 600), "Spyfamily ^v^ - Board Game");
    window.setFramerateLimit(60);

    // ตั้งค่ากระดาน 3x3
    const int boardSize = 3;
    const float cellSize = 120.0f;
    const float padding = 5.0f;
    float startX = (800.0f - (boardSize * cellSize)) / 2.0f;
    float startY = (600.0f - (boardSize * cellSize)) / 2.0f;

    sf::RectangleShape cellShape(sf::Vector2f(cellSize - padding, cellSize - padding));
    cellShape.setOutlineThickness(3.0f);

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // เคลียร์หน้าจอด้วยสีพื้นหลัง
        window.clear(sf::Color(30, 30, 35));

        // วาดกระดาน
        for (int row = 0; row < boardSize; ++row) {
            for (int col = 0; col < boardSize; ++col) {
                float cellX = startX + (col * cellSize) + (padding / 2.0f);
                float cellY = startY + (row * cellSize) + (padding / 2.0f);
                cellShape.setPosition(cellX, cellY);

                // เอฟเฟกต์เมาส์ชี้ (Hover)
                if (mousePos.x >= cellX && mousePos.x <= cellX + cellSize - padding &&
                    mousePos.y >= cellY && mousePos.y <= cellY + cellSize - padding) {
                    cellShape.setFillColor(sf::Color(100, 150, 200, 180));
                    cellShape.setOutlineColor(sf::Color(200, 200, 255));
                } else {
                    cellShape.setFillColor(sf::Color(50, 50, 50, 200)); 
                    cellShape.setOutlineColor(sf::Color(80, 80, 80));
                }

                window.draw(cellShape);
            }
        }

        window.display();
    }
    return 0;
}