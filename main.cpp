#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Garage");
double CurrentFrame = 0;

class Player {
public: 
    double x, y, Weight, Height;
    sf::Texture playertexture;
    sf::Sprite playersprite;

    bool isGround;

    Player() {
        playertexture.loadFromFile("Image/Hero/hero.png");
        playersprite.setTexture(playertexture);
        playersprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
        playersprite.setPosition(50, 25);

        isGround = true;
    }
};

class Background {
public:
    sf::Texture backtext;
    sf::Sprite backsprite;

    Background() {
        backtext.loadFromFile("Image/Background/background.jpg");
        backsprite.setTexture(backtext);
        backsprite.setPosition(0, 0);
    }

};

class Garage : Player{
public: 
   double x, y, startposX,startposY; 
    sf::Texture garagetexture;
    sf::Sprite garagesprite;
    Garage() {
        startposX = 600;
        startposY = 100;
        garagetexture.loadFromFile("Image/Garage/Garage.png");
        garagesprite.setTexture(garagetexture);
        garagesprite.setPosition(startposX,startposY);
   }
};
class Damage : Player {
public: 
    double x, y, Weight, Height;
};

int main()
{
    Player hero;
    Background back1;
    Garage garage1;
    sf::Clock clock;
    
    

    while (window.isOpen()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        int delaytime = 600;
        time = time / delaytime++;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 3) CurrentFrame -= 3;
        hero.playersprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96));
        hero.playersprite.move(0 * time, 0);
        back1.backsprite.move(0 * time, 0);
        garage1.garagesprite.move(-0.1* time, 0);
       
        if (hero.isGround) {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
                CurrentFrame += 0.005 * time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.playersprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96));
                hero.playersprite.move(0, -0.5 * time);
            }
        }
       /* if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3; 
            hero.herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96, 96)); 
            hero.herosprite.move(-0.1 * time, 0);
        }
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
            CurrentFrame += 0.005 * time; 
            if (CurrentFrame > 3) CurrentFrame -= 3; 
            hero.herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96)); 
            hero.herosprite.move(0.1 * time, 0);
        }
      
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))){
            CurrentFrame += 0.005 * time; 
            if (CurrentFrame > 3) CurrentFrame -= 3; 
            hero.herosprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 0, 96, 96)); 
            hero.herosprite.move(0, 0.1 * time);
        }      */
        window.clear();
        window.draw(back1.backsprite);
        window.draw(garage1.garagesprite);
        window.draw(hero.playersprite);
        window.display();
    }

    return 0;
}
