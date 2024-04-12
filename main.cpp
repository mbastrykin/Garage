#include <SFML/Graphics.hpp>
#include <iostream>


sf::RenderWindow window(sf::VideoMode(640, 480), "Garage");

class Hero {
public: 
    double x, y, Weight, Height;
    sf::Texture herotexture;
    sf::Sprite herosprite;

    Hero() {
        herotexture.loadFromFile("Image/Hero/hero.png");
        herosprite.setTexture(herotexture);
        herosprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
        herosprite.setPosition(50, 25);
    }
    
    void move(double offsetX, double offsetY) {
        herosprite.move(offsetX, offsetY);
    }
};

//class Garage {
//public: 
//    double x, y, Weight, Height;
//    sf::Texture garagetexture;
//    sf::Sprite garagesprite;
//    Garage() {
//        garagetexture.loadFromFile("Image/Hero/hero.png");
//        garagesprite.setTexture(garagetexture);
//        garagesprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
//        garagesprite.setPosition(50, 25);
//    }
//};


int main()
{
    Hero hero;
    sf::Clock clock;
    double CurrentFrame = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
            hero.move(-0.1, 0);
            hero.herosprite.setTextureRect(sf::IntRect(0, 96, 96, 96));
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
            hero.move(0.1, 0); 
            hero.herosprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
            hero.move(0, -0.1);
            hero.herosprite.setTextureRect(sf::IntRect(0, 288, 96, 96));
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))){
            hero.move(0, 0.1);
            hero.herosprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
        } 
        window.clear();
        window.draw(hero.herosprite);
        window.display();
    }

    return 0;
}