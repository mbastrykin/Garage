#pragma once
#include <SFML/Graphics.hpp>

class Player {
private: float x, y = 0;
    float CurrentFrame = 0;
public:
    double w, h, dx, dy, speed;
    int dir,playerScore, health;
    bool life;
    
    std::string File;
    sf::Texture texture;
    sf::Sprite sprite;

    Player(std::string F, float X, float Y, float W, float H) {
        dx = 0; dy = 0; speed = 0; dir = 0; playerScore = 0; health = 40;
        life = true;
        File = F;
        w = W; h = H;
        texture.loadFromFile("Image/Hero/" + File);
        sprite.setTexture(texture);
        x = X; y = Y;
        sprite.setTextureRect(sf::IntRect(0, 0, w, h));

    }
    void update(float time) {
        switch (dir)
        {
        case 0: dx = speed; dy = 0; break;
        case 1: dx = -speed; dy = 0; break;
        case 2: dx = 0; dy = speed; break;
        case 3: dx = 0; dy = -speed; break;
        }

        x += dx * time;
        y += dy * time;

        speed = 0;
        
        sprite.setPosition(x, y);
        interactionWithMap();
        if (health <= 0) { life = false; }
    };
    

    /*sf::View changeView() {
        speed;
        if (speed > 0) {
            view.zoom(1.0100f);
        }
    }*/

    void Move(float time) {
        if (life) {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
                dir = 1; speed = 0.1;
                CurrentFrame += 0.005 * time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 115, 96, 96));

            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
                dir = 0; speed = 0.1;
                CurrentFrame += 0.005 * time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 211, 96, 96));

            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
                dir = 3; speed = 0.1;
                CurrentFrame += 0.005 * time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 307, 96, 96));
            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
                dir = 2; speed = 0.1;
                CurrentFrame += 0.005 * time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 0, 96, 96));

            }
        }
    }

    void interactionWithMap() {
        for (int i = y / 32; i < (y + h) / 32; i++)
            for (int ii = x / 32; ii < (x + w) / 32; ii++) {
                if (TileMap[i][ii] == '0') {
                    if (dy > 0) y = i * 32 - h;
                    if (dy < 0) y = i * 32 + 32;
                    if (dx > 0) x = ii * 32 - w;
                    if (dx < 0) x = ii * 32 + 32;
                }
                if (TileMap[i][ii] == 's') {
                    playerScore++;
                    TileMap[i][ii] = ' ';
                }
                if (TileMap[i][ii] == 'f') {
                    health -= 40;
                    TileMap[i][ii] = ' ';
                }
                if (TileMap[i][ii] == 'h') {
                    health += 20;
                    TileMap[i][ii] = ' ';
                }
            }
    }
    float getPlayerCoordinateX() {
        return x;
    }
    float getPlayerCoordinateY() {
        return y;
    }
};