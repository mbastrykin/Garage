#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include "player.h"

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
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Garage");
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

        getPlayerCoordinateForView(hero.getPlayerCoordinateX(), hero.getPlayerCoordinateY());

        hero.Move(time);
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
        
        //window.draw(map.sprite); 
        /*window.draw(s_map)*/;
        window.draw(hero.sprite);
        window.display();

    }

    return 0;
}
