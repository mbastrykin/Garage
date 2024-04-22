#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"

class Player {
private: float x, y = 0;
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
};

//class Map {
//public:
//    std::string File;
//    sf::Texture texture_map;
//    sf::Sprite sprite_map;
//    sf::Image image_map;
//
//    Map(std::string F) {
//        File = F;
//        image_map.loadFromFile("Image/Background/" + File);
//        texture_map.loadFromImage(image_map);
//        sprite_map.setTexture(texture_map);
//        for (int i = 0; i < HEIGHT_MAP; i++)
//            for (int ii = 0; ii < WIDTH_MAP; ii++) {
//                sf::Sprite tile_sprite(sprite_map);
//                if (TileMap[i][ii] == ' ')sprite_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
//                if (TileMap[i][ii] == 's')sprite_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
//                if (TileMap[i][ii] == '0')sprite_map.setTextureRect(sf::IntRect(64, 0, 32, 32));
//
//                sprite_map.setPosition(ii * 32, i * 32);
//                window.draw(tile_sprite);
//            }
//    }
//};


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Garage");
    view.reset(sf::FloatRect(0, 0, 640, 480)); //камера ебанная


    sf::Image map_image;
    map_image.loadFromFile("Image/Background/map.png");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);

    Player hero("hero.png", 250, 250, 96.0, 96.0);
    /*Map map("map.png");*/

    double CurrentFrame = 0;
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
        /*CurrentFrame += 0.005 * time;
        if (CurrentFrame > 3) CurrentFrame -= 3;
        hero.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96));
        hero.sprite.move(0 * time, 0);*/

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
            hero.dir = 1; hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 96, 96, 96));
            
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
            hero.dir = 0; hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 192, 96, 96));
           /* getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/

            /*getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
            hero.dir = 3; hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 288, 96, 96));
           /* getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
            hero.dir = 2; hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.sprite.setTextureRect(sf::IntRect(96 * int(CurrentFrame), 0, 96, 96));
           /* getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());*/
        }

        getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());

        hero.update(time);
        changeView();
        window.setView(view);
        window.clear();


        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int ii = 0; ii < WIDTH_MAP; ii++) {
                if (TileMap[i][ii] == ' ')s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
                if (TileMap[i][ii] == 's')s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
                if (TileMap[i][ii] == '0')s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));

                s_map.setPosition(ii * 32, i * 32);
                window.draw(s_map);
            }
        //// Рисуем карту
        //window.draw(map.sprite); // Вызываем функцию Draw класса Map, передавая окно
        /*window.draw(s_map)*/;
        window.draw(hero.sprite);
        window.display();

    }

    return 0;
}
