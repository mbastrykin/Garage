#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 25;
const int WIDTH_MAP = 40;

//class Map {
//public:
//	std::string File;
//	sf::Texture texture_map;
//	sf::Sprite sprite_map;
//	sf::Image image_map;
//
//	Map(std::string F) {
//		File = F;
//		image_map.loadFromFile("Image/Background/" + File);
//		texture_map.loadFromImage(image_map);
//		sprite_map.setTexture(texture_map);
//		for (int i = 0; i < HEIGHT_MAP; i++)
//			for (int ii = 0; ii < WIDTH_MAP; ii++) {
//				sf::Sprite tile_sprite(sprite_map);
//				if (TileMap[i][ii] == ' ')sprite_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
//				if (TileMap[i][ii] == 's')sprite_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
//				if (TileMap[i][ii] == '0')sprite_map.setTextureRect(sf::IntRect(64, 0, 32, 32));
//
//				sprite_map.setPosition(ii * 32, i * 32);
//				window.draw(tile_sprite);
//			}
//	}
//};

sf::String TileMap[HEIGHT_MAP] = {
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0   s           s                      0",
	"0                                      0",
	"0                                      0",
	"0              s                       0",
	"0                                      0",
	"0              s                       0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
};