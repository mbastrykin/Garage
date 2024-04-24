#pragma once
#include <SFML/Graphics.hpp>

class Player {
private: float x, y = 0;
    float CurrentFrame = 0;
public:
    double w, h, dx, dy, speed;
    int dir;
    std::string File;
    sf::Texture texture;
    sf::Sprite sprite;

    Player(std::string F, float X, float Y, float w, float h) {
        dx = 0; dy = 0; speed = 0; dir = 0;
        File = F;
        w = w; h = h;
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
    };
    float getPlayerCoordinateX() {
        return x;
    }
    float getPlayerCoordinateY() {
        return y;
    }

    /*sf::View changeView() {
        speed;
        if (speed > 0) {
            view.zoom(1.0100f);
        }
    }*/

    void Move(float time) {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
            dir = 1; speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96, 96));
            
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
            dir = 0; speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96));
           /* getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/

            /*getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
            dir = 3; speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96));
           /* getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
            dir = 2; speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 0, 96, 96));
           /* getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/
        }
    }

};